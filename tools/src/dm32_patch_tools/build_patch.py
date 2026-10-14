"""Checklist item: a general-purpose "assemble a patch handler -> modded sector" tool,
generalizing the hand-written per-patch build_*.py scripts in the main repo's
firmware/tools/ramdump-patch/ (build_pllprobe.py, build_megaprobe.py, build_calprobe.py, ...).
Every one of those scripts hand-rolls the same sequence - compile, extract .text, verify the
stock bytes at the hook site, place the handler in free space, encode a br/bsr into it, splice,
bound the diff - with its own copy of the CK803S branch-encoding helper. This module is that
sequence as a reusable library (and a CLI), cross-checked against this submodule's own
meta/sectors.json, meta/patch_risk.json and meta/patch_sites.json before it ever writes a byte.

WHAT THIS DOES NOT DO: flash anything. It produces sector-sized .bin files on disk. Flashing is
always a separate, explicit, human-run step, done outside this repo with a verified full backup
of the radio - this project's standing safety rule is that writes to a real radio
are never automated.

THE TWO HOOK KINDS, matching every existing patch in the main repo:
  - "br"  - a 32-bit unconditional branch, 16-bit signed halfword offset (range +-64KB).
            Used to chain a "not ours" fallthrough inside an already-hooked dispatcher into a
            new handler (e.g. build_pllprobe.py's PLL-settling probe).
  - "bsr" - a 32-bit branch-and-link, 26-bit signed halfword offset (range +-64MB). Used for
            the FIRST hook into a function the stock firmware already calls, redirecting it
            into a handler whose epilogue falls back into the original behaviour (e.g.
            build_patch.py's RAMDUMP hook at 0x0302a47c).
Both encodings verified byte-for-byte against the main repo's existing, hardware-verified
patches (see encode_branch()'s own docstring) - this is not a re-derivation, it's the same
constants carried forward from scripts that have already been flashed to real hardware.

CK803S 32-bit instructions are stored as two LITTLE-ENDIAN HALFWORDS, OPCODE HALFWORD FIRST -
not one little-endian 32-bit word. Getting this backwards hung the radio during this project's
own prior work (see megaprobe_handler.S's docstring and the project's
csky-32bit-insn-halfword-order lesson) - encode_branch() is the one place this encoding lives
now, so every caller gets it from a single, already-verified implementation.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import shutil
import subprocess
import sys
import tempfile

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
SECTORS_JSON = REPO_ROOT / "meta" / "sectors.json"
PATCH_RISK_JSON = REPO_ROOT / "meta" / "patch_risk.json"
PATCH_SITES_JSON = REPO_ROOT / "meta" / "patch_sites.json"

FLASH_BASE = 0x03000000
SECTOR_SIZE = 0x1000

CROSS_CC = "csky-abiv2-elf-gcc"
CROSS_OBJCOPY = "csky-abiv2-elf-objcopy"
CROSS_LD = "csky-abiv2-elf-ld"
CROSS_OBJDUMP = "csky-abiv2-elf-objdump"
CPU = "ck803s"


class BuildError(Exception):
    """A patch-build precondition failed. Never partially writes output files."""


# Program-flash sector that holds per-radio data (see scrub_unit_sector.py). Never a patch target.
PER_UNIT_SECTOR = 0x0300B000


def encode_branch(src: int, tgt: int, kind: str) -> bytes:
    """Encode a CK803S 32-bit br/bsr from src to tgt, as the four bytes stored in flash.

    Verified against real, previously-flashed patches:
      - br:  build_pllprobe.py's br_bytes(), itself checked by
             build_megaprobe.py's verify_branch_lands_on_probe() (decodes the patched bytes
             back into a target address and confirms it lands inside the probe).
      - bsr: build_patch.py's bsr_bytes(), whose comment records the exact ground-truth case
             this was checked against: bsr 0x0302a47c -> 0x030e1000 encodes as insn 0xe005b5c2,
             stored as bytes 05 e0 c2 b5 - i.e. opcode halfword (0xe005) first, each halfword
             little-endian, NOT insn.to_bytes(4, "little") (which would reverse the halfwords
             and silently produce a different, wrong instruction - see this module's own
             docstring and the project's csky-32bit-insn-halfword-order lesson).
    """
    if (tgt - src) % 2 != 0:
        raise BuildError(f"misaligned branch: src={src:#x} tgt={tgt:#x}")
    off = (tgt - src) // 2
    if kind == "br":
        if not (-(1 << 15) <= off < (1 << 15)):
            raise BuildError(f"br out of range: offset {off} halfwords (src={src:#x} tgt={tgt:#x})")
        insn = 0xE8000000 | (off & 0x0000FFFF)
    elif kind == "bsr":
        if not (-(1 << 25) <= off < (1 << 25)):
            raise BuildError(f"bsr out of range: offset {off} halfwords (src={src:#x} tgt={tgt:#x})")
        insn = 0xE0000000 | (off & 0x03FFFFFF)
    else:
        raise BuildError(f"unknown hook kind {kind!r}, expected 'br' or 'bsr'")
    hw_hi = (insn >> 16) & 0xFFFF
    hw_lo = insn & 0xFFFF
    return bytes([hw_hi & 0xFF, (hw_hi >> 8) & 0xFF, hw_lo & 0xFF, (hw_lo >> 8) & 0xFF])


def decode_branch(encoded: bytes) -> tuple[str, int] | None:
    """Inverse of encode_branch(), for verify_branch_lands(). Returns (kind, halfword_offset)
    or None if the bytes don't decode as a br/bsr opcode."""
    if len(encoded) != 4:
        raise BuildError(f"expected 4 bytes, got {len(encoded)}")
    hw0 = int.from_bytes(encoded[0:2], "little")
    hw1 = int.from_bytes(encoded[2:4], "little")
    insn = (hw0 << 16) | hw1
    top = insn & 0xFC000000
    if top == 0xE8000000:
        kind, mask, bit = "br", 0x0000FFFF, 1 << 15
    elif top == 0xE0000000:
        kind, mask, bit = "bsr", 0x03FFFFFF, 1 << 25
    else:
        return None
    off = insn & mask
    if off & bit:
        off -= (bit << 1)
    return (kind, off)


def verify_branch_lands(sector: bytes, hook_sector_off: int, place_addr: int, handler_len: int,
                         kind: str, hook_addr: int) -> None:
    """Decode the branch just written back out of the finished sector bytes and confirm it
    actually lands inside the handler - catching an encoding bug (e.g. the halfword-order bug
    this module's docstring describes) by testing the thing that actually matters, not just
    that the intended bytes were written. See build_megaprobe.py's identically-named function,
    whose comment explains this was the check that would have caught that exact bug."""
    decoded = decode_branch(sector[hook_sector_off:hook_sector_off + 4])
    if decoded is None:
        raise BuildError(
            f"hook site at {hook_addr:#x} does not decode as a br/bsr after patching: "
            f"{sector[hook_sector_off:hook_sector_off+4].hex(' ')}"
        )
    decoded_kind, off = decoded
    if decoded_kind != kind:
        raise BuildError(f"hook site decodes as {decoded_kind}, expected {kind}")
    target = hook_addr + off * 2
    if not (place_addr <= target < place_addr + handler_len):
        raise BuildError(
            f"branch decodes to {target:#x}, outside the handler "
            f"[{place_addr:#x}, {place_addr + handler_len:#x})"
        )


def assemble(src_path: pathlib.Path, cpu: str = CPU, link_addr: int | None = None) -> bytes:
    """Assemble a .S/.c file and return its raw .text+.rodata bytes.

    LINKING IS NOT OPTIONAL (fixed 2026-10-12). Compiling with `-c` and running objcopy on the
    resulting OBJECT leaves every relocation unresolved: an `lrw rX, some_label` - the ordinary
    way to reach a string or table in your own handler - keeps a literal-pool word of
    0x00000000, because R_CKCORE_ADDR32 against a same-section symbol is only resolved by a
    real link. The handler then dereferences a null pointer on the radio, and nothing upstream
    notices, because the build "succeeded". A blind rebuild of this repo's own examples hit
    exactly that. So: when `link_addr` is given, this links at that address (`ld -Ttext=...`,
    the same step tools/examples/build_overlay_image.py always did by hand) and then refuses to
    return bytes if any relocation survives.

    `link_addr=None` assembles without linking, ONLY to measure the handler's size so the caller
    can choose a placement address; those bytes must never be written into a sector.

    Needs csky-abiv2-elf-gcc, -ld and -objcopy on PATH (built into this submodule's own Docker
    image - see ../../../docker/Dockerfile)."""
    if shutil.which(CROSS_CC) is None:
        raise BuildError(
            f"{CROSS_CC} not found on PATH. Run this inside the dm32uv-re Docker image "
            f"(docker/README.md), which builds the CK803S cross-toolchain from source."
        )
    with tempfile.TemporaryDirectory() as td:
        td_path = pathlib.Path(td)
        obj_path = td_path / "handler.o"
        bin_path = td_path / "handler.bin"
        cc_cmd = [CROSS_CC, f"-mcpu={cpu}", "-c", str(src_path), "-o", str(obj_path)]
        result = subprocess.run(cc_cmd, capture_output=True, text=True)
        if result.returncode != 0:
            raise BuildError(f"assemble failed:\n{result.stdout}\n{result.stderr}")

        src = obj_path
        if link_addr is not None:
            elf_path = td_path / "handler.elf"
            ld_cmd = [CROSS_LD, f"-Ttext={link_addr:#x}", "-o", str(elf_path), str(obj_path)]
            result = subprocess.run(ld_cmd, capture_output=True, text=True)
            if result.returncode != 0:
                raise BuildError(
                    f"link at {link_addr:#x} failed:\n{result.stdout}\n{result.stderr}\n"
                    f"(an undefined symbol here usually means the handler calls a stock routine "
                    f"by name instead of through an absolute address - see "
                    f"tools/include/dm32_patch_api.h)"
                )
            src = elf_path
            leftover = subprocess.run([CROSS_OBJDUMP, "-r", str(elf_path)],
                                      capture_output=True, text=True)
            if "R_CKCORE" in leftover.stdout:
                raise BuildError(
                    "relocations survived the link - the handler would contain null/!bogus "
                    "pointers:\n" + leftover.stdout
                )

        objcopy_cmd = [CROSS_OBJCOPY, "-O", "binary", "-j", ".text", "-j", ".rodata",
                       str(src), str(bin_path)]
        result = subprocess.run(objcopy_cmd, capture_output=True, text=True)
        if result.returncode != 0:
            raise BuildError(f"objcopy failed:\n{result.stdout}\n{result.stderr}")
        return bin_path.read_bytes()


def corpus_crosscheck(addr: int) -> list[str]:
    """Pure data lookup against this submodule's own exports (item C/D/E of the project's
    patch-readiness checklist) - informational only, never blocks a build. Returns warning
    strings for the caller to print or ignore."""
    warnings: list[str] = []
    sector_num = (addr - FLASH_BASE) // SECTOR_SIZE
    sectors = json.loads(SECTORS_JSON.read_text())["sectors"] if SECTORS_JSON.exists() else {}
    sec_info = sectors.get(str(sector_num))

    if sec_info and sec_info.get("known_sensitive"):
        warnings.append(f"sector {sector_num} flagged known_sensitive: {sec_info['known_sensitive']}")

    if PATCH_SITES_JSON.exists():
        sites = json.loads(PATCH_SITES_JSON.read_text())["sites"]
        write_lo, write_hi = addr, addr + 4
        for s in sites:
            site_addr = s.get("addr")
            if site_addr and write_lo <= int(site_addr, 16) < write_hi:
                warnings.append(
                    f"collides with catalogued patch site '{s['id']}' ({s.get('description', '')})"
                )

    # patch_risk.json keys by function start address, not a range, so finding "the function
    # containing addr" needs a function's SIZE too - sectors.json's own per-sector function
    # list already carries that (same containment-scan approach verify_patch.py's
    # containing_function() uses), so cross-reference through it rather than scanning all of
    # patch_risk.json's ~3300 entries for a range none of them actually store.
    if PATCH_RISK_JSON.exists():
        risk = json.loads(PATCH_RISK_JSON.read_text())["functions"]
        if sec_info:
            for fn in sec_info.get("functions", []):
                fn_addr = int(fn["addr"], 16)
                if fn_addr <= addr < fn_addr + fn["size"]:
                    fn_risk = risk.get(fn["addr"])
                    if fn_risk and fn_risk["patch_risk"] in ("high", "unknown"):
                        warnings.append(
                            f"hook address falls inside '{fn['name']}' "
                            f"(patch_risk={fn_risk['patch_risk']}): "
                            f"{'; '.join(fn_risk['reasons'])}"
                        )
    return warnings


def build_patch(
    stock_sector: bytes,
    handler_src: pathlib.Path,
    sector_base: int,
    hook_addr: int,
    expected_hook_bytes: bytes,
    hook_kind: str,
    place_addr: int | None = None,
    fallback_bytes: bytes | None = None,
    cpu: str = CPU,
) -> dict:
    """Build one modded sector. This is the library entry point build_patch.py's CLI wraps,
    and what a project-specific build_<name>.py script (replacing the hand-rolled version) can
    import directly.

    stock_sector         - the 4KB sector's current bytes (from a live read or a trusted backup).
    handler_src          - path to the handler .S/.c source to assemble.
    sector_base          - this sector's own flash address (must be 4KB-aligned).
    hook_addr            - address of the site to redirect (must fall inside this sector).
    expected_hook_bytes  - the stock bytes at hook_addr, checked before anything is touched -
                           refuses to patch a firmware state this wasn't built against.
    hook_kind            - "br" or "bsr" (see this module's docstring).
    place_addr           - where to place the handler. If None, finds the first 4-byte-aligned
                           run of 0xFF (erased flash) long enough to hold it, after hook_addr's
                           own sector - same free-space-probing approach build_pllprobe.py uses.
    fallback_bytes       - if given, these go at hook_addr's PREVIOUS site instead of leaving a
                           gap (e.g. chaining a "not ours" dispatcher) - informational pass-
                           through to the result, this function does not interpret them.

    Returns a dict: {"sector": bytes, "pre_sector": bytes, "handler_addr": int,
    "handler_len": int, "diffs": [offsets], "warnings": [str]} and never partially writes
    anything - callers decide what to do with the result.
    """
    if sector_base % SECTOR_SIZE != 0:
        raise BuildError(f"sector_base {sector_base:#x} is not sector-aligned")
    if sector_base == PER_UNIT_SECTOR:
        raise BuildError(
            f"sector {sector_base:#x} is the per-unit parameter sector (eFuse-derived binding record "
            f"at +0x10c, per-unit hardware bytes). It reads as erased in this repo's images only "
            f"because they were scrubbed (scrub_unit_sector.py); on a radio it is never free space.")
    if len(stock_sector) != SECTOR_SIZE:
        raise BuildError(f"stock_sector is {len(stock_sector)} bytes, expected {SECTOR_SIZE:#x}")
    if not (sector_base <= hook_addr < sector_base + SECTOR_SIZE):
        raise BuildError(f"hook_addr {hook_addr:#x} is outside sector [{sector_base:#x}, {sector_base+SECTOR_SIZE:#x})")

    hook_off = hook_addr - sector_base
    actual = bytes(stock_sector[hook_off:hook_off + 4])
    if actual != expected_hook_bytes:
        raise BuildError(
            f"hook site at {hook_addr:#x} does not match expected bytes: "
            f"got {actual.hex(' ')}, expected {expected_hook_bytes.hex(' ')} "
            f"(refusing to patch an unexpected firmware state)"
        )

    # Size the handler first (unlinked bytes are only ever measured, never written), so
    # auto-placement can pick an address; then LINK at that address - see assemble().
    handler = assemble(handler_src, cpu=cpu)
    sec = bytearray(stock_sector)
    pre = bytes(sec)

    if place_addr is None:
        # first 4-byte-aligned run of erased (0xFF) space long enough for the handler,
        # anywhere in this sector after the hook site's own 4 bytes.
        search_start = (hook_off + 4 + 3) & ~3
        found = None
        off = search_start
        while off + len(handler) <= SECTOR_SIZE:
            if all(b == 0xFF for b in sec[off:off + len(handler)]):
                found = off
                break
            off += 4
        if found is None:
            raise BuildError(
                f"no {len(handler)}-byte run of erased space found in sector {sector_base:#x} "
                f"after offset {search_start:#x}"
            )
        place_off = found
        place_addr = sector_base + place_off
    else:
        if not (sector_base <= place_addr < sector_base + SECTOR_SIZE):
            raise BuildError(f"place_addr {place_addr:#x} is outside this sector")
        place_off = place_addr - sector_base
        if place_off + len(handler) > SECTOR_SIZE:
            raise BuildError(f"handler does not fit at {place_addr:#x} (sector would overflow)")
        if any(b != 0xFF for b in sec[place_off:place_off + len(handler)]):
            raise BuildError(f"target area at {place_addr:#x} is not erased")

    # Re-assemble, this time LINKED at the address the handler will actually occupy, so every
    # internal pointer (string literals, tables) is resolved instead of left as 0x00000000.
    handler_linked = assemble(handler_src, cpu=cpu, link_addr=place_addr)
    if len(handler_linked) > len(handler):
        # Linking pulled in .rodata that the unlinked size estimate missed; re-check the fit.
        if place_off + len(handler_linked) > SECTOR_SIZE:
            raise BuildError(
                f"linked handler is {len(handler_linked)} bytes and does not fit at "
                f"{place_addr:#x} (sector would overflow)"
            )
        if any(b != 0xFF for b in sec[place_off:place_off + len(handler_linked)]):
            raise BuildError(
                f"linked handler is {len(handler_linked)} bytes (unlinked estimate was "
                f"{len(handler)}) and the extra space at {place_addr:#x} is not erased"
            )
    handler = handler_linked

    sec[place_off:place_off + len(handler)] = handler

    branch = encode_branch(hook_addr, place_addr, hook_kind)
    sec[hook_off:hook_off + 4] = branch

    verify_branch_lands(bytes(sec), hook_off, place_addr, len(handler), hook_kind, hook_addr)

    diffs = [i for i in range(SECTOR_SIZE) if pre[i] != sec[i]]
    max_expected = 4 + len(handler)
    if len(diffs) > max_expected:
        raise BuildError(
            f"TOO MANY bytes differ from stock ({len(diffs)} > {max_expected} expected) - "
            f"refusing to emit a sector that changes more than intended"
        )
    for i in diffs:
        a = sector_base + i
        in_hook = hook_addr <= a < hook_addr + 4
        in_handler = place_addr <= a < place_addr + len(handler)
        if not (in_hook or in_handler):
            raise BuildError(
                f"diff at {a:#x} is outside the intended ranges "
                f"(hook [{hook_addr:#x},{hook_addr+4:#x}) or handler "
                f"[{place_addr:#x},{place_addr+len(handler):#x}))"
            )

    # dedupe: a hook and its handler commonly land in the same function/sector-sensitivity
    # scope, which would otherwise print the identical warning twice.
    seen = set()
    warnings = []
    for w in corpus_crosscheck(hook_addr) + corpus_crosscheck(place_addr):
        if w not in seen:
            seen.add(w)
            warnings.append(w)

    return {
        "sector": bytes(sec),
        "pre_sector": pre,
        "handler_addr": place_addr,
        "handler_len": len(handler),
        "diffs": diffs,
        "warnings": warnings,
    }


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--handler", required=True, type=pathlib.Path, help="handler .S/.c source")
    ap.add_argument("--stock-sector", required=True, type=pathlib.Path,
                     help="current 4KB sector bytes (live read or trusted backup)")
    ap.add_argument("--sector-base", required=True, help="this sector's flash address, e.g. 0x030e1000")
    ap.add_argument("--hook-addr", required=True, help="address of the site to redirect")
    ap.add_argument("--expect-hook-bytes", required=True,
                     help="expected stock bytes at --hook-addr, as hex, e.g. 08ea0000")
    ap.add_argument("--hook-kind", required=True, choices=["br", "bsr"])
    ap.add_argument("--place-addr", default=None,
                     help="where to place the handler (default: first erased run found)")
    ap.add_argument("--out", required=True, type=pathlib.Path, help="output modded sector .bin")
    ap.add_argument("--out-pre", type=pathlib.Path, default=None,
                     help="also write the pre-patch sector here (default: <out>.pre)")
    ap.add_argument("--cpu", default=CPU)
    args = ap.parse_args()

    sector_base = int(args.sector_base, 0)
    hook_addr = int(args.hook_addr, 0)
    expected = bytes.fromhex(args.expect_hook_bytes)
    place_addr = int(args.place_addr, 0) if args.place_addr else None

    stock_sector = args.stock_sector.read_bytes()

    try:
        result = build_patch(
            stock_sector=stock_sector,
            handler_src=args.handler,
            sector_base=sector_base,
            hook_addr=hook_addr,
            expected_hook_bytes=expected,
            hook_kind=args.hook_kind,
            place_addr=place_addr,
        )
    except BuildError as e:
        print(f"FAIL: {e}", file=sys.stderr)
        sys.exit(1)

    args.out.write_bytes(result["sector"])
    out_pre = args.out_pre or args.out.with_suffix(args.out.suffix + ".pre")
    out_pre.write_bytes(result["pre_sector"])

    print(f"handler placed at {result['handler_addr']:#010x}, {result['handler_len']} bytes")
    print(f"{len(result['diffs'])} bytes differ from stock "
          f"(hook 4 + handler {result['handler_len']} = {4 + result['handler_len']} max)")
    print(f"wrote {args.out}")
    print(f"wrote {out_pre} (pre-patch backup)")
    if result["warnings"]:
        print("\ncorpus cross-check warnings (informational, not blocking):")
        for w in result["warnings"]:
            print(f"  ! {w}")
    print("\nOK - not yet verified against QEMU or flashed. Run verify_patch.py next.")


if __name__ == "__main__":
    main()

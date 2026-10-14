"""Checklist item F: patch verification loop wired to the corpus.

Takes a proposed patch - a modded 4KB sector .bin plus the flash offset it writes to - and
answers two different questions in two different ways:

  1. CORPUS-SIDE PRE-FLIGHT (always runs, fully standalone - no QEMU, no Docker, no
     dependency on anything outside this submodule): which corpus function(s) does the
     write touch, what does meta/patch_risk.json say about how risky that is, is the sector
     flagged known_sensitive in meta/sectors.json, does it collide with a catalogued patch
     site in meta/patch_sites.json. This is pure data lookup against the exports from items
     A-E and runs anywhere dm32uv-re is cloned.

  2. DYNAMIC VERIFICATION (only when qemu-system-cskyv2 is on PATH, i.e. inside this repo's
     Docker image - vendor/csky-qemu + vendor/dm32uv-qemu, see ../../../docker/Dockerfile):
     qemu_boot_diff.py composes stock and patched images with compose_qemu_image.compose()
     (ALPU-MP bypass and the other two QEMU-only patches applied identically to both), boots
     both to the standby screen, drives one fixed key script (MENU, BACK by default) and
     compares every settled screen and the set of executed code addresses. See that module's
     docstring for exactly what is compared and what each verdict means. Code addresses that
     differ outside the patched sector are translated into named corpus functions, so "47
     addresses changed outside the sector" becomes "gpio_pin_configure unexpectedly gained
     execution" - a finding a patch author can act on instead of a bare address list.

WHY THIS SPLIT, NOT ONE MONOLITHIC TOOL: the QEMU boot comparison is heavier infrastructure
that only exists inside the Docker image, while the pre-flight is pure data lookup like
export_sectors.py/export_xrefs.py/export_patch_sites.py/export_patch_risk.py. Without
qemu-system-cskyv2 the dynamic step is reported as skipped, never as an error, and the
pre-flight is always reported regardless.

EXIT STATUS: 0 = PASS / PASS with warnings / dynamic step skipped; 1 = FAIL;
2 = bad arguments; 3 = DIFFERS (the patched image behaves differently on the probe - expected
for a UI patch the probe reaches, review the kept frames); 4 = INCONCLUSIVE.

`--json [PATH]` additionally emits one compact object (to PATH, or as the final stdout line
when PATH is "-") holding the same data the prints use: the preflight dict, the dynamic result
dict (null when the dynamic step is skipped), the final verdict (null when skipped) and the
exit code, so an agent can consume this checklist without parsing prose.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import sys

# qemu_boot_diff.py is a plain sibling module, not imported via the installed dm32_patch_tools
# package - this script is documented to run as `python3 src/dm32_patch_tools/verify_patch.py`
# (no Ghidra/uv needed for its own logic), same as export_sectors.py/export_xrefs.py, so it
# can't assume the package is on sys.path the way export_disasm.py's `uv run` invocation can.
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import qemu_boot_diff

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
SECTORS_JSON = REPO_ROOT / "meta" / "sectors.json"
PATCH_SITES_JSON = REPO_ROOT / "meta" / "patch_sites.json"
PATCH_RISK_JSON = REPO_ROOT / "meta" / "patch_risk.json"

FLASH_BASE = 0x03000000
SECTOR_SIZE = 0x1000

EXIT_CODES = {"PASS": 0, "PASS with warnings": 0, "FAIL": 1, "DIFFERS": 3, "INCONCLUSIVE": 4}


def load_corpus():
    functions = json.loads(FUNCTIONS_JSON.read_text())["functions"]
    functions_by_start = sorted(
        ((int(f["addr"], 16), int(f["addr"], 16) + f["size"], f) for f in functions),
        key=lambda t: t[0],
    )
    return functions_by_start


def containing_function(functions_by_start, addr: int):
    for start, end, f in functions_by_start:
        if start <= addr < end:
            return f
    return None


def find_diff_range(stock: bytes, modded: bytes, offset: int) -> list[int]:
    diffs = [i for i in range(len(stock)) if stock[i] != modded[i]]
    return diffs


def corpus_preflight(functions_by_start, offset: int, diff_offsets: list[int]) -> dict:
    """The fully-standalone half: locate affected corpus functions and cross-reference
    item D/C/E's exports. Never touches QEMU."""
    sectors = json.loads(SECTORS_JSON.read_text())["sectors"]
    patch_sites = json.loads(PATCH_SITES_JSON.read_text())["sites"]
    patch_risk = json.loads(PATCH_RISK_JSON.read_text())["functions"]

    write_start = FLASH_BASE + offset
    write_end = write_start + SECTOR_SIZE
    sector_num = offset // SECTOR_SIZE

    touched_addrs = sorted({write_start + d for d in diff_offsets})
    touched_fns = {}
    for addr in touched_addrs:
        fn = containing_function(functions_by_start, addr)
        if fn is None:
            continue
        key = fn["addr_hex"]
        touched_fns.setdefault(key, {"name": fn["name"], "addrs_touched": []})
        touched_fns[key]["addrs_touched"].append(hex(addr))

    for key, info in touched_fns.items():
        risk = patch_risk.get(key)
        info["patch_risk"] = risk["patch_risk"] if risk else "unknown (not in patch_risk.json)"
        info["patch_risk_reasons"] = risk["reasons"] if risk else []

    sector_info = sectors.get(str(sector_num))
    known_sensitive = sector_info.get("known_sensitive") if sector_info else None

    colliding_sites = [
        s for s in patch_sites
        if s.get("addr") and write_start <= int(s["addr"], 16) < write_end
    ]

    return {
        "write_range": [hex(write_start), hex(write_end)],
        "sector": sector_num,
        "sector_known_sensitive": known_sensitive,
        "bytes_changed": len(diff_offsets),
        "touched_functions": touched_fns,
        "untouched_addresses_in_diff": sum(
            1 for d in diff_offsets
            if containing_function(functions_by_start, write_start + d) is None
        ),
        "colliding_catalogued_patch_sites": [s["id"] for s in colliding_sites],
    }


def translate_pcs_to_functions(functions_by_start, pcs: list[str]) -> list[dict]:
    out = []
    for pc in pcs:
        addr = int(pc, 16)
        fn = containing_function(functions_by_start, addr)
        out.append({
            "pc": pc,
            "corpus_function": fn["name"] if fn else None,
            "corpus_function_addr": fn["addr_hex"] if fn else None,
        })
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--sector", required=True, type=pathlib.Path,
                     help="modded 4KB sector .bin (the whole sector as it should be written)")
    ap.add_argument("--offset", required=True, help="flash write offset, e.g. 0xAF000")
    ap.add_argument("--stock", type=pathlib.Path, default=qemu_boot_diff.DEFAULT_BASE,
                     help="full 1 MB stock program-flash image to diff against and to compose "
                          "both emulator images from (default: "
                          "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin)")
    ap.add_argument("--skip-dynamic", action="store_true",
                     help="corpus-side pre-flight only, never attempt the QEMU comparison")
    ap.add_argument("--iram", type=pathlib.Path,
                     default=REPO_ROOT / "data" / "firmware" / "IRAM_dm32.00.01.048.bin",
                     help="IRAM image to load at 0x00010000 for qemu_boot_diff.py "
                          "(several flash functions call into IRAM-resident code; see "
                          "vendor/dm32uv-qemu/README.md). Defaults to the flash-derived image in "
                          "data/firmware/ (derive_iram.py) - pass --iram= (empty) to preload each "
                          "boot with the IRAM derived from its own composed image instead. The "
                          "boot stub re-copies the IRAM load image from the composed flash either "
                          "way, so a patch inside that image is always what runs.")
    ap.add_argument("--keyseq", default=qemu_boot_diff.PROBE_KEYSEQ,
                     help="DM32_KEYSEQ probe script driven through BOTH boots (default: wait for "
                          "standby, MENU, BACK - see qemu_boot_diff.PROBE_KEYSEQ and "
                          "qemu_run.py's key table). Extend it to reach the screen your patch "
                          "changes.")
    ap.add_argument("--timeout", type=float, default=300,
                     help="wall-clock cap per boot, seconds (default 300; a patched boot that "
                          "has not finished 4x+30s after stock did is stopped earlier)")
    ap.add_argument("--keep-dir", type=pathlib.Path, default=None,
                     help="copy both runs (images, qemu.log, gram.raw.NNN frames) here for "
                          "inspection, e.g. with render_frames.py --rundir <dir>/patched")
    ap.add_argument("--seconds", type=int, default=None, help=argparse.SUPPRESS)  # obsolete
    ap.add_argument("--json", nargs="?", const="-", default=None, metavar="PATH",
                    help="also emit one compact JSON object after the prints - to PATH when "
                         "given, or as the final stdout line when PATH is '-' (default). "
                         "Fields: preflight, dynamic (null when the dynamic step is skipped), "
                         "verdict (null when skipped), exit_code.")
    args = ap.parse_args()

    offset = int(args.offset, 0)
    if offset % SECTOR_SIZE != 0:
        print(f"ERROR: offset {offset:#x} is not {SECTOR_SIZE:#x}-aligned", file=sys.stderr)
        sys.exit(2)

    modded = args.sector.read_bytes()
    if len(modded) != SECTOR_SIZE:
        print(f"ERROR: --sector must be exactly {SECTOR_SIZE:#x} bytes, got {len(modded):#x}",
              file=sys.stderr)
        sys.exit(2)

    stock_full = args.stock.read_bytes()
    stock_sector = stock_full[offset:offset + SECTOR_SIZE]
    if len(stock_sector) != SECTOR_SIZE:
        print(f"ERROR: --stock too short to contain a sector at offset {offset:#x}",
              file=sys.stderr)
        sys.exit(2)

    diff_offsets = find_diff_range(stock_sector, modded, offset)

    print("== corpus-side pre-flight (standalone, no QEMU) ==")
    functions_by_start = load_corpus()
    preflight = corpus_preflight(functions_by_start, offset, diff_offsets)

    print(f"  write range: {preflight['write_range'][0]}..{preflight['write_range'][1]} "
          f"(sector {preflight['sector']}), {preflight['bytes_changed']} bytes differ")
    if preflight["sector_known_sensitive"]:
        print(f"  !! SECTOR FLAGGED known_sensitive: {preflight['sector_known_sensitive']}")
    if preflight["colliding_catalogued_patch_sites"]:
        print(f"  !! collides with catalogued patch site(s): "
              f"{preflight['colliding_catalogued_patch_sites']}")
    if not preflight["touched_functions"]:
        print("  no changed byte falls inside a known corpus function (pure literal-pool/"
              "data region, or a corpus coverage gap - see export_patch_sites.py's "
              "live-ram-hook entry for a real example of the latter)")
    for key, info in preflight["touched_functions"].items():
        print(f"  function: {info['name']} ({key}) - patch_risk={info['patch_risk']}")
        for r in info["patch_risk_reasons"]:
            print(f"      {r}")
    if preflight["untouched_addresses_in_diff"]:
        print(f"  {preflight['untouched_addresses_in_diff']} changed byte(s) fall outside "
              f"any known corpus function")

    dynamic = None
    final_verdict = None
    exit_code = 0

    if args.skip_dynamic:
        print("\n(--skip-dynamic: not attempting either QEMU backend)")
    else:
        print("\n== dynamic verification ==")
        if not qemu_boot_diff.available():
            print("  skipped: qemu-system-cskyv2 is not on PATH (it is inside this repo's Docker "
                  "image - see docker/README.md). The corpus-side findings above are everything "
                  "this run can report.")
        else:
            if args.seconds is not None:
                print("  note: --seconds is obsolete and ignored - each boot now runs until the "
                      "probe key script completes (see --timeout)")

            iram_path = args.iram
            if iram_path is not None and str(iram_path) in ("", "."):
                iram_path = None  # --iram= : derive per composed image
            elif iram_path is not None and not iram_path.exists():
                print(f"  WARN: --iram path {iram_path} does not exist - deriving IRAM from each "
                      f"composed image instead")
                iram_path = None

            print("  qemu-system-cskyv2 found on PATH; composing stock and patched images "
                  "(compose_qemu_image.py) and booting both...")
            result = qemu_boot_diff.verify(args.stock, modded, offset, iram_path=iram_path,
                                           keyseq=args.keyseq, timeout=args.timeout,
                                           keep_dir=args.keep_dir)
            for m in result["infos"]: print(f"  info: {m}")
            for m in result["warns"]: print(f"  WARN: {m}")
            for m in result["fails"]: print(f"  FAIL: {m}")

            def fmt(frames):
                return " ".join(f"s{f['step']}:{f['nonblack']}" for f in frames) or "(none)"
            if result["stock"] is not None:
                print("  settled frames (key step:non-black pixels):")
                print(f"    stock   {fmt(result['frames_stock'])}")
                print(f"    patched {fmt(result['frames_patched'])}")

            # Translated once, used both by the prints below and by --json.
            outside_mod_translated = translate_pcs_to_functions(
                functions_by_start, result["outside_mod_sample"])
            outside_stock_translated = translate_pcs_to_functions(
                functions_by_start, result["outside_stock_sample"])
            if result["outside_mod_sample"] or result["outside_stock_sample"]:
                print("\n== translating changed code addresses to corpus functions ==")
                if result["outside_mod_sample"]:
                    print("  ran in PATCHED but not stock (outside the patched sector):")
                    for t in outside_mod_translated:
                        name = t["corpus_function"] or "(no corpus function at this address)"
                        print(f"    {t['pc']} -> {name}")
                if result["outside_stock_sample"]:
                    print("  ran in STOCK but not patched:")
                    for t in outside_stock_translated:
                        name = t["corpus_function"] or "(no corpus function at this address)"
                        print(f"    {t['pc']} -> {name}")
                print("  (first 5 addresses per category - pass --keep-dir and read the in_asm "
                      "trace in each run's qemu.log for the full set)")
            if result["keep_dir"]:
                print(f"\n  runs kept in {result['keep_dir']}/{{stock,patched}} "
                      f"(render with: render_frames.py --rundir {result['keep_dir']}/patched)")

            print(f"\n== VERDICT: {result['verdict']} ==")
            print("  Scope: boot to standby plus the probe key script only, on the -M dm32 model "
                  "(no RF/DMR, no codeplug, QEMU-only patches applied to both images). Code the "
                  "probe never reaches is not exercised; see qemu_boot_diff.py's docstring.")
            dynamic = {
                "infos": result["infos"],
                "warns": result["warns"],
                "fails": result["fails"],
                "verdict": result["verdict"],
                "frames_stock": result["frames_stock"],
                "frames_patched": result["frames_patched"],
                "outside_mod_translated": outside_mod_translated,
                "outside_stock_translated": outside_stock_translated,
                "keep_dir": str(result["keep_dir"]) if result["keep_dir"] else None,
            }
            final_verdict = result["verdict"]
            exit_code = EXIT_CODES.get(result["verdict"], 1)

    if args.json is not None:
        payload = {
            "preflight": preflight,
            "dynamic": dynamic,
            "verdict": final_verdict,
            "exit_code": exit_code,
        }
        line = json.dumps(payload, separators=(",", ":"))
        if args.json == "-":
            print(line)
        else:
            pathlib.Path(args.json).write_text(line + "\n")
    sys.exit(exit_code)


if __name__ == "__main__":
    main()

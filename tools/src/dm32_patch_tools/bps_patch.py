"""Create, apply and inspect BPS ("beat") patches for DM-32UV program-flash images.

WHY THIS EXISTS: a patched 1 MB image cannot be shared - it carries the whole vendor firmware -
but a BPS patch carries only the bytes a patch build changed, plus CRC32s of the exact source it
expects and the exact target it must produce. Someone with their own verified backup of the same
build applies it locally and gets a byte-identical patched image, or a clear refusal.

FORMAT (byuu's BPS spec, the ROM-hacking format Floating IPS / beat / RomPatcher.js read):
    "BPS1"
    varint source_size, varint target_size, varint metadata_size, metadata bytes
    actions until len(patch) - 12, each varint ((length - 1) << 2 | command):
        0 SourceRead   target[out:out+len] = source[out:out+len]
        1 TargetRead   followed by `len` literal bytes
        2 SourceCopy   followed by signed varint delta; source_rel += delta, copy from source
        3 TargetCopy   followed by signed varint delta; target_rel += delta, copy from target
                       (byte by byte - may overlap the bytes being written, i.e. RLE)
    u32 LE CRC32(source), u32 LE CRC32(target), u32 LE CRC32(every preceding patch byte)
varint: 7 bits per byte, LSB group first, high bit set on the LAST byte, and every non-final
group is "minus one" (value -= 1 after each shift) so each number has exactly one encoding.
Signed delta: (abs(d) << 1) | (d < 0).

`apply` implements all four actions, so patches made by other BPS encoders (flips, beat) apply
too. `create` emits SourceRead for unchanged runs and TargetRead for changed runs, with a
TargetCopy for long runs of a single repeated byte (e.g. 0xFF padding a patch erased). Equal
runs shorter than MERGE_GAP inside a changed region are folded into the TargetRead, since a
separate action costs more than the bytes it saves.

Metadata is JSON (BPS leaves its format to the creator): patch name, firmware build, flash base,
and the 4 KB sectors the patch changes as flash addresses - `info` prints it.

SAFETY - what `create` refuses to put into a patch (exit 2), and `apply` refuses to write:
  * any difference in the PER-UNIT parameter sector 0x0300b000-0x0300bfff (file 0xb000-0xbfff):
    eFuse-derived binding record at +0x10c plus per-unit hardware bytes (scrub_unit_sector.py,
    occupied_regions.json). A patch carrying it would stamp one radio's identity onto another.
  * any of compose_qemu_image.py's three QEMU-ONLY patch sites: the ALPU-MP bypass sector
    (file 0xc6000-0xc6fff), the auto-power-off battery-classifier NOPs (file 0x1bde0-0x1bde3)
    and the binding record (file 0xb10c, already inside the per-unit sector). Those exist only to
    boot stock firmware under the emulator and defeat real anti-clone/safety logic on hardware.
  * any region listed under `occupied_withheld` in occupied_regions.json (contents not reproduced
    by the shipped base image; a difference there is an artefact, not a patch).
There is no override flag for these. A BPS made by this tool cannot carry them; a BPS made
elsewhere that does is refused at `apply` before the output file is written.

THE PER-UNIT SECTOR AND THE CRC32s. The base image this repo ships has 0x0300b000-0x0300bfff
blanked to 0xFF (scrub_unit_sector.py); a user's own radio backup has that radio's real bytes
there. A whole-image source CRC32 made against one would never match the other. So, for full
1 MiB images, this tool computes BOTH CRC32s over the image with that sector blanked to 0xFF
("normalised"):
  * `create` normalises source and target before encoding. The patch therefore never contains,
    and its CRCs never depend on, anybody's per-unit bytes - whether it was made from the
    scrubbed base or from a developer's own unscrubbed backup.
  * `apply` normalises the SOURCE, verifies the source CRC32 against that, decodes, verifies the
    target CRC32, and then copies the applier's OWN 0xb000-0xbfff bytes back into the output, so
    apply never writes that range: the output is the user's backup with only the patch's sectors
    changed. It then re-checks that every differing byte between the user's source and the output
    lies inside the patch's declared changed sectors.
  * Fallback: a BPS made by another tool against a raw (unscrubbed) image is tried against the raw
    source if the normalised CRC fails; that only matches the exact radio the patch was made on.
Consequence for other BPS tools (flips, RomPatcher.js): a patch from this tool is a standard BPS
against the SCRUBBED image. They will refuse a raw backup (source CRC mismatch); scrubbing a copy
first makes them apply, but their output then has a blank per-unit sector and must not be flashed
over it. Use `bps_patch.py apply` for real backups.

OUTPUT FILE GUARD: OUT may not resolve to the same file as any input, and an existing OUT is
refused unless --force. Output is written to a temporary file in the same directory and renamed
into place only after every check passed, so a refusal or crash never truncates anything.

Neither subcommand writes to a radio. Flashing remains a manual, human-run step (stage_sectors.py
turns the applied image into per-sector files; see this repo's CLAUDE.md).

Usage:
    python3 bps_patch.py create SOURCE.bin TARGET.bin OUT.bps [--name N] [--description T] [--force]
    python3 bps_patch.py apply  SOURCE.bin PATCH.bps OUT.bin [--force]
    python3 bps_patch.py info   PATCH.bps
"""
from __future__ import annotations

import argparse
import datetime
import json
import os
import pathlib
import tempfile
import sys
import zlib

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
# Single source of truth for the emulator-only patch sites: if compose_qemu_image.py moves one,
# this tool's refusal moves with it.
from scrub_unit_sector import SECTOR_OFFSET as UNIT_SECTOR_OFFSET  # noqa: E402
from scrub_unit_sector import SECTOR_SIZE as UNIT_SECTOR_SIZE  # noqa: E402
from compose_qemu_image import (  # noqa: E402
    ALPU_SECTOR_OFFSET,
    AUTOPOWEROFF_OFFSET,
    AUTOPOWEROFF_PATCH,
    FLASH_BASE,
    FLASH_SIZE,
    HWBIND_OFFSET,
    HWBIND_PATCH,
    SECTOR_SIZE,
)

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
OCCUPIED_JSON = REPO_ROOT / "data" / "firmware" / "patching" / "occupied_regions.json"

MAGIC = b"BPS1"
FIRMWARE_BUILD = "DM32.00.01.048"
SOURCE_READ, TARGET_READ, SOURCE_COPY, TARGET_COPY = range(4)
ACTION_NAMES = ("SourceRead", "TargetRead", "SourceCopy", "TargetCopy")
MERGE_GAP = 4      # equal runs shorter than this inside a changed region go into the TargetRead
RLE_MIN = 16       # a repeated-byte run at least this long inside a TargetRead becomes a TargetCopy

UNIT_SECTOR = (UNIT_SECTOR_OFFSET, UNIT_SECTOR_OFFSET + UNIT_SECTOR_SIZE)


def normalise(img: bytes) -> bytes:
    """A full 1 MiB image with the per-unit sector blanked to 0xFF; anything else unchanged."""
    if len(img) != FLASH_SIZE:
        return img
    lo, hi = UNIT_SECTOR
    return img[:lo] + b"\xff" * (hi - lo) + img[hi:]


def safe_write(out: pathlib.Path, data: bytes, inputs: list[pathlib.Path], force: bool) -> None:
    """Write `data` to `out` atomically, refusing to clobber an input or (without --force) any
    existing file. Exists because a mixed-up argument order once truncated a committed image."""
    out_r = out.resolve()
    for p in inputs:
        if out_r == p.resolve() or (out.exists() and p.exists() and os.path.samefile(out, p)):
            _refuse([f"{out} is the same file as input {p}"], "output would overwrite an input")
    if out.exists() and not force:
        _refuse([f"{out} already exists (pass --force to replace it)"], "output exists")
    fd, tmp = tempfile.mkstemp(prefix=f".{out.name}.", dir=out_r.parent)
    try:
        with os.fdopen(fd, "wb") as f:
            f.write(data)
        os.replace(tmp, out_r)
    except BaseException:
        if os.path.exists(tmp):
            os.unlink(tmp)
        raise


def protected_ranges() -> list[tuple[int, int, str]]:
    """(start, end_exclusive, why) file-offset ranges no patch may touch."""
    rngs = [
        (UNIT_SECTOR[0], UNIT_SECTOR[1],
         "PER-UNIT parameter sector 0x0300b000-0x0300bfff (eFuse-derived binding record, "
         "per-unit hardware bytes)"),
        (ALPU_SECTOR_OFFSET, ALPU_SECTOR_OFFSET + SECTOR_SIZE,
         "QEMU-only ALPU-MP anti-clone bypass sector (compose_qemu_image.py)"),
        (AUTOPOWEROFF_OFFSET, AUTOPOWEROFF_OFFSET + len(AUTOPOWEROFF_PATCH),
         "QEMU-only auto-power-off battery-classifier patch (compose_qemu_image.py)"),
        (HWBIND_OFFSET, HWBIND_OFFSET + len(HWBIND_PATCH),
         "QEMU-only hardware-binding record patch (compose_qemu_image.py)"),
    ]
    if OCCUPIED_JSON.exists():
        for r in json.loads(OCCUPIED_JSON.read_text()).get("occupied_withheld", []):
            rngs.append((int(r["start"], 16), int(r["end"], 16),
                         f"withheld region (occupied_regions.json): {r.get('what', '')[:80]}"))
    return rngs


class BpsError(Exception):
    """Malformed patch, CRC mismatch, or a refused (protected) difference."""


# ---- primitives ------------------------------------------------------------------------------

def encode_num(n: int) -> bytes:
    if n < 0:
        raise ValueError("BPS numbers are unsigned")
    out = bytearray()
    while True:
        x = n & 0x7F
        n >>= 7
        if n == 0:
            out.append(0x80 | x)
            return bytes(out)
        out.append(x)
        n -= 1


def decode_num(buf: bytes, pos: int) -> tuple[int, int]:
    n, shift = 0, 1
    while True:
        if pos >= len(buf):
            raise BpsError("truncated varint")
        x = buf[pos]
        pos += 1
        n += (x & 0x7F) * shift
        if x & 0x80:
            return n, pos
        shift <<= 7
        n += shift


def encode_signed(d: int) -> bytes:
    return encode_num((abs(d) << 1) | (1 if d < 0 else 0))


def crc32(b: bytes) -> int:
    return zlib.crc32(b) & 0xFFFFFFFF


def diff_runs(src: bytes, tgt: bytes) -> list[tuple[int, int]]:
    """Maximal [start, end) runs where tgt differs from src (positions past len(src) differ)."""
    runs, i, n, m = [], 0, len(tgt), len(src)
    while i < n:
        if i < m and src[i] == tgt[i]:
            i += 1
            continue
        j = i
        while j < n and not (j < m and src[j] == tgt[j]):
            j += 1
        runs.append((i, j))
        i = j
    return runs


def check_protected(src: bytes, tgt: bytes) -> list[str]:
    """Human-readable violations: protected ranges where tgt differs from src."""
    bad = []
    for lo, hi, why in protected_ranges():
        a, b = src[lo:hi], tgt[lo:hi]
        if a == b:
            continue
        first = next((k for k in range(max(len(a), len(b)))
                      if k >= len(a) or k >= len(b) or a[k] != b[k]), 0) + lo
        bad.append(f"file {lo:#07x}-{hi - 1:#07x} (flash {FLASH_BASE + lo:#010x}), first "
                   f"difference at file {first:#07x}: {why}")
    return bad


def changed_sectors(src: bytes, tgt: bytes) -> list[int]:
    size = max(len(src), len(tgt))
    return [off for off in range(0, size, SECTOR_SIZE)
            if src[off:off + SECTOR_SIZE] != tgt[off:off + SECTOR_SIZE]]


# ---- encoder ---------------------------------------------------------------------------------

def encode(src: bytes, tgt: bytes, metadata: bytes) -> bytes:
    out = bytearray(MAGIC)
    out += encode_num(len(src)) + encode_num(len(tgt)) + encode_num(len(metadata)) + metadata

    # merge diff runs separated by short equal gaps
    merged: list[list[int]] = []
    for lo, hi in diff_runs(src, tgt):
        if merged and lo - merged[-1][1] < MERGE_GAP:
            merged[-1][1] = hi
        else:
            merged.append([lo, hi])

    target_rel = 0  # BPS TargetCopy relative pointer (persists across actions)
    pos = 0

    def source_read(n: int) -> None:
        nonlocal out
        out += encode_num(((n - 1) << 2) | SOURCE_READ)

    def target_read(lo: int, hi: int) -> None:
        nonlocal out
        out += encode_num(((hi - lo - 1) << 2) | TARGET_READ) + tgt[lo:hi]

    for lo, hi in merged:
        if lo > pos:
            source_read(lo - pos)
        # literal region [lo, hi): split long single-byte runs into TargetRead(1) + TargetCopy
        i = lit = lo
        while i < hi:
            j = i + 1
            while j < hi and tgt[j] == tgt[i]:
                j += 1
            if j - i >= RLE_MIN:
                target_read(lit, i + 1)              # includes the run's first byte
                delta = i - target_rel               # copy source: that first byte
                out += encode_num(((j - i - 1 - 1) << 2) | TARGET_COPY) + encode_signed(delta)
                target_rel = i + (j - i - 1)          # pointer advances by the copy length
                lit = j
            i = j
        if hi > lit:
            target_read(lit, hi)
        pos = hi
    if pos < len(tgt):
        source_read(len(tgt) - pos)  # tail equal (diff_runs marks past-source bytes as differing)

    out += crc32(src).to_bytes(4, "little") + crc32(tgt).to_bytes(4, "little")
    out += crc32(bytes(out)).to_bytes(4, "little")
    return bytes(out)


# ---- decoder ---------------------------------------------------------------------------------

def parse_header(patch: bytes) -> dict:
    if len(patch) < 4 + 3 + 12 or patch[:4] != MAGIC:
        raise BpsError("not a BPS patch (missing 'BPS1' magic)")
    pos = 4
    src_size, pos = decode_num(patch, pos)
    tgt_size, pos = decode_num(patch, pos)
    meta_size, pos = decode_num(patch, pos)
    metadata = patch[pos:pos + meta_size]
    pos += meta_size
    end = len(patch) - 12
    if pos > end:
        raise BpsError("truncated patch header")
    src_crc = int.from_bytes(patch[end:end + 4], "little")
    tgt_crc = int.from_bytes(patch[end + 4:end + 8], "little")
    patch_crc = int.from_bytes(patch[end + 8:end + 12], "little")
    return dict(source_size=src_size, target_size=tgt_size, metadata=metadata,
                actions_start=pos, actions_end=end, source_crc=src_crc, target_crc=tgt_crc,
                patch_crc=patch_crc, patch_crc_ok=crc32(patch[:end + 8]) == patch_crc)


def decode(src: bytes, patch: bytes, stats: dict | None = None) -> bytes:
    h = parse_header(patch)
    if not h["patch_crc_ok"]:
        raise BpsError("patch file CRC32 mismatch - the .bps itself is corrupt or truncated")
    if len(src) != h["source_size"]:
        raise BpsError(f"source is {len(src)} bytes, patch expects {h['source_size']}")
    if crc32(src) != h["source_crc"]:
        raise BpsError(f"source CRC32 {crc32(src):08x} != expected {h['source_crc']:08x} - this "
                       f"is not the exact image the patch was made against")
    tgt = bytearray(h["target_size"])
    out = src_rel = tgt_rel = 0
    pos, end = h["actions_start"], h["actions_end"]
    counts = [0, 0, 0, 0]
    while pos < end:
        data, pos = decode_num(patch, pos)
        cmd, length = data & 3, (data >> 2) + 1
        counts[cmd] += 1
        if out + length > len(tgt):
            raise BpsError(f"{ACTION_NAMES[cmd]} at output {out:#x} overruns target size")
        if cmd == SOURCE_READ:
            if out + length > len(src):
                raise BpsError("SourceRead past end of source")
            tgt[out:out + length] = src[out:out + length]
        elif cmd == TARGET_READ:
            if pos + length > end:
                raise BpsError("TargetRead past end of patch data")
            tgt[out:out + length] = patch[pos:pos + length]
            pos += length
        else:
            d, pos = decode_num(patch, pos)
            d = -(d >> 1) if d & 1 else d >> 1
            if cmd == SOURCE_COPY:
                src_rel += d
                if src_rel < 0 or src_rel + length > len(src):
                    raise BpsError("SourceCopy out of source bounds")
                tgt[out:out + length] = src[src_rel:src_rel + length]
                src_rel += length
            else:
                tgt_rel += d
                if tgt_rel < 0 or tgt_rel >= out:
                    raise BpsError("TargetCopy reads target bytes not yet written")
                for k in range(length):  # byte by byte: overlap is legal (RLE)
                    tgt[out + k] = tgt[tgt_rel + k]
                tgt_rel += length
        out += length
    if out != len(tgt):
        raise BpsError(f"actions produced {out} bytes, header says {len(tgt)}")
    if crc32(bytes(tgt)) != h["target_crc"]:
        raise BpsError(f"target CRC32 {crc32(bytes(tgt)):08x} != expected {h['target_crc']:08x} "
                       f"- refusing to write a result that is not the patch author's image")
    if stats is not None:
        stats.update({ACTION_NAMES[i]: counts[i] for i in range(4)})
    return bytes(tgt)


# ---- CLI -------------------------------------------------------------------------------------

def _refuse(msg_lines: list[str], header: str) -> None:
    print(f"REFUSED: {header}", file=sys.stderr)
    for line in msg_lines:
        print(f"  {line}", file=sys.stderr)
    sys.exit(2)


def cmd_create(a: argparse.Namespace) -> None:
    src, tgt = a.source.read_bytes(), a.target.read_bytes()
    if not a.any_size and (len(src) != FLASH_SIZE or len(tgt) != FLASH_SIZE):
        sys.exit(f"FAIL: source is {len(src)} bytes, target {len(tgt)}; both must be full "
                 f"{FLASH_SIZE:#x}-byte program-flash images (pass --any-size to override)")
    bad = check_protected(src, tgt)
    if bad:
        _refuse(bad, "target differs from source in protected range(s); a BPS made by this "
                     "tool may never carry these (no override)")
    sectors = changed_sectors(src, tgt)
    if not sectors:
        sys.exit("FAIL: source and target are identical - nothing to patch")
    unit_was_blank = src[UNIT_SECTOR[0]:UNIT_SECTOR[1]] == b"\xff" * UNIT_SECTOR_SIZE
    src, tgt = normalise(src), normalise(tgt)   # no per-unit bytes in the patch or its CRCs
    meta = {
        "format": "dm32uv-re bps_patch.py v1",
        "name": a.name or a.target.stem,
        "description": a.description or "",
        "firmware_build": FIRMWARE_BUILD,
        "flash_base": f"{FLASH_BASE:#010x}",
        "changed_sectors": [f"{FLASH_BASE + off:#010x}" for off in sectors],
        "changed_bytes": sum(hi - lo for lo, hi in diff_runs(src, tgt)),
        "crc_normalisation": (f"source/target CRC32s computed with flash "
                              f"{FLASH_BASE + UNIT_SECTOR[0]:#010x}-{FLASH_BASE + UNIT_SECTOR[1] - 1:#010x}"
                              f" blanked to 0xFF; bps_patch.py apply keeps the applier's own bytes "
                              f"there") if len(src) == FLASH_SIZE else "none",
        "created": datetime.date.today().isoformat(),
        "note": "Apply only to a verified full backup of the same build; flashing is a manual "
                "human step (stage_sectors.py).",
    }
    patch = encode(src, tgt, json.dumps(meta, indent=1).encode())
    # round-trip before writing: never emit a patch that does not reproduce the target
    if decode(src, patch) != tgt:
        raise AssertionError("encoder round-trip mismatch - bug in bps_patch.py")
    safe_write(a.out, patch, [a.source, a.target], a.force)
    if len(src) == FLASH_SIZE and not unit_was_blank:
        print("note: source had a non-blank per-unit sector; it was blanked before encoding, "
              "so nothing from it is in the patch")
    print(f"wrote {a.out} ({len(patch)} bytes): {len(sectors)} sector(s), "
          f"{meta['changed_bytes']} changed bytes, source crc32 {crc32(src):08x}, "
          f"target crc32 {crc32(tgt):08x}")
    for s in meta["changed_sectors"]:
        print(f"  {s}")


def cmd_apply(a: argparse.Namespace) -> None:
    raw, patch = a.source.read_bytes(), a.patch.read_bytes()
    stats: dict = {}
    norm = normalise(raw)
    mode = "normalised (per-unit sector blanked)" if norm is not raw else "raw"
    try:
        tgt = decode(norm, patch, stats)
        base = norm
    except BpsError as e:
        if norm == raw or "source CRC32" not in str(e):  # raw identical: nothing else to try
            _refuse([str(e)], "patch not applied, nothing written")
        try:  # a foreign BPS made against an unscrubbed image: only matches that same radio
            tgt, base, mode = decode(raw, patch, stats), raw, "raw (patch made against an unscrubbed image)"
        except BpsError as e2:
            _refuse([f"normalised: {e}", f"raw: {e2}"], "patch not applied, nothing written")
    bad = check_protected(base, tgt)
    if bad:
        _refuse(bad, "patch would change protected range(s); output NOT written")
    out = bytearray(tgt)
    if len(out) == FLASH_SIZE and len(raw) == FLASH_SIZE:
        out[UNIT_SECTOR[0]:UNIT_SECTOR[1]] = raw[UNIT_SECTOR[0]:UNIT_SECTOR[1]]  # never written
    out = bytes(out)
    # belt and braces: the output may differ from the USER'S source only in the patch's sectors
    declared = set(changed_sectors(base, tgt))
    actual = set(changed_sectors(raw, out))
    if not actual <= declared or check_protected(raw, out):
        _refuse([f"declared sectors {sorted(map(hex, declared))}, actual {sorted(map(hex, actual))}"],
                "output differs from source outside the patch's own sectors; NOT written")
    safe_write(a.out, out, [a.source, a.patch], a.force)
    print(f"source crc32 {crc32(base):08x} OK ({mode}); target crc32 {crc32(tgt):08x} OK")
    if len(out) == FLASH_SIZE:
        blank = raw[UNIT_SECTOR[0]:UNIT_SECTOR[1]] == b"\xff" * UNIT_SECTOR_SIZE
        print(f"per-unit sector {FLASH_BASE + UNIT_SECTOR[0]:#010x}: kept from source "
              f"({'blank' if blank else 'this unit’s own bytes'}), not written by the patch")
    print(f"wrote {a.out} ({len(out)} bytes); actions {stats}; {len(actual)} sector(s) changed:")
    for off in sorted(actual):
        print(f"  {FLASH_BASE + off:#010x}")


def cmd_info(a: argparse.Namespace) -> None:
    patch = a.patch.read_bytes()
    try:
        h = parse_header(patch)
    except BpsError as e:
        sys.exit(f"FAIL: {e}")
    print(f"patch        {a.patch} ({len(patch)} bytes), patch crc32 "
          f"{'OK' if h['patch_crc_ok'] else 'MISMATCH'} ({h['patch_crc']:08x})")
    print(f"source       {h['source_size']} bytes, crc32 {h['source_crc']:08x}")
    print(f"target       {h['target_size']} bytes, crc32 {h['target_crc']:08x}")
    md = h["metadata"]
    try:
        print("metadata     " + json.dumps(json.loads(md), indent=1).replace("\n", "\n             "))
    except (ValueError, UnicodeDecodeError):
        print(f"metadata     {len(md)} bytes (not JSON): {md[:200]!r}")
    counts = [0, 0, 0, 0]
    pos, end = h["actions_start"], h["actions_end"]
    while pos < end:
        data, pos = decode_num(patch, pos)
        cmd, length = data & 3, (data >> 2) + 1
        counts[cmd] += 1
        if cmd == TARGET_READ:
            pos += length
        elif cmd >= SOURCE_COPY:
            _, pos = decode_num(patch, pos)
    print("actions      " + ", ".join(f"{ACTION_NAMES[i]} {counts[i]}" for i in range(4)))


def main(argv: list[str] | None = None) -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("create", help="make a BPS from SOURCE -> TARGET")
    c.add_argument("source", type=pathlib.Path)
    c.add_argument("target", type=pathlib.Path)
    c.add_argument("out", type=pathlib.Path)
    c.add_argument("--name", help="patch name for the metadata (default: target file stem)")
    c.add_argument("--description", help="free-text description for the metadata")
    c.add_argument("--any-size", action="store_true",
                   help="allow images that are not exactly 1 MiB (protected ranges still enforced)")
    c.add_argument("--force", action="store_true", help="replace OUT if it already exists")
    c.set_defaults(func=cmd_create)
    p = sub.add_parser("apply", help="apply PATCH to SOURCE, verifying both CRC32s")
    p.add_argument("source", type=pathlib.Path)
    p.add_argument("patch", type=pathlib.Path)
    p.add_argument("out", type=pathlib.Path)
    p.add_argument("--force", action="store_true", help="replace OUT if it already exists")
    p.set_defaults(func=cmd_apply)
    i = sub.add_parser("info", help="print a patch's header, metadata and action counts")
    i.add_argument("patch", type=pathlib.Path)
    i.set_defaults(func=cmd_info)
    a = ap.parse_args(argv)
    a.func(a)


if __name__ == "__main__":
    main()

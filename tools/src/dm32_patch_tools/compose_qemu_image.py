"""Build an emulator-bootable 1MB image from a base image plus optional patched sectors, then
(unless told not to) splice in the three patches this project's own QEMU model needs just to
reach the standby screen with real stock firmware.

WHY THIS EXISTS: `qemu_run.py` and every doc in this submodule assume a single ready-to-boot
image. Getting there from the committed base image
(`data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin`) plus whatever sector(s) a
patch build actually touched was, before this script, a manual "cat the base, splice in my
sector(s), remember the three QEMU-only hacks" dance repeated by hand each session - exactly
the kind of repeatable step this submodule's other `compose_*`/`build_*` scripts exist to stop
re-deriving.

================================================================================================
THE THREE "QEMU-ONLY" PATCHES THIS SCRIPT CAN APPLY MUST NEVER BE FLASHED TO A REAL RADIO.
================================================================================================
They exist ONLY so the `-M dm32` board model can get a real stock firmware image past three
things it does not yet emulate correctly (the ALPU-MP anti-clone challenge-response, a
battery-classifier ADC read the model doesn't source realistically, and a hardware-binding
record check) far enough to reach the standby/menu screen for UI and patch-site work. On real
hardware all three stock behaviors are correct and load-bearing (the ALPU-MP check in
particular is this project's documented anti-clone gate - see the main repo's
`alpu-mp-auth-located` finding). Applying ANY of them to a sector that will be flashed to a
physical unit defeats real anti-clone/safety logic on that unit. `stage_sectors.py` (script 6
in this family) refuses to stage any of these three sectors unless explicitly told to allow it,
specifically to keep this mistake from happening by accident.

Each of the three patches is guarded by an assertion on the expected stock bytes at its site -
if the base image is not the exact build this script was written against, it aborts with a
clear message instead of silently writing garbage over unknown code.

Usage:
    python3 compose_qemu_image.py --out /tmp/boot.bin
    python3 compose_qemu_image.py --patched /path/to/full_1MB_patched.bin --out /tmp/boot.bin
    python3 compose_qemu_image.py --sector sector_030e1000_mine.bin@0x030e1000 --out /tmp/boot.bin
    python3 compose_qemu_image.py --out /tmp/boot.bin --iram-out
    python3 compose_qemu_image.py --out /tmp/boot.bin --no-qemu-only-patches
"""
from __future__ import annotations

import argparse
import pathlib
import re
import sys

from derive_iram import derive as derive_iram

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent

DEFAULT_BASE = REPO_ROOT / "data" / "firmware" / "patching" / "progmem_stock_DP570UV_20260926_FULL.bin"
ALPU_BYPASS_SECTOR = REPO_ROOT / "data" / "firmware" / "patching" / "sector_030c6000_alpubypass.bin"

FLASH_BASE = 0x03000000
FLASH_SIZE = 0x00100000
SECTOR_SIZE = 0x1000

# --- the three QEMU-only patches ------------------------------------------------------------
# Each entry: (flash offset, expected stock bytes, replacement bytes or None for "whole sector
# file"). Offsets are FILE offsets (== VA - FLASH_BASE) throughout this script.
ALPU_SECTOR_OFFSET = 0xC6000  # whole 4KB sector swap

AUTOPOWEROFF_OFFSET = 0x1BDE0
AUTOPOWEROFF_EXPECT = bytes.fromhex("63d86e00")
AUTOPOWEROFF_PATCH = bytes.fromhex("00330033")  # two movi16 r3,0 NOPs over the battery-classifier load

# The per-unit parameter sector (0x0300b000) is blanked in every image this repo ships
# (scrub_unit_sector.py): +0x10c is the record the firmware compares with a value derived from the
# SoC's eFuse ID. HWBIND_PATCH is the value this tool has always written there for QEMU (why
# that particular value satisfies the check under the model is not documented here).
HWBIND_OFFSET = 0xB10C
HWBIND_EXPECT = bytes.fromhex("ffffffff")
HWBIND_PATCH = bytes.fromhex("ff18ffff")


class ComposeError(Exception):
    """A precondition for composing the image failed."""


def parse_sector_arg(spec: str) -> tuple[pathlib.Path, int]:
    """Parse one `--sector FILE@0xOFFSET` argument."""
    m = re.match(r"^(.*)@(0[xX][0-9a-fA-F]+|\d+)$", spec)
    if not m:
        raise ComposeError(f"--sector must look like FILE@0xOFFSET, got {spec!r}")
    path = pathlib.Path(m.group(1))
    offset = int(m.group(2), 0)
    if offset % SECTOR_SIZE != 0:
        raise ComposeError(f"--sector offset {offset:#x} is not sector-aligned ({SECTOR_SIZE:#x})")
    data = path.read_bytes()
    if len(data) != SECTOR_SIZE:
        raise ComposeError(f"--sector file {path} is {len(data)} bytes, expected {SECTOR_SIZE:#x}")
    return path, offset


def diff_sectors(base: bytes, full_patched: bytes) -> list[int]:
    """Return the file offsets of every 4KB sector that differs between base and full_patched."""
    if len(full_patched) != len(base):
        raise ComposeError(
            f"--patched image is {len(full_patched)} bytes, base is {len(base)} bytes - "
            f"must be the same size to diff sector-by-sector"
        )
    changed = []
    for off in range(0, len(base), SECTOR_SIZE):
        if base[off:off + SECTOR_SIZE] != full_patched[off:off + SECTOR_SIZE]:
            changed.append(off)
    return changed


def apply_qemu_only_patches(image: bytearray) -> list[str]:
    """Apply the three QEMU-only patches in place. Aborts (ComposeError) if the expected stock
    bytes aren't found - see module docstring for why that's a hard stop, not a warning."""
    applied = []

    alpu_bytes = ALPU_BYPASS_SECTOR.read_bytes()
    if len(alpu_bytes) != SECTOR_SIZE:
        raise ComposeError(f"{ALPU_BYPASS_SECTOR} is {len(alpu_bytes)} bytes, expected {SECTOR_SIZE:#x}")
    image[ALPU_SECTOR_OFFSET:ALPU_SECTOR_OFFSET + SECTOR_SIZE] = alpu_bytes
    applied.append(f"ALPU bypass sector @ {FLASH_BASE+ALPU_SECTOR_OFFSET:#010x}")

    actual = bytes(image[AUTOPOWEROFF_OFFSET:AUTOPOWEROFF_OFFSET + 4])
    if actual != AUTOPOWEROFF_EXPECT:
        raise ComposeError(
            f"auto-power-off patch site {FLASH_BASE+AUTOPOWEROFF_OFFSET:#010x}: "
            f"expected stock bytes {AUTOPOWEROFF_EXPECT.hex(' ')}, got {actual.hex(' ')} "
            f"- expected a blanked per-unit sector (run scrub_unit_sector.py on images read "
            f"from a radio); refusing to patch blindly"
        )
    image[AUTOPOWEROFF_OFFSET:AUTOPOWEROFF_OFFSET + 4] = AUTOPOWEROFF_PATCH
    applied.append(f"auto-power-off NOP @ {FLASH_BASE+AUTOPOWEROFF_OFFSET:#010x}")

    actual = bytes(image[HWBIND_OFFSET:HWBIND_OFFSET + 4])
    if actual != HWBIND_EXPECT:
        raise ComposeError(
            f"hardware-binding patch site {FLASH_BASE+HWBIND_OFFSET:#010x}: "
            f"expected stock bytes {HWBIND_EXPECT.hex(' ')}, got {actual.hex(' ')} "
            f"- expected a blanked per-unit sector (run scrub_unit_sector.py on images read "
            f"from a radio); refusing to patch blindly"
        )
    image[HWBIND_OFFSET:HWBIND_OFFSET + 4] = HWBIND_PATCH
    applied.append(f"hardware-binding bypass @ {FLASH_BASE+HWBIND_OFFSET:#010x}")

    return applied


def compose(base_path: pathlib.Path, patched_path: pathlib.Path | None,
            sector_specs: list[str], qemu_only: bool) -> tuple[bytes, list[str]]:
    base = bytearray(base_path.read_bytes())
    if len(base) != FLASH_SIZE:
        raise ComposeError(f"base image {base_path} is {len(base)} bytes, expected {FLASH_SIZE:#x}")

    summary: list[str] = []

    if patched_path is not None:
        full_patched = patched_path.read_bytes()
        changed_offsets = diff_sectors(bytes(base), full_patched)
        for off in changed_offsets:
            base[off:off + SECTOR_SIZE] = full_patched[off:off + SECTOR_SIZE]
        summary.append(
            f"{len(changed_offsets)} sector(s) taken from {patched_path.name}: "
            + ", ".join(f"{FLASH_BASE+o:#010x}" for o in changed_offsets) if changed_offsets
            else f"0 sectors differed between base and {patched_path.name}"
        )

    for spec in sector_specs:
        path, offset = parse_sector_arg(spec)
        base[offset:offset + SECTOR_SIZE] = path.read_bytes()
        summary.append(f"sector from {path.name} @ {FLASH_BASE+offset:#010x}")

    if qemu_only:
        applied = apply_qemu_only_patches(base)
        summary.append("QEMU-only patches applied: " + "; ".join(applied))
    else:
        summary.append("QEMU-only patches SKIPPED (--no-qemu-only-patches)")

    return bytes(base), summary


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--base", type=pathlib.Path, default=DEFAULT_BASE,
                     help=f"base 1MB image (default: {DEFAULT_BASE.relative_to(REPO_ROOT)})")
    ap.add_argument("--patched", type=pathlib.Path, default=None,
                     help="a full 1MB patched image; only sectors that differ from --base are taken")
    ap.add_argument("--sector", action="append", default=[], metavar="FILE@0xOFFSET",
                     help="a 4096-byte sector file to splice in at the given flash offset "
                          "(repeatable)")
    ap.add_argument("--out", required=True, type=pathlib.Path, help="output bootable image")
    ap.add_argument("--no-qemu-only-patches", action="store_true",
                     help="do NOT apply the three QEMU-only patches (see module docstring) - "
                          "use this if you are composing an image for a purpose other than "
                          "booting it under this project's QEMU model")
    ap.add_argument("--iram-out", action="store_true",
                     help="also write iram.bin next to --out, derived from the composed image "
                          "exactly as the boot stub builds IRAM (so patches inside the IRAM load "
                          "image are included), and a 32KiB zero sram.bin (the two loader images "
                          "qemu_run.py needs)")
    args = ap.parse_args()

    try:
        image, summary = compose(args.base, args.patched, args.sector,
                                  qemu_only=not args.no_qemu_only_patches)
    except ComposeError as e:
        print(f"FAIL: {e}", file=sys.stderr)
        sys.exit(1)

    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_bytes(image)
    print(f"wrote {args.out} ({len(image)} bytes)")
    for line in summary:
        print(f"  - {line}")

    if args.iram_out:
        iram_dst = args.out.parent / "iram.bin"
        sram_dst = args.out.parent / "sram.bin"
        try:
            iram_dst.write_bytes(derive_iram(image))
        except ValueError as e:
            print(f"FAIL: --iram-out: {e}", file=sys.stderr)
            sys.exit(1)
        sram_dst.write_bytes(b"\x00" * 0x8000)
        print(f"wrote {iram_dst} (derived from the composed image, see derive_iram.py)")
        print(f"wrote {sram_dst} (32 KiB zero)")


if __name__ == "__main__":
    main()

"""Find every 4KB sector that differs between a patched full image and its stock counterpart,
and stage them as individually-flashable files plus a flasher command template.

WHY THIS EXISTS: `compose_qemu_image.py` goes stock -> bootable-under-QEMU; this script is the
other direction a finished patch needs - full patched image -> "here are the N actual sectors
that changed, verified, hashed, with the exact command to flash each one." Flashing is always a
manual human step (see this submodule's CLAUDE.md and every other script's docstring in this
family) - this script's job stops at producing files and printing commands, never at running them.

================================================================================================
FLASHING IS A MANUAL, HUMAN-RUN STEP. THIS SCRIPT NEVER FLASHES ANYTHING.
================================================================================================
Before running any printed command: have a VERIFIED FULL BACKUP of the exact unit being flashed
(per-unit calibration lives on a separate chip this program-flash doesn't touch, but a backup is
still the only unbrick path). Each printed
command template includes `--i-have-a-verified-backup` as a reminder of that precondition, not
as a tool invocation this script makes for you.

SAFETY GATES THIS SCRIPT ENFORCES BEFORE WRITING ANYTHING:
  1. Refuses (exit 2) if any touched sector is marked sensitive in meta/sectors.json's own
     `known_sensitive` field (non-null = sensitive - see export_sectors.py's docstring for what's
     catalogued there so far; absence of a flag is a starting point, not a safety guarantee).
  2. Refuses (assertion failure) if any of the THREE QEMU-ONLY sectors compose_qemu_image.py
     patches (file offsets 0xc6000, 0x1b000, 0xb000) shows up as changed here, UNLESS
     --allow-qemu-only is passed. Those three patches exist only to make the emulator boot
     stock firmware and must never reach a real radio (see compose_qemu_image.py's docstring) -
     if one of them is present in a "patched" image being staged for REAL hardware, that's
     almost certainly compose_qemu_image.py's own output being staged by mistake. The 0xb000
     sector is also PER-UNIT (eFuse-derived binding record, see scrub_unit_sector.py): writing it
     from any other image breaks that radio's binding check, so it is listed in
     occupied_regions.json too, and staging it is refused UNCONDITIONALLY (--allow-qemu-only
     does not override that).
"""
from __future__ import annotations

import argparse
import hashlib
import json
import pathlib
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
SECTORS_JSON = REPO_ROOT / "meta" / "sectors.json"

FLASH_BASE = 0x03000000
SECTOR_SIZE = 0x1000

# The three QEMU-only patch sectors from compose_qemu_image.py, as FILE offsets. Never allowed
# into a staged set of sectors meant for real hardware unless explicitly overridden.
QEMU_ONLY_SECTOR_OFFSETS = {0xC6000, 0x1B000, 0xB000}
PER_UNIT_SECTOR_OFFSET = 0xb000  # flash 0x0300b000, see main()

DEFAULT_FLASHER = "C7000_write_progmem_robust.py"


def diff_sectors(stock: bytes, patched: bytes) -> list[int]:
    if len(stock) != len(patched):
        raise SystemExit(
            f"FAIL: --stock is {len(stock)} bytes, --patched is {len(patched)} bytes - "
            f"must be the same size"
        )
    changed = []
    for off in range(0, len(stock), SECTOR_SIZE):
        if stock[off:off + SECTOR_SIZE] != patched[off:off + SECTOR_SIZE]:
            changed.append(off)
    return changed


def load_sensitive_sectors() -> dict[int, str]:
    """sector_number -> known_sensitive reason, for every sector flagged in meta/sectors.json."""
    if not SECTORS_JSON.exists():
        return {}
    data = json.loads(SECTORS_JSON.read_text())
    out = {}
    for num_str, info in data.get("sectors", {}).items():
        reason = info.get("known_sensitive")
        if reason:
            out[int(num_str)] = reason
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--patched", required=True, type=pathlib.Path, help="full patched 1MB image")
    ap.add_argument("--stock", required=True, type=pathlib.Path, help="full stock 1MB image")
    ap.add_argument("--out", required=True, type=pathlib.Path, help="output directory for staged sectors")
    ap.add_argument("--expect-sectors", default=None, metavar="0xADDR,0xADDR,...",
                     help="comma-separated flash addresses expected to be the ONLY ones that "
                          "changed; mismatch is reported as a warning, not a failure")
    ap.add_argument("--flasher", default=DEFAULT_FLASHER,
                     help=f"flasher command/path used in the printed template (default: {DEFAULT_FLASHER})")
    ap.add_argument("--allow-qemu-only", action="store_true",
                     help="allow staging one of the three QEMU-only sectors (0xc6000/0x1b000/"
                          "0xb000) - almost never what you want; see module docstring")
    args = ap.parse_args()

    stock = args.stock.read_bytes()
    patched = args.patched.read_bytes()
    changed = diff_sectors(stock, patched)

    if not changed:
        print("0 sectors differ between --stock and --patched - nothing to stage")
        return

    sensitive = load_sensitive_sectors()
    blocked = []
    for off in changed:
        sector_num = off // SECTOR_SIZE
        if sector_num in sensitive:
            blocked.append((off, sector_num, sensitive[sector_num]))
    if blocked:
        print("FAIL: refusing to stage - touched sector(s) are marked known_sensitive in "
              f"{SECTORS_JSON.relative_to(REPO_ROOT)}:", file=sys.stderr)
        for off, num, reason in blocked:
            print(f"  sector {num} (flash {FLASH_BASE+off:#010x}): {reason}", file=sys.stderr)
        sys.exit(2)

    # The per-unit parameter sector (flash 0x0300b000; see occupied_regions.json and
    # docs/rtos-and-memory.md). Every radio's copy is different, and the shipped images carry it
    # blanked, so a "difference" there is either compose_qemu_image.py's binding patch or an
    # attempt to write another unit's data. Refused unconditionally: --allow-qemu-only does not
    # override this.
    if PER_UNIT_SECTOR_OFFSET in changed:
        print(f"FAIL: refusing to stage flash {FLASH_BASE + PER_UNIT_SECTOR_OFFSET:#010x}: it is the "
              "per-unit parameter sector (different on every radio; never written by a patch). "
              "No flag overrides this.", file=sys.stderr)
        sys.exit(2)

    qemu_only_hit = [off for off in changed if off in QEMU_ONLY_SECTOR_OFFSETS]
    if qemu_only_hit and not args.allow_qemu_only:
        print("FAIL: changed sector(s) match compose_qemu_image.py's QEMU-ONLY patch sectors "
              "(never meant for real hardware):", file=sys.stderr)
        for off in qemu_only_hit:
            print(f"  flash {FLASH_BASE+off:#010x} (file offset {off:#x})", file=sys.stderr)
        print("Pass --allow-qemu-only only if you are deliberately staging an "
              "emulator-only image.", file=sys.stderr)
        sys.exit(2)
    assert args.allow_qemu_only or not (set(changed) & QEMU_ONLY_SECTOR_OFFSETS), \
        "QEMU-only sector slipped past the check above"

    if args.expect_sectors:
        expected_addrs = [int(x, 0) for x in args.expect_sectors.split(",")]
        expected_sector_nums = {(addr - FLASH_BASE) // SECTOR_SIZE for addr in expected_addrs}
        actual_sector_nums = {off // SECTOR_SIZE for off in changed}
        if expected_sector_nums != actual_sector_nums:
            print(f"warning: --expect-sectors did not match the sectors that actually changed "
                  f"(expected sector#s {sorted(expected_sector_nums)}, got {sorted(actual_sector_nums)})",
                  file=sys.stderr)

    args.out.mkdir(parents=True, exist_ok=True)
    manifest_lines = []
    print(f"{len(changed)} sector(s) differ:\n")
    print("=" * 70)
    print("REMINDER: flashing is a manual, human-run step. Before running ANY command below,")
    print("have a VERIFIED FULL BACKUP of the exact unit being flashed.")
    print("=" * 70)
    print()

    for off in changed:
        addr = FLASH_BASE + off
        sector_bytes = patched[off:off + SECTOR_SIZE]
        fname = f"sector_{addr:08x}_patched.bin"
        fpath = args.out / fname
        fpath.write_bytes(sector_bytes)

        # verify what was written matches the patched image exactly.
        written_back = fpath.read_bytes()
        if written_back != sector_bytes:
            print(f"FAIL: {fpath} did not verify after writing", file=sys.stderr)
            sys.exit(1)

        digest = hashlib.sha256(sector_bytes).hexdigest()
        manifest_lines.append(f"{digest}  {fname}")

        print(f"sector {addr:#010x}: wrote {fpath}, verified, sha256 {digest[:16]}...")
        print(f"  {args.flasher} <PORT> {fpath} {addr - FLASH_BASE:#x} --i-have-a-verified-backup")
        print()

    manifest_path = args.out / "MANIFEST.sha256"
    manifest_path.write_text("\n".join(manifest_lines) + "\n")
    print(f"wrote {manifest_path}")
    print(f"\nverify later with: cd {args.out} && sha256sum -c MANIFEST.sha256")


if __name__ == "__main__":
    main()

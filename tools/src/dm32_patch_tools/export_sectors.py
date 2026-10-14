"""Checklist item D: flash-sector awareness.

Maps every FLASH-resident corpus function (addr >= 0x03000000) to the 4KB program-flash
sector that contains it, and the reverse index (sector -> functions in it). This is the
blast-radius question a patch author needs answered before proposing any change: the
program flash's own firmware-side sector writeback path
(flash_cache_sector_modify_and_writeback @0x0301ca44, see the main repo's
docs/CALIBRATION-SAFETY.md) reads a WHOLE 4KB sector into a cache buffer, splices in the
intended bytes, and writes the whole sector back - so every other function sharing that
sector is rewritten too, whether the patch touches it or not.

IRAM-resident functions (addr < 0x03000000, e.g. 0x0001023c) are NOT in this map. IRAM is
volatile SRAM populated at runtime, not flash - there is no sector-erase/rewrite hazard
there in the first place, so the whole premise of this checklist item does not apply to it.

Sector size (0x1000 = 4096 bytes) and chip identity (the 1MB GD25Q80 PROGRAM flash, distinct
from the 16MB W25Q128 DATA chip that holds the codeplug and per-unit calibration) are both
taken from docs/CALIBRATION-SAFETY.md in the main repo, not re-derived here.

What this script does NOT claim: per-unit calibration lives entirely on the OTHER flash
chip (the data chip, never covered by this corpus - see the main repo's
docs/CALIBRATION-SAFETY.md "there are TWO SPI-NOR chips" correction), so no program-flash
sector in this map can be "calibration-bearing" the way the checklist's wording suggests.
What IS flagged `known_sensitive` here is the one patch site this project has concretely
documented and reused (the ALPU-MP anti-clone bypass at flash 0xC6866, per
notes/openrtx-port-viability-checklist.md in the main repo) - this is a STARTING POINT, not
a complete catalogue. A sector not flagged here has simply not yet had a documented reason
to avoid it; absence of a flag is not a safety guarantee, the same lesson
no-free-flash-on-the-data-chip already taught about treating "nothing documented" as "safe".
"""
from __future__ import annotations

import argparse
import json
import pathlib

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
OUT_JSON = REPO_ROOT / "meta" / "sectors.json"

SECTOR_SIZE = 0x1000
FLASH_BASE_ADDR = 0x03000000  # first byte of the program flash's own address space

# Concretely documented reasons to avoid a program-flash sector, seeded from this project's
# own notes (see module docstring). Not exhaustive - see the docstring above.
#
# ADDRESSES ARE ABSOLUTE VAs (0x0300xxxx), not file offsets. The ALPU-bypass site is recorded
# elsewhere as "flash file offset 0xc6866 (VA 0x030c6866)" precisely because the two are easy to
# confuse (see PROVENANCE.md's own load-base field for a different instance of the same mistake).
# The same note confirms the sector size claimed above: "in the 4KB sector 0xc6000-0xc7000" is
# exactly SECTOR_SIZE under this script's own math.
KNOWN_SENSITIVE_ADDRS = {
    0x030C6866: "ALPU-MP anti-clone bypass patch site (IRAM 0x16c46, copied to this flash "
                "offset at boot) - required for any custom firmware to boot; patching this "
                "sector without knowing that destroys the bypass "
                "(data/firmware/patching/sector_030c6000_alpubypass.bin)",
}


def sector_of(addr: int) -> int:
    return (addr - FLASH_BASE_ADDR) // SECTOR_SIZE


def sector_range(sector: int) -> tuple[int, int]:
    start = FLASH_BASE_ADDR + sector * SECTOR_SIZE
    return start, start + SECTOR_SIZE  # end exclusive


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", type=pathlib.Path, default=OUT_JSON)
    args = ap.parse_args()

    functions = json.loads(FUNCTIONS_JSON.read_text())["functions"]
    flash_fns = [f for f in functions if int(f["addr"], 16) >= FLASH_BASE_ADDR]
    iram_count = len(functions) - len(flash_fns)

    sensitive_sectors = {
        sector_of(addr): reason for addr, reason in KNOWN_SENSITIVE_ADDRS.items()
    }

    sectors: dict[int, list[dict]] = {}
    for fn in flash_fns:
        addr = int(fn["addr"], 16)
        end_addr = addr + fn["size"]  # a function can span more than one sector
        first_sector = sector_of(addr)
        last_sector = sector_of(end_addr - 1) if fn["size"] > 0 else first_sector
        for s in range(first_sector, last_sector + 1):
            sectors.setdefault(s, []).append({
                "addr": fn["addr_hex"],
                "name": fn["name"],
                "size": fn["size"],
                "spans_sector_boundary": first_sector != last_sector,
            })

    out = {
        "sector_size": SECTOR_SIZE,
        "flash_base_addr": hex(FLASH_BASE_ADDR),
        "note": "Program flash (1MB GD25Q80, the XIP app image) only. The data chip "
                "(16MB W25Q128, codeplug + per-unit calibration) is a SEPARATE chip not "
                "covered by this corpus or this file - see this script's module docstring.",
        "iram_functions_excluded": iram_count,
        "sectors": {
            str(s): {
                "range": [hex(r) for r in sector_range(s)],
                "known_sensitive": sensitive_sectors.get(s),
                "function_count": len(fns),
                "functions_spanning_boundary": sum(1 for f in fns if f["spans_sector_boundary"]),
                "functions": sorted(fns, key=lambda f: f["addr"]),
            }
            for s, fns in sorted(sectors.items())
        },
    }

    args.out.write_text(json.dumps(out, indent=1))

    spanning = sum(
        1 for fns in sectors.values() for f in fns if f["spans_sector_boundary"]
    )
    print(f"wrote {len(sectors)} sectors covering {len(flash_fns)} flash functions "
          f"({iram_count} IRAM functions excluded - not flash-resident) to {args.out}")
    print(f"{spanning} functions span a sector boundary - patching either sector touches them")
    print(f"{len(sensitive_sectors)} sector(s) flagged known_sensitive (seeded, not exhaustive "
          f"- see module docstring)")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""Mechanically check address/size claims in this repo's prose docs against the shipped images.

Scans docs/*.md, tools/README.md, tools/examples/**/README.md and CLAUDE.md, one LINE at a time,
for claims it can decide from the firmware images in data/firmware/ plus
data/firmware/patching/occupied_regions.json, and prints one result per claim:

    <file>:<line>: PASS|FAIL|UNCHECKABLE  <kind>  <detail>

Exit status is 1 if any claim FAILs, else 0. Plain python3, no dependencies.

What it checks
--------------
* flash-bound    every 0x03xxxxxx address must be <= 0x03100000 (1 MB GD25Q80 program flash;
                 0x03100000 itself is allowed as an exclusive end bound).
* sram-bound     every 0x18xxxxxx address must be <= 0x18008000 (32 KB SRAM per the HR_C7000 v2.7
                 memory map; 0x18008000 allowed as an exclusive end bound).
* range-order    a written range `A`-`B` must have A < B.
* range-size     a size written right after a range ("8 KB", "(13 KB", "512 bytes", "1 MB") must
                 match the range length. An end address ending in ...fff (or not 4 KB aligned and
                 odd) is read as inclusive, otherwise exclusive. Tolerance 1%, or 10% after "~".
* free-claim     a range on a line saying free/erased/available/blank (and not "not free",
                 "never free", ...):
                   - flash: every byte must be 0xFF in progmem_stock_DP570UV_20260926_FULL.bin AND
                     the range must not overlap occupied_regions.json (which includes the PER-UNIT
                     sector 0x0300b000, blanked to 0xFF in shipped images but never free);
                   - SRAM: must not overlap the modem-owned 0x18000000-0x180007FF or the SRAM init
                     image destination 0x18000800-0x18004BFC. That is a STATIC check only; runtime
                     use is reported in the detail as unchecked.
                   - IRAM: must not overlap the boot-stub load+zero-fill region 0x10000-0x4A7B0.
* sector-number  "sector N" / "sectors N-M" (decimal) on a line that also carries a flash address:
                 N (and M) must equal (addr - 0x03000000) >> 12 for some address on the line
                 (an aligned address also counts for the sector before it, as an exclusive end).
                 Without a flash address on the same line: UNCHECKABLE.

What it cannot check (be honest about a PASS)
---------------------------------------------
* Claims split across lines (e.g. a range on one line and "free" on the next) are seen per line;
  the keyword or size may simply be missed. A PASS means "nothing contradicted on this line".
* Semantics: that an address is a given function/variable, that a region holds what the doc says,
  that RAM is free at runtime. Those need disassembly or a live capture (docs/live-ram-capture.md).
* Allocations made by this repo's own patches (Snake, RAMDUMP) are not in the stock image, so a
  free-claim covering them still PASSes; the docs must list them separately.
* A line can opt out with the marker `doc-claims: skip` (e.g. inside an HTML comment) when it
  quotes a deliberately wrong value (a correction note).
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[3]
FULL_IMAGE = REPO / "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin"
OCCUPIED_JSON = REPO / "data/firmware/patching/occupied_regions.json"

FLASH_BASE = 0x03000000
FLASH_END = 0x03100000          # exclusive; 1 MB
SRAM_BASE = 0x18000000
SRAM_END = 0x18008000           # exclusive; 32 KB
SECTOR = 0x1000

SRAM_STATIC_OCCUPIED = [
    (0x18000000, 0x18000800, "modem-owned SRAM"),
    (0x18000800, 0x18004BFC, "SRAM init image destination (occupied_regions.json)"),
]
IRAM_STATIC_OCCUPIED = [
    (0x00010000, 0x0004A7B0, "IRAM load image + zero-fill (boot stub)"),
]

HEX = r"0x[0-9a-fA-F][0-9a-fA-F_]*"
RANGE_RE = re.compile(rf"`?({HEX})`?\s*(?:–|—|-|\.\.|to)\s*`?({HEX})`?")
ADDR_RE = re.compile(HEX)
SIZE_RE = re.compile(r"(~|≈)?\s*((?<![\d,])\d{1,3}(?:,\d{3})+(?!\d)|\d+(?:\.\d+)?)\s*(KB|KiB|MB|MiB|bytes?)\b")
SECTOR_RE = re.compile(r"\bsectors?\s+(\d+)(?:\s*(?:–|—|-|to)\s*(\d+))?(?![\dxX])")
FREE_RE = re.compile(r"\b(free|erased|available|blank)\b", re.I)
NEG_RE = re.compile(r"\b(not|never|isn'?t|no longer|nor)\b[^.;|]{0,25}\b(free|erased|available|blank)\b", re.I)
SKIP_MARK = "doc-claims: skip"
UNITS = {"kb": 1024, "kib": 1024, "mb": 1 << 20, "mib": 1 << 20, "byte": 1, "bytes": 1}


def parse_hex(tok: str) -> int:
    return int(tok.replace("_", ""), 16)


def end_exclusive(end: int) -> int:
    """Read an end address as inclusive when it looks inclusive (..fff / odd), else exclusive."""
    if end & 0xFFF == 0xFFF or (end & 1):
        return end + 1
    return end


def load_occupied() -> list[tuple[int, int, str]]:
    data = json.loads(OCCUPIED_JSON.read_text())
    out = []
    for r in data["occupied"]:
        out.append((FLASH_BASE + int(r["start"], 16), FLASH_BASE + int(r["end"], 16),
                    r["what"].split(":")[0].split(",")[0][:60]))
    return out


def overlaps(lo: int, hi: int, regions) -> list[str]:
    return [f"{name} [{a:#010x}-{b:#010x})" for a, b, name in regions if lo < b and a < hi]


class Checker:
    def __init__(self) -> None:
        self.image = FULL_IMAGE.read_bytes()
        self.occupied = load_occupied()
        self.results: list[tuple[str, int, str, str, str]] = []

    def add(self, path: str, ln: int, status: str, kind: str, detail: str) -> None:
        self.results.append((path, ln, status, kind, detail))

    # -- individual checks -------------------------------------------------------------------
    def check_free_flash(self, lo: int, hi: int) -> tuple[str, str]:
        if hi > FLASH_END:
            return "FAIL", f"{lo:#010x}-{hi:#010x} runs past end of 1 MB flash"
        seg = self.image[lo - FLASH_BASE:hi - FLASH_BASE]
        bad = [i for i, b in enumerate(seg) if b != 0xFF]
        problems = []
        if bad:
            problems.append(f"{len(bad)} non-0xFF bytes in full image (first at {lo + bad[0]:#010x})")
        ov = overlaps(lo, hi, self.occupied)
        if ov:
            problems.append("overlaps occupied_regions.json: " + "; ".join(ov))
        if problems:
            return "FAIL", f"claimed free {lo:#010x}-{hi:#010x}: " + " / ".join(problems)
        return "PASS", f"{lo:#010x}-{hi:#010x} all 0xFF, no occupied_regions overlap"

    def check_free_ram(self, lo: int, hi: int, regions, what: str) -> tuple[str, str]:
        ov = overlaps(lo, hi, regions)
        if ov:
            return "FAIL", f"claimed free {what} {lo:#010x}-{hi:#010x} overlaps " + "; ".join(ov)
        return "PASS", (f"{what} {lo:#010x}-{hi:#010x} clear of known static occupants "
                        "(runtime use NOT checked)")

    # -- per line ----------------------------------------------------------------------------
    def scan_line(self, path: str, ln: int, line: str) -> None:
        if SKIP_MARK in line:
            return
        addrs = [(m.start(), parse_hex(m.group(0))) for m in ADDR_RE.finditer(line)]

        # flash / sram bounds
        for _, a in addrs:
            if 0x03000000 <= a <= 0x03FFFFFF:
                if a > FLASH_END:
                    self.add(path, ln, "FAIL", "flash-bound",
                             f"{a:#010x} is beyond 1 MB program flash (ends {FLASH_END - 1:#010x})")
            elif 0x18000000 <= a <= 0x18FFFFFF:
                if a > SRAM_END:
                    self.add(path, ln, "FAIL", "sram-bound",
                             f"{a:#010x} is beyond 32 KB SRAM (ends {SRAM_END - 1:#010x})")

        ranges = list(RANGE_RE.finditer(line))
        is_free = bool(FREE_RE.search(line)) and not NEG_RE.search(line)
        for i, m in enumerate(ranges):
            a, b = parse_hex(m.group(1)), parse_hex(m.group(2))
            if a < 0x100 or b < 0x100:      # small numbers: masks, codes, not addresses
                continue
            if a >= b:
                self.add(path, ln, "FAIL", "range-order", f"{m.group(0).strip()}: start >= end")
                continue
            hi = end_exclusive(b)
            length = hi - a

            # size stated right after the range (before the next range)
            stop = ranges[i + 1].start() if i + 1 < len(ranges) else len(line)
            tail = line[m.end():min(stop, m.end() + 60)]
            sm = SIZE_RE.search(tail)
            if sm:
                approx = bool(sm.group(1))
                stated = float(sm.group(2).replace(",", "")) * UNITS[sm.group(3).lower()]
                tol = 0.10 if approx else 0.01
                ok = abs(stated - length) <= tol * max(length, 1)
                self.add(path, ln, "PASS" if ok else "FAIL", "range-size",
                         f"{a:#010x}-{hi:#010x} is {length:#x} bytes ({length / 1024:g} KB); "
                         f"text says {sm.group(0).strip()}")

            if is_free:
                if 0x03000000 <= a < 0x04000000:
                    st, d = self.check_free_flash(a, hi)
                elif 0x18000000 <= a < 0x19000000:
                    st, d = self.check_free_ram(a, hi, SRAM_STATIC_OCCUPIED, "SRAM")
                elif 0x00010000 <= a < 0x00058000:
                    st, d = self.check_free_ram(a, hi, IRAM_STATIC_OCCUPIED, "IRAM")
                else:
                    st, d = "UNCHECKABLE", f"{a:#x}-{hi:#x}: not a flash/SRAM/IRAM address"
                self.add(path, ln, st, "free-claim", d)

        # sector numbers
        for sm in SECTOR_RE.finditer(line):
            nums = [int(sm.group(1))] + ([int(sm.group(2))] if sm.group(2) else [])
            flash = [a for _, a in addrs if FLASH_BASE <= a <= FLASH_END]
            if not flash:
                self.add(path, ln, "UNCHECKABLE", "sector-number",
                         f"'{sm.group(0)}' with no flash address on the same line")
                continue
            secs = set()
            for a in flash:
                secs.add((a - FLASH_BASE) >> 12)
                if a & 0xFFF == 0 and a > FLASH_BASE:
                    secs.add(((a - FLASH_BASE) >> 12) - 1)
            missing = [n for n in nums if n not in secs]
            if any(n > 255 for n in nums):
                self.add(path, ln, "FAIL", "sector-number",
                         f"'{sm.group(0)}': flash has only sectors 0-255")
            elif missing:
                self.add(path, ln, "FAIL", "sector-number",
                         f"'{sm.group(0)}' matches no address on the line "
                         f"(addresses there are sectors {sorted(secs)})")
            else:
                self.add(path, ln, "PASS", "sector-number",
                         f"'{sm.group(0)}' consistent with an address on the line")


def doc_files() -> list[Path]:
    files = sorted((REPO / "docs").glob("*.md"))
    files.append(REPO / "tools/README.md")
    files += sorted((REPO / "tools/examples").rglob("README.md"))
    files.append(REPO / "CLAUDE.md")
    return [f for f in files if f.is_file()]


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--failures-only", action="store_true", help="print only FAIL lines")
    ap.add_argument("files", nargs="*", type=Path, help="override the default file list")
    args = ap.parse_args(argv)

    chk = Checker()
    for f in (args.files or doc_files()):
        f = f.resolve()
        rel = str(f.relative_to(REPO)) if f.is_relative_to(REPO) else str(f)
        for ln, line in enumerate(f.read_text(encoding="utf-8").splitlines(), 1):
            chk.scan_line(rel, ln, line)

    counts = {"PASS": 0, "FAIL": 0, "UNCHECKABLE": 0}
    for path, ln, st, kind, detail in chk.results:
        counts[st] += 1
        if not args.failures_only or st == "FAIL":
            print(f"{path}:{ln}: {st:<11} {kind:<13} {detail}")
    print(f"\nsummary: {counts['PASS']} PASS, {counts['FAIL']} FAIL, "
          f"{counts['UNCHECKABLE']} UNCHECKABLE ({len(chk.results)} claims)")
    return 1 if counts["FAIL"] else 0


if __name__ == "__main__":
    sys.exit(main())

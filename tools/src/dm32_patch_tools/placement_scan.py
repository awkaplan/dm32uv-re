"""Statically answer "is this RAM/flash address range safe for a patch to put new data in?"

================================================================================================
A RANGE THAT READS AS ALL-ZERO IN A LIVE DUMP IS NOT EVIDENCE THAT IT IS FREE.
================================================================================================
NULL pointers, empty ready-list slots, and unused stack depth all look blank too. This project
found that out the expensive way: the Snake example patch's first attempt at a scratch-state
address landed its state block directly on top of the uC/OS-III scheduler's own live variables
at 0x42cb4, because that address was zero in every dump taken while the firmware sat idle at the
menu - "zero right now" and "nobody's using this" are different claims, and only the second one
matters for a patch.

The only RAM region that has passed ALL THREE tests this script runs (no literal reference into
it from flash OR IRAM, nearest referenced base farther than the margin, and zero throughout a
live dump) is SRAM 0x18004c00-0x18008000, where the highest SRAM literal found is 0x18004bfc.
This project's own patches keep their scratch there: Snake's game state at 0x18007000, the
overlay GUARD word at 0x18007FE0, and the RAMDUMP cursor at 0x18007FF0. Treat a "clear" verdict
from this script on a NEW range with the same skepticism that address earned before being
trusted - it is the best static evidence available, not a proof.

WHAT THIS SCRIPT DOES: scans both the flash image and the IRAM image (optionally also an
SRAM dump) for every 32-bit little-endian value, at every 2-byte alignment, that falls inside
[--lo, --hi). Each hit means some code, somewhere, holds that address as data - almost always
because it's an array/struct base a loop indexes from, which is exactly how a zero-looking-but-
live region gets touched without ever having its own address appear inside the loop body. It
also reports the nearest referenced address below --lo and above --hi (within --margin, default
0x400) for the same reason: an array is referenced once, by its base, not once per element.
`meta/functions.json` is used to name the function containing any flash literal hit, when the
hit falls inside a known function's address range.

Verdict: `clear` if no literal falls inside the range, the nearest base below --lo is farther
than --margin bytes away, and the range is all-zero throughout whatever dump(s) cover it;
otherwise `suspect`, with every reason listed.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
DEFAULT_FLASH = REPO_ROOT / "data" / "firmware" / "patching" / "progmem_stock_DP570UV_20260926_FULL.bin"
DEFAULT_IRAM = REPO_ROOT / "data" / "firmware" / "IRAM_dm32.00.01.048.bin"
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
ALLOCATIONS_JSON = REPO_ROOT / "data" / "allocations.json"

FLASH_BASE = 0x03000000
IRAM_BASE = 0x00010000
SRAM_BASE = 0x18000000

DEFAULT_MARGIN = 0x400

# The default IRAM image is derived from flash (derive_iram.py): it holds the load image up to
# IRAM_RUNTIME_START and zeros above it. That upper region is bss, stacks and heap - used at runtime
# but zero in the image - so "zero in the image" there says nothing about whether it is free.
IRAM_RUNTIME_START = 0x0002f098
IRAM_END = 0x00058000


def load_functions() -> list[dict]:
    if not FUNCTIONS_JSON.exists():
        return []
    data = json.loads(FUNCTIONS_JSON.read_text())
    out = []
    for fn in data.get("functions", []):
        addr = fn["addr"]
        addr_int = int(addr, 16) if isinstance(addr, str) else addr
        out.append({"addr": addr_int, "size": fn.get("size", 0), "name": fn.get("name", "?")})
    return out


def containing_function(functions: list[dict], addr: int) -> str | None:
    for fn in functions:
        if fn["addr"] <= addr < fn["addr"] + max(fn["size"], 1):
            return fn["name"]
    return None


def scan_literals(data: bytes, base: int, lo: int, hi: int) -> list[tuple[int, int]]:
    """Every 2-byte-aligned 32-bit LE value in `data` (mapped at `base`) that falls in [lo, hi).
    Returns (address_of_the_literal, value) pairs."""
    hits = []
    for off in range(0, len(data) - 3, 2):
        val = int.from_bytes(data[off:off + 4], "little")
        if lo <= val < hi:
            hits.append((base + off, val))
    return hits


def nearest_reference(data: bytes, base: int, lo: int, hi: int, margin: int) -> tuple[int | None, int | None]:
    """Nearest literal value below lo (within margin) and above hi (within margin), scanning
    the same image. Returns (nearest_below_or_None, nearest_above_or_None)."""
    below_lo, below_hi = max(lo - margin, base), lo
    above_lo, above_hi = hi, min(hi + margin, base + len(data))

    best_below = None
    best_above = None
    for off in range(0, len(data) - 3, 2):
        val = int.from_bytes(data[off:off + 4], "little")
        if below_lo <= val < below_hi:
            if best_below is None or val > best_below:
                best_below = val
        elif above_lo <= val < above_hi:
            if best_above is None or val < best_above:
                best_above = val
    return best_below, best_above


def claimed_regions(extra_files=()) -> list[dict]:
    """Flash/RAM regions this repo has already claimed, from data/allocations.json.

    A static claim - another patch's .bss, a guard word, a reserved flash sector - is invisible
    to every other check here: nothing in the stock firmware points at it, and RAM reads blank in
    any dump taken before that patch runs. The only record is the declaration. Without this, the
    scanner called the Snake example's own state range "clear" (found by a blind rebuild,
    2026-10-12).

    This is the same file gen_link_artifacts.py turns into tools/link/dm32_patch_memory.ld, so a
    region reported here is also one a patch would fail to LINK against. `forbidden` entries
    (the per-unit sector, the emulator-only bypass sector) are reported too: they are never
    patch space.
    """
    paths = ([ALLOCATIONS_JSON] if ALLOCATIONS_JSON.exists() else []) + list(extra_files)
    out = []
    for path in paths:
        data = json.loads(pathlib.Path(path).read_text())
        for key, kind in (("allocations", "claimed"), ("forbidden", "forbidden")):
            for a in data.get(key, []):
                try:
                    out.append({"name": a["name"], "kind": kind, "start": int(a["start"], 16),
                                "end": int(a["end_exclusive"], 16), "source": a.get("source", "")})
                except (KeyError, ValueError):
                    continue
    return out


def occupied_fraction(data: bytes, base: int, lo: int, hi: int, blank: int) -> tuple[int, int]:
    """(occupied_byte_count, total_byte_count) of [lo, hi) intersected with this image's range.

    `blank` is the byte value that means "unused" for THIS kind of image, and the two kinds
    disagree: erased NOR flash reads 0xFF, while an unused RAM/SRAM dump reads 0x00. Testing
    flash for zero (as this did until 2026-10-12) calls every genuinely erased region "suspect"
    - a blind rebuild of this repo hit exactly that on 0x030e2000, which docs/rtos-and-memory.md
    correctly documents as free and which really is all-0xFF in the shipped image.
    """
    start = max(lo, base) - base
    end = min(hi, base + len(data)) - base
    if end <= start:
        return 0, 0
    region = data[start:end]
    return sum(1 for b in region if b != blank), len(region)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--extra-allocations", type=pathlib.Path, action="append", default=[],
                    metavar="FILE", help="additional allocation file(s), same schema as "
                    "data/allocations.json (e.g. an out-of-tree patches repo's claims); repeatable")
    ap.add_argument("--lo", required=True, help="range start address, e.g. 0x18004c00")
    ap.add_argument("--hi", required=True, help="range end address (exclusive), e.g. 0x18008000")
    ap.add_argument("--flash", type=pathlib.Path, default=DEFAULT_FLASH,
                     help=f"flash image (default: {DEFAULT_FLASH.relative_to(REPO_ROOT)})")
    ap.add_argument("--iram", type=pathlib.Path, default=DEFAULT_IRAM,
                     help=f"IRAM image, mapped at {IRAM_BASE:#x} (default: the flash-derived "
                          f"{DEFAULT_IRAM.relative_to(REPO_ROOT)}; pass a live capture together "
                          f"with --iram-is-live to test runtime use, see docs/live-ram-capture.md)")
    ap.add_argument("--iram-is-live", action="store_true",
                     help="the --iram file is a live capture, so its contents above "
                          f"{IRAM_RUNTIME_START:#x} reflect real runtime use")
    ap.add_argument("--sram", type=pathlib.Path, default=None,
                     help=f"optional SRAM dump, mapped at {SRAM_BASE:#x}")
    ap.add_argument("--margin", default=hex(DEFAULT_MARGIN),
                     help=f"how far below/above the range to look for the nearest reference "
                          f"(default {DEFAULT_MARGIN:#x})")
    args = ap.parse_args()

    lo = int(args.lo, 0)
    hi = int(args.hi, 0)
    margin = int(args.margin, 0)
    if hi <= lo:
        print("FAIL: --hi must be > --lo", file=sys.stderr)
        sys.exit(2)

    images: list[tuple[str, bytes, int]] = []
    if args.flash.exists():
        images.append(("flash", args.flash.read_bytes(), FLASH_BASE))
    else:
        print(f"warning: flash image {args.flash} not found, skipping", file=sys.stderr)
    if args.iram.exists():
        images.append(("iram", args.iram.read_bytes(), IRAM_BASE))
    else:
        print(f"warning: IRAM dump {args.iram} not found, skipping", file=sys.stderr)
    if args.sram is not None:
        if args.sram.exists():
            images.append(("sram", args.sram.read_bytes(), SRAM_BASE))
        else:
            print(f"warning: SRAM dump {args.sram} not found, skipping", file=sys.stderr)

    functions = load_functions()
    reasons: list[str] = []
    any_literal = False

    for label, data, base in images:
        hits = scan_literals(data, base, lo, hi)
        for addr, val in hits:
            any_literal = True
            fn_name = containing_function(functions, addr) if label == "flash" else None
            where = f" in {fn_name}" if fn_name else ""
            print(f"{label} literal @{addr:#010x}{where} -> {val:#010x}")

        below, above = nearest_reference(data, base, lo, hi, margin)
        if below is not None:
            print(f"{label}: nearest referenced base BELOW --lo (within {margin:#x}): {below:#010x} "
                  f"(distance {lo - below:#x})")
        if above is not None:
            print(f"{label}: nearest referenced base ABOVE --hi (within {margin:#x}): {above:#010x} "
                  f"(distance {above - hi:#x})")

        if below is not None and (lo - below) <= margin:
            reasons.append(f"{label} has a referenced base at {below:#x}, only {lo-below:#x} "
                            f"bytes below --lo (margin {margin:#x})")

        # Erased NOR flash reads 0xFF; an unused RAM/SRAM dump reads 0x00.
        blank = 0xFF if label == "flash" else 0x00
        blank_word = "erased (0xFF)" if blank == 0xFF else "zero"
        used, total = occupied_fraction(data, base, lo, hi, blank)
        if total > 0:
            print(f"{label}: {used}/{total} bytes of the range are NOT {blank_word} in this dump")
            if used > 0:
                reasons.append(f"{label} has {used}/{total} bytes that are not {blank_word} "
                                f"in [{lo:#x},{hi:#x})")

    # Already-claimed patch RAM: declared, because nothing else here can see it.
    for alloc in claimed_regions(args.extra_allocations):
        if lo < alloc["end"] and hi > alloc["start"]:
            where = f" ({alloc['source']})" if alloc["source"] else ""
            print(f"{alloc['kind']}: {alloc['start']:#010x}-{alloc['end']:#010x} "
                  f"{alloc['name']}{where}")
            reasons.append(f"overlaps {alloc['kind']} region {alloc['name']} at "
                            f"{alloc['start']:#x}-{alloc['end']:#x} "
                            f"(declared in data/allocations.json)")

    if any_literal:
        reasons.insert(0, "one or more literal 32-bit references point inside the range")

    if not args.iram_is_live and lo < IRAM_END and hi > IRAM_RUNTIME_START:
        reasons.append(f"range overlaps IRAM {IRAM_RUNTIME_START:#x}-{IRAM_END - 1:#x} (bss, stacks, "
                       "heap): the flash-derived IRAM image is zero there whether or not it is used "
                       "at runtime. Re-run with a live capture and --iram-is-live")

    if reasons:
        print("\nverdict: suspect")
        for r in reasons:
            print(f"  - {r}")
    else:
        print("\nverdict: clear (no literal inside, nearest base below farther than "
              f"{margin:#x} bytes, range blank in every dump scanned - erased 0xFF in flash, "
              "zero in RAM)")


if __name__ == "__main__":
    main()

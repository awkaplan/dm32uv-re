# /// script
# requires-python = ">=3.9"
# dependencies = []
# ///
"""
Scan the firmware image for GB2312/ASCII-mixed string literals, using the exact byte-classification
rules the firmware's own confirmed string renderer (display_draw_string_gb2312, flash 0x03018998 -
see tools/include/dm32_ui.h) uses:

  - byte < 0x81            -> single-byte ASCII character (renderer's own boundary check)
  - byte >= 0x81 AND next byte >= 0x81 -> GB2312 double-byte character pair
  - 0x00                   -> string terminator (NUL, per the renderer's `while (*p != 0)` loop)
  - 0xff                   -> the renderer's own "line break" marker (not decoded as a character)

WHY THIS EXISTS: mapping a numeric menu-item/dialog-reason code to its real on-screen meaning
needs the label text, which isn't visible from disassembly alone - this is how docs/menu-system.md's
per-category string tables were originally found (a `--near` search around a known dispatcher
address, then cross-referencing the addresses found against a raw-pointer sweep of the image).
This scans the flash image directly for exactly the byte patterns the confirmed renderer consumes,
decodes them via Python's built-in gb2312 codec, and reports each string's flash address so it can
be cross-referenced against nearby code (e.g. "what's the closest string literal to this dispatch
site").

Usage:
    python3 extract_gb2312_strings.py ../../../data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin > strings.json
    python3 extract_gb2312_strings.py ../../../data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin --near 0x030b7db8
"""

import argparse
import json
import sys
from pathlib import Path

LOAD_BASE = 0x03000000  # header region; app code region is LOAD_BASE + 0x1000, see decompiled/README.md


def classify_run(data, start):
    """
    Try to read one NUL-terminated mixed ASCII/GB2312 string starting at `start`.
    Returns (raw_bytes, decoded_str, end_offset) or None if this isn't a plausible string start.
    """
    i = start
    n = len(data)
    raw = bytearray()
    ascii_count = 0
    gb_count = 0
    while i < n:
        b = data[i]
        if b == 0x00:
            break
        if b == 0xFF:
            # line-break marker per the renderer - treat as a space and continue
            raw.append(0x20)
            i += 1
            continue
        if b < 0x81:
            if b < 0x20 or b > 0x7E:
                return None  # not a printable ASCII byte - not a real string
            raw.append(b)
            ascii_count += 1
            i += 1
        else:
            if i + 1 >= n:
                return None
            b2 = data[i + 1]
            if b2 < 0x81:
                return None  # renderer would treat this as malformed - bail
            raw.extend((b, b2))
            gb_count += 1
            i += 2
        if len(raw) > 200:  # sanity cap - real menu/UI strings are short
            return None
    if i == start:
        return None  # empty string
    try:
        decoded = raw.decode("gb2312", errors="strict") if gb_count else raw.decode("ascii")
    except UnicodeDecodeError:
        return None
    return bytes(raw), decoded, i, ascii_count, gb_count


def is_high_confidence(decoded, ascii_only, gb_count, min_ascii_len, min_gb_count):
    """
    GB2312's valid byte ranges overlap heavily with arbitrary binary data, and short/repeated-
    character runs are common false positives (confirmed empirically at two successive filter
    thresholds - see this script's own git history / firmware/DM32.00.01.048/live-memory-poke/
    gb2312-string-extraction.md for the tuning process). Three checks, tuned empirically against
    this specific binary:
      1. ASCII runs need to be reasonably long (default 8) - shorter ones are overwhelmingly
         coincidental byte patterns inside CK803S instruction encodings, not real text.
      2. GB2312 runs need several consecutive double-byte pairs (default 3).
      3. Reject a decoded string that's just ONE character repeated many times (e.g. "驶驶驶驶")
         - real UI text doesn't look like this; it's a strong signal of a coincidental match
         against a repeating byte pattern (e.g. inside a bitmap/font table, not a string table).
    This is an explicit precision-over-recall tradeoff - some genuinely short real strings (e.g.
    2-character UI labels) are missed, in exchange for a list a human can actually read through.
    """
    if len(set(decoded)) == 1 and len(decoded) > 2:
        return False
    if ascii_only:
        return len(decoded) >= min_ascii_len
    return gb_count >= min_gb_count


def scan(data, min_ascii_len, min_gb_count):
    results = []
    i = 0
    n = len(data)
    while i < n:
        b = data[i]
        # Only attempt a decode at plausible string-start bytes: printable ASCII or a GB2312 lead byte.
        if (0x20 <= b <= 0x7E) or (0x81 <= b <= 0xFE and i + 1 < n and 0x81 <= data[i + 1] <= 0xFE):
            res = classify_run(data, i)
            if res is not None:
                raw, decoded, end, ascii_count, gb_count = res
                ascii_only = gb_count == 0
                if is_high_confidence(decoded, ascii_only, gb_count, min_ascii_len, min_gb_count):
                    results.append(
                        {
                            "file_offset": i,
                            "addr": LOAD_BASE + i,
                            "len": len(decoded),
                            "text": decoded,
                            "kind": "ascii" if ascii_only else "gb2312",
                        }
                    )
                i = end + 1
                continue
        i += 1
    return results


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("bin_path")
    parser.add_argument("--min-ascii-len", type=int, default=8, help="minimum length for a pure-ASCII run to be kept (default 8 - tuned empirically, see the module docstring)")
    parser.add_argument("--min-gb-count", type=int, default=3, help="minimum number of GB2312 double-byte pairs for a run containing any to be kept (default 3 - i.e. at least 3 Chinese/GB characters)")
    parser.add_argument("--near", help="hex address - only print strings within --window bytes of this address")
    parser.add_argument("--window", type=lambda x: int(x, 0), default=0x2000)
    args = parser.parse_args()

    data = Path(args.bin_path).read_bytes()
    results = scan(data, args.min_ascii_len, args.min_gb_count)

    if args.near:
        target = int(args.near, 16)
        results = [r for r in results if abs(r["addr"] - target) <= args.window]
        results.sort(key=lambda r: abs(r["addr"] - target))

    json.dump(results, sys.stdout, ensure_ascii=False, indent=2)
    print()
    print(f"# {len(results)} strings found", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())

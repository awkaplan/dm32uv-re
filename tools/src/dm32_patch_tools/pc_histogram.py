"""Turn a QEMU exec trace into windowed PC histograms, then map a histogram onto named
functions from meta/functions.json.

WHY THIS EXISTS: `qemu-system-cskyv2 -d exec,nochain -D FILE` (or a FIFO fed the same way) is
the standard way to see exactly what's executing, but the raw trace is enormous and line-by-line
reading it is not how anyone actually wants to answer "what was this boot/navigation run
actually spending its time in." This script turns the trace into small `pcw_NN.txt` snapshots
(one per `--window` seconds) a human or another script can diff or skim, and its `--map` mode
turns one of those snapshots into a function-level profile using the same address ranges
`meta/functions.json` already carries - cheap, since a '-d exec' trace already has every PC a
sampling profiler would have to intercept execution to approximate.

Line matching is deliberately permissive: `/([0-9a-f]{8})/` against whatever is in each line,
so this script works unchanged whether the trace is a real file or is being read live out of a
FIFO (`-D /path/to/fifo`), and whether the surrounding log format is QEMU's own `-d exec`
("IN: ...\\n0x0300c004: ...") or something else that merely contains 8-hex-digit addresses.

TWO MODES:
    pc_histogram.py --trace FILE_OR_FIFO --out DIR [--window SECONDS]
        Reads the trace line by line (blocks on a FIFO exactly like `tail -f` would), and every
        --window seconds (default 10) writes "pcw_NN.txt" into --out: sorted "pc count" lines,
        most-executed first, with a one-line header giving the sample/distinct-pc counts.

    pc_histogram.py --map PCW_FILE [--top N]
        Reads one pcw_NN.txt file back and aggregates its per-pc counts into per-function
        totals by containment in meta/functions.json's [addr, addr+size) ranges, then prints
        the top --top (default 40) functions with counts and percentages of the window total.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys
import time

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"

PC_RE = re.compile(r"([0-9a-f]{8})")


def load_functions() -> list[dict]:
    if not FUNCTIONS_JSON.exists():
        return []
    data = json.loads(FUNCTIONS_JSON.read_text())
    out = []
    for fn in data.get("functions", []):
        addr = fn["addr"]
        addr_int = int(addr, 16) if isinstance(addr, str) else addr
        out.append({"addr": addr_int, "size": fn.get("size", 0), "name": fn.get("name", "?")})
    out.sort(key=lambda f: f["addr"])
    return out


def containing_function(sorted_functions: list[dict], pc: int) -> str | None:
    """Binary search by start address, then confirm pc actually falls inside [addr, addr+size)."""
    lo, hi = 0, len(sorted_functions) - 1
    best = None
    while lo <= hi:
        mid = (lo + hi) // 2
        fn = sorted_functions[mid]
        if fn["addr"] <= pc:
            best = fn
            lo = mid + 1
        else:
            hi = mid - 1
    if best is not None and best["addr"] <= pc < best["addr"] + max(best["size"], 1):
        return best["name"]
    return None


def write_window(out_dir: pathlib.Path, window_index: int, counts: dict[int, int]) -> pathlib.Path:
    path = out_dir / f"pcw_{window_index:02d}.txt"
    total = sum(counts.values())
    lines = [f"# window {window_index}, {total} samples, {len(counts)} distinct pc"]
    for pc, count in sorted(counts.items(), key=lambda kv: (-kv[1], kv[0])):
        lines.append(f"{pc:08x} {count}")
    path.write_text("\n".join(lines) + "\n")
    return path


def collect(trace_path: pathlib.Path, out_dir: pathlib.Path, window_seconds: float) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)

    window_index = 0
    counts: dict[int, int] = {}
    window_start = time.monotonic()

    def flush():
        nonlocal counts, window_index, window_start
        if counts:
            path = write_window(out_dir, window_index, counts)
            print(f"wrote {path} ({sum(counts.values())} samples)")
        window_index += 1
        counts = {}
        window_start = time.monotonic()

    with open(trace_path, errors="replace") as f:
        for line in f:
            if time.monotonic() - window_start >= window_seconds:
                flush()
            m = PC_RE.search(line)
            if m:
                pc = int(m.group(1), 16)
                counts[pc] = counts.get(pc, 0) + 1

    flush()


def do_map(pcw_path: pathlib.Path, top: int) -> None:
    functions = load_functions()
    if not functions:
        print(f"warning: {FUNCTIONS_JSON} not found or empty - all PCs will be unmapped", file=sys.stderr)

    totals: dict[str, int] = {}
    unmapped = 0
    grand_total = 0

    with open(pcw_path) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split()
            if len(parts) != 2:
                continue
            pc = int(parts[0], 16)
            count = int(parts[1])
            grand_total += count
            name = containing_function(functions, pc)
            if name is None:
                unmapped += count
            else:
                totals[name] = totals.get(name, 0) + count

    if grand_total == 0:
        print("no samples found in pcw file")
        return

    ranked = sorted(totals.items(), key=lambda kv: -kv[1])[:top]
    print(f"{grand_total} total samples, {len(totals)} distinct functions, "
          f"{unmapped} unmapped ({100*unmapped/grand_total:.1f}%)\n")
    for name, count in ranked:
        pct = 100 * count / grand_total
        print(f"{count:8d}  {pct:6.2f}%  {name}")


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--trace", type=pathlib.Path, default=None,
                     help="exec trace file or FIFO to read (collect mode)")
    ap.add_argument("--window", type=float, default=10, help="window length in seconds (default 10)")
    ap.add_argument("--out", type=pathlib.Path, default=None, help="output directory (collect mode)")
    ap.add_argument("--map", type=pathlib.Path, default=None, metavar="PCW_FILE",
                     help="aggregate this pcw_NN.txt file into per-function counts (map mode)")
    ap.add_argument("--top", type=int, default=40, help="map mode: show the top N functions (default 40)")
    args = ap.parse_args()

    if args.map is not None:
        do_map(args.map, args.top)
        return

    if args.trace is None or args.out is None:
        print("FAIL: collect mode needs --trace and --out (or use --map PCW_FILE)", file=sys.stderr)
        sys.exit(2)

    collect(args.trace, args.out, args.window)


if __name__ == "__main__":
    main()

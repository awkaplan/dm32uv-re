"""Fingerprint matching for settled-screen "non-black pixel" counts.

WHY THIS EXISTS: qemu_run.py and the docs print token lines of settled-frame pixel counts
(F<i>:<nonblack>), and the prose records what count means which screen. This module is the
machine side of that: data/screen_fingerprints.json (hand-maintained, kept in sync with
docs/qemu-workflow.md) maps a count to the named screens it could be, so an agent tailing a run
can resolve "9472" to "snake-category-sublist" without reading prose. qemu_run.py --json uses
describe() to attach those names to each frame.

DESIGN: the library raises on a missing/corrupt JSON (a data file problem should be loud).
qemu_run.py wraps the call in try/except and degrades to "no matches" rather than failing the
whole run when the file is unavailable.

PUBLIC API:
    load_fingerprints(path=None) -> dict   the "fingerprints" dict of the JSON
    matches(nonblack, path=None) -> list   names whose point equals it or whose range contains it
    describe(frames, path=None) -> list    enrich [{"idx","step","nonblack"}] with "matches"
"""
from __future__ import annotations

import argparse
import json
import pathlib

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FINGERPRINTS_JSON = REPO_ROOT / "data" / "screen_fingerprints.json"


def load_fingerprints(path=None) -> dict:
    """Return the "fingerprints" dict of data/screen_fingerprints.json (or the file at `path`)."""
    p = pathlib.Path(path) if path is not None else FINGERPRINTS_JSON
    return json.loads(p.read_text())["fingerprints"]


def matches(nonblack: int, path=None) -> list[str]:
    """Names whose fingerprint matches `nonblack`: a point equal to it, or min <= n <= max."""
    out = []
    for name, spec in load_fingerprints(path).items():
        v = spec["nonblack"]
        if isinstance(v, dict):
            if v["min"] <= nonblack <= v["max"]:
                out.append(name)
        elif v == nonblack:
            out.append(name)
    return out


def describe(frames: list[dict], path=None) -> list[dict]:
    """Enrich [{"idx","step","nonblack"}]-shaped frames with a "matches" list of names."""
    out = []
    for fr in frames:
        out.append({**fr, "matches": matches(fr["nonblack"], path)})
    return out


def main() -> None:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p_match = sub.add_parser("match", help="list fingerprints matching a non-black pixel count")
    p_match.add_argument("nonblack", type=int)
    sub.add_parser("list", help="list every fingerprint name, count and context")
    args = ap.parse_args()

    if args.cmd == "list":
        for name, spec in sorted(load_fingerprints().items()):
            v = spec["nonblack"]
            shown = f"{v['min']}..{v['max']}" if isinstance(v, dict) else str(v)
            print(f"{name}: {shown} [{spec['context']}]")
    else:
        hits = matches(args.nonblack)
        print(" ".join(hits) if hits else "(no match)")


if __name__ == "__main__":
    main()

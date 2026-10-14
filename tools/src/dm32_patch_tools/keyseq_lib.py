"""Load, validate and resolve named DM32_KEYSEQ scripts, and build raw keyseq strings.

WHY THIS EXISTS: qemu_run.py takes a raw DM32_KEYSEQ string and every example in the docs
hand-rolls one. Named scenarios (data/keyseq_scenarios.json) make a UI-navigation script a
one-word argument (`--keyseq-name snake-walkthrough` instead of an 11-step incantation), and
the press()/wait()/build() helpers stop everyone from re-typing the cb:cbit:rb:rbit numbers
again (they live in qemu_run.KEYS, derived once and shared). The raw grammar those strings
follow is documented in qemu_run.py's module docstring ("KEYSEQ GRAMMAR").

The data is hand-maintained in data/ (same rule as every other data/ file); this module only
loads it and turns a query into a string. `tools/dm32 keyseq` wraps this module's CLI.

PUBLIC API:
    load_scenarios(path=None) -> dict      the "scenarios" dict of the JSON
    press(key, hold, gap) -> str           one KEYSEQ step from a key name in qemu_run.KEYS
    wait(reads) -> str                     a "-1:0:1:31:0:<reads>" wait step
    build(*steps) -> str                   join steps with ";"
    resolve_keyseq(query, path=None)       raw keyseq passthrough, or scenario name -> keyseq
        -> tuple[str, dict | None]         (keyseq, scenario) ; scenario is None for raw input.
        Raises ValueError (naming the available scenarios) for anything else; callers decide
        how that becomes an exit status - the CLI exits 2.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
SCENARIOS_JSON = REPO_ROOT / "data" / "keyseq_scenarios.json"

# qemu_run.py is a sibling module imported by bare name (the same sys.path pattern
# verify_patch.py uses for qemu_boot_diff). A plain import is safe here: qemu_run only runs
# its main() under __main__, so importing it for KEYS never executes a second babysit loop.
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import qemu_run  # noqa: E402

# One KEYSEQ step is six colon-separated fields "cb:cbit:rb:rbit:hold:gap"; the first field may
# be -1 for the dedicated-input-pin steps (Menu, and the "-1:0:1:31:0:<reads>" wait lead-in).
RAW_KEYSEQ_RE = re.compile(r"^-?\d+:\d+:\d+:\d+:\d+:\d+(;-?\d+:\d+:\d+:\d+:\d+:\d+)*$")


def load_scenarios(path=None) -> dict:
    """Load data/keyseq_scenarios.json (or the file at `path`) and return its "scenarios" dict."""
    p = pathlib.Path(path) if path is not None else SCENARIOS_JSON
    return json.loads(p.read_text())["scenarios"]


def press(key: str, hold: int, gap: int) -> str:
    """Build one KEYSEQ step from a key name in qemu_run.KEYS plus hold/gap read counts."""
    if key not in qemu_run.KEYS:
        raise ValueError(
            f"unknown key {key!r}; available: {', '.join(sorted(qemu_run.KEYS))}")
    return f"{qemu_run.KEYS[key]}:{hold}:{gap}"


def wait(reads: int) -> str:
    """A "-1:0:1:31:0:<reads>" lead-in/tail step: hold=0, so it only delays `reads` row reads."""
    return f"-1:0:1:31:0:{reads}"


def build(*steps: str) -> str:
    """Join KEYSEQ step strings into one DM32_KEYSEQ value (same join as qemu_run.keyseq)."""
    return ";".join(steps)


def resolve_keyseq(query: str, path=None) -> tuple[str, dict | None]:
    """Turn a query into a DM32_KEYSEQ string.

    A raw keyseq (matches RAW_KEYSEQ_RE) is returned unchanged with scenario=None. A name in
    data/keyseq_scenarios.json returns its stored keyseq plus the whole scenario dict. Anything
    else raises ValueError naming the available scenarios - the CLI turns that into exit 2, and
    qemu_run.py does the same for a bad --keyseq-name.
    """
    if RAW_KEYSEQ_RE.match(query):
        return query, None
    scenarios = load_scenarios(path)
    if query in scenarios:
        sc = scenarios[query]
        return sc["keyseq"], sc
    names = ", ".join(sorted(scenarios))
    raise ValueError(f"unknown keyseq scenario {query!r}; available scenarios: {names}")


def main() -> None:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("list", help="list scenario names and descriptions")
    p_show = sub.add_parser("show", help="print one scenario's (or a raw keyseq's) keyseq")
    p_show.add_argument("name")
    p_resolve = sub.add_parser(
        "resolve", help="raw keyseq passthrough or scenario name -> keyseq string")
    p_resolve.add_argument("query")
    p_press = sub.add_parser("press", help="build one KEYSEQ step: press KEY HOLD GAP")
    p_press.add_argument("key")
    p_press.add_argument("hold", type=int)
    p_press.add_argument("gap", type=int)
    p_wait = sub.add_parser("wait", help="build a wait step: wait READS")
    p_wait.add_argument("reads", type=int)
    args = ap.parse_args()

    if args.cmd == "list":
        for name, sc in sorted(load_scenarios().items()):
            print(f"{name}: {sc['description']}")
        return

    try:
        if args.cmd == "show":
            print(resolve_keyseq(args.name)[0])
        elif args.cmd == "resolve":
            print(resolve_keyseq(args.query)[0])
        elif args.cmd == "press":
            print(press(args.key, args.hold, args.gap))
        elif args.cmd == "wait":
            print(wait(args.reads))
    except ValueError as e:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(2)


if __name__ == "__main__":
    main()

"""Checklist item B: real call-site/xref data (callers/callees only - see README.md for why
register-liveness per call site was explicitly dropped from this pass's scope).

Parses every bsr (direct call) and jsr (indirect, register-target call) instruction out of
meta/disasm.jsonl - already-verified real disassembly from item A - rather than asking Ghidra
for xrefs via a second analysis pass. Ghidra's ReferenceManager only has flow references for
code it has actually disassembled with xref-recording turned on, which export_disasm.py
deliberately does not do (see its own docstring on why this corpus avoids analyzeAll); the
instruction text already has everything needed; parsing it is cheaper and stays consistent
with the one disassembly dataset this tooling has already verified byte-for-byte.

A DIRECT call target is not automatically trustworthy, and this was caught empirically: this
binary contains inline data words (literal pools / jump tables that the corpus's own
decompiler did not recognize as such, e.g. channel_scan_step_and_lock @0x03065e3c) whose raw
bytes can coincidentally decode as a syntactically VALID bsr/jsr instruction pointing at
nonsense (observed target 0x06be6002, far outside either flash or IRAM's address space - not
a typo, a genuinely garbage decode of a data word). Every target is therefore classified, not
just accepted:

  - "resolved"   - lands exactly on a known function's entry address (meta/functions.json).
                   The strong case: a real, named call edge.
  - "iram"       - lands inside IRAM's address range (0x00010000-0x00057FFF) but not on one
                   of the corpus's 61 catalogued IRAM function entries. Real signal, not
                   noise: this project's own history (iram-decompile-unlocks-flash-readability
                   in project memory) found hundreds of flash->IRAM calls still uncatalogued -
                   this is exactly where a future IRAM-decompile pass should look first.
  - "flash_unresolved" - lands inside the flash app's address range but not on a known
                   function entry (could be a thunk, a mid-function target, or a corpus gap).
                   Lower confidence than "resolved"; worth a human look, not proven garbage.
  - "garbage"    - lands outside EVERY valid address range for this hardware. Treated as a
                   misdecoded data word, not a call, and excluded from the callers/callees
                   graph entirely (counted separately so the exclusion is visible, not silent).

jsr (indirect call via register) targets are never resolvable from static text alone - no
operand gives an address. These are recorded as "indirect calls out" per function (a count,
not a target), which still matters to a patch author: a function with indirect calls has
call edges this whole script - and the corpus's own decompiler - cannot enumerate.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
DISASM_JSONL = REPO_ROOT / "meta" / "disasm.jsonl"
OUT_JSON = REPO_ROOT / "meta" / "xrefs.json"

IRAM_START, IRAM_END = 0x00010000, 0x00058000  # end exclusive; 288KB per the main repo's docs
FLASH_START, FLASH_END = 0x03000000, 0x030D3000  # end exclusive; this image's own extent

DEFAULT_CALLING_CONVENTION = "csky-abiv2"

# Refuse to run (without --allow-partial) when meta/disasm.jsonl covers less than this fraction
# of meta/functions.json's flash-range functions - see the guard in main().
MIN_DISASM_COVERAGE = 0.90

# Per-function overrides, keyed by entry address (hex string, as in meta/functions.json).
# Intentionally EMPTY right now: the one known non-ABI convention in this project's history
# ("vframe-r8-length" - a handler returns its result length in r8 instead of r0, used by
# hand-written patch hooks like megaprobe_handler.S) belongs to PROJECT-AUTHORED patch code
# at flash 0x030E1000, which is not part of this stock-firmware corpus at all (verified: no
# meta/functions.json entry exists at that address - it occupies flash the stock image never
# used). Add a real override here only once a STOCK corpus function is found that needs one;
# forcing this one in would annotate a function that doesn't exist.
CALLING_CONVENTION_OVERRIDES: dict[str, str] = {}


def classify_target(target: int, known_addrs: set[int]) -> str:
    if target in known_addrs:
        return "resolved"
    if IRAM_START <= target < IRAM_END:
        return "iram"
    if FLASH_START <= target < FLASH_END:
        return "flash_unresolved"
    return "garbage"


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", type=pathlib.Path, default=OUT_JSON)
    ap.add_argument("--allow-partial", action="store_true",
                    help="Proceed even when meta/disasm.jsonl covers fewer than "
                         f"{MIN_DISASM_COVERAGE * 100:.0f}%% of the flash functions in "
                         "meta/functions.json (e.g. after a LIMIT=N smoke run). The output "
                         "is then marked partial and export_patch_risk.py will refuse it "
                         "unless also given --allow-partial.")
    args = ap.parse_args()

    functions = json.loads(FUNCTIONS_JSON.read_text())["functions"]
    known_addrs = {int(f["addr"], 16) for f in functions}
    addr_to_name = {int(f["addr"], 16): f["name"] for f in functions}

    disasm_rows = [json.loads(l) for l in DISASM_JSONL.read_text().splitlines() if l.strip()]

    # GUARD: a LIMIT=N smoke run of export_disasm.py overwrites meta/disasm.jsonl with only N
    # rows; regenerating xrefs from that would silently shrink the whole call graph (and,
    # downstream, patch_risk.json) to N functions. Refuse unless explicitly told otherwise.
    flash_fn_addrs = {a for a in known_addrs if a >= FLASH_START}
    covered = flash_fn_addrs & {int(r["addr"], 16) for r in disasm_rows}
    coverage = len(covered) / len(flash_fn_addrs) if flash_fn_addrs else 0.0
    partial = coverage < MIN_DISASM_COVERAGE
    if partial and not args.allow_partial:
        sys.exit(
            f"ERROR: {DISASM_JSONL} covers only {len(covered)}/{len(flash_fn_addrs)} flash "
            f"functions from {FUNCTIONS_JSON} ({coverage:.1%}, threshold "
            f"{MIN_DISASM_COVERAGE:.0%}). This looks like a LIMIT=N smoke run; regenerating "
            f"xrefs from it would silently shrink {args.out}. Re-run the full export "
            f"(`make disasm` with no LIMIT), or pass --allow-partial if this is intentional."
        )
    if partial:
        print(f"WARNING: --allow-partial: disasm coverage is {coverage:.1%} "
              f"({len(covered)}/{len(flash_fn_addrs)}); output will be marked partial")

    # callers[target_addr] = [caller_addr, ...]; callees[caller_addr] = [target_addr, ...]
    callers: dict[int, list[int]] = {}
    callees: dict[int, list[int]] = {}
    indirect_call_sites: dict[int, int] = {}  # caller_addr -> count of jsr instructions
    classification_counts = {"resolved": 0, "iram": 0, "flash_unresolved": 0, "garbage": 0}

    for row in disasm_rows:
        fn_addr = int(row["addr"], 16)
        for instr in row["instructions"]:
            mnem = instr["mnemonic"]
            if mnem == "bsr":
                target = int(instr["text"].split()[1], 16)
                cls = classify_target(target, known_addrs)
                classification_counts[cls] += 1
                if cls == "garbage":
                    continue
                callees.setdefault(fn_addr, []).append(target)
                callers.setdefault(target, []).append(fn_addr)
            elif mnem == "jsr":
                indirect_call_sites[fn_addr] = indirect_call_sites.get(fn_addr, 0) + 1

    out = {
        "default_calling_convention": DEFAULT_CALLING_CONVENTION,
        "calling_convention_overrides": CALLING_CONVENTION_OVERRIDES,
        "classification_counts": classification_counts,
        # Read by export_patch_risk.py's own guard - see the coverage check in main().
        "source_disasm_coverage": {
            "flash_functions_in_functions_json": len(flash_fn_addrs),
            "flash_functions_in_disasm_jsonl": len(covered),
            "partial": partial,
        },
        "note": "callees targeting IRAM or an unresolved flash address are kept (see "
                "'iram'/'flash_unresolved' below each entry) - only 'garbage' targets "
                "(outside every valid address range, almost certainly a misdecoded inline "
                "data word) are excluded from the graph. See this script's module docstring.",
        "live_in_regs_note": "NOT computed in this pass - real register liveness needs "
                              "backward data-flow analysis per call site, deliberately out "
                              "of scope here; see tools/README.md",
        "functions": {},
    }

    all_fn_addrs = sorted(set(callers) | set(callees) | set(indirect_call_sites))
    for addr in all_fn_addrs:
        caller_list = sorted(set(callers.get(addr, [])))
        callee_list = callees.get(addr, [])
        callee_resolved = sorted({t for t in callee_list if t in known_addrs})
        callee_iram = sorted({t for t in callee_list if t not in known_addrs
                               and IRAM_START <= t < IRAM_END})
        callee_flash_unresolved = sorted({t for t in callee_list if t not in known_addrs
                                           and FLASH_START <= t < FLASH_END
                                           and not (IRAM_START <= t < IRAM_END)})

        out["functions"][hex(addr)] = {
            "name": addr_to_name.get(addr),
            "calling_convention": CALLING_CONVENTION_OVERRIDES.get(
                hex(addr), DEFAULT_CALLING_CONVENTION
            ),
            "callers": [hex(c) for c in caller_list],
            "callees_resolved": [hex(c) for c in callee_resolved],
            "callees_iram_uncatalogued": [hex(c) for c in callee_iram],
            "callees_flash_unresolved": [hex(c) for c in callee_flash_unresolved],
            "indirect_calls_out": indirect_call_sites.get(addr, 0),
        }

    args.out.write_text(json.dumps(out, indent=1))

    print(f"wrote xrefs for {len(all_fn_addrs)} functions to {args.out}")
    print(f"classification: {classification_counts}")
    print(f"{sum(indirect_call_sites.values())} indirect (jsr) call sites across "
          f"{len(indirect_call_sites)} functions - targets not resolvable from static text")


if __name__ == "__main__":
    main()

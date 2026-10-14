"""Checklist item E: a patch-risk axis, separate from naming confidence.

Adds `"patch_risk"` (low/medium/high/unknown) to every flash-resident corpus function,
answering a DIFFERENT question than CONFIRMED/STRUCTURAL/RAW does. Confidence answers "is
the name/behavior understanding right." Patch risk answers "if I change bytes near this
function, how likely am I to break something badly." A STRUCTURAL function with a merely
wrong name is low patch-risk if it's a quiet leaf; a CONFIRMED function can still be
high-risk if it's an RTOS primitive every task depends on. Never conflate the two axes in
any UI or doc - see tools/README.md.

WHAT THIS HEURISTIC ACTUALLY DETECTS, STATED PLAINLY (narrower than the checklist's original
wording, because the broader claim doesn't hold up against what's mechanically checkable):

  - "high": the function IS a catalogued patch site itself (meta/patch_sites.json), or sits
    in a sector flagged known_sensitive (meta/sectors.json), or its name matches an ISR/
    interrupt-primitive pattern (isr_*, cpu_sr_*_irq, irq_*). This last check found exactly
    7 functions - a real but narrow signal. Most actual ISR handlers in this firmware are
    reached by argument (a function pointer loaded with lrw and handed to a
    register-handler call), not a direct bsr captured in meta/xrefs.json, so a great many
    real ISRs are almost certainly NOT caught here. This heuristic does not claim otherwise.
  - "low": a leaf (no resolved/IRAM/flash_unresolved callees, no indirect calls out per
    meta/xrefs.json) that is ALSO not itself a patch site or in a sensitive sector, and has
    at least one known caller (so it's reachable, not dead/isolated code of unknown status).
  - "unknown": everything else, including every function with zero detected callers AND
    zero detected callees (328 of them) - genuinely isolated under this static analysis, not
    equivalent to "probably safe." Calling that "low" would be a worse mistake than calling
    it "unknown": isolation here just as plausibly means "reached only via an indirect call
    this analysis can't resolve" as "truly dead code."
  - "medium": has outgoing calls (not a leaf) but trips none of the "high" triggers.

The original checklist text ("calibration-bearing sector defaults to high") does not apply
to this corpus at all: per-unit calibration lives entirely on a DIFFERENT physical flash chip
than the one this corpus covers (see export_sectors.py's own module docstring and the main
repo's docs/CALIBRATION-SAFETY.md) - there is no calibration-bearing sector on this chip to
flag. Don't add one without first re-confirming which chip an address is actually on.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
XREFS_JSON = REPO_ROOT / "meta" / "xrefs.json"
SECTORS_JSON = REPO_ROOT / "meta" / "sectors.json"
PATCH_SITES_JSON = REPO_ROOT / "meta" / "patch_sites.json"
OUT_JSON = REPO_ROOT / "meta" / "patch_risk.json"

ISR_NAME_PATTERN = re.compile(r"^(isr_|cpu_sr_.*_irq|irq_)", re.IGNORECASE)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--out", type=pathlib.Path, default=OUT_JSON)
    ap.add_argument("--allow-partial", action="store_true",
                    help="Proceed even when meta/xrefs.json was built from a partial "
                         "meta/disasm.jsonl (export_xrefs.py --allow-partial), or carries no "
                         "coverage record at all.")
    args = ap.parse_args()

    functions = json.loads(FUNCTIONS_JSON.read_text())["functions"]
    flash_fns = [f for f in functions if int(f["addr"], 16) >= 0x03000000]

    xrefs_doc = json.loads(XREFS_JSON.read_text())
    # GUARD: this script never reads meta/disasm.jsonl itself, but xrefs.json is derived from
    # it - a partial disasm (LIMIT=N smoke run) would make nearly every function look
    # "isolated" here and silently degrade the whole risk map. export_xrefs.py records its
    # input coverage; refuse a partial or unrecorded one unless explicitly told otherwise.
    cov = xrefs_doc.get("source_disasm_coverage")
    if cov is None or cov.get("partial", True):
        detail = ("has no source_disasm_coverage record (built by an older export_xrefs.py?)"
                  if cov is None else
                  f"was built from a PARTIAL disasm.jsonl "
                  f"({cov.get('flash_functions_in_disasm_jsonl')}/"
                  f"{cov.get('flash_functions_in_functions_json')} flash functions)")
        if not args.allow_partial:
            sys.exit(f"ERROR: {XREFS_JSON} {detail}. Regenerate it from a full "
                     f"`make disasm` + `make xrefs`, or pass --allow-partial if intentional.")
        print(f"WARNING: --allow-partial: {XREFS_JSON} {detail}")
    xrefs = xrefs_doc["functions"]
    sectors = json.loads(SECTORS_JSON.read_text())["sectors"]
    patch_sites = json.loads(PATCH_SITES_JSON.read_text())["sites"]

    sensitive_sector_nums = {
        int(s) for s, v in sectors.items() if v.get("known_sensitive")
    }
    # Every function address that falls in a known_sensitive sector (from the sector's own
    # function list, not re-derived - avoids re-implementing export_sectors.py's sector math).
    sensitive_fn_addrs = {
        int(f["addr"], 16)
        for s, v in sectors.items()
        if int(s) in sensitive_sector_nums
        for f in v["functions"]
    }

    # Patch-site addresses that land inside a corpus function (per patch_sites.json's own
    # resolution) - that containing function is itself part of an active or historical patch.
    patch_site_fn_addrs = {
        int(site["corpus_function_addr"], 16)
        for site in patch_sites
        if site.get("corpus_function_addr")
    }

    results = {}
    counts = {"low": 0, "medium": 0, "high": 0, "unknown": 0}

    for fn in flash_fns:
        addr = int(fn["addr"], 16)
        xref_key = hex(addr)  # normalize: xrefs.json keys drop leading zeros, addr_hex doesn't
        xref = xrefs.get(xref_key)

        reasons = []
        risk = None

        if addr in patch_site_fn_addrs:
            risk = "high"
            reasons.append("contains a catalogued patch site (meta/patch_sites.json)")
        elif addr in sensitive_fn_addrs:
            risk = "high"
            reasons.append("in a sector flagged known_sensitive (meta/sectors.json)")
        elif ISR_NAME_PATTERN.match(fn["name"]):
            risk = "high"
            reasons.append("name matches an ISR/interrupt-primitive pattern")

        if risk is None:
            if xref is None:
                risk = "unknown"
                reasons.append("zero detected callers AND zero detected callees - "
                                "isolated under static analysis, not known to be dead code")
            else:
                is_leaf = (not xref["callees_resolved"]
                           and not xref["callees_iram_uncatalogued"]
                           and not xref["callees_flash_unresolved"]
                           and not xref["indirect_calls_out"])
                has_caller = bool(xref["callers"])
                if is_leaf and has_caller:
                    risk = "low"
                    reasons.append("leaf function (no outgoing calls) with at least one "
                                    "known caller")
                elif is_leaf and not has_caller:
                    risk = "unknown"
                    reasons.append("leaf function but ZERO known callers either - "
                                    "reachability itself is unconfirmed")
                else:
                    risk = "medium"
                    reasons.append("has outgoing calls; trips no high-risk trigger")

        counts[risk] += 1
        results[fn["addr_hex"]] = {
            "name": fn["name"],
            "patch_risk": risk,
            "reasons": reasons,
        }

    out = {
        "note": "patch_risk is a SEPARATE axis from CONFIRMED/STRUCTURAL/RAW naming "
                "confidence - never conflate the two. See this script's module docstring "
                "for exactly what each risk level does and does not detect; in particular "
                "'high' is seeded from only 3 narrow signals (catalogued patch sites, one "
                "known-sensitive sector, and a 7-function ISR name pattern) and almost "
                "certainly under-detects real ISR/RTOS-callback functions reached only via "
                "indirect/function-pointer calls this static analysis cannot resolve.",
        "counts": counts,
        "functions": results,
    }

    args.out.write_text(json.dumps(out, indent=1))

    print(f"wrote patch_risk for {len(results)} flash functions to {args.out}")
    print(f"counts: {counts}")


if __name__ == "__main__":
    main()

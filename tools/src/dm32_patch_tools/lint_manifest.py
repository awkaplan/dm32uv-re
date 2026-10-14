#!/usr/bin/env python3
"""Static lint for DM-32UV patch manifests and ad-hoc hook sites.

Turns two documented, real patch-authoring disasters into mechanical checks, plus the
placeholder/schema/claims/symbol problems the builder already refuses - so a patch author sees
them in one pass before a build, not as a mid-build error:

  L1  hook-at-entry      a splice/branch write at a function's first instruction(s) is pattern 1's
                         failure: a `bsr` there overwrites the caller's r15 before any displaced
                         `push ... r15` can save it. ERROR when the hook addr equals a function's
                         entry or entry+2 (patch-patterns.md pattern 1).
  L2  r15-liveness       a `bsr` written over a window inside a stock function may clobber a live
                         r15. r15 is only known SAFE when the function has an earlier `push`
                         saving r15/lr, or an earlier `bsr`/`jsr` (a prior call already rewrote
                         r15). Otherwise WARNING (pattern 11, the channel_type_mode_settings_write
                         incident). Note: control flow is modeled as straight-line from the
                         function entry to the hook site - multi-path control flow is NOT modeled,
                         so a push that sits on only one path can be misread as safe (or a
                         tail-branch-only window misread as live). When the scanned span contains
                         undecoded bytes the warning is downgraded to an info note (the scan is
                         incomplete).
  L3  TODO               any "TODO" string anywhere in the manifest JSON is a deliberate
                         placeholder the builder refuses; lint catches it earlier and in one pass.
                         ERROR.
  L4  splice schema      every splice needs exactly ONE expectation key ("expect"|"expect_u32"|
                         "expect_u8"|"expect_branch") and ONE replacement key ("bytes"|"u32"|
                         "u8"|"branch"), mirroring build_manifest_patch.py's schema. ERROR
                         otherwise.
  L5  claims             every manifest "allocations" name must resolve in data/allocations.json
                         merged with any --extra-allocations files (same merge semantics as the
                         builder: a duplicate claim name is an error). ERROR on unknown names;
                         WARNING when "allocations" is empty (every build will warn that its
                         writes are unclaimed - see the builder's check_policy).
  L6  stock symbols      "branch"/"expect_branch" targets of the form "@stock:<name>" must exist
                         in tools/link/dm32_stock_symbols.ld (parsed as PROVIDE(<name> = 0x...)).
                         ERROR if absent.

Host-runnable: every piece of disassembly evidence comes from the shipped meta/disasm.jsonl +
meta/functions.json - never capstone/objdump - so this runs anywhere the repo is cloned.

USAGE
  lint_manifest.py <manifest.patch.json> [--strict] [--extra-allocations FILE]...
  lint_manifest.py --hook 0xADDR [--json [PATH]]

  --hook runs L1/L2 for one raw address against the corpus and prints the verdict - the
  one-shot "should I bsr-hook here?" question. --json [PATH] emits
  {"findings": [...], "verdict": "PASS"|"FAIL", "exit_code": N} to PATH, or as the final stdout
  line when PATH is omitted or "-".

Verdict: one line per finding (site, rule, message), then LINT PASS / LINT FAIL. Exit 0 pass,
1 fail, 2 usage. --strict promotes warnings to failures (L2, and the empty-allocations warning).
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
# Reuse the builder's allocation merge (identical duplicate/overlap semantics) and its BuildError.
from build_manifest_patch import BuildError, load_allocations  # noqa: E402

REPO_ROOT = HERE.parents[2]
DISASM_JSONL = REPO_ROOT / "meta" / "disasm.jsonl"
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
STOCK_SYMBOLS_LD = REPO_ROOT / "tools" / "link" / "dm32_stock_symbols.ld"

# The builder's PROVIDE regex (build_manifest_patch.py stock_symbols()).
PROVIDE_RE = re.compile(r"PROVIDE\((\w+)\s*=\s*(0x[0-9a-fA-F]+)\)")


def h(x: int) -> str:
    return f"{x:#010x}"


# ----------------------------------------------------------------------------------------------
# corpus (meta/disasm.jsonl + meta/functions.json)
# ----------------------------------------------------------------------------------------------

class Corpus:
    """Read-only function index built from the shipped exports. Never touches a toolchain."""

    def __init__(self, disasm_path: pathlib.Path = DISASM_JSONL,
                 functions_path: pathlib.Path = FUNCTIONS_JSON):
        self.by_entry: dict[int, dict] = {}
        self.confidence: dict[int, str] = {}
        if disasm_path.exists():
            for line in disasm_path.read_text().splitlines():
                line = line.strip()
                if not line:
                    continue
                rec = json.loads(line)
                try:
                    self.by_entry[int(rec["addr"], 16)] = rec
                except (KeyError, ValueError):
                    continue
        if functions_path.exists():
            try:
                funcs = json.loads(functions_path.read_text()).get("functions", [])
            except (OSError, ValueError):
                funcs = []
            for f in funcs:
                try:
                    self.confidence[int(f["addr"], 16)] = f.get("confidence", "")
                except (KeyError, ValueError):
                    continue
        self._sorted = sorted((e, r.get("size", 0)) for e, r in self.by_entry.items())

    def containing(self, addr: int) -> tuple[int, dict] | None:
        """The function record whose [entry, entry+size) contains addr, or None."""
        best = None
        for entry, size in self._sorted:
            if entry > addr:
                break
            if addr < entry + size:
                best = (entry, self.by_entry[entry])
        return best

    def describe(self, entry: int, rec: dict) -> str:
        conf = self.confidence.get(entry)
        tail = f" confidence={conf}" if conf else ""
        return f"{rec.get('name', '?')} {h(entry)}..{h(entry + rec.get('size', 0))}{tail}"


# ----------------------------------------------------------------------------------------------
# L1 / L2 - hook-position and r15-liveness for a single hook site
# ----------------------------------------------------------------------------------------------

def lint_hook_site(addr: int, corpus: Corpus, *, check_l2: bool = True) -> list[dict]:
    """L1 (hook-at-entry) + L2 (r15-liveness) for one hook address. check_l2=False skips the r15
    scan (used for non-bsr splices, which never clobber r15)."""
    findings: list[dict] = []
    fn = corpus.containing(addr)
    if fn is None:
        if not check_l2:
            return findings
        findings.append({
            "rule": "L2-r15-liveness", "severity": "info", "site": h(addr),
            "message": f"{h(addr)} is not inside any catalogued function; r15 liveness cannot be "
                       f"assessed (no disasm.jsonl function covers it)",
            "evidence": "no meta/disasm.jsonl function range contains this address"})
        return findings

    entry, rec = fn
    if addr == entry or addr == entry + 2:
        findings.append({
            "rule": "L1-hook-at-entry", "severity": "error", "site": h(addr),
            "message": "hook after the prologue, never at the first instruction "
                       "(patch-patterns.md pattern 1)",
            "evidence": f"{corpus.describe(entry, rec)}; {h(addr)} is the function entry"
                        f"{' (entry+2)' if addr != entry else ''}, so a bsr here overwrites the "
                        f"caller's r15 before the displaced prologue can save it"})

    if not check_l2:
        return findings

    # Straight-line scan from the function entry up to (not including) the hook site.
    scan = [i for i in rec.get("instructions", [])
            if entry <= int(i["addr"], 16) < addr]
    push_saves = any(i["mnemonic"] == "push"
                     and ("r15" in i["text"] or re.search(r"\blr\b", i["text"]))
                     for i in scan)
    prior_call = any(i["mnemonic"] in ("bsr", "jsr") for i in scan)
    if push_saves or prior_call:
        return findings

    # has_undecoded_bytes in the scanned span downgrades the warning to an info note.
    span_undec = any(int(lo, 16) < addr and int(hi, 16) > entry
                     for lo, hi in rec.get("undecoded_ranges", []))
    msg = (f"r15 may be live at the hook site: this function has no prologue push and no earlier "
           f"call before {h(addr)} - a bsr here can lose the caller's return address (pattern 11; "
           f"the channel_type_mode_settings_write incident)")
    if span_undec:
        msg += " [undecoded bytes in the scanned span: the scan is incomplete]"
    findings.append({
        "rule": "L2-r15-liveness",
        "severity": "info" if span_undec else "warning",
        "site": h(addr),
        "message": msg,
        "evidence": (f"{corpus.describe(entry, rec)}; span [{h(entry)},{h(addr)}): "
                     f"{'push r15/lr found' if push_saves else 'no push of r15/lr'}, "
                     f"{'earlier call' if prior_call else 'no earlier bsr/jsr'}")})
    return findings


# ----------------------------------------------------------------------------------------------
# L3 - TODO placeholders anywhere in the manifest JSON
# ----------------------------------------------------------------------------------------------

def walk_strings(obj, prefix: str = ""):
    """Yield (json_path, string_value) for every string in a parsed JSON object."""
    if isinstance(obj, dict):
        for k, v in obj.items():
            yield from walk_strings(v, f"{prefix}.{k}" if prefix else k)
    elif isinstance(obj, list):
        for i, v in enumerate(obj):
            yield from walk_strings(v, f"{prefix}[{i}]")
    elif isinstance(obj, str):
        yield prefix, obj


# ----------------------------------------------------------------------------------------------
# L6 - @stock:<name> targets resolve in tools/link/dm32_stock_symbols.ld
# ----------------------------------------------------------------------------------------------

def stock_symbol_names() -> set[str]:
    names: set[str] = set()
    if STOCK_SYMBOLS_LD.exists():
        for m in PROVIDE_RE.finditer(STOCK_SYMBOLS_LD.read_text()):
            names.add(m.group(1))
    return names


def branch_targets(item: dict):
    """Yield every branch/expect_branch target string in a splice or assert item."""
    for key in ("branch", "expect_branch"):
        b = item.get(key)
        if isinstance(b, dict) and isinstance(b.get("target"), str):
            yield key, b["target"]


# ----------------------------------------------------------------------------------------------
# the two lints
# ----------------------------------------------------------------------------------------------

def lint_manifest(path: pathlib.Path, extra_allocations=(), corpus: Corpus | None = None) -> list[dict]:
    """All six L-rules for one manifest. Returns findings (never raises on manifest content)."""
    corpus = corpus or Corpus()
    findings: list[dict] = []
    try:
        m = json.loads(path.read_text())
    except (OSError, ValueError) as e:
        return [{"rule": "manifest-load", "severity": "error", "site": str(path),
                 "message": f"cannot read manifest: {e}", "evidence": ""}]
    if not isinstance(m, dict):
        return [{"rule": "manifest-load", "severity": "error", "site": str(path),
                 "message": "manifest root is not a JSON object", "evidence": ""}]

    # L3: TODO anywhere.
    for where, val in walk_strings(m):
        if "TODO" in val:
            findings.append({
                "rule": "L3-todo", "severity": "error", "site": where or "<manifest>",
                "message": f"placeholder {val!r} is still a TODO (the builder refuses these too)",
                "evidence": "value contains 'TODO'"})

    # L4: exactly one expectation and one replacement per splice.
    for i, s in enumerate(m.get("splices", [])):
        where = f"splices[{i}]"
        exps = [k for k in ("expect", "expect_u32", "expect_u8", "expect_branch") if k in s]
        reps = [k for k in ("bytes", "u32", "u8", "branch") if k in s]
        if len(exps) != 1 or len(reps) != 1:
            findings.append({
                "rule": "L4-splice-schema", "severity": "error", "site": where,
                "message": f"splice {s.get('name', where)!r} has expectation key(s) {exps} and "
                           f"replacement key(s) {reps}; need exactly one of each (mirror the "
                           f"builder's schema)",
                "evidence": "build_manifest_patch.py: splice has ONE expectation + ONE replacement"})

    # L5: allocations names resolve (same merge as the builder: duplicate names = error).
    allocs = m.get("allocations", [])
    try:
        merged = load_allocations([pathlib.Path(a) for a in extra_allocations])
    except BuildError as e:
        findings.append({"rule": "L5-claims", "severity": "error", "site": "allocations",
                         "message": f"allocation merge failed: {e}",
                         "evidence": "load_allocations() (same semantics as the builder)"})
        known: set[str] = set()
    else:
        known = {c["name"] for c in merged["claims"]}
    if not allocs:
        findings.append({
            "rule": "L5-claims", "severity": "warning", "site": "allocations",
            "message": "'allocations' is empty; every build will warn that this patch's writes "
                       "are unclaimed (see the builder's check_policy)",
            "evidence": "manifest 'allocations' == []"})
    for n in allocs:
        if n not in known:
            findings.append({
                "rule": "L5-claims", "severity": "error", "site": f"allocations.{n}",
                "message": f"unknown allocation claim {n!r}",
                "evidence": "not in data/allocations.json nor any --extra-allocations file"})

    # L6: @stock:<name> targets must exist in dm32_stock_symbols.ld.
    stock = stock_symbol_names()
    for i, s in enumerate(m.get("splices", [])):
        for key, tgt in branch_targets(s):
            if tgt.startswith("@stock:"):
                name = re.sub(r"[+\-].*$", "", tgt[len("@stock:"):])
                if name not in stock:
                    findings.append({
                        "rule": "L6-stock-symbol", "severity": "error",
                        "site": f"splices.{s.get('name', i)}.{key}.target",
                        "message": f"@stock:{name} is not in tools/link/dm32_stock_symbols.ld",
                        "evidence": f"no PROVIDE({name} = ...) in dm32_stock_symbols.ld"})
    for i, a in enumerate(m.get("asserts", [])):
        for key, tgt in branch_targets(a):
            if tgt.startswith("@stock:"):
                name = re.sub(r"[+\-].*$", "", tgt[len("@stock:"):])
                if name not in stock:
                    findings.append({
                        "rule": "L6-stock-symbol", "severity": "error",
                        "site": f"asserts.{a.get('name', i)}.{key}.target",
                        "message": f"@stock:{name} is not in tools/link/dm32_stock_symbols.ld",
                        "evidence": f"no PROVIDE({name} = ...) in dm32_stock_symbols.ld"})

    # L1/L2: every splice's hook site. L2 only for splices that write a bsr.
    for i, s in enumerate(m.get("splices", [])):
        try:
            addr = int(str(s.get("addr")), 0)
        except (ValueError, TypeError):
            continue  # a TODO address is already flagged by L3
        br = s.get("branch")
        is_bsr = isinstance(br, dict) and br.get("kind") == "bsr"
        findings.extend(lint_hook_site(addr, corpus, check_l2=is_bsr))

    return findings


def verdict(findings: list[dict], strict: bool) -> tuple[str, int]:
    errs = any(f["severity"] == "error" for f in findings)
    warns = any(f["severity"] == "warning" for f in findings)
    fail = errs or (strict and warns)
    return ("FAIL" if fail else "PASS"), (1 if fail else 0)


# ----------------------------------------------------------------------------------------------
# CLI
# ----------------------------------------------------------------------------------------------

def main(argv=None) -> int:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="exit: 0 PASS, 1 FAIL, 2 usage; --strict promotes warnings to FAIL")
    ap.add_argument("manifest", nargs="?", type=pathlib.Path, default=None,
                    help="patch manifest (*.patch.json) to lint (omit with --hook)")
    ap.add_argument("--hook", metavar="0xADDR", default=None,
                    help="one-shot 'should I bsr-hook here?' check for one raw address (L1/L2)")
    ap.add_argument("--strict", action="store_true",
                    help="promote warnings (L2, empty allocations) to failures")
    ap.add_argument("--extra-allocations", type=pathlib.Path, action="append", default=[],
                    metavar="FILE",
                    help="additional allocation file(s) merged with data/allocations.json "
                         "(repeatable; same semantics as the builder)")
    ap.add_argument("--json", nargs="?", const="-", default=None, metavar="PATH",
                    help="emit JSON to PATH, or to the final stdout line when PATH is omitted "
                         "or '-'")
    args = ap.parse_args(argv)

    if args.hook and args.manifest:
        print("ERROR: give either a manifest or --hook, not both", file=sys.stderr)
        return 2
    if not args.hook and args.manifest is None:
        print("ERROR: give a manifest path or --hook 0xADDR", file=sys.stderr)
        return 2

    try:
        if args.hook:
            addr = int(args.hook, 0)
        else:
            addr = None
    except ValueError:
        print(f"ERROR: bad address {args.hook!r}", file=sys.stderr)
        return 2

    if addr is not None:
        findings = lint_hook_site(addr, Corpus(), check_l2=True)
    else:
        findings = lint_manifest(args.manifest, args.extra_allocations)

    v, exit_code = verdict(findings, args.strict)

    for f in findings:
        print(f"{f['severity'].upper():<4} {f['rule']:<18} {f['site']:<12} {f['message']}")
    print(f"LINT {v}")

    if args.json is not None:
        payload = {"findings": findings, "verdict": v, "exit_code": exit_code}
        if args.json == "-":
            print(json.dumps(payload))  # the final stdout line
        else:
            pathlib.Path(args.json).write_text(json.dumps(payload) + "\n")
    return exit_code


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/env python3
"""Generate meta/patch_api.json, the machine-queryable view of the stock-firmware patch API.

Input (hand-maintained): tools/include/dm32_patch_api.h -- the C header that declares every
stock primitive a DM-32UV patch may call (typed function-pointer #defines, RAM/SRAM cells, small
constants), with section-banner comments and per-entry confidence tags.

Output (regenerated, never hand-edited): meta/patch_api.json -- one entry per `#define` in the
header (the include guard is skipped), plus the typedefs the header defines, under a "types" key.
Each api entry carries the definition's kind, its raw macro body, the section banner it lives
under, the nearest preceding comment block, any trailing same-line comment, the source line, and a
machine-usable `confidence`. Everything is emitted in header order, so the output is deterministic
for a given header.

Kind classification of a `#define`'s body (never silently drop a definition):
  function  -- a cast to a pointer-to-function:           `((RET (*)(ARGS))0xADDR)`
  cell      -- a cast to a pointer-to-object (a RAM/SRAM cell or table):  `((TYPE *)0xADDR)`
  constant  -- a bare integer literal (hex or decimal), e.g. `SCAN_BACK 0x06`, `MENU_MAX_VISIBLE_ROWS 8`
  other     -- anything that parses as none of the above (function-like expression macros such as
               UI_LANG_IS_ENGLISH(), multi-token bodies); the raw body is kept so nothing is lost.
The include-guard `#define DM32_PATCH_API_H` (empty body) is skipped.

Per-entry fields by kind (all entries also carry line/section/comment/trailing_comment/confidence/raw):
  function  -- address (hex, normalized 0x%08x), return_type, args (ordered list of {type, name}
               as written in the header), prototype (the function-pointer type as written).
  cell      -- address (normalized), type (pointer type as written, e.g. "volatile u32 *"),
               pointed_at (type without the outermost '*', e.g. "volatile u32").
  constant  -- value (the literal exactly as written, e.g. "0x06", "8", "0x0303d872").
  other     -- note ("function-like macro" or "unclassified macro body") + the raw body.

Comment attachment: an entry's `comment` is the nearest comment block that directly precedes the
#define (only blank lines may sit between them); the file's own header comment, guards, and
typedefs do not count as "directly preceding", so they never leak onto the first define. A banner
comment (first line starts with `/* ----...`) is treated as the section header, not as an entry
comment. `trailing_comment` is any same-line /* ... */ after the macro body.

Section: the title of the nearest preceding banner, using the banner's own words -- the first
non-dash line cut at the first '(' or '.' (e.g. "Display primitives", "Keypad", "RTOS",
"Menu / sub-list cells", "Patch scratch RAM").

Confidence mapping (documented here because it is the contract the tests check):
  Search, in order: the entry's own preceding comment, its trailing same-line comment, then the
  section banner's full text. The first text containing a recognised tag decides the value; `null`
  when none does. Tag -> value (all case-insensitive substring matches):
    "confirmed on hardware"                    -> "CONFIRMED (hardware)"
    "qemu-confirmed"                           -> "CONFIRMED (QEMU)"
    "qemu confirmed" | "confirmed under qemu"  -> "CONFIRMED (QEMU)"
    "measured under qemu"                      -> "CONFIRMED (QEMU)"   (the MEASURED tag, QEMU-qualified)
    "structural"                               -> "STRUCTURAL"
  There is deliberately no "raw" rule: the word appears in prose ("returns a raw scan code") and
  would false-positive; RAW (FUN_xxxxxxxx) confidence comes from meta/functions.json, never from
  header prose. A bare "CONFIRMED" with no medium qualifier, or "CONFIRMED against <sources>"
  (a source-level confirmation, neither hardware nor QEMU), maps to null. The "CONFIRMED (hardware)"
  tag of a section banner outranks a QEMU measurement tag in the same banner, because the banner
  leads with the hardware claim and states the QEMU measurement as a secondary detail.

Usage (pure python, stdlib only; runs on the host or in the image):
    python3 tools/src/dm32_patch_tools/gen_patch_api.py            # (re)generate
    python3 tools/src/dm32_patch_tools/gen_patch_api.py --check    # exit 1 if stale
"""
from __future__ import annotations

import argparse
import json
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parents[3]
DEFAULT_HEADER = ROOT / "tools" / "include" / "dm32_patch_api.h"
DEFAULT_OUT = ROOT / "meta" / "patch_api.json"

FIRMWARE = "DM32.00.01.048 (load base 0x03000000)"

_DEFINE_RE = re.compile(r"^#\s*define\s+([A-Za-z_][A-Za-z0-9_]*)(\(\s*\))?(.*)$")
_TYPEDEF_RE = re.compile(r"^typedef\s+(.+?)\s+([A-Za-z_][A-Za-z0-9_]*)\s*;\s*$")
# A cast-to-address body:  ((TYPE)ADDR)  -- TYPE is greedy, ADDR is the trailing 0x... literal.
_CAST_RE = re.compile(r"^\(\s*\(\s*(?P<type>.+)\)\s*(?P<addr>0[xX][0-9a-fA-F]+)\s*\)$", re.S)
_FN_PTR_RE = re.compile(r"\(\s*\*\s*\)\s*\(")
_RET_RE = re.compile(r"^(?P<ret>.*?)\s*\(\s*\*\s*\)\s*\(\s*(?P<params>.*)\s*\)\s*$", re.S)
_ARG_RE = re.compile(r"^(?P<type>.+?)\s+(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*$")
_BARE_HEX_RE = re.compile(r"^(?P<val>0[xX][0-9a-fA-F]+)$")
_BARE_INT_RE = re.compile(r"^(?P<val>[0-9]+)$")
_TRAILING_CMT_RE = re.compile(r"/\*.*?\*/")
BANNER_OPEN_RE = re.compile(r"^/\*\s*-{3,}")

# (needle, value) -- first needle found in the first matching text wins.
CONFIDENCE_TAGS = (
    ("confirmed on hardware", "CONFIRMED (hardware)"),
    ("qemu-confirmed", "CONFIRMED (QEMU)"),
    ("qemu confirmed", "CONFIRMED (QEMU)"),
    ("confirmed under qemu", "CONFIRMED (QEMU)"),
    ("measured under qemu", "CONFIRMED (QEMU)"),
    ("structural", "STRUCTURAL"),
)


def die(msg: str) -> "NoReturn":  # type: ignore[name-defined]
    sys.exit(f"gen_patch_api: ERROR: {msg}")


def clean_comment(text: str) -> str:
    """Strip /* */ markers and per-line leading '* ' from a comment block."""
    out = []
    for raw in text.splitlines():
        line = raw.strip()
        if line.startswith("/*"):
            line = line[2:].lstrip()
        if line.endswith("*/"):
            line = line[:-2].rstrip()
        if line.startswith("*"):
            line = line[1:].lstrip()
        out.append(line.strip())
    return "\n".join(out).strip()


def banner_title(text: str) -> str:
    """The banner's own words: the first non-dash line cut at the first '(' or '.'."""
    for line in text.splitlines():
        s = line.strip()
        if not s or set(s) <= set("-"):
            continue
        return re.split(r"[\(\.]", s, maxsplit=1)[0].strip()
    return ""


def confidence_of(text: str):
    if not text:
        return None
    low = text.lower()
    for needle, value in CONFIDENCE_TAGS:
        if needle in low:
            return value
    return None


def split_top_level(text: str) -> list[str]:
    """Split on commas that are not nested inside (), [], {}."""
    parts, depth, cur = [], 0, []
    for ch in text:
        if ch in "([{":
            depth += 1
            cur.append(ch)
        elif ch in ")]}":
            depth -= 1
            cur.append(ch)
        elif ch == "," and depth == 0:
            parts.append("".join(cur))
            cur = []
        else:
            cur.append(ch)
    parts.append("".join(cur))
    return parts


def parse_prototype(typ: str):
    """Split a function-pointer type into (return_type, [{'type', 'name'}, ...])."""
    m = _RET_RE.match(typ)
    if not m:
        die(f"cannot parse function-pointer type: {typ!r}")
    ret = " ".join(m.group("ret").split())
    params = m.group("params")
    if params.strip() == "void":
        return ret, []
    args = []
    for part in split_top_level(params):
        part = part.strip()
        am = _ARG_RE.match(part)
        if am:
            args.append({"type": " ".join(am.group("type").split()), "name": am.group("name")})
        else:
            args.append({"type": part, "name": None})
    return ret, args


def pointed_at(typ: str) -> str:
    """The type a cell pointer points at: the pointer type minus its outermost '*'.
    e.g. "volatile u32 *" -> "volatile u32", "void (**)" -> "void (*)"."""
    idx = typ.rfind("*")
    if idx == -1:
        return " ".join(typ.split())
    return " ".join((typ[:idx] + typ[idx + 1:]).split())


def classify_define(name: str, body: str, raw: str, is_fnlike: bool) -> dict:
    e: dict = {"name": name, "kind": "other"}
    if is_fnlike:
        e.update({"note": "function-like macro", "raw": raw})
        return e
    cm = _CAST_RE.match(body)
    if cm:
        typ = " ".join(cm.group("type").split())
        addr = f"0x{int(cm.group('addr'), 16):08x}"
        if _FN_PTR_RE.search(typ):
            ret, args = parse_prototype(typ)
            e.update({"kind": "function", "address": addr, "return_type": ret,
                      "args": args, "prototype": typ})
        elif "*" in typ:
            e.update({"kind": "cell", "address": addr, "type": typ,
                      "pointed_at": pointed_at(typ)})
        else:
            e.update({"kind": "other", "address": addr,
                      "note": f"cast to non-pointer type: {typ}"})
        e["raw"] = raw
        return e
    hm = _BARE_HEX_RE.match(body)
    if hm:
        e.update({"kind": "constant", "value": hm.group("val")})
        e["raw"] = raw
        return e
    im = _BARE_INT_RE.match(body)
    if im:
        e.update({"kind": "constant", "value": im.group("val")})
        e["raw"] = raw
        return e
    e.update({"note": "unclassified macro body", "raw": raw})
    return e


def resolve_confidence(pending, trailing, section):
    for text in (pending["text"] if pending else None,
                 trailing,
                 section["text"] if section else None):
        c = confidence_of(text)
        if c:
            return c
    return None


def parse_header(text: str):
    lines = text.splitlines()
    n = len(lines)
    entries: list[dict] = []
    typedefs: list[dict] = []
    section = None      # {"title", "text"} of the nearest preceding banner
    pending = None      # {"text", "end"} of the nearest preceding non-banner comment
    i = 0
    while i < n:
        line = lines[i]
        stripped = line.strip()
        if stripped.startswith("/*"):
            start = i
            parts = [line]
            while "*/" not in line:
                i += 1
                if i >= n:
                    die(f"unterminated comment starting at line {start + 1}")
                line = lines[i]
                parts.append(line)
            ctext = clean_comment("\n".join(parts))
            if BANNER_OPEN_RE.match(parts[0]):
                section = {"title": banner_title(ctext), "text": ctext}
                pending = None
            else:
                pending = {"text": ctext, "end": i}
            i += 1
            continue
        if stripped.startswith("#define"):
            m = _DEFINE_RE.match(stripped)
            if not m:
                die(f"unparseable #define at line {i + 1}: {line!r}")
            name = m.group(1)
            is_fnlike = m.group(2) is not None
            parts = [m.group(3)]
            cur = line
            while cur.rstrip().endswith("\\"):
                i += 1
                if i >= n:
                    die(f"macro {name} ends the file on a continuation (line {i + 1})")
                cur = lines[i]
                parts.append(cur)
            body_lines = []
            for part in parts:
                p = part.rstrip()
                if p.endswith("\\"):
                    p = p[:-1]
                body_lines.append(p.strip())
            raw = " ".join(b for b in body_lines if b)
            if not raw:
                # empty body: the include guard (#define DM32_PATCH_API_H) -- skip it.
                i += 1
                continue
            trailing = None
            tcm = _TRAILING_CMT_RE.search(raw)
            if tcm:
                trailing = clean_comment(tcm.group(0))
                body = (raw[:tcm.start()] + raw[tcm.end():]).strip()
            else:
                body = raw
            if pending is not None and any(g.strip() for g in lines[pending["end"] + 1:i]):
                pending = None      # non-blank lines sat between the comment and the define
            entry = classify_define(name, body, raw, is_fnlike)
            entry.update({
                "line": i - len(parts) + 2,          # 1-based line of the #define keyword
                "section": section["title"] if section else None,
                "comment": pending["text"] if pending else None,
                "trailing_comment": trailing,
                "confidence": resolve_confidence(pending, trailing, section),
            })
            entries.append(entry)
            pending = None
            i += 1
            continue
        if stripped.startswith("typedef"):
            tm = _TYPEDEF_RE.match(stripped)
            if tm:
                typedefs.append({"name": tm.group(2),
                                 "type": re.sub(r"\s+", " ", tm.group(1)).strip(),
                                 "line": i + 1})
            i += 1
            continue
        # guards (#ifndef/#if/#endif) and blank lines: nothing to record.
        i += 1
    return entries, typedefs


def build_doc(header: pathlib.Path) -> dict:
    entries, typedefs = parse_header(header.read_text())
    counts = {}
    for e in entries:
        counts[e["kind"]] = counts.get(e["kind"], 0) + 1
    return {
        "_comment": [
            "generated by tools/src/dm32_patch_tools/gen_patch_api.py from "
            "tools/include/dm32_patch_api.h",
            "do not hand-edit; regenerate with `make -C tools patch-api`; --check fails on "
            "staleness",
        ],
        "source": "tools/include/dm32_patch_api.h",
        "firmware": FIRMWARE,
        "types": typedefs,
        "api": entries,
        "counts": counts,
    }


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--header", type=pathlib.Path, default=DEFAULT_HEADER,
                    help="hand-maintained header to read (default: tools/include/dm32_patch_api.h)")
    ap.add_argument("--out", type=pathlib.Path, default=DEFAULT_OUT,
                    help="output json (default: meta/patch_api.json)")
    ap.add_argument("--check", action="store_true",
                    help="do not write; exit 1 if the committed json is stale")
    args = ap.parse_args(argv)

    doc = build_doc(args.header)
    text = json.dumps(doc, indent=1)

    if args.check:
        if not args.out.exists() or args.out.read_text() != text:
            print(f"STALE: {args.out} (stale; re-run gen_patch_api.py)", file=sys.stderr)
            return 1
        return 0

    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(text)
    c = doc["counts"]
    print(f"wrote {len(doc['api'])} API entries ({c['function']} functions, "
          f"{c['constant']} constants, {c['cell']} cells, {c.get('other', 0)} other) "
          f"to {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

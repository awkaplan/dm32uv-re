#!/usr/bin/env python3
"""Generate C headers, a JSON evidence index and HTML from the SystemRDL chip descriptions.

    gen_rdl.py                 regenerate everything for every specs/rdl/*.rdl
    gen_rdl.py w25q128jv       only the named chip(s) (file stems)
    gen_rdl.py --check         write nothing; exit 1 if anything committed is stale or any
                               register/field breaks the evidence rule
    gen_rdl.py --no-html       skip the (uncommitted) HTML

Needs the `specs` dependency group (`cd tools && uv sync --group specs`); exits 2 without it.

INPUTS: every specs/rdl/*.rdl except dm32_udp.rdl (the evidence properties, which each chip file
includes). The top addrmap of each file must be named after the file stem. Include path:
specs/rdl.

OUTPUTS, per chip (all deterministic: same input, byte-identical output):

  specs/generated/include/<chip>.h          committed
      PeakRDL-cheader output: `<CHIP>__<BLOCK>__<REG>__<FIELD>_bm/_bp/_bw/_reset` macros, plus a
      packed struct per block. Options, chosen because these chips are NOT memory-mapped (they
      sit on SPI / 3-wire / I2C, so nothing is ever overlaid on an address):
        std=gnu99               the headers must build under -std=c99 (the patch toolchain is
                                GCC 6.3); gnu99 also drops PeakRDL's _Static_assert footer
        generate_bitfields=False C bitfield packing is implementation-defined; the mask/shift
                                macros are the useful part for a byte that came off a wire
        instantiate=False       no base-address instance macro: there is no base address
      The structs are a SHADOW layout (one member per register, in description order), useful
      only as a cache of register values; they do not describe any memory. A preamble saying so
      is inserted after PeakRDL's banner.

  specs/generated/include/<chip>_regnum.h   committed
      What PeakRDL does not emit for a non-memory-mapped chip: the number that selects each
      register ON THE WIRE, as one C enum per block (`enum <chip>_<block>`; registers placed
      directly in the top addrmap go in `enum <chip>_reg`). The rule, per register:
          wire_addr property, if set            (paged / opcode-selected / odd-width register files)
          else address_offset // (regwidth/8)   (offset within its immediate parent block)
      A block whose instance name is `cmd` is the chip's COMMAND SET (see below): its enum is the
      opcode enum, each entry's comment naming `wr_cmd` and marking DESTRUCTIVE registers, followed
      by <CHIP>_CMD_DESTRUCTIVE_COUNT / _DESTRUCTIVE_LIST / _IS_DESTRUCTIVE(op) built from the
      `destructive` property. Every `encode` enum used by a field is emitted as `enum <chip>_<enum>` too, with
      members <CHIP>_<ENUM minus a trailing _e/_t>_<MEMBER>.

  specs/generated/json/<chip>.json          committed
      Evidence index for tools and agents: every block, register and field with confidence,
      ds_ref, ds_value, fw_writes, fw_reads, hw_reads, reset, access, wire number and encode
      values; registers also carry wr_cmd and destructive, fields nonvolatile (true/false, or
      null when the .rdl does not say). Query example:
          python3 -c "import json; d=json.load(open('specs/generated/json/w25q128jv.json'));
                      print([r['inst_name'] for r in d['registers'] if r['fw_writes']])"

  out/specs-html/<chip>/                    NOT committed (out/ is git-ignored)
      PeakRDL-html browsable register docs.

HOW COMMANDS / OPCODES ARE WRITTEN IN SYSTEMRDL (repo convention): a SystemRDL `enum` cannot carry
user-defined properties on its members, so it cannot hold per-opcode evidence. A chip's command
set is therefore a sub-addrmap instantiated as `cmd`, holding one 8-bit pseudo-register per
opcode at address offset == opcode, each with exactly one constant field named `opcode`
(sw = r, hw = na, reset = the opcode) and the usual confidence / ds_ref / fw_writes properties.
This generator validates that shape (hard error otherwise) and emits the block as a C enum.

EVIDENCE RULE (specs/README.md), enforced as a hard error in both modes: every reg and every
field has `confidence` in {CONFIRMED, DATASHEET, STRUCTURAL, INFERRED} and at least one of
ds_ref / fw_writes / fw_reads / hw_reads. A `confidence` set on a block must also be valid.

Exit status: 0 OK, 1 stale output / evidence violation / RDL compile error, 2 toolchain missing.
"""
from __future__ import annotations

import argparse
import io
import json
import pathlib
import re
import sys
import tempfile

REPO = pathlib.Path(__file__).resolve().parents[3]
RDL_DIR = REPO / "specs" / "rdl"
INC_DIR = REPO / "specs" / "generated" / "include"
JSON_DIR = REPO / "specs" / "generated" / "json"
HTML_DIR = REPO / "out" / "specs-html"
UDP_FILE = "dm32_udp.rdl"
GENERATOR = "tools/src/dm32_patch_tools/gen_rdl.py"

CONFIDENCE = ("CONFIRMED", "DATASHEET", "STRUCTURAL", "INFERRED")
EVIDENCE = ("ds_ref", "fw_writes", "fw_reads", "hw_reads")
UDPS = ("confidence", "ds_ref", "ds_value", "fw_writes", "fw_reads", "hw_reads", "wire_addr")
CMD_BLOCK = "cmd"

CHEADER_PREAMBLE = """\
// dm32uv-re: generated from {src} by {gen} (do not edit).
// This chip is not memory-mapped: use the _bm/_bp/_bw/_reset field macros on register values
// read from or written to the wire. The packed structs below are a shadow layout (one member per
// register) and describe no real memory. Wire register numbers and opcodes: {chip}_regnum.h.
// Evidence for every register and field: specs/generated/json/{chip}.json.

"""


class ToolchainMissing(Exception):
    pass


def _import_toolchain():
    try:
        from systemrdl import RDLCompiler, RDLCompileError  # noqa: F401
        from systemrdl.node import AddrmapNode, FieldNode, RegNode, RegfileNode  # noqa: F401
        from peakrdl_cheader.exporter import CHeaderExporter  # noqa: F401
        from peakrdl_cheader.c_standards import CStandard  # noqa: F401
    except ImportError as e:  # pragma: no cover - exercised by the test's skip path
        raise ToolchainMissing(
            f"{e}. Install the specs group: cd tools && uv sync --group specs") from e


# ------------------------------------------------------------------------------------------ model

def chip_files(only: list[str] | None = None) -> list[pathlib.Path]:
    files = sorted(p for p in RDL_DIR.glob("*.rdl") if p.name != UDP_FILE)
    if only:
        known = {p.stem for p in files}
        missing = sorted(set(only) - known)
        if missing:
            raise SystemExit(f"error: no specs/rdl/<chip>.rdl for: {', '.join(missing)}")
        files = [p for p in files if p.stem in only]
    return files


def compile_chip(path: pathlib.Path):
    from systemrdl import RDLCompiler
    rdlc = RDLCompiler()
    rdlc.compile_file(str(path), incl_search_paths=[str(RDL_DIR)])
    return rdlc.elaborate(top_def_name=path.stem).top


def prop(node, name):
    """A property value, or None if unset / not defined (a chip file that forgot the include)."""
    try:
        return node.get_property(name, default=None)
    except LookupError:
        return None


def enum_name(v):
    return None if v is None else getattr(v, "name", str(v))


def regs_in_order(top):
    from systemrdl.node import RegNode
    return [n for n in top.descendants(unroll=True) if isinstance(n, RegNode)]


def blocks_in_order(top):
    from systemrdl.node import AddrmapNode, RegfileNode
    return [n for n in top.descendants(unroll=True) if isinstance(n, (AddrmapNode, RegfileNode))]


def seg(node) -> str:
    """Instance name with array indices, e.g. `REG` or `REG_3`."""
    if node.is_array and node.current_idx is not None:
        return node.inst_name + "".join(f"_{i}" for i in node.current_idx)
    return node.inst_name


def block_key(reg, top) -> list[str]:
    """Path of the reg's parent block below the top addrmap, e.g. ['cmd'] or [] (top level)."""
    out, p = [], reg.parent
    while p is not None and p is not top:
        out.append(seg(p))
        p = p.parent
    return out[::-1]


def wire_number(reg) -> tuple[int, str]:
    wa = prop(reg, "wire_addr")
    if wa is not None:
        return int(wa), "wire_addr"
    return reg.address_offset // (reg.get_property("regwidth") // 8), "offset"


def field_reset(f):
    r = f.get_property("reset")
    return r if isinstance(r, int) else None


def reg_reset(reg):
    total = 0
    for f in reg.fields():
        r = field_reset(f)
        if r is None:
            return None
        total |= r << f.lsb
    return total


# --------------------------------------------------------------------------------------- checks

def evidence_problems(top) -> list[str]:
    """The specs/README.md evidence rule, plus the `cmd` block shape. Empty list = clean."""
    from systemrdl.node import FieldNode, RegNode
    probs = []
    for n in [top] + blocks_in_order(top):
        c = prop(n, "confidence")
        if c is not None and c not in CONFIDENCE:
            probs.append(f"{n.get_path()}: confidence {c!r} not one of {', '.join(CONFIDENCE)}")
    for n in top.descendants(unroll=False):
        if not isinstance(n, (RegNode, FieldNode)):
            continue
        kind = "reg" if isinstance(n, RegNode) else "field"
        c = prop(n, "confidence")
        if c is None:
            probs.append(f"{n.get_path()}: {kind} has no confidence")
        elif c not in CONFIDENCE:
            probs.append(f"{n.get_path()}: confidence {c!r} not one of {', '.join(CONFIDENCE)}")
        if not any(prop(n, e) for e in EVIDENCE):
            probs.append(f"{n.get_path()}: {kind} has none of {'/'.join(EVIDENCE)}")
    # wire numbers unique per block; command blocks well-formed
    seen: dict[tuple, str] = {}
    for r in regs_in_order(top):
        key = tuple(block_key(r, top))
        num, _ = wire_number(r)
        other = seen.get(key + (num,))
        if other:
            probs.append(f"{r.get_path()}: wire number 0x{num:X} already used by {other}")
        seen[key + (num,)] = r.get_path()
        if key and key[-1] == CMD_BLOCK:
            fs = list(r.fields())
            ok = (len(fs) == 1 and fs[0].inst_name == "opcode" and fs[0].width == 8
                  and enum_name(fs[0].get_property("sw")) == "r"
                  and enum_name(fs[0].get_property("hw")) == "na"
                  and field_reset(fs[0]) == num and r.get_property("regwidth") == 8)
            if not ok:
                probs.append(f"{r.get_path()}: a `{CMD_BLOCK}` register must be 8 bits wide with one "
                             f"constant field `opcode` (sw=r, hw=na) whose reset equals its wire "
                             f"number 0x{num:X}")
    return probs


# ------------------------------------------------------------------------------------- outputs

def gen_cheader(top, chip: str, src: str) -> str:
    from peakrdl_cheader.c_standards import CStandard
    from peakrdl_cheader.exporter import CHeaderExporter
    with tempfile.TemporaryDirectory(prefix="gen_rdl-") as td:
        out = pathlib.Path(td) / f"{chip}.h"   # same file name: the include guard derives from it
        CHeaderExporter().export(top, str(out), std=CStandard.gnu99, generate_bitfields=False,
                                 instantiate=False, reuse_typedefs=True)
        text = out.read_text()
    lines = text.splitlines(keepends=True)
    # keep PeakRDL's 2-line attribution banner first, then ours
    cut = 0
    while cut < len(lines) and lines[cut].startswith("//"):
        cut += 1
    pre = CHEADER_PREAMBLE.format(src=src, gen=GENERATOR, chip=chip)
    return "".join(lines[:cut]) + pre + "".join(lines[cut:]).lstrip("\n")


def c_ident(*parts: str) -> str:
    return re.sub(r"[^A-Za-z0-9_]", "_", "_".join(p for p in parts if p))


def c_comment(s) -> str:
    s = " ".join(str(s).split())
    return s.replace("*/", "* /")


def gen_regnum(top, chip: str, src: str) -> str:
    CHIP = chip.upper()
    guard = c_ident(CHIP, "REGNUM_H")
    out = io.StringIO()
    w = out.write
    w(f"/* {chip}_regnum.h - generated from {src} by {GENERATOR}; do not edit.\n")
    w(" *\n")
    w(" * Wire register numbers and command opcodes for a chip that is not memory-mapped.\n")
    w(" * Rule: a register's number is its `wire_addr` property if set, else its address offset\n")
    w(" * within its parent block divided by its width in bytes. For SPI NOR flashes the status\n")
    w(" * and ID registers are selected by opcode, so their wire_addr is the opcode that READS them.\n")
    w(f" * The `{CMD_BLOCK}` block is the command set: one pseudo-register per opcode at offset ==\n")
    w(" * opcode (SystemRDL enum members cannot carry evidence properties, registers can).\n")
    w(" * [CONFIDENCE] after each entry is the register's confidence; the evidence behind it (datasheet\n")
    w(f" * section, stock-firmware call sites, hardware reads) is in specs/generated/json/{chip}.json.\n")
    w(" */\n")
    w(f"#ifndef {guard}\n#define {guard}\n\n")

    groups: dict[tuple, list] = {}
    for r in regs_in_order(top):
        groups.setdefault(tuple(block_key(r, top)), []).append(r)
    for key, regs in groups.items():
        block_name = "_".join(key) if key else "reg"
        blk = regs[0].parent
        title = prop(blk, "name") if key else "registers"
        is_cmd = bool(key) and key[-1] == CMD_BLOCK
        w(f"/* {c_comment(title)}{' (opcodes)' if is_cmd else ''} */\n")
        w(f"enum {c_ident(chip, block_name)} {{\n")
        ents = []
        for r in regs:
            num, how = wire_number(r)
            name = c_ident(CHIP, *(k.upper() for k in key), seg(r).upper())
            note = f"{r.get_property('name')} [{prop(r, 'confidence')}]"
            if not is_cmd and how == "wire_addr":
                note += " (wire_addr)"
            if prop(r, "wr_cmd"):
                note += f" written by {prop(r, 'wr_cmd')}"
            if prop(r, "destructive"):
                note += " DESTRUCTIVE"
            ents.append((num, name, note, bool(prop(r, "destructive"))))
        if is_cmd:
            ents.sort()
        width = max(len(e[1]) for e in ents)
        for num, name, note, _ in ents:
            w(f"    {name.ljust(width)} = 0x{num:02X}, /* {c_comment(note)} */\n")
        w("};\n\n")
        if is_cmd:
            pfx = c_ident(CHIP, *(k.upper() for k in key))
            bad = [e for e in ents if e[3]]
            w(f"/* Opcodes marked `destructive` in {src} (erase, program, status-register and\n"
              f" * security-register writes): flag every call site that sends one. */\n")
            w(f"#define {pfx}_DESTRUCTIVE_COUNT {len(bad)}\n")
            w(f"#define {pfx}_DESTRUCTIVE_LIST {', '.join(f'0x{e[0]:02X}' for e in bad)}\n")
            cond = " || ".join(f"(op) == 0x{e[0]:02X}" for e in bad) or "0"
            w(f"#define {pfx}_IS_DESTRUCTIVE(op) ({cond})\n\n")

    enums = {}
    for r in regs_in_order(top):
        for f in r.fields():
            e = f.get_property("encode")
            if e is not None:
                enums.setdefault(e.type_name, e)
    for tname in sorted(enums):
        e = enums[tname]
        w(f"/* encode enum {tname} */\n")
        w(f"enum {c_ident(chip, tname)} {{\n")
        members = sorted(e, key=lambda m: m.value)
        stem = re.sub(r"_[et]$", "", tname).upper()   # drv_e -> DRV
        width = max(len(c_ident(CHIP, stem, m.name)) for m in members)
        for m in members:
            nm = c_ident(CHIP, stem, m.name)
            desc = f" /* {c_comment(m.rdl_desc)} */" if m.rdl_desc else ""
            w(f"    {nm.ljust(width)} = {m.value},{desc}\n")
        w("};\n\n")
    w(f"#endif /* {guard} */\n")
    return out.getvalue()


def evidence_dict(node) -> dict:
    return {k: prop(node, k) for k in UDPS if k != "wire_addr"}


def flag(node, name):
    """A boolean UDP as True/False/None (None = not stated in the .rdl)."""
    v = prop(node, name)
    return None if v is None else bool(v)


def gen_json(top, chip: str, src: str) -> str:
    def text(node, p):
        v = prop(node, p)
        return None if v is None else " ".join(str(v).split())

    doc = {
        "generator": GENERATOR,
        "source": src,
        "chip": chip,
        "name": text(top, "name"),
        "desc": text(top, "desc"),
        **evidence_dict(top),
        "blocks": [],
        "registers": [],
        "enums": {},
    }
    for b in blocks_in_order(top):
        doc["blocks"].append({
            "path": b.get_path(), "inst_name": seg(b), "name": text(b, "name"),
            "desc": text(b, "desc"), "address": b.absolute_address,
            "is_command_set": seg(b) == CMD_BLOCK, **evidence_dict(b)})
    for r in regs_in_order(top):
        num, how = wire_number(r)
        fields = []
        for f in sorted(r.fields(), key=lambda f: f.lsb):
            e = f.get_property("encode")
            fields.append({
                "inst_name": f.inst_name, "name": text(f, "name"), "desc": text(f, "desc"),
                "lsb": f.lsb, "msb": f.msb, "width": f.width,
                "sw": enum_name(f.get_property("sw")), "hw": enum_name(f.get_property("hw")),
                "onwrite": enum_name(f.get_property("onwrite")),
                "reset": field_reset(f),
                "encode": None if e is None else e.type_name,
                "nonvolatile": flag(f, "nonvolatile"),
                **evidence_dict(f)})
        key = block_key(r, top)
        doc["registers"].append({
            "path": r.get_path(), "block": ".".join(key) or None, "inst_name": seg(r),
            "name": text(r, "name"), "desc": text(r, "desc"),
            "address": r.absolute_address, "offset": r.address_offset,
            "regwidth": r.get_property("regwidth"),
            "wire_number": num, "wire_number_source": how,
            "is_command": bool(key) and key[-1] == CMD_BLOCK,
            "reset": reg_reset(r),
            "wr_cmd": text(r, "wr_cmd"), "destructive": flag(r, "destructive"),
            **evidence_dict(r), "fields": fields})
        for f in r.fields():
            e = f.get_property("encode")
            if e is not None and e.type_name not in doc["enums"]:
                doc["enums"][e.type_name] = [
                    {"name": m.name, "value": m.value, "desc": m.rdl_desc}
                    for m in sorted(e, key=lambda m: m.value)]
    return json.dumps(doc, indent=1, ensure_ascii=True) + "\n"


def gen_html(top, chip: str) -> pathlib.Path:
    from peakrdl_html import HTMLExporter
    dest = HTML_DIR / chip
    HTMLExporter().export(top, str(dest))
    return dest


# ----------------------------------------------------------------------------------------- main

def outputs_for(path: pathlib.Path):
    """(top node, {repo-relative output path: content}) for one chip."""
    chip = path.stem
    top = compile_chip(path)
    src = str(path.relative_to(REPO))
    return top, {
        INC_DIR / f"{chip}.h": gen_cheader(top, chip, src),
        INC_DIR / f"{chip}_regnum.h": gen_regnum(top, chip, src),
        JSON_DIR / f"{chip}.json": gen_json(top, chip, src),
    }


def orphans(chips: set[str]) -> list[pathlib.Path]:
    """Generated files of ours whose .rdl is gone (only files carrying this generator's mark)."""
    out = []
    for p in sorted(JSON_DIR.glob("*.json")):
        try:
            mine = json.loads(p.read_text()).get("generator") == GENERATOR
        except (ValueError, OSError):
            mine = False
        if mine and p.stem not in chips:
            out.append(p)
    for p in sorted(INC_DIR.glob("*.h")):
        stem = p.stem[:-len("_regnum")] if p.stem.endswith("_regnum") else p.stem
        if stem not in chips and GENERATOR in p.read_text(errors="replace")[:600]:
            out.append(p)
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("chips", nargs="*", help="limit to these chip file stems")
    ap.add_argument("--check", action="store_true",
                    help="write nothing; exit 1 if generated files are stale or evidence is missing")
    ap.add_argument("--no-html", action="store_true", help="skip out/specs-html")
    args = ap.parse_args(argv)
    try:
        _import_toolchain()
    except ToolchainMissing as e:
        print(f"error: SystemRDL toolchain not available: {e}", file=sys.stderr)
        return 2
    from systemrdl import RDLCompileError

    files = chip_files(args.chips)
    failed = False
    stale: list[str] = []
    for path in files:
        rel = path.relative_to(REPO)
        try:
            top, outs = outputs_for(path)
        except RDLCompileError:
            print(f"FAIL {rel}: SystemRDL compile error (messages above)", file=sys.stderr)
            failed = True
            continue
        probs = evidence_problems(top)
        for p in probs:
            print(f"FAIL {rel}: {p}", file=sys.stderr)
        if probs:
            failed = True
            continue
        for dest, content in outs.items():
            drel = dest.relative_to(REPO)
            current = dest.read_text() if dest.exists() else None
            if args.check:
                if current != content:
                    stale.append(f"{drel} ({'missing' if current is None else 'stale'})")
            elif current != content:
                dest.parent.mkdir(parents=True, exist_ok=True)
                dest.write_text(content)
                print(f"wrote {drel}")
        if not args.check and not args.no_html:
            print(f"html  {gen_html(top, path.stem).relative_to(REPO)}/")
    if not args.chips:
        for p in orphans({p.stem for p in files}):
            stale.append(f"{p.relative_to(REPO)} (orphan: its .rdl no longer exists)")
    for s in stale:
        print(f"STALE {s}", file=sys.stderr)
    if stale:
        print("run tools/src/dm32_patch_tools/gen_rdl.py to regenerate", file=sys.stderr)
    ok = not failed and not stale
    print(f"gen_rdl: {len(files)} chip(s), {'OK' if ok else 'FAIL'}")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())

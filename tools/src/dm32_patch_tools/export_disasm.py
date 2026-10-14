"""Checklist item A: pair every corpus function with real disassembly.

Reads dm32uv-re/meta/functions.json (address + byte size per function, already known from the
main project's analysis) and, for each one, asks a plain disassembler - not a full
function-boundary analysis - to decode exactly that many bytes starting at that address. This
is deliberately NOT a re-run of Ghidra's analyzeAll: that takes minutes and would silently
let a fresh analysis disagree with the published corpus about where functions start and end.
Disassembling the corpus's own (addr, size) pairs instead means this script's output can only
ever describe the SAME functions the corpus already asserts, with ground-truth instruction
text standing next to the decompiler's reconstruction - exactly the point of this checklist
item (see notes/dm32uv-re-patch-readiness-checklist.md, item A, in the main repo).

A function body can be fragmented (inter-fragment literal pools, jump tables) - this script
flags that per the same lesson the main project already learned the hard way (see
truncated-functions-are-fragmented-not-truncated in project memory, and
DumpFunctionRanges.java's fragment-aware CSV in firmware/tools/ghidra_scripts/): it disassembles
strictly within [addr, addr+size) and records any byte range inside that span the disassembler
refuses to decode as an instruction (most often a literal pool word) rather than silently
including it as if it were code.

Output: one line of JSON per function, written to dm32uv-re/meta/disasm.jsonl, plus a per-file
sidecar "<name>_<addr>.disasm.txt" alongside the usual list in dm32uv-re/data/disasm/ for
functions a patch author will actually want to open directly.

KNOWN GAP, not fixed: cross-checking against the corpus's own halt_baddata()/"bad instruction"
markers (51 functions) finds 14 this script does NOT flag as having an undecoded span, even
though their decompiled .c does. Those 14 are "CPU_SR_Save-class" stops (mfcr/mtcr
control-register moves that decode as a plain, syntactically valid instruction)
- Ghidra's CONTROL-FLOW analysis refuses to continue past them, but a bare
Disassembler.disassemble() call, which is all this script does, has no opinion on control
flow and happily decodes the bytes. This is a different failure mode at a different layer
than the literal-pool / truncated-disassembly gaps this script DOES catch, and fixing it
would mean re-running Ghidra's full control-flow analysis per function - the exact cost this
script exists to avoid (see above). Treat halt_baddata() in the corpus's .c as the stronger
signal for "control flow is not understood here"; this script's undecoded_ranges is the
stronger signal for "these exact bytes are not one instruction, at all, under any analysis".
The count of 14 was measured on the committed corpus; vendor/ghidra_csky now decodes the privileged
instructions (CHANGELOG.md, "Added"; bank-0 mfcr/mtcr only, per its README), so re-measure after
regenerating the corpus with it.
"""
from __future__ import annotations

import argparse
import json
import pathlib
import sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent.parent))

from dm32_patch_tools.ghidra_project import open_program, FLASH_BASE

REPO_ROOT = pathlib.Path(__file__).resolve().parent.parent.parent.parent
FUNCTIONS_JSON = REPO_ROOT / "meta" / "functions.json"
OUT_JSONL = REPO_ROOT / "meta" / "disasm.jsonl"
OUT_DIR = REPO_ROOT / "data" / "disasm"


def disassemble_range(flat_api, program, start_offset: int, size: int):
    """Disassembles [start_offset, start_offset+size) within the flash image.

    Returns (instructions, undecoded_ranges) where instructions is a list of
    {"addr": "0x...", "mnemonic": str, "text": str, "length": int} in address order, and
    undecoded_ranges is a list of [start_hex, end_hex) spans that are NOT instructions -
    inline literal pools (a global's address embedded as data words right in the function
    body - e.g. display_lookup_channel_icon_and_bank's PTR_DAT_03054fb4 table) or genuine
    bad-instruction stops (the same ones the corpus's own decompiler flags with "WARNING:
    Control flow encountered bad instruction data" / halt_baddata()).

    RESYNCS ON 2-BYTE-ALIGNED BOUNDARIES after a failure, rather than retrying byte-by-byte
    or giving up on the rest of the function. Both extremes were tried and wrong:
      - Byte-by-byte retry calls Disassembler.disassemble() at every candidate offset,
        including ones that are not real instruction starts. Disassembly mutates the shared,
        persistent Ghidra listing, so an accidental "successful" decode of garbage at a
        misaligned offset gets COMMITTED and blocks the correct decode of real code that
        follows, for every function processed afterward in the same run (caught empirically:
        strlen_unaligned_path's one genuine bad-instruction byte at 0x30010fe cascaded into
        280+ bogus "undecoded" reports in unrelated later functions).
      - Giving up on the whole rest of the function after one failure is just as wrong the
        other way: display_lookup_channel_icon_and_bank has a 4-word literal pool at
        0x3054fb4 in the MIDDLE of a 564-byte function with real, fully-decompiled control
        flow both before and after it - stopping there would report 452 bytes of perfectly
        good code as "undecoded".
    Stepping forward by the CK803S minimum instruction width (2 bytes) and re-checking is
    safe against the first failure mode (every address probed is 2-byte aligned relative to
    a known-good instruction boundary, so it can never land mid-instruction the way the
    byte-by-byte retry did) while still recovering once real code resumes after a data span.
    """
    from ghidra.program.disassemble import Disassembler
    from ghidra.util.task import ConsoleTaskMonitor

    af = program.getAddressFactory()
    start = af.getDefaultAddressSpace().getAddress(start_offset)
    end_exclusive_offset = start_offset + size

    disasm = Disassembler.getDisassembler(program, ConsoleTaskMonitor(), None)
    listing = program.getListing()

    instructions = []
    undecoded_ranges = []
    cur = start
    undecoded_start = None

    tid = program.startTransaction("export_disasm")
    try:
        while cur.getOffset() < end_exclusive_offset:
            instr = listing.getInstructionAt(cur)
            if instr is None:
                disasm.disassemble(cur, None)
                instr = listing.getInstructionAt(cur)

            if instr is not None and instr.getMaxAddress().next().getOffset() > end_exclusive_offset:
                # Decoded "successfully" but runs past the function's own declared end -
                # almost certainly a misaligned/garbage decode (the corpus's byte size is
                # ground truth here, from the same analysis that produced the decompiled
                # .c). Clear it so it cannot poison later calls, and treat as a failure.
                listing.clearCodeUnits(cur, instr.getMaxAddress(), False)
                instr = None

            if instr is None:
                if undecoded_start is None:
                    undecoded_start = cur.getOffset()
                cur = cur.add(2)  # resync on the next 2-byte boundary; never retry mid-span
                continue

            if undecoded_start is not None:
                undecoded_ranges.append([hex(undecoded_start), hex(cur.getOffset())])
                undecoded_start = None

            instructions.append({
                "addr": hex(cur.getOffset()),
                "mnemonic": str(instr.getMnemonicString()),
                "text": str(instr),
                "length": instr.getLength(),
            })
            cur = instr.getMaxAddress().next()
    finally:
        program.endTransaction(tid, True)

    if undecoded_start is not None:
        undecoded_ranges.append([hex(undecoded_start), hex(end_exclusive_offset)])

    return instructions, undecoded_ranges


def is_flash_addr(addr_hex: str) -> bool:
    return int(addr_hex, 16) >= 0x03000000


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--limit", type=int, default=None,
                     help="Only process the first N flash-range functions (for a quick smoke test).")
    ap.add_argument("--write-files", action="store_true",
                     help="Also write one .disasm.txt file per function under data/disasm/.")
    args = ap.parse_args()

    functions = json.loads(FUNCTIONS_JSON.read_text())["functions"]
    flash_fns = [f for f in functions if is_flash_addr(f["addr_hex"])]
    flash_fns.sort(key=lambda f: f["addr"])
    if args.limit:
        flash_fns = flash_fns[: args.limit]

    print(f"disassembling {len(flash_fns)} flash-range functions "
          f"(skipping {len(functions) - len(flash_fns)} IRAM-range functions - not yet in scope)")

    if args.write_files:
        OUT_DIR.mkdir(parents=True, exist_ok=True)

    with open_program(analyze=False) as flat_api:
        program = flat_api.getCurrentProgram()
        assert program.getImageBase().getOffset() == FLASH_BASE

        results = []
        for i, fn in enumerate(flash_fns):
            addr_off = int(fn["addr"], 16)
            size = fn["size"]
            instructions, undecoded = disassemble_range(flat_api, program, addr_off, size)

            # NOT auto-classifying short tail gaps as "harmless padding": a 2-byte gap at a
            # function's own end is indistinguishable by size alone from a genuine
            # halt_baddata() bad-instruction stop that happens to land right at the tail
            # (confirmed: strlen_unaligned_path and strlen_ck803s are exactly this case - a
            # real, decompiler-flagged bad instruction in their last 2 bytes, which an
            # earlier version of this script silently reclassified as "padding" and dropped).
            # Every undecoded range is reported as-is; a human or downstream tool can look at
            # whether the next function's first instruction starts immediately after to judge
            # alignment filler from context, rather than this script guessing wrong.
            row = {
                "addr": fn["addr_hex"],
                "name": fn["name"],
                "size": size,
                "instruction_count": len(instructions),
                "has_undecoded_bytes": len(undecoded) > 0,
                "undecoded_ranges": undecoded,
                "instructions": instructions,
            }
            results.append(row)

            if args.write_files:
                lines = [f"; {fn['name']} @ {fn['addr_hex']} ({size} bytes, "
                         f"{len(instructions)} instructions)"]
                if row["has_undecoded_bytes"]:
                    lines.append(f"; UNDECODED span(s) - inline literal pool or bad-"
                                 f"instruction stop: {row['undecoded_ranges']}")
                for ins in instructions:
                    lines.append(f"{ins['addr']}  {ins['text']}")
                out_path = OUT_DIR / f"{fn['name']}_{fn['addr']}.disasm.txt"
                out_path.write_text("\n".join(lines) + "\n")

            if (i + 1) % 200 == 0:
                print(f"  {i + 1}/{len(flash_fns)}")

    with open(OUT_JSONL, "w") as f:
        for row in results:
            f.write(json.dumps(row) + "\n")

    undecoded_count = sum(1 for r in results if r["has_undecoded_bytes"])
    print(f"wrote {len(results)} rows to {OUT_JSONL}")
    print(f"{undecoded_count} functions contain at least one undecoded span - an inline "
          f"literal pool, a jump table, or a genuine bad-instruction stop (cross-check "
          f"against halt_baddata()/'bad instruction' warnings in the corpus's .c files; this "
          f"script does not try to distinguish those cases by guessing, since a short gap at "
          f"a function's own tail can be either real bad data or, less often, alignment "
          f"filler before the next function - see disassemble_range's docstring)")


if __name__ == "__main__":
    main()

"""Builds (or reopens) the standalone Ghidra project this toolset analyzes.

dm32uv-re/tools does its own Ghidra analysis from data/firmware/*.bin, independent of the
private research repo's Ghidra project.

LOAD BASE, verified empirically (do not trust PROVENANCE.md's "Assumed load base" field for
this - it names the address where CODE starts, not the file's base address):

  - DM32.00.01.048.bin is a flat image with a reserved 0x1000-byte header (the DH_FLAG magic
    "thd\\x0c" at file offset 0, the encoded load address 0x03001000 at offset 4, then zero
    padding). Real code starts at file offset 0x1000. So the file's BASE address is
    0x03000000, making file offset 0x1000 line up with 0x03001000 - confirmed by
    disassembling a known corpus function (sram_state_word_bit_clear @ 0x03001c50, which maps
    to file offset 0x1c50 under base 0x03000000 and is dense non-zero instruction bytes there,
    all-zero under the wrong base 0x03001000).
  - IRAM_dm32.00.01.048.bin is the IRAM image derived from the program flash exactly as the boot
    stub builds it (derive_iram.py): raw, no header, loads directly at 0x00010000. It holds code
    and initialised data up to 0x0002f098 and zeros above (bss/stack/heap at runtime).

Fragment-aware: callers must use Function.getBody().getAddressRanges(), never
entry + getNumAddresses(), when walking a function's bytes - a contiguous read of a
fragmented body silently includes inter-fragment literal pools as if they were code
(the same mistake documented in the main project as a false "truncated functions" finding).
"""
from __future__ import annotations

import pathlib

THIS_DIR = pathlib.Path(__file__).resolve().parent
TOOLS_DIR = THIS_DIR.parent.parent
REPO_ROOT = TOOLS_DIR.parent
FIRMWARE_DIR = REPO_ROOT / "data" / "firmware"

FLASH_BIN = FIRMWARE_DIR / "DM32.00.01.048.bin"
FLASH_BASE = 0x03000000

IRAM_BIN = FIRMWARE_DIR / "IRAM_dm32.00.01.048.bin"
IRAM_BASE = 0x00010000

LANGUAGE_ID = "CSKY_V2:LE:32:default"

PROJECT_DIR = TOOLS_DIR / "ghidra_project"  # no leading dot: Ghidra's ProjectLocator rejects it
PROJECT_NAME = "dm32uv_re_standalone"
PROGRAM_NAME = "dm32_flash"


def open_program(analyze: bool = False, verbose: bool = False):
    """Returns a FlatProgramAPI over the flash image, rebased to FLASH_BASE.

    Context-manager style, matching pyghidra.open_program: `with open_program() as flat_api:`.
    Reuses an existing project/program on disk if one is already there (including any prior
    analysis) instead of re-importing. Delete PROJECT_DIR to force a clean rebuild, e.g. after
    a Ghidra or C-SKY extension upgrade.

    NOTE on the rebase: BinaryLoader's "Base Address" load option (addLoaderArg /
    ProgramLoader.Builder) was tried and silently had no effect in this Ghidra/pyghidra
    version - the loaded program always lands at 0x0. The reliable path is: import at the
    default base, call Program.setImageBase() inside a transaction, and do this BEFORE
    running analysis (afterwards leaves stale analysis keyed to the old addresses).
    """
    if not FLASH_BIN.exists():
        raise FileNotFoundError(f"missing {FLASH_BIN} - see data/firmware/README.md")

    import pyghidra

    pyghidra.start(verbose=verbose)

    PROJECT_DIR.parent.mkdir(parents=True, exist_ok=True)

    return _RebasedProgram(
        binary=FLASH_BIN,
        base=FLASH_BASE,
        project_location=PROJECT_DIR,
        project_name=PROJECT_NAME,
        analyze=analyze,
    )


class _RebasedProgram:
    """Context manager: open_program (at default base), rebase, optionally analyze."""

    def __init__(self, binary, base, project_location, project_name, analyze):
        self._binary = binary
        self._base = base
        self._project_location = project_location
        self._project_name = project_name
        self._analyze_after_rebase = analyze
        self._cm = None
        self.flat_api = None

    def __enter__(self):
        import pyghidra

        self._cm = pyghidra.open_program(
            str(self._binary),
            project_location=str(self._project_location),
            project_name=self._project_name,
            analyze=False,  # always rebase before analysis; see module docstring
            language=LANGUAGE_ID,
        )
        self.flat_api = self._cm.__enter__()
        program = self.flat_api.getCurrentProgram()

        af = program.getAddressFactory()
        new_base = af.getDefaultAddressSpace().getAddress(self._base)
        if program.getImageBase().getOffset() != self._base:
            tid = program.startTransaction("rebase")
            try:
                program.setImageBase(new_base, True)
            finally:
                program.endTransaction(tid, True)

        if self._analyze_after_rebase:
            from ghidra.program.util import GhidraProgramUtilities

            self.flat_api.analyzeAll(program)
            GhidraProgramUtilities.markProgramAnalyzed(program)
            program.save("post-rebase analysis", None)

        return self.flat_api

    def __exit__(self, *exc):
        return self._cm.__exit__(*exc)

"""dm32-patch-tools: hand-maintained patch-building tooling for the DM-32UV stock firmware.

Each module in this package is a standalone script (run it as
`python3 tools/src/dm32_patch_tools/<script>.py --help`); they import each other by bare name, so
the directory is put on sys.path rather than imported as a package. The catalogue of scripts, what
each needs (plain python3, the cross-toolchain, QEMU, Ghidra) and the patch lifecycle they serve
is in tools/README.md.

Nothing here writes to a radio: every tool stops at producing files (see tools/README.md "Hard
rules").
"""


def main() -> None:
    print("dm32-patch-tools: see tools/README.md for the available scripts "
          "(build_manifest_patch.py, lookup.py, ...)")

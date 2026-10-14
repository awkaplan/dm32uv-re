# Provenance

**The analysis in this repository (`include/`, `src/`, `meta/`, `site/`, `build/`) is
generated output. Do not edit it by hand** &mdash; the next regeneration will overwrite it.

| | |
|---|---|
| Firmware build | `DM32.00.01.048` |
| Source binary | `DM32.00.01.048.bin` |
| SHA-256 | `0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147` |
| Address map | file base `0x03000000`; code starts at `0x03001000` (the first `0x1000` bytes are a header holding the boot magic) |
| Architecture | C-SKY CK803S (little-endian, 32-bit) |
| Generated (UTC) | 2026-10-19 21:06:34Z |

The SHA-256 above is of the program-flash read this corpus was generated from, taken from a
DM-32UV running build DM32.00.01.048 (there is no vendor download of this build), before its one
per-radio 4 KB sector (`0x0300b000`) was blanked. The image shipped in `data/firmware/` is the
same read with that sector set to `0xFF`; its own hash is in the `.sha256` file beside it.
Every address, size and name in this repository is a property of the firmware and is identical on
any DM-32UV running this build. No per-unit data &mdash; calibration, codeplug contents,
identifiers &mdash; appears anywhere in this tree.

## What this corpus is

The decompiled corpus (`src/`, `include/`, `meta/`, `site/`) is a decompiler reconstruction
of Baofeng firmware DM32.00.01.048, produced for interoperability research. It is not Baofeng's source
code. Names, types and structure are inferred and may be wrong; every function carries a
confidence level (CONFIRMED, STRUCTURAL or RAW) stating how far it has been verified. This project
is not affiliated with, endorsed by, or supported by Baofeng.

## Corpus syntax-check

2883 of 3561 decompiled sources (81.0%) are syntax-clean against the generated headers.

This is a tracked quality metric, not a build gate. The dominant remaining failure is an analysis
gap rather than a tooling defect: many globals are dereferenced as pointers by the decompiled code
while still carrying a scalar type. Recovering those types is the single highest-leverage way to
raise this number, and it improves the decompiled C itself.

## Decompiler caveats

Decompiled C is a reconstruction, not source. Known defects were found and corrected in the
decompiler used for this architecture during this work:

* An AND-NOT instruction was mis-modelled as NAND, producing nonsensical arithmetic. Fixed; this
  corpus has been regenerated since.
* A move-complemented-condition instruction renders as a misleading bitwise NOT of a promoted
  boolean. The underlying semantics are correct but the C output is not &mdash; verify any
  `return ~((...) != 0)`-shaped output against disassembly before trusting it.
* A load-high-immediate instruction was mis-modelled as always loading zero, which rendered
  every peripheral-register access built from it as an access to a tiny absolute address
  (`uRam00000000`). Fixed; this corpus has been regenerated since, and no such access remains.

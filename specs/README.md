# specs/: machine-readable chip and format descriptions

Hand-maintained (like `tools/` and `docs/`). Each file here is the source of truth for one chip's
registers or one binary format, written in a standard language so existing tools can read it:

| Directory | Language | What |
|---|---|---|
| `rdl/` | [SystemRDL 2.0](https://www.accellera.org/downloads/standards/systemrdl) | Register maps of the chips around the SoC (one `.rdl` per chip). The SoC's own map is the CMSIS-SVD in `../data/registers/`. |
| `ksy/` | [Kaitai Struct](https://kaitai.io) 0.11 | Binary formats and wire protocols. |
| `dts/` | [Devicetree](https://www.devicetree.org) source | The board: which chip sits on which bus and pins. |
| `include/` | C | Hand-written headers for chips or protocols that patches don't call into (e.g. `hr_v3000.h`: a related vocoder this radio does **not** have). Patch-facing headers live in `../tools/include/`. |
| `generated/` | (generated) | Outputs of the generators below. Committed so they work without the toolchain; never edit by hand. |

## Toolchain

```sh
cd tools && uv sync --group specs     # systemrdl-compiler, PeakRDL, kaitaistruct (pinned in pyproject.toml)
tools/fetch_ksc.sh                    # Kaitai compiler 0.11 (Java), pinned by sha256, into tools/.ksc/
```

Generators live in `tools/src/dm32_patch_tools/` (`gen_rdl.py`, `gen_ksy.py`); each has `--check`
(exit 1 if `generated/` is stale), which the test suite runs.

## SystemRDL conventions

- One `.rdl` per chip; the top `addrmap` is named after the file stem.
- **Command opcodes** (SPI flash and similar): a sub-addrmap named `cmd` with one 8-bit
  pseudo-register per opcode at offset = opcode, holding a single constant field `opcode` plus the
  evidence properties (a SystemRDL `enum` cannot carry evidence per member). `gen_rdl.py` enforces
  this shape and emits the block as the chip's opcode enum. Mark erase/program/status-write
  commands `destructive = true`.
- **Register numbers on the wire**: `wire_addr` if set, else `address_offset / (regwidth / 8)`
  within the parent block. For opcode-selected registers (flash status registers), `wire_addr` is
  the opcode that reads it and `wr_cmd` lists the opcodes that write it.
- **Page citations** in `ds_ref` are PDF page indices (what a PDF viewer shows), not the printed
  page number, and name the section, e.g. "W25Q128JV Rev F, 7.1.1 (BUSY), PDF p.14".
- `gen_rdl.py` writes `generated/include/<chip>.h` (peakrdl-cheader field macros),
  `generated/include/<chip>_regnum.h` (register-number and opcode enums),
  `generated/json/<chip>.json` (evidence index) and HTML to `../out/specs-html/<chip>/`
  (not committed).

## Kaitai conventions

- `meta.id` equals the file stem. Confidence is inherited: an entry's own `-dm32-confidence`, else
  its enclosing type's, else `meta`'s; every value must be one of the four allowed.
- `gen_ksy.py` emits Python only, with `--read-write` (Kaitai 0.11 serializes Python and Java;
  generate Java on demand for a Ghidra loader). Each output records the sha256 of its source, so
  `--check` works without Java; with the compiler it recompiles and compares byte for byte.
- **Test fixtures** are declared in a sidecar `ksy/<name>.fixtures.json`:

  ```json
  {"root_type": "<optional ksy id or a::b nested type>",
   "generic": [{"path": "specs/ksy/fixtures/x.bin", "offset": 0, "length": 64,
                "root_type": "<optional override>", "note": "...",
                "expect": {"frames[2].body.addr": "0x1fff"}}],
   "private_globs": ["<glob under $DM32_PRIVATE_DUMPS>",
                     {"glob": "...", "root_type": "...", "stream": "host|radio"}]}
  ```

  `generic` fixtures are committed, generic bytes only (stock firmware, or frames built from a
  spec); `expect` checks decoded meaning, not just bytes (enums by name, ints as hex strings).
  `stream` marks a serial-monitor text log and selects one direction. Fixture files built by code
  are regenerated with `gen_ksy.py --write-fixtures`.

## Evidence rules (all files)

Same standard as the rest of the repo: nothing is invented.

- **SystemRDL**: `include "dm32_udp.rdl"`. Every `reg` and `field` has `confidence`
  (`CONFIRMED` / `DATASHEET` / `STRUCTURAL` / `INFERRED`) and at least one of `ds_ref` (datasheet
  document, section, PDF page), `fw_writes` / `fw_reads` (stock DM32.00.01.048 addresses and the
  values written), `hw_reads` (a real radio or the QEMU model; say which). A datasheet that
  disagrees with the stock firmware or the hardware is recorded, not silently corrected: put the
  datasheet's claim in `ds_value` and the observed one in `reset` / `hw_reads`, and say which
  wins in `desc`.
- **Kaitai**: every `seq` / `instances` entry has a `doc`; sources go in `doc-ref`. Confidence
  goes in the custom key `-dm32-confidence` (same four values). Unproven meanings say so in `doc`.
- **Devicetree**: a comment on every node and pin citing its source.
- Cite external specs by name and section (e.g. "DVSI AMBE-3000 manual, 6.2"); do not copy their
  text. Credit any open-source description you follow (with its license) in a comment.

## Data rules

- **No per-unit data in this repo, ever** (see `../README.md` "Scope"). Test fixtures here are
  generic stock-firmware bytes only. A format that exists only on a radio (codeplug, calibration
  page, data-chip pages) is tested against your own dumps by passing their directory in
  `DM32_PRIVATE_DUMPS`; those tests skip when it is unset, and nothing they read is written into
  the repo, a test log or an error message.
- **Calibration is restore-only.** The calibration-page description is for parsing and comparing
  dumps. No tool here may build a calibration page from a model; the only legitimate write is a
  byte-exact copy of the same radio's own verified backup.
- **Round-trip before write.** A Kaitai description may be used by anything that writes only after
  a test proves it parses every available dump and serializes it back byte-for-byte identical.
- Nothing here writes to a radio. Flashing stays a manual human step outside this repo.

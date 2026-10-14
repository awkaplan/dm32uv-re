# dm32uv-re/tools

Patch-building tooling for the DM-32UV stock firmware (DM32.00.01.048): look things up in the
corpus, place and link new code, splice hooks into flash sectors, verify a patch under the
`-M dm32` QEMU board model, and stage the changed sectors for a human to flash.

**This directory is hand-maintained, not generated.** `src/`, `include/`, `meta/functions.json`,
`site/` and `build/` at the repo root are regenerated wholesale by the upstream analysis pipeline
(see `../PROVENANCE.md`) and must never be hand-edited. Everything under `tools/` is written here
directly and survives regeneration. It needs nothing outside this repository: the firmware images
are in `../data/firmware/` and the corpus metadata is in `../meta/`.

Comments that refer to "the main repo" or "the main project" mean the private research
repository this one is exported from. It is not published; those references record where a fact
came from and are not steps you need to follow.

Read before writing a patch: `../CLAUDE.md` (standing gotchas), `../docs/patch-patterns.md`
(hook techniques), `../docs/menu-system.md`, `../docs/keypad-input.md`,
`../docs/rtos-and-memory.md`, `../docs/qemu-workflow.md`, and `include/dm32_patch_api.h` (every
stock primitive a patch can call, with addresses and calling conventions).

## Quick start (Docker)

The Docker image supplies everything the heavier tools need: Ghidra 12.1.3 with the C-SKY Sleigh
extension, `qemu-system-cskyv2` with the DM-32 board model, the `csky-abiv2-elf-*` CK803S
cross-toolchain, and a capstone build with C-SKY support. Full details, including what is bind-mounted and the known gaps, are in
[`../docker/README.md`](../docker/README.md).

```sh
git submodule update --init --recursive   # vendor/ trees the image builds from
cd docker
docker compose build                      # slow the first time; cached afterwards
docker compose run --rm dm32uv-re         # shell at /work/tools with this Makefile
make help                                 # list every target
```

Many tools need no Docker at all. Most scripts below run with plain `python3` (3.10+, stdlib only)
from a bare checkout. The table says which ones need more.

## Local Ghidra setup (secondary path)

Use this only if you want to run `export_disasm.py` (whole-corpus disassembly regen) outside
Docker. It needs [`uv`](https://docs.astral.sh/uv/) and a local Ghidra 12.1.x with the C-SKY
Sleigh extension (`../vendor/ghidra_csky`) installed into it.

```sh
./setup.sh    # finds Ghidra, points pyproject.toml at its bundled pyghidra wheel, runs uv sync
uv run python3 src/dm32_patch_tools/export_disasm.py --limit 50   # quick smoke test
```

Why not `pip install pyghidra`: pyghidra is not a standalone library. It loads the installed
Ghidra's own Java classes through jpype, so it must be the exact wheel that Ghidra version ships
(`<ghidra>/Ghidra/Features/PyGhidra/pypkg/dist/*.whl`), including whatever Sleigh/processor fixes
are installed into that instance. A PyPI release could be a different Ghidra version with
different pcode behaviour for CK803S. `setup.sh` rewrites `pyproject.toml`'s `[tool.uv.sources]`
to the local wheel and writes `.env.ghidra`; re-run it after upgrading Ghidra. Set
`GHIDRA_INSTALL_DIR` if your Ghidra is not where `setup.sh` looks (it tries, in order:
`$GHIDRA_INSTALL_DIR`, a `ghidraRun` on PATH, Homebrew, `/opt/ghidra*`, `/usr/local/ghidra*`,
`~/ghidra*`) and fails with a clear error otherwise. The committed `pyproject.toml` carries no
`[tool.uv.sources]` entry (it would be an absolute path on one machine); `setup.sh` appends the
local one, so do not commit that edit. `uv.lock` embeds the same path, so it is **not tracked**
(gitignored); `setup.sh`'s `uv sync` regenerates it, as it does `.env.ghidra`. The Docker image bakes its own Linux-pathed `pyproject.toml` and `.venv`, so the
host's copies are never mounted into it.

## Scripts

All live in `src/dm32_patch_tools/`. Run them from `tools/` as
`python3 src/dm32_patch_tools/<script>.py --help`. "python3" means stdlib-only and runnable on a
bare host.

| Script | What it does | Needs |
|---|---|---|
| `lookup.py` | Answers "what is X?" for an address, a name or a `--search` substring: containing function, sector, sensitivity, patch risk, patch sites, callers/callees, disassembly, `--c` decompiled source, `--json`. | python3 |
| `cs_disasm.py` | Fast spot-check disassembly of one function or address (`--addr`, `--bin/--base` for IRAM), or a mnemonic `--sweep`. | capstone with C-SKY support (built into the Docker image; host build steps in its docstring), else falls back to `csky-abiv2-elf-objdump` |
| `extract_gb2312_strings.py` | Finds every GB2312/ASCII string the stock renderer can draw, with its flash address; `--near ADDR` to search around a dispatcher. | python3 |
| `placement_scan.py` | Static "is this RAM/flash range safe for patch data?" check: literal references into the range, nearest referenced base, non-zero bytes in the given dumps. Verdict `clear` or `suspect`. `--extra-allocations FILE` (repeatable) adds an out-of-tree claims file to the claimed-region report. | python3 |
| `gen_link_artifacts.py` | Generates `link/dm32_stock_symbols.ld` (stock functions by name) and `link/dm32_patch_memory.ld` (free regions from `../data/allocations.json`). `--check` exits 1 if they are stale. | python3 |
| `gen_compile_commands.py` | Writes `out/compile_commands.json` for clangd (patch sources plus, unless `--no-corpus`, the decompiled corpus) and `out/compile_commands.csky.json` with the real `csky-abiv2-elf-gcc` command lines. clang has no C-SKY target, so files are parsed as `thumbv7m-none-eabi` with the C-SKY predefines; `alignof(long long)` differs (8 vs 4), so treat 64-bit struct layouts under clangd as advisory. The repo-root `.clangd` points clangd at `out/`. | python3 (clangd to use it) |
| `make_stock_elf.py` | Builds `../out/dm32_stock.elf`: stock flash and IRAM as one symbolised ELF for objdump/nm/gdb, or `ld -R`. | python3 |
| `derive_iram.py` | Rebuilds the IRAM image from the program-flash image exactly as the boot stub does (produces `../data/firmware/IRAM_dm32.00.01.048.bin`). | python3 |
| `build_patch.py` | Assembles one handler (`.S`/`.c`), places it in erased space in one sector, encodes a `br`/`bsr` hook after checking the expected stock bytes, and writes the modded sector. Refuses the per-unit sector. | cross-toolchain (Docker) |
| `build_manifest_patch.py` | Builds a multi-site patch from a JSON manifest (blobs, data items, splices with expected stock bytes, `@stock:name` references) and writes the full image + per-sector files to `out/patches/<name>/`. Refuses the per-unit sector, other patches' claims and unexpected changes. `tools/examples/snake/snake.patch.json` reproduces Snake byte for byte. `--extra-allocations FILE` (repeatable) merges additional claim files (same schema as `data/allocations.json`) before claim resolution and overlap checks, so a patch living in another repo can own claims of its own; duplicate names and overlaps are hard errors. See "Building a patch that lives outside this repo". | cross-toolchain (Docker) for blobs; python3 for data/splice-only manifests |
| `new_patch.py` | `new_patch.py NAME` scaffolds a patch (C handler, linker script INCLUDE-ing `tools/link/`, manifest with a guarded TODO hook) from `tools/templates/new_patch/`. | python3 |
| `compose_qemu_image.py` | Builds one emulator-bootable 1 MB image from the base image plus patched sectors or a full patched image, and applies the three QEMU-only boot patches unless `--no-qemu-only-patches`. `--iram-out` also writes `iram.bin` and `sram.bin`. | python3 |
| `qemu_run.py` | Launches one `-M dm32` run with the board model's environment variables and a `--keyseq` key script, babysits it until `--until-step`, a stall or a timeout, and prints a summary. Exposes `KEYS`/`keyseq()` for other scripts. | QEMU (Docker) |
| `render_frames.py` | Renders a run's `gram.raw.NNN` GRAM captures to PNG: `--single N`, `--frames`, or `--last N` montage. | Pillow (`pip install pillow`) |
| `gdb_rsp.py` | Minimal GDB remote-protocol client for the emulator's `-s` stub: `regs`, `mem`, `watch`, `crashwait`. | a running QEMU with `--gdb` |
| `pc_histogram.py` | Turns a `-d exec,nochain` trace into windowed PC histograms (`--trace/--out`), then maps one to named functions (`--map`). | python3 (trace comes from QEMU) |
| `qemu_boot_diff.py` | Library behind `verify_patch.py`'s dynamic half: boots stock and patched images, drives one key script through both, compares settled screens and executed code. No CLI of its own. | QEMU (Docker) |
| `verify_patch.py` | Verifies one modded sector: corpus pre-flight (functions touched, patch risk, sensitive sectors, patch-site collisions), then the QEMU boot comparison when `qemu-system-cskyv2` is on PATH. | python3; QEMU for the dynamic half |
| `stage_sectors.py` | Diffs a full patched image against stock and writes one file per changed sector plus `MANIFEST.sha256` and a flash-command template. Refuses sensitive and QEMU-only sectors. Never flashes. | python3 |
| `bps_patch.py` | `create` / `apply` / `info` for BPS patches: a shareable diff of a patched image (changed bytes plus source/target CRC32s) instead of the whole vendor firmware. Refuses the per-unit sector and the QEMU-only sites, with no override. | python3 |
| `scrub_unit_sector.py` | Blanks the per-unit sector (`0x0300b000`-`0x0300bfff`) to `0xFF` in an image, in place. Run it on any program-flash image read from a radio before sharing it. | python3 |
| `check_doc_claims.py` | Checks address and size claims in the docs (including this README) against the shipped images. Exits 1 on any FAIL. | python3 |
| `export_disasm.py` | Regenerates `../meta/disasm.jsonl`: real CK803S disassembly for each corpus function, with undecoded spans flagged. Slow; `--limit N` for a smoke test. | Ghidra (Docker, or the local setup above) |
| `export_xrefs.py` | Regenerates `../meta/xrefs.json` (call graph) from `disasm.jsonl`, classifying every call target. | python3 |
| `export_sectors.py` | Regenerates `../meta/sectors.json` (function to 4 KB sector and back, with `known_sensitive` flags). | python3 |
| `export_patch_sites.py` | Regenerates `../meta/patch_sites.json` from a hand-curated catalogue of known patch sites, re-checking each address against the corpus. | python3 |
| `export_patch_risk.py` | Regenerates `../meta/patch_risk.json` (`low`/`medium`/`high`/`unknown` per flash function). Needs the three exports above. | python3 |
| `ghidra_project.py` | Library: creates or reopens the Ghidra project in `tools/ghidra_project/` (gitignored) at load base `0x03000000`. No CLI. | Ghidra |
| `dm32_cps_common.py` | Library: read-only CPS serial protocol (handshake, V-frames, `0x52` reads) used by `dm32_ramdump.py`. No CLI. | `pyserial` |
| `crypto_kat.py` | Known-answer test of the STOCK firmware's own DMR-privacy crypto (AES key schedule/block, MI-to-IV LFSR, voice keystream, the TX setup/apply path), executed by the real CK803S code under `-M dm32` over the gdb stub and compared with FIPS-197 / OpenSSL. Verifies stock behaviour, not a patch; see `../docs/encryption.md`. | QEMU + `openssl` (Docker) |
| `rng_seed_probe.py` | Boots stock under `-M dm32` and samples the libc `rand()` state once a second, reporting how many LCG steps from the compiled-in seed: confirms stock never seeds the generator that draws the DMR-privacy MI. Verifies stock behaviour. | QEMU (Docker) |
| `gen_ksy.py` | Lints `../specs/ksy/*.ksy` (Kaitai Struct) against the evidence rules and compiles them to `../specs/generated/python/`; `--check` fails on a stale or rule-breaking spec, `--lint` needs no compiler. | `uv sync --group specs`; Kaitai compiler (`fetch_ksc.sh`) except for `--lint` |
| `gen_rdl.py` | Generates C headers, a JSON evidence index and HTML from `../specs/rdl/*.rdl` (SystemRDL chip descriptions); `--check` fails on stale output or a register without evidence. | `uv sync --group specs` |
| `fetch_ksc.sh` | Downloads the Kaitai Struct compiler 0.11 into `tools/.ksc/` (gitignored), refusing it unless its sha256 matches the pin; prints the binary path. | `curl`, `unzip`, a JRE (>= 8) |
| `setup.sh` | One-time local Ghidra/pyghidra setup (see "Local Ghidra setup"): finds Ghidra, injects its bundled pyghidra wheel path into `pyproject.toml`, writes `.env.ghidra`, runs `uv sync`, which regenerates `uv.lock`. | `uv`, a local Ghidra 12.1.x |
| `dm32_ramdump.py` | Dumps live RAM from a running radio over the programming cable. Works only if a live-RAM-read patch is already flashed; see `../docs/live-ram-capture.md`. Read-only. | `pyserial`, a radio |

The `export_*` scripts write into `../meta/`. They are run in dependency order by
`make export-all` (disasm, then xrefs, sectors, patch-sites, patch-risk). You only need them
after changing the corpus or the patch-site catalogue; the committed `meta/` files are current.

## Headers (`include/`)

Include with `-I tools/include`; `build_manifest_patch.py` adds it automatically.

| Header | What it is for |
|---|---|
| `dm32_patch_api.h` | The primary API: every stock primitive a patch can call (display, keypad, RTOS, menu cells, scratch RAM) with addresses, C-SKY ABIv2 conventions and confidence tags. Read first. |
| `dm32_ui.h` | The older, smaller subset of the above, kept for the overlay example (`examples/build_overlay_image.py`). |
| `hr_c7000_regs.h` | The few HR_C7000 peripheral registers patches touch (pin mux IO_DIPLEX0/1/2, GPIO, PIC, TIMER, WDG, ADC) plus the DM-32 traps; the full map is `../data/registers/`. |
| `st7789v.h` | Vendor (non-MIPI) commands of the LCD controller (an ST7789V or compatible, structural identification). |
| `mipi_dcs.h` | Standard MIPI DCS opcodes the panel understands, for patch code and for typing the stock LCD command writer in Ghidra. |
| `rda5807m_shadow.h` | The stock FM-tuner driver's RAM register shadow, related cells, init table and entry points. |

## Makefile targets

Run from `tools/` (`make help` prints the Makefile header). Variables are documented there.

| Target | What it does |
|---|---|
| `sectors`, `xrefs`, `patch-sites` | Regenerate `../meta/sectors.json`, `xrefs.json`, `patch_sites.json` (pure python). |
| `patch-risk` | Regenerate `../meta/patch_risk.json`; depends on the three above. |
| `disasm` | Regenerate `../meta/disasm.jsonl` via Ghidra (`LIMIT=50` for a smoke test). |
| `export-all` | `disasm`, then the four exports above, in dependency order. |
| `clean` | Delete the regenerated `../meta/{disasm.jsonl,xrefs,sectors,patch_sites,patch_risk}` (re-run `export-all`). |
| `lookup Q=...` | `lookup.py` for an address or name (`ARGS="--search"`, `--c`, `--json`). |
| `build-patch` | `build_patch.py` single hook in one sector (`HANDLER`, `STOCK_SECTOR`, `SECTOR_BASE`, `HOOK_ADDR`, `HOOK_BYTES`). |
| `verify-patch` | `verify_patch.py` for `SECTOR` at `OFFSET`. |
| `build-manifest MANIFEST=... [OUT= COMPARE= ARGS=...]` | `build_manifest_patch.py`; pass `ARGS="--extra-allocations f.json --require-claims"` for an out-of-tree patch. |
| `snake-manifest` | Rebuild Snake from its manifest and compare byte for byte with the committed image. |
| `new-patch NAME=...` | `new_patch.py` scaffold (`ARGS="--dest <dir>"` to put it elsewhere). |
| `bps-create` / `bps-apply` / `bps-info` | `bps_patch.py create` / `apply` / `info` (`BPS_TARGET`, `BPS_OUT`, `BPS_PATCH`, `BPS_SOURCE`, `BPS_NAME`). |
| `compile-commands` | `gen_compile_commands.py` (`ARGS=--no-corpus`). |
| `link-artifacts` | Regenerate `link/dm32_stock_symbols.ld`, `link/dm32_patch_memory.ld` and `../out/dm32_stock.elf`. |
| `link-check` | Exit 1 if the committed `link/*.ld` are stale. |
| `link-example` | Compile and link `link/example/hello_patch.c` into `../out/link-example/` (cross-toolchain). |
| `specs` / `specs-check` | `gen_rdl.py` + `gen_ksy.py` generation / staleness check (`uv sync --group specs`). |
| `test` | Host test suite (`../tests/run_tests.py --suite host`, stdlib only). |
| `test-all` | Host plus image suite (Snake rebuilds, QEMU fingerprint; ~2 min, via `docker run $(TEST_IMAGE)`). |

## Building a patch that lives outside this repo

A patch can live in its own repository and still be built
and verified with this one. Nothing in the builder depends on the manifest being under `tools/`:
it resolves `data/`, `tools/link/` and `tools/include/` relative to this repo and puts the
manifest's own directory on the linker search path (`-L`).

1. Keep the patch's claims in its own allocation file, same schema as `../data/allocations.json`
   (`{"allocations": [{"name", "space", "start", "end_exclusive", "owner", "source"}]}`, optional
   `"forbidden"`; flash claims are whole 4 KiB sectors inside the flash window, SRAM claims inside
   the SRAM window). List the claim names in the manifest's `"allocations"`.
2. Write the linker script to `INCLUDE dm32_stock_symbols.ld` and `INCLUDE
   dm32_patch_own_memory.ld`, which the builder generates per build from the manifest's owned
   claims (`PATCH_OWN_FLASH` / `PATCH_OWN_SRAM`). Do not use `dm32_patch_memory.ld`: it is
   generated from `data/allocations.json` only and knows nothing about the extra file.
3. Build (inside the toolchain image, or anywhere `csky-abiv2-elf-*` is on PATH):

   ```sh
   python3 tools/src/dm32_patch_tools/build_manifest_patch.py /path/to/patch.patch.json \
       --extra-allocations /path/to/allocations.json --require-claims --out /tmp/patch_out
   ```

   Several `--extra-allocations` files may be given. Every claim from every file is checked
   against every other (duplicate names, overlapping ranges, windows, forbidden ranges), so one
   patch cannot take another's space even across repositories. `--compare ref.bin` and the rest
   of the flow (`compose_qemu_image.py`, `verify_patch.py`, `stage_sectors.py`) work unchanged.
4. Use `placement_scan.py --extra-allocations ...` when choosing a new SRAM or flash range.

`make build-manifest MANIFEST=... ARGS="--extra-allocations ... --require-claims"` does the same
from `tools/`.

## The patch lifecycle

### 1. Find a target

```sh
make lookup Q=0x03012e14                     # what is at this address?
make lookup Q=keypad_scan_and_map_pressed_key ARGS=--c
make lookup Q=keypad ARGS=--search
python3 src/dm32_patch_tools/extract_gb2312_strings.py \
    ../data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin --near 0x030b7db8
```

Use `progmem_stock_DP570UV_20260926_FULL.bin` (the full 1 MB image), not `DM32.00.01.048.bin`,
whenever the question is "what is actually erased". Apply the gotchas in `../CLAUDE.md` before
trusting any table address you find: a named address is often the literal-pool slot holding the
table base, not the table itself.

### 2. Claim space and link against stock by name

New code and state go only into space listed in `../data/allocations.json`, which records the
patch windows, the forbidden ranges and every existing claim. To claim space:

1. Add an allocation entry (flash claims are whole 4 KiB sectors).
2. `make link-artifacts` regenerates `link/dm32_patch_memory.ld` and `link/dm32_stock_symbols.ld`
   (and `../out/dm32_stock.elf`). `make link-check` fails if the committed `.ld` files are stale.
3. Write the patch as ordinary C. Declare a stock function's prototype and call it by name; the
   linker resolves it from `dm32_stock_symbols.ld`. Place sections with `> PATCH_FLASH` /
   `> PATCH_SRAM` (or a specific `PATCH_FLASH_<n>`). An oversized section or one that overlaps a
   reserved range fails the link instead of silently landing on stock code.

`link/example/hello_patch.c` + `hello_patch.ld` is the template (`make link-example`, needs the
cross-toolchain). It only demonstrates linking: nothing hooks it into the firmware. Only
CONFIRMED and STRUCTURAL names are exported. Names that clash with the C library become
`stock_<name>`, so GCC's implicit `memcpy`/`memset` calls never bind to a reverse-engineered
stock routine.

For a new RAM range not already in `allocations.json`, run `placement_scan.py --lo ... --hi ...`
first, and treat a `clear` verdict as evidence, not proof (its docstring explains why a range
that reads as zero can still be live).

### 3. Build

- **One hook into one sector:** `build_patch.py`, wrapped by `make build-patch`:

  ```sh
  make build-patch HANDLER=my_handler.S STOCK_SECTOR=<current 4KB sector.bin> \
      SECTOR_BASE=0x030e1000 HOOK_ADDR=0x030e100c HOOK_BYTES=08ea0000 OUT=out.bin
  ```

  It fails if the hook site's bytes differ from `HOOK_BYTES`, the placement area is not erased,
  the branch is out of range, or the sector is the per-unit sector. Corpus risk findings are
  printed as warnings.
- **Several sites or sectors:** write a build script that splices with byte-exact expectations, as
  `examples/snake/build_snake_patch.py` does (six sectors, a new top-level menu category, verified
  on hardware). `examples/build_overlay_image.py` is the smaller hook-after-prologue trampoline
  example. Read `examples/snake/README.md` and `HISTORY.md` before writing a multi-site patch.

### 4. Verify

```sh
make verify-patch SECTOR=out.bin OFFSET=0xE1000 KEEP=/tmp/verify-run
```

`verify_patch.py` checks one sector per call. The pre-flight always runs; the dynamic half runs
when `qemu-system-cskyv2` is on PATH and is reported as skipped otherwise (`--skip-dynamic`
forces that). The dynamic half boots stock and patched images to the standby screen, presses
MENU then BACK (extend with `--keyseq` to reach the screen your patch changes), and compares every
settled frame and the executed code.

| Verdict | Exit | Meaning |
|---|---|---|
| PASS | 0 | screens identical, no code-coverage change outside the sector |
| PASS with warnings | 0 | screens identical, code outside the sector ran differently (normal for a hook that calls stock code) |
| (dynamic step skipped) | 0 | pre-flight only; no QEMU available |
| FAIL | 1 | static gate failed, or the patched image crashed or never finished the probe while stock did |
| (bad arguments) | 2 | |
| DIFFERS | 3 | screens differ; expected for a UI patch the probe reaches. Review the kept frames. |
| INCONCLUSIVE | 4 | stock itself did not complete the probe, or the patch overlaps a QEMU-only patch site |

A PASS covers only what the probe reached. The model has no RF, DMR, vocoder or codeplug (the
data chip is all `0xFF`, so standby shows "Null Ch."), and says nothing about calibration.

For interactive checking, the emulator loop is:

```sh
# bootable image: stock + your sector + the three QEMU-only boot patches
python3 src/dm32_patch_tools/compose_qemu_image.py \
    --sector out.bin@0x030e1000 --out /tmp/boot/image.bin --iram-out

# MENU, Down, Ok (key strings from qemu_run.KEYS)
python3 src/dm32_patch_tools/qemu_run.py --image /tmp/boot/image.bin \
    --iram /tmp/boot/iram.bin --sram /tmp/boot/sram.bin \
    --keyseq="-1:0:1:17:20:120;2:11:1:18:20:40;2:7:1:17:20:40" \
    --tag my-run --until-step 3

python3 src/dm32_patch_tools/render_frames.py --rundir qemu-run/my-run --last 6 --out /tmp/montage.png

# if it hangs: rerun with --gdb, then
python3 src/dm32_patch_tools/gdb_rsp.py crashwait --dump 0x18007000,64
# or profile a `--extra "-d exec,nochain -D trace.log"` run
python3 src/dm32_patch_tools/pc_histogram.py --trace trace.log --out /tmp/pcw
python3 src/dm32_patch_tools/pc_histogram.py --map /tmp/pcw/pcw_00.txt --top 20
```

`../docs/qemu-workflow.md` covers what the model can and cannot simulate.

### 5. Stage

```sh
python3 src/dm32_patch_tools/stage_sectors.py \
    --patched my_full_patched_image.bin \
    --stock ../data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin \
    --out /tmp/staged --expect-sectors 0x030e1000
```

It writes one `sector_<addr>_patched.bin` per changed sector, verified against the patched
image, plus `MANIFEST.sha256`, and prints a command template for each. It exits 2 on any sector
flagged `known_sensitive` and refuses the three QEMU-only sectors unless `--allow-qemu-only` is
given. Stage the patched image from your build script, never the output of
`compose_qemu_image.py`.

To share a patch, publish a BPS file, not a patched image (which contains the whole vendor
firmware):

```sh
python3 src/dm32_patch_tools/bps_patch.py create \
    ../data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin my_full_patched_image.bin my.bps
python3 src/dm32_patch_tools/bps_patch.py info my.bps
python3 src/dm32_patch_tools/bps_patch.py apply <own verified backup>.bin my.bps patched.bin
```

`apply` checks the CRC32 of the whole source image and refuses unless it is byte-identical to
the image the patch was created from. Neither subcommand writes to a radio.

### Hard rules

- **Never write the per-unit sector `0x0300b000`-`0x0300bfff`.** It holds that radio's
  eFuse-derived hardware-binding record and per-unit hardware bytes. It reads as `0xFF` in every
  image here only because it was scrubbed (`scrub_unit_sector.py`); on a radio it is never free.
  `build_patch.py` and `gen_link_artifacts.py` refuse it, `check_doc_claims.py` fails any doc
  calling it free, and `stage_sectors.py` refuses it unless `--allow-qemu-only` is passed.
- **Emulator-only patches never reach a radio.** `compose_qemu_image.py`'s three patches (ALPU-MP
  bypass sector `0x030c6000`, auto-power-off NOP in sector `0x0301b000`, binding record in
  `0x0300b000`) exist only so the model can boot. On a real unit they defeat the anti-clone and
  binding checks.
- **Flashing is outside this repository.** Every tool here stops at producing files and printing
  commands. Writing to a radio is a separate, manual step a human runs, with a verified full
  backup of that exact unit first. Do not add a flash-write path here.

## Design notes worth knowing before extending this

- **Load base is `0x03000000`.** The image starts with a `0x1000`-byte header (DH_FLAG magic,
  encoded load address), so code starts at `0x03001000`. `ghidra_project.py`'s docstring records
  how this was verified.
- **The Ghidra rebase:** `ProgramLoader.Builder.addLoaderArg("Base Address", ...)` silently has
  no effect in this pyghidra/Ghidra version. `ghidra_project.py` imports at the default base and
  calls `Program.setImageBase()` in a transaction before any analysis runs.
- **Never disassemble byte-by-byte on failure.** `Disassembler.disassemble()` mutates the shared,
  persistent listing. Trying every byte offset can commit a garbage decode at a misaligned address
  that then blocks the correct decode of later functions. `export_disasm.py`'s
  `disassemble_range()` resyncs on 2-byte boundaries (the CK803S minimum instruction width).
  Before this was fixed, one bad byte cascaded into 280+ bogus reports.
- **A function can have real code before and after an inline literal pool.** Resync and keep
  going after an undecoded span instead of stopping.
- **A short gap at a function's tail is not reliably padding.** `strlen_unaligned_path` and
  `strlen_ck803s` end in real bad-instruction stops of that size. Report every undecoded range
  as-is.
- **`export_disasm.py`'s undecoded spans and the corpus's `halt_baddata()` markers disagree in
  both directions, by design.** A bare disassemble has no notion of control flow, so `mfcr`/`mtcr`
  class stops that decode as valid instructions are not flagged. Treat the two signals as
  complementary. (`vendor/ghidra_csky` decodes `mfcr`/`mtcr` for control-register bank 0 only;
  see its README's "Status".)
- **Not every `bsr`-shaped word is a call.** Inline data can decode as a `bsr` to a nonsense
  address (observed: `0x06be6002`). `export_xrefs.py` classifies targets as `resolved` / `iram`
  / `flash_unresolved` / `garbage` and drops only `garbage` (607 of them in this image).
- **`known_sensitive` and `patch_risk` are floors, not ceilings.** `known_sensitive` is seeded
  from catalogued patch sites (today the ALPU-MP bypass sector). `high` risk fires on catalogued
  sites, sensitive sectors and a narrow ISR name pattern; most ISRs are registered through
  function pointers the xref data cannot see. `unknown` means "no detected callers or callees",
  which is as consistent with "reached only indirectly" as with dead code; never treat it as
  `low`. Naming confidence (CONFIRMED/STRUCTURAL/RAW) and patch risk are separate axes.
- **No program-flash sector is calibration-bearing.** Per-unit calibration is on the separate
  16 MB data chip, which this corpus does not cover. The per-unit sector `0x0300b000` above is a
  hardware-binding record, not calibration. Confirm which chip an address is on before adding a
  calibration flag anywhere.
- **`calling_convention_overrides` in `meta/xrefs.json` ships empty on purpose.** The one known
  non-ABI convention belongs to project-authored handler code, not to any stock function. Add an
  override only when a stock function needs one.
- **A patch site that does not resolve to a corpus function is not automatically wrong.**
  `live-ram-hook` (`0x0302a47c`) matches stock bytes exactly but falls just past the corpus's
  recorded end of `serial_protocol_vframe_command_loop`; its entry sets
  `expected_resolution: False`. Fix the corpus boundary, not the address.
- **Patch sites have four `kind`s:** `instruction-patch` and `data-patch` (code vs. a literal;
  literals often sit in pools no function owns), `handler` (new code in flash stock never used),
  and `third-party-finding` (a hook this project did not author), kept separate so the catalogue
  never claims work it did not do. Cross-checking the catalogue against real artifacts has already
  caught one misattributed site (`0x030C6866` is this project's own ALPU-MP bypass).
- **`verify_patch.py` is two independent halves.** The pre-flight is pure data lookup and runs
  anywhere. The dynamic half (`qemu_boot_diff.py`) stops on firmware progress (key-script
  completion under `-icount`), not wall-clock time, so results do not depend on host load. Both
  images get the same QEMU-only patches. Without the ALPU-MP bypass the firmware halts at the
  deliberate `while(1)` at IRAM `0x169d4`, the failure leg of the anti-clone check.
- **IRAM always comes from the composed flash.** The boot stub copies flash
  `0x030bfc20`-`0x030decb8` to IRAM `0x00010000`, overwriting any `-device loader` preload, so a
  patch inside that flash range is what runs from IRAM under emulation too.

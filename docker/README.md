# dm32uv-re, containerized

Runs the whole patch-development lifecycle — find a target in the corpus, write/assemble a
patch, verify it — inside Docker instead of against a locally-installed Ghidra, a locally-built
QEMU, and a separate amd64-emulated cross-compiler wrapper. One image provides:

- **Ghidra 12.1.3** + the C-SKY Sleigh extension (`vendor/ghidra_csky`), so `pyghidra` can drive
  `export_disasm.py` (and, downstream of its output, `export_xrefs.py`/`export_patch_risk.py`,
  which are pure-Python and don't need Ghidra themselves).
- **`qemu-system-cskyv2`**, built from mainline QEMU (the GitLab mirror, pinned to a commit both
  `vendor/csky-qemu` and `vendor/dm32uv-qemu` were verified against) with those two overlays
  installed — the CPU target and the DM-32 board model respectively — for `verify_patch.py`'s
  dynamic verification half (`qemu_boot_diff.py`).
- **`csky-abiv2-elf-gcc`** (GCC 6.3.0), a CK803S cross-compiler built from source
  (`vendor/csky-toolchain-build`), native to this image's own architecture — no amd64 emulation
  of a prebuilt binary needed. `cskybuild.sh` is a drop-in replacement for the main repo's
  host-side toolchain wrapper, same CLI contract, no nested container.
- **`libcapstone` with C-SKY support** (`github.com/awkaplan/capstone`, branch `csky`, pinned by
  commit in the Dockerfile's `capstone-csky` stage), installed at `/opt/capstone-csky` and exported
  as `DM32_CAPSTONE_LIB` / `DM32_CAPSTONE_HDR`, so `cs_disasm.py --addr 0x03012e14` works out of
  the box. Stock capstone has no C-SKY module. `cs_disasm.py --backend objdump` uses
  `csky-abiv2-elf-objdump` instead (also the automatic fallback when no capstone-csky is found).

## Prerequisites

- Docker with Compose v2 (`docker compose version`).
- The four vendored submodules checked out: `git submodule update --init vendor/ghidra_csky
  vendor/csky-qemu vendor/dm32uv-qemu vendor/csky-toolchain-build` from the `dm32uv-re` root (or
  `--recursive` from the outer `dm32` checkout).

## Build

```sh
cd docker
docker compose build
```

Takes a while the first time: downloads Ghidra (~400MB), builds the GCC cross-toolchain from
source (the slow part), clones a pinned QEMU commit and compiles `qemu-system-cskyv2`, builds the
Sleigh extension with Gradle, and (in a parallel stage) builds capstone-csky. All of that is cached in
image layers — a rebuild after only touching `tools/` or `meta/` is instant (those are bind-
mounted, not baked in; see `docker-compose.yml`'s comments for why `tools/pyproject.toml` and
`tools/.venv` specifically are the two exceptions). Layers are ordered most-expensive-first
(toolchain, then QEMU, then the Ghidra extension), so a `vendor/ghidra_csky` Sleigh fix only
rebuilds the Gradle step and what follows it.

`docker compose build` tags the result `dm32uv-re-pipeline:latest` (the compose file's `image:`).
To keep a known-good build around, tag it before rebuilding:
`docker tag dm32uv-re-pipeline:latest dm32uv-re-pipeline:<name>`.

## No prebuilt image

This project does not publish the pipeline image, and you should not publish yours: it contains a
QEMU build (GPL-2.0) linked with the board model (PolyForm Noncommercial), and `LICENSE.md` asks
that neither `qemu-system-cskyv2` binaries nor images that include it be distributed. Build it
locally as above. Codespaces/VS Code users can use the `../.devcontainer/` setup, which builds and
attaches to this same compose service.

## Run

```sh
docker compose run --rm dm32uv-re
```

Drops you into a shell at `/work/tools` with everything on `PATH` — `qemu-system-cskyv2`,
`csky-abiv2-elf-gcc`, `gradle`, `uv`, etc. — and a `Makefile` wrapping the whole patch
lifecycle. `make help` lists every target; the same scripts are also runnable directly (see
`../tools/README.md`) if you want to pass a flag the Makefile doesn't expose.

### Two ways in, and when to use which

The top-level `README.md` shows a different invocation — `docker run --rm -v "$PWD":/repo -w
/repo/<subdir> dm32uv-re-pipeline -c '<command>'` — and both are correct:

| | `docker compose run` (this file) | `docker run -v "$PWD":/repo` (top-level README) |
|---|---|---|
| Mounts | `tools/` **per subdirectory**, plus `data/`, `meta/`, `src/`, `include/` | the whole repo at `/repo` |
| Working dir | `/work/tools` | whatever `-w` says |
| Use it for | an interactive session, and anything touching `pyghidra` | one-shot commands, scripting, CI |

The compose file deliberately mounts `tools/` one subdirectory at a time so the host's
`tools/.venv` and `tools/pyproject.toml` do **not** overlay the image's own: `setup.sh` rewrites
that `pyproject.toml` to point at the host's decompiler wheel, which is the wrong path inside the
container. The whole-repo mount does overlay them, so it is fine for everything except the
decompiler-backed scripts (`export_disasm.py` and friends) — use compose for those.

Either way, remember that the container's `/tmp` disappears when the command exits: write outputs
under the mounted repo if you want to keep them.

```sh
# static analysis (needs Ghidra; pure-python steps work even without it)
make disasm LIMIT=50        # uses `uv run` internally - needed for pyghidra
make export-all             # disasm -> xrefs -> sectors -> patch-sites -> patch-risk

# build a patch: assemble a handler, splice it into a sector, hook a br/bsr into it -
# cross-checks the hook/handler addresses against meta/sectors.json, meta/patch_risk.json and
# meta/patch_sites.json (warnings only, never blocking) before writing anything. See
# `make help` for every variable, or build_patch.py's own --help/module docstring for the two
# hook kinds and the safety checks it runs.
make build-patch HANDLER=my_handler.S STOCK_SECTOR=<current 4KB sector.bin> \
    SECTOR_BASE=0x030e1000 HOOK_ADDR=0x030e100c HOOK_BYTES=08ea0000 \
    OUT=sector_030e1000_mymod.bin

# patch verification, both halves (corpus pre-flight always runs; dynamic half uses THIS
# image's own qemu-system-cskyv2 automatically if it's on PATH, no external container).
# --iram defaults to data/firmware/IRAM_dm32.00.01.048.bin, derived from the program flash exactly
# as the boot stub builds IRAM (tools/src/dm32_patch_tools/derive_iram.py) - several flash
# functions call into IRAM-resident code; see verify_patch.py's own --help to override.
make verify-patch SECTOR=sector_030e1000_mymod.bin OFFSET=0xE1000
```

## Regression-checking the image itself

```sh
./smoke_test.sh              # rebuilds first, then runs every check below
./smoke_test.sh --no-build   # image already built/current - just run the checks
```

Runs end-to-end, inside the image: the cross-compiler compiles and the output is real CK803S
machine code; the `cskybuild.sh` wrapper; `qemu-system-cskyv2` has the `dm32` machine;
`pyghidra` imports; `export_disasm.py` and `export_sectors.py` each produce real output;
`build_patch.py` assembles and splices a synthetic patch; `cs_disasm.py` disassembles a known
function through both backends (capstone-csky and the objdump fallback); the installed Ghidra
extension carries the `movih` Sleigh fix; `verify_patch.py` rejects a malformed sector with exit
status 2 and returns PASS / exit 0 for an identity patch after a full QEMU boot-diff (stock vs
stock must compare equal - anything else means the harness is broken or nondeterministic). The
export-script checks run on a scratch copy inside the container, never on the bind-mounted
`meta/`, so the smoke test cannot overwrite the host's corpus. Run this after touching anything under `vendor/`, the `Dockerfile`, or
`docker-compose.yml` — getting this pipeline working took many iterative build-fix cycles (the
`Dockerfile`'s comments and `vendor/csky-toolchain-build/README.md`'s "Changes on this branch"
describe the specific bugs each check would have caught), and a full manual re-verification is
exactly what this script exists to replace.

## What's baked in vs. live-mounted

| Path | Image build time | `docker compose run` |
|---|---|---|
| `vendor/ghidra_csky`, `vendor/csky-qemu`, `vendor/dm32uv-qemu`, `vendor/csky-toolchain-build` | built into the image | not mounted — rebuild the image to pick up a submodule bump |
| `tools/pyproject.toml`, `tools/.venv` | baked for this image's `/opt/ghidra` path | **not** mounted (host's are macOS-pathed — see compose file comment) |
| `tools/src` (the actual scripts), `tools/Makefile`, `tools/README.md`, `tools/include/` | copied in | bind-mounted — edits on the host apply immediately (`include/` read-only) |
| `tools/link/`, `tools/examples/` | copied in | bind-mounted **read-write** — `make link-artifacts` regenerates `link/*.ld`, and the examples' build scripts write next to themselves |
| `include/`, `meta/`, `data/` (incl. `data/firmware/`, `data/allocations.json`) | copied in | bind-mounted (`meta/` read-write — the export scripts write there; `include/` and `data/` **read-only**, so nothing in the container can modify the committed firmware images) |
| `src/` | not copied | bind-mounted read-only |
| `out/` | — | bind-mounted read-write (`make_stock_elf.py`, `make link-example` write here); created on first run |
| `/opt/capstone-csky` | built in its own stage | not mounted |

## Known gaps carried over from the vendored repos, read before trusting a result

- **`-M dm32` reaches the standby screen and menu with three QEMU-only patches applied.** Stock
  firmware boots to the standby screen with the ALPU-MP bypass, auto-poweroff bypass, and
  hardware-binding bypass patches in place (applied by `compose_qemu_image.py` and guarded by
  byte-exact assertions on the stock image). These patches are necessary only for the emulator
  and must never be flashed to a real radio. Without them, stock firmware loops at an ALPU-MP
  check exception before the UI boot completes. The three patches are documented in
  `docs/qemu-workflow.md` and `vendor/dm32uv-qemu/docs/boot-path.md`.
- **CPU-model stale-PC fix and LCD pin-mux fix must be in the image.** The original c-sky/qemu
  CPU target left the saved PC stale across `mtcr cr0`/`psrset` (both can take a pending
  interrupt mid-block); `vendor/csky-qemu` syncs the PC first (`gen_save_pc(ctx->pc + 4)` in
  `target/csky/translate_v2.c`). The DM-32 board model's LCD pin-mux (IO_DIPLEX2) logic is in
  `vendor/dm32uv-qemu`. Both trees are vendored and must be checked out and rebuilt into the
  image for the model to work correctly — if either is missing or stale, `git submodule update`
  and rebuild the Docker image.
- **The QEMU commit is pinned, not `master`.** `docker/Dockerfile`'s `QEMU_REF` build-arg is set
  to the exact commit both overlays' `install.sh` were last verified against. Their `git apply
  --check` fails the build loudly (not silently) if a future bump breaks the patch — bump
  `QEMU_REF` deliberately, re-verify, and update this comment, rather than floating `master`.
- **ALPU-MP (the anti-clone coprocessor) and the RF/vocoder signal path are not modeled.** Stock
  firmware needs ALPU-MP patched out of the flash image to boot at all under this image's QEMU;
  the board model does no real over-the-air DMR signal work
  (the modem model tracks slot *timing* for protocol work, not actual RF).
- **The cross-toolchain is C-only, no `gdb`.** `vendor/csky-toolchain-build`'s C++ support hits
  a known-hard GCC cross-bootstrap issue in `libstdc++` (link tests disallowed under
  `GCC_NO_EXECUTABLES`), and its `gdb` build is a *host*-side C++ program incompatible with this
  image's own GCC 14/libstdc++ — both dropped rather than chased, since every existing patch
  handler here is `.S`/C and nothing here uses an interactive debugger. If a real need for
  either comes up, `vendor/csky-toolchain-build/README.md` ("Changes on this branch") and the
  comments in its `build-csky-gcc.py` say where each was cut (`-m gdb` still builds gdb).

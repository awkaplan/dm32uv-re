# dm32uv-re — orientation for coding agents

> Claude Code users: `CLAUDE.md` has the full standing gotchas; this file is the short canonical
> orientation for all agents (OpenCode, Codex, Claude Code, …). Read both.

## What this repo is

A reverse-engineering + patch-building kit for the Baofeng DM-32UV stock firmware (HR_C7000 SoC,
C-SKY CK803S core). It is **generated analysis corpus plus hand-maintained patch tooling**, with a
hard split you must respect:

- **Regenerated wholesale, NEVER hand-edit:** `src/` (3561 decompiled functions), `include/`,
  `meta/`, `site/`, `build/`. Edits there are silently lost on the next regen.
- **Hand-maintained, survives regen:** `tools/` (the patch kit), `docs/` (prose narrative),
  `docker/` (one image: toolchain + QEMU board model + decompiler), `data/` (firmware images and
  the memory-claims registry).

Exception to "never hand-edit meta/": files produced by this repo's **own** export/gen tools
(`export_disasm.py`, `export_xrefs.py`, `export_sectors.py`, `export_patch_sites.py`,
`export_patch_risk.py`, `gen_link_artifacts.py`) are refreshed by re-running those tools, never by
editing the output. Anything else you learn goes in `docs/` (see "Recording what you learn").

The repo contains **no per-unit data** — no calibration constants, codeplug contents, or radio
identifiers (`README.md` "Scope"). It carries only stock-behaviour docs, the corpus, the tooling,
and two worked examples (`tools/examples/snake/`, `tools/examples/overlay_trampoline.S`).
Nothing here can flash a radio.

## Hard rules

- [x] **Nothing here flashes a radio; never add a flash-write path.** Every tool stops at
  producing `.bin` files. Flashing is a separate, manual, human-run step outside this repo, on a
  radio with a verified full backup.
- [x] **Never write the per-unit sector `0x0300b000`–`0x0300bfff`.** It holds the eFuse-derived
  binding record (at `+0x10c`) and per-unit hardware bytes. It reads `0xFF` in every shipped image
  only because those images are scrubbed — never because it is free. The builder tools refuse it.
- [x] **Emulator-only patches must never be staged for a radio:** the ALPU bypass (sector
  `0x030c6000`), auto-power-off (`0x1BDE0`) and the hardware-binding record (`0xB10C`) exist only
  so QEMU can boot. `stage_sectors.py` refuses them unless `--allow-qemu-only` is passed.
- [x] **Never commit a live radio capture.** `data/firmware/live-captures/` is gitignored; a
  capture is a snapshot of one specific radio, a different category from the stock-derived
  reference data this repo does commit (`docs/live-ram-capture.md`).
- [x] **Verify expected stock bytes immediately before every write, in the build script itself.**
  Assert the hook bytes, bound-check bytes, literal-pool slots and erased ranges right before
  overwriting — never from memory of an earlier check (`CLAUDE.md` gotcha 4).
- [x] **New radio BEHAVIOUR (features) belongs OUT of this repo.** Scaffold with
  `python3 tools/src/dm32_patch_tools/new_patch.py NAME --dest <outside>` and build with
  `build_manifest_patch.py --extra-allocations <file> --require-claims`. In-repo
  `tools/patches/` (gitignored) is for WIP only; `README.md` "Scope" is the rule.

## The golden path — five commands for a patch

The full prose version is `README.md` "Writing a patch". Compressed:

1. **Find the code to hook:**
   `python3 tools/src/dm32_patch_tools/lookup.py 0x03018e64` — or `--search standby` for a
   name/substring. It joins function, confidence, sector, patch risk, catalogued sites, callers,
   disassembly.
2. **Scaffold or write the patch:** `python3 tools/src/dm32_patch_tools/new_patch.py NAME
   --dest <outside>` (the scaffold's manifest has a guarded TODO hook; the builder refuses to run
   until it is filled in). For a multi-site patch, write a manifest like
   `tools/examples/snake/snake.patch.json`.
3. **Build (inside Docker):** the image is `dm32uv-re-pipeline` (build once via `docker compose
   build` under `docker/`). One-shot form:

   ```sh
   docker run --rm -v "$(git rev-parse --show-toplevel)":/repo -w /repo \
       dm32uv-re-pipeline -c '<cmd>'
   ```

   (`tools/dm32`, if present, wraps this.) The command is `python3
   tools/src/dm32_patch_tools/build_manifest_patch.py <manifest> --extra-allocations <file>
   --require-claims`. Outputs land in `out/patches/<name>/` (gitignored).
4. **Verify under QEMU:** `compose_qemu_image.py --patched <image> --out ... --iram-out` →
   `qemu_run.py --image ... --keyseq ...` → `render_frames.py`. See `docs/qemu-workflow.md`.
5. **Stage for a human:** `stage_sectors.py --patched <image> --stock
   data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin --out <dir>` — one file per
   changed sector plus a manifest. It never flashes.

Single-hook patches can use `build_patch.py` (`make -C tools build-patch`) instead of a manifest.

## Where the knowledge lives

- **`CLAUDE.md`** — the standing technical gotchas (literal-pool-slot vs table address, zext bit
  ranges, keypad/LCD bus mux, verify-before-write). Read it; several cost real time once each.
- **`docs/patch-patterns.md`** — 12 hook/splice techniques, each with the failure it avoids and a
  QEMU check. Pattern numbers are referenced throughout `docs/patch-cookbook.md`.
- **`docs/patch-cookbook.md`** — goal-indexed recipes ("I want to X" → read/do/traps/verify).
- **`docs/menu-system.md`**, **`docs/keypad-input.md`**, **`docs/rtos-and-memory.md`**,
  **`docs/qemu-workflow.md`** — the subsystem narratives the generated function names don't carry.
- **`tools/include/dm32_patch_api.h`** — every stock primitive a patch can safely call, with
  addresses and C-SKY ABIv2 calling conventions.
- **`meta/*.json`** — machine-readable corpus: `functions.json`, `xrefs.json`, `sectors.json`,
  `patch_sites.json`, `patch_risk.json`, `disasm.jsonl`.
- **`data/allocations.json`** — the memory-claims registry: the flash/SRAM patch windows, the
  forbidden ranges, and every existing claim (Snake, RAMDUMP probe, overlay guard).

Worked examples to copy from: `tools/examples/snake/` (new menu category + blocking screen,
`README.md` + `HISTORY.md` are the real documentation) and `tools/examples/overlay_trampoline.S`
(the smallest hook-after-prologue trampoline).

## Recording what you learn

New mechanisms go into `docs/*.md` prose (or a new `docs/` file) — **NEVER into generated files**.
A correction made only to `meta/functions.json` (or any generated copy) is lost on the next regen;
`docs/` survives. After editing any doc that names a free/erased range, run
`python3 tools/src/dm32_patch_tools/check_doc_claims.py` and leave it exiting 0.

## Definition of done for a patch

- Builds with `build_manifest_patch.py` with **no unexpected-byte errors** (every splice's
  expected bytes asserted against stock).
- Verifies under QEMU to the expected screens (frame fingerprints in `docs/qemu-workflow.md`
  "Reading the results").
- Claims recorded in `data/allocations.json` (or the out-of-tree `--extra-allocations` file) and
  `gen_link_artifacts.py` re-run (`make -C tools link-check` passes).
- `make -C tools test` passes (`tests/run_tests.py --suite host`).
- `python3 tools/src/dm32_patch_tools/check_doc_claims.py` exits 0.

## When you reach outside this repo

If a patch build genuinely needed something this repo doesn't carry (a tool, a reference doc, a
generic stock-derived artifact), it's safe to vendor in — see `CLAUDE.md` "Closing a gap". If a
task seems to call for flashing hardware, stop and say so; that step belongs elsewhere and is
never automated here.

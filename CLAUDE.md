# dm32uv-re: patch-development instructions

This repo is **generated output plus hand-maintained patch tooling** (see `README.md`'s own
"generated vs. hand-maintained" split — `src/`, `include/`, `meta/`, `site/`, `build/` are
regenerated wholesale and never hand-edited; `tools/`, `docker/`, `docs/`, and `data/` are not).
It contains **no per-unit data of any kind** — no calibration constants, codeplug contents, radio
identifiers, or anything else specific to an individual device (see `README.md`'s "Scope"
section). Every byte here is either analysis of the stock vendor firmware image, or new code/data
this repo's own patch tooling can produce.

## What this repo is for

Building and verifying patches against the DM-32UV's stock firmware — new screens, new menu
entries, new behavior — without needing to leave this directory for reference material. If you
find yourself reaching outside this repo for something (another project's docs, a tool that isn't
here, a firmware image this repo doesn't ship), that's a gap in this repo worth closing, not just
working around — see "Closing a gap" at the end of this file.

## New here? Start with AGENTS.md and docs/patch-cookbook.md

`AGENTS.md` is the short canonical orientation for any coding agent dropped into this repo — the
hard rules (what never gets flashed, what never gets committed, what never gets hand-edited) and
the five-command golden path. `docs/patch-cookbook.md` indexes the same material by goal ("I want
to add a menu category", "I want to place patch state in RAM", ...) with the exact commands, traps
and QEMU fingerprints. This file keeps the standing technical gotchas below — read AGENTS.md first
and this file before trusting any address you find.

## Scope

This repository carries only stock-behaviour documentation, the decompiled corpus, the tooling,
and two worked examples (Snake and the overlay trampoline). Patches that add **new radio
behaviour**, and feature proposals and analyses, are out of scope and belong in a repository of
their own; the tooling builds such out-of-tree patches unchanged (`tools/README.md`, "Building a
patch that lives outside this repo").

## Before touching anything: read these docs

- **`docs/menu-system.md`** — how the top-level menu actually works (item visibility, string
  tables, screen-mode dispatch), including two hard-won gotchas about table addresses that cost
  real time to rediscover once already.
- **`docs/keypad-input.md`** — how to read a keypress from patch code, and the real scan codes.
- **`docs/rtos-and-memory.md`** — where to place patch state and how to interact with the
  uC/OS-III RTOS (tasks, semaphores, mutexes, timeouts).
- **`docs/qemu-workflow.md`** — verifying a patch under the `-M dm32` QEMU model: what it can
  and cannot simulate, the build-run-render-stage loop, how to debug with `gdb_rsp.py` and
  `pc_histogram.py`, and known pitfalls.

All four were written while building this repo's own first example patch (a Snake game added as a
real new top-level menu category) and are the connecting narrative the generated corpus's function
names alone don't carry. If you trace a NEW mechanism this session that isn't already written down
in one of these, **add it to the relevant doc as you go** (or start a new `docs/*.md` file if it's
a genuinely separate subsystem) — don't just fix the one thing you needed and move on. The next
agent to touch this area starts from what you leave behind, the same way this session started from
what a previous one left.

## Before writing patch code: read the API header

**`tools/include/dm32_patch_api.h`** — every stock-firmware primitive a patch can safely call,
with addresses, calling conventions (C-SKY ABIv2), and RTOS object handles. Supersedes the older
`dm32_ui.h` (kept for the overlay example). Everything documented was exercised by the Snake
example under QEMU and on real hardware (confidence tags note which).

## Standing technical gotchas (apply these before trusting any address you find)

0. **Every call to the stock keypad scan must be followed by `lcd_bus_restore_after_keypad_scan()`
   before the next LCD write (hardware-only failure).** The keypad matrix and the LCD data bus
   share the same GPIO pads; the scan hand-muxes them to GPIO with `IO_DIPLEX2 |= 0xfe00`, and
   restores them to LCD with `IO_DIPLEX2 &= 0xffff01ff`. On real hardware, a forgotten restore
   causes the next LCD write to hit GPIO pins instead, freezing the panel white until the next
   power cycle. The QEMU model now detects and visualizes this (writes while muxed are forced
   white), so a forgotten restore shows up under emulation too — but it is load-bearing on
   hardware.

1. **A jump/function-pointer table's address as named by Ghidra or seen in the decompiled C
   (`PTR_PTR_xxxxx`, `_LAB_xxxxx`, or a bare hex literal in a `bsr`/`ldr.w` site) is very often the
   LITERAL-POOL SLOT holding the table's base address, not the table's real address.** Reading N
   words starting AT that named address produces plausible-looking garbage. Disassemble the real
   call site and read the table base as the 32-bit VALUE stored there, then re-read from that
   value.
2. **Searching the raw image for a known address as a literal 4-byte value will find
   coincidental matches inside unrelated functions' own literal pools, not just real
   references.** A hit count is not evidence of that many real call sites. Confirm each hit by
   disassembling its own containing function (found via its real entry/prologue, not a guessed
   offset) and checking it's genuinely inside an `lrw` immediately preceding an indirect call. For
   finding real callers, brute-force-matching every `bsr`'s COMPUTED target address against a
   function's real entry address is reliable; string-searching the target address is not.
3. **CK803S `zext rd, rs, msb, lsb` is an inclusive bit RANGE (`[msb:lsb]`), not "extract `lsb`
   bits."** `zext32 a1, a1, 6, 6` is a single bit, not a 6-bit field. When in doubt, cross-check
   against a nearby instruction whose corresponding decompiled C is already known-correct.
4. **Verify before you write, every time**: confirm a flash region is genuinely erased (`0xFF`) and
   a hook site's bytes exactly match what you expect, immediately before writing — not from memory
   of having checked it earlier in the same session. `tools/src/dm32_patch_tools/build_patch.py`
   does this automatically for its own interface; if you're writing a custom build script (as the
   Snake example patch's `tools/examples/` precursor needed to, for its multi-site splice), do the
   same checks explicitly and fail loudly on any mismatch rather than overwriting silently.

## Tools available in this repo

| Need | Tool |
|---|---|
| Quick "what does this one call site do" disassembly | `tools/src/dm32_patch_tools/cs_disasm.py` (needs a capstone build with C-SKY support: built into the Docker image; on a host, see its module docstring, or `--backend objdump` falls back to `csky-abiv2-elf-objdump`) |
| Whole-corpus disassembly regen | `tools/src/dm32_patch_tools/export_disasm.py` (pyghidra-based, slow, see `tools/README.md`) |
| Find every on-screen string and where it lives in flash | `tools/src/dm32_patch_tools/extract_gb2312_strings.py` |
| Assemble a handler + splice a `br`/`bsr` hook into a sector | `tools/src/dm32_patch_tools/build_patch.py` (see `tools/Makefile`'s `build-patch` target) |
| Verify a patch (corpus risk lookup + optional QEMU boot-diff) | `tools/src/dm32_patch_tools/verify_patch.py` (see `tools/Makefile`'s `verify-patch` target) |
| Capture live RAM from a real radio (to confirm a region is actually free) | `tools/src/dm32_patch_tools/dm32_ramdump.py` — see `docs/live-ram-capture.md`, needs a live-RAM-read patch already on the radio |
| Stock API (display, keypad, RTOS, menu cells, scratch RAM) with calling-convention notes | `tools/include/dm32_patch_api.h` (`dm32_ui.h` is the older subset) |
| A complete, working hook-splice example to copy from | `tools/examples/` (`overlay_trampoline.S`, `build_overlay_image.py`) |
| A complete new-menu-category + blocking-screen patch, verified on hardware and under QEMU | `tools/examples/snake/` (read its `README.md` and `HISTORY.md`) |
| Compose an emulator-bootable image (applies the three QEMU-only patches) | `tools/src/dm32_patch_tools/compose_qemu_image.py` |
| Run the emulator with a key script, get the frame/step token line | `tools/src/dm32_patch_tools/qemu_run.py` |
| Render dumped frames to PNG | `tools/src/dm32_patch_tools/render_frames.py` |
| Registers / memory / write-watchpoints / crash poller over the gdb stub | `tools/src/dm32_patch_tools/gdb_rsp.py` |
| "Is this RAM/flash range free?" literal scan | `tools/src/dm32_patch_tools/placement_scan.py` |
| Turn a patched image into per-sector files + manifest + flash-command template | `tools/src/dm32_patch_tools/stage_sectors.py` |
| Exec-trace histogram mapped to function names | `tools/src/dm32_patch_tools/pc_histogram.py` |
| Full 1MB stock program-flash image (for erased-region checks, as the base for a bootable image) | `data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin` — use this, not `data/firmware/DM32.00.01.048.bin`, for anything that needs to know what's actually erased |
| ALPU-bypass sector (needed to boot ANYTHING under this repo's QEMU, patched or not) | `data/firmware/patching/sector_030c6000_alpubypass.bin` |

## Building and verifying a patch

See `README.md`'s own "Writing a patch" section for the end-to-end Docker workflow and
`tools/Makefile`'s targets. In short: find a target (`docs/menu-system.md`/`docs/keypad-input.md`
plus `meta/functions.json`), write a handler, `make build-patch`, `make verify-patch`.

**Limits of the dynamic-verification half** (read before trusting a PASS from it): the `-M dm32`
board model (`vendor/dm32uv-qemu/`) boots stock firmware to the standby screen **only when the
ALPU-bypass sector (`data/firmware/patching/sector_030c6000_alpubypass.bin`) is applied**. Without
it the boot stalls at `0x169d4`, a `br16 0x169d4` (a deliberate `while(1);` fatal halt) whose only
caller (IRAM `0x16c8c`) is the failure leg of the ALPU-MP anti-clone check. That is firmware
behaviour, not an emulator gap. `qemu_boot_diff.py` (`tools/src/dm32_patch_tools/`) still boots the
padded update file without the bypass, so a PASS from it proves only that the first ~7000 flash
transfers were unchanged, not a full-firmware behavioural guarantee; compose the image with the
bypass (as `tools/examples/build_overlay_image.py` does) for anything stronger. Keypresses work
because the GPIO model handles input reads at `EXT_PORT` (offset `0x50`), which stock reads; see
`vendor/dm32uv-qemu/hw/gpio/dm32_gpio.c` (`DM32_KEYSEQ`) and `docs/qemu-workflow.md` (2026-10-09
entry).

## Safety

- **This repo is safe to experiment in freely** — it contains no per-unit data, and nothing here
  can brick a real radio by itself. The patches this repo builds are inert binary diffs until a
  human deliberately flashes them.
- **Flashing a built patch to a real radio is ALWAYS a separate, manual, explicit, human-run step,
  never something to automate.** This repo's own tooling (`build_patch.py`, `verify_patch.py`)
  deliberately stops at producing a `.bin` file; there is no flash-write path anywhere in this
  repo, and none should be added. If a task seems to call for flashing hardware, stop and say so
  rather than looking for a way to do it — that step happens outside this repo, with dedicated flashing
  tooling, a verified full backup of that specific radio (its per-unit calibration cannot be
  restored from another radio's image), and a human directly reading and running each command.
- **Never check in a live radio capture of any kind.** `data/firmware/live-captures/` is
  `.gitignore`'d for exactly this reason (see `docs/live-ram-capture.md`) — a live RAM/flash
  capture is inherently a snapshot of one specific radio's runtime or configuration state, a
  different category from the stock-firmware-derived reference data this repo does commit. If
  you're about to add a binary file to this repo, confirm first that it's derived purely from the
  generic stock firmware image (same on every unit) and say so in whatever commit/PR introduces it
  — don't assume.

## Closing a gap

If you reach outside this repo for something a patch build genuinely needed — a tool, a reference
doc, a firmware artifact — and it's safe to vendor in (generic stock-firmware-derived, not
per-unit data), add it here rather than leaving the gap for the next agent to rediscover:

- Generic reference data (tools, headers, generic-firmware images) → the appropriate place under
  `tools/` or `data/firmware/`, with a short README note on provenance.
- A newly-traced mechanism → append to the relevant `docs/*.md` file (or start a new one) as prose,
  the same way `docs/menu-system.md` and `docs/keypad-input.md` were written. **Do not** try to
  fold a new finding back into `meta/functions.json` or any other generated file directly — those
  are regenerated wholesale from this project's own source-of-truth naming manifest, which lives
  outside this repo; a correction made only to the generated copy is lost on the next regen. Write
  it in `docs/` instead, in prose a human (or the regen process, eventually) can act on.

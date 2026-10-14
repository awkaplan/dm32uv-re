# Worked examples

| example | what it demonstrates | start here |
|---|---|---|
| `snake/` | **The main worked example.** A complete multi-site patch: a new top-level menu category, a blocking game screen, C + assembly blobs linked at free flash/SRAM, six spliced sectors, QEMU verification and staging. Built from a declarative manifest (`snake.patch.json`) or the original script. | `snake/README.md`, design history in `snake/HISTORY.md` |
| `overlay_trampoline.S` + `build_overlay_image.py` (+ `example_overlay.c`) | The smallest hook-after-prologue trampoline, described below. | this file |

Read `snake/` first for the end-to-end workflow; read the overlay example for the single-hook
pattern and its two gotchas. Flashing anything is a manual, human-run step this repo never
automates.

---

## Overlay example: a hook-after-prologue trampoline

The smallest complete, buildable, splice-verified example of adding new behavior to the stock
firmware without claiming a screen-mode ID — a UI overlay banner hooked onto an existing display
primitive's call path. Read this before writing a patch's own trampoline; the two gotchas below
cost real debugging time once each and are easy to re-make.

| file | purpose |
|---|---|
| `overlay_trampoline.S` | The whole patch: saves live registers, takes the re-entrancy guard, draws the banner **inline** (a blue `display_fill_rect` at 30,60–210,80 and the string "CLAUDE" via `display_draw_string_gb2312`), releases the guard, re-executes the two displaced stock instructions, jumps back. |
| `build_overlay_image.py` | Assembles the trampoline, splices it into the full stock image (`data/firmware/patching/`) at `0x030e1000` with a `bsr` at `0x0301899c`, verifies every byte it touches before writing, and (by default) applies the three QEMU-only patches from `../src/dm32_patch_tools/compose_qemu_image.py` so the result boots under the emulator. |
| `example_overlay.c` | **Not used by the build.** A C variant of the banner (different rectangle, 23,50–216,72) written against `../include/dm32_ui.h`, kept as a reference for writing the C half of a larger patch (the Snake example under `snake/` shows a full C build and link). |

## Build and verify

Inside this repo's Docker image (`cskybuild.sh` and the toolchain are on `PATH`; the repo can be
mounted read-only, since intermediates go to a temporary directory):

```sh
python3 tools/examples/build_overlay_image.py --out /tmp/ovl/boot.bin --iram-out
cd tools/src/dm32_patch_tools
python3 qemu_run.py --image /tmp/ovl/boot.bin --iram /tmp/ovl/iram.bin --sram /tmp/ovl/sram.bin \
    --rundir /tmp/ovl/run --timeout 110 --stall-seconds 1000
python3 render_frames.py --rundir /tmp/ovl/run --last 1 --out /tmp/ovl/last.png
```

`boot.bin` is a complete, emulator-bootable image with the overlay installed; the standby screen
should show the blue "CLAUDE" banner. The default build includes the ALPU bypass, the
auto-power-off NOP and the hardware-binding record (the shipped base image has its per-unit sector
`0x0300b000` blanked, so the ALPU bypass alone no longer reaches standby). **Those three are
QEMU-only and must never be flashed** — pass `--no-qemu-only-patches` for an image that differs
from stock only at the hook site and the handler region (see `../../docs/qemu-workflow.md`).

To reproduce real-hardware SRAM, where the guard word starts as power-on noise rather than zero,
pass `qemu_run.py --sram` a 32 KiB file with a non-zero word at offset `0x7fe0` (e.g. the observed
`0x140b32b9`); the banner should still draw, and `gdb_rsp.py mem 0x18007fe0 4` (with `--gdb`)
should read 0 afterwards.

## The two gotchas this pattern exists to avoid re-discovering

1. **Hook AFTER a function's prologue, never at its first instruction.** A `bsr` at a function's
   entry overwrites the caller's return address in `r15` before the prologue's own `push ...  r15`
   can save it — the function's epilogue then "returns" into its own body instead of the real
   caller. Hook the first instruction *after* the prologue instead, where `r15` is already safely
   on the stack and a `bsr` may clobber it freely.
2. **A hooked function that calls back into itself (directly, or via a shared helper) needs a
   re-entrancy guard**, or the nested call re-triggers the hook recursively. `overlay_trampoline.S`
   uses a single guard word at SRAM `0x18007FE0`, and the guard is a **magic value**, not a
   zero/non-zero flag: take = store `0x4F564C59`, skip only while the word equals it,
   release = store 0. That is deliberate, because nothing initialises the word:
   - The address's only provenance is "zero in `sram.bin`" — the zero-filled QEMU SRAM loader
     image — recorded by this trampoline's original comment. No live capture ever verified
     it.
   - The one full live SRAM capture from a real radio (not shipped here; see `../../docs/live-ram-capture.md`) shows
     `0x18004c00`–`0x18007fff` as power-on noise (13,277 of 13,312 bytes non-zero), with
     `0x18007fe0 = 0x140b32b9` (`../../docs/rtos-and-memory.md`; `../../docs/patch-patterns.md`
     pattern 2 and section 10 item 12).
   - The previous trampoline skipped the overlay while the word was non-zero, so on that radio it
     would most likely never have drawn. With a magic value, noise causes a skip only if it
     happens to equal the magic (about 2^-32 for random bits), and the first completed overlay
     leaves the word at 0.

   General advice still applies: capture your own RAM before trusting any scratch address
   (`../../docs/live-ram-capture.md`), expect unused SRAM on hardware to hold unchanging noise
   rather than zeros, and never write a guard or state variable that relies on a zero start value.
   One limitation remains: if the overlay is abandoned mid-draw (a fault, or a warm reset that
   keeps SRAM), the word stays equal to the magic and the overlay stays off until something
   stores 0 there.

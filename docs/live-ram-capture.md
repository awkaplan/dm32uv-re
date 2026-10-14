# Capturing live RAM from a real radio

## Why you'd need this

Placing new patch code or data safely requires knowing a RAM region is genuinely free before
claiming it as scratch space — a region reading as zero in one snapshot is evidence of "likely
unused," not proof (the same gap applies to flash: see `data/firmware/patching/README.md`'s note on
erased-vs-truncated). The static analysis in this repo can tell you a lot about what SHOULD be in
a given RAM region, but only a live capture from a real, running radio can confirm what actually
IS there at a moment you choose (e.g. "after the top-level menu has been opened at least once," if
that's the state your patch needs to coexist with).

## Why this isn't just another file in `data/firmware/`

Every other reference file this repo ships (`data/firmware/DM32.00.01.048.bin`,
`data/firmware/patching/*.bin`) is derived from the **stock vendor firmware image** — identical on
every unit running that firmware build, independent of any individual radio's configuration. A
live RAM capture is different in kind: it's a snapshot of one specific radio's runtime state at one
moment (stack contents, in-flight buffers, whatever the firmware happened to be doing), so it
doesn't belong in version control the way the stock-image-derived files do. `data/firmware/
live-captures/` is `.gitignore`'d for exactly this reason — capture your own there, and it stays
local.

## Prerequisite: a live-RAM-read patch must already be on the radio

Stock firmware has no command that reads arbitrary RAM over the CPS serial link — this capability
only exists if a patch has installed one. This repo does not (yet) carry the tooling to build that
patch from scratch; see `meta/patch_sites.json`'s `live-ram-hook` entry for its design
and build scripts if you need to create it. If your radio already has an equivalent capability
installed (from following that guide, or from a prior session), you can use the tool below
directly against it.

## Capturing a region

```sh
cd dm32uv-re/tools
python3 src/dm32_patch_tools/dm32_ramdump.py \
    --port /dev/tty.usbserial-XXXX \
    --addr 0x18000000 --size 0x8000 \
    --out ../data/firmware/live-captures/sram_18000000_0x8000.bin
```

- `--addr`/`--size`: the region you need to check. `0x18000000`-`0x18008000` is the full 32 KB
  SRAM range; `0x00010000`-`0x00058000` is the full 288 KB IRAM range. **No live IRAM capture
  is safe to commit either.** This repo once shipped one on the assumption that IRAM is boot-time
  code; it is, only up to `0x0002f098`. Above that is runtime state, and that capture held a
  codeplug channel name and the RAM copy of the calibration-derived table at `0x38470`. It was
  replaced 2026-10-10 by `data/firmware/IRAM_dm32.00.01.048.bin`, derived from flash
  (`tools/src/dm32_patch_tools/derive_iram.py`), which is identical on every unit. Use a live IRAM
  capture locally, e.g. with `placement_scan.py --iram <capture> --iram-is-live` to test whether
  an IRAM range is used at runtime, and keep it under `data/firmware/live-captures/`.
- `--probe`: read one chunk and print it, as a quick sanity check before a full capture.
- The tool is read-only by construction (`dm32_cps_common.py`'s own docstring explains the
  project's standing pattern of keeping write support in a separate, explicitly-reviewed module) —
  running it cannot modify the radio.

## Using the capture

Read it the same way any other binary dump in this repo is read — e.g. to check whether a
candidate scratch address is actually unused at the moment you captured:

```python
with open("data/firmware/live-captures/sram_18000000_0x8000.bin", "rb") as f:
    sram = f.read()
SRAM_BASE = 0x18000000
addr = 0x18007E00
print(sram[addr - SRAM_BASE : addr - SRAM_BASE + 64].hex(" "))
```

On hardware, SRAM the firmware never initialises is not zero: everything above the SRAM init
image (`0x18004c00` and up) holds power-on noise (see `docs/rtos-and-memory.md`): the one full live
capture (RAMDUMP 2026-09-29, not shipped) has 13,277 of the 13,312 bytes in
`0x18004c00-0x18007fff` non-zero. There, "unused"
looks like unstructured bytes that no code changes, not like zeros; compare captures, and do not
expect a scratch word to start at 0. A region reading all-zero (or matching some other known-idle
pattern) across two independent
captures taken at different times is good evidence it's unused; a single capture is only a
starting hypothesis — see `docs/menu-system.md`'s own account of how this exact distinction mattered
when this repo's first example patch (Snake) needed to place its game state somewhere in RAM.

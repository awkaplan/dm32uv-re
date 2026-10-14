# Patching reference data

The images here were **read from a DM-32UV's program flash** (there is no vendor download of this
build), then scrubbed: the one per-unit sector, `0x0300b000`-`0x0300bfff`, is blanked to `0xFF`
(`tools/src/dm32_patch_tools/scrub_unit_sector.py`). Everything else is firmware, identical on every
radio running DM32.00.01.048. Calibration and the codeplug live on the separate 16 MB data chip,
which nothing here touches.

**The per-unit sector (found 2026-10-10).** Program flash does hold per-radio data, in that one
sector: a 4-byte record at `+0x10c` derived from the SoC's eFuse ID, which the firmware checks at
runtime (the "hardware-binding" check; a mismatch shows an error screen), and per-unit hardware
bytes at `+0x80..+0x82` and `+0xa0..+0xa1`. Two other units' public dumps differ from each other and
from this radio's only inside this sector. Consequences: the sector is listed in
`occupied_regions.json`, `build_patch.py` refuses it, `compose_qemu_image.py` writes the binding
record only for emulation, and **these images must never be flashed whole onto a radio** - that
would overwrite the radio's own binding record and fail the check.

## `progmem_stock_DP570UV_20260926_FULL.bin`

The complete 1 MB (`0x100000`) program-flash image. `../DM32.00.01.048.bin` (the file the rest of
this repo's analysis is built from) is the same image truncated at `0xd2100` bytes — every byte
the two files have in common is identical (verified byte-for-byte before this file was added). The
per-unit sector is blanked in both; the hashes of the unscrubbed reads (`a51e4213...345a` for this
file, `0791558d...6147` for `../DM32.00.01.048.bin`) are the ones `PROVENANCE.md` and the generated
corpus cite as the analysis input.
This full version exists because patch-building needs to know which flash regions are genuinely
**erased** (`0xFF`, safe to place new code/data in) versus merely *not included* in the truncated
file, and only the complete image can answer that. SHA-256 in the matching `.sha256` file.

**Use this, not `../DM32.00.01.048.bin`, as the base image for `build_patch.py`'s erased-region
checks and for constructing a bootable image for `verify_patch.py`'s dynamic/QEMU half.**

## `sector_030c6000_alpubypass.bin` / `sector_030c6000_stock.bin`

The 4 KB sector containing the ALPU-MP anti-clone bypass patch (and its stock/unpatched
counterpart, for reference). `qemu-system-cskyv2 -M dm32` will not boot stock firmware past the
anti-clone challenge-response gate, so every dynamic-verification run needs this sector spliced
into the image in place of the stock one — it's needed purely to get far enough into boot for a
*different* patch's own verification to mean anything, independent of whatever that patch does.

Splice it in at flash offset `0xC6000` before booting:

```python
img = bytearray(open("progmem_stock_DP570UV_20260926_FULL.bin", "rb").read())
img[0xC6000:0xC6000+0x1000] = open("sector_030c6000_alpubypass.bin", "rb").read()
```

What the patch does: it replaces one `bnez` with two NOPs at IRAM `0x00016c46`, so a failed or
absent anti-clone authentication falls through instead of hanging at the fatal halt
(`0x000169d4`, a `br16 .` whose only caller is that check's failure leg). See
`../../../docs/qemu-workflow.md` for where it fits in the emulator workflow, and
`../../../meta/patch_sites.json` for the catalogued site.

## What's deliberately NOT here

A live SRAM capture (needed to confirm a RAM region is actually free before using it as patch
scratch space, the way this repo's own example patches needed to) is not included, because it is
inherently a snapshot of one specific radio's live runtime state at one moment — a different
category of data from the two stock-firmware-derived files above. See
`../../../docs/live-ram-capture.md` for how to capture your own.

## Region `0x0bfc20-0x0e04c0`: the IRAM load image and its trailer (2026-10-10)

The vendor update file ends at `0x0d2100`, but the radio's program flash is occupied up to
`0x0e04c0`. The boot stub at `0x0300c000` explains what it is: it copies flash `0x03072000..` to
SRAM `0x18000800..0x18004bfc` (initialised data), then flash **`0x030bfc20..0x030decb8` to IRAM
`0x00010000..0x0002f098`** (the SoC runtime: uC/OS-III, drivers -- `../IRAM_dm32.00.01.048.bin`
is built from exactly this, see `derive_iram.py`), zero-fills IRAM `0x2f098..0x4a7b0` and calls
`0x0002e158`. So the bytes beyond the update file's end are the tail of the IRAM image plus a short
trailer, i.e. vendor firmware identical on every unit running this build (two other units' public
dumps, on firmware 032/046, carry their own versions of it). Without them the emulator halts in
early boot. `occupied_regions.json` lists these regions; they are never erased space.

## `datachip_generic_factory_defaults.bin.xz` -- a generic emulator data chip (2026-10-14)

A 16 MB SPI-NOR image (xz -9, 3.5 KB; the `.xz.sha256` sidecar covers the compressed file; the uncompressed image's sha256 is `487b33f8940813d265db5b2db15dc5fe99c5cabaa5dadbb4de9b4c3f2788f2f2`)
for `qemu_run.py --spinor`. **It is derived purely from the generic stock firmware**: it is what the
stock firmware's own `codeplug_factory_defaults_write` (@0x03032434) writes to a blank data chip when
run under the `-M dm32` emulator, made by `tools/src/dm32_patch_tools/make_generic_datachip.py`. Same on
every unit; no per-unit data (no calibration content -- block 2 is a tag-only erased page -- no DMR ID,
no serial). Regenerate it (the output is byte-identical, checked three times) rather than trusting this
file. See `docs/qemu-workflow.md`, "A generic codeplug for the emulator".

#!/usr/bin/env python3
# /// script
# requires-python = ">=3.9"
# dependencies = []
# ///
"""Build an emulator flash image with the UI overlay trampoline installed - the worked example
this repo's docs point to for the proven hook-after-prologue trampoline pattern.

Places the assembled trampoline in a free flash region and replaces the two 16-bit instructions
right AFTER display_draw_string_gb2312's prologue (0x0301899c) with a 32-bit `bsr` to it. The hook
deliberately sits after the `push ... r15`, because a `bsr` at a function's first instruction
overwrites the caller's return address before it can be saved (confirmed the hard way during the
Snake example patch's own development - see docs/menu-system.md's own mention of this).

The trampoline is self-contained assembly (it draws the banner inline with display_fill_rect /
display_draw_string_gb2312); example_overlay.c is NOT compiled or linked by this script - it is
the same banner written in C against dm32_ui.h, kept as a reference for writing the C half of a
larger patch.

EMULATOR/OFFLINE ONLY: this patches the FULL stock image vendored at data/firmware/patching/
(see that directory's own README for why the full image, not data/firmware/DM32.00.01.048.bin,
is the right base). By default it then applies the three QEMU-only patches from
tools/src/dm32_patch_tools/compose_qemu_image.py (ALPU-bypass sector, auto-power-off NOP,
hardware-binding record) so the result boots under this repo's own QEMU (docker/README.md): the
shipped base image has its per-unit sector 0x0300b000 blanked, so the ALPU bypass alone is no
longer enough to reach standby. Pass --no-qemu-only-patches for an image carrying only the
overlay's own two changes (e.g. as stage_sectors.py's --patched input). It never touches
hardware - flashing is always a separate, explicit, human-run step on a real radio, outside
anything this repo does.

Intermediate build files (ovl.o/ovl.elf/ovl.bin) go to a temporary directory, so the repo can be
mounted read-only; only --out (and, with --iram-out, iram.bin/sram.bin beside it) is written.

Run from INSIDE this repo's Docker image (`docker compose run --rm dm32uv-re`, see
docker/README.md) so csky-abiv2-elf-gcc and friends are already on PATH; docker/cskybuild.sh is a
drop-in exec wrapper for that case (see its own docstring for why it differs from the main `dm32`
project's cskybuild.sh, which spins up a separate container instead).
"""
import argparse
import os
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, "..", ".."))
FLASHBASE = 0x03000000
HANDLER = 0x030E1000  # free region (~124KB erased, confirmed against the full stock image)
HOOK = 0x0301899C  # display_draw_string_gb2312, first insn AFTER the prologue
# the two 16-bit instructions we displace: mov r5,r2 ; zexth r6,r0 (see overlay_trampoline.S)
# NOT the prologue push: a bsr at a function's entry destroys the caller's r15.
HOOK_ORIG = bytes([0x4B, 0x6D, 0x81, 0x75])

STOCK_IMAGE = os.path.join(ROOT, "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin")

# The QEMU-only patches (and IRAM derivation) live in the tool family; reuse them rather than
# keeping a second copy of their byte-exact site assertions here.
sys.path.insert(0, os.path.join(ROOT, "tools", "src", "dm32_patch_tools"))
from compose_qemu_image import ComposeError, apply_qemu_only_patches  # noqa: E402
from derive_iram import derive as derive_iram  # noqa: E402


def bsr_bytes(src, tgt):
    """Encode a 32-bit CK803S bsr from `src` to `tgt`.

    Layout (verified against csky-abiv2-elf-objdump): opcode 0b111000 in the top 6 bits, low 26
    bits are a halfword-granular signed offset; the two halfwords are stored HIGH-halfword first,
    each little-endian - getting this backwards hangs the radio, see
    build_patch.py's encode_branch() for the full ground-truth cases this is checked against.
    """
    assert (tgt - src) % 2 == 0
    off = (tgt - src) // 2
    assert -(1 << 25) <= off < (1 << 25), "bsr target out of range"
    insn = 0xE0000000 | (off & 0x03FFFFFF)
    hi, lo = (insn >> 16) & 0xFFFF, insn & 0xFFFF
    return bytes([hi & 0xFF, (hi >> 8) & 0xFF, lo & 0xFF, (lo >> 8) & 0xFF])


def sh(cwd, *args):
    r = subprocess.run(args, cwd=cwd, capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"command failed: {' '.join(args)}\n{r.stdout}\n{r.stderr}")
    return r


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--in", dest="src", default=STOCK_IMAGE)
    ap.add_argument("--out", dest="dst", default=os.path.join(HERE, "flash_overlay.bin"))
    ap.add_argument("--asm", default=os.path.join(HERE, "overlay_trampoline.S"))
    ap.add_argument(
        "--cskybuild",
        default="cskybuild.sh",
        help="toolchain wrapper - 'cskybuild.sh' if it's on PATH (true inside this repo's "
        "Docker image), or a path to one (e.g. ../../docker/cskybuild.sh run from elsewhere)",
    )
    ap.add_argument(
        "--no-qemu-only-patches",
        action="store_true",
        help="do NOT apply compose_qemu_image.py's three QEMU-only patches; the output then "
        "differs from --in only at the hook site and the handler region",
    )
    ap.add_argument(
        "--iram-out",
        action="store_true",
        help="also write iram.bin (derived from the output image) and a zero 32KiB sram.bin "
        "next to --out, as compose_qemu_image.py --iram-out does",
    )
    args = ap.parse_args()
    asm = os.path.abspath(args.asm)

    with tempfile.TemporaryDirectory(prefix="ovl-build-") as tmp:
        sh(tmp, args.cskybuild, "csky-abiv2-elf-gcc", "-mcpu=ck803s", "-c", asm, "-o", "ovl.o")
        sh(
            tmp,
            args.cskybuild,
            "csky-abiv2-elf-ld",
            f"-Ttext={HANDLER:#x}",
            "-e",
            "overlay_trampoline",
            "-o",
            "ovl.elf",
            "ovl.o",
        )
        sh(tmp, args.cskybuild, "csky-abiv2-elf-objcopy", "-O", "binary", "-j", ".text",
           "ovl.elf", "ovl.bin")
        handler = open(os.path.join(tmp, "ovl.bin"), "rb").read()
    print(f"trampoline: {len(handler)} bytes at {HANDLER:#x}")

    stock = open(args.src, "rb").read()
    img = bytearray(stock)

    ho = HOOK - FLASHBASE
    got = bytes(img[ho : ho + 4])
    if got != HOOK_ORIG:
        sys.exit(
            f"hook site {HOOK:#x} is not the expected prologue: got {got.hex()} "
            f"expected {HOOK_ORIG.hex()} (already patched, or wrong image?)"
        )

    hf = HANDLER - FLASHBASE
    if not all(b == 0xFF for b in img[hf : hf + len(handler)]):
        sys.exit(f"handler region {HANDLER:#x} is not erased")

    img[hf : hf + len(handler)] = handler
    hook = bsr_bytes(HOOK, HANDLER)
    img[ho : ho + 4] = hook
    print(f"hook @ {HOOK:#x}: {HOOK_ORIG.hex(' ')} -> {hook.hex(' ')} (bsr -> {HANDLER:#x})")

    if args.no_qemu_only_patches:
        print("QEMU-only patches SKIPPED (--no-qemu-only-patches): this image will NOT boot "
              "under the -M dm32 model")
    else:
        # Same three patches compose_qemu_image.py applies (each asserts its stock bytes first).
        # NEVER flash these sectors (0x030c6000, 0x0301b000, 0x0300b000) to a real radio.
        try:
            for line in apply_qemu_only_patches(img):
                print(f"QEMU-only: {line}")
        except ComposeError as e:
            sys.exit(f"FAIL: {e}")

    os.makedirs(os.path.dirname(os.path.abspath(args.dst)), exist_ok=True)
    open(args.dst, "wb").write(img)
    ndiff = sum(1 for a, b in zip(stock, img) if a != b)
    print(f"wrote {args.dst} ({len(img)} bytes, {ndiff} bytes differ from {args.src})")

    if args.iram_out:
        outdir = os.path.dirname(os.path.abspath(args.dst))
        iram_dst = os.path.join(outdir, "iram.bin")
        sram_dst = os.path.join(outdir, "sram.bin")
        open(iram_dst, "wb").write(derive_iram(bytes(img)))
        open(sram_dst, "wb").write(b"\x00" * 0x8000)
        print(f"wrote {iram_dst} (derived from the output image) and {sram_dst} (32 KiB zero)")

    print("Flashing to real hardware is a separate, manual, human-run step - this only produced "
          "an image file" + ("." if args.no_qemu_only_patches else
                             " (emulator-only: it carries the QEMU-only patches)."))


if __name__ == "__main__":
    main()

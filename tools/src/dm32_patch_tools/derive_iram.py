#!/usr/bin/env python3
"""Derive the IRAM image from the stock program-flash image, exactly as the boot stub builds it.

The firmware's boot stub (flash 0x0300c000) initialises IRAM itself; its literal pool at
0x0300c0b8..0x0300c0e0 gives the ranges this module reproduces:

    copy  flash 0x030bfc20..0x030decb8  ->  IRAM 0x00010000..0x0002f098   (code + initialised data)
    zero                                    IRAM 0x0002f098..0x0004a7b0   (bss)

Everything above 0x0004a7b0 up to the end of IRAM (0x00058000) is left uninitialised by the stub;
this image fills it with zeros. The result contains only vendor firmware bytes and zeros, so it is
identical on every unit running this build - unlike a live IRAM capture, which also holds runtime
state (codeplug strings, cached calibration, stacks).

Replaces data/firmware/IRAM_dm32.00.01.048_LIVE.bin, which was a capture from one radio.

Usage:
    python3 derive_iram.py [--flash <1 MB program-flash image>] [--out <file>]
"""
import argparse
import hashlib
import pathlib
import sys

REPO_ROOT = pathlib.Path(__file__).resolve().parents[3]
DEFAULT_FLASH = REPO_ROOT / "data" / "firmware" / "patching" / "progmem_stock_DP570UV_20260926_FULL.bin"
DEFAULT_OUT = REPO_ROOT / "data" / "firmware" / "IRAM_dm32.00.01.048.bin"

FLASH_BASE = 0x03000000
IRAM_BASE = 0x00010000
IRAM_SIZE = 0x48000                     # 0x00010000..0x00057fff
LOAD_SRC = 0x030bfc20                   # flash source of the IRAM load image
LOAD_DST, LOAD_END = 0x00010000, 0x0002f098
BSS_END = 0x0004a7b0

# The stub's own literal pool, checked before trusting the ranges above against a given image.
STUB_POOL = {0x0300c0d0: LOAD_DST, 0x0300c0d4: LOAD_END, 0x0300c0d8: LOAD_SRC,
             0x0300c0dc: LOAD_END, 0x0300c0e0: BSS_END}


def derive(flash: bytes) -> bytes:
    if len(flash) < LOAD_SRC - FLASH_BASE + (LOAD_END - LOAD_DST):
        raise ValueError("flash image too short (%d bytes): need the full 1 MB program flash, not "
                         "the truncated update file" % len(flash))
    for addr, want in STUB_POOL.items():
        got = int.from_bytes(flash[addr - FLASH_BASE:addr - FLASH_BASE + 4], "little")
        if got != want:
            raise ValueError("boot-stub literal at 0x%08x is 0x%08x, expected 0x%08x: not the "
                             "DM32.00.01.048 image this module was written for" % (addr, got, want))
    iram = bytearray(IRAM_SIZE)
    n = LOAD_END - LOAD_DST
    src = LOAD_SRC - FLASH_BASE
    iram[LOAD_DST - IRAM_BASE:LOAD_DST - IRAM_BASE + n] = flash[src:src + n]
    return bytes(iram)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--flash", type=pathlib.Path, default=DEFAULT_FLASH)
    ap.add_argument("--out", type=pathlib.Path, default=DEFAULT_OUT)
    args = ap.parse_args(argv)
    try:
        iram = derive(args.flash.read_bytes())
    except (OSError, ValueError) as e:
        print("FAIL: %s" % e, file=sys.stderr)
        return 1
    args.out.write_bytes(iram)
    digest = hashlib.sha256(iram).hexdigest()
    args.out.with_name(args.out.name + ".sha256").write_text("%s  %s\n" % (digest, args.out.name))
    print("wrote %s (%d bytes, sha256 %s)" % (args.out, len(iram), digest))
    return 0


if __name__ == "__main__":
    sys.exit(main())

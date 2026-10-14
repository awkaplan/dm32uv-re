#!/usr/bin/env python3
"""Blank the per-unit parameter sector (program flash 0x0300b000-0x0300bfff) in a flash image.

WHY: that 4 KB sector is not firmware. It is written per radio and differs on every unit:

  +0x10c  u32  a value derived from the SoC's eFuse ID. Stock firmware builds it as
               data_block_checksum4(byte_table_derive_from_const_seed(<8 bytes read from the eFuse
               over SPI_Master3>)) and compares it with this record
               (channel_change_detect_reset_and_redisplay @0x0305f838); a mismatch shows an error
               screen. This is the "hardware-binding record": it is why one radio's program-flash
               image fails on another ("Incorrect HW version").
  +0x080..+0x082, +0x0a0..+0x0a1   per-unit hardware bytes read by
               hw_port_state_poll_into_ram_mirror @0x0305ef44.
  +0x000.. strings (model name and similar) on some units.

The sector is read through FUN_0002c0e0 (IRAM; flash 0x0300b000 + offset) and rewritten by IRAM
0x2c0f8, which erases it and writes back only +0x10c. Found 2026-10-10 by comparing this project's
dump with two other units' program-flash dumps (github.com/yo3hjv/Baofeng-DM32): they differ from
each other and from ours only inside this sector.

Images shipped in this repository have this sector blanked to 0xFF. A blanked record never matches,
so under QEMU compose_qemu_image.py still patches +0x10c (it already did); on a real radio the
firmware would show the binding error. NEVER flash a program-flash image over this sector of a
radio unless it is that same radio's own backup.

Usage:
    python3 scrub_unit_sector.py <image> [<image> ...]   # in place; prints old/new sha256
"""
import hashlib
import pathlib
import sys

SECTOR_OFFSET = 0xB000           # file offset in an image based at 0x03000000
SECTOR_SIZE = 0x1000


def scrub(data: bytes) -> bytes:
    if len(data) < SECTOR_OFFSET + SECTOR_SIZE:
        raise ValueError("image is %#x bytes, too short to contain the sector" % len(data))
    if data[:4] != b"thd\x0c":
        raise ValueError("no DH_FLAG 'thd\\x0c' at offset 0: not a program-flash image based at 0x03000000")
    out = bytearray(data)
    out[SECTOR_OFFSET:SECTOR_OFFSET + SECTOR_SIZE] = b"\xff" * SECTOR_SIZE
    return bytes(out)


def main(argv) -> int:
    if not argv:
        print(__doc__)
        return 2
    for p in map(pathlib.Path, argv):
        data = p.read_bytes()
        try:
            new = scrub(data)
        except ValueError as e:
            print("FAIL %s: %s" % (p, e), file=sys.stderr)
            return 1
        p.write_bytes(new)
        print("%s\n  before %s\n  after  %s" % (p, hashlib.sha256(data).hexdigest(),
                                                hashlib.sha256(new).hexdigest()))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

#!/usr/bin/env python3
"""Build a GENERIC SPI-NOR data-chip image for the -M dm32 emulator by letting the stock firmware
write its own factory-default codeplug.

WHY: the emulated 16 MB W25Q128 data chip starts blank (0xFF), so stock boots to "Null Ch." with no
channels, and every patch test that needs a channel cannot run. The repo forbids using a real
radio's dump. The stock firmware contains `codeplug_factory_defaults_write` @0x03032434
(src/codeplug/, void, no args): it erases and rewrites the codeplug blocks with constants that live
in the firmware image itself (16 channels "Channel N", default zone/talk-group/settings blocks).
Whatever that routine writes is derived purely from the generic stock image and is identical on
every unit, so it is allowed here (CLAUDE.md "Safety"). It contains NO per-unit data: no
calibration page (block 2), no DMR ID, no serial number.

ROUTE A (implemented here): boot stock under QEMU with `-s`, wait for standby, interrupt the CPU
over the gdb stub (RSP ^C), save the registers, hijack the CPU to call
codeplug_factory_defaults_write(void) with sp in the SRAM scratch window and lr = a sentinel
address that has a hardware breakpoint (same technique as crypto_kat.py / mi_rng_test.py), restore
the registers, continue, then SIGTERM QEMU. QEMU (gap/ssi-persist branch) writes the store to
DM32_SPINOR_OUT at exit. The scheduler keeps running during the call, so the RTOS-synchronised
flash driver and the LCD redraws behave as in a real reset.
ROUTE B (fallback, not implemented): drive the UI "reset to factory defaults" confirmation with
DM32_KEYSEQ (qemu_run.py KEYS table); the routine's callers are FUN_03014a54 / FUN_030156f4, gated
on bit 2 of a UI state byte. Needs the menu path traced first.

Refuses to run when DM32_SPINOR is set: the base store must be blank so the result is purely what
the firmware wrote.

USAGE (inside the QEMU container; needs qemu-system-cskyv2 from the ssi-persist build):
  python3 make_generic_datachip.py --out datachip_generic.bin
  python3 qemu_run.py --image <boot.bin> --spinor datachip_generic.bin ...
"""
import argparse
import hashlib
import os
import pathlib
import signal
import subprocess
import struct
import sys
import tempfile
import time

from crypto_kat import RspClient, setreg, sram_image
from gdb_rsp import read_pc

REPO_ROOT = pathlib.Path(__file__).resolve().parents[3]
HERE = pathlib.Path(__file__).resolve().parent
FUNC = 0x03032434                 # codeplug_factory_defaults_write
SENTINEL = 0x000169D4             # br16 . in IRAM (ALPU-failure loop); never reached once bypassed
STACK = 0x18007B00                # SRAM scratch window, unclaimed (dm32uv-patches allocations.json)
PAGE = 0x1000

# Page tag byte (+0xFFF) -> block name, from the corpus / infamy protocol spec / this routine.
def block_name(tag):
    """Logical block id -> name, per infamy's DM32-Protocol-Spec 07-BLOCK-INVENTORY.md (ranges) and
    this project's block-2 finding. Ids outside these ranges are left unnamed rather than guessed."""
    if tag == 0x02:
        return "block 2 = per-unit calibration slot (tag only here; content never fabricated)"
    if 0x12 <= tag <= 0x41:
        return "channel bank %d" % (tag - 0x11)
    if 0x44 <= tag <= 0x48:
        return "talk-group page %d" % (tag - 0x43)
    if 0x5C <= tag <= 0x64:
        return "zone page %d" % (tag - 0x5B)
    return ""


def inventory(img):
    out = []
    for p in range(len(img) // PAGE):
        pg = img[p * PAGE:(p + 1) * PAGE]
        if pg.count(0xFF) != PAGE:
            out.append((p, PAGE - pg.count(0xFF), pg[0xFFF]))
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--qemu", default="qemu-system-cskyv2")
    ap.add_argument("--image", type=pathlib.Path, default=None,
                    help="boot image (default: compose the stock one with compose_qemu_image.py)")
    ap.add_argument("--iram", type=pathlib.Path, default=None,
                    help="IRAM image (default: iram.bin composed alongside, else data/firmware/IRAM_dm32.00.01.048.bin)")
    ap.add_argument("--out", required=True, type=pathlib.Path)
    ap.add_argument("--timeout", type=float, default=240, help="overall seconds (default 240)")
    ap.add_argument("--boot-seconds", type=float, default=40, help="wall seconds to let stock boot to standby")
    ap.add_argument("--port", type=int, default=1234)
    a = ap.parse_args()
    if os.environ.get("DM32_SPINOR"):
        sys.exit("DM32_SPINOR is set; the base store must start blank. Unset it.")
    work = pathlib.Path(tempfile.mkdtemp(prefix="gen_datachip_"))
    img, iram = a.image, a.iram
    if img is None:
        img = work / "img.bin"
        subprocess.run([sys.executable, str(HERE / "compose_qemu_image.py"), "--out", str(img), "--iram-out"],
                       check=True, capture_output=True)
        iram = iram or work / "iram.bin"
    iram = iram or REPO_ROOT / "data/firmware/IRAM_dm32.00.01.048.bin"
    # real SRAM-init image (the 0x43fc-byte init at flash 0x72000 -> SRAM 0x800), not zeros
    import crypto_kat
    crypto_kat.FLASH = img                      # sram_image() reads FLASH
    sram = sram_image(str(work))
    raw = work / "raw.bin"
    cmd = [a.qemu, "-M", "dm32", "-cpu", "ck803", "-display", "none", "-monitor", "none", "-serial", "null",
           "-s", "-kernel", str(img), "-device", f"loader,file={iram},addr=0x00010000",
           "-device", f"loader,file={sram},addr=0x18000000"]
    log = open(work / "qemu.log", "w")
    env = dict(os.environ, DM32_SPINOR_OUT=str(raw))
    proc = subprocess.Popen(cmd, stdout=log, stderr=subprocess.STDOUT, env=env)
    t0 = time.time()
    try:
        c = None
        for _ in range(100):
            try:
                c = RspClient("127.0.0.1", a.port, timeout=120); break
            except OSError:
                time.sleep(0.1)
        if c is None:
            sys.exit("gdb stub never came up; see %s/qemu.log" % work)
        c.command("?")
        c.send_packet("c")
        time.sleep(a.boot_seconds)
        c.sock.sendall(b"\x03"); c.read_packet()
        saved = c.command("g")
        pc0, _ = read_pc(c)
        print(f"boot {time.time()-t0:.0f}s, interrupted at pc={pc0:#x}")
        # hijack: call codeplug_factory_defaults_write(); lr = sentinel with a HW breakpoint
        setreg(c, 14, STACK)
        setreg(c, 15, SENTINEL)
        setreg(c, 0x48, FUNC)
        c.command("Z1,%x,2" % SENTINEL)
        c.send_packet("c")
        c.sock.settimeout(max(5, a.timeout - (time.time() - t0)))
        c.read_packet()
        pc, _ = read_pc(c)
        if pc != SENTINEL:
            sys.exit(f"stopped at {pc:#x}, not the sentinel; see {work}/qemu.log")
        print(f"codeplug_factory_defaults_write returned after {time.time()-t0:.0f}s")
        c.command("z1,%x,2" % SENTINEL)
        r = c.command("G" + saved)              # restore every register incl. pc
        print("register restore:", r)
        c.send_packet("c")
        time.sleep(3)                           # let the firmware settle (flash writes were synchronous)
    finally:
        proc.send_signal(signal.SIGTERM)
        try:
            proc.wait(timeout=60)
        except subprocess.TimeoutExpired:
            proc.kill()
    if not raw.exists():
        sys.exit(f"no store written; see {work}/qemu.log")
    data = raw.read_bytes()
    a.out.write_bytes(data)
    print("wrote", a.out, len(data), "bytes; sha256", hashlib.sha256(data).hexdigest())
    inv = inventory(data)
    print(f"{len(inv)} touched 4 KB pages (page index, flash addr, non-FF bytes, tag@+0xFFF):")
    for p, n, tag in inv:
        print(f"  page {p:5d}  0x{p*PAGE:06x}  {n:4d}  tag 0x{tag:02x} {block_name(tag)}")
    print("work dir:", work)


if __name__ == "__main__":
    main()

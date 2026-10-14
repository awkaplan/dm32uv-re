"""Boot stock firmware under -M dm32 and sample the libc rand() state (SRAM 0x18000c2c) once a
second, reporting k such that state == LCG^k(1) - the number of rand() calls made since the
compiled-in initial value 1.

WHY: the DMR-privacy TX message indicator (MI) is drawn from rand() (see docs/encryption.md).
srand (0x0306fec0) has no caller anywhere in flash or IRAM; this is the dynamic confirmation.
If the firmware seeded the generator from anything (timer, ADC, eFuse ID), the sampled state
would not be a small number of LCG steps from 1, and two boots would disagree.

CAVEAT: the image is compose_qemu_image.py's emulator-bootable composition, which bypasses the
ALPU anti-clone exchange (itself a rand() consumer), so a real radio's k at standby can differ
from the emulator's. What carries over is that k is deterministic, not its value.

USAGE (inside the image):
  docker run --rm -v "$(git rev-parse --show-toplevel)":/repo -w /repo/tools/src/dm32_patch_tools \\
      dm32uv-re-pipeline -c 'python3 rng_seed_probe.py --seconds 20'
"""
import argparse
import os
import pathlib
import struct
import subprocess
import sys
import tempfile
import time

from gdb_rsp import RspClient, read_mem

REPO_ROOT = pathlib.Path(__file__).resolve().parents[3]
FLASH = REPO_ROOT / "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin"
HERE = pathlib.Path(__file__).resolve().parent
RAND_STATE = 0x18000C2C
LCG_A, LCG_C = 1103515245, 12345


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seconds", type=int, default=20)
    args = ap.parse_args()

    w = tempfile.mkdtemp(prefix="rng_probe_")
    subprocess.run([sys.executable, str(HERE / "compose_qemu_image.py"), "--out", w + "/img.bin",
                    "--iram-out"], check=True, capture_output=True)
    iram = w + "/iram.bin"
    p = FLASH.read_bytes()
    sram = bytearray(0x8000)
    sram[0x800:0x800 + 0x43FC] = p[0x72000:0x763FC]
    open(w + "/sram.bin", "wb").write(sram)
    q = subprocess.Popen(["qemu-system-cskyv2", "-M", "dm32", "-cpu", "ck803", "-display", "none",
                          "-monitor", "none", "-serial", "null", "-s", "-kernel", w + "/img.bin",
                          "-device", f"loader,file={iram},addr=0x00010000",
                          "-device", f"loader,file={w}/sram.bin,addr=0x18000000"],
                         stdout=open(w + "/qemu.log", "w"), stderr=subprocess.STDOUT,
                         env=dict(os.environ, DM32_ADC_CH2="0x300"))
    steps, s = {}, 1
    for k in range(200001):
        steps.setdefault(s, k)
        s = (s * LCG_A + LCG_C) & 0xFFFFFFFF
    time.sleep(1)
    try:
        c = RspClient("127.0.0.1", 1234, timeout=30)
        c.command("?")
        c.send_packet("c")
        for t in range(args.seconds):
            time.sleep(1)
            c.sock.sendall(b"\x03")
            c.read_packet()
            st = struct.unpack("<I", read_mem(c, RAND_STATE, 4))[0]
            c.send_packet("c")
            k = steps.get(st, "NOT within 200000 LCG steps of seed 1 - seeded?")
            print(f"t={t + 1:3d}s rand_state={st:#010x} k={k}", flush=True)
        c.close()
    finally:
        q.kill()


if __name__ == "__main__":
    main()

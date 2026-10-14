"""Known-answer test of the stock firmware's own DMR-privacy crypto, executed instruction-for-
instruction by the -M dm32 QEMU model (the real CK803S code, not a re-implementation).

WHAT IT CHECKS (see docs/encryption.md for why each one matters):
  1. aes_key_schedule_expand + aes_block_encrypt against FIPS-197 C.1
     (AES-128) and C.3 (AES-256), and against OpenSSL for a second AES-256 key.
  2. The MI -> 128-bit IV expansion (corpus name "dmr_privacy_mi_expand_lfsr", really a 32-bit LFSR,
     taps 32,22,2,1) against a Python reference.
  3. The 128-byte AES voice keystream generator (corpus name "dmr_privacy_aes_ofb_keystream_128", really
     AES-OFB with the first output block skipped) against OpenSSL.
  4. The whole TX setup + apply path (IRAM 0x15bd4 / 0x15918) on a scratch context: with
     internal id 5 the applied keystream equals the OpenSSL model (positive control), and with
     internal id 2 (the "DES-style" path) the data comes back UNCHANGED, because its three block
     routines (FUN_030cd0d8/dc/e4) are `rts` stubs; whatever sits at ctx+0x340..0x347 is XORed in
     instead (checked with a marker). Algorithm 2 is not a cipher in this build.

METHOD: QEMU is started halted (-S) with the flash, IRAM and SRAM-init images preloaded - no
boot at all, so nothing but the routine under test runs. Each call writes its inputs to scratch
IRAM, sets a0..a3/sp/lr/pc over the gdb stub, continues, and waits for pc to reach the IRAM
fatal-halt loop at 0x169d4 (`br16 .`), which lr points at as a return sentinel. The crypto code
lives in the IRAM load image (flash 0x030bfc20.. copied to 0x00010000), so every flash-view
corpus address is translated by IRAM_DELTA before being called.

USAGE (inside the image; needs qemu-system-cskyv2 and openssl):
  docker run --rm -v "$(git rev-parse --show-toplevel)":/repo -w /repo/tools/src/dm32_patch_tools \\
      dm32uv-re-pipeline -c 'python3 crypto_kat.py'
Exit status 0 iff every check passes.
"""
import os
import pathlib
import struct
import subprocess
import sys
import tempfile
import time

from gdb_rsp import RspClient, read_mem, read_pc

REPO_ROOT = pathlib.Path(__file__).resolve().parents[3]
FLASH = REPO_ROOT / "data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin"
IRAM = REPO_ROOT / "data/firmware/IRAM_dm32.00.01.048.bin"

IRAM_DELTA = 0x030BFC20 - 0x00010000       # flash-view address -> IRAM execution address
AES_KS = 0x030CCBCC - IRAM_DELTA           # aes_key_schedule_expand(key, sched, Nk, Nr)
AES_ENC = 0x030CCC9C - IRAM_DELTA          # aes_block_encrypt(in, out, sched, Nr)
MI_EXPAND = 0x030CD000 - IRAM_DELTA        # "dmr_privacy_mi_expand_lfsr"(mi4, out, nwords)
OFB_GEN = 0x030CD08C - IRAM_DELTA          # "dmr_privacy_aes_ofb_keystream_128"(alg, iv16, sched, out128)
TX_SETUP = 0x030C57F4 - IRAM_DELTA         # "dmr_privacy_tx_keystream_setup"(mode, ctx)
APPLY = 0x030C5538 - IRAM_DELTA            # "dmr_privacy_keystream_apply"(ctx, buf, len)
CTX_SIZE = 0x3C0                           # TX context: [0] id, [1] key id, +2 key, +0x22 MI, +0x338 keystream
SENTINEL = 0x000169D4                      # br16 0x169d4 (the ALPU-failure while(1))
STACK = 0x0002F800                         # above the IRAM load image; nothing else runs
BUF = 0x0002FA00                           # scratch buffers


def sram_image(workdir):
    """SRAM as the boot stub would leave it: flash 0x03072000.. copied to 0x18000800. The AES
    S-box and Rcon live in this initialised data (S-box at SRAM 0x1800119c)."""
    p = FLASH.read_bytes()
    img = bytearray(0x8000)
    init = p[0x72000:0x763FC]
    img[0x800:0x800 + len(init)] = init
    path = os.path.join(workdir, "sram.bin")
    open(path, "wb").write(img)
    return path


def start_qemu(workdir):
    cmd = ["qemu-system-cskyv2", "-M", "dm32", "-cpu", "ck803", "-display", "none",
           "-monitor", "none", "-serial", "null", "-S", "-s", "-kernel", str(FLASH),
           "-device", f"loader,file={IRAM},addr=0x00010000",
           "-device", f"loader,file={sram_image(workdir)},addr=0x18000000"]
    log = open(os.path.join(workdir, "qemu.log"), "w")
    proc = subprocess.Popen(cmd, stdout=log, stderr=subprocess.STDOUT)
    for _ in range(100):
        try:
            return proc, RspClient("127.0.0.1", 1234, timeout=10)
        except OSError:
            time.sleep(0.1)
    proc.kill()
    sys.exit("QEMU gdb stub never came up; see %s/qemu.log" % workdir)


def setreg(c, n, v):
    r = c.command("P%x=%s" % (n, struct.pack("<I", v).hex()))
    if r != "OK":
        sys.exit(f"P{n:x} failed: {r!r}")


def write_mem(c, addr, data):
    r = c.command("M%x,%x:%s" % (addr, len(data), data.hex()))
    if r != "OK":
        sys.exit(f"M {addr:#x} failed: {r!r}")


def call(c, fn, *args):
    for i, a in enumerate(args):
        setreg(c, i, a)                     # a0..a3 = r0..r3
    setreg(c, 14, STACK)                    # sp
    setreg(c, 15, SENTINEL)                 # lr
    setreg(c, 0x48, fn)                     # pc (register 72 on this stub)
    c.send_packet("c")
    pc = None
    deadline = time.time() + 20
    while time.time() < deadline:
        time.sleep(0.05)
        c.sock.sendall(b"\x03")
        c.read_packet()
        pc, _ = read_pc(c)
        if pc == SENTINEL:
            return
        c.send_packet("c")
    sys.exit(f"call {fn:#x} did not return (pc={pc})")


def openssl_ecb(key, block):
    alg = {16: "aes-128-ecb", 32: "aes-256-ecb"}[len(key)]
    return subprocess.run(["openssl", "enc", "-" + alg, "-nopad", "-K", key.hex()],
                          input=block, capture_output=True, check=True).stdout


def lfsr_expand(mi, nwords):
    """Reference model: MI || L(MI) || L^2(MI) ..., L = 32 steps of taps 32,22,2,1."""
    v = int.from_bytes(mi, "big")
    out = bytearray(mi)
    for _ in range(nwords):
        for _ in range(32):
            fb = (v >> 31) ^ (v >> 21) ^ (v >> 1) ^ v
            v = ((v << 1) | (fb & 1)) & 0xFFFFFFFF
        out += v.to_bytes(4, "big")
    return bytes(out)


def main():
    workdir = tempfile.mkdtemp(prefix="crypto_kat_")
    proc, c = start_qemu(workdir)
    ok = True

    def report(res, msg):
        nonlocal ok
        ok &= res
        print(("PASS  " if res else "FAIL  ") + msg)

    try:
        key_in, sched, pt, ct, iv_buf, ks_buf = (BUF + o for o in (0, 0x40, 0x140, 0x160, 0x180, 0x1C0))
        block = bytes.fromhex("00112233445566778899aabbccddeeff")
        for name, key, nk, nr, want in (
                ("FIPS-197 C.1 AES-128", bytes(range(16)), 4, 10, "69c4e0d86a7b0430d8cdb78070b4c55a"),
                ("FIPS-197 C.3 AES-256", bytes(range(32)), 8, 14, "8ea2b7ca516745bfeafc49904b496089")):
            write_mem(c, key_in, key.ljust(32, b"\0"))
            write_mem(c, pt, block)
            call(c, AES_KS, key_in, sched, nk, nr)
            call(c, AES_ENC, pt, ct, sched, nr)
            got = read_mem(c, ct, 16).hex()
            report(got == want, f"{name}: got {got} want {want}")

        key = bytes.fromhex("603deb1015ca71be2b73aef0857d77811f352c073b6108d72d9810a30914dff4")
        blk = bytes.fromhex("6bc1bee22e409f96e93d7e117393172a")
        write_mem(c, key_in, key)
        write_mem(c, pt, blk)
        call(c, AES_KS, key_in, sched, 8, 14)
        call(c, AES_ENC, pt, ct, sched, 14)
        got = read_mem(c, ct, 16)
        report(got == openssl_ecb(key, blk), f"AES-256 vs OpenSSL (SP800-38A key): {got.hex()}")

        mi = bytes.fromhex("53734a9e")
        write_mem(c, iv_buf, mi + bytes(12))
        call(c, MI_EXPAND, iv_buf, iv_buf + 0x20, 3)
        iv = read_mem(c, iv_buf + 0x20, 16)
        report(iv == lfsr_expand(mi, 3), f"MI {mi.hex()} -> IV {iv.hex()} (LFSR taps 32,22,2,1)")

        call(c, OFB_GEN, 5, iv_buf + 0x20, sched, ks_buf)
        ks = read_mem(c, ks_buf, 128)
        t, ref = openssl_ecb(key, iv), b""
        for _ in range(8):
            t = openssl_ecb(key, t)
            ref += t
        report(ks == ref, "128-byte keystream == E^2(IV)..E^9(IV) (AES-OFB, first block skipped)")

        # 4. full TX path on a scratch context. Apply re-derives the IV from the CURRENT MI (as
        # left by setup, which advances it once), computes t = E(IV) into ctx+0x338 and XORs
        # E(t) = E^2(IV) into the data (first OFB block skipped, as in the keystream generator).
        ctx, data = BUF + 0x400, BUF + 0x800
        plain = bytes(range(0x30, 0x40))
        c_init = bytearray(CTX_SIZE)
        c_init[0] = 5
        c_init[2:34] = key
        c_init[0x22:0x26] = mi
        write_mem(c, ctx, bytes(c_init))
        call(c, TX_SETUP, 1, ctx)
        mi_after = read_mem(c, ctx + 0x22, 4)
        write_mem(c, data, plain)
        call(c, APPLY, ctx, data, 16)
        got = read_mem(c, data, 16)
        iv2 = lfsr_expand(mi_after, 3)
        want = bytes(a ^ b for a, b in zip(plain, openssl_ecb(key, openssl_ecb(key, iv2))))
        report(mi_after == lfsr_expand(mi, 1)[4:] and got == want,
               f"id 5 TX setup+apply: MI advanced to L(MI) = {mi_after.hex()}, data ^ E^2(IV) matches OpenSSL")

        for marker in (bytes(8), bytes(range(8, 16))):
            c_init = bytearray(CTX_SIZE)
            c_init[0] = 2
            c_init[2:9] = bytes.fromhex("1234567890abcd")
            c_init[0x22:0x26] = mi
            c_init[0x340:0x348] = marker
            write_mem(c, ctx, bytes(c_init))
            call(c, TX_SETUP, 1, ctx)
            ks_region = read_mem(c, ctx + 0x338, 16)
            write_mem(c, data, plain)
            call(c, APPLY, ctx, data, 16)
            got = read_mem(c, data, 16)
            want = bytes(p ^ marker[i % 8] for i, p in enumerate(plain))
            report(ks_region == bytes(8) + marker and got == want,
                   f"id 2 (\"DES\"): stubs wrote nothing, data ^ marker {marker.hex()} repeated "
                   f"({'PLAINTEXT' if marker == bytes(8) else 'stale bytes'})")
    finally:
        c.close()
        proc.kill()
    print("ALL PASS" if ok else "FAILURES")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()

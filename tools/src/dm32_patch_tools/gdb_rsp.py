"""A tiny GDB Remote Serial Protocol client for this project's QEMU `-s` stub (vendor/csky-qemu's
gdbstub, port 1234 by default).

WHY THIS EXISTS AS ITS OWN SCRIPT, NOT "JUST USE GDB": a full GDB needs this target's own
csky-elf support built and configured (the Docker image's toolchain deliberately omits gdb) just
to attach - a heavyweight, host-specific dependency for what is often a one-off "is pc stuck at
the fatal halt or past it" check. Talking the wire protocol directly needs nothing but a TCP
socket, and this project already has two ground-truth facts about how this exact gdbstub answers
that a generic GDB build would get right anyway but this script has to get right ITSELF:

1. THE 'g' (READ ALL REGISTERS) REPLY'S WORD LAYOUT IS TARGET-SPECIFIC. The C-SKY gdbstub
   (inherited from c-sky/qemu; vendor/csky-qemu/docs/PORT-NOTES.md "gdbstub" keeps the same byte
   layout) skips zero-length registers, so the concatenated 32-bit words in a 'g' reply are:
   words 0-31 = r0-r31, word 130 = pc, word 147 = psr, word 148 = vbr, word 149 = epsr,
   word 151 = epc. This is NOT the generic "pc is register 15" assumption a normal target.xml
   would give you.
2. 'p48' (PC AS REGISTER 72) SOMETIMES WORKS INSTEAD. Try it first; if the reply is exactly 8
   hex digits and non-empty, trust it (word-130 extraction is skipped and the method used is
   printed). Otherwise fall back to the word-130 rule from (1).

READ THIS BEFORE USING `watch` OR `crashwait`: attaching to a live QEMU guest halts it briefly
(the stub stops the vCPU to answer), and a `Z2` write watchpoint changes timing further - it
defeats TCG's translation-block chaining for the watched page, so a timing-dependent bug that
only reproduces WITH chaining intact can vanish the moment you watch it. A clean run under
`watch`/`crashwait` is evidence about the watched address, not proof the unwatched system
behaves identically.

Subcommands:
    regs                              print pc, sp, lr, psr, r0-r7
    mem ADDR LEN [--words]            hex dump (chunks of <= 0x100 bytes per 'm' packet)
    watch ADDR LEN (--until-zero|--until-nonzero|--count N) [--dump ADDR,LEN ...]
    crashwait [--interval 20] [--dump ADDR,LEN ...]
"""
from __future__ import annotations

import argparse
import socket
import sys
import time

DEFAULT_PORT = 1234

# Fixed by the C-SKY gdbstub's register-skip behavior (see module docstring).
WORD_PC = 130
WORD_PSR = 147
WORD_VBR = 148
WORD_EPSR = 149
WORD_EPC = 151


class RspError(Exception):
    pass


class RspClient:
    def __init__(self, host: str, port: int, timeout: float = 5.0):
        self.sock = socket.create_connection((host, port), timeout=timeout)
        self.sock.settimeout(timeout)
        # Without TCP_NODELAY the '+' ack and the next '$...' command are two small writes, and
        # Nagle holds the second until the peer ACKs the first (delayed ~40 ms): measured 45 ms
        # per command -> 0.1 ms with this set and reads buffered (2026-11-01).
        self.sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        self._buf = b""

    def close(self) -> None:
        self.sock.close()

    def _checksum(self, data: str) -> str:
        return format(sum(data.encode()) & 0xFF, "02x")

    def send_packet(self, data: str) -> None:
        pkt = f"${data}#{self._checksum(data)}"
        self.sock.sendall(pkt.encode())

    def _fill(self) -> None:
        b = self.sock.recv(4096)
        if not b:
            raise RspError("connection closed while reading")
        self._buf += b

    def _read_byte(self) -> bytes:
        if not self._buf:
            self._fill()
        b, self._buf = self._buf[:1], self._buf[1:]
        return b

    def read_packet(self) -> str:
        """Read one $...#cc packet, ack it, and return its payload. Skips a leading '+'/'-' ack
        byte if the stub sends one before the packet."""
        c = self._read_byte()
        while c in (b"+", b"-"):
            c = self._read_byte()
        if c != b"$":
            raise RspError(f"expected '$', got {c!r}")
        payload = b""
        while True:
            i = self._buf.find(b"#")
            if i >= 0:
                payload += self._buf[:i]
                self._buf = self._buf[i + 1:]
                break
            payload += self._buf
            self._buf = b""
            self._fill()
        while len(self._buf) < 2:  # checksum, consumed, not verified
            self._fill()
        self._buf = self._buf[2:]
        self.sock.sendall(b"+")
        return payload.decode(errors="replace")

    def command(self, data: str) -> str:
        self.send_packet(data)
        return self.read_packet()

    def command_skip_stop_replies(self, data: str) -> str:
        """Send a command and keep reading replies until one that doesn't look like a stray
        stop-reply packet (T02/T05/...), for commands issued right after a 'c' (continue) where
        the stub can interleave an unsolicited stop notification before the real data reply."""
        self.send_packet(data)
        while True:
            reply = self.read_packet()
            if reply.startswith("T") and len(reply) <= 4:
                continue
            return reply


def parse_g_reply(hexstr: str) -> dict:
    """Parse a 'g' packet reply into {"r0".."r31", "pc", "psr", "vbr", "epsr", "epc"} using the
    fork's fixed word layout (see module docstring). Each register is 4 bytes = 8 hex chars,
    stored little-endian in the wire format."""
    words = []
    for i in range(0, len(hexstr) - 7, 8):
        chunk = hexstr[i:i + 8]
        if len(chunk) < 8 or any(c not in "0123456789abcdefABCDEF" for c in chunk):
            break
        b = bytes.fromhex(chunk)
        words.append(int.from_bytes(b, "little"))

    regs = {}
    for i in range(32):
        regs[f"r{i}"] = words[i] if i < len(words) else None
    regs["pc"] = words[WORD_PC] if len(words) > WORD_PC else None
    regs["psr"] = words[WORD_PSR] if len(words) > WORD_PSR else None
    regs["vbr"] = words[WORD_VBR] if len(words) > WORD_VBR else None
    regs["epsr"] = words[WORD_EPSR] if len(words) > WORD_EPSR else None
    regs["epc"] = words[WORD_EPC] if len(words) > WORD_EPC else None
    return regs


def read_pc(client: RspClient) -> tuple[int | None, str]:
    """Try 'p48' first (register 72 = pc in some stub builds); fall back to the 'g'-reply
    word-130 rule. Returns (pc_or_None, method_used)."""
    try:
        reply = client.command("p48")
    except RspError:
        reply = ""
    reply = reply.strip()
    if reply and len(reply) == 8 and all(c in "0123456789abcdefABCDEF" for c in reply):
        pc = int.from_bytes(bytes.fromhex(reply), "little")
        return pc, "p48"

    g_reply = client.command("g")
    regs = parse_g_reply(g_reply)
    return regs.get("pc"), "g-word130"


def read_all_regs(client: RspClient) -> dict:
    g_reply = client.command("g")
    regs = parse_g_reply(g_reply)
    pc, method = read_pc(client)
    regs["pc"] = pc
    regs["_pc_method"] = method
    return regs


def fmt_reg(v: int | None) -> str:
    return "????????" if v is None else f"{v:08x}"


def print_regs(regs: dict) -> None:
    print(f"pc  = {fmt_reg(regs.get('pc'))}  (via {regs.get('_pc_method', '?')})")
    print(f"sp  = {fmt_reg(regs.get('r14'))}   lr  = {fmt_reg(regs.get('r15'))}")
    print(f"psr = {fmt_reg(regs.get('psr'))}")
    for i in range(8):
        print(f"r{i}  = {fmt_reg(regs.get(f'r{i}'))}")


def read_mem(client: RspClient, addr: int, length: int) -> bytes:
    out = bytearray()
    off = 0
    while off < length:
        chunk = min(0x100, length - off)
        reply = client.command(f"m{addr+off:x},{chunk:x}")
        if reply.startswith("E"):
            raise RspError(f"m packet error reading {addr+off:#x},{chunk:#x}: {reply}")
        out += bytes.fromhex(reply)
        off += chunk
    return bytes(out)


def dump_mem(client: RspClient, addr: int, length: int, words: bool) -> None:
    data = read_mem(client, addr, length)
    print(f"mem {addr:#010x} len {length:#x}:")
    print("  " + data.hex(" "))
    if words:
        for i in range(0, len(data) - 3, 4):
            w = int.from_bytes(data[i:i + 4], "little")
            print(f"  {addr+i:#010x}: {w:#010x}")


def parse_dump_args(dump_args: list[str]) -> list[tuple[int, int]]:
    out = []
    for spec in dump_args:
        try:
            a, l = spec.split(",")
            out.append((int(a, 0), int(l, 0)))
        except ValueError:
            raise SystemExit(f"--dump must be ADDR,LEN, got {spec!r}")
    return out


def cmd_regs(client: RspClient, args) -> int:
    print_regs(read_all_regs(client))
    return 0


def cmd_mem(client: RspClient, args) -> int:
    dump_mem(client, args.addr, args.length, args.words)
    return 0


def cmd_watch(client: RspClient, args) -> int:
    print(f"NOTE: setting a write watchpoint changes guest timing and can hide "
          f"chaining-dependent bugs - see module docstring.", file=sys.stderr)
    reply = client.command(f"Z2,{args.addr:x},{args.length:x}")
    if reply != "OK":
        raise RspError(f"failed to set watchpoint: {reply}")

    count = 0
    while True:
        reply = client.command_skip_stop_replies("c")
        count += 1
        value_bytes = read_mem(client, args.addr, args.length)
        value = int.from_bytes(value_bytes, "little")
        print(f"stop #{count} (reply={reply!r}): value @ {args.addr:#x} = {value:#x}")

        if args.until_zero and value == 0:
            break
        if args.until_nonzero and value != 0:
            break
        if args.count is not None and count >= args.count:
            break

    client.command(f"z2,{args.addr:x},{args.length:x}")
    print_regs(read_all_regs(client))
    for a, l in parse_dump_args(args.dump):
        dump_mem(client, a, l, False)
    return 0


def cmd_crashwait(client: RspClient, args) -> int:
    while True:
        regs = read_all_regs(client)
        pc, sp = regs.get("pc"), regs.get("r14")
        print(f"pc={fmt_reg(pc)} sp={fmt_reg(sp)}")
        client.send_packet("D")
        try:
            client.read_packet()
        except RspError:
            pass

        if pc == 0 or (sp is not None and sp > 0xF0000000):
            print("CRASH-LIKE STATE DETECTED (pc==0 or sp > 0xf0000000):")
            print_regs(regs)
            for a, l in parse_dump_args(args.dump):
                dump_mem(client, a, l, False)
            return 1

        time.sleep(args.interval)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--host", default="localhost")
    ap.add_argument("--port", type=int, default=DEFAULT_PORT)
    sub = ap.add_subparsers(dest="cmd", required=True)

    sub.add_parser("regs", help="print pc, sp, lr, psr, r0-r7")

    p_mem = sub.add_parser("mem", help="read and hex-dump guest memory")
    p_mem.add_argument("addr", type=lambda s: int(s, 0))
    p_mem.add_argument("length", type=lambda s: int(s, 0))
    p_mem.add_argument("--words", action="store_true", help="also print as 32-bit LE words with addresses")

    p_watch = sub.add_parser("watch", help="set a write watchpoint and continue until a condition")
    p_watch.add_argument("addr", type=lambda s: int(s, 0))
    p_watch.add_argument("length", type=lambda s: int(s, 0))
    grp = p_watch.add_mutually_exclusive_group(required=True)
    grp.add_argument("--until-zero", action="store_true")
    grp.add_argument("--until-nonzero", action="store_true")
    grp.add_argument("--count", type=int, default=None, help="stop after N watchpoint hits regardless of value")
    p_watch.add_argument("--dump", action="append", default=[], metavar="ADDR,LEN",
                          help="memory range to dump once stopped (repeatable)")

    p_crash = sub.add_parser("crashwait", help="poll pc/sp periodically; report and exit 1 on a crash-like state")
    p_crash.add_argument("--interval", type=float, default=20, help="seconds between polls (default 20)")
    p_crash.add_argument("--dump", action="append", default=[], metavar="ADDR,LEN",
                          help="memory range to dump on crash detection (repeatable)")

    args = ap.parse_args()

    client = RspClient(args.host, args.port)
    try:
        if args.cmd == "regs":
            rc = cmd_regs(client, args)
        elif args.cmd == "mem":
            rc = cmd_mem(client, args)
        elif args.cmd == "watch":
            rc = cmd_watch(client, args)
        elif args.cmd == "crashwait":
            rc = cmd_crashwait(client, args)
        else:
            raise SystemExit(f"unknown subcommand {args.cmd!r}")
    except RspError as e:
        print(f"FAIL: {e}", file=sys.stderr)
        sys.exit(1)
    finally:
        client.close()
    sys.exit(rc)


if __name__ == "__main__":
    main()

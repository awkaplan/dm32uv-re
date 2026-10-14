#!/usr/bin/env python3
"""Drive the DM32.PATCH live-RAM-read command (0x56 sub-id 0x40) to dump arbitrary RAM from the
RUNNING firmware over UART0 — requires the ramdump patch to be flashed first. Reads in <=0x80-byte
chunks and reassembles.

Wire protocol (matches the patched firmware handler):
  host -> 56 00 00 00 40            (0x56 vframe, sub-id 0x40 = RAMDUMP)
  host -> AA AA AA AA LL LL         (4-byte BE address + 2-byte BE length, <=0x80)
  dev  -> 56 40 LL <LL data bytes>  (standard vframe response)

SAFETY: read-only w.r.t. the radio (issues a read command; performs no writes/erases). The patch
itself is a separate, already-authorized flash modification.

PREREQUISITE NOT INCLUDED IN THIS REPO: this tool talks to a live-RAM-read COMMAND that the
RAMDUMP patch itself installs — it does nothing useful against stock, unpatched firmware. Building
and flashing that patch is a separate step this repo does not (yet) carry the tooling for; that patch is
not published, so if you need one you will have to build an equivalent RAM-read command yourself. If your radio already has an equivalent RAM-read patch
installed, point this tool at it directly.

See `../../docs/live-ram-capture.md` for the end-to-end recipe (what this is for, where the output
should go, and why a live capture is treated differently from this repo's other reference data).
"""
import time, argparse
import dm32_cps_common as cps

CHUNK = 0x40  # v8 handler copies a fixed 0x40 bytes per READ command

def _vframe_cmd(port, sub_id):
    """Send a safe 0x56 frame [56,00,00,00,sub_id] (b1=b2=b3=0 - required by the firmware parser),
    return the response payload. Header must be 56 <sub_id> <len>."""
    port.write(bytes([0x56, 0x00, 0x00, 0x00, sub_id]))
    time.sleep(cps.VFRAME_DELAY_S)
    header = port.read(3)
    if len(header) != 3 or header[0] != 0x56 or header[1] != sub_id:
        raise cps.DM32ProtocolError(f"bad response header for sub-id 0x{sub_id:02x}: {header.hex(' ')}")
    n = header[2]
    payload = port.read(n) if n else b""
    if len(payload) != n:
        raise cps.DM32ProtocolError(f"short payload: got {len(payload)} want {n}")
    return payload

def ramdump_reset(port):
    """sub-id 0x3f: reset the dump cursor to DUMPSTART (0x00010000). Returns the 4 echoed cursor
    bytes (big-endian) so the caller can confirm the reset took."""
    return _vframe_cmd(port, 0x3f)

def ramdump_read_next(port):
    """sub-id 0x40: return the next 0x40 bytes at the cursor and advance it."""
    return _vframe_cmd(port, 0x40)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--port', required=True)
    ap.add_argument('--addr', required=True, help='start address, e.g. 0x00010000')
    ap.add_argument('--size', help='total bytes for a full dump, e.g. 0x48000')
    ap.add_argument('--out', help='output file (required unless --probe)')
    ap.add_argument('--probe', action='store_true', help='read one chunk and print hex (sanity check)')
    ap.add_argument('--diag', action='store_true', help='query known-good vframe 0x0A then RAMDUMP 0x40, compare')
    a = ap.parse_args()
    addr = int(a.addr, 0); size = int(a.size, 0) if a.size else 0
    if not a.probe and not a.diag:
        if not a.out: ap.error('--out is required for a full dump')
        if not a.size: ap.error('--size is required for a full dump')
    port = cps.open_port(a.port)
    cps.settle_after_open(port)
    model = cps.handshake(port)
    print(f"connected: {model}")
    if a.diag:
        try:
            rc = ramdump_reset(port)
            print(f"[diag] reset -> cursor bytes: {rc.hex(' ')} (expect 00 01 00 00)")
        except Exception as e:
            print(f"[diag] reset FAILED: {e}")
        try:
            d = ramdump_read_next(port)
            print(f"[diag] read-next -> {len(d)} bytes: {d.hex(' ')}")
        except Exception as e:
            print(f"[diag] read-next FAILED: {e}")
        port.close(); return
    if a.probe:
        ramdump_reset(port)
        data = ramdump_read_next(port)
        print(f"probe: first {len(data)} bytes from 0x00010000:")
        print(data.hex(' '))
        port.close(); return
    # full sequential dump from DUMPSTART (0x00010000) via the cursor
    ramdump_reset(port)
    got = 0
    with open(a.out, 'wb') as f:
        while got < size:
            data = ramdump_read_next(port)
            if not data:
                raise cps.DM32ProtocolError(f"empty read at offset {got}")
            take = min(len(data), size - got)
            f.write(data[:take]); got += take
            if (got % 0x1000) == 0:
                print(f"  {got}/{size} ({100*got//size}%)", flush=True)
    print(f"done: wrote {got} bytes to {a.out}")
    port.close()

if __name__ == '__main__':
    main()

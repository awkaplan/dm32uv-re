# /// script
# requires-python = ">=3.9"
# dependencies = ["pyserial>=3.5"]
# ///
"""
DM-32UV CPS serial protocol - connection handshake, V-frame queries, programming-mode entry,
and 0x52 memory reads. Ported from firmware/tools/protocol-spec/DM32-Protocol-Spec/ (external,
MIT-licensed, cross-validated against two real hardware captures and the neonplug implementation -
see that directory's 02-CONNECTION-SEQUENCE.md and 03-COMMANDS.md for the full evidence base and
confidence markers this module's docstrings reference).

SAFETY: this module deliberately implements ONLY the read path (handshake, V-frame queries,
programming-mode entry, 0x52 block/byte reads). It does NOT implement 0x57 (write) at all, even
though the spec documents it fully - see dfu_write.py and dahua_hdboot_common.py for this
project's established pattern of keeping write support in a separate, explicitly-reviewed module
gated behind an "I understand the risk" flag. There is no reason for an unattended probing tool to
carry write capability.

WRITE SUPPORT: added 2026-09-26 in dm32_cps_write.py (a separate module, per the pattern above),
after the user explicitly authorized write access for live-behavioral-control research ("I want to
give you maximal control over the radio... Write operations are fine as long as you don't brick
the radio or there's a path to easily unbricking it"). That module builds on this one's connection/
programming-mode/read functions and adds ONLY a read-modify-write helper that mandates: (1) a fresh
read of the target block immediately before any write (never write stale/blind data), (2) an
automatic on-disk backup of the pre-write bytes before the write is sent, (3) an explicit restore
path that writes the backed-up bytes back. This module itself remains read-only; nothing here
changed to enable writes - see dm32_cps_write.py for all of it.

This is a DIFFERENT wire protocol from dahua_hdboot_common.py's HDBoot/mini-boot boot-ROM debug
protocol - CPS only works once the radio has booted into normal firmware and requires the
documented PSEARCH/PASSSTA/SYSINFO/V-frame/PROGRAM handshake below; HDBoot only works in a short
window at power-on before Flash boot. Do not confuse the two - see this project's CLAUDE.md known
context for the current status of each.
"""

import struct
import time

import serial as pyserial

BAUD_RATE = 115200

# --- Timing constants, all from DM32-Protocol-Spec 02-CONNECTION-SEQUENCE.md's
# "Timing and Timeout Reference" table - confirmed-sufficient-in-practice (neonplug), not
# confirmed-minimal or protocol-mandated. See that doc for per-constant source commentary.
INIT_DELAY_S = 0.4
CLEAR_BUFFER_DELAY_S = 0.2
PSEARCH_READ_DELAY_S = 0.15
HANDSHAKE_STEP_DELAY_S = 0.05
ASCII_CMD_POST_WRITE_DELAY_S = 0.01
VFRAME_DELAY_S = 0.05
PROGRAM_STEP_DELAY_S = 0.01
READ_HEADER_DELAY_S = 0.025
READ_PAYLOAD_SETTLE_DELAY_S = 0.030
BLOCK_READ_DELAY_S = 0.15
# Not from the spec - added 2026-09-26 after a real run stalled/desynced on the 14th block of a
# 200-block walk (see DM32StreamDesyncError's docstring). The spec's own 0.15s is neonplug's
# value for a UI-driven, human-paced connect session; this tool runs the same loop unattended and
# back-to-back for up to 200 iterations, which is untested territory relative to any known-good
# reference session. Doubling the delay is a cheap, reversible hedge against a load/timing-related
# cause while more data is gathered - NOT confirmed necessary or sufficient by itself.
UNATTENDED_BLOCK_READ_DELAY_S = 0.30
METADATA_PROBE_DELAY_S = 0.005
REOPEN_DELAY_S = 0.4

DEFAULT_TIMEOUT_S = 5.0
READ_MEMORY_TIMEOUT_S = 15.0

MAIN_CONFIG_BLOCK_SIZE = 0x1000  # 4 KB
METADATA_OFFSET = 0xFFF
SENTINEL_ADDR = 0xFFF001  # "no physical page allocated" address, per 03-COMMANDS.md 5.2

# V-frame IDs actually queried by the OEM CPS, in its own order (0x0D queried twice - see spec).
# This module queries in neonplug's simpler ascending order (0x0C skipped, matching both real
# implementations - its purpose is unconfirmed and nothing ever queries it).
VFRAME_IDS = (0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0D, 0x0E, 0x0F, 0x10)

VFRAME_ASCII_IDS = {0x01, 0x03, 0x04, 0x05, 0x0B}  # firmware/build-date/DSP/radio/codeplug version
VFRAME_RANGE_IDS = {0x06, 0x07, 0x08, 0x09, 0x0A, 0x0E, 0x0F}  # start_addr/end_addr uint32 LE pairs


class DM32ProtocolError(RuntimeError):
    pass


def open_port(device: str, timeout: float = DEFAULT_TIMEOUT_S) -> pyserial.Serial:
    """115200 8N1, no flow control - the only parameters the reference implementation ever sets
    explicitly (baud); the rest are platform/pyserial defaults, which happen to match."""
    return pyserial.Serial(
        port=device,
        baudrate=BAUD_RATE,
        bytesize=pyserial.EIGHTBITS,
        parity=pyserial.PARITY_NONE,
        stopbits=pyserial.STOPBITS_ONE,
        timeout=timeout,
    )


def settle_after_open(port: pyserial.Serial) -> None:
    """Step 1b: post-open settling - REQUIRED in practice per 02-CONNECTION-SEQUENCE.md, even
    though neither hardware capture can show *why* (a byte log records bytes, not silence)."""
    time.sleep(INIT_DELAY_S)
    port.reset_input_buffer()
    time.sleep(CLEAR_BUFFER_DELAY_S)
    time.sleep(CLEAR_BUFFER_DELAY_S)


def handshake(port: pyserial.Serial) -> str:
    """PSEARCH -> PASSSTA -> SYSINFO. Returns the decoded model string (e.g. "DP570UV").

    Raises DM32ProtocolError on any step failing, with the specific step named - this is the
    same failure-mode vocabulary 02-CONNECTION-SEQUENCE.md's workflow example uses.
    """
    port.write(b"PSEARCH")
    time.sleep(PSEARCH_READ_DELAY_S)
    psearch = port.read(8)
    if len(psearch) != 8 or psearch[0] != 0x06:
        raise DM32ProtocolError(
            "No reply from the radio (PSEARCH). Is it connected, powered on, and not still in "
            "programming mode from a previous session?"
        )
    model = psearch[1:].decode("ascii", errors="ignore").replace("\0", "").strip()
    if not any(tag in model for tag in ("DP570", "DM32", "DM-32")):
        raise DM32ProtocolError(f"Unsupported radio model: {model!r}")
    time.sleep(HANDSHAKE_STEP_DELAY_S)

    port.write(b"PASSSTA")
    time.sleep(HANDSHAKE_STEP_DELAY_S)
    passsta = port.read(3)
    if len(passsta) != 3 or passsta[0] != 0x50:
        raise DM32ProtocolError(f"PASSSTA failed: expected 0x50, got {passsta!r}")
    time.sleep(HANDSHAKE_STEP_DELAY_S)

    port.write(b"SYSINFO")
    time.sleep(HANDSHAKE_STEP_DELAY_S)
    if port.read(1) != b"\x06":
        raise DM32ProtocolError("SYSINFO failed: expected 0x06 ACK")
    time.sleep(ASCII_CMD_POST_WRITE_DELAY_S)

    return model


def query_vframe(port: pyserial.Serial, frame_id: int, length_hint: int = 0x00) -> bytes:
    """56 00 00 <length_hint> <frame_id> -> 56 <frame_id> <len> <payload>. See 03-COMMANDS.md
    section 2. Returns the raw payload bytes (possibly empty)."""
    port.write(bytes([0x56, 0x00, 0x00, length_hint, frame_id]))
    time.sleep(VFRAME_DELAY_S)
    header = port.read(3)
    if len(header) != 3 or header[0] != 0x56 or header[1] != frame_id:
        raise DM32ProtocolError(f"Invalid V-frame response for 0x{frame_id:02X}: {header.hex(' ')}")
    length = header[2]
    payload = port.read(length) if length else b""
    if length:
        time.sleep(VFRAME_DELAY_S)
    return payload


def decode_vframe(frame_id: int, payload: bytes):
    """Best-effort decode per the V-Frame Reference Table in 03-COMMANDS.md. Returns a dict with
    at least {"raw": <hex>}; adds "text", or "start_addr"/"end_addr" when the frame type is known.
    Unknown/short payloads are returned with just the raw hex - never guessed at."""
    out = {"raw": payload.hex()}
    if frame_id in VFRAME_ASCII_IDS and payload:
        out["text"] = payload.decode("ascii", errors="ignore").replace("\0", "").strip()
    elif frame_id in VFRAME_RANGE_IDS and len(payload) >= 8:
        start_addr, end_addr = struct.unpack("<II", payload[:8])
        out["start_addr"] = start_addr
        out["end_addr"] = end_addr
    elif frame_id == 0x10 and payload:
        out["max_contacts"] = int.from_bytes(payload, "little")
    return out


def enter_programming_mode(port: pyserial.Serial) -> None:
    """FF FF FF FF 0C PROGRAM -> 02 -> 06, per 03-COMMANDS.md section 3. Raises
    DM32ProtocolError naming the specific failed step."""
    port.write(b"\xFF\xFF\xFF\xFF\x0CPROGRAM")
    if port.read(1) != b"\x06":
        raise DM32ProtocolError("PROGRAM command failed (no ACK)")
    time.sleep(PROGRAM_STEP_DELAY_S)

    port.write(b"\x02")
    if port.read(8) != b"\xFF" * 8:
        raise DM32ProtocolError("Mode 02 failed (expected 8x 0xFF)")
    time.sleep(PROGRAM_STEP_DELAY_S)

    port.write(b"\x06")
    if port.read(1) != b"\x06":
        raise DM32ProtocolError("ACK 06 failed")
    time.sleep(PROGRAM_STEP_DELAY_S)


class DM32StreamDesyncError(DM32ProtocolError):
    """Raised when a response was short, malformed, or absent in a way that means the serial
    stream can no longer be trusted to be frame-aligned - e.g. a payload read that timed out
    partway through. Distinct from a clean protocol-level rejection (e.g. a bad header received
    promptly) because the radio may still be mid-transmission of stale bytes. Callers should stop
    issuing further reads on this port rather than retry, since the next write may land in the
    middle of leftover bytes from the failed frame and produce a cascade of unrelated failures.

    OBSERVED ON REAL HARDWARE (2026-09-26): a full-run snapshot got a short read (4089/4096 bytes,
    after the full READ_MEMORY_TIMEOUT_S) on block 14 of a 200-block walk, and the user reported
    the radio itself appeared to restart around this point. Every subsequent read in that run came
    back with a completely empty header (0 bytes, not just a malformed one) - consistent with the
    radio dropping out of programming mode mid-transfer, not a simple host-side buffer desync.
    This module cannot distinguish "radio rebooted" from "cable/host hiccup" from the wire alone;
    treat any DM32StreamDesyncError as "stop and let the caller decide whether to reconnect from
    scratch," never as "retry the same read."
    """


def read_memory(port: pyserial.Serial, addr: int, length: int) -> bytes:
    """0x52 <addr:3 LE> <len:2 LE> -> 0x57 <addr:3 LE echoed> <len:2 LE> <data>.

    Per 03-COMMANDS.md 4.1: response address is NOT validated (matching the reference
    implementation), response length must be >0 and <= requested (a short response is accepted
    BY THE PROTOCOL SPEC as meaning "fewer bytes than requested, but still a clean frame" - that
    is different from what this function treats as short: pyserial's read(n) with a timeout set
    returns whatever it got by the deadline, silently, so a payload that arrives short because the
    radio stalled/rebooted mid-transfer looks the same at the pyserial layer as a deliberate short
    response. This function raises DM32StreamDesyncError for that case since we cannot tell them
    apart, and a stream in that state cannot be trusted to still be frame-aligned.
    """
    if not (0 <= addr <= 0xFFFFFF):
        raise ValueError(f"addr out of 24-bit range: 0x{addr:x}")
    if not (0 < length <= 0xFFFF):
        raise ValueError(f"length out of range: {length}")

    port.write(b"\x52" + addr.to_bytes(3, "little") + length.to_bytes(2, "little"))
    time.sleep(READ_HEADER_DELAY_S)
    header = port.read(6)
    if len(header) == 0:
        raise DM32StreamDesyncError(
            f"No response at all to read at 0x{addr:06X} - radio may have reset or left "
            "programming mode"
        )
    if len(header) != 6 or header[0] != 0x57:
        raise DM32StreamDesyncError(f"Invalid read response header at 0x{addr:06X}: {header.hex(' ')}")
    resp_len = struct.unpack("<H", header[4:6])[0]
    if resp_len == 0 or resp_len > length:
        raise DM32StreamDesyncError(f"Invalid response length at 0x{addr:06X}: {resp_len}")

    old_timeout = port.timeout
    try:
        port.timeout = READ_MEMORY_TIMEOUT_S
        data = port.read(resp_len)
    finally:
        port.timeout = old_timeout
    if len(data) != resp_len:
        raise DM32StreamDesyncError(
            f"Payload read at 0x{addr:06X} stalled/timed out: expected {resp_len} bytes, got "
            f"{len(data)} within {READ_MEMORY_TIMEOUT_S}s - radio may have reset mid-transfer"
        )
    time.sleep(READ_PAYLOAD_SETTLE_DELAY_S)
    return data


def read_logical_block_id(port: pyserial.Serial, block_addr: int) -> int:
    """1-byte probe at block_addr + 0xFFF - the logical block ID, per 03-COMMANDS.md 4.1/
    04-MEMORY-LAYOUT.md. Does NOT sleep METADATA_PROBE_DELAY_S itself - callers loop this over
    many blocks and should add that delay between calls (see dm32_cps_snapshot.py)."""
    return read_memory(port, block_addr + METADATA_OFFSET, 1)[0]


def close_and_wait_for_reopen(port: pyserial.Serial) -> None:
    """There is no exit-programming-mode command (CONFIRMED by absence in both hardware
    captures) - closing the port DTR-resets the radio out of programming mode. Callers that will
    reopen the same device should sleep REOPEN_DELAY_S after calling this."""
    port.close()
    time.sleep(REOPEN_DELAY_S)

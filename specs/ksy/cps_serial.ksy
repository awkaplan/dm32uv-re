# Follows infamy/DM32-Protocol-Spec (github.com/infamy/DM32-Protocol-Spec, MIT License,
# Copyright (c) 2025 DM-32UV Protocol Documentation Contributors), 03-COMMANDS.md, for the
# framing, the V-frame table and the session order; no text is copied. Where the stock firmware's
# own parser (decompiled in this repository) says more or differently, the doc fields say so.
meta:
  id: cps_serial
  title: Baofeng DM-32UV CPS programming protocol (UART0, 115200 8N1), both directions
  ks-version: '0.11'
  endian: le
  -dm32-confidence: CONFIRMED
doc: |
  The protocol the vendor CPS speaks to a running DM-32UV. No checksum or CRC anywhere; integrity
  rests on fixed codes, the echoed V-frame id, the length fields and 0x06 acks.

  Session (OEM CPS, both of infamy's captures; the stock parser explains each step):
    host  PSEARCH, PASSSTA, SYSINFO          7-byte ASCII commands, answered 06+model / 50 xx xx / 06
    host  V-frames 56 00 00 00 <id> ...      SYSINFO starts the "info loop" (0x0302a044)
    host  47 00 00 00 00 01                  one 0x47 read, answered 53 + echo + 256 bytes
    host  FF FF FF FF 0C                     ends the info loop (5-byte frame, last byte ignored)
    host  PROGRAM                            7-byte ASCII, enters the programming loop (0x0302a4dc)
    radio 06; host 02; radio FF x8; host 06; radio 06
    host  52/57 block reads and writes       24-bit little-endian addresses, 16-bit LE lengths
    (no exit command: closing the port resets the radio)
  The "0x0C" byte before PROGRAM that the spec lists as unknown is the fifth byte of the info
  loop's 5-byte read: the loop leaves when bytes 0-3 are FF and never looks at byte 4.

  Each loop reads a 5-byte header with a 2 s timeout (0x7d0) and leaves on timeout; with nothing
  received, the radio then resets. Sub-ids above 0x40 make the info loop return without a reply
  (`cmphsi r8,0x41` at 0x0302a0e6), which is why this project's debug patches use 0x21-0x40.

  Root type: the host-to-radio stream of one OEM-order session. radio_session parses the other
  direction under the same assumption. host_frames_programming / radio_frames_programming parse
  either direction of the programming loop alone (both are self-delimiting there).

  Every V-frame reply except 0x02 is a constant of the firmware: the strings and the 8-byte
  ranges are literals in DM32.00.01.048's flash (ranges at 0x030adb0c..0x030adb4f) and equal the
  values infamy captured from DM32.01.01.046.

  Per-unit data: replies to PASSSTA (two codeplug bytes), V-frame 0x02 (computed at run time,
  meaning unknown) and every block read carry one radio's data; real captures are private test
  inputs only (DM32_PRIVATE_DUMPS), never fixtures.

  SAFETY. A format description; nothing in this repository sends these frames. The write frames
  (0x57, and the stock 0x53/0x43 the CPS never uses) change the data chip, which also holds the
  calibration page (restore-only).
doc-ref:
  - infamy/DM32-Protocol-Spec (MIT), 03-COMMANDS.md and 02-CONNECTION-SEQUENCE.md, commit 62b9b36 (2026)
  - stock DM32.00.01.048 serial_protocol_vframe_command_loop @0x0302a044, serial_protocol_vframe_command_loop_variant @0x0302a4dc, cps_serial_handshake_command_dispatcher @0x0302b3d4 (src/peripheral-uart/, src/host-protocol/, meta/disasm.jsonl)
  - tools/src/dm32_patch_tools/dm32_cps_common.py, dm32_ramdump.py (this project's debug sub-ids)
seq:
  - id: handshake
    type: ascii_command
    repeat: until
    repeat-until: _.text == "SYSINFO"
    doc: 7-byte ASCII commands up to and including SYSINFO (OEM sends PSEARCH, PASSSTA, SYSINFO).
  - id: info_frames
    type: info_host_frame
    repeat: until
    repeat-until: _.code == host_code::loop_exit
    doc: Frames to the info loop, ending with the FF FF FF FF xx frame that leaves it.
  - id: program
    contents: PROGRAM
    doc: The 7-byte command that starts the programming loop.
  - id: mode_request
    contents: [0x02]
    doc: Sent after the radio acks PROGRAM; the radio answers with eight 0xFF.
  - id: confirm
    contents: [0x06]
    doc: Sent after the eight 0xFF; the radio answers 0x06 and starts serving block commands.
  - id: frames
    type: programming_host_frame
    repeat: eos
    doc: Block reads/writes and V-frames until the port is closed.
types:
  ascii_command:
    doc: |
      Commands the stock dispatcher (0x0302b3d4) compares against: PSEARCH, PASSSTA, SYSINFO,
      PROGRAM, PASWORD, PCTESTM, RTCITEM, DEL-RCD, IDCHECK. Only the first four occur in a CPS
      session; the others are recorded from the dispatcher, not from captures.
    seq:
      - id: text
        type: str
        size: 7
        encoding: ASCII
        doc: Command name.
  host_frames_programming:
    doc: Host-to-radio frames of the programming loop alone (e.g. one captured block transfer).
    seq:
      - id: frames
        type: programming_host_frame
        repeat: eos
        doc: Consecutive frames.
  host_frames_info:
    doc: |
      Host-to-radio frames of the info loop alone, e.g. a debug session that sends SYSINFO and
      then only V-frames (dm32_ramdump.py), without the 7-byte commands before it.
    seq:
      - id: frames
        type: info_host_frame
        repeat: eos
        doc: Consecutive frames.
  info_host_frame:
    doc: |
      A frame to the info loop (0x0302a044). Codes other than these make the loop return.
      0x43 and 0x53 are write commands the stock parser accepts here; no CPS capture uses them.
    seq:
      - id: code
        type: u1
        enum: host_code
        valid:
          any-of:
            - host_code::vframe
            - host_code::g_read
            - host_code::s_write
            - host_code::c_write
            - host_code::loop_exit
        doc: Frame code (byte 0).
      - id: body
        type:
          switch-on: code
          cases:
            'host_code::vframe': vframe_request
            'host_code::g_read': info_mem_request
            'host_code::s_write': info_s_write
            'host_code::c_write': info_c_write
            'host_code::loop_exit': loop_exit
        doc: The rest of the frame.
  loop_exit:
    doc: FF FF FF FF xx. Bytes 1-3 must be FF; byte 4 is not examined (the CPS sends 0x0C).
    seq:
      - id: ff
        contents: [0xff, 0xff, 0xff]
        doc: Bytes 1-3.
        -dm32-confidence: STRUCTURAL
      - id: ignored
        type: u1
        doc: Byte 4, read but never examined by the stock parser. 0x0C from the OEM CPS.
        -dm32-confidence: STRUCTURAL
  vframe_request:
    doc: |
      56 a b c <id>, always 5 bytes. For id 0x0d the stock parser reads a 16-bit big-endian table
      offset from a:b and the reply length from c (so `56 00 00 40 0D` returns 64 bytes and
      `56 00 00 00 0D` none). For every other id a, b and c must be 0 or the loop returns.
    seq:
      - id: arg_a
        type: u1
        doc: 0, or the high byte of the 0x0d table offset.
        -dm32-confidence: STRUCTURAL
      - id: arg_b
        type: u1
        doc: 0, or the low byte of the 0x0d table offset.
        -dm32-confidence: STRUCTURAL
      - id: arg_c
        type: u1
        doc: 0, or the 0x0d reply length.
        -dm32-confidence: STRUCTURAL
      - id: sub_id
        type: u1
        enum: vframe_id
        doc: What to return. Ids above 0x40 are rejected without a reply.
    instances:
      table_offset:
        value: arg_a * 256 + arg_b
        doc: Offset into the stock 0x0d table (sub_id 0x0d only).
        -dm32-confidence: STRUCTURAL
  info_mem_request:
    doc: |
      0x47 in the info loop: bytes 1-3 address, 4-5 length (u16 LE). The stock parser builds the
      address as (b1 << 12) | (b2 << 8) | b3 here (`lsli r11,r3,0xc` at 0x0302a0d0), unlike the
      24-bit little-endian address of the programming loop; the only captured request uses 0, so
      the captures cannot tell the two apart. The read itself goes through
      mutex_guarded_call_generic3arg (0x03010ddc); what it reads is unknown.
    seq:
      - id: b1
        type: u1
        doc: Address byte 1.
        -dm32-confidence: STRUCTURAL
      - id: b2
        type: u1
        doc: Address byte 2.
        -dm32-confidence: STRUCTURAL
      - id: b3
        type: u1
        doc: Address byte 3.
        -dm32-confidence: STRUCTURAL
      - id: length
        type: u2
        doc: Bytes requested (0x0100 from the CPS).
    instances:
      stock_address:
        value: (b1 << 12) | (b2 << 8) | b3
        doc: The address as the stock info loop computes it.
        -dm32-confidence: STRUCTURAL
  info_s_write:
    doc: |
      0x53 in the info loop: header as info_mem_request, then `length` bytes; the radio acks 0x06.
      The stock parser passes them to IRAM 0x0002c160 (address, data, length), calling
      0x0002c0f8 first when the address is 4 KB-aligned: an erase-then-program shape. Neither
      routine is identified; never captured.
    seq:
      - id: header
        type: info_mem_request
        doc: Address and length.
        -dm32-confidence: STRUCTURAL
      - id: data
        size: header.length
        doc: Payload.
        -dm32-confidence: STRUCTURAL
  info_c_write:
    doc: |
      0x43 in the info loop: bytes 1-3 (unused by the parser), byte 4 = length, then `length`
      bytes, handed to mutex_guarded_call3_wrapper (0x03010db8) with first argument 0x10c; the
      radio acks 0x06. Purpose unknown; never captured.
    seq:
      - id: unused
        size: 3
        doc: Bytes 1-3; the 0x43 path does not use them.
        -dm32-confidence: STRUCTURAL
      - id: length
        type: u1
        doc: Payload length.
        -dm32-confidence: STRUCTURAL
      - id: data
        size: length
        doc: Payload.
        -dm32-confidence: STRUCTURAL
  programming_host_frame:
    doc: A frame to the programming loop (0x0302a4dc). Other codes make the loop return.
    seq:
      - id: code
        type: u1
        enum: host_code
        valid:
          any-of:
            - host_code::vframe
            - host_code::read
            - host_code::write
            - host_code::g_read
            - host_code::s_write
            - host_code::d_request
        doc: Frame code (byte 0).
      - id: body
        type:
          switch-on: code
          cases:
            'host_code::vframe': vframe_request
            'host_code::read': mem_request
            'host_code::g_read': mem_request
            'host_code::d_request': mem_request
            'host_code::write': mem_write
            'host_code::s_write': mem_write
        doc: The rest of the frame.
  mem_request:
    doc: |
      52 (read), 47, or 44: 24-bit little-endian address, 16-bit little-endian length, 6 bytes in
      all. A read of `blockBase + 0xfff`, length 1, returns a 4 KB page's logical block id; the
      address 0xfff001 is the "no page" sentinel. 0x44 makes the stock loop call
      sdcard_data_block_read (formerly flash_program_data_block_write) with the address and (length < 0x200 ? 1 : (length >> 9) & 0xff)
      and reply like a read; never captured, purpose unknown.
    seq:
      - id: addr_lo
        type: u1
        doc: Address bits 0-7.
      - id: addr_mid
        type: u1
        doc: Address bits 8-15.
      - id: addr_hi
        type: u1
        doc: Address bits 16-23.
      - id: length
        type: u2
        doc: Byte count (1, 4 or 4096 from the CPS; neonplug also uses 2 and 2048).
    instances:
      addr:
        value: addr_lo | (addr_mid << 8) | (addr_hi << 16)
        doc: The 24-bit data-chip address.
      is_sentinel:
        value: addr == 0xfff001
        doc: True for the "no physical page" sentinel address.
  mem_write:
    doc: |
      57 (write) or 53: mem_request header, then `length` bytes; the radio acks 0x06. The 4 KB
      write's logical block id is its last byte (payload +0xfff). For 0x57 at a 4 KB-aligned
      address the stock loop first calls flash_mutex_guarded_op(addr >> 12) (a sector erase, by
      its shape; not confirmed), then spi_flash_write_multi_sector.
    seq:
      - id: header
        type: mem_request
        doc: Address and length.
      - id: data
        size: header.length
        doc: Payload (4096 bytes from the CPS).
  radio_session:
    doc: |
      Radio-to-host stream of one OEM-order session. Assumes the info loop got only V-frames and
      0x47 reads (true of every CPS capture): its first 0x06 is then the PROGRAM ack.
    seq:
      - id: psearch_reply
        type: psearch_reply
        doc: Reply to PSEARCH.
      - id: passsta_reply
        type: passsta_reply
        doc: Reply to PASSSTA.
      - id: sysinfo_ack
        contents: [0x06]
        doc: Reply to SYSINFO.
      - id: info_replies
        type: info_radio_frame
        repeat: until
        repeat-until: _.code == radio_code::ack
        doc: Replies inside the info loop, then the 0x06 that acks PROGRAM.
      - id: mode_reply
        contents: [0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff]
        doc: Reply to the 0x02 step.
      - id: confirm_ack
        contents: [0x06]
        doc: Reply to the 0x06 step.
      - id: frames
        type: programming_radio_frame
        repeat: eos
        doc: Replies in the programming loop.
  radio_frames_programming:
    doc: Radio-to-host frames of the programming loop alone.
    seq:
      - id: frames
        type: programming_radio_frame
        repeat: eos
        doc: Consecutive frames.
  psearch_reply:
    doc: 06 followed by 7 ASCII model bytes, no terminator ("DP570UV" in DM32.00.01.048).
    seq:
      - id: ack
        contents: [0x06]
        doc: Ack.
      - id: model
        type: str
        size: 7
        encoding: ASCII
        doc: Model string, from flash (0x0302b548 points at it).
  passsta_reply:
    doc: |
      50 xx xx. The stock dispatcher reads xx xx from logical block 4 at offset 0x439 of the
      codeplug (flash_block_id_resolve_locked(4) + flash_block_read), so they are codeplug data;
      meaning unknown (only 00 00 has been captured).
    seq:
      - id: code
        contents: [0x50]
        doc: "'P'."
      - id: codeplug_bytes
        size: 2
        doc: Two bytes of codeplug block 4 at +0x439.
        -dm32-confidence: STRUCTURAL
  radio_frames_info:
    doc: Radio-to-host replies of the info loop alone (no PROGRAM ack among them).
    seq:
      - id: frames
        type: info_radio_frame
        repeat: eos
        doc: Consecutive replies.
  info_radio_frame:
    doc: A reply from the info loop, or the 0x06 that acks PROGRAM.
    seq:
      - id: code
        type: u1
        enum: radio_code
        valid:
          any-of:
            - radio_code::vframe
            - radio_code::g_reply
            - radio_code::ack
        doc: Reply code (byte 0).
      - id: body
        type:
          switch-on: code
          cases:
            'radio_code::vframe': vframe_response
            'radio_code::g_reply': mem_reply
            _: no_body
        doc: The rest of the reply.
  programming_radio_frame:
    doc: A reply from the programming loop.
    seq:
      - id: code
        type: u1
        enum: radio_code
        valid:
          any-of:
            - radio_code::ack
            - radio_code::vframe
            - radio_code::read_reply
            - radio_code::g_reply
        doc: Reply code (byte 0).
      - id: body
        type:
          switch-on: code
          cases:
            'radio_code::vframe': vframe_response
            'radio_code::read_reply': mem_reply
            'radio_code::g_reply': mem_reply
            _: no_body
        doc: The rest of the reply.
  no_body:
    doc: A one-byte reply (0x06 ack).
    seq: []
  mem_reply:
    doc: |
      57 (reply to 52 or 44) or 53 (reply to 47): the request's 5 header bytes echoed, then
      `length` bytes. The CPS checks only that the length is non-zero and not above the request.
    seq:
      - id: echo
        type: mem_request
        doc: Address and length as echoed.
      - id: data
        size: echo.length
        doc: The data.
  vframe_response:
    doc: 56 <id> <n> then n payload bytes (n <= 255).
    seq:
      - id: sub_id
        type: u1
        enum: vframe_id
        doc: Echo of the requested id.
      - id: length
        type: u1
        doc: Payload length; 0 is legal.
      - id: payload
        size: length
        type:
          switch-on: sub_id
          cases:
            'vframe_id::firmware_version': ascii_payload
            'vframe_id::build_date': ascii_payload
            'vframe_id::dsp_version': ascii_payload
            'vframe_id::radio_version': ascii_payload
            'vframe_id::codeplug_version': ascii_payload
            'vframe_id::range_06': range_payload
            'vframe_id::range_07': range_payload
            'vframe_id::range_08': range_payload
            'vframe_id::range_09': range_payload
            'vframe_id::codeplug_range': range_payload
            'vframe_id::boot_image_range': range_payload
            'vframe_id::contacts_range': range_payload
            'vframe_id::max_contacts': max_contacts_payload
        doc: Payload; ids without a known layout stay raw bytes.
  ascii_payload:
    doc: A version or date string (strip NULs and spaces when displaying).
    seq:
      - id: text
        type: str
        size-eos: true
        encoding: ASCII
        doc: The string, e.g. "DM32.00.01.048" for id 0x01 on this firmware.
  range_payload:
    doc: start and end address of a data-chip region, both u32 LE; end is the region's last byte.
    seq:
      - id: start
        type: u4
        doc: First byte.
      - id: end
        type: u4
        doc: Last byte (inclusive).
      - id: extra
        size-eos: true
        doc: Any bytes beyond 8 (none in the captures).
        -dm32-confidence: STRUCTURAL
    instances:
      size:
        value: end - start + 1
        doc: Region size in bytes.
  max_contacts_payload:
    doc: Contact capacity as a little-endian integer over the payload (3 bytes, 50 C3 00 = 50000).
    seq:
      - id: lo
        type: u1
        doc: Bits 0-7.
      - id: mid
        type: u1
        doc: Bits 8-15.
      - id: hi
        type: u1
        doc: Bits 16-23.
      - id: extra
        size-eos: true
        doc: Any further bytes (none on DM32.00.01.048, which hard-codes 3).
        -dm32-confidence: STRUCTURAL
    instances:
      count:
        value: lo | (mid << 8) | (hi << 16)
        doc: The capacity.
enums:
  host_code:
    0x43:
      id: c_write
      doc: Info loop only; length-prefixed payload, purpose unknown (stock parser, never captured).
      -dm32-confidence: STRUCTURAL
    0x44:
      id: d_request
      doc: Programming loop only; replies like a read (stock parser, never captured).
      -dm32-confidence: STRUCTURAL
    0x47:
      id: g_read
      doc: Read answered with 0x53 + echo + data. Sent once per CPS session, before PROGRAM.
    0x52:
      id: read
      doc: "'R', data-chip read."
    0x53:
      id: s_write
      doc: Write in both loops (stock parser, never captured).
      -dm32-confidence: STRUCTURAL
    0x56:
      id: vframe
      doc: "'V', info query."
    0x57:
      id: write
      doc: "'W', data-chip write."
    0xff:
      id: loop_exit
      doc: First byte of FF FF FF FF xx, which ends the info loop.
      -dm32-confidence: STRUCTURAL
  radio_code:
    0x06:
      id: ack
      doc: Ack.
    0x53:
      id: g_reply
      doc: Reply to 0x47.
    0x56:
      id: vframe
      doc: V-frame reply.
    0x57:
      id: read_reply
      doc: Reply to 0x52 (and to 0x44).
  vframe_id:
    0x01:
      id: firmware_version
      doc: ASCII firmware version ("DM32.00.01.048").
    0x02:
      id: unknown_02
      doc: 12 bytes built at run time (0x0305f7d8, then bytes 8-11 = XOR/OR of 0-3 with 4-7). Meaning unknown; treat real replies as private.
      -dm32-confidence: STRUCTURAL
    0x03:
      id: build_date
      doc: ASCII build date.
    0x04:
      id: dsp_version
      doc: ASCII DSP version ("D1.01.01.004").
    0x05:
      id: radio_version
      doc: ASCII radio version ("R1.00.01.001").
    0x06:
      id: range_06
      doc: Data-chip range, contents unknown (0x201000-0x264fff in the captures).
    0x07:
      id: range_07
      doc: Data-chip range, contents unknown (0x0c9000-0x149fff).
    0x08:
      id: range_08
      doc: Data-chip range, contents unknown (0x180000-0x200fff).
    0x09:
      id: range_09
      doc: Data-chip range, contents unknown (0x6dc000-0xffffff).
    0x0a:
      id: codeplug_range
      doc: Main config block, the codeplug pages (0x001000-0x0c8fff).
    0x0b:
      id: codeplug_version
      doc: ASCII codeplug version ("C1.00.01.001").
    0x0c:
      id: unused_0c
      doc: Never queried by the CPS or neonplug; no case in the stock handler.
      -dm32-confidence: STRUCTURAL
    0x0d:
      id: table_0d
      doc: Slice of a constant table in flash at 0x030adb50 (first bytes 03 4e 2d 00, as captured), offset and length from the request (see vframe_request). Meaning unknown.
      -dm32-confidence: STRUCTURAL
    0x0e:
      id: boot_image_range
      doc: Data-chip range holding the 240x320 boot image (0x150000-0x175fff); purpose derived by the spec, not captured.
    0x0f:
      id: contacts_range
      doc: Data-chip range of the DMR contact database (0x278000-0x6dbfff).
    0x10:
      id: max_contacts
      doc: Contact capacity; DM32.00.01.048 hard-codes 50 C3 00 (50000).
    0x3e:
      id: patch_flash_read_next
      doc: NOT STOCK. A read-only diagnostic patch of this project ("megaprobe", not shipped) answers 0x40 bytes of the data chip at its flash cursor and advances it.
      -dm32-confidence: CONFIRMED
    0x3f:
      id: patch_ramdump_reset
      doc: NOT STOCK. The RAMDUMP patch (tools/src/dm32_patch_tools/dm32_ramdump.py) resets its RAM cursor to 0x00010000 and replies with the cursor, 4 bytes big-endian.
      -dm32-confidence: CONFIRMED
    0x40:
      id: patch_ramdump_read
      doc: NOT STOCK. The RAMDUMP patch replies with 0x40 bytes at its RAM cursor and advances it. 0x40 is the highest id the stock parser lets through.
      -dm32-confidence: CONFIRMED

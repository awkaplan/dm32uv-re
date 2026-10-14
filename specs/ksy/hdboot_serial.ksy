meta:
  id: hdboot_serial
  title: HR_C7000 (Dahua) mask boot ROM serial protocol, and the flash loader that runs over it
  ks-version: '0.11'
  endian: be
  -dm32-confidence: STRUCTURAL
doc: |
  The HR_C7000's 2 KB mask boot ROM talks on UART0 at 115200 8N1 before any flash code runs. At
  reset it sends a NOTIFY frame and briefly waits for a host; if none answers it checks DH_FLAG
  at flash 0 and jumps to the entry word at flash 4 (dm32_firmware_image.ksy), sending that word
  on the UART first (rom_boot_announce). If a host answers NOTIFY with DEBUG, the ROM stays in a
  command loop: write a word, read words, download words, run (jump), exit.

  Two frame formats exist in Dahua's own PC tool ("DH SOC Tools", decompiled), chosen there by a
  CPU-type setting:
    Mini   host frame = STX 0x02, command, 8-bit checksum, ETX 0x03, then a big-endian body;
           device frames are the same 4-byte header. USED BY THE DM-32: its boot ROM sends
           02 24 00 03 at power-on and accepts 02 14 00 03 (DEBUG), DOWNLOAD and RUN.
    DH6000 host frame = 0x00, command, body, then a 4-byte big-endian checksum; the device acks
           with one byte 0x08 and reports status in 4-byte frames 00 <cmd> ?? 01. Never seen on
           a DM-32; described from the tool only.
  The checksums are sums Kaitai cannot compute: Mini = (sum of the body bytes) & 0xff, DH6000 =
  sum of the address and value bytes, or of the data bytes alone for DOWNLOAD, as a u32. The
  description keeps them as fields; tests/test_ksy_roundtrip.py checks them.

  Flash loader. Programming the DM-32's flashes over this link (as rogerclarkmelbourne/DM32's
  C7000_*.py tools do, after the UV008 Flash tool by andynvkz) means downloading a small loader
  into IRAM at 0x00010000 in 256-byte DOWNLOAD frames, RUNning it at 0x00010974, and then
  speaking the loader's own Mini-framed commands (loader_frame): 256-byte reads and writes of the
  program flash and of the 16 MB data chip. Command 0x18 means DOWNLOAD to the ROM and
  "write 256 bytes of program flash" to the loader, so the two stages need separate types;
  loader_session splits a host stream at the RUN frame.

  SAFETY. This is a format description; nothing in this repository sends these frames. The
  loader's write commands erase-and-program flash directly: 0x16 writes the data chip, which
  holds the radio's calibration (restore-only, from that radio's own verified backup), and 0x18
  writes the program flash, whose per-unit sector must never be written from another unit's image.

  Host-to-device streams are self-delimiting (the command fixes the body length), so the root
  type and loader_session parse whole captured host streams. Device-to-host streams are not
  (a READ reply's length comes from the request), so only single device frames are described.
doc-ref:
  - HR_C7000 datasheet v2.2 (zh), boot flowchart, p.24 (serial handshake, then write/read/download/jump/exit command loop, 115200 bps)
  - DH SOC Tools (Dahua chip debug tool, .NET), serial.cs as decompiled with ILSpy (PtzLibMiniPacket, PtzLibDH6000PacketHdboot, the DHC_BM_CMD_E values); facts only, no code copied
  - github.com/rogerclarkmelbourne/DM32 C7000_read_progmem.py, C7000_write_progmem.py, C7000_read_Q128.py, C7000_write_Q128.py (no license file; protocol facts only, no code or loader bytes copied)
  - this project's UART capture at power-on and disassembly of the mask boot ROM (offsets 0x5c-0x72)
seq:
  - id: frames
    type: mini_host_frame
    repeat: eos
    doc: |
      Host-to-ROM frames in Mini format, e.g. DEBUG, DOWNLOAD..., RUN. Stops being valid at the
      first frame after a RUN that started a loader; use loader_session for such captures.
    -dm32-confidence: CONFIRMED
types:
  mini_host_frame:
    doc: One host-to-boot-ROM command in Mini format.
    seq:
      - id: stx
        contents: [0x02]
        doc: Start byte.
        -dm32-confidence: CONFIRMED
      - id: cmd
        type: u1
        enum: rom_cmd
        valid:
          any-of:
            - rom_cmd::debug
            - rom_cmd::exit
            - rom_cmd::ack
            - rom_cmd::download
            - rom_cmd::write
            - rom_cmd::read
            - rom_cmd::run
            - rom_cmd::erase
        doc: Command. Only the commands the Dahua tool can send in Mini format are accepted.
      - id: checksum
        type: u1
        doc: |
          (sum of every body byte) & 0xff; 0 for commands without a body. Not validated by this
          description.
        -dm32-confidence: CONFIRMED
      - id: etx
        contents: [0x03]
        doc: End-of-header byte (the body, if any, follows it).
        -dm32-confidence: CONFIRMED
      - id: body
        type:
          switch-on: cmd
          cases:
            'rom_cmd::download': mini_download_body
            'rom_cmd::write': mini_write_body
            'rom_cmd::read': mini_addr_count
            'rom_cmd::erase': mini_addr_count
            'rom_cmd::run': mini_run_body
            _: no_body
        doc: Command arguments. DEBUG, EXIT and ACK have none.
  mini_download_body:
    doc: |
      DOWNLOAD: store word_count 32-bit words at addr. The DM-32 flash loader is sent this way,
      0x40 words (256 bytes) per frame, to IRAM 0x00010000 upward.
    seq:
      - id: addr
        type: u4
        doc: Destination address.
        -dm32-confidence: CONFIRMED
      - id: word_count
        type: u4
        doc: Number of 32-bit words in data.
        -dm32-confidence: CONFIRMED
      - id: data
        size: word_count * 4
        doc: |
          The words, sent as-is. (The Dahua tool reverses the bytes of each word for its
          "mini-boot" CPU type; the DM-32 loader upload sends the image bytes unchanged.)
        -dm32-confidence: CONFIRMED
  mini_write_body:
    doc: WRITE one 32-bit word.
    seq:
      - id: addr
        type: u4
        doc: Address to write.
      - id: value
        size: 4
        type: word_either_endian
        doc: |
          The value. The Dahua tool sends it big-endian for its mini-boot CPU type and
          little-endian for the others; which one the DM-32 ROM expects is not known (never used).
        -dm32-confidence: INFERRED
  word_either_endian:
    doc: A 4-byte word whose byte order is not known; both readings are offered.
    seq:
      - id: as_be
        type: u4be
        doc: The word read big-endian.
        -dm32-confidence: INFERRED
    instances:
      as_le:
        pos: 0
        type: u4le
        doc: The same 4 bytes read little-endian.
        -dm32-confidence: INFERRED
  mini_addr_count:
    doc: |
      READ: word_count 32-bit words from addr (the tool caps a read at 64 words; the ROM answers
      with a READ header frame, the raw words, then an OK frame). ERASE (0x45): same layout in
      the tool; what the DM-32 ROM does with it is unknown.
    seq:
      - id: addr
        type: u4
        doc: Start address.
      - id: word_count
        type: u4
        doc: Count, in 32-bit words.
  mini_run_body:
    doc: RUN (jump). The DM-32 flash loader is started with addr 0x00010974.
    seq:
      - id: addr
        type: u4
        doc: Address to jump to.
        -dm32-confidence: CONFIRMED
  no_body:
    doc: Commands without arguments.
    seq: []
  mini_device_frame:
    doc: |
      A 4-byte frame from the ROM or the loader: 02 <code> <byte> 03. Seen on a DM-32:
      02 24 00 03 (NOTIFY, at power-on) and 02 05 00 03 (OK, after each DOWNLOAD, the RUN and each
      loader write). The tool's reader accepts any code here and takes it as the command echoed.
    seq:
      - id: stx
        contents: [0x02]
        doc: Start byte.
        -dm32-confidence: CONFIRMED
      - id: code
        type: u1
        enum: rom_cmd
        doc: notify (0x24), ok (0x05), err (0x0a), or the echo of the command being answered.
      - id: arg
        type: u1
        doc: 0x00 in every frame seen; not interpreted by either tool.
      - id: etx
        contents: [0x03]
        doc: End byte.
        -dm32-confidence: CONFIRMED
  rom_boot_announce:
    doc: |
      What a DM-32 sends on UART0 at power-on when no host answers: NOTIFY, then (after the
      handshake window, once DH_FLAG matched) the four bytes of the entry address it is about to
      jump to, least significant byte first. Observed with a non-stock image's entry word; for
      stock firmware (entry 0x03001000) that makes 02 24 00 03 00 10 00 03.
    seq:
      - id: notify
        type: mini_device_frame
        doc: 02 24 00 03.
        -dm32-confidence: CONFIRMED
      - id: entry
        type: u4le
        doc: Word at flash+4 (dm32_firmware_image.ksy header.entry), sent little-endian.
        -dm32-confidence: CONFIRMED
  loader_session:
    doc: |
      A host-to-device stream of a flash-loader session: ROM frames up to and including the RUN
      that starts the loader, then loader frames to the end.
    seq:
      - id: rom_frames
        type: mini_host_frame
        repeat: until
        repeat-until: _.cmd == rom_cmd::run
        doc: DEBUG, the loader's DOWNLOAD frames, RUN.
        -dm32-confidence: CONFIRMED
      - id: loader_frames
        type: loader_frame
        repeat: eos
        doc: Commands to the running loader.
        -dm32-confidence: CONFIRMED
  loader_frame:
    doc: |
      A command to the IRAM flash loader (not the ROM): Mini header, 4-byte big-endian address,
      and for writes 256 bytes of data. Checksum = (sum of address and data bytes) & 0xff. The
      loader answers a read with 02 05 xx 03 plus 256 bytes and a write with 02 05 00 03.
    seq:
      - id: stx
        contents: [0x02]
        doc: Start byte.
        -dm32-confidence: CONFIRMED
      - id: cmd
        type: u1
        enum: loader_cmd
        valid:
          any-of:
            - loader_cmd::datachip_read
            - loader_cmd::datachip_write
            - loader_cmd::progflash_read
            - loader_cmd::progflash_write
        doc: Loader command.
      - id: checksum
        type: u1
        doc: (sum of addr and data bytes) & 0xff. Not validated by this description.
        -dm32-confidence: CONFIRMED
      - id: etx
        contents: [0x03]
        doc: End-of-header byte.
        -dm32-confidence: CONFIRMED
      - id: addr
        type: u4
        doc: |
          Byte address inside the selected flash chip, 256-aligned in every use (0..0xfffff for
          the program flash, 0..0xffffff for the data chip).
        -dm32-confidence: CONFIRMED
      - id: data
        size: 256
        if: cmd == loader_cmd::datachip_write or cmd == loader_cmd::progflash_write
        doc: The 256 bytes to program (write commands only).
        -dm32-confidence: CONFIRMED
  dh6000_host_stream:
    doc: Host-to-device frames in DH6000 format (not used by the DM-32).
    seq:
      - id: frames
        type: dh6000_host_frame
        repeat: eos
        doc: Consecutive frames.
        -dm32-confidence: STRUCTURAL
  dh6000_host_frame:
    doc: One host command in the DH6000 format (from the Dahua tool only).
    seq:
      - id: lead
        contents: [0x00]
        doc: Lead byte.
      - id: cmd
        type: u1
        enum: rom_cmd
        valid:
          any-of:
            - rom_cmd::debug
            - rom_cmd::download
            - rom_cmd::write
            - rom_cmd::read
            - rom_cmd::run
        doc: Command. The tool cannot build any other command in this format.
      - id: body
        type:
          switch-on: cmd
          cases:
            'rom_cmd::debug': dh6000_debug_body
            'rom_cmd::download': dh6000_download_body
            'rom_cmd::run': dh6000_run_body
            _: dh6000_addr_value_body
        doc: Arguments and trailing checksum.
  dh6000_debug_body:
    doc: DEBUG repeats the command byte and has no checksum (frame 00 14 14).
    seq:
      - id: cmd_again
        contents: [0x14]
        doc: The command byte again.
  dh6000_addr_value_body:
    doc: READ (count in words) or WRITE (value).
    seq:
      - id: addr
        type: u4
        doc: Address.
      - id: value_or_count
        type: u4
        doc: Word count for READ, the value for WRITE.
      - id: checksum
        type: u4
        doc: Sum of the 8 preceding bytes, as a u32.
  dh6000_run_body:
    doc: RUN.
    seq:
      - id: addr
        type: u4
        doc: Address to jump to.
      - id: checksum
        type: u4
        doc: Sum of the 4 address bytes, as a u32.
  dh6000_download_body:
    doc: DOWNLOAD. Unlike Mini, the count field is in bytes and the checksum covers only the data.
    seq:
      - id: addr
        type: u4
        doc: Destination address.
      - id: byte_count
        type: u4
        doc: Data length in bytes (the tool sends words * 4).
      - id: data
        size: byte_count
        doc: The data.
      - id: checksum
        type: u4
        doc: Sum of the data bytes only, as a u32.
  dh6000_status_frame:
    doc: |
      Device status frame in DH6000 format, 00 <code> ?? 01. The tool treats code 0x03 as "the
      last command succeeded" and any other code as that command's echo. Its separate ack is the
      single byte 0x08 (rom_cmd::dh6000_idle).
    seq:
      - id: lead
        contents: [0x00]
        doc: Lead byte.
      - id: code
        type: u1
        enum: rom_cmd
        doc: 0x03 (dh6000_ok) or a command echo.
      - id: arg
        type: u1
        doc: Not interpreted by the tool.
      - id: trail
        contents: [0x01]
        doc: Trailing byte.
enums:
  rom_cmd:
    0x00:
      id: invalid
      doc: Unused value in the tool's enumeration.
    0x02:
      id: dh6000_err
      doc: DH6000-format error code (tool enumeration).
    0x03:
      id: dh6000_ok
      doc: DH6000 status "last command OK".
    0x05:
      id: ok
      doc: Mini-format OK (02 05 00 03), seen from the DM-32 ROM and loader.
    0x08:
      id: dh6000_idle
      doc: DH6000 one-byte ack.
    0x0a:
      id: err
      doc: Mini-format error code (tool enumeration).
    0x14:
      id: debug
      doc: Host reply to NOTIFY that keeps the ROM in its command loop (02 14 00 03).
    0x18:
      id: download
      doc: Store words at an address.
    0x19:
      id: write
      doc: Write one word.
    0x1a:
      id: read
      doc: Read words.
    0x1b:
      id: run
      doc: Jump to an address.
    0x24:
      id: notify
      doc: Sent by the ROM at reset (02 24 00 03).
    0x45:
      id: erase
      doc: Erase (tool's mini-boot mode); semantics on the DM-32 unknown.
    0x55:
      id: shake
      doc: Handshake code in the tool's enumeration; not seen in any frame it builds.
    0x65:
      id: exit
      doc: Leave the command loop.
    0x75:
      id: miniboot
      doc: Alternative reset notification (the tool's "mini-boot" mode).
    0xaa:
      id: ack
      doc: Ack code in the tool's enumeration.
  loader_cmd:
    0x15:
      id: datachip_read
      doc: Read 256 bytes of the 16 MB data chip (W25Q128).
      -dm32-confidence: CONFIRMED
    0x16:
      id: datachip_write
      doc: Program 256 bytes of the data chip. Destroys calibration if aimed at it.
      -dm32-confidence: STRUCTURAL
    0x17:
      id: progflash_read
      doc: Read 256 bytes of the 1 MB program flash (GD25Q80).
      -dm32-confidence: CONFIRMED
    0x18:
      id: progflash_write
      doc: Program 256 bytes of the program flash.
      -dm32-confidence: CONFIRMED

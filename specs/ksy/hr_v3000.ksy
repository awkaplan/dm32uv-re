meta:
  id: hr_v3000
  title: Hongrui HR_V3000 vocoder, UART control/data frames
  ks-version: '0.11'
  endian: be
  bit-endian: be
  -dm32-confidence: DATASHEET
doc: |
  The UART link between a host MCU and the Hongrui (Zhejiang Hongrui Communication Technology)
  HR_V3000 vocoder: an STM32F303RC running DVSI's AMBE++ as a software core. 115200 baud, 8N1,
  no flow control. Every frame is a 0x61 start byte, a 2-byte big-endian DATA length, a 1-byte
  type and DATA. The UART only carries control and *coded* (compressed) voice; uncompressed PCM
  goes over I2S and the normal coded-voice path to the baseband chip is the vocoder's V_SPI bus
  (Cmd 0x03 write / 0x83 read + Addr 0x00 + 27 bytes), neither of which this file describes.

  RELATION TO DVSI AMBE-3000. The framing is DVSI's AMBE-3000 packet format: the same start
  byte, the same payload-only length, type 0x00 = control and type 0x01 = channel (coded) data,
  and the same control field IDs for ECMODE (0x05), DCMODE (0x06), PRODID (0x30), VERSTRING
  (0x31) and READY (0x39). Cross-checked against the public DVSI AMBE-3000R Vocoder Chip User's
  Manual as transcribed by three open-source AMBE-3000 tools: serialDV (github.com/f4exb/serialDV,
  dvcontroller.h, GPL-3.0), tcd (github.com/nostar/tcd, DVSIPacket.h, GPL-3.0) and zumspotpy
  (github.com/spectriclabs/zumspotpy, ambeserver.py, Apache-2.0, which cites DVSI manual
  v2.2 Tables 12-15 for the mode words). No code is copied from them. Where the HR_V3000 differs:
    - type 0x03 is ENCP, coded data to/from the ENCODER. DVSI's 0x02 is a speech (PCM) packet;
      the HR_V3000 has no PCM over UART.
    - DECP/ENCP DATA is the bare coded bits ("纯编码数据"). DVSI channel/speech packets carry
      tagged fields (CHAND 0x01 + bit count, SPEECHD 0x00 + sample count) and optional channel
      selectors 0x40-0x42.
    - a control packet holds ONE command (DATA[0]) plus its parameters. DVSI packs several
      field IDs per packet.
    - the acknowledgement echoes only the command code (DATA length 1). DVSI answers each field
      ID with the ID plus a status byte.
    - vendor command codes 0xa0-0xb5 (encoder/decoder start/stop, encryption-detour on/off,
      record/playback source, AGC, tone/DTMF, error counters, GPIO). None are DVSI field IDs.
    - ECMODE bit 13 is AGC_ON here; in DVSI's table it is the echo canceller (EC_ENABLE). DVSI
      bits 7-9 (CP_SELECT, CP_ENABLE, ES_ENABLE) and DCMODE bits 2, 7, 8 are reserved here.
    - DVSI-only fields (RATET 0x09, RATEP 0x0a, INIT 0x0b, GAIN 0x4b, PARITYBYTE 0x2f, ...) do
      not appear in the HR_V3000 manual. No parity byte appears in any HR_V3000 example.

  DM-32UV: THE STOCK FIRMWARE HAS NO HR_V3000 DRIVER. Checked against DM32.00.01.048
  (2026-10-11): no frame template (61 00 01 00 / 61 00 03 00 / 61 00 02 00 / 61 00 1b) in the
  app image, the 1 MB program-flash image or the derived IRAM image; no `movi`/`cmpnei` of 0x61
  in the IRAM code (capstone-csky linear sweep, 47,771 instructions), and in the flash app
  region (0x03001000-0x030d2000, 321,079 instructions) only 12, none a frame builder: XMODEM
  @0x0300468c, ASCII in codeplug defaults / display code, a settings clamp @0x0304abcc and byte
  tables decoded as code. The only UART besides the
  CPS/console UART0 (uart0_init @0x0301da48, 115200, called with 0xe1<<9 from
  radio_boot_full_init_sequence @0x0305f326) is UART1 @0x14040000, set up by gps_uart1_init_9600
  @0x0301d96c: 9600 baud (clock / 0x25800), called only when option byte bit 2 is set
  (@0x0305f310-0x0305f31e), and its only transmitter (uart_tx_chunked_mutex_send @0x0301d9d4,
  called from FUN_030119f4) sends ASCII strings with a CR LF terminator taken from 0x03081e0c,
  next to the CASIC GPS commands "$PCAS03,...", "$PCAS00*01", "$PCAS05,2*1A", "$PCAS04,3*1A"
  (0x03081e10-0x03081e4c). That is the GPS receiver (ATGM336H), not a vocoder. The HR_C7000
  datasheet (v2.7 en, 7.1.1, p.473) describes a built-in vocoder, which is what this radio uses.
  This description is therefore for other HR_C5000/HR_C7000 boards that do populate an HR_V3000,
  and for anyone probing one; it has no DM-32 capture to be tested against.
doc-ref:
  - HR_V3000 声码器使用说明文档 (HR_V3000 vocoder user manual) v1.2, 2013-09-11, 4.2.1, p.11-13; 5, p.13-14; A.1, p.22
  - DVSI AMBE-3000R Vocoder Chip User's Manual (packet interface; mode-word tables 12-15 in v2.2)
seq:
  - id: frames
    type: frame
    repeat: eos
    doc: A capture of the UART in one direction, or a single frame.
    -dm32-confidence: DATASHEET
types:
  frame:
    doc: One UART frame, Header(1) + Length(2) + Type(1) + DATA(Length).
    doc-ref: HR_V3000 manual v1.2, 4.2.1, p.11
    seq:
      - id: start
        contents: [0x61]
        doc: Header byte, always 0x61 (same as DVSI's packet start byte).
        doc-ref: HR_V3000 manual v1.2, 4.2.1 frame-format table, p.11
        -dm32-confidence: DATASHEET
      - id: len_data
        type: u2
        doc: |
          Length of DATA only; the header, the length itself and the type byte are not counted
          (n >= 1). Big-endian: every example sends the high byte first (0x00, 0x01). The manual
          says "Header 的最高 bit 首先输出" (the header's most significant bit is sent first);
          its examples show this means most-significant BYTE first. Bit order on the wire is
          ordinary UART.
        doc-ref: HR_V3000 manual v1.2, 4.2.1 frame-format table, p.11
        -dm32-confidence: DATASHEET
      - id: type
        type: u1
        enum: packet_type
        doc: What DATA holds. Values other than 0x00/0x01/0x03 are reserved.
        doc-ref: HR_V3000 manual v1.2, 4.2.1 type table, p.11-12
        -dm32-confidence: DATASHEET
      - id: data
        size: len_data
        type:
          switch-on: type
          cases:
            'packet_type::ccp': control_packet
            'packet_type::decp': coded_voice
            'packet_type::encp': coded_voice
        doc: DATA. A reserved type is kept as raw bytes.
        doc-ref: HR_V3000 manual v1.2, 4.2.1, p.11-12
        -dm32-confidence: DATASHEET

  control_packet:
    doc: |
      Type CCP. DATA[0] is the command code; DATA[1..Length-1], when Length > 1, are its
      parameters. Host-to-vocoder commands and vocoder-to-host answers share this layout, and
      direction is not on the wire: the vocoder acknowledges every command it accepts with a
      frame of Length 1 holding the same code (so a 1-byte ECMODE packet is an ACK, a 3-byte one
      is a command), and the host waits for the ACK before sending the next command. READY and
      PLAYRAMRDY are only ever sent by the vocoder. PRODID, VERSTRING, ERR_RATE and TTL_ERRS
      answers carry a value after the code.
    doc-ref: HR_V3000 manual v1.2, 4.2.1, p.12-13; A.1, p.22
    seq:
      - id: code
        type: u1
        enum: control_code
        doc: Command code (指令码字).
        doc-ref: HR_V3000 manual v1.2, 4.2.1 command table, p.12; A.1, p.22
        -dm32-confidence: DATASHEET
      - id: params
        size: _parent.len_data - 1
        if: _parent.len_data > 1
        type:
          switch-on: code
          cases:
            'control_code::ecmode': ecmode_word
            'control_code::dcmode': dcmode_word
            'control_code::prodid': chip_id
            'control_code::verstring': version_string
            'control_code::decsrc': decoder_source
            'control_code::recsrc': record_source
            'control_code::set_dbm0_level': level_db
            'control_code::max_db_gain': level_db
            'control_code::min_db_gain': level_db
            'control_code::enc_tone_index': tone_index
            'control_code::enc_tone_level': level_db
            'control_code::dec_tone_index': tone_index
            'control_code::dec_tone_level': level_db
            'control_code::err_rate': error_rate
            'control_code::ttl_errs': error_bits
            'control_code::gpio_set': gpio_mask
            'control_code::gpio_reset': gpio_mask
        doc: |
          Parameters, present only when Length > 1. Codes with no parameter type here
          (or unknown codes) keep their parameters as raw bytes.
        doc-ref: HR_V3000 manual v1.2, A.1, p.22
        -dm32-confidence: DATASHEET

  ecmode_word:
    doc: |
      ECMODE, the 16-bit encoder mode word, sent high byte first. A set bit enables the
      function; reserved bits must be 0. Example (4.2.1): 0x1840 = tone detect + DTX + noise
      suppression, which matches the defaults the manual states for DTX_ENABLE and NS_ENABLE.
      Bit positions 6, 11, 12 and 14 match DVSI's ECMODE_IN; bit 13 does not (see top-level doc).
      Register view: specs/rdl/hr_v3000_modes.rdl.
    doc-ref: HR_V3000 manual v1.2, 5, ECMODE table, p.13-14
    seq:
      - id: reserved_15
        type: b1
        doc: Bit 15, reserved, write 0.
        doc-ref: HR_V3000 manual v1.2, ECMODE table, p.13
        -dm32-confidence: DATASHEET
      - id: dtmf_send
        type: b1
        doc: |
          Bit 14 DTMF_SEND. When set the encoder ignores speech and encodes the tone selected by
          ENC_TONE_INDEX at ENC_TONE_LEVEL. (DVSI name TS_ENABLE, tone send.)
        doc-ref: HR_V3000 manual v1.2, ECMODE table p.13; 5.3, p.15-16
        -dm32-confidence: DATASHEET
      - id: agc_on
        type: b1
        doc: |
          Bit 13 AGC_ON, input automatic gain control (targets SET_DBM0_LEVEL within
          MIN_DB_GAIN..MAX_DB_GAIN). DVSI's table has the echo canceller (EC_ENABLE) here.
        doc-ref: HR_V3000 manual v1.2, ECMODE table p.13; 5.4, p.16-17
        -dm32-confidence: DATASHEET
      - id: tone_det_enable
        type: b1
        doc: Bit 12 TONE_DET_ENABLE, single/dual-tone detection. (DVSI name TD_ENABLE.)
        doc-ref: HR_V3000 manual v1.2, ECMODE table, p.13
        -dm32-confidence: DATASHEET
      - id: dtx_enable
        type: b1
        doc: |
          Bit 11 DTX_ENABLE, discontinuous transmission: the encoder emits a standard silence
          frame during speech gaps. Default 1. (DVSI name DTX_ENABLE.)
        doc-ref: HR_V3000 manual v1.2, ECMODE table p.13; 5.1, p.14
        -dm32-confidence: DATASHEET
      - id: reserved_10_7
        type: b4
        doc: Bits 10-7, reserved, write 0.
        doc-ref: HR_V3000 manual v1.2, ECMODE table, p.13
        -dm32-confidence: DATASHEET
      - id: ns_enable
        type: b1
        doc: |
          Bit 6 NS_ENABLE, background noise suppression on speech and silence frames (not on
          tone frames); takes a few seconds to act. Default 1. (DVSI name NS_ENABLE.)
        doc-ref: HR_V3000 manual v1.2, ECMODE table p.13; 5.2, p.15
        -dm32-confidence: DATASHEET
      - id: reserved_5_0
        type: b6
        doc: Bits 5-0, reserved, write 0.
        doc-ref: HR_V3000 manual v1.2, ECMODE table, p.13
        -dm32-confidence: DATASHEET

  dcmode_word:
    doc: |
      DCMODE, the 16-bit decoder mode word, high byte first. Reserved bits must be 0.
      Bits 3 and 14 match DVSI's DCMODE_IN (CNI_FRAME, TS_ENABLE). Register view:
      specs/rdl/hr_v3000_modes.rdl.
    doc-ref: HR_V3000 manual v1.2, 5, DCMODE table, p.14
    seq:
      - id: reserved_15
        type: b1
        doc: Bit 15, reserved, write 0.
        doc-ref: HR_V3000 manual v1.2, DCMODE table, p.14
        -dm32-confidence: DATASHEET
      - id: dtmf_send
        type: b1
        doc: |
          Bit 14 DTMF_SEND. When set the decoder ignores coded input and plays the tone selected
          by DEC_TONE_INDEX at DEC_TONE_LEVEL.
        doc-ref: HR_V3000 manual v1.2, DCMODE table p.14; 5.3, p.15-16
        -dm32-confidence: DATASHEET
      - id: reserved_13_4
        type: b10
        doc: Bits 13-4, reserved, write 0.
        doc-ref: HR_V3000 manual v1.2, DCMODE table, p.14
        -dm32-confidence: DATASHEET
      - id: cni_frame
        type: b1
        doc: |
          Bit 3 CNI_FRAME. When set the decoder outputs comfort noise continuously. Default 0.
        doc-ref: HR_V3000 manual v1.2, DCMODE table p.14; 5.1, p.14
        -dm32-confidence: DATASHEET
      - id: reserved_2_0
        type: b3
        doc: Bits 2-0, reserved, write 0.
        doc-ref: HR_V3000 manual v1.2, DCMODE table, p.14
        -dm32-confidence: DATASHEET

  chip_id:
    doc: PRODID answer (Length 13). Per-chip data on real hardware; never commit a real one.
    doc-ref: HR_V3000 manual v1.2, 5.9.2, p.21
    seq:
      - id: id
        size: 12
        doc: The chip's fixed 96-bit ID (ID[0-11]). Byte order inside it is not documented.
        doc-ref: HR_V3000 manual v1.2, 5.9.2, p.21
        -dm32-confidence: DATASHEET

  version_string:
    doc: VERSTRING answer (Length >= 7).
    doc-ref: HR_V3000 manual v1.2, 5.9.2, p.21; A.1, p.22
    seq:
      - id: text
        type: str
        size-eos: true
        encoding: ASCII
        doc: '"V" followed by a dotted version, e.g. "V1.2.0" (no terminator in the example).'
        doc-ref: HR_V3000 manual v1.2, 5.9.2, p.21
        -dm32-confidence: DATASHEET

  decoder_source:
    doc: DECSRC parameter (Length 2).
    doc-ref: HR_V3000 manual v1.2, 5.6.1-5.6.2, p.18-19
    seq:
      - id: source
        type: u1
        enum: dec_source
        doc: Where the decoder takes coded data from. Default 0.
        doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18
        -dm32-confidence: DATASHEET

  record_source:
    doc: RECSRC parameter (Length 2).
    doc-ref: HR_V3000 manual v1.2, 5.6.1-5.6.2, p.18
    seq:
      - id: source
        type: u1
        enum: rec_source
        doc: |
          Which coded stream the vocoder copies to the host every 60 ms (encoder output as ENCP,
          decoder input as DECP). Values other than 1-3 turn recording off.
        doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18
        -dm32-confidence: DATASHEET

  level_db:
    doc: |
      A signed 16-bit level ("short"), high byte first. SET_DBM0_LEVEL in dBm0 (default -22),
      MAX_DB_GAIN / MIN_DB_GAIN in dB (defaults 20 / -10), ENC_/DEC_TONE_LEVEL in dBm0
      (default -20). The examples use whole units (0xfff4 = -12).
    doc-ref: HR_V3000 manual v1.2, 5.3-5.4, p.15-17
    seq:
      - id: value
        type: s2
        doc: Level, whole dB / dBm0.
        doc-ref: HR_V3000 manual v1.2, 5.3.2 and 5.4.2 examples, p.16-17
        -dm32-confidence: DATASHEET

  tone_index:
    doc: ENC_TONE_INDEX / DEC_TONE_INDEX parameter, a 16-bit value, high byte first.
    doc-ref: HR_V3000 manual v1.2, 5.3, p.15-16; A.2, p.23-24
    seq:
      - id: index
        type: u2
        enum: tone
        doc: |
          Tone index (A.2). 5-122 are single tones at index * 31.25 Hz (156.25-3812.5 Hz), and
          are left unnamed in the enum; 128-143 DTMF, 144-159 KNOX, 160-163 call progress,
          255 no tone; everything else is invalid. The manual calls the parameter "short";
          all valid values are < 256 so signedness does not matter.
        doc-ref: HR_V3000 manual v1.2, A.2, p.23-24
        -dm32-confidence: DATASHEET

  error_rate:
    doc: ERR_RATE answer (Length 3).
    doc-ref: HR_V3000 manual v1.2, 5.5, p.17
    seq:
      - id: raw
        type: u2
        doc: |
          Bit-error rate * 2^17; divide by 131072. The manual's example reads "0xbb, b8" for the
          value 3000, which is 0x0bb8: a typo in the manual (0xbbb8 would be 48056).
        doc-ref: HR_V3000 manual v1.2, 5.5.1-5.5.2, p.17
        -dm32-confidence: DATASHEET
    instances:
      rate:
        value: raw / 131072.0
        doc: The error rate as a fraction.
        doc-ref: HR_V3000 manual v1.2, 5.5.1, p.17
        -dm32-confidence: DATASHEET

  error_bits:
    doc: TTL_ERRS answer (Length 3).
    doc-ref: HR_V3000 manual v1.2, 5.5, p.17
    seq:
      - id: count
        type: u2
        doc: Number of bit errors in the last received frame.
        doc-ref: HR_V3000 manual v1.2, 5.5.2, p.17
        -dm32-confidence: DATASHEET

  gpio_mask:
    doc: |
      GPIO_SET / GPIO_RESET parameter (Length 3), high byte first; bit n = vocoder output IOn,
      1 = act on this pin. All 16 outputs start low. A.1 lists the command Length of both as 1,
      which contradicts 4.2.1 ("参数长度为2个字节") and the 5.8.2 examples (Length 3); the
      examples are taken as correct.
    doc-ref: HR_V3000 manual v1.2, 5.8, p.20-21; A.1, p.22
    seq:
      - id: pins
        type: u2
        doc: Pin mask, bit 15 = IO15 ... bit 0 = IO0.
        doc-ref: HR_V3000 manual v1.2, 5.8.1, p.20
        -dm32-confidence: DATASHEET

  coded_voice:
    doc: |
      Type DECP or ENCP: bare coded voice, no field tags. In every example DATA is 27 bytes
      (216 bits) and one such frame moves every 60 ms (3600 bit/s), used for recording,
      playback and the encryption detour (host encrypts/decrypts and sends it back). 216 bits
      per 60 ms is three 72-bit AMBE+2 frames at 3600 bit/s with FEC (the DMR rate); the manual
      does not say how the 216 bits split, so that is an inference.
    doc-ref: HR_V3000 manual v1.2, 5.6-5.7, p.18-20
    seq:
      - id: bits
        size-eos: true
        doc: The coded bits, 27 bytes in every documented case. Inner layout undocumented.
        doc-ref: HR_V3000 manual v1.2, 5.6.2 and 5.7.2, p.18-20
        -dm32-confidence: DATASHEET
    instances:
      is_standard_size:
        value: _io.size == 27
        doc: True for the documented 216-bit frame.
        doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18
        -dm32-confidence: DATASHEET

enums:
  packet_type:
    0x00:
      id: ccp
      doc: Control packet (CCP). DVSI uses 0x00 for control too.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 type table, p.11
    0x01:
      id: decp
      doc: Decoder data (DECP), coded voice into or out of the decoder. DVSI 0x01 = channel data.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 type table, p.11
    0x03:
      id: encp
      doc: Encoder data (ENCP), coded voice out of or back into the encoder. Not a DVSI type.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 type table, p.11

  control_code:
    0x05:
      id: ecmode
      doc: Set encoder mode word (Length 3, ACK 1). Same field ID as DVSI PKT_ECMODE.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0x06:
      id: dcmode
      doc: Set decoder mode word (Length 3, ACK 1). Same field ID as DVSI PKT_DCMODE.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0x30:
      id: prodid
      doc: Read the 96-bit chip ID (Length 1, answer 13). Same ID as DVSI PKT_PRODID.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.9.2 p.21; A.1 p.22
    0x31:
      id: verstring
      doc: Read the version string (Length 1, answer >= 7). Same ID as DVSI PKT_VERSTRING.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.9.2 p.21; A.1 p.22
    0x39:
      id: ready
      doc: Vocoder to host only, after init or wake-up; the host must wait for it. Same ID as DVSI PKT_READY.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.9.2 p.21; A.1 p.22
    0xa0:
      id: encoderstart
      doc: Encoder on.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0xa1:
      id: encoderstop
      doc: Encoder off.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0xa2:
      id: decoderstart
      doc: Decoder on.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0xa3:
      id: decoderstop
      doc: Decoder off.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0xa4:
      id: encrypton
      doc: Encryption detour on (encoder output goes to the host and back). The vocoder has no cipher of its own.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.7 p.19-20; A.1 p.22
    0xa5:
      id: encryptoff
      doc: Encryption detour off.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0xa6:
      id: decrypton
      doc: Decryption detour on (decoder input goes to the host and back).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.7 p.19-20; A.1 p.22
    0xa7:
      id: decryptoff
      doc: Decryption detour off.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; A.1 p.22
    0xa8:
      id: decsrc
      doc: Decoder data source (Length 2).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.6 p.18-19; A.1 p.22
    0xa9:
      id: recsrc
      doc: Recording source (Length 2).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.6 p.18; A.1 p.22
    0xaa:
      id: playramrdy
      doc: Vocoder to host only, every 60 ms in playback mode - the playback buffer can take one 27-byte DECP frame.
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.6.2 p.19; A.1 p.22
    0xab:
      id: set_dbm0_level
      doc: AGC target level, s16 dBm0 (Length 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.4 p.16-17; A.1 p.22
    0xac:
      id: max_db_gain
      doc: AGC maximum input gain, s16 dB (Length 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.4 p.16-17; A.1 p.22
    0xad:
      id: min_db_gain
      doc: AGC minimum input gain, s16 dB (Length 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.4 p.16-17; A.1 p.22
    0xae:
      id: enc_tone_index
      doc: Encoder tone/DTMF index (Length 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.3 p.15-16; A.1 p.22
    0xaf:
      id: enc_tone_level
      doc: Encoder tone level, s16 dBm0 (Length 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.3 p.15-16; A.1 p.22
    0xb0:
      id: dec_tone_index
      doc: Decoder tone/DTMF index (Length 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.3 p.15-16; A.1 p.22
    0xb1:
      id: dec_tone_level
      doc: Decoder tone level, s16 dBm0 (Length 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.3 p.15-16; A.1 p.22
    0xb2:
      id: err_rate
      doc: Read the bit-error rate (Length 1, answer 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.5 p.17; A.1 p.22
    0xb3:
      id: ttl_errs
      doc: Read the bit errors of one frame (Length 1, answer 3).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.5 p.17; A.1 p.22
    0xb4:
      id: gpio_set
      doc: Drive the masked vocoder outputs high (Length 3; A.1 says 1, see gpio_mask).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.8 p.20; A.1 p.22
    0xb5:
      id: gpio_reset
      doc: Drive the masked vocoder outputs low (Length 3; A.1 says 1, see gpio_mask).
      doc-ref: HR_V3000 manual v1.2, 4.2.1 p.12; 5.8 p.20-21; A.1 p.22

  dec_source:
    0:
      id: baseband
      doc: The host baseband chip over V_SPI (the manual names the HR_C5000). Default.
      doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18
    1:
      id: playback_buffer
      doc: The playback buffer, filled by the host with DECP frames.
      doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18

  rec_source:
    1:
      id: encoder
      doc: Record the encoder's output (sent as ENCP).
      doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18
    2:
      id: decoder
      doc: Record the decoder's input (sent as DECP).
      doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18
    3:
      id: both
      doc: Record both.
      doc-ref: HR_V3000 manual v1.2, 5.6.1, p.18

  tone:
    128: {id: dtmf_0, doc: '1336 + 941 Hz'}
    129: {id: dtmf_1, doc: '1209 + 697 Hz'}
    130: {id: dtmf_2, doc: '1336 + 697 Hz'}
    131: {id: dtmf_3, doc: '1477 + 697 Hz'}
    132: {id: dtmf_4, doc: '1209 + 770 Hz'}
    133: {id: dtmf_5, doc: '1336 + 770 Hz'}
    134: {id: dtmf_6, doc: '1477 + 770 Hz'}
    135: {id: dtmf_7, doc: '1209 + 852 Hz'}
    136: {id: dtmf_8, doc: '1336 + 852 Hz'}
    137: {id: dtmf_9, doc: '1477 + 852 Hz'}
    138: {id: dtmf_a, doc: '1633 + 697 Hz'}
    139: {id: dtmf_b, doc: '1633 + 770 Hz'}
    140: {id: dtmf_c, doc: '1633 + 852 Hz'}
    141: {id: dtmf_d, doc: '1633 + 941 Hz'}
    142: {id: dtmf_star, doc: '1209 + 941 Hz'}
    143: {id: dtmf_hash, doc: '1477 + 941 Hz'}
    144: {id: knox_0, doc: '1162 + 820 Hz'}
    145: {id: knox_1, doc: '1052 + 606 Hz'}
    146: {id: knox_2, doc: '1162 + 606 Hz'}
    147: {id: knox_3, doc: '1279 + 606 Hz'}
    148: {id: knox_4, doc: '1052 + 672 Hz'}
    149: {id: knox_5, doc: '1162 + 672 Hz'}
    150: {id: knox_6, doc: '1279 + 672 Hz'}
    151: {id: knox_7, doc: '1052 + 743 Hz'}
    152: {id: knox_8, doc: '1162 + 743 Hz'}
    153: {id: knox_9, doc: '1279 + 743 Hz'}
    154: {id: knox_a, doc: '1430 + 606 Hz'}
    155: {id: knox_b, doc: '1430 + 672 Hz'}
    156: {id: knox_c, doc: '1430 + 743 Hz'}
    157: {id: knox_d, doc: '1430 + 820 Hz'}
    158: {id: knox_star, doc: '1052 + 820 Hz'}
    159: {id: knox_hash, doc: '1279 + 820 Hz'}
    160: {id: call_progress_440_350, doc: '440 + 350 Hz'}
    161: {id: call_progress_480_440, doc: '480 + 440 Hz'}
    162: {id: call_progress_620_480, doc: '620 + 480 Hz'}
    163: {id: call_progress_490_350, doc: '490 + 350 Hz'}
    255: {id: no_tone, doc: 'No tone (A.2, p.24)'}

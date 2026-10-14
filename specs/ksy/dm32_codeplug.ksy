meta:
  id: dm32_codeplug
  title: DM-32UV codeplug - the logical-ID-tagged config region of the data chip
  file-extension: bin
  endian: le
  ks-version: '0.11'
  imports:
    - dm32_calibration
  -dm32-confidence: STRUCTURAL
doc: |
  The codeplug of a DM-32UV: the 4 KB pages of the 16 MB W25Q128 data chip whose last byte
  (+0xFFF) is a logical block ID. The root is any page-aligned read of that region (one page or
  many); every page is decoded on its own, by its tag, so the input may start at any page.

  ADDRESSING. A logical ID occurs on at most one page; which page is decided by the radio
  (flash-translation-layer style) and differs between units and after every codeplug edit. Never
  hardcode a page: scan the tags. The stock firmware keeps the tag of every config page in a
  200-entry RAM table (IRAM 0x0002feb4, one byte per page, page 0..199), filled by
  flash_page_tag_search and walked by flash_block_id_resolve from index 1; the data-chip address
  is then (page << 12) | offset. The OEM CPS finds the same region through V-frame 0x0A as
  0x001000-0x0C8FFF (pages 1..200); page 200 lies outside the firmware's 200-entry table, which
  is not explained (see dm32_datachip.ksy).

  TAG VALUES. 0xFF = erased/free page. 0x00 = page tag of a superseded copy (several pages can
  carry it; their content is older versions of live blocks). Every other value is one logical
  block, decoded by `config_page`. Blocks whose layout is not established are kept as raw bytes
  (`config_page.block` is then a byte array), and every decoded block covers all 4096 bytes, so a
  page always serializes back byte for byte.

  FIDELITY. Text fields are decoded as ISO-8859-1 so that every byte, including 0x00/0xFF fill
  and stale bytes after a terminator, survives a round trip; the content is ASCII and ends at
  the first 0x00 or 0xFF. Fill differs by writer (0x00 on a factory radio, 0xFF from the OEM
  CPS), so unknown bytes must be preserved, never regenerated.

  CREDIT. Layouts follow infamy's DM32-Protocol-Spec (MIT License, Copyright (c) 2025 DM-32UV
  Protocol Documentation Contributors; github.com/infamy/DM32-Protocol-Spec, commit 62b9b36,
  2026-08-03), files 04-MEMORY-LAYOUT.md, 05-DATA-STRUCTURES.md, 06-ENCODING.md and
  07-BLOCK-INVENTORY.md, built from OEM CPS serial captures of a DP570UV on firmware
  DM32.01.01.046 and from the NeonPlug implementation. Field names here are this project's. Each
  field was cross-checked against a read of a DM32.00.01.048 radio's data chip and against the
  stock firmware where a consumer is known; disagreements are recorded in the field docs.
  Confidence: CONFIRMED = hardware-attested (infamy's captures and/or this project's read) or
  traced in stock code; STRUCTURAL = offset/stride attested, meaning not; INFERRED = infamy
  marks it DERIVED (from CPS decompilation or the reference implementation only) or it is a guess.
doc-ref:
  - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md (MIT)
  - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md (MIT)
  - infamy/DM32-Protocol-Spec 06-ENCODING.md (MIT)
  - infamy/DM32-Protocol-Spec 07-BLOCK-INVENTORY.md (MIT)
  - DM32.00.01.048 flash_block_id_resolve @0x0300f364, flash_page_tag_search @0x0300f52c
seq:
  - id: pages
    type: config_page
    size: 0x1000
    repeat: eos
    doc: The pages of the read, in address order. Page number = (start address >> 12) + index.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
    -dm32-confidence: CONFIRMED
types:
  config_page:
    doc: One 4 KB page, decoded by the logical block ID in its last byte.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Summary of Logical Block IDs"
    -dm32-confidence: CONFIRMED
    seq:
      - id: block
        size: 0x1000
        doc: |
          The page decoded by tag. Tags without a case are kept as raw bytes: 0x00 and 0xFF (see
          root doc); 0x01, 0x05, 0x07-0x09, 0x0C-0x0E, 0x4B, 0x4F-0x5B, 0x69-0x6E, 0x74, 0x75,
          0x7C (allocated, never read or written by the OEM CPS; several are dense binary on a
          048 radio; purpose unknown, do not write); 0x45-0x48 (talk-group slots 2-5, layout of
          entries beyond slot 1 not established).
        doc-ref: infamy/DM32-Protocol-Spec 07-BLOCK-INVENTORY.md "B. Complete metadata value inventory"
        -dm32-confidence: CONFIRMED
        type:
          switch-on: tag
          cases:
            0x02: dm32_calibration
            0x03: two_tone_block
            0x04: radio_settings_block
            0x06: analog_signalling_block
            0x0a: quick_text_block
            0x0b: talk_group_index_block
            0x0f: rx_group_block
            0x10: emergency_key_block
            0x11: scan_list_block
            0x12: channel_bank_first
            0x13: channel_bank
            0x14: channel_bank
            0x15: channel_bank
            0x16: channel_bank
            0x17: channel_bank
            0x18: channel_bank
            0x19: channel_bank
            0x1a: channel_bank
            0x1b: channel_bank
            0x1c: channel_bank
            0x1d: channel_bank
            0x1e: channel_bank
            0x1f: channel_bank
            0x20: channel_bank
            0x21: channel_bank
            0x22: channel_bank
            0x23: channel_bank
            0x24: channel_bank
            0x25: channel_bank
            0x26: channel_bank
            0x27: channel_bank
            0x28: channel_bank
            0x29: channel_bank
            0x2a: channel_bank
            0x2b: channel_bank
            0x2c: channel_bank
            0x2d: channel_bank
            0x2e: channel_bank
            0x2f: channel_bank
            0x30: channel_bank
            0x31: channel_bank
            0x32: channel_bank
            0x33: channel_bank
            0x34: channel_bank
            0x35: channel_bank
            0x36: channel_bank
            0x37: channel_bank
            0x38: channel_bank
            0x39: channel_bank
            0x3a: channel_bank
            0x3b: channel_bank
            0x3c: channel_bank
            0x3d: channel_bank
            0x3e: channel_bank
            0x3f: channel_bank
            0x40: channel_bank
            0x41: channel_bank_vfo
            0x42: tx_contact_low_block
            0x43: tx_contact_high_block
            0x44: talk_group_block
            0x5c: zone_bank_first
            0x5d: zone_bank
            0x5e: zone_bank
            0x5f: zone_bank
            0x60: zone_bank
            0x61: zone_bank
            0x62: zone_bank
            0x63: zone_bank
            0x64: zone_bank
            0x65: roaming_zone_block
            0x66: roaming_channel_block
            0x67: radio_id_block
    instances:
      tag:
        pos: 0xfff
        type: u1
        doc: Logical block ID (or 0x00 / 0xFF page state). Read first to choose the block type.
        doc-ref:
          - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
          - DM32.00.01.048 flash_page_tag_search @0x0300f52c
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ shared field types
  bcd_freq32:
    doc: |
      Frequency, u32 little-endian packed BCD, 8 digits, 10 Hz units (XXX.XXXXX MHz). 0xFFFFFFFF
      and 0x00000000 mean unset.
    doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "BCD Frequency Encoding"
    -dm32-confidence: CONFIRMED
    seq:
      - id: raw
        type: u4
        doc: Packed BCD as stored.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "BCD Frequency Encoding"
        -dm32-confidence: CONFIRMED
    instances:
      freq_10hz:
        value: >-
          ((raw >> 28) & 15) * 10000000 + ((raw >> 24) & 15) * 1000000
          + ((raw >> 20) & 15) * 100000 + ((raw >> 16) & 15) * 10000
          + ((raw >> 12) & 15) * 1000 + ((raw >> 8) & 15) * 100
          + ((raw >> 4) & 15) * 10 + (raw & 15)
        doc: Frequency in 10 Hz units (meaningless for 0xFFFFFFFF).
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "BCD Frequency Encoding"
        -dm32-confidence: CONFIRMED
  u24:
    doc: Unsigned 24-bit little-endian integer (DMR IDs and talk-group numbers; binary, not BCD).
    doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "Integer Encoding and Endianness"
    -dm32-confidence: CONFIRMED
    seq:
      - id: lo
        type: u2
        doc: Bits 15-0.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "Integer Encoding and Endianness"
        -dm32-confidence: CONFIRMED
      - id: hi
        type: u1
        doc: Bits 23-16.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "Integer Encoding and Endianness"
        -dm32-confidence: CONFIRMED
    instances:
      value:
        value: (hi << 16) | lo
        doc: The integer. 0x000000 and 0xFFFFFF are used as empty (and 0xFFFFFF as All Call).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x67 - DMR Radio ID List"
        -dm32-confidence: CONFIRMED
  tone:
    doc: |
      CTCSS/DCS setting, two bytes [low, high]. FF FF (radio/OEM CPS) or 00 00 = none. high >=
      0x80 = DCS (0x80-0xBF normal, >= 0xC0 inverted), code digits = high & 0x0F, low >> 4,
      low & 0x0F. Otherwise CTCSS in 0.1 Hz as four BCD nibbles high>>4, high&15, low>>4, low&15.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Channel CTCSS / DCS Encoding (bytes 0x21-0x24)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: low
        type: u1
        doc: Low byte (CTCSS ones/tenths, or DCS tens/ones).
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "CTCSS/DCS Encoding"
        -dm32-confidence: CONFIRMED
      - id: high
        type: u1
        doc: High byte (CTCSS hundreds/tens, or DCS flag + hundreds).
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "CTCSS/DCS Encoding"
        -dm32-confidence: CONFIRMED
    instances:
      is_none:
        value: (low == 0xff and high == 0xff) or (low == 0 and high == 0)
        doc: No tone.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "None / Off - read and write are asymmetric"
        -dm32-confidence: CONFIRMED
      is_dcs:
        value: not is_none and high >= 0x80
        doc: DCS rather than CTCSS.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "DCS"
        -dm32-confidence: CONFIRMED
      dcs_inverted:
        value: high >= 0xc0
        doc: DCS polarity inverted (I) rather than normal (N); only meaningful when is_dcs.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "DCS"
        -dm32-confidence: CONFIRMED
      dcs_code:
        value: (high & 15) * 100 + (low >> 4) * 10 + (low & 15)
        doc: DCS code as its decimal digits (e.g. 23 for D023); only meaningful when is_dcs.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "DCS"
        -dm32-confidence: CONFIRMED
      ctcss_tenths_hz:
        value: (high >> 4) * 1000 + (high & 15) * 100 + (low >> 4) * 10 + (low & 15)
        doc: CTCSS frequency in 0.1 Hz; only meaningful when neither is_none nor is_dcs.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "CTCSS"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ channels (0x12-0x41)
  channel:
    doc: |
      One 48-byte channel record. The TX contact (talk group) is NOT in it: see
      tx_contact_low_block / tx_contact_high_block. Bytes 0x1D and 0x1F mean different things on
      analog and digital channels (see the value instances). An all-0x00/0xFF record is an empty
      slot that still consumes its channel number.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Channel Structure (48 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: name
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: ASCII, NUL-terminated then padded; a 16-character name has no terminator.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "The 16-character channel name has no terminator"
        -dm32-confidence: CONFIRMED
      - id: rx_freq
        type: bcd_freq32
        doc: Receive frequency.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field-by-Field Breakdown"
        -dm32-confidence: CONFIRMED
      - id: tx_freq
        type: bcd_freq32
        doc: Transmit frequency.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field-by-Field Breakdown"
        -dm32-confidence: CONFIRMED
      - id: mode
        type: b4
        enum: channel_mode
        doc: Byte 0x18 bits 7-4.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x18 (24)"
        -dm32-confidence: CONFIRMED
      - id: forbid_tx
        type: b1
        doc: Byte 0x18 bit 3.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x18 (24)"
        -dm32-confidence: CONFIRMED
      - id: power
        type: b2
        doc: Byte 0x18 bits 2-1; 0 low, 1 medium, 2 high (CPS level, not a calibration index).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x18 (24)"
        -dm32-confidence: CONFIRMED
      - id: lone_worker
        type: b1
        doc: Byte 0x18 bit 0.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x18 (24)"
        -dm32-confidence: CONFIRMED
      - id: bandwidth_wide
        type: b1
        doc: Byte 0x19 bit 7; 1 = 25 kHz, 0 = 12.5 kHz. Polarity strongly indicated, not directly attested.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x19 (25)"
        -dm32-confidence: INFERRED
      - id: scan_add
        type: b1
        doc: Byte 0x19 bit 6 (CPS "Auto Scan").
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x19 (25)"
        -dm32-confidence: CONFIRMED
      - id: scan_list_id
        type: b4
        doc: Byte 0x19 bits 5-2; 0 = none.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x19 (25)"
        -dm32-confidence: CONFIRMED
      - id: unknown_19
        type: b2
        doc: Byte 0x19 bits 1-0, unknown; preserve.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x19 (25)"
        -dm32-confidence: STRUCTURAL
      - id: forbid_talkaround
        type: b1
        doc: Byte 0x1A bit 7.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1A (26)"
        -dm32-confidence: CONFIRMED
      - id: unknown_1a_6_4
        type: b3
        doc: Byte 0x1A bits 6-4, unknown setting; carries data on hardware.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1A (26)"
        -dm32-confidence: STRUCTURAL
      - id: unknown_1a_3
        type: b1
        doc: Byte 0x1A bit 3, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1A (26)"
        -dm32-confidence: STRUCTURAL
      - id: aprs_receive
        type: b1
        doc: Byte 0x1A bit 2.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1A (26)"
        -dm32-confidence: CONFIRMED
      - id: unknown_1a_1_0
        type: b2
        doc: Byte 0x1A bits 1-0, unknown; the OEM CPS writes 3 on every channel.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1A (26)"
        -dm32-confidence: STRUCTURAL
      - id: emergency_indicator
        type: b1
        doc: Byte 0x1B bit 7.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1B (27)"
        -dm32-confidence: CONFIRMED
      - id: emergency_ack
        type: b1
        doc: Byte 0x1B bit 6.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1B (27)"
        -dm32-confidence: CONFIRMED
      - id: unknown_1b_5
        type: b1
        doc: Byte 0x1B bit 5, unknown (set by the OEM CPS); may be bit 5 of a 6-bit system ID.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1B (27)"
        -dm32-confidence: STRUCTURAL
      - id: emergency_system_id
        type: b5
        doc: Byte 0x1B bits 4-0 (5 or 6 bits wide, unresolved).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1B (27)"
        -dm32-confidence: INFERRED
      - id: squelch_level
        type: b4
        doc: Byte 0x1C bits 7-4, 0-15.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1C (28)"
        -dm32-confidence: CONFIRMED
      - id: aprs_report_mode
        type: b2
        doc: Byte 0x1C bits 3-2; 0 off, 1 digital, 2 analog.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1C (28)"
        -dm32-confidence: CONFIRMED
      - id: unknown_1c
        type: b2
        doc: Byte 0x1C bits 1-0, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1C (28)"
        -dm32-confidence: STRUCTURAL
      - id: mode_features_1d
        type: u1
        doc: Byte 0x1D, dual-purpose; decoded by the analog_* / digital_* value instances.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Bytes 0x1D (29) and 0x1F (31)"
        -dm32-confidence: CONFIRMED
      - id: unknown_1e
        type: u1
        doc: Byte 0x1E, unknown (not the squelch level, which is at 0x1C). Preserve.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1E (30)"
        -dm32-confidence: STRUCTURAL
      - id: mode_settings_1f
        type: u1
        doc: Byte 0x1F, dual-purpose; decoded by the analog_* / digital_* value instances.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Bytes 0x1D (29) and 0x1F (31)"
        -dm32-confidence: CONFIRMED
      - id: unknown_20
        type: u1
        doc: Byte 0x20, unknown; NOT the colour code. 0x00 in every capture, even OEM writes.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x20 (32)"
        -dm32-confidence: STRUCTURAL
      - id: rx_tone
        type: tone
        doc: Bytes 0x21-0x22, CTC/DCS decode.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Channel CTCSS / DCS Encoding (bytes 0x21-0x24)"
        -dm32-confidence: CONFIRMED
      - id: tx_tone
        type: tone
        doc: Bytes 0x23-0x24, CTC/DCS encode.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Channel CTCSS / DCS Encoding (bytes 0x21-0x24)"
        -dm32-confidence: CONFIRMED
      - id: unknown_25_7_6
        type: b2
        doc: Byte 0x25 bits 7-6, unknown (OEM CPS writes 3).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x25 (37)"
        -dm32-confidence: STRUCTURAL
      - id: compander_copy
        type: b1
        doc: Byte 0x25 bit 5, second copy of the analog compander flag (0x1D bit 5); which copy the firmware honours is unverified.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x25 (37)"
        -dm32-confidence: INFERRED
      - id: vox_flag
        type: b1
        doc: Byte 0x25 bit 4, VOX-related; competes with 0x1D bit 7 for the CPS "VOX Function" control.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x25 (37)"
        -dm32-confidence: INFERRED
      - id: unknown_25_3_0
        type: b4
        doc: Byte 0x25 bits 3-0, unknown setting.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x25 (37)"
        -dm32-confidence: STRUCTURAL
      - id: ptt_id_display_copy
        type: b1
        doc: Byte 0x26 bit 7, copy of PTT ID display (0x1F bit 6 on analog).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x26 (38)"
        -dm32-confidence: INFERRED
      - id: rx_squelch_mode
        type: b3
        doc: Byte 0x26 bits 6-4; 0 carrier/CTC, 1 optional, 2 CTC&opt, 3 CTC|opt.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x26 (38)"
        -dm32-confidence: CONFIRMED
      - id: unknown_26_3_1
        type: b3
        doc: Byte 0x26 bits 3-1, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x26 (38)"
        -dm32-confidence: STRUCTURAL
      - id: unknown_26_0
        type: b1
        doc: Byte 0x26 bit 0, unknown (OEM CPS writes 1).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x26 (38)"
        -dm32-confidence: STRUCTURAL
      - id: step
        type: b4
        doc: Byte 0x27 bits 7-4, step (0 2.5k, 1 5k, 2 6.25k, 3 10k, 4 12.5k, 5 25k, 6 50k, 7 100k); 15 seen = unset.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x27 (39)"
        -dm32-confidence: INFERRED
      - id: signaling_type
        type: b4
        doc: Byte 0x27 bits 3-0 (0 none, 1 DTMF, 2 two-tone, 3 five-tone, 4 MDC1200); 15 seen = unset.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x27 (39)"
        -dm32-confidence: INFERRED
      - id: unknown_28
        type: u1
        doc: Byte 0x28, unknown (0x00 factory, 0xFF OEM CPS).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x28 (40)"
        -dm32-confidence: STRUCTURAL
      - id: ptt_id_type
        type: b4
        doc: Byte 0x29 bits 7-4 (0 off, 1 BOT, 2 EOT, 3 both); 15 seen from the OEM CPS.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x29 (41)"
        -dm32-confidence: INFERRED
      - id: unknown_29_3_2
        type: b2
        doc: Byte 0x29 bits 3-2, unknown setting.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x29 (41)"
        -dm32-confidence: STRUCTURAL
      - id: unknown_29_1_0
        type: b2
        doc: Byte 0x29 bits 1-0, unknown (OEM CPS writes 3).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x29 (41)"
        -dm32-confidence: STRUCTURAL
      - id: encryption_key_2a
        type: u1
        doc: Byte 0x2A; digital channels - encryption key 0 none / 1-8 (keys in block 0x10); analog - unknown. 0xFF seen from the OEM CPS.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x2A (42)"
        -dm32-confidence: INFERRED
      - id: radio_id_index
        type: u1
        doc: Byte 0x2B, index into the radio's own DMR ID list (block 0x67); 0xFF = none. 0- vs 1-based is unresolved.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x2B (43)"
        -dm32-confidence: INFERRED
      - id: unknown_2c
        size: 4
        doc: Bytes 0x2C-0x2F, unknown/padding (0x00 factory, 0xFF OEM CPS).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Bytes 0x2C-0x2F (44-47)"
        -dm32-confidence: STRUCTURAL
    instances:
      is_digital:
        value: mode == channel_mode::digital or mode == channel_mode::fixed_digital
        doc: Selects the digital reading of bytes 0x1D/0x1F.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Bytes 0x1D (29) and 0x1F (31)"
        -dm32-confidence: CONFIRMED
      digital_color_code:
        value: mode_features_1d & 15
        doc: Digital channels - colour code (0x1D bits 3-0).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1D - DIGITAL channels"
        -dm32-confidence: CONFIRMED
      digital_timeslot2:
        value: (mode_features_1d >> 4) & 1 == 1
        doc: Digital channels - timeslot 2 when true, 1 when false (0x1D bit 4).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1D - DIGITAL channels"
        -dm32-confidence: CONFIRMED
      digital_rx_group_list:
        value: mode_settings_1f & 0x3f
        doc: Digital channels - RX group list ID, 0 = none (0x1F bits 5-0).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1F - DIGITAL channels"
        -dm32-confidence: CONFIRMED
      digital_private_call_confirm:
        value: (mode_settings_1f >> 6) & 1 == 1
        doc: Digital channels - private call confirm (0x1F bit 6).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1F - DIGITAL channels"
        -dm32-confidence: INFERRED
      analog_scramble:
        value: (mode_features_1d >> 6) & 1 == 1
        doc: Analog channels - scramble (0x1D bit 6).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1D - ANALOG channels"
        -dm32-confidence: CONFIRMED
      analog_compander:
        value: (mode_features_1d >> 5) & 1 == 1
        doc: Analog channels - compander (0x1D bit 5; copy at 0x25 bit 5).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1D - ANALOG channels"
        -dm32-confidence: CONFIRMED
      analog_ptt_id:
        value: mode_settings_1f & 0x3f
        doc: Analog channels - PTT ID 0-63 (0x1F bits 5-0).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Byte 0x1F - ANALOG channels"
        -dm32-confidence: INFERRED
  channel_bank_first:
    doc: Logical ID 0x12, channel bank slot 1 - 16-byte header with the channel count, then channels 1-84.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel Block Structure"
    -dm32-confidence: CONFIRMED
    seq:
      - id: channel_count
        type: u2
        doc: Total number of channels in the codeplug (all banks). u16, not u32.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel count field width"
        -dm32-confidence: CONFIRMED
      - id: header_fill
        size: 14
        doc: Header bytes 2-15, fill of unknown purpose.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel Block Structure"
        -dm32-confidence: STRUCTURAL
      - id: channels
        type: channel
        repeat: expr
        repeat-expr: 84
        doc: Channels 1-84 (84, not 85, because of the header; confirmed by an 84 + 44 split).
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel bank capacity"
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 47
        doc: 0xFD0-0xFFE, after the last record.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel bank capacity"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x12.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED
  channel_bank:
    doc: |
      Logical IDs 0x13-0x40, channel bank slots 2-47, 85 channels each from offset 0; slot n
      (ID 0x12 + n - 1) holds channels 85 + (n - 2) * 85 onwards.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel bank capacity"
    -dm32-confidence: CONFIRMED
    seq:
      - id: channels
        type: channel
        repeat: expr
        repeat-expr: 85
        doc: 85 channel records.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel bank capacity"
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 15
        doc: 0xFF0-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel bank capacity"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x13-0x40.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED
  channel_bank_vfo:
    doc: |
      Logical ID 0x41: the last channel bank slot AND the home of the VFO A / VFO B records at
      0xF9F / 0xFCF (ordinary channel records). The two uses collide: channel records 83 and 84
      of this slot would overlap the VFOs, so this description decodes 83 channels and the VFOs,
      which is what hardware shows.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x41 - VFO A / VFO B Channel Records"
    -dm32-confidence: CONFIRMED
    seq:
      - id: channels
        type: channel
        repeat: expr
        repeat-expr: 83
        doc: Channel records 0-82 of slot 48 (channels 3995 onwards).
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Channel bank capacity"
        -dm32-confidence: STRUCTURAL
      - id: gap
        size: 15
        doc: 0xF90-0xF9E, between the last whole channel record and VFO A.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x41 - VFO A / VFO B Channel Records"
        -dm32-confidence: STRUCTURAL
      - id: vfo_a
        type: channel
        doc: VFO A at 0xF9F (CPS pseudo-channel 4001); its TX contact is at block 0x43 +0xFFA.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x41 - VFO A / VFO B Channel Records"
        -dm32-confidence: CONFIRMED
      - id: vfo_b
        type: channel
        doc: VFO B at 0xFCF (pseudo-channel 4002); its TX contact is at block 0x43 +0xFFC.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x41 - VFO A / VFO B Channel Records"
        -dm32-confidence: CONFIRMED
      - id: tag
        type: u1
        doc: Logical ID 0x41.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ TX contacts (0x42/0x43)
  tx_contact:
    doc: Per-channel TX contact, 2 bytes - a 12-bit 1-based index into the talk-group list (block 0x44), 0 = none.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "TX contact record (2 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: index_hi
        type: b4
        doc: Index bits 11-8 (byte 0 bits 7-4).
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "12-bit talk-group index split across 2 bytes"
        -dm32-confidence: CONFIRMED
      - id: unknown
        type: b3
        doc: Byte 0 bits 3-1, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "TX contact record (2 bytes)"
        -dm32-confidence: STRUCTURAL
      - id: digital
        type: b1
        doc: Byte 0 bit 0, digital flag.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "TX contact record (2 bytes)"
        -dm32-confidence: INFERRED
      - id: index_lo
        type: u1
        doc: Index bits 7-0.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "12-bit talk-group index split across 2 bytes"
        -dm32-confidence: CONFIRMED
    instances:
      talk_group_index:
        value: (index_hi << 8) | index_lo
        doc: 1-based physical slot in the talk-group block; 0 = none.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "TX contact record (2 bytes)"
        -dm32-confidence: CONFIRMED
  tx_contact_low_block:
    doc: Logical ID 0x42 - TX contacts of channels 1-2047, entry (channel - 1) * 2.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x42 / 0x43 - TX Contact Assignment"
    -dm32-confidence: CONFIRMED
    seq:
      - id: entries
        type: tx_contact
        repeat: expr
        repeat-expr: 2047
        doc: Channels 1-2047. The handover channel to block 0x43 is DERIVED (2047/2048).
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "TX Contact index split"
        -dm32-confidence: STRUCTURAL
      - id: unknown_ffe
        type: u1
        doc: 0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "TX Contact index split"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x42.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED
  tx_contact_high_block:
    doc: Logical ID 0x43 - TX contacts of channels 2048 onwards, entry (channel & 0x7FF) * 2, plus the two VFO entries.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x42 / 0x43 - TX Contact Assignment"
    -dm32-confidence: CONFIRMED
    seq:
      - id: entries
        type: tx_contact
        repeat: expr
        repeat-expr: 2045
        doc: Channels 2048 onwards, up to the VFO entries.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block split point and offset formulas"
        -dm32-confidence: STRUCTURAL
      - id: vfo_a
        type: tx_contact
        doc: VFO A TX contact at 0xFFA.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "TX Contact Assignment (blocks 0x42 / 0x43)"
        -dm32-confidence: CONFIRMED
      - id: vfo_b
        type: tx_contact
        doc: VFO B TX contact at 0xFFC.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "TX Contact Assignment (blocks 0x42 / 0x43)"
        -dm32-confidence: CONFIRMED
      - id: unknown_ffe
        type: u1
        doc: 0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "TX Contact Assignment (blocks 0x42 / 0x43)"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x43.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ talk groups (0x44, 0x0B)
  talk_group:
    doc: |
      One 24-byte talk group ("TX contact" in the CPS). Entry 1 is preceded by the block's
      one-byte header, so names fall at 24 * (n - 1) + 2. A talk group's index is its 1-based
      physical slot (empty slots count).
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry field table (24 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: flag
        type: u1
        doc: Unknown flag (0x00 factory, 0xFF OEM CPS; 0 = created on PC / 1 = on radio is unverified).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry field table (24 bytes)"
        -dm32-confidence: INFERRED
      - id: name
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: ASCII name; ends at the first 0x00 or 0xFF; 16 characters leave no terminator.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry field table (24 bytes)"
        -dm32-confidence: CONFIRMED
      - id: fill_11
        type: u1
        doc: Fill (0x00 factory, 0xFF OEM), not a terminator.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry field table (24 bytes)"
        -dm32-confidence: STRUCTURAL
      - id: number
        type: u24
        doc: DMR talk-group / ID number, u24 LE binary.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry field table (24 bytes)"
        -dm32-confidence: CONFIRMED
      - id: call_type
        type: u1
        enum: call_type
        doc: 3 private, 4 group, 5 all call.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry field table (24 bytes)"
        -dm32-confidence: CONFIRMED
      - id: fill_16
        size: 2
        doc: Fill.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry field table (24 bytes)"
        -dm32-confidence: STRUCTURAL
  talk_group_block:
    doc: |
      Logical ID 0x44, talk-group slot 1 of 5 (0x44-0x48). Up to 170 entries fit; the distribution
      of entries across 0x45-0x48 is not established, so those pages are not decoded.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x44 - Talk Groups"
    -dm32-confidence: CONFIRMED
    seq:
      - id: header
        type: u1
        doc: Block header byte (0x00 factory, 0xFF OEM CPS); "mandatory 0x00" claims are unsupported.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block layout"
        -dm32-confidence: STRUCTURAL
      - id: entries
        type: talk_group
        repeat: expr
        repeat-expr: 170
        doc: Talk-group slots 1-170 (entry 170 ends at 0xFF0).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Talk-group block range 0x44-0x48 - block math"
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 14
        doc: 0xFF1-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block layout"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x44.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED
  tg_index_entry:
    doc: Index-table entry, [slot in block 0x44 (1-based), type byte 0x30 private / 0x40 group / 0x50 all].
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Index entry format (2 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: slot
        type: u1
        doc: 1-based physical slot in the talk-group block.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Index entry format (2 bytes)"
        -dm32-confidence: CONFIRMED
      - id: type_byte
        type: u1
        doc: Call type << 4.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Index entry format (2 bytes)"
        -dm32-confidence: CONFIRMED
  talk_group_index_block:
    doc: Logical ID 0x0B - counts, slot-usage bitmask and two sorted index tables over the talk groups.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x0B - Quick Access Contact List"
    -dm32-confidence: CONFIRMED
    seq:
      - id: total_count
        type: u2
        doc: Number of talk groups.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: CONFIRMED
      - id: group_call_count
        type: u2
        doc: Number of group-call talk groups.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: CONFIRMED
      - id: unknown_004
        type: u1
        doc: Not the private-call count (matched the all-call count in one capture). Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: STRUCTURAL
      - id: unknown_005
        size: 11
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: STRUCTURAL
      - id: slot_free_mask
        size: 16
        doc: 128 display slots, bit clear = used.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: CONFIRMED
      - id: unknown_020
        size: 0xe0
        doc: Unknown, untouched by the OEM CPS.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: STRUCTURAL
      - id: by_name
        type: tg_index_entry
        repeat: expr
        repeat-expr: 768
        doc: Index table 1 at 0x100, sorted by name (plain byte-wise ASCII). Extent to 0x6FF is DERIVED.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: STRUCTURAL
      - id: unknown_700
        size: 0x40
        doc: Gap between the tables.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: STRUCTURAL
      - id: by_number
        type: tg_index_entry
        repeat: expr
        repeat-expr: 736
        doc: Index table 2 at 0x740, sorted by DMR number ascending. Extent to 0xCFF is DERIVED.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: STRUCTURAL
      - id: tail
        size: 0x2ff
        doc: 0xD00-0xFFE, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x0B)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x0B.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ zones (0x5C-0x64)
  zone:
    doc: One 145-byte zone - name, channel count, up to 64 absolute 1-based channel numbers.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Zone Structure (145 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: name
        type: str
        size: 11
        encoding: ISO-8859-1
        doc: ASCII, NUL-terminated, 0xFF padding.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Zone Name Encoding"
        -dm32-confidence: CONFIRMED
      - id: name_pad
        size: 5
        doc: Padding after the name.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout" (zone)
        -dm32-confidence: CONFIRMED
      - id: channel_count
        type: u1
        doc: Number of channels in this zone (authoritative, not perfectly trustworthy).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Channel List Format"
        -dm32-confidence: CONFIRMED
      - id: channels
        type: u2
        repeat: expr
        repeat-expr: 64
        doc: Absolute channel numbers; 0x0000 / 0xFFFF fill ends the list. Do not write 0x0000 terminators.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Terminator semantics (hardware-observed)"
        -dm32-confidence: CONFIRMED
  zone_bank_first:
    doc: Logical ID 0x5C, zone slot 1 - 16-byte header (global zone count), then zones 1-28.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Zone block header (first zone block only)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: zone_count
        type: u1
        doc: Total zones across all zone blocks.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Zone block header (first zone block only)"
        -dm32-confidence: CONFIRMED
      - id: header_unknown
        size: 15
        doc: Not a constant; differs between factory and OEM-written blocks. Preserve.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Zone block header (first zone block only)"
        -dm32-confidence: STRUCTURAL
      - id: zones
        type: zone
        repeat: expr
        repeat-expr: 28
        doc: Zones 1-28 (zone 2 at 0x0A1 is hardware-confirmed; capacity 28 is DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Offset Calculation"
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 19
        doc: 0xFEC-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Offset Calculation"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x5C.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED
  zone_bank:
    doc: Logical IDs 0x5D-0x64, zone slots 2-9 - no header, 28 zones from offset 0 (DERIVED - never exercised by a capture).
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Offset Calculation"
    -dm32-confidence: INFERRED
    seq:
      - id: zones
        type: zone
        repeat: expr
        repeat-expr: 28
        doc: 28 zone records.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Offset Calculation"
        -dm32-confidence: INFERRED
      - id: tail
        size: 35
        doc: 0xFDC-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Offset Calculation"
        -dm32-confidence: INFERRED
      - id: tag
        type: u1
        doc: Logical ID 0x5D-0x64.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ scan lists (0x11)
  scan_list:
    doc: |
      One 57-byte scan list. Where the channel list starts is unresolved (+0x18 vs +0x1A); this
      follows the recommended reading (15 channels at +0x1A, +0x18 an opaque word) and keeps
      every byte either way.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Scan List Structure (57 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: name
        type: str
        size: 11
        encoding: ISO-8859-1
        doc: ASCII; no terminator when exactly 11 characters.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout (57 bytes per entry)"
        -dm32-confidence: CONFIRMED
      - id: channel_count_raw
        type: u1
        doc: Declared count; does not match the channels present in either capture. Do not trust.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout (57 bytes per entry)"
        -dm32-confidence: STRUCTURAL
      - id: unknown_0c_7_4
        type: b4
        doc: Byte 0x0C bits 7-4, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Values" (scan list)
        -dm32-confidence: STRUCTURAL
      - id: scan_tx_mode
        type: b2
        doc: Byte 0x0C bits 3-2 (0 current, 1 last active, 2 designated - contested).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Values" (scan list)
        -dm32-confidence: INFERRED
      - id: ctc_scan_mode
        type: b2
        doc: Byte 0x0C bits 1-0.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Values" (scan list)
        -dm32-confidence: INFERRED
      - id: hang_time
        type: u1
        doc: Unit not established (0.1 s is assumed by the reference implementation).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Values" (scan list)
        -dm32-confidence: INFERRED
      - id: priority2_type
        type: b4
        doc: Byte 0x0E bits 7-4 (0 none, 1 current, 2 designated).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Values" (scan list)
        -dm32-confidence: INFERRED
      - id: priority1_type
        type: b4
        doc: Byte 0x0E bits 3-0.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Values" (scan list)
        -dm32-confidence: INFERRED
      - id: priority_channel1
        type: u2
        doc: Channel number; gate on priority1_type.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout (57 bytes per entry)"
        -dm32-confidence: STRUCTURAL
      - id: designated_tx_channel_raw
        type: u2
        doc: Stored = channel - 2 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout (57 bytes per entry)"
        -dm32-confidence: INFERRED
      - id: priority_channel2_raw
        type: u2
        doc: Stored = channel - 2 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout (57 bytes per entry)"
        -dm32-confidence: INFERRED
      - id: unknown_15
        size: 3
        doc: Bytes 0x15-0x17, unknown, differ between captures.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout (57 bytes per entry)"
        -dm32-confidence: STRUCTURAL
      - id: word_18
        type: u2
        doc: Bytes 0x18-0x19 - a first channel slot or a separate field (unresolved).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Where the channel list starts is UNRESOLVED"
        -dm32-confidence: STRUCTURAL
      - id: channels
        type: u2
        repeat: expr
        repeat-expr: 15
        doc: Channel numbers; 0x0000 / 0xFFFF fill.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Where the channel list starts is UNRESOLVED"
        -dm32-confidence: STRUCTURAL
      - id: unknown_38
        type: u1
        doc: Byte 0x38, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Field Layout (57 bytes per entry)"
        -dm32-confidence: STRUCTURAL
  scan_list_block:
    doc: Logical ID 0x11 - count byte, then 57-byte scan lists from offset 1.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (scan list)
    -dm32-confidence: CONFIRMED
    seq:
      - id: count
        type: u1
        doc: Number of scan lists.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (scan list)
        -dm32-confidence: CONFIRMED
      - id: lists
        type: scan_list
        repeat: expr
        repeat-expr: 32
        doc: Scan lists 1-32 (32 is the reference implementation's limit; bytes past it are kept raw in `tail`).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (scan list)
        -dm32-confidence: INFERRED
      - id: tail
        size: 0x8de
        doc: 0x721-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (scan list)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x11.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ RX groups (0x0F)
  rx_group:
    doc: One 109-byte RX group list - name and up to 32 raw 24-bit DMR IDs (not talk-group indices).
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (109 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: name
        type: str
        size: 11
        encoding: ISO-8859-1
        doc: ASCII, NUL-terminated; bytes after the terminator may be stale.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (109 bytes)"
        -dm32-confidence: CONFIRMED
      - id: ids
        type: u24
        repeat: expr
        repeat-expr: 32
        doc: DMR IDs; 0 or 0xFFFFFF = empty, parse stops at the first empty.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (109 bytes)"
        -dm32-confidence: CONFIRMED
      - id: unknown_6b
        type: u1
        doc: Carries data (0x02 seen on a 14-ID group). Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (109 bytes)"
        -dm32-confidence: STRUCTURAL
      - id: unknown_6c
        type: u1
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (109 bytes)"
        -dm32-confidence: STRUCTURAL
  rx_group_block:
    doc: Logical ID 0x0F - 17-byte header (active-group bitmask), then 32 RX groups of 109 bytes.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "RX Group List Structure"
    -dm32-confidence: CONFIRMED
    seq:
      - id: active_mask
        type: u4
        doc: Bit n set = group slot n in use.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (RX group)
        -dm32-confidence: CONFIRMED
      - id: unknown_004
        type: u1
        doc: Carries data; not a plain count.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (RX group)
        -dm32-confidence: STRUCTURAL
      - id: unknown_005
        size: 11
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (RX group)
        -dm32-confidence: STRUCTURAL
      - id: header_flag
        type: u1
        doc: 0x01 in every capture.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (RX group)
        -dm32-confidence: STRUCTURAL
      - id: groups
        type: rx_group
        repeat: expr
        repeat-expr: 32
        doc: RX group slots 0-31 at 0x11 + n * 0x6D.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (RX group)
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 0x24e
        doc: 0xDB1-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Memory Organization" (RX group)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x0F.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ quick texts (0x0A)
  quick_text:
    doc: One 129-byte message - character count then 128 bytes of text.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (129 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: char_count
        type: u1
        doc: Number of characters (settled by both captures).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (129 bytes)"
        -dm32-confidence: CONFIRMED
      - id: text
        type: str
        size: 128
        encoding: ISO-8859-1
        doc: ASCII; ends at the first 0x00 or 0xFF; usable maximum 127 characters.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Message Text Encoding"
        -dm32-confidence: CONFIRMED
  quick_text_block:
    doc: Logical ID 0x0A - count, 15 header bytes, 20 messages from 0x10.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x0A - Quick Text Messages"
    -dm32-confidence: CONFIRMED
    seq:
      - id: count
        type: u1
        doc: Number of messages.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x0A)
        -dm32-confidence: CONFIRMED
      - id: header_unknown
        size: 15
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x0A)
        -dm32-confidence: STRUCTURAL
      - id: messages
        type: quick_text
        repeat: expr
        repeat-expr: 20
        doc: Messages 1-20.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x0A)
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 0x5db
        doc: 0xA24-0xFFE, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x0A)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x0A.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ radio IDs (0x67)
  radio_id:
    doc: One 16-byte entry of the radio's own DMR IDs.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (16 bytes)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: dmr_id
        type: u24
        doc: DMR radio ID, u24 LE binary (not BCD).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "ID Encoding"
        -dm32-confidence: CONFIRMED
      - id: name
        type: str
        size: 12
        encoding: ISO-8859-1
        doc: ASCII, NUL-terminated.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (16 bytes)"
        -dm32-confidence: CONFIRMED
      - id: unknown_0f
        type: u1
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (16 bytes)"
        -dm32-confidence: STRUCTURAL
  radio_id_block:
    doc: Logical ID 0x67 - count, 15 unknown bytes, 250 entries from 0x10.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x67 - DMR Radio ID List"
    -dm32-confidence: CONFIRMED
    seq:
      - id: count
        type: u1
        doc: Number of IDs (one byte, not a u32).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x67)
        -dm32-confidence: CONFIRMED
      - id: header_unknown
        size: 15
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x67)
        -dm32-confidence: STRUCTURAL
      - id: entries
        type: radio_id
        repeat: expr
        repeat-expr: 250
        doc: Entries 0-249.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x67)
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 0x4f
        doc: 0xFB0-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x67)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x67.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ roaming (0x65, 0x66)
  roaming_zone:
    doc: One 33-byte roaming zone; stride and name offset hardware-confirmed, fields DERIVED.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x65 - Roaming Zones"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: flags
        type: u1
        doc: Bit 0 enabled (DERIVED). In slot 0 this byte also reads like a zone count; unresolved.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (33 bytes)"
        -dm32-confidence: INFERRED
      - id: unknown_01
        type: u1
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (33 bytes)"
        -dm32-confidence: INFERRED
      - id: value_02
        type: u1
        doc: Stored value + 1 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (33 bytes)"
        -dm32-confidence: INFERRED
      - id: value_03
        type: u1
        doc: Stored value + 1, max 0x40 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (33 bytes)"
        -dm32-confidence: INFERRED
      - id: unknown_04
        size: 12
        doc: Unknown; where the zone's channel list lives is unresolved.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (33 bytes)"
        -dm32-confidence: INFERRED
      - id: name
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: ASCII, NUL-terminated (offset +0x10 hardware-confirmed).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x65 - Roaming Zones"
        -dm32-confidence: CONFIRMED
      - id: last_20
        type: u1
        doc: Channel count or index (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (33 bytes)"
        -dm32-confidence: INFERRED
  roaming_zone_block:
    doc: Logical ID 0x65 - 33-byte entries from offset 0 (infamy's "16-byte header" is the first entry's first 16 bytes).
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x65 - Roaming Zones"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: zones
        type: roaming_zone
        repeat: expr
        repeat-expr: 124
        doc: As many 33-byte entries as fit; capacity not established.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x65 - Roaming Zones"
        -dm32-confidence: INFERRED
      - id: tail
        size: 3
        doc: 0xFFC-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x65 - Roaming Zones"
        -dm32-confidence: INFERRED
      - id: tag
        type: u1
        doc: Logical ID 0x65.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED
  roaming_channel:
    doc: One 26-byte roaming channel.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x66 - Roaming Channels"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: name
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: ASCII, NUL-terminated (hardware-confirmed).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (26 bytes)"
        -dm32-confidence: CONFIRMED
      - id: rx_freq
        type: bcd_freq32
        doc: RX frequency (corroborated by capture).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (26 bytes)"
        -dm32-confidence: STRUCTURAL
      - id: tx_freq
        type: bcd_freq32
        doc: TX frequency (corroborated by capture).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (26 bytes)"
        -dm32-confidence: STRUCTURAL
      - id: color_code
        type: u1
        doc: 0-15 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (26 bytes)"
        -dm32-confidence: INFERRED
      - id: timeslot
        type: u1
        doc: 1 or 2 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry Structure (26 bytes)"
        -dm32-confidence: INFERRED
  roaming_channel_block:
    doc: Logical ID 0x66 - 26-byte entries from offset 0; a count at 0xFF0 is DERIVED only and not corroborated by a hardware read.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x66 - Roaming Channels"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: channels
        type: roaming_channel
        repeat: expr
        repeat-expr: 150
        doc: Up to 150 (DERIVED maximum).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x66 - Roaming Channels"
        -dm32-confidence: INFERRED
      - id: unknown_f3c
        size: 0xb4
        doc: 0xF3C-0xFEF.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x66 - Roaming Channels"
        -dm32-confidence: INFERRED
      - id: count_ff0
        type: u1
        doc: Count per CPS decompilation (DERIVED, max 150). Not corroborated on hardware.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x66 - Roaming Channels"
        -dm32-confidence: INFERRED
      - id: unknown_ff1
        size: 14
        doc: 0xFF1-0xFFE.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x66 - Roaming Channels"
        -dm32-confidence: INFERRED
      - id: tag
        type: u1
        doc: Logical ID 0x66.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ emergency + keys (0x10)
  digital_emergency:
    doc: One 20-byte digital emergency system.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1 - Digital Emergency Systems (0x000-0x09F)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: name
        type: str
        size: 10
        encoding: ISO-8859-1
        doc: ASCII, NUL-padded.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: alarm_type
        type: u1
        doc: 0 none, 1 only whistle, 2 normal, 3 secret, 4 secret with voice, 5 alarm whistle.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: alarm_mode_raw
        type: u1
        doc: Stored value + 1 (1 emergency alarm, 2 alarm call, 3 emergency call).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: revert_channel
        type: u2
        doc: 0 = none.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: retransmission
        type: u1
        doc: 1-15.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: hot_mic_s
        type: u1
        doc: 1-15 s.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: calls_number_raw
        type: u1
        doc: (raw + 1) * 10.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: flags
        type: u1
        doc: Bit 0 enabled; bits 7-1 carry data (0xFE from the OEM CPS). Modify bit 0 only.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: rx_duration_s
        type: u1
        doc: 1-255 s.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
      - id: auto_call_timer_raw
        type: u1
        doc: (raw + 1) * 10.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 1"
        -dm32-confidence: CONFIRMED
  privacy_key:
    doc: One 44-byte encryption/privacy key entry. Key placement inside the 32 bytes depends on the type (AES right-aligned); keep all 32.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 3 - Encryption / Privacy Keys (0x300-0x45F)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: entry_id
        type: u1
        doc: 1-8 = entry number; 0 = empty slot.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 3"
        -dm32-confidence: CONFIRMED
      - id: name
        type: str
        size: 10
        encoding: ISO-8859-1
        doc: ASCII, NUL-terminated/padded.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 3"
        -dm32-confidence: CONFIRMED
      - id: key_type
        type: u1
        doc: 0 none, 1 custom, 2 ARC4, 3 AES128, 4 AES256.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 3"
        -dm32-confidence: CONFIRMED
      - id: key
        size: 32
        doc: Key material (secret; treat dumps containing it accordingly).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 3"
        -dm32-confidence: INFERRED
  emergency_key_block:
    doc: Logical ID 0x10 - digital emergency systems, analog emergency systems and privacy keys in one page. Read-modify-write the whole page.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x10 - Multi-section"
    -dm32-confidence: CONFIRMED
    seq:
      - id: digital
        type: digital_emergency
        repeat: expr
        repeat-expr: 8
        doc: 0x000-0x09F.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x10)
        -dm32-confidence: CONFIRMED
      - id: gap_0a0
        size: 12
        doc: 0x0A0-0x0AB, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x10)
        -dm32-confidence: STRUCTURAL
      - id: analog
        size: 36
        repeat: expr
        repeat-expr: 16
        doc: |
          Analog emergency systems, 36-byte entries (size confirmed). The base (0x0AC vs 0x0D0)
          and the intra-entry layout are unresolved - the documented field table does not decode
          the one real entry - so entries are kept raw. Unrelated bytes are known to sit inside
          this span.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 2 - Analog Emergency Systems (0x0AC-0x2FF)"
        -dm32-confidence: STRUCTURAL
      - id: analog_tail
        size: 20
        doc: 0x2EC-0x2FF, the remainder of the analog span after 16 x 36 bytes (16 does not divide it exactly).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 2 - Analog Emergency Systems (0x0AC-0x2FF)"
        -dm32-confidence: STRUCTURAL
      - id: keys
        type: privacy_key
        repeat: expr
        repeat-expr: 8
        doc: 0x300-0x45F.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Section 3"
        -dm32-confidence: CONFIRMED
      - id: tail
        size: 0xb9f
        doc: 0x460-0xFFE; not empty (repeated 0A 0A pairs near 0xB00); unknown, preserve.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block Layout" (0x10)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x10.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ analog signalling (0x06)
  analog_contact:
    doc: One 32-byte analog (DTMF) contact; only the name position is attested.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x06 - DTMF Encode Data"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: name
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: ASCII name.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x06 - DTMF Encode Data"
        -dm32-confidence: CONFIRMED
      - id: rest
        size: 16
        doc: Unknown (probably the DTMF code).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x06 - DTMF Encode Data"
        -dm32-confidence: INFERRED
  analog_signalling_block:
    doc: Logical ID 0x06 - DTMF code table, DTMF settings, analog contacts, and a second (BDC/MDC) table.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x06 - DTMF Encode Data"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: dtmf_codes
        size: 16
        repeat: expr
        repeat-expr: 16
        doc: DTMF code sequences (digits 0x00-0x0F, not ASCII), stride 16 (anchor hardware-checked).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "DTMF Code Encoding"
        -dm32-confidence: STRUCTURAL
      - id: dtmf_settings
        size: 16
        doc: 0x100-0x10F DTMF settings bytes (group code value+9, interval sign value+10, auto ack value+4 ...; DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x06)
        -dm32-confidence: INFERRED
      - id: dtmf_codes_extra
        size: 16
        repeat: expr
        repeat-expr: 4
        doc: 0x110-0x14F, four more code sequences (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x06)
        -dm32-confidence: INFERRED
      - id: unknown_150
        size: 0xaf
        doc: 0x150-0x1FE, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Structure Overview" (0x06)
        -dm32-confidence: STRUCTURAL
      - id: count_1ff
        type: u1
        doc: |
          A count. infamy found it tracking the analog-contact count and not the talk-group count;
          a read of a 048 radio contradicts the analog-contact reading. Unidentified - leave alone.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Block 0x06 offset 0x1FF is not a Talk Groups counter"
        -dm32-confidence: STRUCTURAL
      - id: analog_contacts
        type: analog_contact
        repeat: expr
        repeat-expr: 69
        doc: 0x200-0xA9F, 32-byte stride (hardware); capacity up to the next table is inferred.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x06 - DTMF Encode Data"
        -dm32-confidence: STRUCTURAL
      - id: table_aa0
        size: 0x55f
        doc: 0xAA0-0xFFE, a second named table (BDC/MDC-style names) of unknown layout.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x06 - DTMF Encode Data"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x06.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ 2-tone list (0x03)
  two_tone_entry:
    doc: |
      One 40-byte two-tone sequential-call entry - in-use marker, two tone frequencies, and a
      UTF-16LE name. The stock consumer (named flash_record_frequency_calibration_apply in the
      corpus - a misnomer, it is NOT calibration) reads the two u16 tones, enables the FD6818
      TONE1 generator, keys TX, plays tone 1 then tone 2 and unkeys; 0xFFFF at +2 means an empty
      slot. infamy documents the same layout with the purpose unknown.
    doc-ref:
      - DM32.00.01.048 flash_record_frequency_calibration_apply @0x03066f98
      - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x03 - Call list"
    -dm32-confidence: CONFIRMED
    seq:
      - id: marker
        type: u2
        doc: 0xFFFE (bytes FE FF) on a configured entry, 0xFFFF on an empty one.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry array" (0x03)
        -dm32-confidence: CONFIRMED
      - id: tone1
        type: u2
        doc: First tone, 0.1 Hz units; 0xFFFF = empty slot.
        doc-ref: DM32.00.01.048 flash_record_frequency_calibration_apply @0x03066f98
        -dm32-confidence: CONFIRMED
      - id: tone2
        type: u2
        doc: Second tone, 0.1 Hz units.
        doc-ref: DM32.00.01.048 flash_record_frequency_calibration_apply @0x03066f98
        -dm32-confidence: CONFIRMED
      - id: pad
        type: u2
        doc: Always 0xFFFF in captures.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry array" (0x03)
        -dm32-confidence: STRUCTURAL
      - id: name_raw
        size: 32
        doc: UTF-16LE name, NUL-terminated, max 16 characters (the only UTF-16 strings in the codeplug).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry array" (0x03)
        -dm32-confidence: CONFIRMED
    instances:
      name:
        value: name_raw.to_s('UTF-16LE')
        doc: Decoded name including trailing NULs (strip at the first U+0000).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry array" (0x03)
        -dm32-confidence: CONFIRMED
  two_tone_block:
    doc: |
      Logical ID 0x03 - the two-tone sequential-call list. Earlier notes (including infamy and
      this project) mislabelled it "Digital Emergency Systems" and then "calibration"; it is
      neither. Entry n is at 0x218 + n * 0x28; the stock consumer addresses record k (k >= 1) at
      0x240 + (k - 1) * 0x28, the same formula, so entry 0 is reached only with k = 0. 32 entries
      are initialised before other data starts.
    doc-ref:
      - DM32.00.01.048 flash_record_frequency_calibration_apply @0x03066f98
      - DM32.00.01.048 call_list_index_write @0x03066ea4
      - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x03 - Call list"
    -dm32-confidence: CONFIRMED
    seq:
      - id: unknown_000
        type: u1
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Other populated regions" (0x03)
        -dm32-confidence: STRUCTURAL
      - id: count_001
        type: u1
        doc: Possibly the number of named entries (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Other populated regions" (0x03)
        -dm32-confidence: INFERRED
      - id: unknown_002
        size: 0x2e
        doc: 0x002-0x02F, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Other populated regions" (0x03)
        -dm32-confidence: STRUCTURAL
      - id: config_030
        size: 7
        doc: 0x030-0x036, header/config bytes of unknown meaning.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Other populated regions" (0x03)
        -dm32-confidence: STRUCTURAL
      - id: tone_table
        type: u2
        repeat: expr
        repeat-expr: 4
        doc: 0x037-0x03E, four tone values (0.1 Hz) - the set the entries' tone pairs are drawn from.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Hardware evidence (read capture, page 0x011000)"
        -dm32-confidence: STRUCTURAL
      - id: unknown_03f
        size: 0x1d9
        doc: 0x03F-0x217, unknown (more config bytes near 0x040).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Other populated regions" (0x03)
        -dm32-confidence: STRUCTURAL
      - id: entries
        type: two_tone_entry
        repeat: expr
        repeat-expr: 32
        doc: Entries 0-31, 0x218-0x717 (infamy's 92-entry capacity is not supported by the data that follows).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Entry array" (0x03)
        -dm32-confidence: STRUCTURAL
      - id: tail
        size: 0x8e7
        doc: 0x718-0xFFE - index-like runs around 0x730 and an option-label table (Disable/Enable) around 0x8A0; unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Other populated regions" (0x03)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x03.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED

  # ------------------------------------------------------------------ radio settings (0x04)
  one_touch_call:
    doc: One-touch call entry (5 bytes).
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
    -dm32-confidence: CONFIRMED
    seq:
      - id: call_type
        type: u1
        doc: 0 off, 1 analog, 2 digital.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
      - id: call_object
        type: u2
        doc: Contact / object number.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
      - id: digital_call_type
        type: u1
        doc: 0 off, 1 private, 2 group, 3 message, 4 call alert, 5 radio check, 6 remote monitor, 7 active, 8 kill.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
      - id: sms
        type: u1
        doc: SMS number/index.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
  fun_plus:
    doc: Fun+ (number-key) entry (7 bytes); the key number is the entry index.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
    -dm32-confidence: CONFIRMED
    seq:
      - id: operate_mode
        type: u1
        doc: 0 call, 1 menu.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
      - id: menu_select
        type: u1
        doc: 0-13 menu item.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
      - id: pad
        type: u1
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: STRUCTURAL
      - id: call_way
        type: u1
        doc: 0 off, 1 analog, 2 digital (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: INFERRED
      - id: call_object
        type: u1
        doc: Contact/ID, one byte (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: INFERRED
      - id: digital_call_type
        type: u1
        doc: Same enumeration as one_touch_call (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: INFERRED
      - id: sms
        type: u1
        doc: Raw (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: INFERRED
  radio_settings_block:
    doc: |
      Logical ID 0x04 - the global radio settings. About 230 of 4096 bytes are mapped; everything
      else is kept raw. Read-modify-write only: several "unknown" bytes and bits carry data.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x04 - Embedded Information / Radio Names"
    -dm32-confidence: CONFIRMED
    seq:
      - id: power_on_interface
        type: u1
        doc: 0 picture, 1 custom message, 2 battery voltage.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: CONFIRMED
      - id: power_on_line1
        type: str
        size: 14
        encoding: ISO-8859-1
        doc: Power-on display line 1, ASCII, NUL-terminated.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: CONFIRMED
      - id: power_on_line2
        type: str
        size: 14
        encoding: ISO-8859-1
        doc: Power-on display line 2.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: CONFIRMED
      - id: allow_reset_flags
        type: u1
        doc: Bit 0 allow reset (DERIVED); bits 7-1 unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: INFERRED
      - id: auto_power_off
        type: u1
        doc: 0 off, 1 30 min, 2 60, 3 120, 4 240, 5 480 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: INFERRED
      - id: unknown_01f
        type: u1
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: STRUCTURAL
      - id: alert_tones
        size: 2
        doc: Alert-tone bit flags (labels DERIVED; unlabelled bits carry data).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: INFERRED
      - id: unknown_022
        size: 14
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Power-on region (0x000-0x02F)"
        -dm32-confidence: STRUCTURAL
      - id: backlight_brightness
        type: u1
        doc: Stored 0-5, displayed 1-6.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: CONFIRMED
      - id: auto_backlight
        type: u1
        doc: (raw + 1) * 5 s (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: INFERRED
      - id: unknown_032
        type: u1
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: STRUCTURAL
      - id: display_flags
        type: u1
        doc: Bit 0 volume prompt, 1 time display, 3 date format (DERIVED); others unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: INFERRED
      - id: callsign_color
        type: u1
        doc: Low nibble colour (0 white ... 7 blue); high nibble preserved.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: CONFIRMED
      - id: standby_text_color
        type: u1
        doc: Low nibble colour.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: CONFIRMED
      - id: menu_exit_time
        type: u1
        doc: 1-30 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: INFERRED
      - id: standby_char_color1
        type: u1
        doc: 0-30 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: INFERRED
      - id: channel_zone_colors
        type: u1
        repeat: expr
        repeat-expr: 4
        doc: Channel A, channel B, zone A, zone B colours (low nibble).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: CONFIRMED
      - id: unknown_03c
        size: 4
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Display / UI region (0x030-0x03B)"
        -dm32-confidence: STRUCTURAL
      - id: gps_unknown_7
        type: b1
        doc: Byte 0x040 bit 7, unknown (preserve).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: STRUCTURAL
      - id: gps_display_dms
        type: b1
        doc: Byte 0x040 bit 6, 0 degrees / 1 deg-min-sec.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: CONFIRMED
      - id: gps_speed_unit
        type: b2
        doc: Byte 0x040 bits 5-4, 0 km/h, 1 mph, 2 kt.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: CONFIRMED
      - id: gps_mode
        type: b2
        doc: Byte 0x040 bits 3-2, 0 GPS, 1 BDS, 2 GPS+BDS.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: CONFIRMED
      - id: gps_distance_imperial
        type: b1
        doc: Byte 0x040 bit 1.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: CONFIRMED
      - id: gps_on
        type: b1
        doc: Byte 0x040 bit 0.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: CONFIRMED
      - id: utc_zone
        type: u1
        doc: 0-25 = UTC-12 .. UTC+13 (12 = UTC).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: CONFIRMED
      - id: gps_report_interval_s
        type: u1
        doc: Seconds, 5-255.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: CONFIRMED
      - id: unknown_043
        size: 0x1d
        doc: 0x043-0x05F, unknown (0x045 carries data).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "GPS region (0x040-0x045)"
        -dm32-confidence: STRUCTURAL
      - id: digital_decode_flags
        type: u1
        doc: Bit 0 private call match, bit 1 group call match.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: call_hold_time_s
        type: u1
        doc: Seconds.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: active_wait_raw
        type: u1
        doc: Raw (scaling DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: active_retries
        type: u1
        doc: 1-8.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: pre_carrier_raw
        type: u1
        doc: Raw (scaling DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: digital_flags
        type: u1
        doc: Decode/alert flag bits (remote monitor, disable, check, enable, call alert, data service, missed call).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: sms_format_raw
        type: u1
        doc: Raw (scaling DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: name_display_flags
        type: u1
        doc: Name data format / send TX name / display priority bits.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: CONFIRMED
      - id: unknown_068
        size: 0x18
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Digital (DMR) settings region (0x060-0x067)"
        -dm32-confidence: STRUCTURAL
      - id: vfo_embedded_flags
        type: u1
        doc: Bit field, labels are placeholders.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Miscellaneous (0x080-0x081, 0x0A0-0x0A7)"
        -dm32-confidence: STRUCTURAL
      - id: tx_dwell_time
        type: u1
        doc: 0-255 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Miscellaneous (0x080-0x081, 0x0A0-0x0A7)"
        -dm32-confidence: INFERRED
      - id: unknown_082
        size: 3
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Miscellaneous (0x080-0x081, 0x0A0-0x0A7)"
        -dm32-confidence: STRUCTURAL
      - id: key_lock_flags
        type: u1
        doc: Bit 0 auto lock, 1 knob lock, 2 side-key lock; bits 7-3 carry data.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: CONFIRMED
      - id: auto_keypad_lock_delay_s
        type: u1
        doc: Seconds, 5-60.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: CONFIRMED
      - id: side_keys_1_2
        type: u1
        enum: button_function
        repeat: expr
        repeat-expr: 4
        doc: SK1 short, SK1 long, SK2 short, SK2 long.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: CONFIRMED
      - id: unknown_08b
        size: 2
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: STRUCTURAL
      - id: prog_keys_1_2
        type: u1
        enum: button_function
        repeat: expr
        repeat-expr: 4
        doc: P1 short, P1 long, P2 short, P2 long.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: CONFIRMED
      - id: unknown_091
        size: 2
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: STRUCTURAL
      - id: long_press_time_raw
        type: u1
        doc: Stored 0-4, displayed 1-5.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: CONFIRMED
      - id: unknown_094
        size: 12
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Key lock and button functions (0x085-0x093)"
        -dm32-confidence: STRUCTURAL
      - id: language_blob
        size: 8
        doc: 0x0A0-0x0A7, language/other settings, opaque.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Miscellaneous (0x080-0x081, 0x0A0-0x0A7)"
        -dm32-confidence: STRUCTURAL
      - id: unknown_0a8
        size: 0x78
        doc: 0x0A8-0x11F, unknown (0x0A9 carries data).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Unmapped byte ranges"
        -dm32-confidence: STRUCTURAL
      - id: analog_one_key
        size: 8
        doc: 0x120-0x127, analog one-key call, 4 x 2 bytes; field order contradicted by hardware, kept raw.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: STRUCTURAL
      - id: unknown_128
        size: 0xd8
        doc: 0x128-0x1FF, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Unmapped byte ranges"
        -dm32-confidence: STRUCTURAL
      - id: one_touch_calls
        type: one_touch_call
        repeat: expr
        repeat-expr: 5
        doc: 0x200-0x218.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
      - id: unknown_219
        size: 0x17
        doc: 0x219-0x22F, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Unmapped byte ranges"
        -dm32-confidence: STRUCTURAL
      - id: fun_plus_keys
        type: fun_plus
        repeat: expr
        repeat-expr: 10
        doc: 0x230-0x275.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "One-Key Operation"
        -dm32-confidence: CONFIRMED
      - id: unknown_276
        size: 0x8b
        doc: 0x276-0x300, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Unmapped byte ranges"
        -dm32-confidence: STRUCTURAL
      - id: aprs_send_time_raw
        type: u1
        doc: 0 off, else n * 30 s (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: INFERRED
      - id: aprs_fixed_beacon
        type: u1
        doc: Bit 0 (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: INFERRED
      - id: unknown_303
        size: 3
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: STRUCTURAL
      - id: latitude
        type: str
        size: 9
        encoding: ISO-8859-1
        doc: Fixed latitude, ASCII decimal degrees, 9-byte field.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: CONFIRMED
      - id: latitude_dir
        type: u1
        doc: ASCII N / S (0x00 when unset).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: CONFIRMED
      - id: longitude
        type: str
        size: 9
        encoding: ISO-8859-1
        doc: Fixed longitude, ASCII, 9-byte field.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: CONFIRMED
      - id: longitude_dir
        type: u1
        doc: ASCII E / W.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: CONFIRMED
      - id: unknown_31a
        size: 6
        doc: Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: STRUCTURAL
      - id: aprs_report_channels
        type: u2
        repeat: expr
        repeat-expr: 8
        doc: 0 = current channel (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: INFERRED
      - id: aprs_repeater_delay
        type: u1
        doc: 0 off, n * 100 ms (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: INFERRED
      - id: aprs_call_type
        type: u1
        doc: Bit 0, 0 private / 1 group (DERIVED).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: INFERRED
      - id: aprs_upload_id
        size: 3
        doc: 24-bit DMR ID, byte order disputed (LE favoured); kept raw.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "APRS and fixed GPS position (0x301-0x334)"
        -dm32-confidence: INFERRED
      - id: unknown_335
        size: 0x1cb
        doc: 0x335-0x4FF, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Unmapped byte ranges"
        -dm32-confidence: STRUCTURAL
      - id: menu_enable_flags
        size: 8
        doc: 0x500-0x507, per-menu-item enable bits (polarity DERIVED; unlabelled bits carry data).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Menu enable/disable flags (0x500-0x507)"
        -dm32-confidence: INFERRED
      - id: unknown_508
        size: 0xaf7
        doc: 0x508-0xFFE, unknown (0x600-0x602 and 0x700-0x703 carry data).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Unmapped byte ranges"
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Logical ID 0x04.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
        -dm32-confidence: CONFIRMED
enums:
  channel_mode:
    0: analog
    1: digital
    2: fixed_analog
    3: fixed_digital
  call_type:
    3: private_call
    4: group_call
    5: all_call
  button_function:
    0: none
    1: power_select
    2: volt
    3: talkaround
    4: digital_encrypt
    5: call
    6: vox
    7: v_m
    8: alarm
    9: one_touch_call_1
    10: one_touch_call_2
    11: one_touch_call_3
    12: one_touch_call_4
    13: one_touch_call_5
    14: sms
    15: csv_contacts
    16: zone_up
    17: zone_down
    18: scan
    19: record_switch
    20: previous_record
    21: next_record
    22: fm_radio
    23: fm_search
    24: gps_information
    25: monitor
    26: switch_main_channel
    27: lone_work
    28: keypad_lock
    29: nuisance_channel_delete
    30: tbst_send
    31: aprs_send
    32: channel_type
    33: display_mode
    34: ctc_scan
    35: ctc_setting
    36: silent_tone
    37: roaming
    38: sub_ptt
    39: analog_scramble_switch
    40: one_key_scan_freq
    41: flashlight
    42: man_down_alarm

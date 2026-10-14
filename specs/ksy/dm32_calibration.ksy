meta:
  id: dm32_calibration
  title: DM-32UV per-unit calibration page (data-chip logical block 0x02) - VERIFICATION ONLY
  file-extension: bin
  endian: le
  ks-version: '0.11'
  -dm32-confidence: STRUCTURAL
doc: |
  VERIFICATION ONLY. This describes the one 4 KB page of the 16 MB W25Q128 data chip that
  carries logical block ID 0x02 in its last byte. It holds this radio's factory calibration
  (measured per unit: interpolation tables and their frequency breakpoints) mixed with a few
  settings bytes. It exists so that dumps can be parsed, checked against the content signature,
  and compared unit to unit.

  It is compiled --read-write like every other spec here, because the pipeline compiles
  everything that way and because the round-trip test (parse a dump, serialize it, compare
  byte for byte) is how this description proves it loses nothing. That is the ONLY sanctioned
  use of serialization. NEVER use it to synthesize, edit, "repair" or transplant a calibration
  page: calibration is factory-tuned per unit, cannot be recreated from a model or from another
  radio, and the only legitimate write of this page is a byte-exact copy of the SAME radio's own
  verified backup (specs/README.md, "Calibration is restore-only").

  LOCATING THE PAGE. Its address differs between units (three units put it at three different
  data-chip pages). Never hardcode an address. Resolve it through the block-to-page tag map
  (the page whose byte 0xFFF is 0x02 inside the config region, see dm32_codeplug.ksy), and
  cross-check the 16-byte content signature at +0x000 (field `signature`).

  WHAT READS IT. The stock firmware reads this block with flash_field_read_cached(2, offset, ...)
  (logical block 2) from the frequency-interpolation chain run on every channel change:
  freq_calibration_apply_all -> freq_calibration_interpolate_single /
  freq_calibration_interpolate_selected / channel_step_frequency_bound_check ->
  linear_interpolate_freq_calibration. Each table value is fetched with a 2-byte read at
  (table base + bracket index), so the byte at index i is the low point and the byte at i+1 the
  high point of the bracket: adjacent points OVERLAP, and a 5-point table reaches 6 bytes (see
  type `points5`, instance `reach`). Breakpoints are fetched 4 bytes at a time from the bases
  0x314 (UHF) and 0x33c (VHF); band select is bit 4 of the radio-mode flags byte 3 (set = UHF).

  CONFIDENCE. Offsets the interpolators compute are CONFIRMED by the stock code (DM32.00.01.048).
  Which physical quantity a table controls is CONFIRMED only for the modulation-bias tables;
  everything else says UNPROVEN in its doc. A four-unit differential (this project's unit plus
  three published pages) shows the decoded table offsets are exactly the regions that vary
  smoothly between units, which corroborates the offsets; bytes that are identical on every
  unit are marked as such and carry no claim about meaning.

  infamy's DM32-Protocol-Spec (MIT, github.com/infamy/DM32-Protocol-Spec) calls this block
  "Frequency Adjustment / Calibration Data", read-only to the OEM CPS; its field table for this
  block is explicitly unreliable (its own words) and is not followed here, except where noted.
doc-ref:
  - DM32.00.01.048 freq_calibration_apply_all @0x0300db48
  - DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130
  - DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424
  - DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
  - DM32.00.01.048 linear_interpolate_freq_calibration @0x0301b000
  - DM32.00.01.048 flash_field_read_cached (logical block 2), flash_block_id_resolve @0x0300f364
  - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "0x02 - Frequency Adjustment/Calibration Data" (MIT)
  - github.com/yo3hjv/Baofeng-DM32 bins/ (three other units' pages; unlicensed, used for comparison only, not redistributed)
seq:
  - id: signature
    contents: [0x00, 0x40, 0x00, 0x47, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x58, 0x02, 0x7c, 0x02]
    doc: |
      Content signature, byte-identical on all four units examined (including a band-modified
      one). Use it to locate or confirm the page. Parsing fails if it differs, which is the
      intended behaviour for a verification spec. Meaning of the bytes is UNPROVEN (the first
      four read as two little-endian BCD u16 values in 100 kHz units spanning the UHF band; a
      guess, nothing traced reads them).
    doc-ref: four-unit comparison of block-0x02 pages (this project's unit + github.com/yo3hjv/Baofeng-DM32)
    -dm32-confidence: STRUCTURAL
  - id: unknown_010
    size: 6
    doc: Identical on all four units examined. No reader traced. Meaning UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_016
    type: u1
    doc: Differs between units (per-unit). No reader traced. Meaning UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: mod_bias_uhf
    type: points5(0x17)
    doc: |
      UHF transmit modulation bias, one byte per UHF breakpoint (`breakpoints_uhf`). Read by
      freq_calibration_interpolate_single when band bit (flags byte 3, bit 4) is SET; the
      interpolated value lands in IRAM 0x38470[0x29], is scaled and clamped to 255 and written
      to the HR_C7000 RF_MOD_BIAS register 0x11000114. Per unit.
    doc-ref:
      - DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130 (base 0x17, flag-set path)
      - DM32.00.01.048 freq_calibration_apply_all @0x0300db48 (write to 0x11000114)
    -dm32-confidence: CONFIRMED
  - id: unknown_01c
    size: 3
    doc: |
      Directly after the UHF modulation-bias table; one unit carries different values here.
      Byte 0x01c is the overlap byte `mod_bias_uhf.reach` can address. Otherwise UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_01f
    size: 8
    doc: Identical on all four units (two bytes then 0xFF fill). Meaning UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: audio_027
    type: u2
    doc: |
      Two-byte field read by audio_compander_calibration_apply (block 2, offset 0x27). Varies
      slightly between units. Its effect on the audio path is not traced further; UNPROVEN as
      calibration versus a setting.
    doc-ref: DM32.00.01.048 audio_compander_calibration_apply @0x030551b0
    -dm32-confidence: STRUCTURAL
  - id: unknown_029
    size: 7
    doc: 0xFF on all four units.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: freqs_030
    type: bcd_freq32
    repeat: expr
    repeat-expr: 3
    doc: |
      Three frequency-shaped values (u32 LE packed BCD, 10 Hz units) inside the UHF band,
      identical on all four units. infamy notes the same three values. No reader traced;
      purpose UNPROVEN.
    doc-ref:
      - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md 0x02 "Structure Overview" (0x030-0x03B)
      - four-unit comparison
    -dm32-confidence: STRUCTURAL
  - id: unknown_03c
    size: 4
    doc: 0xFF on all four units.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: level_vhf
    type: points5(0x40 + _index * 5)
    repeat: expr
    repeat-expr: 3
    doc: |
      Three VHF five-point tables at 0x40, 0x45, 0x4a (level 0, 1, 2), one byte per VHF
      breakpoint (`breakpoints_vhf`). Read by freq_calibration_interpolate_selected when the band
      bit is CLEAR, selected by the 2-bit field (flags byte 8 >> 1) & 3; the result lands in IRAM
      0x38470[0x28], whose consumer is NOT found in the stock corpus. L0 < L1 < L2 at every
      breakpoint on all four units, and the vendor manual lists three TX power levels, so these
      are probably TX power low/mid/high. That reading is UNPROVEN: do not label them as power
      in any tool. Per unit (large unit-to-unit spread).
    doc-ref:
      - DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424 (bases 0x40/0x45/0x4a, flag-clear path)
      - four-unit comparison (ordering)
    -dm32-confidence: CONFIRMED
  - id: unknown_04f
    type: u1
    doc: 0xFF on all four units; also the overlap byte level_vhf[2].reach can address.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_050
    size: 20
    doc: |
      Identical on all four units; groups of five bytes that look like default tables. No reader
      traced. Meaning UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: bound_064
    type: points5(0x64)
    doc: |
      Five-point table read by channel_step_frequency_bound_check as the second member of the
      pair (+0x69, +0x64). Pairs are chosen by a band bit (flags byte 3, bit 3 - a different bit
      from the one the other interpolators use) and a 1-bit field (flags byte 9 >> 7). The result
      lands in IRAM 0x3e212 (u16), consumer not traced. Squelch-like (infamy's list of CPS
      calibration parameters names U/V SQL9 and SQL3 five-point tables), but the band and the
      quantity are UNPROVEN. Per unit.
    doc-ref:
      - DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
      - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md 0x02 "Calibration Parameters (1-77)"
    -dm32-confidence: STRUCTURAL
  - id: bound_069
    type: points5(0x69)
    doc: First member of the bound_check pair (+0x69, +0x64). See `bound_064`. Quantity UNPROVEN.
    doc-ref: DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
    -dm32-confidence: STRUCTURAL
  - id: bound_06e
    type: points5(0x6e)
    doc: |
      Second member of the bound_check pair (+0x73, +0x6e). A real table, not padding: on three
      units 0x6e-0x7d holds the same default values, on the fourth 0x6e-0x77 is a copy of
      0x64-0x6d (filled by duplication). Do not assume it is constant. Quantity UNPROVEN.
    doc-ref:
      - DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
      - four-unit comparison
    -dm32-confidence: STRUCTURAL
  - id: bound_073
    type: points5(0x73)
    doc: First member of the bound_check pair (+0x73, +0x6e). See `bound_06e`. Quantity UNPROVEN.
    doc-ref: DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
    -dm32-confidence: STRUCTURAL
  - id: unknown_078
    size: 6
    doc: |
      End of the 0x6e-0x7d table area. Same values on three units, 0xFF on the unit that filled
      0x6e by duplication. No reader traced. UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_07e
    size: 2
    doc: 0xFF on all four units.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: bound_080
    type: points5(0x80)
    doc: |
      Second member of the bound_check pair (+0x85, +0x80), used for a third frequency range
      selected by a different pointer pair in the interpolator. Identical on all four units.
      Quantity UNPROVEN.
    doc-ref: DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
    -dm32-confidence: STRUCTURAL
  - id: bound_085
    type: points5(0x85)
    doc: First member of the bound_check pair (+0x85, +0x80). Quantity UNPROVEN.
    doc-ref: DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
    -dm32-confidence: STRUCTURAL
  - id: unknown_08a
    size: 22
    doc: 0xFF on all four units (0x08a is also the overlap byte bound_085.reach can address).
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_0a0
    size: 6
    doc: Identical on all four units. No reader traced. UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: mod_bias_vhf
    type: points5(0xa6)
    doc: |
      VHF transmit modulation bias, one byte per VHF breakpoint. Read by
      freq_calibration_interpolate_single when the band bit is CLEAR; same consumer as
      `mod_bias_uhf` (HR_C7000 RF_MOD_BIAS 0x11000114). Per unit.
    doc-ref: DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130 (base 0xa6, flag-clear path)
    -dm32-confidence: CONFIRMED
  - id: unknown_0ab
    size: 3
    doc: Directly after the VHF modulation-bias table; one unit differs. UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_0ae
    size: 18
    doc: 0xFF on all four units.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: bcd16_0c0
    type: u2
    repeat: expr
    repeat-expr: 8
    doc: |
      Eight u16 values; most read as little-endian BCD in 100 kHz units inside the VHF band
      (four digits, same nibble rule as `bcd_freq32`). The first entry differs on one unit. No reader traced; purpose UNPROVEN. An early
      decode mistook this area for the VHF breakpoint table; the breakpoints are at 0x33c.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: level_uhf
    type: points5(0xd0 + _index * 5)
    repeat: expr
    repeat-expr: 3
    doc: |
      Three UHF five-point tables at 0xd0, 0xd5, 0xda (level 0, 1, 2), the UHF counterpart of
      `level_vhf` (band bit SET). Same consumer caveat: probably TX power low/mid/high, UNPROVEN.
      Per unit.
    doc-ref: DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424 (bases 0xd0/0xd5/0xda, flag-set path)
    -dm32-confidence: CONFIRMED
  - id: unknown_0df
    type: u1
    doc: 0xFF on all four units; also the overlap byte level_uhf[2].reach can address.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: bound_0e0
    type: points5(0xe0)
    doc: Second member of the bound_check pair (+0xe5, +0xe0). Quantity and band UNPROVEN. Per unit.
    doc-ref: DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
    -dm32-confidence: STRUCTURAL
  - id: bound_0e5
    type: points5(0xe5)
    doc: First member of the bound_check pair (+0xe5, +0xe0). Quantity and band UNPROVEN. Per unit.
    doc-ref: DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
    -dm32-confidence: STRUCTURAL
  - id: bound_0ea
    type: points5(0xea)
    doc: |
      Second member of the bound_check pair (+0xef, +0xea). On one unit 0xea-0xf3 is a copy of
      0xe0-0xe9, the same duplication pattern as at 0x6e. Quantity and band UNPROVEN.
    doc-ref:
      - DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
      - four-unit comparison
    -dm32-confidence: STRUCTURAL
  - id: bound_0ef
    type: points5(0xef)
    doc: First member of the bound_check pair (+0xef, +0xea). Quantity and band UNPROVEN.
    doc-ref: DM32.00.01.048 channel_step_frequency_bound_check @0x0301b214
    -dm32-confidence: STRUCTURAL
  - id: unknown_0f4
    size: 20
    doc: |
      Identical on all four units except where one unit's duplicated 0xea table runs into it;
      groups of five bytes like the tables before it. No reader traced. UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_108
    size: 0x48
    doc: 0xFF on all four units.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: freqs_150
    type: bcd_freq32
    repeat: expr
    repeat-expr: 3
    doc: |
      Three more frequency-shaped values (u32 LE packed BCD, 10 Hz units) inside the UHF band,
      identical on all four units, close to but not equal to `freqs_030`. No reader traced.
      Purpose UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_15c
    size: 0xa4
    doc: Mostly 0xFF; one non-0xFF byte, identical on all four units. UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: unknown_200
    size: 0x100
    doc: |
      Starts with about 20 non-0xFF bytes identical on all four units, then 0xFF. No reader
      traced. UNPROVEN.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: breakpoints_uhf_copy
    type: bcd_freq32
    repeat: expr
    repeat-expr: 5
    doc: |
      A byte-identical copy of `breakpoints_uhf`. The interpolators never use base 0x300 (an
      early decode wrongly did). Kept for comparison: a mismatch between the copy and the live
      table is worth investigating, not repairing.
    doc-ref:
      - DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130 (literal base 0x314, never 0x300)
      - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md 0x02 (0x300-0x34F band table)
    -dm32-confidence: STRUCTURAL
  - id: breakpoints_uhf
    type: bcd_freq32
    repeat: expr
    repeat-expr: 5
    doc: |
      The five UHF calibration breakpoints (u32 LE packed BCD, 10 Hz units), ascending across
      the UHF band. Read 4 bytes at a time from base 0x314 when the band bit is SET; the
      interpolators bracket the channel frequency between two of these and interpolate the
      matching pair of table bytes. Same values on all four units examined.
    doc-ref:
      - DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130
      - DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424
    -dm32-confidence: CONFIRMED
  - id: breakpoints_vhf_copy
    type: bcd_freq32
    repeat: expr
    repeat-expr: 5
    doc: A byte-identical copy of `breakpoints_vhf`; base 0x328 is never used by the interpolators.
    doc-ref: DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130 (literal base 0x33c)
    -dm32-confidence: STRUCTURAL
  - id: breakpoints_vhf
    type: bcd_freq32
    repeat: expr
    repeat-expr: 5
    doc: |
      The five VHF calibration breakpoints (u32 LE packed BCD, 10 Hz units), ascending across
      the VHF band. Read from base 0x33c when the band bit is CLEAR.
    doc-ref:
      - DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130
      - DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424
    -dm32-confidence: CONFIRMED
  - id: band_mod_breakpoints
    type: bcd_freq32
    repeat: expr
    repeat-expr: 20
    doc: |
      0xFF on stock units. A band-modified unit carries four extra breakpoint tables here, in the
      same layout as 0x300-0x34f: two identical five-entry tables for a 300 MHz range (0x350,
      0x364) and two for a 200 MHz range (0x378, 0x38c). No stock DM32.00.01.048 code reads them
      (the interpolators only use 0x314 and 0x33c), so they belong to modified firmware. Use
      `is_blank` to tell the cases apart.
    doc-ref:
      - four-unit comparison (one band-modified unit)
      - github.com/yo3hjv/Baofeng-DM32 Firmware_versions/ (band-modified 046 images)
    -dm32-confidence: INFERRED
  - id: unknown_3a0
    size: 0xc5f
    doc: |
      0xFF on all four units examined (other units or firmware versions may use it). The stock
      firmware reads block 2 at many literal offsets as ordinary settings (119 reads); which of
      those land here is not mapped.
    doc-ref: four-unit comparison
    -dm32-confidence: INFERRED
  - id: tag
    type: u1
    valid: 0x02
    doc: Logical block ID 0x02 (page tag at +0xFFF).
    doc-ref:
      - DM32.00.01.048 flash_page_tag_search @0x0300f52c
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Metadata System"
    -dm32-confidence: CONFIRMED
types:
  points5:
    doc: |
      Five one-byte calibration points, one per breakpoint of the band. The firmware reads them
      with 2-byte reads at (base + i), i = bracket index, and passes the two bytes as the low and
      high value to linear_interpolate_freq_calibration. Index 4 (top of band) is clamped before
      use, but the addressable extent is still 6 bytes, so the 6th byte belongs to whatever
      follows (instance `reach`). Copying exactly 5 bytes per table drops that overlap.
    doc-ref: DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424
    -dm32-confidence: CONFIRMED
    params:
      - id: base
        type: u2
        doc: Offset of this table inside the calibration page (the literal the firmware adds to).
        doc-ref: DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424
        -dm32-confidence: CONFIRMED
    seq:
      - id: points
        type: u1
        repeat: expr
        repeat-expr: 5
        doc: Raw point values, unscaled. Scaling depends on the consumer and is only traced for modulation bias.
        doc-ref: DM32.00.01.048 linear_interpolate_freq_calibration @0x0301b000
        -dm32-confidence: CONFIRMED
    instances:
      reach:
        io: _parent._io
        pos: base
        size: 6
        doc: The six bytes the firmware's overlapping 2-byte reads can reach (points plus the next byte).
        doc-ref: DM32.00.01.048 freq_calibration_interpolate_selected @0x0301b424
        -dm32-confidence: CONFIRMED
  bcd_freq32:
    doc: |
      A frequency as u32 little-endian packed BCD, eight digits, 10 Hz units (so the most
      significant nibble is hundreds of MHz). 0xFFFFFFFF means unused.
    doc-ref:
      - DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130
      - infamy/DM32-Protocol-Spec 06-ENCODING.md "BCD Frequency Encoding" (same codec as channel frequencies)
    -dm32-confidence: CONFIRMED
    seq:
      - id: raw
        type: u4
        doc: Packed BCD as stored.
        doc-ref: DM32.00.01.048 freq_calibration_interpolate_single @0x0301b130
        -dm32-confidence: CONFIRMED
    instances:
      is_blank:
        value: raw == 0xffffffff
        doc: True for an erased (unused) entry.
        doc-ref: four-unit comparison
        -dm32-confidence: CONFIRMED
      freq_10hz:
        value: >-
          ((raw >> 28) & 15) * 10000000 + ((raw >> 24) & 15) * 1000000
          + ((raw >> 20) & 15) * 100000 + ((raw >> 16) & 15) * 10000
          + ((raw >> 12) & 15) * 1000 + ((raw >> 8) & 15) * 100
          + ((raw >> 4) & 15) * 10 + (raw & 15)
        doc: Decoded frequency in units of 10 Hz (meaningless when is_blank).
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "BCD Frequency Encoding"
        -dm32-confidence: CONFIRMED

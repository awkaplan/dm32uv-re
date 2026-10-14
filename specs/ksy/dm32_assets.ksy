meta:
  id: dm32_assets
  title: DM-32UV asset region (data-chip V-frame 0x06) - directory plus data
  file-extension: bin
  endian: le
  ks-version: '0.11'
  -dm32-confidence: INFERRED
doc: |
  The data-chip region the radio reports in CPS V-frame 0x06 (0x201000-0x264FFF on firmware 046;
  infamy lists its purpose as unknown). Its first 4 KB page, read from a DM32.00.01.048 radio, is a
  directory of 16-byte entries (index, offset, length, kind); the rest is opaque data. The root is a
  read starting at the region's first byte (the directory page alone is enough).

  The whole region is byte-identical on two other units' full images, and the directory page is
  identical on a third, so it is fixed content shipped with the radio, not user data. It is not
  free space.

  WHAT THE ENTRIES ARE (INFERRED, not traced in stock code). Kind 1 entries are blobs of roughly
  3-18 KB laid end to end; kind 0 entries are empty (length 0, offset = end of the previous blob);
  kind 2 entries carry no data of their own and instead list two to four other entry indices -
  for example entries composed as (2, 10, 1) and (10, n) for n = 1..9. That is how spoken numbers
  are built from digit clips ("two-ten-one" = 21), so the blobs are most likely voice-prompt audio
  clips and kind 2 a phrase. Unconfirmed: no consumer has been traced and no blob decoded.

  OPEN: the base of `offset`. Relative to the region start, the first blob begins right after the
  directory page (consistent) but the last blobs end about 0x730 bytes past the region's reported
  end, where a read of this unit shows 72-byte icon data instead; relative to 0x200000, the first
  blob would overlap the directory. Neither reading is consistent with all evidence, so offsets
  are given raw and no blob is sliced out here.
doc-ref:
  - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x06" (MIT)
  - hardware read of the region's first page, one DM32.00.01.048 unit (per-unit dumps are not in this repo)
seq:
  - id: directory
    type: entry
    size: 16
    repeat: expr
    repeat-expr: 256
    doc: |
      The first 4 KB page as 256 entry slots. On the unit read, slots 0x00-0xEF are populated and
      0xF0-0xFF are 0xFF; whether the directory continues on the next page is unknown.
    doc-ref: hardware read of the region's first page (DM32.00.01.048)
    -dm32-confidence: STRUCTURAL
  - id: data
    size-eos: true
    doc: Everything after the directory page, kept opaque.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x06"
    -dm32-confidence: STRUCTURAL
types:
  entry:
    doc: One 16-byte directory entry.
    doc-ref: hardware read of the region's first page (DM32.00.01.048)
    -dm32-confidence: STRUCTURAL
    seq:
      - id: index
        type: u1
        doc: Entry number, equal to the slot number on the unit read (0xFF in unused slots).
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
      - id: offset_lo
        type: u2
        doc: Data offset bits 15-0 (see `offset`).
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
      - id: offset_hi
        type: u1
        doc: Data offset bits 23-16.
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
      - id: length
        type: u2
        doc: |
          Data length in bytes (0 for kinds 0 and 2). On the unit read, entries are laid out end
          to end: the next entry's offset is offset + (length & ~15) + 16 after a kind-1 entry,
          offset + 2 * count after a kind-2 entry (its index list is apparently stored in the data
          area too), and unchanged after a kind-0 entry.
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
      - id: kind
        type: u1
        doc: 0 empty, 1 data blob, 2 composite (list of entry indices in `params`); 0xFF unused slot.
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: INFERRED
      - id: params
        size: 9
        doc: 0xFF for kinds 0/1; for kind 2 a count byte and that many u16 entry indices (see `composite`).
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
    instances:
      offset:
        value: (offset_hi << 16) | offset_lo
        doc: Data offset; its base is unresolved (see the top-level doc).
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: INFERRED
      composite:
        pos: 7
        type: composite
        if: kind == 2
        doc: The entry indices a kind-2 entry is composed of.
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: INFERRED
  composite:
    doc: Count byte plus up to four u16 entry indices.
    doc-ref: hardware read of the region's first page (DM32.00.01.048)
    -dm32-confidence: INFERRED
    seq:
      - id: count
        type: u1
        doc: Number of parts (2-3 observed; at most 4 fit).
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: INFERRED
      - id: parts
        type: u2
        repeat: expr
        repeat-expr: 'count <= 4 ? count : 0'
        doc: Entry indices, in playback/assembly order.
        doc-ref: hardware read of the region's first page (DM32.00.01.048)
        -dm32-confidence: INFERRED

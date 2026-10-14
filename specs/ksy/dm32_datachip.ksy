meta:
  id: dm32_datachip
  title: DM-32UV 16 MB data chip (Winbond W25Q128) - region map
  file-extension: bin
  endian: le
  ks-version: '0.11'
  imports:
    - dm32_codeplug
    - dm32_boot_image
    - dm32_assets
    - dm32_contacts
  -dm32-confidence: STRUCTURAL
doc: |
  The second SPI-NOR chip of the DM-32UV: a 16 MB Winbond W25Q128 (JEDEC EF 40 18) on SSI unit 0
  with chip select GPIO 0x12, separate from the 1 MB program flash. The stock firmware reaches it
  with opcode 0x03 and a 24-bit address formed as (page << 12) | offset (spi_flash_read_seq). It
  holds the codeplug, the per-unit calibration page, fonts, icons, the power-on picture, an asset
  region (probably voice prompts), the DMR contact database and more. The boot ROM's serial read
  cannot see this chip.

  The root is a read starting at chip address 0: either the whole 16 MB or any whole-page prefix
  of it. Each region below is decoded only if the read reaches the region's end (the config
  region is also decoded when cut short); anything left over is kept in `remainder`, so any such
  read round-trips byte for byte.

  REGION MAP. The boundaries are the ones the radio itself reports through the CPS V-frame
  memory pointers (0x06-0x0A, 0x0E, 0x0F), as decoded from an OEM CPS capture of a DP570UV running
  DM32.01.01.046 in infamy's DM32-Protocol-Spec. Reads of a DM32.00.01.048 radio agree at every
  point sampled (config region, 0x0C9000, 0x0D0000, 0x0E0000, 0x150000, 0x180000, 0x201000,
  0x265000, 0x6DC000). Other firmware builds can move the ends (one build's contact database runs
  to 0xFFFFFF); a tool should read the V-frames rather than trust these constants.

  SAFETY. Nothing on this chip is free space. Every gap between reported regions that has been
  read holds data, and regions that read 0xFF on one radio (the contact database, the tail) are
  full on another. The calibration page (logical block 0x02, inside the config region, at a
  different page on every unit) is irreplaceable: see dm32_calibration.ksy. This description is
  for reading and comparing dumps; writes stay a manual, per-page, backed-up human step.

  Credit: region map from infamy's DM32-Protocol-Spec (MIT License, Copyright (c) 2025 DM-32UV
  Protocol Documentation Contributors; github.com/infamy/DM32-Protocol-Spec, commit 62b9b36),
  04-MEMORY-LAYOUT.md "Memory Regions by V-Frame". Content descriptions of regions infamy lists
  as unknown come from this project's hardware reads and say so.
doc-ref:
  - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Memory Organization", "Memory Regions by V-Frame" (MIT)
  - DM32.00.01.048 spi_flash_read_seq @0x0002b99c, flash_page_tag_search @0x0300f52c
  - Winbond W25Q128JV datasheet Rev F (4,096 x 4 KB sectors)
seq:
  - id: page0
    size: 0x1000
    if: _io.size >= 0x1000
    doc: |
      0x000000-0x000FFF. No V-frame points here and the OEM CPS never touches it. In the stock
      firmware's 200-entry page-tag table this is index 0, which flash_block_id_resolve skips. On
      the unit read its tag byte is 0xFF. Unknown.
    doc-ref:
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Memory Organization"
      - DM32.00.01.048 flash_block_id_resolve @0x0300f364
    -dm32-confidence: STRUCTURAL
  - id: config
    type: dm32_codeplug
    size: '_io.size >= 0xc9000 ? 0xc8000 : _io.size - 0x1000'
    if: _io.size > 0x1000
    doc: |
      0x001000-0x0C8FFF (V-frame 0x0A, pages 1-200): the logical-ID-tagged config region -
      codeplug, settings, the two-tone list and the calibration page. The stock firmware's page-tag
      table has 200 entries (pages 0-199), so page 200 (0x0C8000) is reported by the V-frame but
      not covered by that table; why is not known.
    doc-ref:
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0A - Main Config Block (CRITICAL)"
      - DM32.00.01.048 flash_page_tag_search @0x0300f52c (IRAM tag table 0x0002feb4)
    -dm32-confidence: CONFIRMED
  - id: fonts
    type: font_region
    size: 0x81000
    if: _io.size >= 0x14a000
    doc: |
      0x0C9000-0x149FFF (V-frame 0x07, infamy - unknown). Reads at 0x0C9000, 0x0D0000 and
      0x0E0000 show 1-bit glyph bitmaps in 16-byte cells (there the last byte of every 16-byte
      cell is 0, for no other stride) - fonts. Over the whole region only about 63% of 16-byte
      cells end in 0, so other cell sizes probably occur further in. Identical on two units' full
      images and in every sample from a third.
      Not free space.
    doc-ref:
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x07"
      - hardware reads at 0x0C9000, 0x0D0000, 0x0E0000 (DM32.00.01.048)
    -dm32-confidence: STRUCTURAL
  - id: gap_14a000
    size: 0x6000
    if: _io.size >= 0x150000
    doc: 0x14A000-0x14FFFF, no V-frame. Read as all 0xFF on one unit. Unknown; not proven free.
    doc-ref:
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Memory Organization" (gaps)
      - hardware read at 0x14A000 (DM32.00.01.048)
    -dm32-confidence: INFERRED
  - id: boot_image
    type: dm32_boot_image
    size: 0x26000
    if: _io.size >= 0x176000
    doc: 0x150000-0x175FFF (V-frame 0x0E), the power-on picture.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0E - Boot / Startup Image"
    -dm32-confidence: CONFIRMED
  - id: gap_176000
    size: 0xa000
    if: _io.size >= 0x180000
    doc: 0x176000-0x17FFFF, no V-frame. Read as all 0xFF on one unit. Unknown; not proven free.
    doc-ref:
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Memory Organization" (gaps)
      - hardware read at 0x176000 (DM32.00.01.048)
    -dm32-confidence: INFERRED
  - id: icons
    type: icon_region
    size: 0x81000
    if: _io.size >= 0x201000
    doc: |
      0x180000-0x200FFF (V-frame 0x08, infamy - unknown; an older "zones" label there was wrong).
      The first page read on one unit is 1-bit bitmaps on a 72-byte stride from the region start
      (24 x 24 pixels, 3 bytes per row, last byte of each cell 0) - icons. Over the whole region
      the stride rule holds for only 60-70% of cells, and one of three units differs here, so the
      72-byte cells are evidenced for the start of the region only.
    doc-ref:
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x08"
      - hardware read at 0x180000 (DM32.00.01.048)
    -dm32-confidence: STRUCTURAL
  - id: assets
    type: dm32_assets
    size: 0x64000
    if: _io.size >= 0x265000
    doc: 0x201000-0x264FFF (V-frame 0x06), directory plus data, probably voice prompts. See dm32_assets.ksy.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x06"
    -dm32-confidence: STRUCTURAL
  - id: gap_265000
    type: icon_region
    size: 0x13000
    if: _io.size >= 0x278000
    doc: |
      0x265000-0x277FFF, no V-frame. NOT free: a full read of one unit is 24 x 24 1-bit icons on
      the same 72-byte stride as `icons` (all 19 pages non-blank), and another unit has it ~98%
      occupied.
    doc-ref:
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "Memory Organization" (gaps)
      - hardware read of the whole range (DM32.00.01.048)
    -dm32-confidence: STRUCTURAL
  - id: contacts
    type: dm32_contacts
    size: 0x464000
    if: _io.size >= 0x6dc000
    doc: |
      0x278000-0x6DBFFF (V-frame 0x0F), the DMR contact database - and, from 0x635000, tagged
      non-contact pages (see dm32_contacts.ksy). Mostly 0xFF on a radio with few contacts - still
      not free.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0F - DMR Contact Database"
    -dm32-confidence: CONFIRMED
  - id: tail
    type: tail_region
    size: 0x924000
    if: _io.size >= 0x1000000
    doc: |
      0x6DC000-0xFFFFFF (V-frame 0x09, infamy - unknown). Starts with the firmware's
      tag-searched record pages. On one unit nearly every page of the tail holds data (about half
      of all bytes) and many pages carry tag bytes; on another it is blank but for the chip's last
      page.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x09"
    -dm32-confidence: STRUCTURAL
  - id: remainder
    size-eos: true
    doc: Whatever part of the read did not cover a whole region (empty for a full 16 MB image).
    doc-ref: this description
    -dm32-confidence: CONFIRMED
types:
  font_region:
    doc: The V-frame 0x07 region as 16-byte glyph cells. Cell geometry (8 x 16, one byte per row is the natural reading of the first page) and the character mapping are not established.
    doc-ref: hardware reads at 0x0C9000, 0x0D0000, 0x0E0000 (DM32.00.01.048)
    -dm32-confidence: STRUCTURAL
    seq:
      - id: cells
        size: 16
        repeat: eos
        doc: 16-byte cells from the region start (0x81000 / 16 = 33,024 cells).
        doc-ref: hardware reads at 0x0C9000, 0x0D0000, 0x0E0000 (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
  icon_region:
    doc: 72-byte cells (24 x 24 at 1 bit per pixel, 3 bytes per row) from the region start, plus any remainder.
    doc-ref: hardware reads at 0x180000 and 0x265000 (DM32.00.01.048)
    -dm32-confidence: STRUCTURAL
    seq:
      - id: icons
        size: 72
        repeat: expr
        repeat-expr: _io.size / 72
        doc: Icon cells.
        doc-ref: hardware reads at 0x180000 and 0x265000 (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
      - id: rest
        size-eos: true
        doc: Bytes after the last whole cell (the region size is not a multiple of 72).
        doc-ref: this description
        -dm32-confidence: STRUCTURAL
  tagged_page:
    doc: A 4 KB page whose last byte is a tag, as searched by flash_page_tag_search.
    doc-ref: DM32.00.01.048 flash_page_tag_search @0x0300f52c
    -dm32-confidence: CONFIRMED
    seq:
      - id: body
        size: 0xfff
        doc: Page content (erased on the unit read).
        doc-ref: hardware read at 0x6DC000 (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
      - id: tag
        type: u1
        doc: Page tag (0xA5 / 0xA6 seen; 0xFF = free).
        doc-ref: hardware read at 0x6DC000 (DM32.00.01.048)
        -dm32-confidence: STRUCTURAL
  tail_region:
    doc: |
      The V-frame 0x09 region. Its first nine pages (data-chip pages 1756-1764) are the two ranges
      the stock firmware's tag search scans (type 0 pages 1756-1758, type 1 pages 1759-1764, from
      four IRAM configuration words); tags 0xA5/0xA6 were found there on two units. What they
      record is not traced. The rest is opaque and, on one unit, a tagged-page store of its own.
    doc-ref:
      - DM32.00.01.048 flash_page_tag_search @0x0300f52c (range words in IRAM 0x0003ffbc-0x0003ffd4)
      - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x09"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: record_pages
        type: tagged_page
        size: 0x1000
        repeat: expr
        repeat-expr: 9
        doc: Pages 1756-1764.
        doc-ref: DM32.00.01.048 flash_page_tag_search @0x0300f52c
        -dm32-confidence: CONFIRMED
      - id: rest
        size-eos: true
        doc: 0x6E5000 onward, unknown.
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x09"
        -dm32-confidence: INFERRED

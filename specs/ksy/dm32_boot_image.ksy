meta:
  id: dm32_boot_image
  title: DM-32UV power-on picture (data-chip region at V-frame 0x0E)
  file-extension: bin
  endian: le
  ks-version: '0.11'
  -dm32-confidence: STRUCTURAL
doc: |
  The power-on picture shown when settings choose "picture" at power-on. The radio reports the
  region in CPS V-frame 0x0E (0x150000-0x175FFF, 152 KiB). It holds 240 x 320 portrait pixels,
  16 bits each, raw (no header): 153,600 bytes, followed by 2,048 bytes to the end of the region
  (0xFF on the unit read). The root is a read starting at the region's first byte.

  The vendor's Picture Tool and third-party CPS tools replace this picture, so it can be user
  content; on the three units examined it is the same (stock) picture.

  Credit: region from infamy's DM32-Protocol-Spec (MIT, github.com/infamy/DM32-Protocol-Spec)
  04-MEMORY-LAYOUT.md "V-Frame 0x0E"; the pixel format (BGR565, no header, 37 x 4 KB + 2 KB
  transfers) there comes from the NeonPlug boot-image feature, exercised against hardware.
  A read of this region from a DM32.00.01.048 radio has exactly the region's size and parses as
  described; the colour order was not independently checked.
doc-ref:
  - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0E - Boot / Startup Image" (MIT)
seq:
  - id: rows
    type: row
    repeat: expr
    repeat-expr: 320
    doc: 320 rows, top to bottom.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0E - Boot / Startup Image"
    -dm32-confidence: STRUCTURAL
  - id: tail
    size-eos: true
    doc: Rest of the region (2,048 bytes for a whole-region read), unused by the picture.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0E - Boot / Startup Image"
    -dm32-confidence: STRUCTURAL
types:
  row:
    doc: One row of 240 pixels, left to right.
    doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0E - Boot / Startup Image"
    -dm32-confidence: STRUCTURAL
    seq:
      - id: pixels
        type: u2
        repeat: expr
        repeat-expr: 240
        doc: BGR565 pixel as a little-endian u16 (colour order per infamy, not independently checked).
        doc-ref: infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0E - Boot / Startup Image"
        -dm32-confidence: INFERRED

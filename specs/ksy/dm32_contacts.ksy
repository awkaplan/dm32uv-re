meta:
  id: dm32_contacts
  title: DM-32UV DMR contact database (data-chip region at V-frame 0x0F)
  file-extension: bin
  endian: le
  ks-version: '0.11'
  -dm32-confidence: STRUCTURAL
doc: |
  The DMR contact address book: a raw region of the data chip (no logical-ID tags) whose start
  and end the radio reports in CPS V-frame 0x0F (0x278000-0x6DBFFF on firmware 046; the end
  varies by firmware, and a firmware with a larger database reaches 0xFFFFFF). V-frame 0x10 gives
  the maximum contact count. The root is a read starting at the region's first byte, any whole
  number of 4 KB pages.

  Layout: a 16-byte region header (u32 count) at the start; then 44 records of 92 bytes per
  4 KB page - page 0 after the header, every later page from its offset 0. Records never straddle
  a page; the slack at the end of each page (32 bytes on page 0, 48 on the others) includes the
  page's last byte, which is NOT a logical-ID tag here and is preserved verbatim by the OEM CPS.

  CAUTION: a large part of this region reads 0xFF on radios with no contacts loaded. That is not
  free space - writing there destroys the contact list of any radio that has one.

  NOT ONLY CONTACTS. On two units' full data-chip images, the pages from 0x635000 to the
  region's reported end carry page tags (0x00-0x0F, 0xA5, 0xA6) and non-contact data (high-entropy
  pages on one unit). So the contact records end before that point - at 44 per page, the pages
  from 0x278000 to 0x634FFF hold at most 42,108 records, fewer than the 50,000 V-frame 0x10
  reports. Where the contact area really ends, and what the tagged pages are, is not established;
  this description decodes every page as contacts (lossless either way) and says so here.

  Credit: layout from infamy's DM32-Protocol-Spec (MIT, github.com/infamy/DM32-Protocol-Spec),
  05-DATA-STRUCTURES.md "DMR Contact Database" and 04-MEMORY-LAYOUT.md "V-Frame 0x0F". There,
  only the header and the first record are hardware-attested and the 44-per-page walk comes
  from the NeonPlug implementation (DERIVED). This project checked the walk against two other
  units' published full images (github.com/yo3hjv/Baofeng-DM32, unlicensed, not redistributed):
  with several hundred and several thousand contacts loaded, every record up to the header
  count decodes as a valid record across many pages, and byte +0x13 is 0xF0 in all of them.
doc-ref:
  - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "DMR Contact Database (V-frame 0x0F region)" (MIT)
  - infamy/DM32-Protocol-Spec 04-MEMORY-LAYOUT.md "V-Frame 0x0F - DMR Contact Database" (MIT)
seq:
  - id: first_page
    type: first_page
    size: 0x1000
    if: _io.size >= 0x1000
    doc: Page 0 of the region - header plus contacts 0-43.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
    -dm32-confidence: CONFIRMED
  - id: pages
    type: page
    size: 0x1000
    repeat: eos
    doc: Pages 1 onward, 44 contacts each (contact index = 44 * page + i). See the top-level doc for the tagged pages near the region's end.
    doc-ref:
      - infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
      - two published full data-chip images (github.com/yo3hjv/Baofeng-DM32)
    -dm32-confidence: CONFIRMED
types:
  first_page:
    doc: Region header and the first 44 contacts.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
    -dm32-confidence: CONFIRMED
    seq:
      - id: count
        type: u4
        doc: Number of contacts (u32 LE; the OEM CPS reads exactly these 4 bytes first).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
        -dm32-confidence: CONFIRMED
      - id: header_unknown
        size: 12
        doc: 0xFF in both OEM captures (one implementation zero-fills them - a divergence). Unknown.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
        -dm32-confidence: STRUCTURAL
      - id: contacts
        type: contact
        repeat: expr
        repeat-expr: 44
        doc: Contacts 0-43 at 0x10 + i * 0x5C.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
        -dm32-confidence: CONFIRMED
      - id: slack
        size: 32
        doc: 0xFE0-0xFFF, unused; 0xFFF is not a tag.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
        -dm32-confidence: STRUCTURAL
  page:
    doc: A later page of 44 contacts.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
    -dm32-confidence: CONFIRMED
    seq:
      - id: contacts
        type: contact
        repeat: expr
        repeat-expr: 44
        doc: Contacts at i * 0x5C.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
        -dm32-confidence: CONFIRMED
      - id: slack
        size: 48
        doc: 0xFD0-0xFFF, unused (0xFF on the pages checked); 0xFFF is not a tag.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Region header and block math"
        -dm32-confidence: STRUCTURAL
  u24:
    doc: Unsigned 24-bit little-endian integer (binary, not BCD).
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
        doc: The integer.
        doc-ref: infamy/DM32-Protocol-Spec 06-ENCODING.md "Integer Encoding and Endianness"
        -dm32-confidence: CONFIRMED
  contact:
    doc: |
      One 92-byte contact, fixed-offset fields (an older "packed Normal vs Big" reading exists and
      is DERIVED). Text is ASCII, NUL-terminated, 0xFF-padded; decoded as ISO-8859-1 so every byte
      round-trips. Empty = first name byte 0x00 or 0xFF. No call-type field exists in the record.
    doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
    -dm32-confidence: CONFIRMED
    seq:
      - id: name
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: Name, max 15 characters + NUL.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: CONFIRMED
      - id: dmr_id
        type: u24
        doc: DMR ID, u24 LE. Often documented as a u32; the only hardware record contradicts that.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: CONFIRMED
      - id: flag_13
        type: u1
        doc: Unknown; 0xF0 in every record seen (infamy's capture and two other units). Preserve.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: STRUCTURAL
      - id: callsign
        type: str
        size: 8
        encoding: ISO-8859-1
        doc: Callsign, max 7 characters + NUL (all 0xFF when empty).
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: CONFIRMED
      - id: city
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: City.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: INFERRED
      - id: province
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: Province / state.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: INFERRED
      - id: country
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: Country.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: INFERRED
      - id: remark
        type: str
        size: 16
        encoding: ISO-8859-1
        doc: Remark.
        doc-ref: infamy/DM32-Protocol-Spec 05-DATA-STRUCTURES.md "Contact entry (92 bytes / 0x5C)"
        -dm32-confidence: INFERRED

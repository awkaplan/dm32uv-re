meta:
  id: dm32_firmware_image
  title: Baofeng DM-32UV program-flash image (HR_C7000 SoC, firmware DM32.00.01.048)
  file-extension: bin
  ks-version: '0.11'
  endian: le
  -dm32-confidence: STRUCTURAL
doc: |
  The 1 MB GD25Q80 program flash of the DM-32UV, as read out of the radio, and its truncated
  form. The SoC executes it in place at 0x03000000, so file offset N is CPU address
  0x03000000 + N. Two files in this repository have this layout:

    data/firmware/patching/progmem_stock_DP570UV_20260926_FULL.bin  the whole flash, 0x100000 bytes
    data/firmware/DM32.00.01.048.bin                                 the same image cut at 0xd2100

  Both are reads of one radio with the per-unit sector (0x0300b000) blanked to 0xFF; every byte
  they share is identical. There is no vendor download of this build. The cut file ends inside
  the IRAM load image, so iram_load_image is absent when parsing it.

  Layout (file offsets):
    0x000000  image_header, 4 KB: the boot ROM's DH_FLAG and entry address, then padding
    0x001000  entry_region: the code the boot ROM jumps to, with its own crt0 and copy table
    0x00b000  per_unit_sector: different on every radio; opaque here, never interpreted
    0x00c000  app_region: second crt0 (0x0300c000), then the application, its SRAM
              initialised-data image (0x072000), its IRAM load image (0x0bfc20..0x0decb8) and a
              short trailer (to 0x0e04c0); 0xFF (erased) after that in the full image

  Both crt0s are the same 0x74-byte routine (byte-identical) reading a 13-word literal pool
  (boot_stub_pool): it sets PSR, SP and VBR, writes three words to 0xE000F000, copies the SRAM
  data image, copies the IRAM image, zero-fills .bss, then calls main in IRAM. What the entry
  region's program does, and how control reaches 0x0300c000, are not traced here.

  Uses beyond parsing: the instances give a loader everything it needs to map the image (flash
  base, IRAM and SRAM images and their run addresses, VBR), so the generated Java (ksc -t java
  --read-write) could drive a Ghidra loader in place of hand-written offsets. Not done yet.

  Never build a flashable image from a parse of another radio's read: per_unit_sector carries
  that radio's hardware-binding record (see data/firmware/patching/README.md).
doc-ref:
  - HR_C7000 datasheet v2.2 (zh), boot flowchart, p.24 (DH_FLAG at flash 0, jump address at flash 4)
  - this project's disassembly of the 2 KB mask boot ROM (offsets 0x5c-0x72 compare flash+0 with 0x0c646874, then jump to the word at flash+4)
  - github.com/fenfir/hd2_infodump (same SoC family; DH_FLAG value 0x0c646874)
  - stock DM32.00.01.048 crt0 at 0x0300c000 and 0x03001000 (meta/disasm.jsonl)
  - tools/src/dm32_patch_tools/derive_iram.py, data/firmware/patching/occupied_regions.json
seq:
  - id: header
    size: 0x1000
    type: image_header
    doc: Flash 0x03000000..0x03000fff. The boot ROM reads only its first 8 bytes.
    -dm32-confidence: CONFIRMED
  - id: entry_region
    size: 0xa000
    doc: |
      Flash 0x03001000..0x0300afff, entered by the boot ROM (header.entry). Starts with a crt0
      whose copy table is entry_stub_pool. Kept as raw bytes; the decompiled corpus covers the
      functions in it.
  - id: per_unit_sector
    size: 0x1000
    doc: |
      Flash 0x0300b000..0x0300bfff. Per-unit data, different on every radio: a 4-byte record at
      +0x10c derived from the SoC eFuse ID (compared by the firmware's hardware-binding check)
      and per-unit hardware bytes at +0x80..+0x82 and +0xa0..+0xa1. Deliberately opaque: this
      description never interprets it. Blanked to 0xFF in every image this repository ships.
    doc-ref: data/firmware/patching/occupied_regions.json; data/firmware/patching/README.md
    -dm32-confidence: CONFIRMED
  - id: app_region
    size-eos: true
    doc: |
      Flash 0x0300c000 to the end of the file: the application, starting with its crt0 at
      0x0300c000 (copy table app_stub_pool). 0xc6100 bytes in the cut file, 0xf4000 in the
      full image.
instances:
  flash_base:
    value: 0x03000000
    doc: CPU address of file offset 0 (execute-in-place flash window).
    doc-ref: data/firmware/README.md "Load base, verified empirically"
    -dm32-confidence: CONFIRMED
  is_full_image:
    value: _io.size == 0x100000
    doc: True for a whole-flash read (1 MB, GD25Q80).
  is_cut_image:
    value: _io.size == 0xd2100
    doc: True for the 0xd2100-byte cut (data/firmware/DM32.00.01.048.bin).
  entry_stub_pool:
    pos: 0x10b0
    type: boot_stub_pool
    doc: |
      Literal pool of the entry region's crt0 (flash 0x030010b0..0x030010e3). On
      DM32.00.01.048: SRAM 0x18000800..0x18000844 from flash 0x03001d00, IRAM
      0x00010000..0x00012a60 from flash 0x03001f48, .bss 0x00012a60..0x00017090; its crt0 then
      calls IRAM 0x0001252c (bsr at 0x03001074).
  app_stub_pool:
    pos: 0xc0b0
    type: boot_stub_pool
    doc: |
      Literal pool of the application's crt0 (flash 0x0300c0b0..0x0300c0e3). On DM32.00.01.048:
      SRAM 0x18000800..0x18004bfc from flash 0x03072000, IRAM 0x00010000..0x0002f098 from flash
      0x030bfc20, .bss 0x0002f098..0x0004a7b0; then calls IRAM 0x0002e158 (bsr at 0x0300c074).
      derive_iram.py checks the iram and bss words before trusting its own constants.
    doc-ref: tools/src/dm32_patch_tools/derive_iram.py (STUB_POOL)
    -dm32-confidence: CONFIRMED
  sram_init_image:
    pos: app_stub_pool.sram_src - flash_base
    size: app_stub_pool.sram_size
    doc: |
      The bytes the application's crt0 copies to SRAM app_stub_pool.sram_dst (initialised data,
      0x43fc bytes on DM32.00.01.048, flash 0x03072000..0x030763fb).
    doc-ref: data/firmware/patching/occupied_regions.json
  iram_load_image_present:
    value: app_stub_pool.iram_src - flash_base + app_stub_pool.iram_size <= _io.size
    doc: |
      False for the cut file, which ends at 0xd2100, inside the IRAM load image
      (0x0bfc20..0x0decb8).
  iram_load_image:
    pos: app_stub_pool.iram_src - flash_base
    size: app_stub_pool.iram_size
    if: iram_load_image_present
    doc: |
      Code and initialised data of the SoC runtime (uC/OS-III, drivers) that the application's
      crt0 copies to IRAM 0x00010000. data/firmware/IRAM_dm32.00.01.048.bin is exactly these
      bytes at IRAM offset 0, zeros above (derive_iram.py).
    doc-ref: tools/src/dm32_patch_tools/derive_iram.py
    -dm32-confidence: CONFIRMED
  trailer_present:
    value: app_stub_pool.iram_src - flash_base + app_stub_pool.iram_size + 0x1808 <= _io.size
    doc: True when the file reaches past the trailer (full image only).
  trailer:
    pos: app_stub_pool.iram_src - flash_base + app_stub_pool.iram_size
    size: 0x1808
    if: trailer_present
    doc: |
      Flash 0x030decb8..0x030e04bf, right after the IRAM load image. Vendor data referenced from
      flash code (0x030ddc64, 0x030de800, 0x030dff01); not decoded. Its length (0x1808) is taken
      from occupied_regions.json, not from any header field.
    doc-ref: data/firmware/patching/occupied_regions.json
types:
  image_header:
    doc: The first 4 KB of flash.
    seq:
      - id: dh_flag
        contents: [0x74, 0x68, 0x64, 0x0c]
        doc: |
          DH_FLAG, u32 0x0c646874 ("thd" 0x0c). The boot ROM compares flash+0 with it after its
          serial handshake times out; on a mismatch it stays in its serial loop instead of booting.
        doc-ref: HR_C7000 datasheet v2.2 (zh), p.24; mask boot ROM offsets 0x5c-0x66
        -dm32-confidence: CONFIRMED
      - id: entry
        type: u4
        doc: |
          Address the boot ROM jumps to (`jmp` to the word at flash+4; it also sends these four
          bytes on the UART first, see hdboot_serial.ksy rom_boot_announce). 0x03001000 on every
          stock image, the start of entry_region. It is an entry point, not a vector table.
        doc-ref: mask boot ROM offsets 0x68-0x72
        -dm32-confidence: CONFIRMED
      - id: magic2
        size: 4
        doc: |
          74 78 64 0f ("txd" 0x0f) on every DM-32 image this project has seen. The boot ROM does
          not read it (its mask ROM contains "thd" but not "txd"); what reads it, if anything, is
          unknown. Kept raw so a non-stock image still parses.
        -dm32-confidence: STRUCTURAL
      - id: rest
        size-eos: true
        doc: |
          Offsets 0x0c..0xfff. Zero except the words exposed as instances below; meaning unknown.
        -dm32-confidence: STRUCTURAL
    instances:
      has_txd_magic:
        value: magic2 == [0x74, 0x78, 0x64, 0x0f]
        doc: True when magic2 holds the value every stock image carries.
        -dm32-confidence: STRUCTURAL
      word_0x20:
        pos: 0x20
        type: u4
        doc: 0xffffffff on DM32.00.01.048; the only non-zero word before 0x350. Meaning unknown.
        -dm32-confidence: INFERRED
      half_0x350:
        pos: 0x350
        type: u2
        doc: 0xa6b5 on DM32.00.01.048. Meaning unknown; not checked against other units' images.
        -dm32-confidence: INFERRED
      half_0x400:
        pos: 0x400
        type: u2
        doc: 0xa6b5 on DM32.00.01.048, same value as half_0x350. Meaning unknown.
        -dm32-confidence: INFERRED
  boot_stub_pool:
    doc: |
      The 13-word literal pool a crt0 loads with `lrw`, in the order it uses them (stock code
      0x0300c000..0x0300c074; the routine at 0x03001000 is byte-identical and has its own pool).
      The copy loops are word-sized: `while (dst < end) *dst++ = *src++`.
    doc-ref: meta/disasm.jsonl, function at 0x0300c000
    seq:
      - id: psr
        type: u4
        doc: Moved to control register cr0 (PSR). 0x80000100 on DM32.00.01.048.
      - id: sp
        type: u4
        doc: Initial stack pointer. 0x00050000.
      - id: vbr
        type: u4
        doc: Moved to cr1 (VBR, vector base). 0x00010000, so the vector table is the start of the IRAM image.
      - id: ctl_base
        type: u4
        doc: |
          0xe000f000. crt0 stores 1 to +4, 4 to +0, ctl_region to +8, then sets bit 0 of +0.
          Consistent with the CK803 cache-control block (enable/invalidate/region registers);
          not confirmed from a datasheet in this repository.
        -dm32-confidence: INFERRED
      - id: ctl_region
        type: u4
        doc: Word written to ctl_base+8. 0x0300002d (flash base in the high bits; low bits not decoded).
        -dm32-confidence: INFERRED
      - id: sram_dst
        type: u4
        doc: First SRAM word of the initialised-data copy.
      - id: sram_end
        type: u4
        doc: End (exclusive) of the SRAM copy.
      - id: sram_src
        type: u4
        doc: Flash address the SRAM copy reads from.
      - id: iram_dst
        type: u4
        doc: First IRAM word of the load-image copy.
      - id: iram_end
        type: u4
        doc: End (exclusive) of the IRAM copy.
      - id: iram_src
        type: u4
        doc: Flash address the IRAM copy reads from.
      - id: bss_start
        type: u4
        doc: First IRAM word zero-filled (.bss).
      - id: bss_end
        type: u4
        doc: End (exclusive) of the zero fill.
    instances:
      sram_size:
        value: sram_end - sram_dst
        doc: Bytes copied to SRAM.
      iram_size:
        value: iram_end - iram_dst
        doc: Bytes copied to IRAM.
      bss_size:
        value: bss_end - bss_start
        doc: Bytes of IRAM zero-filled.

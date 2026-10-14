/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_row_or_text_entry_render @ 0305aee8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_list_row_or_text_entry_render(void)

{
  undefined *puVar1;
  uint uVar2;
  
  puVar1 = PTR_s___________________<>___________0305b034;
  if (PTR_DAT_0305b02c[3] == '\0') {
    scan_list_row_render(PTR_LAB_0305b030);
  }
  else {
    display_draw_string_wrapped2(100,5,PTR_s___________________<>___________0305b034,0,0xffff);
    uVar2 = (uint)*p_text_entry_current_char_alias;
    display_draw_string_ascii_mixed
              ((uVar2 % 0x12) * 0xc + 5,(uVar2 / 0x12 + 1) * 2,puVar1 + uVar2,1,0,0xffff);
  }
  return;
}


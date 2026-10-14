/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_cursor_advance_line_wrap @ 0305ac24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 240 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_cursor_advance_line_wrap(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  char cVar4;
  
  PTR_DAT_0305ad24[5] = 0xf0;
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305ad20,*(undefined2 *)p_text_entry_current_char,
             PTR_LAB_0305ad28,1);
  draw_wrapped_text_conditional();
  bVar1 = *(byte *)PTR_DAT_0305ad2c;
  if ((uint)bVar1 == *(byte *)PTR_DAT_0305ad30 - 1) {
    *(undefined1 *)PTR_DAT_0305ad2c = 0;
    *(undefined2 *)p_text_entry_current_char = 5;
    *(undefined2 *)PTR_DAT_0305ad20 = 0x20;
    if (*(char *)p_text_entry_current_char_alias == '\0') goto LAB_0305ad02;
    *(undefined1 *)p_text_entry_current_char_alias = 0;
    scan_monitor_display_refresh();
  }
  else if ((char)p_text_entry_buffer[bVar1] < '\0') {
    if (0xd8 < *(ushort *)p_text_entry_current_char) {
      *(undefined2 *)p_text_entry_current_char = 5;
      *(short *)PTR_DAT_0305ad20 = *(short *)PTR_DAT_0305ad20 + 0x18;
    }
    *(short *)p_text_entry_current_char = *(short *)p_text_entry_current_char + 0x18;
    *(byte *)PTR_DAT_0305ad2c = bVar1 + 2;
  }
  else {
    *(byte *)PTR_DAT_0305ad2c = bVar1 + 1;
    if (0xe4 < *(ushort *)p_text_entry_current_char) {
      *(undefined2 *)p_text_entry_current_char = 5;
      *(short *)PTR_DAT_0305ad20 = *(short *)PTR_DAT_0305ad20 + 0x18;
    }
    *(short *)p_text_entry_current_char = *(short *)p_text_entry_current_char + 0xc;
  }
  if ((0x107 < *(ushort *)PTR_DAT_0305ad20) &&
     ((int)(uint)*(byte *)PTR_DAT_0305ad2c < (int)(*(byte *)PTR_DAT_0305ad30 - 1))) {
    *(undefined2 *)PTR_DAT_0305ad20 = 0xf0;
    puVar3 = p_text_entry_current_char_alias;
    cVar2 = *(char *)p_text_entry_current_char_alias;
    cVar4 = text_entry_columns_remaining(cVar2);
    *(char *)puVar3 = cVar4 + cVar2;
    scan_monitor_display_refresh();
  }
LAB_0305ad02:
  display_blit_bitmap_1bpp_rows
            (*(undefined2 *)PTR_DAT_0305ad20,*(undefined2 *)p_text_entry_current_char,
             PTR_DAT_0305ad38,1);
  return;
}


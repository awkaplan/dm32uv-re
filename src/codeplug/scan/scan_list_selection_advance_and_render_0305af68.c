/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_list_selection_advance_and_render @ 0305af68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 118 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scan_list_selection_advance_and_render(void)

{
  byte bVar1;
  
  bVar1 = *PTR_DAT_0305b02c;
  if (bVar1 == 2) {
    if ((uint)*(byte *)PTR_DAT_0305b03c == *(byte *)PTR_DAT_0305b040 - 1) {
      *(undefined1 *)PTR_DAT_0305b03c = 0;
    }
    else {
      *(byte *)PTR_DAT_0305b03c = *(byte *)PTR_DAT_0305b03c + 1;
    }
    text_entry_char_picker_render_fixed();
    scan_list_row_render();
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      if ((uint)*(byte *)PTR_DAT_0305b044 == *(byte *)PTR_DAT_0305b048 - 1) {
        *(undefined1 *)PTR_DAT_0305b044 = 0;
      }
      else {
        *(byte *)PTR_DAT_0305b044 = *(byte *)PTR_DAT_0305b044 + 1;
      }
      text_entry_char_picker_render();
      scan_list_row_render();
    }
  }
  else if (bVar1 == 3) {
    text_entry_cursor_advance_line_wrap();
  }
  else if (bVar1 == 4) {
    scan_list_or_text_entry_index_advance_and_render();
  }
  return;
}


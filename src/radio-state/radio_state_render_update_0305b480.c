/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_state_render_update @ 0305b480 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_state_render_update(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)PTR_DAT_0305b5f0;
  if (bVar1 == 2) {
    bVar1 = *(byte *)PTR_DAT_0305b5fc;
    if ((uint)bVar1 % 9 == 0) {
      if (bVar1 == 0) {
        *(char *)PTR_DAT_0305b5fc = *(char *)PTR_DAT_0305b600 + -1;
      }
      else {
        *(byte *)PTR_DAT_0305b5fc = bVar1 - 1;
      }
    }
    else {
      *(byte *)PTR_DAT_0305b5fc = bVar1 - 1;
    }
    text_entry_char_picker_render_fixed();
    scan_list_row_render();
  }
  else if (bVar1 < 3) {
    if (bVar1 == 1) {
      if (*(char *)PTR_DAT_0305b5f4 == '\0') {
        *(char *)PTR_DAT_0305b5f4 = *(char *)PTR_DAT_0305b5f8 + -1;
      }
      else {
        *(char *)PTR_DAT_0305b5f4 = *(char *)PTR_DAT_0305b5f4 + -1;
      }
      text_entry_char_picker_render();
      scan_list_row_render();
    }
  }
  else if (bVar1 == 3) {
    text_entry_cursor_advance_wide_or_narrow();
  }
  else if (bVar1 == 4) {
    ui_countdown_decrement_wrap();
  }
  return;
}


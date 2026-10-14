/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_countdown_decrement_wrap @ 0305afe0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_countdown_decrement_wrap(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)PTR_DAT_0305b03c;
  if ((uint)bVar1 % 9 == 0) {
    if (bVar1 == 0) {
      *(char *)PTR_DAT_0305b03c = *(char *)PTR_DAT_0305b040 + -1;
    }
    else {
      *(byte *)PTR_DAT_0305b03c = bVar1 - 1;
    }
  }
  else {
    *(byte *)PTR_DAT_0305b03c = bVar1 - 1;
  }
  scan_list_row_or_text_entry_render();
  return;
}


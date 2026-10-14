/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_char_row_step_wrap @ 0305b04c (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_char_row_step_wrap(void)

{
  byte bVar1;
  uint uVar2;
  
  if (PTR_DAT_0305b188[3] == '\0') {
    uVar2 = 9;
  }
  else {
    uVar2 = 0x12;
  }
  bVar1 = *(byte *)PTR_text_entry_current_char_minus_2_0305b18c;
  if ((int)uVar2 < (int)((uint)*(byte *)PTR_DAT_0305b190 - (uint)bVar1)) {
    *(byte *)PTR_text_entry_current_char_minus_2_0305b18c = (char)uVar2 + bVar1;
  }
  else {
    *(byte *)PTR_text_entry_current_char_minus_2_0305b18c =
         bVar1 - (char)(bVar1 / uVar2) * (char)uVar2;
  }
  scan_list_row_or_text_entry_render();
  return;
}


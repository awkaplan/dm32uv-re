/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_char_step_up_and_render @ 0305b120 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void text_entry_char_step_up_and_render(void)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  
  puVar3 = PTR_text_entry_current_char_minus_2_0305b18c;
  if (PTR_DAT_0305b188[3] == '\0') {
    uVar6 = 9;
  }
  else {
    uVar6 = 0x12;
  }
  bVar1 = *(byte *)PTR_text_entry_current_char_minus_2_0305b18c;
  if (bVar1 < uVar6) {
    bVar2 = *(byte *)PTR_DAT_0305b190;
    uVar5 = (uint)bVar1 + uVar6 * (bVar2 / uVar6);
    cVar4 = (char)uVar5;
    *(char *)PTR_text_entry_current_char_minus_2_0305b18c = cVar4;
    if ((uint)bVar2 <= (uVar5 & 0xff)) {
      *(char *)puVar3 = cVar4 - (char)uVar6;
    }
  }
  else {
    *(byte *)PTR_text_entry_current_char_minus_2_0305b18c = bVar1 - (char)uVar6;
  }
  scan_list_row_or_text_entry_render();
  return;
}


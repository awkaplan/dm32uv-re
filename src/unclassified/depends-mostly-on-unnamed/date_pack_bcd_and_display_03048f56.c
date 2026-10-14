/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: date_pack_bcd_and_display @ 03048f56 (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void date_pack_bcd_and_display(undefined4 param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  byte bStack00000011;
  
  rtc_decode_calendar_date();
  puVar1 = PTR_DAT_030490b4;
  bStack00000011 = (byte)(param_2 >> 8);
  uVar2 = (param_2 >> 0x10) % 100;
  cVar3 = (char)(uVar2 / 10);
  *(char *)PTR_DAT_030490b4 = cVar3;
  *(char *)((int)puVar1 + 1) = (char)uVar2 + cVar3 * -10;
  *(byte *)((int)puVar1 + 2) = bStack00000011 / 10;
  *(byte *)((int)puVar1 + 3) = bStack00000011 % 10;
  *(char *)(puVar1 + 1) = (char)((param_2 & 0xff) / 10);
  *(char *)((int)puVar1 + 5) = (char)((param_2 & 0xff) % 10);
  *(undefined1 *)PTR_DAT_030490b8 = 0;
  *(undefined2 *)PTR_DAT_030490bc = 100;
  *(undefined2 *)p_text_entry_current_char = 0x54;
  *(undefined2 *)PTR_DAT_030490c4 = 0x54;
  date_ymd_display();
  return;
}


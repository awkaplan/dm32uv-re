/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rtc_date_decode_to_bcd_display_buffer @ 03048ef4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rtc_date_decode_to_bcd_display_buffer(void)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  byte bStack0000000d;
  byte bStack0000000e;
  
  uVar2 = rtc_decode_calendar_date();
  puVar1 = PTR_DAT_030490b4;
  bStack0000000d = (byte)(uVar2 >> 8);
  bStack0000000e = (byte)(uVar2 >> 0x10);
  cVar3 = (char)((uVar2 & 0xff) / 10);
  *(char *)PTR_DAT_030490b4 = cVar3;
  *(char *)((int)puVar1 + 1) = (char)uVar2 + cVar3 * -10;
  *(byte *)((int)puVar1 + 2) = bStack0000000d / 10;
  *(byte *)((int)puVar1 + 3) = bStack0000000d % 10;
  *(byte *)(puVar1 + 1) = bStack0000000e / 10;
  *(byte *)((int)puVar1 + 5) = bStack0000000e % 10;
  *(undefined1 *)PTR_DAT_030490b8 = 0;
  *(undefined2 *)PTR_DAT_030490bc = 100;
  *(undefined2 *)p_text_entry_current_char = 0x48;
  *(undefined2 *)PTR_DAT_030490c4 = 0x48;
  time_hms_display();
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: date_display_refresh_and_char_picker_offset_inc @ 03048bfa (file base 0x03000000; code starts at 0x03001000)
 * Size: 6 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void date_display_refresh_and_char_picker_offset_inc(void)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  
  date_ymd_display();
  if (1 < (byte)(*(char *)PTR_DAT_03048ee0 - 1U)) {
    return;
  }
  bVar2 = *(char *)PTR_DAT_03048ee4 + 1;
  uVar3 = (ushort)bVar2;
  *(byte *)PTR_DAT_03048ee4 = bVar2;
  if (bVar2 < 6) {
    if (5 < bVar2) {
      return;
    }
    uVar1 = 1 << ((int)(char)bVar2 & 0x3fU);
    if ((uVar1 & 0x30) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0x18 + (ushort)bVar2 * 0xc
      ;
      return;
    }
    if ((uVar1 & 0xc) != 0) {
      *(ushort *)p_text_entry_current_char = *(short *)PTR_DAT_03048ee8 + 0xc + (ushort)bVar2 * 0xc;
      return;
    }
    if ((uVar1 & 3) == 0) {
      return;
    }
  }
  else {
    *(undefined1 *)PTR_DAT_03048ee4 = 0;
    uVar3 = 0;
  }
  *(ushort *)p_text_entry_current_char = uVar3 * 0xc + *(short *)PTR_DAT_03048ee8;
  return;
}


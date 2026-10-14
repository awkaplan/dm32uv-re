/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_list_window_clamp_to_8 @ 030418a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 206 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_list_window_clamp_to_8(void)

{
  char cVar1;
  byte bVar2;
  undefined1 *puVar3;
  short sVar4;
  uint uVar5;
  
  bVar2 = p_vfo_display_state->flags_0x8 >> 4;
  if (*(char *)PTR_DAT_03041a10 == '\x01') {
    *(undefined2 *)PTR_DAT_03041a14 = 0;
    *(undefined2 *)PTR_DAT_03041a18 = 1;
  }
  puVar3 = PTR_DAT_03041a1c;
  if (bVar2 < 2) {
    *(undefined1 *)p_active_screen_option_count = PTR_DAT_03041a1c[4];
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar3;
    *(undefined1 *)PTR_active_screen_subtype_03041a28 = puVar3[5];
    cVar1 = *(char *)PTR_DAT_03041a2c;
    if (cVar1 != '\0') {
      *(undefined1 *)PTR_DAT_03041a2c = 0;
      sVar4 = *(short *)PTR_DAT_03041a30;
      *(short *)PTR_DAT_03041a14 = sVar4;
      *(short *)PTR_DAT_03041a18 = sVar4 + 1;
    }
    uVar5 = contact_count_range_calc();
    sVar4 = (short)uVar5;
    *(short *)PTR_DAT_03041a34 = sVar4;
    if (uVar5 < 2) {
      *(undefined2 *)p_active_screen_index_list = 0;
    }
    else {
      *(undefined2 *)p_active_screen_index_list = 2;
    }
    if (*(ushort *)PTR_DAT_03041a14 < uVar5) {
      uVar5 = *(ushort *)PTR_DAT_03041a14 + 1;
      *(short *)PTR_DAT_03041a18 = (short)uVar5;
      if (8 < (uVar5 & 0xffff)) {
        *(undefined2 *)PTR_DAT_03041a18 = 8;
      }
    }
    else if (uVar5 == 0) {
      *(undefined2 *)PTR_DAT_03041a14 = 0;
      *(undefined2 *)PTR_DAT_03041a18 = 1;
    }
    else {
      *(short *)PTR_DAT_03041a14 = sVar4 + -1;
      *(short *)PTR_DAT_03041a18 = sVar4;
      if (8 < uVar5) {
        *(undefined2 *)PTR_DAT_03041a18 = 8;
      }
    }
    if (*(char *)PTR_DAT_03041a10 == '\x01') {
      set_flag_byte_03064328_variant_0303501c(cVar1 != '\0' || bVar2 != 0);
    }
  }
  return;
}


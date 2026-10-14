/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_group_range_select_and_clamp @ 0304332c (file base 0x03000000; code starts at 0x03001000)
 * Size: 182 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_group_range_select_and_clamp(void)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  short sVar4;
  int iVar5;
  
  bVar1 = p_vfo_display_state->flags_0x8;
  if (*(char *)PTR_DAT_030434cc == '\x01') {
    *(undefined2 *)PTR_DAT_030434d0 = 0;
    *(undefined2 *)PTR_DAT_030434d4 = 1;
  }
  puVar3 = PTR_DAT_030434d8;
  *(undefined1 *)p_active_screen_option_count = PTR_DAT_030434d8[4];
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar3;
  *(undefined1 *)PTR_active_screen_subtype_030434e4 = puVar3[5];
  cVar2 = *(char *)PTR_DAT_030434e8;
  if (cVar2 != '\0') {
    *(undefined1 *)PTR_DAT_030434e8 = 0;
    sVar4 = *(short *)PTR_DAT_030434ec;
    *(short *)PTR_DAT_030434d0 = sVar4;
    *(short *)PTR_DAT_030434d4 = sVar4 + 1;
  }
  iVar5 = contact_count_range_calc();
  *(short *)PTR_DAT_030434f0 = (short)(iVar5 + 1U);
  sVar4 = flash_block_u16_scan_find_index_030349e4
                    (*(undefined2 *)&p_vfo_display_state->field_0x31_0,iVar5);
  *(short *)PTR_DAT_030434d0 = sVar4;
  if ((iVar5 + 1U & 0xffff) < 2) {
    *(undefined2 *)p_active_screen_index_list = 0;
  }
  else {
    *(undefined2 *)p_active_screen_index_list = 2;
  }
  *(ushort *)PTR_DAT_030434d4 = sVar4 + 1U;
  if (8 < (ushort)(sVar4 + 1U)) {
    *(undefined2 *)PTR_DAT_030434d4 = 8;
  }
  if (*(char *)PTR_DAT_030434cc == '\x01') {
    set_flag_byte_03064328_variant_0303501c(cVar2 != '\0' || bVar1 >> 4 != 0);
  }
  return;
}


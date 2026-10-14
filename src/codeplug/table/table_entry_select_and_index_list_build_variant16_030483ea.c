/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_select_and_index_list_build_variant16 @ 030483ea (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_entry_select_and_index_list_build_variant16(void)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bVar3;
  
  puVar1 = PTR_PTR_030484c4;
  uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar3 = *(byte *)(PTR_PTR_030484c4 + uVar2 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar3;
  *p_active_screen_option_ptr_array = puVar1[uVar2 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03048498 = *(undefined1 *)((int)puVar1 + uVar2 * 8 + 5);
  build_sequential_index_list
            ((ushort)bVar3,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  bVar3 = PTR_DAT_030484a0[0xc] & 1;
  *(byte *)p_active_screen_state_word = bVar3;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar3 + 1;
  *(undefined1 *)PTR_DAT_030484b8 = 2;
  *(byte *)p_menu_selected_item_index = bVar3;
  return;
}


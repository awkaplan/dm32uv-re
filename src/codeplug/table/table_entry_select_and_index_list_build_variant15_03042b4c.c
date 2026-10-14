/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_select_and_index_list_build_variant15 @ 03042b4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 164 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_entry_select_and_index_list_build_variant15(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  byte bVar5;
  
  puVar3 = PTR_PTR_03042c28;
  puVar2 = PTR_PTR_03042c14;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03042c0c + 2);
  if (cVar1 == '\0') {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar5 = *(byte *)(PTR_PTR_03042c14 + uVar4 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar5;
    *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03042c20 = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5)
    ;
    build_sequential_index_list
              ((ushort)bVar5,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  else if (cVar1 == '\x01') {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar5 = *(byte *)(PTR_PTR_03042c28 + uVar4 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar5;
    *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03042c20 = *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5)
    ;
    build_sequential_index_list
              ((ushort)bVar5,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    bVar5 = *(byte *)PTR_DAT_03042c2c >> 1 & 1;
    *(byte *)p_active_screen_state_word = bVar5;
    *(byte *)p_active_screen_flag_0003e5d5 = bVar5 + 1;
    *(undefined1 *)PTR_DAT_03042c38 = 2;
    *(byte *)p_menu_selected_item_index = bVar5;
  }
  return;
}


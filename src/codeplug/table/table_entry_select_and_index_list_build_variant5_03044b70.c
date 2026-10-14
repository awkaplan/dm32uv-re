/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_select_and_index_list_build_variant5 @ 03044b70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_entry_select_and_index_list_build_variant5(void)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = PTR_PTR_03044c94;
  puVar3 = p_dm32_settings_block04;
  uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar1 = *(byte *)(PTR_PTR_03044c94 + uVar5 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = puVar4[uVar5 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03044ca0 = *(undefined1 *)((int)puVar4 + uVar5 * 8 + 5);
  build_sequential_index_list
            ((ushort)bVar1,(ushort *)p_active_screen_index_list,
             (byte *)((int)p_active_screen_index_list + 2));
  cVar2 = puVar3[0x6b];
  *(char *)p_active_screen_state_word = cVar2;
  *(char *)p_menu_selected_item_index = cVar2;
  *(undefined1 *)PTR_DAT_03044cac = 2;
  *(char *)p_active_screen_flag_0003e5d5 = cVar2 + '\x01';
  return;
}


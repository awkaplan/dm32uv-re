/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_bool_option_init_03044d82 @ 03044d82 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_bool_option_init_03044d82(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte bVar4;
  
  puVar2 = PTR_PTR_03044eac;
  puVar1 = p_dm32_settings_block04;
  uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar4 = *(byte *)(PTR_PTR_03044eac + uVar3 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar4;
  *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03044e8c = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5);
  build_sequential_index_list
            ((ushort)bVar4,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  bVar4 = (byte)puVar1[0x6d] >> 2 & 1;
  *(byte *)p_active_screen_state_word = bVar4;
  *(undefined1 *)PTR_DAT_03044ea8 = 2;
  *(byte *)p_menu_selected_item_index = bVar4;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar4 + 1;
  return;
}


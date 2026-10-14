/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_direction_normal_reverse_option_init @ 0304478c (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_direction_normal_reverse_option_init(void)

{
  undefined4 *puVar1;
  uint uVar2;
  byte bVar3;
  
  puVar1 = PTR_PTR_030448fc;
  uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar3 = *(byte *)(PTR_PTR_030448fc + uVar2 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar3;
  *p_active_screen_option_ptr_array = puVar1[uVar2 * 2];
  *(undefined1 *)PTR_active_screen_subtype_030448e0 = *(undefined1 *)((int)puVar1 + uVar2 * 8 + 5);
  if (*(char *)PTR_DAT_030448e4 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar3,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  bVar3 = p_dm32_settings_block04[0x6d] & 1;
  *(byte *)p_active_screen_state_word = bVar3;
  *(byte *)p_menu_selected_item_index = bVar3;
  *(undefined1 *)PTR_DAT_030448f0 = 2;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar3 + 1;
  return;
}


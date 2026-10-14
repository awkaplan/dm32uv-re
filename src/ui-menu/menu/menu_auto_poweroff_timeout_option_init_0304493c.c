/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_auto_poweroff_timeout_option_init @ 0304493c (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_auto_poweroff_timeout_option_init(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_03044ac0;
  uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar1 = *(byte *)(PTR_PTR_03044ac0 + uVar4 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03044acc = *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5);
  if (*(char *)PTR_DAT_03044ad0 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  cVar2 = p_dm32_settings_block04[0x6e];
  *(char *)p_active_screen_state_word = cVar2;
  *(undefined1 *)PTR_DAT_03044adc = 2;
  *(char *)p_menu_selected_item_index = cVar2;
  *(char *)p_active_screen_flag_0003e5d5 = cVar2 + '\x01';
  return;
}


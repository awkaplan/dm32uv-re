/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_0x22_from_settings_block @ 03044b1e (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_init_0x22_from_settings_block(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_03044c94;
  puVar2 = p_dm32_settings_block04;
  uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03044c94 + uVar4 * 2 + 1);
  *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03044ca0 = *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5);
  menu_option_list_dispatch
            (0x22,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
  cVar1 = puVar2[0x6a];
  *(char *)p_active_screen_state_word = cVar1;
  *(char *)p_menu_selected_item_index = cVar1;
  *(undefined1 *)PTR_DAT_03044cac = 2;
  *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_bool_option_init_03041fd8 @ 03041fd8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_bool_option_init_03041fd8(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = PTR_PTR_03042160;
  uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar1 = *(byte *)(PTR_PTR_03042160 + uVar4 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
  *(undefined1 *)PTR_active_screen_subtype_0304216c = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5);
  build_sequential_index_list
            ((ushort)bVar1,(ushort *)p_active_screen_index_list,
             (byte *)((int)p_active_screen_index_list + 2));
  *(undefined1 *)PTR_DAT_03042174 = 2;
  iVar3 = get_current_mode_state1();
  if (iVar3 == 0) {
    *(undefined1 *)p_active_screen_state_word = 1;
    *(undefined1 *)p_menu_selected_item_index = 1;
  }
  else {
    *(undefined1 *)p_active_screen_state_word = 0;
    *(undefined1 *)p_menu_selected_item_index = 0;
  }
  *(char *)p_active_screen_flag_0003e5d5 = *(char *)p_active_screen_state_word + '\x01';
  return;
}


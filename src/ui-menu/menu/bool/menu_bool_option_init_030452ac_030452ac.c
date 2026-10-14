/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_bool_option_init_030452ac @ 030452ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 208 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_bool_option_init_030452ac(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint uVar5;
  
  puVar3 = p_active_screen_state_word;
  puVar2 = PTR_PTR_0304541c;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03045414 + 2);
  if (cVar1 == '\0') {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar4 = *(byte *)(PTR_PTR_0304541c + uVar5 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar4;
    *p_active_screen_option_ptr_array = puVar2[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03045428 = *(undefined1 *)((int)puVar2 + uVar5 * 8 + 5)
    ;
    build_sequential_index_list
              ((ushort)bVar4,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
    if (((p_vfo_display_state->field_0xf & 0x40) == 0) || (p_vfo_display_state->field_0xe == 0)) {
      *(undefined1 *)p_active_screen_state_word = 1;
    }
    else {
      *(undefined1 *)p_active_screen_state_word = 0;
    }
    *(undefined1 *)PTR_DAT_03045438 = 2;
    cVar1 = *(char *)p_active_screen_state_word;
    *(char *)p_menu_selected_item_index = cVar1;
    *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
  }
  else if (cVar1 == '\x01') {
    *(byte *)p_active_screen_state_word = p_vfo_display_state->field_0xe;
    *(undefined1 *)PTR_active_screen_subtype_03045428 = 0x2e;
    bVar4 = flash_block_count_records_until_null();
    *(byte *)PTR_DAT_03045444 = bVar4;
    *(ushort *)p_active_screen_index_list = bVar4 + 1;
    if (0x10 < *(byte *)puVar3) {
      *(undefined1 *)puVar3 = 0;
    }
    *(undefined1 *)PTR_DAT_03045438 = 2;
    cVar1 = *(char *)p_active_screen_state_word;
    *(char *)p_menu_selected_item_index = cVar1;
    bVar4 = cVar1 + 1;
    *(byte *)p_active_screen_flag_0003e5d5 = bVar4;
    if (8 < bVar4) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
    }
  }
  return;
}


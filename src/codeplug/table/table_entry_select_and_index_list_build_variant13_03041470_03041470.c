/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_select_and_index_list_build_variant13_03041470 @ 03041470 (file base 0x03000000; code starts at 0x03001000)
 * Size: 228 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_entry_select_and_index_list_build_variant13_03041470(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = PTR_PTR_03041594;
  puVar3 = PTR_PTR_0304156c;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03041564 + 2);
  if (cVar1 == '\0') {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar2 = *(byte *)(PTR_PTR_0304156c + uVar5 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar2;
    *p_active_screen_option_ptr_array = puVar3[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03041578 = *(undefined1 *)((int)puVar3 + uVar5 * 8 + 5)
    ;
    build_sequential_index_list
              ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    if ((*(byte *)PTR_DAT_03041580 & 1) == 0) {
      *(undefined1 *)p_active_screen_state_word = 1;
    }
    else {
      *(undefined1 *)p_active_screen_state_word = 0;
    }
    cVar1 = *(char *)p_active_screen_state_word;
    *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
    *(undefined1 *)PTR_DAT_0304158c = 2;
    *(char *)p_menu_selected_item_index = cVar1;
  }
  else if (cVar1 == '\x01') {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar2 = *(byte *)(PTR_PTR_03041594 + uVar5 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar2;
    *p_active_screen_option_ptr_array = puVar4[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03041578 = *(undefined1 *)((int)puVar4 + uVar5 * 8 + 5)
    ;
    build_sequential_index_list
              ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    if ((*(byte *)PTR_DAT_03041580 & 0x3c) == 0) {
      *(undefined1 *)p_active_screen_state_word = 0;
    }
    else {
      *(undefined1 *)p_active_screen_state_word = 1;
    }
    cVar1 = *(char *)p_active_screen_state_word;
    *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
    *(undefined1 *)PTR_DAT_0304158c = 2;
    *(char *)p_menu_selected_item_index = cVar1;
  }
  return;
}


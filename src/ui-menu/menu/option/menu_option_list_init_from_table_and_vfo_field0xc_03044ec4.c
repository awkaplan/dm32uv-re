/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_from_table_and_vfo_field0xc @ 03044ec4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_init_from_table_and_vfo_field0xc(void)

{
  byte bVar1;
  undefined4 *puVar2;
  
  puVar2 = PTR_PTR_0304502c;
  bVar1 = *(byte *)(PTR_PTR_0304502c + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = *puVar2;
  *(undefined1 *)PTR_active_screen_subtype_03045038 = *(undefined1 *)((int)puVar2 + 5);
  if (*(char *)PTR_DAT_0304503c == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  bVar1 = p_vfo_display_state->field_0xc >> 4;
  *(byte *)p_active_screen_state_word = bVar1;
  *(byte *)p_menu_selected_item_index = bVar1;
  *(undefined1 *)PTR_DAT_03045050 = 2;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar1 + 1;
  if (8 < (byte)(bVar1 + 1)) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_from_table_and_vfo_state @ 030474ea (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_init_from_table_and_vfo_state(void)

{
  undefined4 *puVar1;
  byte bVar2;
  
  puVar1 = PTR_PTR_03047590;
  bVar2 = *(byte *)(PTR_PTR_03047590 + 1);
  *(byte *)p_active_screen_option_count = bVar2;
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_0304754c = *(undefined1 *)((int)puVar1 + 5);
  if (*(char *)PTR_DAT_03047550 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  bVar2 = p_vfo_display_state->flags_0xd & 0xf;
  *(byte *)p_active_screen_state_word = bVar2;
  *(byte *)p_menu_selected_item_index = bVar2;
  *(undefined1 *)PTR_DAT_0304757c = 2;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar2 + 1;
  if (8 < (byte)(bVar2 + 1)) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}


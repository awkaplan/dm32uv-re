/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_descriptor_init_from_vfo_field_0x19 @ 03044bc4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 90 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_descriptor_init_from_vfo_field_0x19(void)

{
  byte bVar1;
  undefined4 *puVar2;
  
  puVar2 = PTR_PTR_03044cb0;
  bVar1 = *(byte *)(PTR_PTR_03044cb0 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *(undefined1 *)PTR_active_screen_subtype_03044ca0 = *(undefined1 *)((int)puVar2 + 5);
  *p_active_screen_option_ptr_array = *puVar2;
  if (*(char *)PTR_DAT_03044cb4 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
  }
  bVar1 = p_vfo_display_state->field_0x19 >> 4;
  *(byte *)p_active_screen_state_word = bVar1;
  *(byte *)p_menu_selected_item_index = bVar1;
  *(undefined1 *)PTR_DAT_03044cac = 2;
  if (*(ushort *)p_active_screen_index_list <= (ushort)bVar1) {
    *(undefined1 *)p_active_screen_state_word = 0;
  }
  *(char *)p_active_screen_flag_0003e5d5 = *(char *)p_active_screen_state_word + '\x01';
  return;
}


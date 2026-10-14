/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_entry_toggle_and_related_display_refresh @ 03043dfa (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_entry_toggle_and_related_display_refresh(void)

{
  byte bVar1;
  menu_screen_state *pmVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  *(undefined1 *)PTR_DAT_03043f00 = 3;
  puVar3 = PTR_PTR_03043f0c;
  bVar1 = *(byte *)(PTR_PTR_03043f0c + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = *puVar3;
  *(undefined1 *)PTR_active_screen_subtype_03043efc = *(undefined1 *)((int)puVar3 + 5);
  *(ushort *)p_active_screen_index_list = (ushort)bVar1;
  pmVar2 = p_menu_screen_state;
  list_record_lookup_and_toggle_by_index(3,p_menu_screen_state->index_0x4 + 1);
  uVar4 = channel_number_decode_from_menu_index(3,pmVar2->index_0x4 + 1,DAT_03043f04);
  *PTR_DAT_03043f08 = uVar4;
  active_screen_option_list_reindex_and_clear();
  return;
}


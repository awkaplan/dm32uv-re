/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_entry_toggle_and_related_lookup_gated @ 03043da0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_entry_toggle_and_related_lookup_gated(void)

{
  menu_screen_state *pmVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = PTR_PTR_03043ef0;
  if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03043eec + 2) == '\0') {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043ef0 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03043efc = *(undefined1 *)((int)puVar2 + 5);
    *(undefined1 *)PTR_DAT_03043f00 = 1;
    pmVar1 = p_menu_screen_state;
    list_record_lookup_and_toggle_by_index(1,p_menu_screen_state->index_0x4 + 1);
    uVar3 = channel_number_decode_from_menu_index(1,pmVar1->index_0x4 + 1,DAT_03043f04);
    *PTR_DAT_03043f08 = uVar3;
    active_screen_option_list_reindex_and_clear();
  }
  return;
}


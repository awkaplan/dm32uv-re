/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_state_dispatch_by_submode @ 03045d70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_state_dispatch_by_submode(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_03045e24;
  bVar1 = *(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03045e20 + 2);
  if (bVar1 == 2) {
    menu_contact_pick_method_option_init_03045cd8();
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_03045e24 + uVar4 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
      *(undefined1 *)PTR_active_screen_subtype_03045df8 =
           *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5);
      puVar3 = p_active_screen_index_list;
      if (*(char *)PTR_DAT_03045e08 == '\x01') {
        uVar2 = *(ushort *)p_active_screen_index_list;
        *(undefined1 *)((int)p_active_screen_index_list + uVar2 + 2) = 0;
        uVar4 = uVar2 + 1 & 0xffff;
        *(undefined1 *)((int)puVar3 + uVar4 + 2) = 1;
        uVar4 = uVar4 + 1;
        *(undefined1 *)((int)puVar3 + (uVar4 & 0xffff) + 2) = 3;
        *(short *)puVar3 = (short)uVar4 + 1;
      }
    }
  }
  else if (bVar1 == 3) {
    table_entry_select_and_index_list_build_variant_03045c94();
  }
  else if (bVar1 == 4) {
    table_entry_select_and_index_list_build_variant3();
  }
  return;
}


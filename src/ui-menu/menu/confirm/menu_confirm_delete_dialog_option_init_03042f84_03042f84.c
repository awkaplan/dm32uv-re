/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_delete_dialog_option_init_03042f84 @ 03042f84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 290 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_confirm_delete_dialog_option_init_03042f84(void)

{
  char cVar1;
  byte bVar2;
  menu_screen_state *pmVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  pmVar3 = p_menu_screen_state;
  contact_name_lookup_by_offset_walk
            (p_menu_screen_state->index_0x2 + 1,p_menu_screen_state->index_0x3 + 1,DAT_030430fc);
  puVar7 = PTR_PTR_03043128;
  puVar6 = PTR_PTR_03043124;
  puVar5 = PTR_PTR_03043120;
  puVar4 = PTR_PTR_03043108;
  cVar1 = *(char *)((uint)pmVar3->index_0x2 + DAT_03043100 + 2);
  if (cVar1 == '\x01') {
    uVar8 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar2 = *(byte *)(PTR_PTR_03043120 + uVar8 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar2;
    *p_active_screen_option_ptr_array = puVar5[uVar8 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043114 = *(undefined1 *)((int)puVar5 + uVar8 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03043118 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    }
  }
  else if (cVar1 == '\0') {
    uVar8 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar2 = *(byte *)(PTR_PTR_03043108 + uVar8 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar2;
    *p_active_screen_option_ptr_array = puVar4[uVar8 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043114 = *(undefined1 *)((int)puVar4 + uVar8 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03043118 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    }
  }
  else if (cVar1 == '\x02') {
    uVar8 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar2 = *(byte *)(PTR_PTR_03043124 + uVar8 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar2;
    *p_active_screen_option_ptr_array = puVar6[uVar8 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043114 = *(undefined1 *)((int)puVar6 + uVar8 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03043118 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    }
  }
  else if (cVar1 == '\x03') {
    uVar8 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043128 + uVar8 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar7[uVar8 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03043114 = *(undefined1 *)((int)puVar7 + uVar8 * 8 + 5)
    ;
  }
  return;
}


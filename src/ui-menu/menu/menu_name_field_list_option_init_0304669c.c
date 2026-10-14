/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_name_field_list_option_init @ 0304669c (file base 0x03000000; code starts at 0x03001000)
 * Size: 198 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_name_field_list_option_init(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_030467ac;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_030467a4 + 2);
  if (cVar1 == '\0') {
    if (*(char *)((uint)p_menu_screen_state->index_0x6 + DAT_030467a8 + 2) == '\x01') {
      radio_shutdown_confirm_screen();
    }
  }
  else if (cVar1 == '\x03') {
    if (*(char *)((uint)p_menu_screen_state->index_0x6 + DAT_030467a8 + 2) == '\0') {
      uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      bVar2 = *(byte *)(PTR_PTR_030467ac + uVar4 * 2 + 1);
      *(byte *)p_active_screen_option_count = bVar2;
      *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
      *(undefined1 *)PTR_active_screen_subtype_03046768 =
           *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5);
      if (*(char *)PTR_DAT_0304676c == '\x01') {
        build_sequential_index_list
                  ((ushort)bVar2,(ushort *)p_active_screen_index_list,
                   (byte *)((int)p_active_screen_index_list + 2));
      }
    }
    else {
      if (*(char *)PTR_DAT_0304676c == '\x01') {
        menu_option_list_dispatch
                  (1,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
      }
      puVar3 = PTR_PTR_030467b0;
      if (*(short *)p_active_screen_index_list == 0) {
        history_queue_pop();
      }
      else {
        uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
        *(undefined1 *)p_active_screen_option_count =
             *(undefined1 *)(PTR_PTR_030467b0 + uVar4 * 2 + 1);
        *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
        *(undefined1 *)PTR_active_screen_subtype_03046768 =
             *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5);
      }
    }
  }
  return;
}


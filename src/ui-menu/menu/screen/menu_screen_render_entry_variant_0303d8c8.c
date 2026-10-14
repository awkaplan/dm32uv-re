/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_render_entry_variant @ 0303d8c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 334 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_screen_render_entry_variant(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  
  dialog_history_flush_and_reset();
  PTR_DAT_0303da10[0xa0a] = 1;
  if ((*(byte *)PTR_DAT_0303da14 & 2) == 0) {
    uVar7 = (uint)*(byte *)((uint)(byte)PTR_g_menu_screen_state_0303da1c[1] + DAT_0303da44 + 2);
    if (uVar7 < 10) {
                    /* WARNING: Could not recover jumptable at 0x0303da0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0303da48[uVar7] & 0xfffffffe))();
      return;
    }
  }
  else {
    display_fill_rect(0,0,0xf0,0x1b,0);
    puVar4 = PTR_g_menu_screen_state_0303da1c;
    puVar3 = PTR_active_screen_index_list_0303da18;
    display_draw_number_centered
              (2,0xffff,0,
               *(uint *)(*PTR_PTR_0303da20 +
                        (uint)*(byte *)((int)PTR_active_screen_index_list_0303da18 +
                                       (byte)PTR_g_menu_screen_state_0303da1c[1] + 0x49) * 4));
    puVar6 = PTR_PTR_0303da40;
    puVar5 = PTR_PTR_0303da3c;
    cVar2 = *(char *)((int)puVar3 + (byte)puVar4[1] + 0x49);
    if (cVar2 == '\x01') {
      if (PTR_DAT_0303da10[4] == '\x01') {
        menu_option_list_dispatch
                  (0x26,PTR_active_screen_index_list_0303da18,
                   (void *)((int)PTR_active_screen_index_list_0303da18 + 2));
      }
      puVar3 = PTR_PTR_0303da38;
      if (*(short *)PTR_active_screen_index_list_0303da18 == 0) {
        history_queue_pop();
      }
      else {
        *(undefined1 *)PTR_active_screen_option_count_0303da28 =
             *(undefined1 *)(PTR_PTR_0303da38 + 1);
        uVar8 = *puVar3;
        *PTR_active_screen_option_ptr_array_0303da2c = uVar8;
        *PTR_DAT_0303da30 = uVar8;
        *(undefined1 *)PTR_active_screen_subtype_0303da34 = *(undefined1 *)((int)puVar3 + 5);
      }
    }
    else if (cVar2 == '\0') {
      if (PTR_DAT_0303da10[4] == '\x01') {
        menu_option_list_dispatch
                  (0x24,PTR_active_screen_index_list_0303da18,
                   (void *)((int)PTR_active_screen_index_list_0303da18 + 2));
      }
      puVar3 = PTR_PTR_0303da24;
      if (*(short *)PTR_active_screen_index_list_0303da18 == 0) {
        history_queue_pop();
      }
      else {
        *(undefined1 *)PTR_active_screen_option_count_0303da28 =
             *(undefined1 *)(PTR_PTR_0303da24 + 1);
        uVar8 = *puVar3;
        *PTR_active_screen_option_ptr_array_0303da2c = uVar8;
        *PTR_DAT_0303da30 = uVar8;
        *(undefined1 *)PTR_active_screen_subtype_0303da34 = *(undefined1 *)((int)puVar3 + 5);
      }
    }
    else if (cVar2 == '\x02') {
      bVar1 = *(byte *)(PTR_PTR_0303da3c + 1);
      *(byte *)PTR_active_screen_option_count_0303da28 = bVar1;
      *(undefined1 *)PTR_active_screen_subtype_0303da34 = *(undefined1 *)((int)puVar5 + 5);
      uVar8 = *puVar5;
      *PTR_active_screen_option_ptr_array_0303da2c = uVar8;
      *PTR_DAT_0303da30 = uVar8;
      build_sequential_index_list
                ((ushort)bVar1,(ushort *)PTR_active_screen_index_list_0303da18,
                 (byte *)((int)PTR_active_screen_index_list_0303da18 + 2));
    }
    else if (cVar2 == '\x03') {
      *(undefined1 *)PTR_active_screen_option_count_0303da28 = *(undefined1 *)(PTR_PTR_0303da40 + 1)
      ;
      *(undefined1 *)PTR_active_screen_subtype_0303da34 = *(undefined1 *)((int)puVar6 + 5);
      uVar8 = *puVar6;
      *PTR_active_screen_option_ptr_array_0303da2c = uVar8;
      *PTR_DAT_0303da30 = uVar8;
      menu_option_list_dispatch
                (0x29,PTR_active_screen_index_list_0303da18,
                 (void *)((int)PTR_active_screen_index_list_0303da18 + 2));
    }
  }
  main_menu_screen_dispatch();
  return;
}


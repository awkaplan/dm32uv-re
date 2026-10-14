/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_menu_screen_render_entry @ 0303cbc4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 414 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void main_menu_screen_render_entry(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  
  dialog_history_flush_and_reset();
  if ((*(byte *)PTR_DAT_0303cd3c & 2) == 0) {
    PTR_DAT_0303cd9c[0xa0a] = 1;
    uVar5 = (uint)*(byte *)((uint)(byte)PTR_g_menu_screen_state_0303cda0[1] + DAT_0303cda4 + 2);
    if (uVar5 < 10) {
                    /* WARNING: Could not recover jumptable at 0x0303cd98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0303cda8[uVar5] & 0xfffffffe))();
      return;
    }
  }
  else {
    display_fill_rect(0,0,0xf0,0x1b,0);
    puVar3 = PTR_active_screen_index_list_0303cd48;
    puVar2 = PTR_g_menu_screen_state_0303cd40;
    cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303cd40[2] + DAT_0303cd44 + 2);
    if (cVar1 == '\x01') {
      display_draw_number_centered
                (2,0xffff,0,
                 *(uint *)(*PTR_PTR_0303cd4c +
                          (uint)*(byte *)((int)PTR_active_screen_index_list_0303cd48 +
                                         (byte)PTR_g_menu_screen_state_0303cd40[3] + 0x8f) * 4));
      cVar1 = *(char *)((int)puVar3 + (byte)puVar2[3] + 0x8f);
      if (cVar1 == '\0') {
        PTR_DAT_0303cd50[3] = PTR_DAT_0303cd50[3] & 0xe7 | 0x18;
      }
      else if (cVar1 == '\x01') {
        PTR_DAT_0303cd50[3] = PTR_DAT_0303cd50[3] & 0xe7;
      }
      if (PTR_DAT_0303cd54[4] == '\x01') {
        menu_option_list_dispatch
                  (0x2b,PTR_active_screen_index_list_0303cd48,
                   (void *)((int)PTR_active_screen_index_list_0303cd48 + 2));
      }
      puVar3 = PTR_PTR_0303cd58;
      if (*(short *)PTR_active_screen_index_list_0303cd48 == 0) {
        history_queue_pop();
      }
      else {
        *(undefined1 *)PTR_active_screen_option_count_0303cd5c =
             *(undefined1 *)(PTR_PTR_0303cd58 + 1);
        uVar4 = *puVar3;
        *PTR_active_screen_option_ptr_array_0303cd60 = uVar4;
        *PTR_DAT_0303cd64 = uVar4;
        *(undefined1 *)PTR_active_screen_subtype_0303cd68 = *(undefined1 *)((int)puVar3 + 5);
      }
    }
    else if (cVar1 == '\x02') {
      display_draw_number_centered
                (0,0xffff,0,
                 *(uint *)(*PTR_PTR_0303cd6c +
                          (uint)*(byte *)((int)PTR_active_screen_index_list_0303cd48 +
                                         (byte)PTR_g_menu_screen_state_0303cd40[3] + 0x8f) * 4));
      cVar1 = *(char *)((int)puVar3 + (byte)puVar2[3] + 0x8f);
      if (cVar1 == '\0') {
        PTR_DAT_0303cd50[3] = PTR_DAT_0303cd50[3] & 0xe7 | 0x18;
      }
      else if (cVar1 == '\x01') {
        PTR_DAT_0303cd50[3] = PTR_DAT_0303cd50[3] & 0xe7;
      }
      if (PTR_DAT_0303cd54[4] == '\x01') {
        menu_option_list_dispatch
                  (0x2d,PTR_active_screen_index_list_0303cd48,
                   (void *)((int)PTR_active_screen_index_list_0303cd48 + 2));
      }
      puVar3 = PTR_PTR_0303cd70;
      if (*(short *)PTR_active_screen_index_list_0303cd48 == 0) {
        history_queue_pop();
      }
      else {
        *(undefined1 *)PTR_active_screen_option_count_0303cd5c =
             *(undefined1 *)(PTR_PTR_0303cd70 + 1);
        uVar4 = *puVar3;
        *PTR_active_screen_option_ptr_array_0303cd60 = uVar4;
        *PTR_DAT_0303cd64 = uVar4;
        *(undefined1 *)PTR_active_screen_subtype_0303cd68 = *(undefined1 *)((int)puVar3 + 5);
      }
    }
    else if (cVar1 == '\x04') {
      display_draw_number_centered
                (0,0xffff,0,
                 *(uint *)(*PTR_PTR_0303cd78 +
                          (uint)*(byte *)((uint)(byte)PTR_g_menu_screen_state_0303cd40[3] +
                                          DAT_0303cd74 + 2) * 4));
    }
  }
  main_menu_screen_dispatch();
  return;
}


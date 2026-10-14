/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: main_menu_render_and_field_edit_dispatch @ 0303cdf0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 254 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void main_menu_render_and_field_edit_dispatch(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  
  dialog_history_flush_and_reset();
  if ((*(byte *)PTR_DAT_0303cee8 & 2) == 0) {
    PTR_DAT_0303cf00[0xa0a] = 1;
    uVar5 = (uint)*(byte *)((uint)(byte)PTR_g_menu_screen_state_0303ceec[1] + DAT_0303cef0 + 2);
    if (uVar5 < 10) {
                    /* WARNING: Could not recover jumptable at 0x0303cee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0303cf18[uVar5] & 0xfffffffe))();
      return;
    }
  }
  else {
    cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303ceec[1] + DAT_0303cef0 + 2);
    if (cVar1 == '\0') {
      display_fill_rect(0,0,0xf0,0x1b,0);
      puVar3 = PTR_active_screen_index_list_0303cef4;
      puVar2 = PTR_g_menu_screen_state_0303ceec;
      display_draw_number_centered
                (2,0xffff,0,
                 *(uint *)(*PTR_PTR_0303cef8 +
                          (uint)*(byte *)((int)PTR_active_screen_index_list_0303cef4 +
                                         (byte)PTR_g_menu_screen_state_0303ceec[2] + 0x6c) * 4));
      cVar1 = *(char *)((int)puVar3 + (byte)puVar2[2] + 0x6c);
      if (cVar1 == '\0') {
        PTR_DAT_0303cefc[3] = PTR_DAT_0303cefc[3] & 0xe7 | 0x18;
      }
      else if (cVar1 == '\x01') {
        PTR_DAT_0303cefc[3] = PTR_DAT_0303cefc[3] & 0xe7;
      }
      if (PTR_DAT_0303cf00[4] == '\x01') {
        menu_option_list_dispatch
                  (0x25,PTR_active_screen_index_list_0303cef4,
                   (void *)((int)PTR_active_screen_index_list_0303cef4 + 2));
      }
      puVar3 = PTR_PTR_0303cf04;
      if (*(short *)PTR_active_screen_index_list_0303cef4 == 0) {
        history_queue_pop();
      }
      else {
        *(undefined1 *)PTR_active_screen_option_count_0303cf08 =
             *(undefined1 *)(PTR_PTR_0303cf04 + 1);
        uVar4 = *puVar3;
        *PTR_active_screen_option_ptr_array_0303cf0c = uVar4;
        *PTR_DAT_0303cf10 = uVar4;
        *(undefined1 *)PTR_active_screen_subtype_0303cf14 = *(undefined1 *)((int)puVar3 + 5);
      }
    }
    else if (cVar1 == '\x01') {
      settings_edit_field_init_or_commit_dispatch();
    }
  }
  main_menu_screen_dispatch();
  return;
}


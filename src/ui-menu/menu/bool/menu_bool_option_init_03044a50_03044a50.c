/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_bool_option_init_03044a50 @ 03044a50 (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_bool_option_init_03044a50(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = p_vfo_display_state->field_0xa;
  iVar3 = poll_condition_group(0x1a);
  puVar2 = PTR_PTR_03044af8;
  if ((iVar3 == 0) || ((bVar1 & 0x80) != 0)) {
    ui_event_notify(0x21);
    history_queue_pop();
  }
  else {
    uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar1 = *(byte *)(PTR_PTR_03044af8 + uVar4 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03044acc = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03044ad0 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    }
    if ((p_vfo_display_state->field_0xa & 8) == 0) {
      *(undefined1 *)p_active_screen_state_word = 1;
    }
    else {
      *(undefined1 *)p_active_screen_state_word = 0;
    }
    *(char *)p_active_screen_flag_0003e5d5 = *(char *)p_active_screen_state_word + '\x01';
  }
  return;
}


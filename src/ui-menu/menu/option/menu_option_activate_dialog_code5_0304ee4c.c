/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_activate_dialog_code5 @ 0304ee4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_activate_dialog_code5(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  short *psVar4;
  uint uVar5;
  
  puVar3 = PTR_PTR_0304efa8;
  puVar2 = PTR_PTR_0304efa4;
  puVar1 = PTR_PTR_0304efa0;
  if ((p_dialog_flags_from_flash->flags_0x1e & 0xf) == 2) {
    if ((p_dialog_flags_from_flash->flags_0x1e & 0x70) == 0x10) {
      uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_0304efa0 + uVar5 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar1[uVar5 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0304ef94 =
           *(undefined1 *)((int)puVar1 + uVar5 * 8 + 5);
    }
    else {
      uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_0304efa4 + uVar5 * 2 + 1);
      *p_active_screen_option_ptr_array = puVar2[uVar5 * 2];
      *(undefined1 *)PTR_active_screen_subtype_0304ef94 =
           *(undefined1 *)((int)puVar2 + uVar5 * 8 + 5);
    }
  }
  else {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_0304efa8 + uVar5 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar3[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0304ef94 = *(undefined1 *)((int)puVar3 + uVar5 * 8 + 5)
    ;
    if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
      dialog_request_enqueue(5,(void *)*PTR_DAT_0304f124);
    }
    else {
      format_and_write_status_field2
                (**(undefined4 **)
                   (PTR_PTR_0304f120 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
  }
  psVar4 = p_active_screen_index_list;
  menu_option_list_dispatch(1,p_active_screen_index_list,p_active_screen_index_list + 1);
  puVar1 = PTR_PTR_0304f12c;
  if (*psVar4 == 0) {
    history_queue_pop();
  }
  else {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_0304f12c + uVar5 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar1[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0304f138 = *(undefined1 *)((int)puVar1 + uVar5 * 8 + 5)
    ;
  }
  write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f13c + DAT_0304f140),0);
  return;
}


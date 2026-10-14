/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_activate_dialog_code4 @ 0304ee1e (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_activate_dialog_code4(void)

{
  undefined4 *puVar1;
  short *psVar2;
  uint uVar3;
  
  puVar1 = PTR_PTR_0304ef98;
  uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_0304ef98 + uVar3 * 2 + 1);
  *p_active_screen_option_ptr_array = puVar1[uVar3 * 2];
  *(undefined1 *)PTR_active_screen_subtype_0304ef94 = *(undefined1 *)((int)puVar1 + uVar3 * 8 + 5);
  if ((p_vfo_display_state->flags_0x8 & 8) == 0) {
    dialog_request_enqueue(4,(void *)*PTR_DAT_0304f124);
  }
  else {
    format_and_write_status_field2
              (**(undefined4 **)
                 (PTR_PTR_0304f120 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  psVar2 = p_active_screen_index_list;
  menu_option_list_dispatch(1,p_active_screen_index_list,p_active_screen_index_list + 1);
  puVar1 = PTR_PTR_0304f12c;
  if (*psVar2 == 0) {
    history_queue_pop();
  }
  else {
    uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_0304f12c + uVar3 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar1[uVar3 * 2];
    *(undefined1 *)PTR_active_screen_subtype_0304f138 = *(undefined1 *)((int)puVar1 + uVar3 * 8 + 5)
    ;
  }
  write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f13c + DAT_0304f140),0);
  return;
}


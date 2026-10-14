/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_state_action_dispatch_by_index @ 03036420 (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_state_action_dispatch_by_index(void)

{
  char cVar1;
  
  cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_030364a8[1] + DAT_030364ac + 2);
  if (cVar1 == '\0') {
    contact_history_pop_or_scan_action_dispatch();
  }
  else if (cVar1 == '\x01') {
    state_dispatcher_menu_char_0x01_0x02();
  }
  else if (cVar1 == '\x02') {
    contact_list_delete_entry_and_compact_wrapper();
  }
  else if (cVar1 == '\x03') {
    menu_refresh_mode_dispatch();
  }
  else if (cVar1 == '\x04') {
    menu_item_status_refresh_dispatch();
  }
  else if (cVar1 == '\x05') {
    settings_menu_confirm_dispatch();
  }
  else if (cVar1 == '\x06') {
    status_mode_write_from_indexed_field_c();
  }
  else if (cVar1 == '\a') {
    channel_command_dispatch_select_or_save_name();
  }
  else if (cVar1 == '\b') {
    menu_char_dispatcher_null_and_0x01();
  }
  else {
    write_status_mode_byte_pair(0x2a,1);
  }
  return;
}


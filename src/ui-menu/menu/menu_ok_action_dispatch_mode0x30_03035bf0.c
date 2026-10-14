/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_ok_action_dispatch_mode0x30 @ 03035bf0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_ok_action_dispatch_mode0x30(void)

{
  char cVar1;
  
  cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_03035d5c[1] + DAT_03035d60 + 2);
  if (cVar1 == '\x03') {
    channel_contact_commit_or_delete_dispatch();
  }
  else if (cVar1 == '\0') {
    field_entry_confirm_multicontext_dispatch();
  }
  else if (cVar1 == '\x01') {
    scanlist_membership_remove_or_prompt();
  }
  else if (cVar1 == '\x04') {
    channel_select_finalize_or_history_pop();
  }
  else if (cVar1 == '\x05') {
    menu_confirm_apply_dispatcher();
  }
  else if (cVar1 == '\a') {
    roam_zone_countdown_step_from_menu_index();
  }
  return;
}


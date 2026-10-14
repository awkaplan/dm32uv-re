/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_delete_or_two_mode_dispatch @ 03046b40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_confirm_delete_or_two_mode_dispatch(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03046cc0 + 2);
  if (bVar1 == 2) {
    menu_screen_dispatch_contact_or_static_by_two_empty_checks();
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      menu_confirm_delete_dialog_option_init_03046810();
    }
  }
  else if (bVar1 == 3) {
    menu_confirm_delete_dialog_option_init_030469c0();
  }
  else if (bVar1 == 4) {
    table_entry_select_two_mode_dispatch();
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_contact_pick_entry_dispatch @ 0303ca38 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_contact_pick_entry_dispatch(void)

{
  dialog_history_flush_and_reset();
  if (*(char *)((uint)(byte)PTR_g_menu_screen_state_0303cad0[1] + DAT_0303cad4 + 2) == '\x03') {
    menu_contact_pick_method_option_init_03046fe8();
  }
  else {
    write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_0303caa8[2] + DAT_0303cad8),0);
  }
  main_menu_screen_dispatch();
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_channel_entry_apply_or_status @ 03036304 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_channel_entry_apply_or_status(void)

{
  if (*(char *)((uint)(byte)PTR_g_menu_screen_state_03036368[1] + DAT_0303636c + 2) == '\x03') {
    menu_confirm_apply_channel_number_entry();
  }
  else {
    write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_03036370[2] + DAT_03036374),0);
  }
  return;
}


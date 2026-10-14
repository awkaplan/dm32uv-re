/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_capability_field0x44_bit0_check @ 0304c8f4 (file base 0x03000000; code starts at 0x03001000)
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

void menu_capability_field0x44_bit0_check(void)

{
  char cVar1;
  
  if ((p_dm32_settings_block04[0x44] & 1) == 0) {
    *(undefined1 *)p_active_screen_state_word = 1;
  }
  else {
    *(undefined1 *)p_active_screen_state_word = 0;
  }
  *(undefined1 *)PTR_DAT_0304cab0 = 2;
  cVar1 = *(char *)p_active_screen_state_word;
  *(char *)p_menu_selected_item_index = cVar1;
  *(char *)p_active_screen_flag_0003e5d5 = cVar1 + '\x01';
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_wrapper_field0xa4_toggle @ 0304ff9e (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_wrapper_field0xa4_toggle(void)

{
  p_dm32_settings_block04[0x6d] =
       p_dm32_settings_block04[0x6d] & 0xfb | (*(byte *)p_active_screen_state_word & 1) << 2;
  flash_field_read_cached(4,0xa4);
  flash_field_write_cached(4,0xa4);
  menu_row_highlight_draw();
  dialog_show_icon_and_number_from_ptr();
  return;
}


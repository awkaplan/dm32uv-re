/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_wrapper_conditional_notify @ 0304dff0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_wrapper_conditional_notify(void)

{
  if (*(char *)p_active_screen_state_word == '\0') {
    settings_write_dispatcher(5,0);
  }
  else {
    settings_write_dispatcher(5,1);
  }
  ui_event_notify_alt(8);
  menu_row_highlight_draw();
  dialog_show_icon_and_number
            (1,**(undefined4 **)
                 (PTR_PTR_0304e0c4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  return;
}


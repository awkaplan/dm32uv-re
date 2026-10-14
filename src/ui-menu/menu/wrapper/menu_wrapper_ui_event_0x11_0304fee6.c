/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_wrapper_ui_event_0x11 @ 0304fee6 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_wrapper_ui_event_0x11(void)

{
  if (*(char *)p_active_screen_state_word == '\x01') {
    vfo_scan_add_toggle(0);
    ui_event_notify_alt(0x11);
    ui_event_notify(0x19);
  }
  else {
    vfo_scan_add_toggle(1);
    ui_event_notify_alt(0x10);
    ui_event_notify(0x18);
  }
  return;
}


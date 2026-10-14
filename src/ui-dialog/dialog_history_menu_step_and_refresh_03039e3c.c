/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_history_menu_step_and_refresh @ 03039e3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_history_menu_step_and_refresh(void)

{
  if (p_dialog_history_ui_state->field_0x3 != 0x5b) {
    menu_mode_transition_and_field_redraw(4);
    write_status_mode_byte_pair
              (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03039fc0),0);
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: key_shortcut_call_03056ba8 @ 03040c6e (file base 0x03000000; code starts at 0x03001000)
 * Size: 16 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void key_shortcut_call_03056ba8(void)

{
  tx_gate_write_call_record(1);
  control_action_char_dispatch(DAT_03040d4c,DAT_03040d50);
  key_event_filter_dispatch1();
  write_status_mode_byte_pair
            (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03040eec),0);
  return;
}


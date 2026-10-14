/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: number_list_display_update_fwd @ 0304109a (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void number_list_display_update_fwd(void)

{
  tx_gate_write_call_record(1);
  list_cursor_advance_with_wrap();
  number_list_display_update(p_menu_screen_state->index_0x2 + 1);
  key_event_filter_dispatch1();
  write_status_mode_byte_pair
            (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_0304135c),0);
  return;
}


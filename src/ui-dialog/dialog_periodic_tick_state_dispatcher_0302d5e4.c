/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_periodic_tick_state_dispatcher @ 0302d5e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 186 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_periodic_tick_state_dispatcher(void)

{
  byte bVar1;
  
  bVar1 = p_tx_ptt_ui_state->field_0x4 + 1;
  p_tx_ptt_ui_state->field_0x4 = bVar1;
  if (5 < bVar1) {
    p_tx_ptt_ui_state->field_0x4 = 0;
    bVar1 = p_dialog_flags_from_flash->flags_0x1f & 0x78;
    if (bVar1 == 0x30) {
      if ((p_dialog_flags_from_flash->field_0x20 & 0x10) == 0) {
        dialog_close_reset();
      }
      else {
        protocol_control_char_dispatch_dialog_history(1);
        p_dialog_flags_from_flash->field_0x20 = p_dialog_flags_from_flash->field_0x20 & 0xef;
      }
    }
    else {
      if (((p_dialog_flags_from_flash->flags_0x1 & 3) == 1) &&
         ((byte)(p_dialog_flags_from_flash->field_0x32 - 3) < 2)) {
        return;
      }
      if (bVar1 == 0x40) {
        if ((p_dialog_flags_from_flash->flags_0x1 & 8) == 0) {
          p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xf7 | 8;
          ui_event_notify(0x16);
        }
        else if ((PTR_DAT_0302d828[1] & 2) == 0) {
          p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xf7;
        }
      }
      else {
        status_row_redraw_with_selftoggle_noop();
        talker_alias_refresh_gate_by_dialog_flags();
      }
    }
  }
  return;
}


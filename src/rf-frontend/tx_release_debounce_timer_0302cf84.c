/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_release_debounce_timer @ 0302cf84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 144 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_release_debounce_timer(void)

{
  dialog_flags_from_flash *pdVar1;
  byte bVar2;
  
  if ((p_dialog_flags_from_flash->flags_0x2d & 4) != 0) {
    if ((p_dialog_flags_from_flash->flags_0x2d & 0x10) == 0) {
      if ((p_tx_ptt_ui_state->field_0x3 & 1) == 0) {
        ui_notify_0x22_on_bit3_set_and_bit1_clear();
        pdVar1 = p_dialog_flags_from_flash;
        p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xdf | 0x20;
        pdVar1->field_0x2e = 0;
      }
      bVar2 = p_tx_ptt_ui_state->field_0x3 + 1;
      p_tx_ptt_ui_state->field_0x3 = bVar2;
      if (7 < bVar2) {
        p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xef | 0x10;
        p_tx_ptt_ui_state->field_0x3 = 0;
      }
    }
    else {
      bVar2 = p_tx_ptt_ui_state->field_0x3 + 1;
      p_tx_ptt_ui_state->field_0x3 = bVar2;
      if (0x1d < bVar2) {
        p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xef;
        p_tx_ptt_ui_state->field_0x3 = 0;
      }
    }
  }
  return;
}


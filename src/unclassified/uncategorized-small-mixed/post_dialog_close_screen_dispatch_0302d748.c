/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: post_dialog_close_screen_dispatch @ 0302d748 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void post_dialog_close_screen_dispatch(void)

{
  dialog_flags_from_flash *pdVar1;
  tx_ptt_ui_state *ptVar2;
  byte bVar3;
  
  if ((p_tx_ptt_ui_state->flags_0xa & 0x80) == 0) {
    bVar3 = p_dialog_flags_from_flash->flags_0x1 & 3;
    if (bVar3 == 1) {
      dialog_display_refresh_and_flag_clear();
    }
    else if (bVar3 == 2) {
      dialog_timeout_tick_and_notify();
    }
  }
  else {
    vfo_status_screen();
    ptVar2 = p_tx_ptt_ui_state;
    p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0x7f;
    ptVar2->field_0x4 = 0;
    pdVar1 = p_dialog_flags_from_flash;
    p_dialog_flags_from_flash->field_0x2 = 0x1c;
    if ((pdVar1->flags_0x1 & 3) == 1) {
      dialog_display_refresh_and_flag_clear();
    }
  }
  return;
}


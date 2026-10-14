/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_display_refresh_and_flag_clear @ 0302d700 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_display_refresh_and_flag_clear(void)

{
  dialog_flags_from_flash *pdVar1;
  
  if ((p_tx_ptt_ui_state->flags_0xb & 1) != 0) {
    refresh_display_based_on_dialog_flags();
    p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xfe;
  }
  dialog_periodic_tick_state_dispatcher();
  pdVar1 = p_dialog_flags_from_flash;
  if ((*(byte *)p_dialog_flags_from_flash & 0x80) != 0) {
    p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xfc;
    *(byte *)pdVar1 = *(byte *)pdVar1 & 0x7f;
  }
  return;
}


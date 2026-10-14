/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: caller_info_dialog_show_and_clear_flags @ 0302d848 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void caller_info_dialog_show_and_clear_flags(void)

{
  tx_ptt_ui_state *ptVar1;
  
  if ((p_tx_ptt_ui_state->flags_0xb & 2) != 0) {
    tx_caller_dialog_screen();
    ptVar1 = p_tx_ptt_ui_state;
    p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xfd;
    ptVar1->field_0x3 = 0;
    p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xef;
    ptVar1->flags_0xa = ptVar1->flags_0xa & 0xbf;
  }
  return;
}


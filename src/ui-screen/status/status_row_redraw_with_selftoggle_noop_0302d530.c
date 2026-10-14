/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_row_redraw_with_selftoggle_noop @ 0302d530 (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void status_row_redraw_with_selftoggle_noop(void)

{
  byte bVar1;
  
  if (((*(byte *)p_call_active_flag & 3) == 0) && (PTR_DAT_0302d684[0x4b0] == '\0')) {
    display_clear_status_row(0x82,0);
    if ((p_tx_ptt_ui_state->flags_0xa & 2) == 0) {
      display_draw_number_centered(0x82,0xffff,0,p_caller_id_display_text);
    }
    else {
      bVar1 = p_dialog_flags_from_flash->flags_0x1 & 3;
      if (bVar1 == 2) {
        display_draw_number_centered(0x82,0xffff,0,DAT_0302d690);
      }
      else if (bVar1 == 1) {
        display_draw_number_centered(0x82,0xffff,0,DAT_0302d690);
      }
    }
    p_tx_ptt_ui_state->flags_0xa =
         p_tx_ptt_ui_state->flags_0xa & 0xfd | (~(p_tx_ptt_ui_state->flags_0xa >> 1 & 1) & 1) << 1;
  }
  return;
}


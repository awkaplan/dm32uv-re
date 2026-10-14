/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_active_icon_draw_dual_slot @ 0302c17c (file base 0x03000000; code starts at 0x03001000)
 * Size: 216 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ptt_active_icon_draw_dual_slot(void)

{
  int iVar1;
  
  iVar1 = get_field_0301ea64_0x14();
  if (iVar1 == 1) {
    if ((*(byte *)p_call_active_flag & 1) == 0) {
      if ((p_tx_ptt_ui_state->flags_0xa & 1) != 0) {
        display_fill_rect(0xa2,0xe9,0xb9,0x100,0);
        p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfe;
      }
    }
    else if ((p_tx_ptt_ui_state->flags_0xa & 1) == 0) {
      display_blit_image(0xa2,0xe9,0x17,0x17,PTR_LAB_0302c248);
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfe | 1;
    }
  }
  else {
    iVar1 = get_field_0301ea64_0x14();
    if (iVar1 == 2) {
      if ((*(byte *)p_call_active_flag & 2) == 0) {
        if ((p_tx_ptt_ui_state->flags_0xa & 1) != 0) {
          display_fill_rect(0xa2,0xe9,0xb9,0x100,0);
          p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfe;
        }
      }
      else if ((p_tx_ptt_ui_state->flags_0xa & 1) == 0) {
        display_blit_image(0xa2,0xe9,0x17,0x17,PTR_LAB_0302c24c);
        p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfe | 1;
      }
    }
  }
  return;
}


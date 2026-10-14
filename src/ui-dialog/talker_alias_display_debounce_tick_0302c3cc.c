/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talker_alias_display_debounce_tick @ 0302c3cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void talker_alias_display_debounce_tick(void)

{
  tx_ptt_ui_state *ptVar1;
  byte bVar2;
  
  ptVar1 = p_tx_ptt_ui_state;
  *(short *)&p_tx_ptt_ui_state->field_0x60_0 = *(short *)&p_tx_ptt_ui_state->field_0x60_0 + 1;
  if ((ptVar1->flags_0xa & 0x48) == 0) {
    bVar2 = p_tx_ptt_ui_state->field_0x1 + 1;
    p_tx_ptt_ui_state->field_0x1 = bVar2;
    if (4 < bVar2) {
      p_tx_ptt_ui_state->field_0x1 = 0;
      ptt_active_icon_draw_dual_slot();
    }
  }
  else {
    p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xf7;
    talker_alias_info_screen();
    settings_set_menu_hold_interval(p_dm32_settings_block04[0x3a]);
  }
  return;
}


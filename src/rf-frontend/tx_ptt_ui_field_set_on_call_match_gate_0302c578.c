/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_ptt_ui_field_set_on_call_match_gate @ 0302c578 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_ptt_ui_field_set_on_call_match_gate(void)

{
  if (((((p_radio_mode_state_0003e318[1].flags_0x3 & 2) == 0) &&
       (p_tx_ptt_ui_state->field_0x14 == 1)) && ((p_tx_ptt_ui_state->field_0xc & 0x10) == 0)) &&
     ((*(int *)&p_call_setup_sm_state->field_0xc_0 == *PTR_DAT_0302c670 &&
      ((p_dm32_settings_block04[0x6f] & 1) != 0)))) {
    p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0xfc | 3;
  }
  return;
}


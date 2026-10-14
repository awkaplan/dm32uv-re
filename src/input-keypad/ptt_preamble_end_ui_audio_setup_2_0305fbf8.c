/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_preamble_end_ui_audio_setup_2 @ 0305fbf8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ptt_preamble_end_ui_audio_setup_2(void)

{
  tx_abort_on_condition();
  p_radio_mode_state_0003e318[1].flags_0x2 = 1;
  status_byte_bit5_set_clear_wrapper(0,0);
  audio_ctrl_fm_play_set(1);
  fd6818b_reg47_tx_bypass_or_rx_afout();
  audio_pa_enable_gate(1);
  tx_led_or_tone_off_conditional_variant_030609ec();
  return;
}


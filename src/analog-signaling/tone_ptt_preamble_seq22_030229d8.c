/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_ptt_preamble_seq22 @ 030229d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_ptt_preamble_seq22(void)

{
  tx_led_or_tone_off_conditional_variant_030609ec();
  tone_synth_mix4_stream(0x590,0x15e,0,0);
  tx_led_or_tone_off();
  tone_synth_mix4_stream(800,0x7f,0,0);
  tx_led_or_tone_off_conditional_variant_030609ec();
  tone_synth_mix4_stream(0x640,0x15e,0,0);
  tx_led_or_tone_off();
  timer_ch1_disable();
  if ((PTR_DAT_03022e50[0x2b] & 8) == 0) {
    audio_pa_enable_gate(0);
  }
  audio_ctrl_ring_play_set(0);
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0x10) {
    fd6818b_reg47_tx_bypass_or_rx_afout();
  }
  tone_or_volume_step_lookup(*(undefined1 *)PTR_DAT_03022e58);
  if ((*(byte *)p_call_active_flag & 1) == 0) {
    if (p_radio_mode_state_0003e318[1].flags_0x2 == 0) {
      if ((*(byte *)p_call_active_flag & 4) != 0) {
        ptt_preamble_end_ui_audio_setup_1();
      }
    }
    else {
      ptt_preamble_end_ui_audio_setup_2();
    }
  }
  else {
    rx_voice_start_begin_record();
    audio_pa_enable_gate(1);
  }
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    OSTimeDly_ms_wrapper(100);
    gpio_set_output_bit(0x2f);
  }
  p_radio_mode_state_0003e318->flags_0x7 = p_radio_mode_state_0003e318->flags_0x7 & 0xdd;
  PTR_DAT_03022e64[6] = 0;
  return;
}


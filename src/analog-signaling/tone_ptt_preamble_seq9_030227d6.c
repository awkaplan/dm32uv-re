/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_ptt_preamble_seq9 @ 030227d6 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tone_ptt_preamble_seq9(void)

{
  undefined4 uStack00000000;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  undefined4 uStack0000000c;
  undefined4 uStack00000010;
  
  uStack00000000 = 0;
  uStack00000004 = 1;
  uStack00000008 = 0;
  uStack0000000c = 0;
  uStack00000010 = 0;
  tone_synth_mix4_stream(0x1e0,0x9e,0);
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


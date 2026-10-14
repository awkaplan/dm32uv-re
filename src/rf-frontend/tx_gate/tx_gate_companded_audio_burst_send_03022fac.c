/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_gate_companded_audio_burst_send @ 03022fac (file base 0x03000000; code starts at 0x03001000)
 * Size: 150 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_gate_companded_audio_burst_send(undefined1 param_1)

{
  undefined2 local_10;
  undefined2 local_e;
  
  *PTR_keypad_poll_enable_word_03023094 = 0;
  *PTR_keypad_blank_rearm_flag_03023098 = 1;
  compand_table_nibble_split_lookup_variant_03060da8(param_1,&local_e,&local_10);
  audio_ctrl_fm_play_set(0);
  audio_ctrl_ring_play_set(1);
  gpio_clear_output_bit(0x2f);
  if (p_dm32_settings_block04[0x41] == '\0') {
    audio_pa_enable_gate(1);
  }
  mmio_14000000_timer_config(1);
  pcm_sample_mix_and_process_loop
            (1000,local_e,local_10,0,*(undefined4 *)PTR_LAB_030230a0,*PTR_DAT_030230a4,
             *PTR_DAT_030230a8,0);
  audio_pa_enable_gate(0);
  audio_ctrl_ring_play_set(0);
  timer_ch1_disable();
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    gpio_set_output_bit(0x2f);
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_sequence_playback_start @ 03060e84 (file base 0x03000000; code starts at 0x03001000)
 * Size: 300 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */
      (*(code *)(PTR_PTR_03060fe8[uVar4] & 0xfffffffe))();
      return;
    }
  }
dtmf_digit_sequence_playback_cleanup:
  audio_pa_enable_gate(0);
  tone_synth_silence_stream(600);
  config_table_entry_0x30();
  fd6818b_reg47_write_byte_or_6042(0);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
  config_table_entry_0x24();
  puVar1 = PTR_DAT_030610fc;
  *(byte *)PTR_DAT_030610fc = *(byte *)PTR_DAT_030610fc & 0xfe;
  p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xef;
  *(undefined1 *)((int)puVar1 + 1) = 0;
  audio_ctrl_fm_play_set();
  modem_fm_ptt_set(1);
  fd6818b_init_seq_filter_ctcss_chipmode();
  if (*(char *)((int)puVar1 + 3) == '\x01') {
    ui_mode_noop_stub_variant_03060e3c();
  }
  else if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    fd6818b_reg50_tx_audio_unmute_set();
    status_byte_bit5_set_clear_wrapper(0,1);
  }
  timer_ch1_disable();
  PTR_DAT_03061108[1] = PTR_DAT_03061108[1] & 0xfe | 1;
  os_sem_post(p_ucos_mutex_0003ff10);
  return;
}


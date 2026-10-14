/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_type_apply_tone_idx0xf @ 030595e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 4 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_type_apply_tone_idx0xf(void)

{
  undefined2 uStack00000004;
  undefined2 uStack00000006;
  
  fd6818b_reg50_tx_audio_mute_set();
  audio_ctrl_fm_play_set(1);
  modem_fm_ptt_set(0);
  status_byte_bit5_set_clear_wrapper(0,0);
  status_byte_bit5_set_clear_wrapper(1,0);
  config_table_init_entries_0x21_0x24();
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xe0e0);
  fd6818b_reg50_write_bb18();
  fd6818b_reg47_write_byte_or_6042(3);
  config_table_init_group1();
  if (p_dm32_settings_block04[0x41] == '\0') {
    audio_pa_enable_gate(1);
  }
  compand_table_nibble_split_lookup(0xf,(int)&stack0x00000004 + 2,&stack0x00000004);
  mmio_14000000_timer_config(1);
  config_entry_0x71_0x72_and_gain_apply(uStack00000006,uStack00000004,200);
  fd6818b_reg50_write_bb18();
  audio_pa_enable_gate(0);
  config_table_entry_0x30();
  fd6818b_reg47_write_byte_or_6042(0);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
  config_table_entry_0x24();
  fd6818b_init_seq_filter_ctcss_chipmode();
  audio_ctrl_fm_play_set(0);
  modem_fm_ptt_set(1);
  timer_ch1_disable();
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    fd6818b_reg50_tx_audio_unmute_set();
    status_byte_bit5_set_clear_wrapper(0,1);
  }
  return;
}


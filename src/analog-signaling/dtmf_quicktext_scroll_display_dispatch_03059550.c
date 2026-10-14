/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_quicktext_scroll_display_dispatch @ 03059550 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dtmf_quicktext_scroll_display_dispatch(void)

{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined2 local_14;
  undefined2 local_12;
  
  *PTR_keypad_poll_enable_word_030595c4 = 0;
  *PTR_keypad_blank_rearm_flag_030595c8 = 1;
  puVar2 = p_text_entry_current_char;
  if (*(ushort *)PTR_DAT_030595bc < 0x109) {
    display_draw_string_gb2312
              (*(ushort *)PTR_DAT_030595bc,*(ushort *)p_text_entry_current_char,
               (byte *)PTR_DAT_030595cc,0xffff,0);
    sVar1 = *(short *)puVar2;
    *(ushort *)puVar2 = sVar1 + 0xcU;
    if (0xe3 < (ushort)(sVar1 + 0xcU)) {
      *(undefined2 *)puVar2 = 5;
      *(short *)PTR_DAT_030595bc = *(short *)PTR_DAT_030595bc + 0x18;
    }
    uVar3 = *(byte *)PTR_DAT_030595cc - 0x23 & 0xff;
    if (uVar3 < 0x22) {
                    /* WARNING: Could not recover jumptable at 0x030595b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_030595d0[uVar3] & 0xfffffffe))();
      return;
    }
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
    compand_table_nibble_split_lookup();
    mmio_14000000_timer_config(1);
    config_entry_0x71_0x72_and_gain_apply(local_12,local_14,200);
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
  }
  else {
    tx_gate_write_call_record(0);
  }
  return;
}


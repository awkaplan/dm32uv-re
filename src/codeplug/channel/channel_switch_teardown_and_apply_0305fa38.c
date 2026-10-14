/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_switch_teardown_and_apply @ 0305fa38 (file base 0x03000000; code starts at 0x03001000)
 * Size: 410 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_switch_teardown_and_apply(int param_1__w)

{
  char param_1 = (char)param_1__w;
  radio_mode_state_0003e318 *prVar1;
  undefined4 *puVar2;
  
  prVar1 = p_radio_mode_state_0003e318;
  if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x10) == 0) {
    if ((*(byte *)PTR_DAT_0305fbc0 & 0x10) == 0) {
      if ((p_dm32_settings_block04[0x44] & 0xc) == 8) {
        p_radio_mode_state_0003e318[2].field_0x1 =
             p_radio_mode_state_0003e318[2].field_0x1 & 0x7f | 0x80;
        puVar2 = PTR_DAT_0305fbc8;
        *(byte *)PTR_DAT_0305fbc8 = *(byte *)PTR_DAT_0305fbc8 & 0xdf | 0x20;
        tone_gen_config_apply(0x100);
        prVar1[2].field_0x1 = prVar1[2].field_0x1 & 0x7f;
        *(byte *)puVar2 = *(byte *)puVar2 & 0xdf;
      }
      else if ((p_dm32_settings_block04[0x44] & 0xc) == 4) {
        int_to_double_divide_convert(1000);
        audio_pa_enable_gate(1);
        fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xc000);
        config_table_init_group1();
        fd6818b_reg47_write_byte_or_6042(3);
        busy_wait_delay_n_units(0x3c);
        int_to_double_divide_convert(0x2df);
        busy_wait_delay_n_units(0x3c);
        audio_pa_enable_gate(0);
        fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
        fd6818b_reg47_afout_clear_mode();
        fd6818b_init_seq_filter_ctcss_chipmode();
      }
    }
    else {
      *(byte *)PTR_DAT_0305fbc0 = *(byte *)PTR_DAT_0305fbc0 & 0xef;
    }
    fd6818b_reg50_tx_audio_mute_set();
    if (param_1 == '\0') {
      vfo_display_config_apply();
    }
  }
  else {
    audio_ctrl_fm_play_set(0);
    fd6818b_reg47_write_byte_or_6042(0);
    fd6818b_init_seq_filter_ctcss_chipmode();
    audio_pa_enable_gate(0);
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
    p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0xef;
    if (param_1 == '\0') {
      vfo_display_config_apply();
    }
  }
  dac_channel2_write_from_byte(0);
  OSTimeDly_ms_wrapper(0x1e);
  pa_band_select_vhf_uhf_gpio(0);
  noop_stub_0301a5d8(PTR_DAT_0305fbcc[1] & 1,0);
  signal_meter_bargraph_draw(1,0,0x8430);
  *(undefined2 *)&p_tx_ptt_ui_state->field_0x60_0 = 0;
  *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xf7;
  dialog_set_pending_render_flag();
  if ((PTR_DAT_0305fbd8[5] & 1) != 0) {
    if (p_dm32_settings_block04[0x6c] == '\x01') {
      if ((((p_vfo_display_state->field_0x16 >> 1 & 7) == 0) ||
          ((p_radio_mode_state_0003e318[2].flags_0x2 & 0x20) != 0)) ||
         ((p_vfo_display_state->field_0x16 >> 4 & 7) == 0)) {
        vfo_sync_active_side_on_ptt();
      }
    }
    else {
      vfo_sync_active_side_on_ptt();
    }
    PTR_DAT_0305fd5c[5] = PTR_DAT_0305fd5c[5] & 0xfe;
  }
  channel_change_apply_squelch();
  return;
}


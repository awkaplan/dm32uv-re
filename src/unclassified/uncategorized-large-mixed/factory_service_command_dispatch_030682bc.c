/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: factory_service_command_dispatch @ 030682bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 195 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined1 factory_service_command_dispatch(char param_1,undefined1 param_2)

{
  undefined1 uVar1;
  
  if ((p_radio_mode_state_0003e318->flags_0x7 & 0x18) == 0) {
    *(byte *)PTR_DAT_03068440 = *(byte *)PTR_DAT_03068440 & 0xfd;
    PTR_DAT_03068444[1] = PTR_DAT_03068444[1] & 0xfe;
    audio_ctrl_fm_play_set(1);
    modem_fm_ptt_set(0);
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xf7 | 8;
    radio_init_sequence();
    fd6818b_reg50_tx_audio_mute_set();
    if (param_1 == '\x02') {
      uVar1 = flash_record_frequency_calibration_apply(param_2);
    }
    else if (param_1 == '\x03') {
      uVar1 = dtmf_tone_playback_from_i2c_stored_code(param_2);
    }
    else if (param_1 == '\x01') {
      uVar1 = dtmf_compand_config_apply(param_2);
    }
    else {
      uVar1 = 0;
    }
    audio_ctrl_fm_play_set(0);
    fd6818b_reg50_tx_audio_mute_set();
    vfo_display_config_apply();
    dac_channel2_write_from_byte(0);
    OSTimeDly_ms_wrapper(0x1e);
    pa_band_select_vhf_uhf_gpio(0);
    *(undefined2 *)&p_tx_ptt_ui_state->field_0x60_0 = 0;
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xf7;
    dialog_set_pending_render_flag();
    channel_change_apply_squelch();
    PTR_DAT_03068444[1] = PTR_DAT_03068444[1] & 0xfe | 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


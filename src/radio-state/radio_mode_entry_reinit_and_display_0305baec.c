/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_mode_entry_reinit_and_display @ 0305baec (file base 0x03000000; code starts at 0x03001000)
 * Size: 806 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_mode_entry_reinit_and_display(void)

{
  bool bVar1;
  undefined1 *puVar2;
  radio_mode_state_0003e318 *prVar3;
  int iVar4;
  byte bVar5;
  undefined1 auStack_c [4];
  
  *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xf7 | 8;
  *PTR_DAT_0305bbf8 = (uint)(byte)p_dm32_settings_block04[0x58];
  if ((PTR_DAT_0305bbfc[3] & 1) != 0) {
    PTR_DAT_0305bbfc[3] = PTR_DAT_0305bbfc[3] & 0xbf | 0x40;
  }
  noop_stub_0301a5d8(PTR_DAT_0305bc00[1] & 1,2);
  pending_request_set_code(2);
  if ((*(char *)PTR_DAT_0305bc04 != '\0') && ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0))
  {
    dialog_show_number_or_alt();
  }
  if (*(char *)PTR_DAT_0305bc04 == '\0') {
    if ((p_vfo_display_state->flags_0x8 & 6) == 0) {
      signal_meter_bargraph_draw(1,6,0xf800);
    }
    else if ((p_vfo_display_state->flags_0x8 & 6) == 2) {
      signal_meter_bargraph_draw(1,0xc,0xf800);
    }
    else {
      signal_meter_bargraph_draw(1,0x13,0xf800);
    }
    if (((PTR_DAT_0305bc00[1] & 1) == (byte)p_dm32_settings_block04[0x2d] >> 7) &&
       ((iVar4 = vfo_active_side_mode_nibble(), iVar4 == 0 || (iVar4 == 2)))) {
      display_update_tone_signaling_icon(1);
    }
    if (((*(byte *)PTR_DAT_0305bc0c & 8) == 0) || ((PTR_DAT_0305bc00[1] & 1) != 0)) {
      if ((*(byte *)PTR_DAT_0305bc0c & 0x10) == 0) {
        bVar1 = false;
      }
      else {
        bVar1 = (PTR_DAT_0305bc00[1] & 1) != 0;
      }
    }
    else {
      bVar1 = true;
    }
    iVar4 = get_current_mode_state1();
    puVar2 = PTR_DAT_0305bddc;
    if (iVar4 == 0) {
      if ((*(int *)&p_vfo_display_state->field_0x4_0 != *(int *)p_vfo_display_state) && (!bVar1)) {
        if (((p_dm32_settings_block04[0x2d] & 0x24) == 4) ||
           (((p_dm32_settings_block04[0x2d] & 4) == 0 || (p_dm32_settings_block04[0x6c] == '\0'))))
        {
          display_clear_channel_row_background(PTR_DAT_0305bddc[1] & 1,1);
          display_draw_channel_frequency
                    (puVar2[1] & 1,*(undefined4 *)&p_vfo_display_state->field_0x4_0);
        }
        else {
          display_draw_frequency(PTR_DAT_0305bddc[1] & 1);
        }
      }
    }
  }
  if ((PTR_DAT_0305bde0[5] & 1) == 0) {
    display_refresh_tone_mode_icon();
  }
  modem_fm_ptt_set(1);
  dialog_set_pending_render_flag(1);
  radio_init_sequence();
  if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x10) == 0) {
    if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0) {
      if (((((p_vfo_display_state->field_0x16 >> 1 & 7) != 0) &&
           ((p_radio_mode_state_0003e318[2].flags_0x2 & 0x20) == 0)) &&
          ((p_vfo_display_state->field_0x16 >> 4 & 7) != 0)) &&
         ((p_dm32_settings_block04[0x6c] == '\x01' || ((PTR_DAT_0305bde0[5] & 1) == 0)))) {
        radio_mode_enter_and_refresh(PTR_DAT_0305bddc[1] & 1);
        display_refresh_tone_mode_icon();
      }
      prVar3 = p_radio_mode_state_0003e318;
      bVar5 = p_vfo_display_state->field_0x16 & 0xe;
      if (bVar5 == 2) {
        bVar5 = p_vfo_display_state->field_0x19 & 0xc;
        if ((bVar5 == 4) || (bVar5 == 0xc)) {
          operating_mode_set_and_notify(0);
        }
      }
      else if (bVar5 == 8) {
        if (((p_vfo_display_state->field_0x19 >> 2 & 1) != 0) && (PTR_DAT_0305bf70[1] == '\0')) {
          p_radio_mode_state_0003e318[2].field_0x1 =
               p_radio_mode_state_0003e318[2].field_0x1 & 0x7f | 0x80;
          tone_gen_config_apply(0x180);
          prVar3[2].field_0x1 = prVar3[2].field_0x1 & 0x7f;
        }
      }
      else if (((bVar5 == 6) && ((p_vfo_display_state->field_0x19 >> 2 & 1) != 0)) &&
              (PTR_DAT_0305bf70[1] == '\0')) {
        dtmf_tone_playback_from_i2c_code(1);
      }
      fd6818b_reg50_tx_audio_unmute_set();
      status_byte_bit5_set_clear_wrapper(0,1);
    }
    else {
      display_blit_bitmap_1bpp_rows
                (*(undefined2 *)PTR_DAT_0305bdec,*(undefined2 *)p_text_entry_current_char,
                 PTR_LAB_0305bdf4,1);
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_c);
      operating_mode_set_and_notify(2);
    }
  }
  else {
    status_byte_bit5_set_clear_wrapper(0,0);
    status_byte_bit5_set_clear_wrapper(1,0);
    audio_ctrl_fm_play_set(1);
    modem_fm_ptt_set(0);
    int_to_double_divide_convert(PTR_LAB_0305bde8[(byte)p_dm32_settings_block04[0x6d] >> 3 & 3]);
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xc000);
    config_table_init_group1();
    fd6818b_reg47_write_byte_or_6042(3);
    fd6818b_reg50_write_3b18();
    audio_pa_enable_gate(1);
  }
  return;
}


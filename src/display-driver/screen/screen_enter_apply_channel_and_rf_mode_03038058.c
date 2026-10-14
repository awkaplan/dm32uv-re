/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: screen_enter_apply_channel_and_rf_mode @ 03038058 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1148 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void screen_enter_apply_channel_and_rf_mode(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  byte bStack_21;
  ushort auStack_20 [8];
  
  bStack_21 = 0;
  dialog_history_flush_and_reset();
  puVar3 = PTR_DAT_03038250;
  bVar2 = *(byte *)((uint)*(byte *)PTR_DAT_03038250 + DAT_03038254);
  display_fill_rect(0,0,0xf0,0x1b,0);
  display_draw_number_centered
            (2,0xffff,0,
             *(uint *)(*PTR_DAT_0303825c +
                      (uint)(byte)PTR_active_screen_index_list_03038258
                                  [(uint)bVar2 +
                                   ((byte)PTR_active_screen_index_list_03038258[0x2e2] - 1) * 0x23 +
                                   0x26] * 4));
  display_fill_screen(0);
  PTR_DAT_03038260[1] = PTR_DAT_03038260[1] & 0xf7;
  cVar1 = *(char *)(puVar3 + 0x282);
  if ((cVar1 == '\x0f') && (*(char *)((int)puVar3 + 0xa09) != '0')) {
    display_draw_string_gb2312(0x122,0xc,PTR_DAT_03038264,0xffff,0);
  }
  else if (cVar1 == '\x12') {
    display_draw_string_gb2312(0x122,0xc,PTR_LAB_03038268,0xffff,0);
    init_flag_and_mmio_bits7_8();
  }
  else {
    display_draw_string_gb2312(0x122,0xc,PTR_LAB_0303826c,0xffff,0);
  }
  if (*(char *)((int)PTR_DAT_03038250 + 0xa09) == 'J') {
    adc_diag_avg_ch2_display();
  }
  else if (*(char *)(PTR_DAT_03038250 + 0x282) == '\x11') {
    adc_diag_avg_ch1_display();
  }
  else {
    display_lookup_channel_icon_and_bank(&bStack_21);
    audio_compander_calibration_apply(bStack_21);
    if ((PTR_DAT_03038270[3] & 8) == 0) {
      if (*(byte *)((int)PTR_DAT_03038250 + 0xa09) < 0x32) {
        flash_field_read_cached(2,(bStack_21 + 0xcf) * 4,auStack_20,4);
      }
      else {
        flash_field_read_cached(2,(bStack_21 + 0xca) * 4,auStack_20,4);
      }
    }
    else if (*(byte *)((int)PTR_DAT_03038250 + 0xa09) < 0x32) {
      flash_field_read_cached(2,(bStack_21 + 0xc5) * 4,auStack_20,4);
    }
    else {
      flash_field_read_cached(2,(bStack_21 + 0xc0) * 4,auStack_20,4);
    }
    if (*(char *)(PTR_DAT_03038250 + 0x282) == '\x12') {
      uVar5 = channel_list_index_resolve(PTR_DAT_03038274[0x29],PTR_DAT_03038274[0x26]);
      channel_frequencies_read_and_decode(uVar5,&uStack_54);
      frequency_band_range_check_and_status_set(uStack_54,uStack_50);
      commit_channel_record_dual_vfo
                (uStack_54,uStack_50,uStack_4c,uStack_48,uStack_44,uStack_40,uStack_3c,uStack_38,
                 uStack_34,uStack_30,uStack_2c,uStack_28,uStack_24,0);
      PTR_DAT_03038278[8] = PTR_DAT_03038278[8] & 9 | 4;
      rf_mode_transition_on_freq_delta(&uStack_54);
      freq_calibration_apply_all();
    }
    else {
      memcpy_ck803s(&uStack_54,DAT_03038438,0x33);
      uStack_54 = bcd_frequency_decode(auStack_20,4);
      uStack_50 = uStack_54;
    }
    channel_freq_pair_store(uStack_50,uStack_54);
    tx_power_mode_apply_from_flags(&uStack_54);
    if (PTR_DAT_0303843c[0xa09] == '\x1a') {
      flash_field_read_cached(2,*(undefined2 *)PTR_DAT_03038440,auStack_20,2);
      *(ushort *)PTR_DAT_03038444 = auStack_20[0];
      if ((PTR_DAT_0303843c[0xa09] == '\x1a') && (0x400 < auStack_20[0])) {
        *(undefined2 *)PTR_DAT_03038444 = 0x400;
      }
    }
    else if (PTR_DAT_0303843c[0xa09] != 'Q') {
      flash_field_read_cached(2,*(undefined2 *)PTR_DAT_03038440,auStack_20,1);
      if (PTR_DAT_0303843c[0xa08] == '\0') {
        if ((char)auStack_20[0] == -1) {
          auStack_20[0] = CONCAT11(SUBPIECE(auStack_20[0], 1, 1),100);
        }
        PTR_DAT_03038448[0x28] = (char)auStack_20[0];
      }
      else if ((byte)(PTR_DAT_0303843c[0xa08] - 9) < 4) {
        if ((char)auStack_20[0] < '\0') {
          auStack_20[0] = CONCAT11(SUBPIECE(auStack_20[0], 1, 1),0x7f);
        }
        PTR_DAT_0303844c[1] = auStack_20[0] & 0xff;
      }
      *(ushort *)PTR_DAT_03038444 = auStack_20[0] & 0xff;
    }
    if ((PTR_DAT_0303843c[0xa08] != '\x0f') && (PTR_DAT_0303843c[0xa08] != '\x12')) {
      diag_rssi_sql_numeric_draw(3,*(undefined2 *)PTR_DAT_03038444);
    }
    format_and_plot_number_with_decimals
              ((byte)PTR_DAT_03038450[0x2d] >> 7,0x3b,10,0xffff,0,uStack_54);
    mmio_11000088_bool_set(1);
    uVar6 = (uint)(byte)PTR_DAT_0303843c[0xa08];
    if ((((uVar6 != 0xd) && (uVar6 != 0xf)) && (uVar6 != 0x12)) && (uVar6 != 0x13)) {
      (*(code *)(PTR_DAT_03038454[uVar6] & 0xfffffffe))(*(undefined2 *)PTR_DAT_03038444);
    }
    bVar2 = PTR_DAT_0303843c[0xa09];
    if (bVar2 == 0x51) {
      *(byte *)((int)DAT_03038438 + 8) = *(byte *)((int)DAT_03038438 + 8) & 9 | 4;
      modem_rf_mode_transition_apply(0,0,1);
      PTR_DAT_03038458[2] = PTR_DAT_03038458[2] & 0xef;
      tx_bandwidth_deviation_mode_set(0,1);
      gpio_set_output_bit(0x2e);
      gpio_set_output_bit(0x2f);
    }
    else if (bVar2 < 0x32) {
      if ((bVar2 < 0xf) || ((byte)(bVar2 - 0x1b) < 0x15)) {
        *(byte *)((int)DAT_03038438 + 8) = *(byte *)((int)DAT_03038438 + 8) & 0xf;
        tx_bandwidth_deviation_mode_set(0,1);
        radio_init_sequence();
        tx_led_or_tone_off_conditional();
        fd6818b_reg50_tx_audio_unmute_set();
        status_byte_bit5_set_clear_wrapper(0,1);
        modem_fm_bandwidth_write_0x5f(1);
        gpio_set_output_bit(0x2e);
      }
      else {
        tx_bandwidth_deviation_mode_set(1,0);
        radio_init_sequence();
        config_table_entry_0x51_clear();
        tx_led_or_tone_off_conditional();
        status_byte_bit5_set_clear_wrapper(1,1);
        modem_fm_bandwidth_write_0x5f(0);
        gpio_clear_output_bit(0x2e);
      }
      radio_mode_transition_sequencer(*(undefined1 *)PTR_DAT_03038574);
    }
    else {
      bVar2 = p_dialog_history_ui_state->field_0xa08;
      if (bVar2 == 0xf) {
        tx_bandwidth_deviation_mode_set(1,0);
        channel_change_apply_squelch();
        modem_fm_bandwidth_write_0x5f(0);
        SystemControl_Type_11000000.SYS_INTERP_MASK = 0x1800;
        radio_mode_transition_sequencer(*(undefined1 *)PTR_DAT_03038574);
        mmio_11000074_bits_7_8_set_clear(1);
      }
      else if (((byte)(bVar2 - 9) < 4) || (bVar2 == 0x13)) {
        tx_bandwidth_deviation_mode_set(0,1);
        puVar4 = PTR_DAT_0303857c;
        PTR_DAT_0303857c[8] = PTR_DAT_0303857c[8] & 0xf;
        puVar4[9] = puVar4[9] & 0x7f | 0x80;
        puVar4[0xc] = puVar4[0xc] & 0xf | 0x10;
        channel_change_apply_squelch();
        modem_fm_bandwidth_write_0x5f(1);
        radio_mode_transition_sequencer(9);
        PTR_DAT_03038580[2] = PTR_DAT_03038580[2] & 0xef | 0x10;
        mmio_11000074_bits_7_8_set_clear(1);
        gpio_set_output_bit(0x2f);
      }
    }
  }
  return;
}


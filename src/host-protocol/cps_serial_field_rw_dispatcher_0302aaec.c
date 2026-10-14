/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cps_serial_field_rw_dispatcher @ 0302aaec (file base 0x03000000; code starts at 0x03001000)
 * Size: 122 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void cps_serial_field_rw_dispatcher(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  radio_mode_state_0003e318 *prVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  vfo_display_state *pvVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  undefined4 local_7c;
  undefined4 uStack_78;
  byte local_49;
  int local_48;
  ushort local_44;
  undefined1 uStack_42;
  byte bStack_41;
  byte bStack_40;
  ushort auStack_3f [13];
  
  local_49 = 0;
  *(byte *)PTR_DAT_0302ab6c = *(byte *)PTR_DAT_0302ab6c & 0xfd | 2;
  p_call_setup_sm_state_aux->field_0x2 = 1;
  p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xef;
  puVar5 = PTR_DAT_0302ab78;
  PTR_DAT_0302ab78[800] = 0;
  puVar6 = PTR_DAT_0302ab7c;
  prVar4 = p_radio_mode_state_0003e318;
  puVar3 = PTR_DAT_0302ab68;
  do {
    do {
      do {
        cVar9 = (*(code *)(*puVar3 & 0xfffffffe))(&local_44,5,500,&local_48);
        bVar8 = bStack_40;
        bVar10 = bStack_41;
      } while (cVar9 != '\x05');
    } while (local_48 == 0x72d9);
    if (0x40 < bStack_40) {
      return;
    }
    cVar9 = (char)local_44;
    uVar12 = (uint)bStack_41;
    if (uVar12 < 0x67) {
                    /* WARNING: Could not recover jumptable at 0x0302ab64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0302ab80[uVar12] & 0xfffffffe))();
      return;
    }
    if ((byte)puVar5[800] == uVar12) {
      if (*(int *)(puVar5 + 0x324) != 0) goto LAB_0302ae5a;
    }
    else {
      puVar5[800] = bStack_41;
      tx_audio_dac_envelope_ramp(1,0,0);
      pa_band_select_vhf_uhf_gpio(0);
      antenna_switch_select_gpio_24_22(0);
      tx_led_or_tone_on();
      tx_led_or_tone_off();
      radio_mode_reset_to_idle();
      if (0x31 < (byte)*puVar6) {
        audio_pa_enable_gate(0);
      }
      noop_stub_0300c0ec();
LAB_0302ae5a:
      *(undefined4 *)(puVar5 + 0x324) = 0;
      memset_bytes(DAT_0302af48,0,0x32);
      if (*puVar6 == 'J') {
        adc_diag_avg_ch2_display();
      }
      else {
        display_lookup_channel_icon_and_bank(&local_49);
        audio_compander_calibration_apply(local_49);
        if ((prVar4->flags_0x3 & 8) == 0) {
          if ((byte)*puVar6 < 0x32) {
            flash_field_read_cached(2,(local_49 + 0xcf) * 4,&local_44,4);
          }
          else {
            flash_field_read_cached(2,(local_49 + 0xca) * 4,&local_44,4);
          }
        }
        else if ((byte)*puVar6 < 0x32) {
          flash_field_read_cached(2,(local_49 + 0xc5) * 4,&local_44,4);
        }
        else {
          flash_field_read_cached(2,(local_49 + 0xc0) * 4,&local_44,4);
        }
        memcpy_ck803s(&local_7c,p_vfo_display_state,0x33);
        local_7c = bcd_frequency_decode(&local_44,4);
        uStack_78 = local_7c;
        channel_freq_pair_store(local_7c,local_7c);
        tx_power_mode_apply_from_flags(&local_7c);
        bVar2 = *puVar6;
        if (bVar2 == 0x1a) {
          flash_field_read_cached(2,*(undefined2 *)PTR_DAT_0302b150,auStack_3f,2);
          *(ushort *)PTR_DAT_0302b154 = auStack_3f[0];
          if (0x400 < auStack_3f[0]) {
            *(undefined2 *)PTR_DAT_0302b154 = 0x400;
          }
        }
        else if (((bVar2 != 0x4a) && (bVar2 != 0x4c)) && (bVar2 < 0x4c)) {
          flash_field_read_cached(2,*(undefined2 *)PTR_DAT_0302b150,auStack_3f,1);
          *(ushort *)PTR_DAT_0302b154 = auStack_3f[0] & 0xff;
          if (*(char *)PTR_DAT_0302b158 == '\0') {
            if ((char)auStack_3f[0] == -1) {
              *(undefined2 *)PTR_DAT_0302b154 = 100;
            }
            PTR_DAT_0302b15c[0x28] = (char)*(undefined2 *)PTR_DAT_0302b154;
          }
          else if ((byte)(*(char *)PTR_DAT_0302b158 - 9U) < 4) {
            PTR_DAT_0302b160[1] = auStack_3f[0] & 0xff;
          }
        }
        mmio_11000088_bool_set(1);
        bVar2 = *puVar6;
        if (bVar2 < 0x32) {
          if ((bVar2 < 0xf) || ((byte)(bVar2 - 0x1b) < 0x15)) {
            p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf;
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
          radio_mode_transition_sequencer(*(undefined1 *)PTR_DAT_0302b168);
        }
        else {
          cVar1 = *(char *)PTR_DAT_0302b158;
          if (cVar1 == '\x0f') {
            tx_bandwidth_deviation_mode_set(1,0);
            channel_change_apply_squelch();
            modem_fm_bandwidth_write_0x5f(0);
            SystemControl_Type_11000000.SYS_INTERP_MASK = 0x1800;
            radio_mode_transition_sequencer(*(undefined1 *)PTR_DAT_0302b168);
            mmio_11000074_bits_7_8_set_clear(1);
          }
          else if (((byte)(cVar1 - 9U) < 4) || (cVar1 == '\x13')) {
            tx_bandwidth_deviation_mode_set(0,1);
            pvVar7 = p_vfo_display_state;
            p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf;
            pvVar7->flags_0x9 = pvVar7->flags_0x9 & 0x7f | 0x80;
            pvVar7->field_0xc = pvVar7->field_0xc & 0xf | 0x10;
            channel_change_apply_squelch();
            modem_fm_bandwidth_write_0x5f(1);
            radio_mode_transition_sequencer(9);
            prVar4->flags_0x2 = prVar4->flags_0x2 & 0xef | 0x10;
            mmio_11000074_bits_7_8_set_clear(1);
            gpio_set_output_bit(0x2f);
          }
        }
        uVar11 = (uint)*(byte *)PTR_DAT_0302b158;
        if ((((uVar11 != 0xd) && (uVar11 != 0xf)) && (uVar11 != 0x12)) && (uVar11 != 0x13)) {
          (*(code *)(PTR_DAT_0302b16c[uVar11] & 0xfffffffe))(*(undefined2 *)PTR_DAT_0302b154);
        }
      }
    }
    if (cVar9 == 'R') {
      local_44 = 0x57;
      uStack_42 = 0;
      bStack_41 = bVar10;
      bStack_40 = bVar8;
      if (uVar12 < 0x61) {
        if (bVar8 == 1) {
          auStack_3f[0] = CONCAT11(SUBPIECE(auStack_3f[0], 1, 1),(char)*(undefined2 *)PTR_DAT_0302b32c);
          (*(code *)(puVar3[1] & 0xfffffffe))(&local_44,6);
        }
        else {
          auStack_3f[0] = *(ushort *)PTR_DAT_0302b32c;
          (*(code *)(puVar3[1] & 0xfffffffe))(&local_44,7);
        }
      }
      else {
        uVar12 = strlen_ck803s(DAT_0302b170);
        uVar12 = uVar12 & 0xff;
        if (uVar12 == 0) {
          uVar12 = 1;
        }
        bStack_40 = (byte)uVar12;
        memcpy_bytes_iram(auStack_3f,DAT_0302b170,uVar12);
        (*(code *)(puVar3[1] & 0xfffffffe))(&local_44,uVar12 + 5);
      }
    }
    else if (cVar9 == 'W') {
      bVar10 = (*(code *)(*puVar3 & 0xfffffffe))(&local_44,bVar8,500,&local_48);
      if ((bVar10 == bVar8) && (local_48 != 0x72d9)) {
        if (bVar10 == 1) {
          *(ushort *)PTR_DAT_0302b32c = local_44 & 0xff;
        }
        else if (((bVar10 == 2) && (*(ushort *)PTR_DAT_0302b32c = local_44, *puVar6 == '\x1a')) &&
                (0x400 < local_44)) {
          *(undefined2 *)PTR_DAT_0302b32c = 0x400;
        }
        (*(code *)(PTR_DAT_0302b334[*(byte *)PTR_DAT_0302b330] & 0xfffffffe))
                  (*(undefined2 *)PTR_DAT_0302b32c);
        local_44 = CONCAT11(SUBPIECE(local_44, 1, 1),6);
        (*(code *)(puVar3[1] & 0xfffffffe))(&local_44,1);
      }
    }
    else if (cVar9 == 'S') {
      puVar5[800] = 0;
      tx_audio_dac_envelope_ramp(1,0,0);
      pa_band_select_vhf_uhf_gpio(0);
      antenna_switch_select_gpio_24_22(0);
      tx_led_or_tone_on();
      tx_led_or_tone_off();
      radio_mode_reset_to_idle();
      if (0x31 < (byte)*puVar6) {
        audio_pa_enable_gate(0);
      }
      if (*(char *)PTR_DAT_0302b330 != '\x0f') {
        local_44 = *(ushort *)PTR_DAT_0302b32c;
        if ((*puVar6 == '\x1a') || (*puVar6 == 'J')) {
          flash_block_write(2,*(undefined2 *)PTR_DAT_0302b338,&local_44,2);
        }
        else {
          flash_block_write(2,*(undefined2 *)PTR_DAT_0302b338,&local_44,1);
        }
      }
      local_44 = CONCAT11(SUBPIECE(local_44, 1, 1),6);
      (*(code *)(puVar3[1] & 0xfffffffe))(&local_44,1);
    }
  } while( true );
}


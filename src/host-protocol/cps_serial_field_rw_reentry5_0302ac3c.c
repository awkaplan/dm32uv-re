/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cps_serial_field_rw_reentry5 @ 0302ac3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void cps_serial_field_rw_reentry5(void)

{
  byte bVar1;
  vfo_display_state *pvVar2;
  char cVar3;
  uint uVar4;
  uint *unaff_r4;
  byte bVar5;
  uint unaff_r6;
  uint unaff_r7;
  int unaff_r8;
  uint unaff_r9;
  byte *unaff_r10;
  int unaff_r11;
  undefined4 in_stack_00000000;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000030;
  int in_stack_00000034;
  byte bStack00000038;
  undefined1 uStack00000039;
  undefined1 uStack0000003a;
  byte bStack0000003b;
  byte bStack0000003c;
  char cStack0000003d;
  undefined1 uStack0000003e;
  
  *unaff_r10 = (char)unaff_r6 - 0x1f;
  *(undefined1 *)PTR_DAT_0302ad44 = 0;
  *(undefined1 *)PTR_DAT_0302ad48 = 0;
  *(byte *)(unaff_r11 + 3) = *(byte *)(unaff_r11 + 3) & 0xe7;
  do {
    bVar5 = (byte)unaff_r6;
    if (*(byte *)(unaff_r8 + 800) == unaff_r6) {
      if (*(int *)(unaff_r8 + 0x324) != 0) goto LAB_0302ae5a;
    }
    else {
      *(byte *)(unaff_r8 + 800) = bVar5;
      tx_audio_dac_envelope_ramp(1,0,0);
      pa_band_select_vhf_uhf_gpio(0);
      antenna_switch_select_gpio_24_22(0);
      tx_led_or_tone_on();
      tx_led_or_tone_off();
      radio_mode_reset_to_idle();
      if (0x31 < *unaff_r10) {
        audio_pa_enable_gate(0);
      }
      noop_stub_0300c0ec();
LAB_0302ae5a:
      *(undefined4 *)(unaff_r8 + 0x324) = 0;
      memset_bytes(DAT_0302af48,0,0x32);
      if (*unaff_r10 == 0x4a) {
        adc_diag_avg_ch2_display();
      }
      else {
        display_lookup_channel_icon_and_bank((int)&stack0x00000030 + 3);
        audio_compander_calibration_apply(SUBPIECE(in_stack_00000030, 3, 1));
        if ((*(byte *)(unaff_r11 + 3) & 8) == 0) {
          if (*unaff_r10 < 0x32) {
            flash_field_read_cached(2,(SUBPIECE(in_stack_00000030, 3, 1) + 0xcf) * 4,&stack0x00000038,4);
          }
          else {
            flash_field_read_cached(2,(SUBPIECE(in_stack_00000030, 3, 1) + 0xca) * 4,&stack0x00000038,4);
          }
        }
        else if (*unaff_r10 < 0x32) {
          flash_field_read_cached(2,(SUBPIECE(in_stack_00000030, 3, 1) + 0xc5) * 4,&stack0x00000038,4);
        }
        else {
          flash_field_read_cached(2,(SUBPIECE(in_stack_00000030, 3, 1) + 0xc0) * 4,&stack0x00000038,4);
        }
        memcpy_ck803s(&stack0x00000000,p_vfo_display_state,0x33);
        in_stack_00000000 = bcd_frequency_decode(&stack0x00000038,4);
        in_stack_00000004 = in_stack_00000000;
        channel_freq_pair_store(in_stack_00000000,in_stack_00000000);
        tx_power_mode_apply_from_flags();
        bVar1 = *unaff_r10;
        if (bVar1 == 0x1a) {
          flash_field_read_cached(2,*(undefined2 *)PTR_DAT_0302b150,(int)&stack0x0000003c + 1,2);
          *(ushort *)PTR_DAT_0302b154 = _cStack0000003d;
          if (0x400 < _cStack0000003d) {
            *(undefined2 *)PTR_DAT_0302b154 = 0x400;
          }
        }
        else if (((bVar1 != 0x4a) && (bVar1 != 0x4c)) && (bVar1 < 0x4c)) {
          flash_field_read_cached(2,*(undefined2 *)PTR_DAT_0302b150,(int)&stack0x0000003c + 1,1);
          *(ushort *)PTR_DAT_0302b154 = _cStack0000003d & 0xff;
          if (*(char *)PTR_DAT_0302b158 == '\0') {
            if (cStack0000003d == -1) {
              *(undefined2 *)PTR_DAT_0302b154 = 100;
            }
            PTR_DAT_0302b15c[0x28] = (char)*(undefined2 *)PTR_DAT_0302b154;
          }
          else if ((byte)(*(char *)PTR_DAT_0302b158 - 9U) < 4) {
            PTR_DAT_0302b160[1] = _cStack0000003d & 0xff;
          }
        }
        mmio_11000088_bool_set(1);
        bVar1 = *unaff_r10;
        if (bVar1 < 0x32) {
          if ((bVar1 < 0xf) || ((byte)(bVar1 - 0x1b) < 0x15)) {
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
          cVar3 = *(char *)PTR_DAT_0302b158;
          if (cVar3 == '\x0f') {
            tx_bandwidth_deviation_mode_set(1,0);
            channel_change_apply_squelch();
            modem_fm_bandwidth_write_0x5f(0);
            SystemControl_Type_11000000.SYS_INTERP_MASK = 0x1800;
            radio_mode_transition_sequencer(*(undefined1 *)PTR_DAT_0302b168);
            mmio_11000074_bits_7_8_set_clear(1);
          }
          else if (((byte)(cVar3 - 9U) < 4) || (cVar3 == '\x13')) {
            tx_bandwidth_deviation_mode_set(0,1);
            pvVar2 = p_vfo_display_state;
            p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf;
            pvVar2->flags_0x9 = pvVar2->flags_0x9 & 0x7f | 0x80;
            pvVar2->field_0xc = pvVar2->field_0xc & 0xf | 0x10;
            channel_change_apply_squelch();
            modem_fm_bandwidth_write_0x5f(1);
            radio_mode_transition_sequencer(9);
            *(byte *)(unaff_r11 + 2) = *(byte *)(unaff_r11 + 2) & 0xef | 0x10;
            mmio_11000074_bits_7_8_set_clear(1);
            gpio_set_output_bit(0x2f);
          }
        }
        uVar4 = (uint)*(byte *)PTR_DAT_0302b158;
        if ((((uVar4 != 0xd) && (uVar4 != 0xf)) && (uVar4 != 0x12)) && (uVar4 != 0x13)) {
          (*(code *)(PTR_DAT_0302b16c[uVar4] & 0xfffffffe))(*(undefined2 *)PTR_DAT_0302b154);
        }
      }
    }
    if (unaff_r7 == 0x52) {
      _bStack00000038 = 0x57;
      uStack0000003a = 0;
      bStack0000003c = (byte)unaff_r9;
      bStack0000003b = bVar5;
      if (unaff_r6 < 0x61) {
        if (unaff_r9 == 1) {
          _cStack0000003d = CONCAT11(uStack0000003e,(char)*(undefined2 *)PTR_DAT_0302b32c);
          (*(code *)(unaff_r4[1] & 0xfffffffe))(&stack0x00000038,6);
        }
        else {
          _cStack0000003d = *(ushort *)PTR_DAT_0302b32c;
          (*(code *)(unaff_r4[1] & 0xfffffffe))(&stack0x00000038,7);
        }
      }
      else {
        uVar4 = strlen_ck803s(DAT_0302b170);
        uVar4 = uVar4 & 0xff;
        if (uVar4 == 0) {
          uVar4 = 1;
        }
        bStack0000003c = (byte)uVar4;
        memcpy_bytes_iram((int)&stack0x0000003c + 1,DAT_0302b170,uVar4);
        (*(code *)(unaff_r4[1] & 0xfffffffe))(&stack0x00000038,uVar4 + 5);
      }
    }
    else if (unaff_r7 == 0x57) {
      uVar4 = (*(code *)(*unaff_r4 & 0xfffffffe))(&stack0x00000038,unaff_r9,500,&stack0x00000034);
      uVar4 = uVar4 & 0xff;
      if ((uVar4 == unaff_r9) && (in_stack_00000034 != 0x72d9)) {
        if (uVar4 == 1) {
          *(ushort *)PTR_DAT_0302b32c = _bStack00000038 & 0xff;
        }
        else if (((uVar4 == 2) &&
                 (*(ushort *)PTR_DAT_0302b32c = _bStack00000038, *unaff_r10 == 0x1a)) &&
                (0x400 < _bStack00000038)) {
          *(undefined2 *)PTR_DAT_0302b32c = 0x400;
        }
        (*(code *)(PTR_DAT_0302b334[*(byte *)PTR_DAT_0302b330] & 0xfffffffe))
                  (*(undefined2 *)PTR_DAT_0302b32c);
        _bStack00000038 = CONCAT11(uStack00000039,6);
        (*(code *)(unaff_r4[1] & 0xfffffffe))(&stack0x00000038,1);
      }
    }
    else if (unaff_r7 == 0x53) {
      *(undefined1 *)(unaff_r8 + 800) = 0;
      tx_audio_dac_envelope_ramp(1,0,0);
      pa_band_select_vhf_uhf_gpio(0);
      antenna_switch_select_gpio_24_22(0);
      tx_led_or_tone_on();
      tx_led_or_tone_off();
      radio_mode_reset_to_idle();
      if (0x31 < *unaff_r10) {
        audio_pa_enable_gate(0);
      }
      if (*(char *)PTR_DAT_0302b330 != '\x0f') {
        _bStack00000038 = *(ushort *)PTR_DAT_0302b32c;
        if ((*unaff_r10 == 0x1a) || (*unaff_r10 == 0x4a)) {
          flash_block_write(2,*(undefined2 *)PTR_DAT_0302b338,&stack0x00000038,2);
        }
        else {
          flash_block_write(2,*(undefined2 *)PTR_DAT_0302b338,&stack0x00000038,1);
        }
      }
      _bStack00000038 = CONCAT11(uStack00000039,6);
      (*(code *)(unaff_r4[1] & 0xfffffffe))(&stack0x00000038,1);
    }
    do {
      do {
        cVar3 = (*(code *)(*unaff_r4 & 0xfffffffe))(&stack0x00000038,5,500,&stack0x00000034);
      } while (cVar3 != '\x05');
    } while (in_stack_00000034 == 0x72d9);
    unaff_r9 = (uint)bStack0000003c;
    if (0x40 < unaff_r9) {
      return;
    }
    unaff_r7 = (uint)bStack00000038;
    unaff_r6 = (uint)bStack0000003b;
    if (unaff_r6 < 0x67) {
                    /* WARNING: Could not recover jumptable at 0x0302ab64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(PTR_PTR_0302ab80[unaff_r6] & 0xfffffffe))();
      return;
    }
  } while( true );
}


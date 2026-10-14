/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_teardown_tx_release_sequence @ 03068538 (file base 0x03000000; code starts at 0x03001000)
 * Size: 292 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void call_teardown_tx_release_sequence(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((*(byte *)PTR_DAT_03068618 & 0x10) != 0) {
    if ((PTR_DAT_0306861c[0x20] & 1) == 0) {
      if (PTR_DAT_03068624[5] == '\0') {
        if ((p_radio_mode_state_0003e318->flags_0x2 & 0x10) == 0) {
          return;
        }
        *(byte *)PTR_DAT_03068618 = *(byte *)PTR_DAT_03068618 & 0xef;
      }
      else {
        PTR_DAT_03068624[5] = PTR_DAT_03068624[5] + -1;
      }
    }
    else {
      if ((p_radio_mode_state_0003e318->flags_0x2 & 0x10) == 0) {
        return;
      }
      if ((PTR_DAT_03068620[0x1d] & 4) != 0) {
        return;
      }
      if (PTR_DAT_03068624[5] == '\0') {
        *(byte *)PTR_DAT_03068618 = *(byte *)PTR_DAT_03068618 & 0xef;
      }
      else {
        PTR_DAT_03068624[5] = PTR_DAT_03068624[5] + -1;
      }
    }
    if ((*(byte *)PTR_DAT_03068618 & 0x10) == 0) {
      iVar2 = get_current_mode_state2();
      if (iVar2 != 0) {
        set_flag_byte_03064328(3);
      }
      *(byte *)PTR_call_active_flag_03068628 = *(byte *)PTR_call_active_flag_03068628 & 0xf7 | 8;
      p_radio_mode_state_0003e318[2].flags_0x2 =
           p_radio_mode_state_0003e318[2].flags_0x2 & 0xdf | 0x20;
      modem_fm_ptt_set(1);
      audio_pa_enable_gate(1);
      radio_init_sequence();
      fd6818b_reg50_tx_audio_mute_set();
      if (*(char *)((int)PTR_DAT_03068618 + 3) == '\x01') {
        local_beep_tone_burst();
      }
      else {
        local_beep_frontend_init_and_burst();
      }
      puVar1 = PTR_DAT_0306867c;
      *(byte *)PTR_DAT_0306867c = *(byte *)PTR_DAT_0306867c & 0xef;
      PTR_DAT_03068680[0x16] = PTR_DAT_03068680[0x16] & 0xdf;
      *(undefined1 *)((int)puVar1 + 3) = 0;
      modem_fm_ptt_set(0);
      dac_channel2_write_from_byte(0);
      OSTimeDly_ms_wrapper(0x1e);
      pa_band_select_vhf_uhf_gpio(0);
      *(byte *)PTR_call_active_flag_03068684 = *(byte *)PTR_call_active_flag_03068684 & 0xf7;
      channel_change_apply_squelch();
      if (*(char *)((int)puVar1 + 2) != '\0') {
        flash_quad_enable_and_system_reset();
      }
    }
  }
  return;
}


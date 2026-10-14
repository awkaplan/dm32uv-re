/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_freq_display_refresh @ 03015050 (file base 0x03000000; code starts at 0x03001000)
 * Size: 602 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_freq_display_refresh(void)

{
  bool bVar1;
  undefined1 *puVar2;
  radio_mode_state_0003e318 *prVar3;
  undefined4 *puVar4;
  int iVar5;
  byte bVar6;
  undefined1 auStack_c [4];
  
  p_vfo_freq_display_state->field_0xd = p_vfo_freq_display_state->field_0xd & 0xfe;
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    if (*(char *)PTR_DAT_030151f4 == '\0') {
      if ((*(byte *)p_call_active_flag & 8) != 0) {
        if (((PTR_DAT_030151fc[1] & 1) == (byte)p_dm32_settings_block04[0x2d] >> 7) &&
           ((iVar5 = vfo_active_side_mode_nibble(), iVar5 == 0 || (iVar5 == 2)))) {
          display_update_tone_signaling_icon(0);
        }
        if (((*(byte *)PTR_DAT_03015204 & 8) == 0) || ((PTR_DAT_030151fc[1] & 1) != 0)) {
          if ((*(byte *)PTR_DAT_03015204 & 0x10) == 0) {
            bVar1 = false;
          }
          else {
            bVar1 = (PTR_DAT_030151fc[1] & 1) != 0;
          }
        }
        else {
          bVar1 = true;
        }
        iVar5 = get_current_mode_state1();
        puVar2 = PTR_DAT_030151fc;
        if (((iVar5 == 0) &&
            (*(int *)&p_vfo_display_state->field_0x4_0 != *(int *)p_vfo_display_state)) && (!bVar1))
        {
          if ((((p_dm32_settings_block04[0x2d] & 0x24) == 4) ||
              ((p_dm32_settings_block04[0x2d] & 4) == 0)) || (p_dm32_settings_block04[0x6c] == '\0')
             ) {
            display_clear_channel_row_background(PTR_DAT_030151fc[1] & 1,1);
            display_draw_channel_frequency(puVar2[1] & 1,*(undefined4 *)p_vfo_display_state);
          }
          else {
            display_draw_frequency(PTR_DAT_030151fc[1] & 1);
          }
        }
      }
    }
    else {
      write_field_and_mbox_post(1,100);
    }
  }
  prVar3 = p_radio_mode_state_0003e318;
  if ((((p_radio_mode_state_0003e318[1].flags_0x6 & 0x10) == 0) &&
      ((p_radio_mode_state_0003e318->flags_0x4 & 4) == 0)) &&
     (((p_vfo_display_state->flags_0x8 & 0xf0) == 0 && ((*(byte *)p_call_active_flag & 8) != 0)))) {
    bVar6 = p_vfo_display_state->field_0x16 & 0xe;
    if (bVar6 == 2) {
      bVar6 = p_vfo_display_state->field_0x19 & 0xc;
      if ((bVar6 == 8) || (bVar6 == 0xc)) {
        operating_mode_set_and_notify(1);
        mutex_pend_no_timeout_03060f1c();
      }
    }
    else if (bVar6 == 8) {
      if ((PTR_DAT_03015394[1] == '\0') && (((byte)p_vfo_display_state[0x19] >> 2 & 2) != 0)) {
        p_radio_mode_state_0003e318[2].field_0x1 =
             p_radio_mode_state_0003e318[2].field_0x1 & 0x7f | 0x80;
        tone_gen_config_apply(0x100);
        prVar3[2].field_0x1 = prVar3[2].field_0x1 & 0x7f;
      }
    }
    else if (((bVar6 == 6) && (((byte)p_vfo_display_state[0x19] >> 2 & 2) != 0)) &&
            (PTR_DAT_03015394[1] == '\0')) {
      dtmf_tone_playback_from_i2c_code(2);
    }
  }
  *(byte *)PTR_DAT_030153a0 = *(byte *)PTR_DAT_030153a0 & 0x7f;
  PTR_DAT_030153a4[1] = PTR_DAT_030153a4[1] & 0xfc;
  puVar4 = PTR_DAT_030153a0;
  if ((PTR_DAT_030153a8[7] & 2) != 0) {
    *(byte *)((int)PTR_DAT_030153a0 + 5) = *(byte *)((int)PTR_DAT_030153a0 + 5) & 0xfb | 4;
    osflag_pend_consume_with_decisecond_timeout_alt(0x1000,0,0,auStack_c);
    os_flag_post_clear_0300c8d4(0x1000);
    *(byte *)((int)puVar4 + 5) = *(byte *)((int)puVar4 + 5) & 0xfb;
  }
  OSFlagPost_wrapper_set(p_ucos_flaggrp_0003a4f0,0x10);
  return;
}


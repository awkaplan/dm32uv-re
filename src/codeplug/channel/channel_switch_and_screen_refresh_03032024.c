/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_switch_and_screen_refresh @ 03032024 (file base 0x03000000; code starts at 0x03001000)
 * Size: 900 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_switch_and_screen_refresh(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  tx_ptt_ui_state *ptVar4;
  radio_mode_state_0003e318 *prVar5;
  uint uVar6;
  int iVar7;
  
  channel_switch_display_reset();
  rx_forbid_flag_conditional_clear();
  if (((p_vfo_display_state->flags_0x8 & 0xf0) == 0) && ((*(byte *)p_call_active_flag & 8) != 0)) {
    channel_switch_teardown_and_apply(1);
  }
  if ((*(byte *)p_call_active_flag & 1) != 0) {
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfe;
    ptVar4 = p_tx_ptt_ui_state;
    p_tx_ptt_ui_state->field_0x5f = p_tx_ptt_ui_state->field_0x5f & 0xfe;
    memset_bytes(&ptVar4->field_0x3f,0,0x20);
    memset_bytes(DAT_03032180,0,0x20);
  }
  if (PTR_DAT_03032184[0x328] == '\x01') {
    PTR_DAT_03032188[10] = PTR_DAT_03032188[10] & 0xfe | 1;
    dialog_history_show_if_present();
    PTR_DAT_03032184[0x328] = 0;
  }
  config_table_entry_0x30_init_sequence();
  unresolved_callee_pair_wrapper();
  if ((p_dialog_flags_from_flash->flags_0x1 & 4) != 0) {
    dialog_clear_flag_bit2_at_1();
  }
  bVar1 = p_radio_mode_state_0003e318->field_0x1;
  if ((bVar1 == 1) || (bVar1 == 9)) {
    if ((p_radio_mode_state_0003e318[1].flags_0x3 & 2) != 0) {
      p_radio_mode_state_0003e318[1].flags_0x3 = p_radio_mode_state_0003e318[1].flags_0x3 & 0xfd;
      sysctl_0x384_bit8_toggle_with_companion_byte();
    }
    if ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0) {
      uVar6 = channel_list_index_resolve
                        (*(undefined1 *)((int)p_dm32_settings_block04 + 0x29),
                         *(undefined1 *)((int)p_dm32_settings_block04 + 0x26));
    }
    else {
      uVar6 = (uint)*(byte *)((int)p_dm32_settings_block04 + 0x26);
    }
    PTR_DAT_03032198[2] = (char)uVar6;
  }
  else if (bVar1 == 0x12) {
    if ((PTR_DAT_0303219c[1] & 1) == 0) {
      uVar6 = channel_list_index_resolve
                        (*(undefined1 *)p_dm32_settings_block04,
                         *(undefined1 *)((int)p_dm32_settings_block04 + 0x26));
    }
    else {
      uVar6 = channel_list_index_resolve
                        (*(undefined1 *)((int)p_dm32_settings_block04 + 0x13),
                         *(undefined1 *)((int)p_dm32_settings_block04 + 0x26));
    }
  }
  else if (bVar1 == 2) {
    uVar6 = (uint)*(ushort *)&p_vfo_freq_display_state->field_0x14_0;
  }
  else if (bVar1 == 0x1a) {
    uVar6 = (uint)*(ushort *)&p_vfo_freq_display_state->field_0x14_0;
  }
  else if (bVar1 == 4) {
    uVar6 = (uint)*(ushort *)&p_dialog_flags_from_flash->field_0x34_0;
  }
  else if (bVar1 == 0x14) {
    uVar6 = (uint)(ushort)PTR_DAT_030321a4[1];
  }
  else if (bVar1 == 0x16) {
    uVar6 = (uint)(ushort)PTR_DAT_0303230c[1];
  }
  else if (bVar1 == 0xc) {
    uVar6 = (uint)*DAT_03032310;
  }
  else if (bVar1 == 0xd) {
    if ((PTR_DAT_03032314[1] & 1) == 0) {
      uVar6 = channel_list_index_resolve
                        (*(undefined1 *)p_dm32_settings_block04,
                         *(undefined1 *)((int)p_dm32_settings_block04 + 0x26));
    }
    else {
      uVar6 = channel_list_index_resolve
                        (*(undefined1 *)((int)p_dm32_settings_block04 + 0x13),
                         *(undefined1 *)((int)p_dm32_settings_block04 + 0x26));
    }
  }
  else {
    iVar7 = keypad_dispatch_not_inhibited();
    if (iVar7 == 0) {
      uVar6 = (uint)*(ushort *)&p_vfo_freq_display_state->field_0x54_0;
    }
    else {
      uVar6 = channel_list_index_resolve
                        (*(undefined1 *)((int)p_dm32_settings_block04 + 0x29),
                         *(undefined1 *)((int)p_dm32_settings_block04 + 0x26));
    }
  }
  prVar5 = p_radio_mode_state_0003e318;
  channel_load_synchronized(uVar6,p_radio_mode_state_0003e318->field_0x1);
  bVar1 = prVar5->flags_0x3;
  if (((*(byte *)PTR_DAT_03032324 & 2) == 0) &&
     (((bVar2 = prVar5->field_0x1, bVar2 == 1 || (bVar2 == 9)) || (bVar2 == 10)))) {
    zone_change_key_handler(0);
    prVar5 = p_radio_mode_state_0003e318;
    p_radio_mode_state_0003e318[1].flags_0x6 = p_radio_mode_state_0003e318[1].flags_0x6 & 0x3f;
    PTR_DAT_03032328[1] = 0;
    prVar5[2].flags_0x2 = prVar5[2].flags_0x2 & 0xe7;
  }
  OSFlagPost_wrapper_set(p_ucos_flaggrp_0003fd90,4);
  if ((*(byte *)PTR_DAT_03032324 & 2) == 0) {
    bVar2 = p_radio_mode_state_0003e318->field_0x1;
    if (((bVar2 == 1) || (bVar2 == 9)) || ((bVar2 == 0x10 || (bVar2 == 0x11)))) {
      dialog_close_reset();
      if ((*(char *)PTR_DAT_03032330 == '\0') &&
         ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0)) {
        bVar3 = false;
      }
      else {
        write_field_and_mbox_post(1,100);
        bVar3 = true;
      }
      if ((*(byte *)PTR_DAT_03032324 & 2) == 0) {
        if (p_radio_mode_state_0003e318->field_0x1 != 1) goto LAB_030322e6;
        if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) != 0) {
          bVar2 = 1;
          if ((*(byte *)((int)p_dm32_settings_block04 + 0x5d) & 1) == 0) goto LAB_0303233e;
          ui_event_notify(0x20);
        }
      }
    }
    else {
      bVar3 = false;
LAB_030322e6:
      if (((p_radio_mode_state_0003e318->flags_0x3 & 0x40) != 0) &&
         ((*(byte *)((int)p_dm32_settings_block04 + 0x5d) & 1) != 0)) {
        ui_event_notify(0x20);
      }
    }
  }
  else {
    bVar3 = false;
  }
  bVar2 = p_radio_mode_state_0003e318->field_0x1;
  if (bVar2 == 8) {
    return;
  }
LAB_0303233e:
  if (!bVar3) {
    if ((bVar2 == 3) || ((bVar1 >> 6 & 1) != 0)) {
      if ((*(byte *)PTR_DAT_030324d8 & 4) == 0) {
        display_draw_status_bar();
        vfo_screen_redraw();
      }
    }
    else if (bVar2 == 4) {
      if (*(char *)PTR_DAT_030324dc != '\0') {
        write_field_and_mbox_post(1,100);
      }
    }
    else if (bVar2 == 10) {
      if ((p_radio_mode_state_0003e318[1].flags_0x3 & 2) != 0) {
        p_radio_mode_state_0003e318[1].flags_0x3 = p_radio_mode_state_0003e318[1].flags_0x3 & 0xfd;
        sysctl_0x384_bit8_toggle_with_companion_byte();
      }
      display_draw_status_bar();
      if (p_dm32_settings_block04[0x6c] == '\0') {
        vfo_screen_redraw();
      }
      else {
        vfo_active_side_icon_draw((byte)p_dm32_settings_block04[0x2d] >> 7);
      }
    }
    else if ((((1 < (byte)(bVar2 - 0x12)) && (bVar2 != 0xd)) && (3 < (byte)(bVar2 - 0x14))) &&
            ((1 < (byte)(bVar2 - 0x18) && (*(char *)PTR_DAT_030324dc == '\0')))) {
      if (bVar2 == 0x1a) {
        display_clear_channel_row_background((byte)p_dm32_settings_block04[0x2d] >> 7,0);
      }
      channel_display_screen();
    }
  }
  return;
}


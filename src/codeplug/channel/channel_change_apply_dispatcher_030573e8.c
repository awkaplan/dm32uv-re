/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_change_apply_dispatcher @ 030573e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 3184 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_change_apply_dispatcher(short param_1,char param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  radio_mode_state_0003e318 *prVar4;
  undefined1 *puVar5;
  tx_ptt_ui_state *ptVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  byte bVar10;
  uint local_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined2 uStack_b8;
  undefined1 uStack_b6;
  undefined4 uStack_b4;
  undefined1 auStack_b0 [52];
  ushort local_7c [2];
  undefined1 auStack_78 [4];
  byte bStack_74;
  byte bStack_73;
  undefined1 auStack_69 [3];
  char cStack_66;
  int local_5c;
  int iStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint3 uStack_34;
  undefined1 uStack_31;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  short local_28;
  undefined1 local_26 [2];
  
  prVar4 = p_radio_mode_state_0003e318;
  local_28 = 0;
  local_5c = 0;
  iStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  _uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = uStack_2c & 0xff000000;
  p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xef;
  prVar4->flags_0x4 = prVar4->flags_0x4 & 0xf7 | 8;
  tx_timeout_cleanup();
  if ((*(byte *)p_call_active_flag & 4) != 0) {
    *(byte *)PTR_DAT_030575f8 = *(byte *)PTR_DAT_030575f8 & 0xdf;
    tx_abort_reset();
  }
  if ((param_2 == '\x01') || (param_2 == '\t')) {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      *(byte *)PTR_DAT_03057600 = *(byte *)PTR_DAT_03057600 & 0xf7;
    }
    else {
      *(byte *)PTR_DAT_03057600 = *(byte *)PTR_DAT_03057600 & 0xef;
    }
  }
  puVar5 = p_dm32_settings_block04;
  if (((*(byte *)PTR_DAT_03057600 & 8) == 0) || ((PTR_DAT_03057604[1] & 1) != 0)) {
    if ((*(byte *)PTR_DAT_03057600 & 0x10) == 0) {
      bVar1 = false;
    }
    else {
      bVar1 = (PTR_DAT_03057604[1] & 1) != 0;
    }
  }
  else {
    bVar1 = true;
  }
  if (param_2 == '\x04') {
    if (*(short *)&p_dialog_flags_from_flash->field_0x34_0 == 0) {
      if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
        channel_freq_record_build_from_flash(auStack_b0,(byte)p_dm32_settings_block04[0x2d] >> 7);
        memcpy_ck803s(&local_5c,auStack_b0,0x33);
      }
      else {
        channel_num_to_block_offset
                  (*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0,local_26,&local_28);
        flash_field_read_cached(local_26[0],local_28,local_7c,0x20);
        memcpy_bytes_iram(&uStack_54,&bStack_74,0x18);
        local_5c = bcd_frequency_decode(local_7c,4);
        iStack_58 = bcd_frequency_decode(auStack_78,4);
      }
      goto LAB_03057900;
    }
    channel_num_to_block_offset(param_1,local_26,&local_28);
    flash_field_read_cached(local_26[0],local_28,local_7c,0x20);
    memcpy_bytes_iram(&uStack_54,&bStack_74,0x18);
    local_5c = bcd_frequency_decode(local_7c,4);
    iStack_58 = bcd_frequency_decode(auStack_78,4);
  }
  else if ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0) {
    if (param_2 == '\x18') {
      memcpy_ck803s(&local_5c,p_vfo_display_state,0x33);
      local_28 = ((byte)PTR_DAT_030577bc[*(byte *)PTR_DAT_030577b8 + 8] - 1) * 0x1a + 0x10;
      flash_field_read_cached(0x66,local_28,local_7c,10);
      local_5c = bcd_frequency_decode(local_7c,4);
      iStack_58 = bcd_frequency_decode(auStack_78,4);
      uStack_54 = uStack_54 & 0xffffff0f | 0x10;
      bVar10 = SUBPIECE(uStack_50, 1, 1) & 0xc0;
      SUBPIECE_SET(uStack_50, 0, 2, CONCAT11(bVar10 | bStack_74 & 0xf | (bStack_73 & 1) << 4,(byte)uStack_50));
      goto LAB_03057900;
    }
    if (bVar1) {
      if ((((byte)(param_2 - 0x12U) < 2) || (param_2 == '\n')) || (param_2 == '\b')) {
        if ((PTR_DAT_030577c0[1] & 1) == 0) {
          memcpy_ck803s(&local_5c,DAT_030577c4,0x33);
        }
        else {
          memcpy_ck803s(&local_5c,PTR_DAT_030577b0,0x33);
        }
      }
      else {
        if ((1 < (byte)(param_2 - 0x10U)) && (param_2 != '\x17')) goto LAB_03057706;
        if ((PTR_DAT_030577c0[1] & 1) == 0) {
          memcpy_ck803s(&local_5c,DAT_030577c4,0x33);
        }
        else {
          memcpy_ck803s(&local_5c,PTR_DAT_030577b0,0x33);
        }
      }
    }
    else {
LAB_03057706:
      if (((p_dm32_settings_block04[0x2d] & 4) == 0) && ((param_2 != '\x14' && (param_2 != '\x16')))
         ) {
        if ((param_2 == '\x12') || (param_2 == '\r')) {
          channel_freq_record_build_from_flash(auStack_b0,PTR_DAT_030579c0[1] & 1);
          memcpy_ck803s(&local_5c,auStack_b0,0x33);
        }
        else {
          channel_freq_record_build_from_flash(auStack_b0,(byte)p_dm32_settings_block04[0x2d] >> 7);
          memcpy_ck803s(&local_5c,auStack_b0,0x33);
        }
        if (param_2 == '\x02') {
          frequency_band_range_check_and_status_set(local_5c,iStack_58);
          local_5c = channel_frequency_step_clamp
                               (*(undefined4 *)p_vfo_display_state,
                                p_vfo_freq_display_state->field_0x5d & 1);
          goto LAB_03057900;
        }
        uVar9 = get_current_mode_state1();
        if (2 < uVar9) {
          iVar7 = *(int *)p_vfo_display_state;
          uVar8 = *(undefined4 *)&p_vfo_display_state->field_0x4_0;
          SUBPIECE_SET(uVar2, 0, 1, p_vfo_display_state->flags_0x8);
          SUBPIECE_SET(uVar2, 1, 1, p_vfo_display_state->flags_0x9);
          SUBPIECE_SET(uVar2, 2, 1, p_vfo_display_state->field_0xa);
          SUBPIECE_SET(uVar2, 3, 1, p_vfo_display_state->field_0xb);
          SUBPIECE_SET(uVar3, 0, 1, p_vfo_display_state->field_0xc);
          SUBPIECE_SET(uVar3, 1, 1, p_vfo_display_state->flags_0xd);
          SUBPIECE_SET(uVar3, 2, 1, p_vfo_display_state->field_0xe);
          SUBPIECE_SET(uVar3, 3, 1, p_vfo_display_state->field_0xf);
          local_5c = iVar7;
          memcpy_ck803s(&local_d8,&p_vfo_display_state->field_0x10,0x23);
          iStack_58 = channel_apply_frequency_offset(iVar7,uVar8,uVar2,uVar3);
        }
      }
      else if ((ushort)(param_1 - 1U) < 4000) {
        channel_num_to_block_offset(param_1,local_26,&local_28);
        flash_field_read_cached(local_26[0],local_28,local_7c,0x20);
        memcpy_bytes_iram(&uStack_54,&bStack_74,0x18);
        local_5c = bcd_frequency_decode(local_7c,4);
        iStack_58 = bcd_frequency_decode(auStack_78,4);
      }
      else {
        if ((param_2 == '\x16') && ((ushort)(param_1 - 0xfa1U) < 2)) {
          if (param_1 == 0xfa1) {
            channel_freq_record_build_from_flash(auStack_b0,0);
            memcpy_ck803s(&local_5c,auStack_b0,0x33);
          }
          else {
            channel_freq_record_build_from_flash(auStack_b0,1);
            memcpy_ck803s(&local_5c,auStack_b0,0x33);
          }
          goto LAB_03057900;
        }
        local_5c = 0;
        iStack_58 = 0;
      }
    }
  }
  else {
    memcpy_bytes_iram(local_7c,PTR_LAB_03057610 + ((byte)p_dm32_settings_block04[0x26] - 1) * 4,4);
    local_5c = bcd_frequency_decode(local_7c,4);
    uStack_54 = uStack_54 & 0xffff7f07 | 0x8008;
    if ((puVar5[0x2d] & 0x80) == 0) {
      uStack_50 = CONCAT31(SUBPIECE(uStack_50, 1, 3),(byte)uStack_50 & 0xf | PTR_DAT_03057614[0xc] & 0xf0);
    }
    else {
      uStack_50 = CONCAT31(SUBPIECE(uStack_50, 1, 3),(byte)uStack_50 & 0xf | PTR_DAT_030577b0[0xc] & 0xf0);
    }
  }
  if ((param_2 == '\r') && (bVar1)) {
    if ((PTR_DAT_030579c0[1] & 1) == 0) {
      memcpy_ck803s(&local_5c,DAT_030579d0,0x33);
    }
    else {
      memcpy_ck803s(&local_5c,DAT_030579d4,0x33);
    }
  }
LAB_03057900:
  frequency_band_range_check_and_status_set(local_5c,iStack_58);
  if ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) != 0) {
    uStack_54 = uStack_54 & 0xffffff07 | 8;
  }
  if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
    if (((((param_2 == '\x01') || (param_2 == '\b')) || (param_2 == '\t')) || (param_2 == '\n')) &&
       (PTR_DAT_03057b74[0xd8] = PTR_DAT_03057b74[0xd8] & 0x7f,
       (p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
      *(byte *)PTR_DAT_03057b7c = *(byte *)PTR_DAT_03057b7c & 0xfb;
      flash_field_read_cached(0x65,0,local_7c,2);
      if ((((local_7c[0] & 0x100) == 0) || (*(char *)((int)PTR_DAT_03057b7c + 5) == '\0')) ||
         (((*(byte *)((int)PTR_DAT_03057b80 + 3) & 1) == 0 || ((uStack_54 & 8) != 0)))) {
        *(byte *)PTR_DAT_03057b7c = *(byte *)PTR_DAT_03057b7c & 0xfe;
      }
      else {
        *(byte *)PTR_DAT_03057b7c = *(byte *)PTR_DAT_03057b7c & 0xfe | 1;
      }
      bVar10 = (byte)uStack_54 & 0xf0;
      if (((uStack_54 & 0xf0) == 0) || (bVar10 == 0x20)) {
        *(byte *)PTR_DAT_03057b7c = *(byte *)PTR_DAT_03057b7c & 0xfe;
      }
      if ((*(byte *)PTR_DAT_03057b80 & 4) == 0) {
        *(byte *)PTR_DAT_03057b84 = *(byte *)PTR_DAT_03057b84 & 0xfe;
      }
      else if (((uStack_50 & 0xc) == 4) && ((bVar10 == 0x10 || (bVar10 == 0x30)))) {
        *(byte *)PTR_DAT_03057b84 = *(byte *)PTR_DAT_03057b84 & 0xfe | 1;
        if (7 < (byte)uStack_4c) {
          uStack_4c = uStack_4c & 0xffffff00;
        }
        flash_field_read_cached(4,((uStack_4c & 0xff) + 400) * 2,local_7c,2);
        PTR_DAT_03057b84[1] = local_7c[0];
      }
      else {
        *(byte *)PTR_DAT_03057b84 = *(byte *)PTR_DAT_03057b84 & 0xfe;
      }
    }
    if (local_5c == iStack_58) {
      uStack_54 = uStack_54 & 0xff77ffff | 0x800000;
    }
    if (((uStack_54 & 0x800000) == 0) &&
       ((p_radio_mode_state_0003e318->field_0x1 == 0x10 || ((uStack_54 & 0x80000) != 0)))) {
      iStack_58 = local_5c;
      uVar9 = uStack_4c >> 8 & 0xffff;
      uStack_4c = CONCAT13((char)uVar9,(undefined3)uStack_4c);
      uStack_48 = CONCAT31(SUBPIECE(uStack_48, 1, 3),(char)(uVar9 >> 8));
    }
    dialog_state_set_bit_0301ecc4((byte)uStack_54 >> 3 & 1);
    if (param_2 == '\x04') {
      uStack_2c = uStack_2c & 0xff0000ff |
                  (uint)*(ushort *)&p_dialog_flags_from_flash->field_0x36_0 << 8;
    }
    else if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
      if ((PTR_DAT_03057d7c[5] & 1) == 0) {
        uVar9 = vfo_tx_contact_field_read_wrapper((byte)p_dm32_settings_block04[0x2d] >> 7);
        uStack_2c = uStack_2c & 0xff0000ff | (uVar9 & 0xffff) << 8;
      }
      else {
        uVar9 = vfo_tx_contact_field_read_wrapper(PTR_DAT_03057d80[1] & 1);
        uStack_2c = uStack_2c & 0xff0000ff | (uVar9 & 0xffff) << 8;
      }
    }
    else {
      uVar9 = vfo_channel_apply_delegate(param_1);
      uStack_2c = uStack_2c & 0xff0000ff | (uVar9 & 0xffff) << 8;
    }
    if ((p_dm32_settings_block04[0x2d] & 4) != 0) {
      channel_record_read_full(param_1,&uStack_3c);
    }
    if (param_2 == '\x04') {
      uStack_54 = uStack_54 & 0xfffffff9 | 4;
    }
    if ((uStack_54 & 0x80000000) == 0) {
      uStack_54 = uStack_54 & 0xbfffffff;
    }
    noop_stub_03060e80(&local_5c);
    if (param_2 != '\x14') {
      if ((((param_2 == '\x01') || (param_2 == '\f')) || (param_2 == '\b')) || (param_2 == '\t')) {
        uStack_b4 = 1;
        local_d8 = uStack_4c;
        uStack_d4 = uStack_48;
        uStack_d0 = uStack_44;
        uStack_cc = uStack_40;
        uStack_c8 = uStack_3c;
        uStack_c4 = uStack_38;
        uStack_c0 = _uStack_34;
        uStack_bc = uStack_30;
        uStack_b8 = (undefined2)uStack_2c;
        uStack_b6 = SUBPIECE(uStack_2c, 2, 1);
        commit_channel_record_dual_vfo(local_5c,iStack_58,uStack_54,uStack_50);
      }
      else if (((byte)(param_2 - 0x10U) < 2) && (iVar7 = is_memory_channel_not_vfo(), iVar7 == 0)) {
        uStack_b4 = 1;
        local_d8 = uStack_4c;
        uStack_d4 = uStack_48;
        uStack_d0 = uStack_44;
        uStack_cc = uStack_40;
        uStack_c8 = uStack_3c;
        uStack_c4 = uStack_38;
        uStack_c0 = _uStack_34;
        uStack_bc = uStack_30;
        uStack_b8 = (undefined2)uStack_2c;
        uStack_b6 = SUBPIECE(uStack_2c, 2, 1);
        commit_channel_record_dual_vfo(local_5c,iStack_58,uStack_54,uStack_50);
      }
      else {
        uStack_b4 = 0;
        local_d8 = uStack_4c;
        uStack_d4 = uStack_48;
        uStack_d0 = uStack_44;
        uStack_cc = uStack_40;
        uStack_c8 = uStack_3c;
        uStack_c4 = uStack_38;
        uStack_c0 = _uStack_34;
        uStack_bc = uStack_30;
        uStack_b8 = (undefined2)uStack_2c;
        uStack_b6 = SUBPIECE(uStack_2c, 2, 1);
        commit_channel_record_dual_vfo(local_5c,iStack_58,uStack_54,uStack_50);
      }
    }
    bVar10 = (byte)uStack_54 & 0xf0;
    if ((bVar10 == 0x20) || (bVar10 == 0x30)) {
      if (param_2 == '\r') {
        if ((PTR_DAT_03057d84[3] & 2) == 0) {
          PTR_DAT_03057f70[3] = PTR_DAT_03057f70[3] & 0xfd | 2;
          uStack_54 = uStack_54 & 0xffffff0f | 0x10;
          p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfd | 2
          ;
        }
        else {
          PTR_DAT_03057d84[3] = PTR_DAT_03057d84[3] & 0xfd;
          uStack_54 = uStack_54 & 0xffffff0f;
          p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfd;
        }
      }
      else if (param_2 == '\f') {
        if (bVar10 == 0x20) {
          PTR_DAT_03057f70[3] = PTR_DAT_03057f70[3] & 0xfd;
          uStack_54 = uStack_54 & 0xffffff0f;
          p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfd;
        }
        else {
          PTR_DAT_03057f70[3] = PTR_DAT_03057f70[3] & 0xfd | 2;
          uStack_54 = uStack_54 & 0xffffff0f | 0x10;
          p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfd | 2
          ;
        }
      }
      else {
        uStack_54 = uStack_54 & 0xffffff0f | 0x10;
        p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfd | 2;
        PTR_DAT_03057f70[3] = PTR_DAT_03057f70[3] & 0xfd | 2;
      }
      PTR_DAT_03057f70[3] = PTR_DAT_03057f70[3] & 0xfe | 1;
    }
    else {
      PTR_DAT_03057f70[3] = PTR_DAT_03057f70[3] & 0xfe;
    }
    p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf | (byte)uStack_54 & 0xf0;
    if ((uStack_54 & 0xf0) == 0) {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfd;
    }
    else {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xfd | 2;
    }
    channel_freq_pair_store(iStack_58,local_5c);
    tx_power_mode_apply_from_flags(&local_5c);
    if (((p_radio_mode_state_0003e318->flags_0x3 & 2) != 0) ||
       ((*(byte *)PTR_DAT_03057f7c & 2) != 0)) {
      record_read_by_index(uStack_2c >> 8 & 0xffff,local_7c);
      *PTR_DAT_03057f80 = 0;
      if (cStack_66 == '\x04') {
        memcpy_bytes_iram(PTR_DAT_03057f80,auStack_69,3);
      }
      channel_config_load_from_flash_and_apply(SUBPIECE(uStack_50, 3, 1) & 0x3f);
      dmr_privacy_key_load_and_mi_draw();
      if ((param_2 != '\x02') && (param_2 != '\x04')) {
        local_d8 = uStack_4c;
        uStack_d4 = uStack_48;
        uStack_d0 = uStack_44;
        uStack_cc = uStack_40;
        uStack_c8 = uStack_3c;
        uStack_c4 = uStack_38;
        uStack_c0 = _uStack_34;
        uStack_bc = uStack_30;
        uStack_b8 = (undefined2)uStack_2c;
        uStack_b6 = SUBPIECE(uStack_2c, 2, 1);
        dialog_flags_load_from_param_or_flash(local_5c,iStack_58,uStack_54,uStack_50);
      }
    }
    PTR_DAT_03057f84[0x32] = PTR_DAT_03057f84[0x32] & 0xfe | 1;
    freq_calibration_apply_all();
    iVar7 = get_current_mode_state2();
    if (iVar7 == 0) {
      bVar10 = SUBPIECE(uStack_48, 1, 1) >> 4 & 1;
      p_dm32_settings_block04[0x30] = p_dm32_settings_block04[0x30] & 0xfe | bVar10;
      PTR_DAT_03058114[2] = PTR_DAT_03058114[2] & 0xbf | bVar10 << 6;
    }
    else if ((PTR_DAT_03057f88[1] & 1) == (byte)p_dm32_settings_block04[0x2d] >> 7) {
      bVar10 = SUBPIECE(uStack_48, 1, 1) >> 4 & 1;
      p_dm32_settings_block04[0x30] = p_dm32_settings_block04[0x30] & 0xfe | bVar10;
      *(byte *)((int)PTR_DAT_03057f7c + 2) =
           *(byte *)((int)PTR_DAT_03057f7c + 2) & 0xbf | bVar10 << 6;
    }
    if ((param_2 != '\x14') && (param_2 != '\x16')) {
      channel_change_apply_squelch();
    }
    if (*(byte *)PTR_DAT_03058118 != (byte)uStack_54 >> 4) {
      *(byte *)PTR_DAT_03058118 = (byte)uStack_54 >> 4;
      tone_or_volume_step_lookup(*(undefined1 *)PTR_DAT_0305811c);
    }
    *(short *)&p_vfo_freq_display_state->field_0x54_0 = param_1;
    local_d8 = uStack_4c;
    uStack_d4 = uStack_48;
    uStack_d0 = uStack_44;
    uStack_cc = uStack_40;
    uStack_c8 = uStack_3c;
    uStack_c4 = uStack_38;
    uStack_c0 = _uStack_34;
    uStack_bc = uStack_30;
    uStack_b8 = (undefined2)uStack_2c;
    uStack_b6 = SUBPIECE(uStack_2c, 2, 1);
    channel_type_mode_settings_write(local_5c,iStack_58,uStack_54,uStack_50);
    if (((p_dm32_settings_block04[0x2d] & 4) != 0) || (param_2 != '\x02')) {
      rf_mode_transition_on_freq_delta(&local_5c);
    }
    if (((byte)uStack_54 & 0xf0) == 0x10) {
      write_byte_field_0300c3b4(SUBPIECE(uStack_54, 2, 1) >> 4 & 7);
      mmio_11000384_low_byte_write(SUBPIECE(uStack_50, 1, 1) & 0xf);
      uVar8 = flash_field_block67_signed_threshold_check(SUBPIECE(uStack_44, 3, 1));
      *PTR_DAT_03058124 = uVar8;
      call_setup_sm_aux_field24_store();
    }
    if ((uStack_54 & 0xf0) == 0) {
      if ((uStack_54 & 0x8000) == 0) {
        modem_fm_bandwidth_write_0x5f(0);
      }
      else {
        modem_fm_bandwidth_write_0x5f(1);
      }
      gpio_set_output_bit(0x2e);
      gpio_set_output_bit(0x2f);
    }
    else {
      modem_fm_bandwidth_write_0x5f(0);
      gpio_clear_output_bit(0x2e);
      gpio_clear_output_bit(0x2f);
    }
    status_byte_bit5_set_clear_wrapper((byte)uStack_54 >> 4,1);
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfe;
    prVar4 = p_radio_mode_state_0003e318;
    p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0xf7;
    *(undefined1 *)PTR_DAT_03058130 = 0;
    prVar4->flags_0x2 = prVar4->flags_0x2 & 0xef | 0x10;
    ptVar6 = p_tx_ptt_ui_state;
    p_tx_ptt_ui_state->field_0x5f = p_tx_ptt_ui_state->field_0x5f & 0xfe;
    memset_bytes(&ptVar6->field_0x3f,0,0x20);
    memset_bytes(DAT_03058138,0,0x20);
  }
  else {
    dtmf_digit_input_handler(0);
    p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0xf7;
    set_flag_byte_03064328(0);
    local_5c = 0;
    iStack_58 = 0;
    uStack_34 = (uint3)(ushort)uStack_34;
    uStack_50 = uStack_50 & 0xffffdfff;
    strcpy_ck803s(&uStack_3c,
                  **(undefined4 **)
                    (PTR_PTR_030579dc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    uStack_b4 = 0;
    local_d8 = uStack_4c;
    uStack_d4 = uStack_48;
    uStack_d0 = uStack_44;
    uStack_cc = uStack_40;
    uStack_c8 = uStack_3c;
    uStack_c4 = uStack_38;
    uStack_c0 = _uStack_34;
    uStack_bc = uStack_30;
    uStack_b8 = (undefined2)uStack_2c;
    uStack_b6 = SUBPIECE(uStack_2c, 2, 1);
    commit_channel_record_dual_vfo(local_5c,iStack_58,uStack_54,uStack_50);
  }
  return;
}


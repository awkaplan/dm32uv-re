/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: talker_alias_info_screen @ 0302ba20 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1708 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Removing unreachable block (ram,0x0302bf56) */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void talker_alias_info_screen(void)

{
  byte bVar1;
  ushort fg;
  undefined1 *puVar2;
  tx_ptt_ui_state *ptVar3;
  undefined2 *puVar4;
  vfo_display_state *pvVar5;
  short sVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  byte *text;
  undefined4 unaff_r8;
  undefined2 local_38;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_28;
  
  puVar2 = p_dm32_settings_block04;
  fg = PTR_DAT_0302bbf8[(byte)p_dm32_settings_block04[99]];
  display_draw_status_bar();
  *PTR_DAT_0302bbfc = (uint)(byte)puVar2[0x58];
  if ((PTR_DAT_0302bc00[3] & 1) != 0) {
    PTR_DAT_0302bc00[3] = PTR_DAT_0302bc00[3] & 0xbf | 0x40;
  }
  display_fill_screen(0);
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_update_datetime(0);
  text = DAT_0302bc08;
  if ((PTR_DAT_0302bc04[1] & 1) == 0) {
    text = PTR_LAB_0302bc0c;
  }
  display_draw_string_gb2312(0x122,0xc,text,fg,0);
  if ((p_tx_ptt_ui_state->flags_0xa & 0x40) != 0) {
    p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xbf;
  }
  if (((*(byte *)p_call_active_flag & 1) == 0) && (iVar7 = get_field_0301ea64_0x14(), iVar7 != 1)) {
    if (((*(byte *)p_call_active_flag & 2) == 0) && (iVar7 = get_field_0301ea64_0x14(), iVar7 != 2))
    {
      return;
    }
    bVar1 = p_tx_ptt_ui_state->field_0x1c;
    if (bVar1 == 1) {
      display_blit_image(0x54,0xf1,0x30,0x30,PTR_LAB_0302c074);
      iVar7 = 3;
    }
    else if (bVar1 == 2) {
      display_blit_image(0x54,0xf1,0x30,0x30,PTR_LAB_0302c240);
      iVar7 = 4;
    }
    else {
      if (bVar1 == 3) {
        iVar7 = 5;
      }
      else {
        iVar7 = 0;
      }
      display_blit_image(0x54,0xf1,0x30,0x30,PTR_LAB_0302c070);
    }
    display_blit_image(0x82,0xe1,0x40,0x40,PTR_LAB_0302c078);
    if ((*(byte *)p_call_active_flag & 2) != 0) {
      display_blit_image(0xa2,0xe9,0x17,0x17,PTR_LAB_0302c07c);
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfe | 1;
    }
    iVar9 = contact_name_lookup_or_format
                      (1,*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0,
                       &p_tx_ptt_ui_state->field_0x2e,iVar7);
    if (iVar9 == 0) {
      if (iVar7 == 3) {
        unaff_r8 = flash_binary_search_le_record
                             (*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0,
                              &p_tx_ptt_ui_state->field_0x2e);
      }
      else {
        p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xfe;
      }
      puVar4 = PTR_DAT_0302c088;
      if ((p_radio_mode_state_0003e318->flags_0x6 & 1) == 0) {
        display_draw_string_gb2312(0x28,10,p_caller_id_display_text,fg,0);
      }
      else {
        flash_talker_record_read(unaff_r8,PTR_DAT_0302c088);
        if (*(char *)(puVar4 + 10) == '\0') {
          number_to_string_format_2args
                    (&local_38,DAT_0302c08c,*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0);
        }
        else {
          number_to_string_format_2args
                    (&local_38,DAT_0302c090,*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0);
        }
        display_draw_string_gb2312(0x28,10,(byte *)&local_38,fg,0);
        sVar6 = strlen_ck803s(&local_38);
        puVar4 = PTR_DAT_0302c088;
        local_38 = PTR_DAT_0302c088[10];
        uStack_36 = *(undefined1 *)(PTR_DAT_0302c088 + 0xb);
        uStack_35 = *(undefined1 *)((int)PTR_DAT_0302c088 + 0x17);
        uStack_34 = *(undefined1 *)(PTR_DAT_0302c088 + 0xc);
        uStack_33 = *(undefined1 *)((int)PTR_DAT_0302c088 + 0x19);
        uStack_32 = *(undefined1 *)(PTR_DAT_0302c088 + 0xd);
        uStack_31 = *(undefined1 *)((int)PTR_DAT_0302c088 + 0x1b);
        uStack_30 = 0;
        display_draw_string_gb2312
                  (0x28,(sVar6 * 0xc & 0xfcU) + 10,(byte *)&local_38,
                   PTR_DAT_0302c098[(byte)p_dm32_settings_block04[0x62]],0);
        display_draw_string_gb2312(0x46,10,p_caller_id_display_text,0xffe0,0);
        memcpy_ck803s(&local_38,puVar4 + 0xe,0x10);
        uStack_28 = 0;
        display_draw_string_gb2312(100,10,(byte *)&local_38,fg,0);
        memcpy_ck803s(&local_38,puVar4 + 0x16,0x10);
        uStack_28 = 0;
        display_draw_string_gb2312(0x82,10,(byte *)&local_38,fg,0);
        memcpy_ck803s(&local_38,puVar4 + 0x1e,0x10);
        uStack_28 = 0;
        display_draw_string_gb2312(0xa0,10,(byte *)&local_38,fg,0);
      }
    }
    else {
      p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xfe;
      ptVar3 = p_tx_ptt_ui_state;
      number_to_string_format_2args
                (&local_38,DAT_0302c22c,*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0);
      display_draw_string_gb2312(0x28,10,(byte *)&local_38,fg,0);
      display_draw_string_gb2312(0x46,10,&ptVar3->field_0x2e,fg,0);
    }
    display_draw_string_gb2312
              (0xbe,10,*(byte **)(PTR_PTR_0302c234[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] +
                                 (iVar7 + -3) * 4),fg,0);
    pvVar5 = p_vfo_display_state;
    number_to_string_format_2args(&local_38,DAT_0302c23c,p_vfo_display_state->flags_0xd & 0xf);
    display_draw_string_gb2312(0xdc,10,(byte *)&local_38,fg,0);
    if ((pvVar5->flags_0xd & 0x10) == 0) {
      local_38 = 0x3154;
    }
    else {
      local_38 = 0x3254;
    }
    uStack_36 = 0;
    display_draw_string_gb2312(0xfa,0xf,(byte *)&local_38,fg,0);
    return;
  }
  bVar1 = p_tx_ptt_ui_state->field_0x14;
  if (bVar1 == 1) {
    display_blit_image(0x54,0xf1,0x30,0x30,PTR_LAB_0302bc1c);
    iVar7 = 3;
  }
  else if (bVar1 == 2) {
    display_blit_image(0x54,0xf1,0x30,0x30,PTR_LAB_0302c240);
    iVar7 = 4;
  }
  else {
    iVar7 = 0;
    if (bVar1 == 3) {
      iVar7 = 5;
    }
    display_blit_image(0x54,0xf1,0x30,0x30,PTR_LAB_0302bc18);
  }
  display_blit_image(0x82,0xe1,0x40,0x40,PTR_LAB_0302bc20);
  if ((*(byte *)p_call_active_flag & 1) != 0) {
    display_blit_image(0xa2,0xe9,0x17,0x17,PTR_LAB_0302bc24);
    p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfe | 1;
  }
  if (iVar7 == 4) {
    uVar8 = dialog_state_get_field_03020e28();
    iVar7 = contact_name_lookup_or_format(1,uVar8,&local_38,4);
    if (iVar7 == 0) {
      number_to_string_format_2args
                (&local_38,PTR_s__d_030afae0_8_0302bc28,
                 *(undefined4 *)&p_call_setup_sm_state->field_0xc_0);
    }
  }
  else {
    memcpy_bytes_iram(&local_38,
                      *(undefined4 *)
                       (PTR_PTR_0302bc30[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] +
                       (iVar7 + -3) * 4),0x10);
    if ((iVar7 == 3) && (*(int *)&p_call_setup_sm_state->field_0xc_0 != *PTR_DAT_0302bc34)) {
      number_to_string_format_2args(&local_38,PTR_s__d_030afae0_8_0302bc28);
    }
  }
  display_draw_string_gb2312(0xbe,10,(byte *)&local_38,fg,0);
  uVar8 = read_byte_field_03020e30();
  number_to_string_format_2args(&local_38,DAT_0302bc38,uVar8);
  display_draw_string_gb2312(0xdc,10,(byte *)&local_38,fg,0);
  if ((p_vfo_display_state->flags_0xd & 0x10) == 0) {
    local_38 = 0x3154;
  }
  else {
    local_38 = 0x3254;
  }
  uStack_36 = 0;
  display_draw_string_gb2312(0xfa,0xf,(byte *)&local_38,fg,0);
  iVar7 = contact_name_lookup_or_format
                    (1,*(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0,
                     &p_tx_ptt_ui_state->field_0x2e,3);
  if (iVar7 == 0) {
    unaff_r8 = flash_binary_search_le_record
                         (*(undefined4 *)&p_tx_ptt_ui_state->field_0x64_0,
                          &p_tx_ptt_ui_state->field_0x2e);
  }
  else {
    p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xfe;
  }
  puVar4 = PTR_DAT_0302be60;
  ptVar3 = p_tx_ptt_ui_state;
  if ((p_tx_ptt_ui_state->field_0x5f & 1) == 0) {
    if (iVar7 == 0) {
LAB_0302bcfa:
      if ((p_radio_mode_state_0003e318->flags_0x6 & 1) == 0) {
        display_draw_string_gb2312
                  (0x28,10,p_caller_id_display_text,fg,p_radio_mode_state_0003e318->flags_0x6 & 1);
        return;
      }
    }
    else {
LAB_0302bd18:
      if (iVar7 == 1) {
        number_to_string_format_2args
                  (&local_38,DAT_0302be58,*(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0);
        display_draw_string_gb2312(0x28,10,(byte *)&local_38,fg,0);
        display_draw_string_gb2312(0x46,10,&ptVar3->field_0x2e,fg,0);
        return;
      }
    }
    flash_talker_record_read(unaff_r8,PTR_DAT_0302be60);
    if (*(char *)(puVar4 + 10) == '\0') {
      number_to_string_format_2args
                (&local_38,DAT_0302be58,*(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0);
    }
    else {
      number_to_string_format_2args
                (&local_38,DAT_0302be64,*(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0);
    }
    display_draw_string_gb2312(0x28,10,(byte *)&local_38,fg,0);
    sVar6 = strlen_ck803s(&local_38);
    puVar4 = PTR_DAT_0302be60;
    local_38 = PTR_DAT_0302be60[10];
    uStack_36 = *(undefined1 *)(PTR_DAT_0302be60 + 0xb);
    uStack_35 = *(undefined1 *)((int)PTR_DAT_0302be60 + 0x17);
    uStack_34 = *(undefined1 *)(PTR_DAT_0302be60 + 0xc);
    uStack_33 = *(undefined1 *)((int)PTR_DAT_0302be60 + 0x19);
    uStack_32 = *(undefined1 *)(PTR_DAT_0302be60 + 0xd);
    uStack_31 = *(undefined1 *)((int)PTR_DAT_0302be60 + 0x1b);
    uStack_30 = 0;
    display_draw_string_gb2312
              (0x28,(sVar6 * 0xc & 0xfcU) + 10,(byte *)&local_38,
               PTR_DAT_0302be6c[(byte)p_dm32_settings_block04[0x62]],0);
    display_draw_string_gb2312(0x46,10,p_caller_id_display_text,0xffe0,0);
    memcpy_ck803s(&local_38,puVar4 + 0xe,0x10);
    uStack_28 = 0;
    display_draw_string_gb2312(100,10,(byte *)&local_38,fg,0);
    memcpy_ck803s(&local_38,puVar4 + 0x16,0x10);
    uStack_28 = 0;
    display_draw_string_gb2312(0x82,10,(byte *)&local_38,fg,0);
    memcpy_ck803s(&local_38,puVar4 + 0x1e,0x10);
    uStack_28 = 0;
    display_draw_string_gb2312(0xa0,10,(byte *)&local_38,fg,0);
  }
  else {
    if ((*(byte *)PTR_DAT_0302be50 & 2) == 0) {
      if (iVar7 != 0) goto LAB_0302bd18;
      if ((p_radio_mode_state_0003e318->flags_0x6 & 1) != 0) goto LAB_0302bcfa;
    }
    display_draw_glyph_row_mutex(0xa0,10,PTR_s_TalkerAlias_0302be54,fg,0);
    ptVar3 = p_tx_ptt_ui_state;
    number_to_string_format_2args
              (&local_38,DAT_0302be58,*(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0);
    display_draw_string_gb2312(0x28,10,(byte *)&local_38,fg,0);
    display_draw_string_gb2312(0x46,10,&ptVar3->field_0x3f,fg,0);
  }
  return;
}


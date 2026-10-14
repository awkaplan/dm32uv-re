/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_manual_freq_entry @ 03051ea4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 842 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_confirm_apply_manual_freq_entry(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  radio_mode_state_0003e318 *prVar4;
  vfo_display_state *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  byte *pbVar10;
  uint uVar11;
  undefined1 auStack_6c [52];
  short local_38;
  undefined1 local_36 [2];
  undefined1 auStack_34 [4];
  undefined4 local_30;
  byte local_2c [4];
  byte local_28 [4];
  byte abStack_24 [11];
  undefined1 auStack_19 [5];
  
  local_30 = 0;
  if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03052108 + 2) == '\x01') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0305210c + 2);
    if (cVar1 == '\f') {
      if (p_menu_screen_state->index_0x6 < *(byte *)PTR_DAT_03052110) {
        flash_block_read_modify_write_96b
                  (*(undefined1 *)PTR_DAT_03052118,p_menu_screen_state->index_0x6 + 1);
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_03052128 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        history_record_lookup_by_type(6,*(short *)PTR_DAT_03052114 + 1,local_2c);
        memcpy_bytes_iram(&local_30,auStack_19,3);
        iVar6 = flash_field_contains_value(*(undefined1 *)PTR_DAT_03052118,local_30);
        if (iVar6 == 0) {
          recent_value_list_append_to_flash(*(undefined1 *)PTR_DAT_03052118,local_30);
          dialog_show_icon_and_number
                    (1,**(undefined4 **)
                         (PTR_PTR_03052124 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          dialog_show_icon_and_number
                    (0,**(undefined4 **)
                         (PTR_PTR_03052120 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
      }
    }
    else if (cVar1 == '\r') {
      bVar9 = *(byte *)PTR_DAT_0305212c;
      if (2 < bVar9) {
        if (bVar9 == 0) {
          uVar11 = 0;
        }
        else {
          uVar11 = 0;
          uVar8 = DAT_03052134;
          pbVar10 = PTR_DAT_03052130;
          do {
            uVar11 = uVar11 + uVar8 * (*pbVar10 - 0x30);
            uVar8 = uVar8 / 10;
            pbVar10 = pbVar10 + 1;
          } while (pbVar10 != PTR_DAT_03052130 + (byte)(bVar9 - 1) + 1);
        }
        if ((((uint)*PTR_DAT_03052138 <= uVar11) && (uVar11 <= (uint)PTR_DAT_03052138[1])) ||
           (((uint)PTR_DAT_03052138[2] <= uVar11 && (uVar11 <= (uint)PTR_DAT_03052138[3])))) {
          OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_34);
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,PTR_DAT_03052148,
                     **(undefined4 **)
                       (PTR_PTR_03052140 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                     PTR_LAB_03052144);
          prVar4 = p_radio_mode_state_0003e318;
          *(short *)&p_radio_mode_state_0003e318[1].field_0x8 =
               *(short *)&p_radio_mode_state_0003e318[1].field_0x8 + 1;
          flash_block_write(0x12,0,&prVar4[1].field_0x8,2);
          SUBPIECE_SET(uVar2, 0, 1, prVar4[1].field_0x8);
          SUBPIECE_SET(uVar2, 1, 1, prVar4[1].field_0x9);
          channel_offset_from_num(uVar2,local_36,&local_38);
          flash_block_write(local_36[0],local_38,p_text_entry_buffer,0x10);
          pvVar5 = p_vfo_display_state;
          uVar8 = *PTR_DAT_03052154;
          *(char *)p_vfo_display_state = (char)uVar8;
          pvVar5->field_0x1 = (byte)(uVar8 >> 8);
          pvVar5->field_0x2 = (byte)(uVar8 >> 0x10);
          pvVar5->field_0x3 = (byte)(uVar8 >> 0x18);
          pvVar5->field_0x4_0 = (byte)uVar11;
          pvVar5->field_0x5 = (char)(uVar11 >> 8);
          pvVar5->field_0x6 = (char)(uVar11 >> 0x10);
          pvVar5->field_0x7 = (char)(uVar11 >> 0x18);
          pbVar10 = local_28;
          do {
            uVar7 = (uVar11 % 100) / 10;
            *pbVar10 = (char)(uVar11 % 100) + (char)uVar7 * -10 | (byte)(uVar7 << 4);
            pbVar10 = pbVar10 + 1;
            uVar11 = uVar11 / 100;
          } while (pbVar10 != abStack_24);
          pbVar10 = local_2c;
          do {
            uVar11 = (uVar8 % 100) / 10;
            *pbVar10 = (char)(uVar8 % 100) + (char)uVar11 * -10 | (byte)(uVar11 << 4);
            pbVar10 = pbVar10 + 1;
            uVar8 = uVar8 / 100;
          } while (pbVar10 != local_28);
          SUBPIECE_SET(uVar3, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
          SUBPIECE_SET(uVar3, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
          channel_num_to_block_offset(uVar3,local_36,&local_38);
          pvVar5 = p_vfo_display_state;
          p_vfo_display_state->field_0x11_0 = 0xff;
          pvVar5->field_0x12 = 0xff;
          pvVar5->field_0x13_0 = 0xff;
          pvVar5->field_0x14 = 0xff;
          bVar9 = *(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_0305215c + 2);
          if (bVar9 < 4) {
            p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf | bVar9 << 4;
          }
          else {
            p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf;
          }
          pvVar5 = p_vfo_display_state;
          p_vfo_display_state->flags_0xd = p_vfo_display_state->flags_0xd & 0xf0 | 1;
          pvVar5->field_0xf = pvVar5->field_0xf & 0xbf;
          bVar9 = pvVar5->flags_0x8 & 0xf0;
          if ((bVar9 == 0x10) || (bVar9 == 0x30)) {
            p_vfo_display_state->flags_0x9 = p_vfo_display_state->flags_0x9 & 0x7f;
          }
          else {
            p_vfo_display_state->flags_0x9 = p_vfo_display_state->flags_0x9 & 0x7f | 0x80;
          }
          pvVar5 = p_vfo_display_state;
          p_vfo_display_state->field_0xc = p_vfo_display_state->field_0xc & 0xf | 0x10;
          flash_block_write(local_36[0],local_38,local_2c,8);
          flash_block_write(local_36[0],local_38 + 8,&pvVar5->flags_0x8,0x18);
          busy_wait_delay_loop_counted(auStack_6c);
          memcpy_ck803s(pvVar5,auStack_6c,0x33);
          dialog_show_icon_and_number
                    (1,**(undefined4 **)
                         (PTR_PTR_0305231c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
          history_queue_pop();
          history_queue_pop();
          history_queue_pop();
          return;
        }
      }
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_34);
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_0305232c,
                 **(undefined4 **)
                   (PTR_PTR_03052324 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 PTR_LAB_03052328);
      OSTimeDly_ms_wrapper(1000);
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03052330 + DAT_03052334),1);
    }
  }
  return;
}


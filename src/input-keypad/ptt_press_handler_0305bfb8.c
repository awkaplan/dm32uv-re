/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_press_handler @ 0305bfb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 2214 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ptt_press_handler(void)

{
  char cVar1;
  undefined1 *puVar2;
  vfo_display_state *pvVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  byte bVar9;
  undefined4 *puVar10;
  undefined1 uVar11;
  undefined4 *puVar12;
  int unaff_r8;
  undefined4 local_34;
  undefined1 auStack_30 [19];
  undefined1 auStack_1d [3];
  byte bStack_1a;
  
  local_34 = 0;
  get_current_mode_state1();
  bVar9 = p_radio_mode_state_0003e318->flags_0x7;
  if ((bVar9 & 0x18) != 0) {
    PTR_DAT_0305c100[5] = PTR_DAT_0305c100[5] & 0xfe;
    if ((bVar9 & 0x10) == 0) {
      format_and_write_status_field2(PTR_PTR_0305c10c[(byte)p_dm32_settings_block04[0x30] >> 6 & 1])
      ;
    }
    else {
      format_and_write_status_field2(PTR_PTR_0305c108[(byte)p_dm32_settings_block04[0x30] >> 6 & 1])
      ;
    }
    OSTimeDly_ms_wrapper(0x32);
    ui_event_notify(0x1b);
    return;
  }
  if ((*(byte *)p_call_active_flag & 1) == 0) {
    iVar6 = get_field_0301ea64_0x14();
    if (iVar6 == 0) {
      uVar11 = p_dm32_settings_block04[0x53];
    }
    else {
      uVar11 = 0;
    }
  }
  else {
    uVar11 = 0;
  }
  iVar6 = get_current_mode_state1();
  if ((iVar6 != 0) && (iVar6 = get_current_mode_state1(), iVar6 != 2)) {
    if (((p_vfo_freq_display_state->field_0xc & 2) == 0) &&
       ((p_dm32_settings_block04[0x2d] & 4) != 0)) {
      dtmf_digit_input_handler(6);
    }
    else {
      iVar6 = get_current_mode_state1();
      puVar10 = PTR_DAT_0305c118;
      if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
        puVar12 = PTR_DAT_0305c118 + -1;
        memcpy_bytes_iram(PTR_DAT_0305c118,puVar12,4);
        channel_freq_pair_store(*puVar10,*puVar12);
      }
      dtmf_digit_input_handler(6);
      if (iVar6 == 6) goto LAB_0305c148;
    }
    if ((p_dm32_settings_block04[0x2d] & 4) != 0) {
      bVar9 = p_vfo_freq_display_state->field_0x2 & 0xf0;
      if (bVar9 == 0x10) {
        *(undefined2 *)PTR_DAT_0305c11c = *(undefined2 *)&p_vfo_freq_display_state->field_0x56;
      }
      else if (bVar9 == 0x20) {
        *(undefined2 *)PTR_DAT_0305c27c = *(undefined2 *)&p_vfo_freq_display_state->field_0x6;
      }
      else {
        uVar5 = channel_list_index_resolve
                          (p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
        *(undefined2 *)PTR_DAT_0305c27c = uVar5;
      }
      ui_event_notify_alt(0xc);
    }
  }
LAB_0305c148:
  iVar6 = get_current_mode_state2();
  if ((((iVar6 != 0) && ((PTR_DAT_0305c284[5] & 1) == 0)) &&
      (iVar6 = get_current_mode_state2(), iVar6 != 4)) &&
     (iVar6 = get_current_mode_state1(), iVar6 == 0)) {
    iVar6 = get_current_mode_state2();
    puVar2 = PTR_DAT_0305c288;
    if (iVar6 == 3) {
      PTR_DAT_0305c288[0x1d] = 0;
      puVar2[0x1c] = 0;
    }
    else {
      mode_transition_cleanup();
    }
  }
  iVar6 = get_current_mode_state1();
  if (((iVar6 == 0) || (iVar6 = get_current_mode_state1(), iVar6 == 2)) &&
     ((iVar6 = tx_is_inhibited(), iVar6 == 0 && (iVar6 = read_byte_field_0305fca8(), iVar6 == 0))))
  {
    cVar4 = vfo_active_side_mode_nibble();
    p_vfo_display_state->flags_0x8 = p_vfo_display_state->flags_0x8 & 0xf | cVar4 << 4;
  }
  if ((PTR_DAT_0305c284[5] & 1) != 0) {
    iVar6 = get_current_mode_state2();
    if (iVar6 == 3) {
      set_flag_byte_03064328(1);
      display_refresh_tone_mode_icon();
    }
    iVar6 = get_current_mode_state2();
    if ((iVar6 != 0) && (iVar6 = get_current_mode_state2(), iVar6 != 4)) {
      set_flag_byte_03064328(3);
    }
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      PTR_DAT_0305c290[1] = PTR_DAT_0305c290[1] & 0xfe | 1;
    }
    else {
      PTR_DAT_0305c290[1] = PTR_DAT_0305c290[1] & 0xfe;
    }
    vfo_apply_active_side_config();
  }
  if ((PTR_DAT_0305c294[0x32] & 1) != 0) {
    freq_calibration_apply_all();
  }
  puVar10 = PTR_PTR_0305c444;
  if (((p_vfo_display_state->flags_0x8 & 8) == 0) && ((PTR_DAT_0305c284[4] & 0x40) == 0)) {
    if ((p_radio_mode_state_0003e318->flags_0x3 & 0x20) == 0) {
      if (p_tx_ptt_ui_state->field_0x7 == 5) {
        bStack_1a = 3;
        tx_key_from_vfo_mode_guard(3,*(undefined4 *)&p_dialog_flags_from_flash->field_0x24_0,uVar11)
        ;
      }
      else {
        bVar9 = p_vfo_display_state->flags_0x8 & 0xf0;
        if (((bVar9 == 0) || (bVar9 == 0x20)) && ((*(byte *)PTR_DAT_0305c458 & 0x20) != 0)) {
          bVar9 = p_vfo_display_state->field_0xa & 0x70;
          if (bVar9 == 0x10) {
            ui_event_notify(0x1b);
            *PTR_DAT_0305c460 = 0;
            format_and_write_status_field
                      (0x1d,10,**(undefined4 **)
                                 (PTR_PTR_0305c464 +
                                 ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
            return;
          }
          if (bVar9 == 0x20) {
            if ((PTR_DAT_0305c468[0x1d] & 2) == 0) {
              ui_event_notify(0x1b);
              *PTR_DAT_0305c460 = 0;
              format_and_write_status_field
                        (0x1d,10,**(undefined4 **)
                                   (PTR_PTR_0305c464 +
                                   ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
              return;
            }
          }
          else if ((bVar9 == 0x30) && ((PTR_DAT_0305c468[0x1d] & 2) != 0)) {
            ui_event_notify(0x1b);
            *PTR_DAT_0305c460 = 0;
            format_and_write_status_field
                      (0x1d,10,**(undefined4 **)
                                 (PTR_PTR_0305c464 +
                                 ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
            return;
          }
        }
        if ((p_tx_ptt_ui_state->field_0x7 == 4) && ((p_dialog_flags_from_flash->flags_0x1 & 3) == 2)
           ) {
          tx_key_from_vfo_mode_guard(4,*(undefined4 *)&p_dialog_flags_from_flash->field_0x8_0,0);
        }
        else {
          if ((*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0305c5bc + 2) == '\0') &&
             (bVar9 = *(byte *)PTR_DAT_0305c5c0, 3 < bVar9)) {
            cVar4 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0305c5c4 + 2);
            if (cVar4 == '\0') {
              unaff_r8 = contact_count_range_calc(p_vfo_display_state->flags_0x8 >> 4);
              pvVar3 = p_vfo_display_state;
              if ((unaff_r8 != 0) && (*(char *)PTR_DAT_0305c5d0 == '\0')) {
                history_record_lookup_by_type
                          (p_vfo_display_state->flags_0x8 >> 4,*(short *)PTR_DAT_0305c5d4 + 1,
                           auStack_30);
                memcpy_bytes_iram(&local_34,auStack_1d,3);
                bVar9 = pvVar3->flags_0x8 & 0xf0;
                if (((bVar9 == 0) || (bVar9 == 0x20)) && (bStack_1a < 3)) {
                  tx_key_from_vfo_mode_guard(bStack_1a,local_34,uVar11);
                  return;
                }
                if (((bVar9 == 0x10) || (bVar9 == 0x30)) &&
                   (((byte)(bStack_1a - 3) < 4 || (bStack_1a == 10)))) {
                  tx_key_from_vfo_mode_guard(bStack_1a,local_34,uVar11);
                  return;
                }
                format_and_write_status_field
                          (0,10,**(undefined4 **)
                                  (PTR_PTR_0305c5dc +
                                  ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
                return;
              }
            }
            else if ((cVar4 == '\x03') &&
                    (((4 < bVar9 &&
                      (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0305c5cc + 2) == '\0'))
                     || ((5 < bVar9 &&
                         (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0305c5cc + 2) ==
                          '\x01')))))) {
              unaff_r8 = flash_read_4byte_mutex_guarded();
            }
          }
          iVar6 = DAT_0305c5e8;
          if ((*(char *)PTR_DAT_0305c5e0 == '\0') || (unaff_r8 == 0)) {
            if (*(char *)PTR_DAT_0305c5ec == '\0') {
              cVar4 = *(char *)PTR_DAT_0305c78c;
              if (((((cVar4 == '\x04') || (cVar4 == '\x06')) &&
                   (*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0305c794 + 2) == '\x04'))
                  && (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0305c798 + 2) != '\x03'))
                 || (*(char *)PTR_DAT_0305c79c == 'M')) {
                bStack_1a = 3;
                cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0305c798 + 2);
                if ((cVar1 == '\0') || (*(char *)PTR_DAT_0305c79c == 'M')) {
                  if (cVar4 == '\x06') {
                    uVar7 = flash_record_read_nth_entry(1,p_menu_screen_state->index_0x3 + 1);
                    *p_text_entry_current_char_alias = uVar7;
                  }
                  else {
                    uVar7 = flash_record_read_nth_entry
                                      (1,*(char *)p_active_screen_state_word + '\x01');
                    *p_text_entry_current_char_alias = uVar7;
                  }
                }
                else if (cVar1 == '\x01') {
                  if (cVar4 == '\x04') {
                    uVar7 = flash_record_read_nth_entry
                                      (2,*(char *)p_active_screen_state_word + '\x01');
                    *p_text_entry_current_char_alias = uVar7;
                  }
                  else {
                    uVar7 = flash_record_read_nth_entry(2,p_menu_screen_state->index_0x3 + 1);
                    *p_text_entry_current_char_alias = uVar7;
                  }
                }
                else if (cVar1 == '\x02') {
                  if (cVar4 == '\x04') {
                    uVar7 = flash_record_read_nth_entry
                                      (3,*(char *)p_active_screen_state_word + '\x01');
                    *p_text_entry_current_char_alias = uVar7;
                  }
                  else {
                    uVar7 = flash_record_read_nth_entry(3,p_menu_screen_state->index_0x3 + 1);
                    *p_text_entry_current_char_alias = uVar7;
                  }
                }
                uVar7 = *p_text_entry_current_char_alias;
                *PTR_DAT_0305c784 = uVar7;
                tx_key_from_vfo_mode_guard(bStack_1a,uVar7,uVar11);
              }
              else if ((*(char *)PTR_DAT_0305c79c == 'i') &&
                      ((p_radio_mode_state_0003e318[1].flags_0x7 & 1) == 0)) {
                record_read_by_index(*(undefined2 *)((int)PTR_DAT_0305c7a4 + 1),auStack_30);
                memcpy_bytes_iram(&local_34,auStack_1d,3);
                history_queue_pop();
                bVar9 = p_vfo_display_state->flags_0x8 & 0xf0;
                if (((bVar9 == 0) || (bVar9 == 0x20)) && (bStack_1a < 3)) {
                  tx_key_from_vfo_mode_guard(1,local_34,p_dm32_settings_block04[0x53]);
                }
                else if (((bVar9 == 0x10) || (bVar9 == 0x30)) &&
                        (((byte)(bStack_1a - 3) < 4 || (bStack_1a == 10)))) {
                  tx_key_from_vfo_mode_guard(bStack_1a,local_34,uVar11);
                }
              }
              else if ((((p_tx_ptt_ui_state->flags_0xa & 0x30) == 0x10) ||
                       (((*(byte *)p_call_active_flag & 1) != 0 ||
                        (iVar6 = get_field_0301ea64_0x14(), iVar6 == 1)))) &&
                      ((p_dialog_flags_from_flash->flags_0x1e & 0x70) != 0x20)) {
                bVar9 = p_tx_ptt_ui_state->field_0x14;
                if (bVar9 == 3) {
                  uVar7 = dialog_state_get_field_03020e28();
                  tx_key_from_vfo_mode_guard(5,uVar7,0);
                }
                else if (bVar9 == 1) {
                  tx_key_from_vfo_mode_guard(3,*(undefined4 *)&p_tx_ptt_ui_state->field_0x10_0,0);
                }
                else if (bVar9 == 2) {
                  uVar7 = dialog_state_get_field_03020e28();
                  tx_key_from_vfo_mode_guard(4,uVar7,0);
                }
              }
              else {
                iVar6 = get_field_0301ea64_0x14();
                if ((iVar6 == 2) || ((p_tx_ptt_ui_state->flags_0xa & 0x30) == 0x20)) {
                  bVar9 = p_tx_ptt_ui_state->field_0x1c;
                  if (bVar9 == 1) {
                    uVar7 = 3;
                  }
                  else if (bVar9 == 2) {
                    uVar7 = 4;
                  }
                  else if (bVar9 == 3) {
                    uVar7 = 5;
                  }
                  else {
                    uVar7 = 0;
                  }
                  tx_key_from_vfo_mode_guard
                            (uVar7,*(undefined4 *)&p_tx_ptt_ui_state->field_0x18_0,0);
                }
                else {
                  bVar9 = p_vfo_display_state->flags_0x8 & 0xf0;
                  if ((bVar9 != 0) && (bVar9 != 0x20)) {
                    if (*(short *)&p_vfo_display_state->field_0x31_0 == 0) {
                      ui_event_notify(0x1b);
                      format_and_write_status_field
                                (0x2d,0x14,
                                 **(undefined4 **)
                                   (PTR_PTR_0305c968 +
                                   ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
                      return;
                    }
                    record_read_by_index(*(short *)&p_vfo_display_state->field_0x31_0,auStack_30);
                  }
                  memcpy_bytes_iram(&local_34,auStack_1d,3);
                  bVar9 = p_vfo_display_state->flags_0x8 & 0xf0;
                  if ((bVar9 == 0) || (bVar9 == 0x20)) {
                    tx_key_from_vfo_mode_guard(1,local_34,p_dm32_settings_block04[0x53]);
                  }
                  else if (((bVar9 == 0x10) || (bVar9 == 0x30)) &&
                          (((byte)(bStack_1a - 3) < 4 || (bStack_1a == 10)))) {
                    tx_key_from_vfo_mode_guard(bStack_1a,local_34,uVar11);
                  }
                  else {
                    ui_event_notify(0x1b);
                    format_and_write_status_field
                              (0,10,**(undefined4 **)
                                      (PTR_PTR_0305c96c +
                                      ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
                  }
                }
              }
            }
            else {
              iVar6 = ascii_digits_to_uint();
              if (iVar6 == 0) {
                main_menu_screen_dispatch();
              }
              else {
                if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
                  bStack_1a = 3;
                }
                else {
                  bStack_1a = 4;
                }
                uVar7 = *p_text_entry_current_char_alias;
                *PTR_DAT_0305c784 = uVar7;
                tx_key_from_vfo_mode_guard(bStack_1a,uVar7,p_dm32_settings_block04[0x53]);
              }
            }
          }
          else {
            flash_talker_record_read(*PTR_DAT_0305c5e4 + 1,DAT_0305c5e8);
            memcpy_bytes_iram(&local_34,iVar6 + 0x10,3);
            tx_key_from_vfo_mode_guard(3,local_34,uVar11);
          }
        }
      }
    }
    else {
      uVar8 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      *(undefined1 *)p_active_screen_option_count =
           *(undefined1 *)(PTR_PTR_0305c444 + uVar8 * 2 + 1);
      puVar10 = (undefined4 *)puVar10[uVar8 * 2];
      *p_active_screen_option_ptr_array = puVar10;
      p_radio_mode_state_0003e318->field_0x9 = p_radio_mode_state_0003e318->field_0x9 & 0xfe | 1;
      format_and_write_status_field(2,0x14,*puVar10);
      OSTimeDly_ms_wrapper(0x32);
      ui_event_notify(0x1b);
    }
  }
  else {
    if ((PTR_DAT_0305c284[5] & 1) != 0) {
      PTR_DAT_0305c284[5] = PTR_DAT_0305c284[5] & 0xfe;
      vfo_sync_active_side_on_ptt();
    }
    *PTR_DAT_0305c298 = 0;
    if ((PTR_DAT_0305c284[4] & 0x40) == 0) {
      format_and_write_status_field2
                (**(undefined4 **)
                   (PTR_PTR_0305c438 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    else {
      format_and_write_status_field2(PTR_DAT_0305c29c);
    }
    OSTimeDly_ms_wrapper(0x32);
    ui_event_notify(0x30);
    PTR_DAT_0305c43c[1] = PTR_DAT_0305c43c[1] & 0xfd;
  }
  return;
}


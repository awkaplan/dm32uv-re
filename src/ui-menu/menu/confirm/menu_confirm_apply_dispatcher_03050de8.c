/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_dispatcher @ 03050de8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1962 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_confirm_apply_dispatcher(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  byte bVar5;
  undefined1 *puVar6;
  radio_mode_state_0003e318 *prVar7;
  vfo_display_state *dest;
  int iVar8;
  uint uVar9;
  byte bVar10;
  byte *pbVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined1 auStack_90 [52];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  ushort auStack_4c [2];
  undefined4 uStack_48;
  undefined4 uStack_44;
  short sStack_2e;
  undefined1 auStack_2c [3];
  byte bStack_29;
  uint uStack_28;
  
  puVar6 = p_dm32_settings_block04;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03050fb8 + 2);
  if (cVar1 == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03050fbc + 2);
    if (cVar1 == '\x01') {
      cVar1 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_03050fc0 + 2);
      if (cVar1 == '\0') {
        if (*(char *)p_active_screen_state_word == '\0') {
          settings_write_dispatcher(0xf,0);
        }
        else {
          settings_write_dispatcher(0xf,1);
        }
        menu_row_highlight_draw();
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_03050fcc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        return;
      }
      if (cVar1 != '\x01') {
        return;
      }
      settings_write_dispatcher(0x2e,p_dm32_settings_block04[0x3c]);
      puVar6[0x57] = puVar6[0x3c];
      dialog_show_icon_and_number_from_ptr();
      return;
    }
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        return;
      }
      if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030511ec + 2) != '\x03') {
        return;
      }
      if (*(char *)((uint)p_menu_screen_state->index_0x5 + DAT_030511f0 + 2) == '\0') {
        if (*(char *)p_active_screen_state_word == '\0') {
          vfo_field_write_bit4_at_0x15(1);
        }
        else {
          vfo_field_write_bit4_at_0x15(0);
        }
        menu_row_highlight_draw();
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_030511e4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        return;
      }
      settings_write_dispatcher(0x3a,*(undefined1 *)p_active_screen_state_word);
      menu_row_highlight_draw();
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_030511e4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      return;
    }
    if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03050fd0 + 2) != '\x11') {
      return;
    }
    bVar2 = *(byte *)((uint)p_menu_screen_state->index_0x5 + DAT_03050fc0 + 2);
    if (bVar2 == 2) {
      settings_write_dispatcher(0x56,~(*(char *)p_active_screen_state_word != '\0'));
      menu_row_highlight_draw();
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_03050fd4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      return;
    }
    if (1 < bVar2) {
      if (bVar2 != 3) {
        return;
      }
      p_dm32_settings_block04[0x31] =
           p_dm32_settings_block04[0x31] & 0xef | (*(byte *)p_active_screen_state_word & 1) << 4;
      flash_field_read_cached(4,0x33,&bStack_29,1);
      if ((puVar6[0x31] & 0x10) == 0) {
        bStack_29 = bStack_29 & 0xf7;
      }
      else {
        bStack_29 = bStack_29 | 8;
      }
      flash_field_write_cached(4,0x33,bStack_29);
      menu_row_highlight_draw();
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_030511e4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      return;
    }
    uStack_5c = rtc_decode_calendar_date();
    uStack_58 = param_2;
    if (*(char *)PTR_DAT_03050fd8 == '\x01') {
      SUBPIECE_SET(uStack_54, 3, 1, (undefined1)((uint)uStack_5c >> 0x18));
      SUBPIECE_SET(uStack_54, 0, 3, CONCAT12(*(char *)(PTR_DAT_03050fdc + 1) * '\n' + *(char *)((int)PTR_DAT_03050fdc + 5),
                    CONCAT11(*(char *)((int)PTR_DAT_03050fdc + 3) +
                             *(char *)((int)PTR_DAT_03050fdc + 2) * '\n',
                             *(char *)((int)PTR_DAT_03050fdc + 1) + *(char *)PTR_DAT_03050fdc * '\n'
                            )));
      uStack_50 = param_2;
      rtc_date_validate_and_write(uStack_54,param_2);
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_4c);
      dialog_show_icon_and_number_from_ptr();
      return;
    }
    if (*(char *)PTR_DAT_03050fd8 != '\x02') {
      return;
    }
    uStack_50 = CONCAT31(CONCAT21((ushort)*(byte *)PTR_DAT_03050fdc * 10 +
                                  *(byte *)((int)PTR_DAT_03050fdc + 1) + 2000,
                                  *(char *)((int)PTR_DAT_03050fdc + 3) +
                                  *(char *)((int)PTR_DAT_03050fdc + 2) * '\n'),
                         *(char *)(PTR_DAT_03050fdc + 1) * '\n' +
                         *(char *)((int)PTR_DAT_03050fdc + 5));
    uStack_54 = uStack_5c;
    rtc_date_validate_and_write(uStack_5c,uStack_50);
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_4c);
    dialog_show_icon_and_number_from_ptr();
    return;
  }
  if (cVar1 != '\x01') {
    return;
  }
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_030511f8 + 2);
  if (cVar1 == '\x03') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030511ec + 2);
    if (cVar1 == '\0') {
      uVar12 = 1;
    }
    else if (cVar1 == '\x01') {
      uVar12 = 0;
    }
    else {
      uVar12 = 2;
    }
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_030511f0 + 2);
    if (cVar1 == '\x01') {
      memcpy_bytes_iram(auStack_4c,PTR_LAB_030511fc + (uint)*(byte *)p_active_screen_state_word * 2,
                        2);
    }
    else if (cVar1 == '\x02') {
      memcpy_bytes_iram(auStack_4c,PTR_LAB_03051200 + (uint)*(byte *)p_active_screen_state_word * 2,
                        2);
      auStack_4c[0] = auStack_4c[0] | 0x8000;
    }
    else if (cVar1 == '\x03') {
      memcpy_bytes_iram(auStack_4c,PTR_LAB_03051200 + (uint)*(byte *)p_active_screen_state_word * 2,
                        2);
      auStack_4c[0] = auStack_4c[0] | 0xc000;
    }
    if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
      vfo_frequency_write(uVar12,auStack_4c[0]);
    }
    else {
      channel_field_write_and_notify(uVar12,auStack_4c[0]);
    }
    menu_row_highlight_draw();
    dialog_show_icon_and_number_from_ptr();
    ui_event_notify_alt(8);
    return;
  }
  if (cVar1 != '\a') {
    if (cVar1 == '\f') {
      if (*(char *)((uint)p_menu_screen_state->index_0x5 + DAT_030513cc + 2) != '\x02') {
        write_status_mode_byte_pair(0x31,1);
        return;
      }
      if (*(char *)PTR_active_screen_subtype_030513d0 != '\n') {
        return;
      }
      if (*(char *)PTR_DAT_030513a0 != '\x03') {
        scan_state_tick();
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_030515e8 + DAT_030515ec),0);
        return;
      }
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xdf;
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&uStack_28);
      *(undefined1 *)PTR_DAT_030513a4 = 0xf0;
      if (*(char *)p_text_entry_buffer == '\0') {
        dialog_show_icon_and_number
                  (0,**(undefined4 **)
                       (PTR_PTR_030513b0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        return;
      }
      iVar8 = flash_record_11byte_exists_check_bank2(p_text_entry_buffer);
      uVar12 = p_text_entry_buffer;
      if (iVar8 != 0) {
        dialog_show_icon_and_number
                  (0,PTR_PTR_030513bc[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
        return;
      }
      flash_block_write(0xf,(*(byte *)PTR_DAT_030515dc - 1) * 0x6d + 0x11,p_text_entry_buffer,0xb);
      memcpy_bytes_iram(DAT_030515e4,uVar12,0xb);
      dialog_show_icon_and_number_from_ptr();
      return;
    }
    if (cVar1 != '\r') {
      write_status_mode_byte_pair(0x31,1);
      return;
    }
    bVar2 = *(byte *)PTR_DAT_030515f0;
    if (2 < bVar2) {
      if (bVar2 == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = 0;
        uVar9 = DAT_030515f8;
        pbVar11 = PTR_DAT_030515f4;
        do {
          uVar13 = uVar13 + uVar9 * (*pbVar11 - 0x30);
          uVar9 = uVar9 / 10;
          pbVar11 = pbVar11 + 1;
        } while (pbVar11 != PTR_DAT_030515f4 + (byte)(bVar2 - 1) + 1);
      }
      if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03051600 + 2) == '\x04') {
        if (uVar13 < (uint)PTR_DAT_03051604[8]) goto LAB_03051640;
        uVar9 = PTR_DAT_03051604[9];
      }
      else {
        if (((uint)*PTR_DAT_03051604 <= uVar13) && (uVar13 <= (uint)PTR_DAT_03051604[1]))
        goto LAB_030514a0;
        if (uVar13 < (uint)PTR_DAT_03051604[2]) goto LAB_03051640;
        uVar9 = PTR_DAT_03051604[3];
      }
      if (uVar13 <= uVar9) {
LAB_030514a0:
        OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&uStack_28);
        puVar6 = p_dm32_settings_block04;
        if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03051600 + 2) == '\x04') {
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,PTR_DAT_03051618,
                     **(undefined4 **)
                       (PTR_PTR_03051610 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                     PTR_LAB_03051614);
          prVar7 = p_radio_mode_state_0003e318;
          *(short *)&p_radio_mode_state_0003e318[1].field_0x8 =
               *(short *)&p_radio_mode_state_0003e318[1].field_0x8 + 1;
          flash_block_write(0x12,0,&prVar7[1].field_0x8,2);
          SUBPIECE_SET(uVar3, 0, 1, prVar7[1].field_0x8);
          SUBPIECE_SET(uVar3, 1, 1, prVar7[1].field_0x9);
          channel_offset_from_num(uVar3,auStack_2c,&sStack_2e);
          flash_block_write(auStack_2c[0],sStack_2e,p_text_entry_buffer,0x10);
          dest = p_vfo_display_state;
          *(byte *)p_vfo_display_state = (byte)uVar13;
          bVar2 = (byte)(uVar13 >> 8);
          dest->field_0x1 = bVar2;
          bVar5 = (byte)(uVar13 >> 0x10);
          dest->field_0x2 = bVar5;
          bVar10 = (byte)(uVar13 >> 0x18);
          dest->field_0x3 = bVar10;
          dest->field_0x4_0 = (byte)uVar13;
          dest->field_0x5 = bVar2;
          dest->field_0x6 = bVar5;
          dest->field_0x7 = bVar10;
          int_to_bcd_bytes(&uStack_48,uVar13,4);
          uStack_44 = uStack_48;
          SUBPIECE_SET(uVar4, 0, 1, prVar7[1].field_0x8);
          SUBPIECE_SET(uVar4, 1, 1, prVar7[1].field_0x9);
          channel_num_to_block_offset(uVar4,auStack_2c,&sStack_2e);
          dest->field_0x11_0 = 0xff;
          dest->field_0x12 = 0xff;
          dest->field_0x13_0 = 0xff;
          dest->field_0x14 = 0xff;
          dest->flags_0x8 = dest->flags_0x8 & 0xf;
          dest->flags_0xd = dest->flags_0xd & 0xf0 | 1;
          dest->field_0xf = dest->field_0xf & 0xbf;
          dest->flags_0x9 = dest->flags_0x9 & 0x7f | 0x80;
          dest->field_0xc = dest->field_0xc & 0xf | 0x10;
          flash_block_write(auStack_2c[0],sStack_2e,&uStack_48,8);
          flash_block_write(auStack_2c[0],sStack_2e + 8,&dest->flags_0x8,0x18);
          busy_wait_delay_loop_counted(auStack_90);
          memcpy_ck803s(dest,auStack_90,0x33);
          dialog_show_icon_and_number
                    (1,**(undefined4 **)(PTR_PTR_03051624 + ((byte)puVar6[0x30] >> 6 & 1) * 8));
          history_queue_pop();
          history_queue_pop();
          return;
        }
        *PTR_DAT_03051720 = uVar13;
        write_status_mode_byte_pair(0x31,1);
        return;
      }
    }
LAB_03051640:
    OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&uStack_28);
    dialog_show_icon_and_two_numbers
              (0x30,0x30,PTR_DAT_03051734,
               **(undefined4 **)
                 (PTR_PTR_0305172c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
               PTR_LAB_03051730);
    OSTimeDly_ms_wrapper(1000);
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03051738 + DAT_0305173c),1);
    return;
  }
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x5 + DAT_030511f0 + 2);
  if (cVar1 != '\x01') {
    if (cVar1 != '\x02') {
      return;
    }
    if (*(char *)PTR_DAT_030513a0 == '\x03') {
      *(undefined1 *)PTR_DAT_030513a4 = 0xf0;
      if (*(char *)p_text_entry_buffer == '\0') {
        display_draw_dialog_panel();
        display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_030513ac);
        display_draw_number_centered
                  (0x90,0,0xc618,
                   **(uint **)(PTR_PTR_030513b0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8
                              ));
        OSTimeDly_ms_wrapper(500);
      }
      else {
        iVar8 = locked_radio_id_lookup_by_string
                          (p_text_entry_buffer,*(undefined1 *)PTR_DAT_030513b4);
        if (iVar8 == 0) {
          strcpy_ck803s(p_list_row_text_buffer,p_text_entry_buffer);
        }
        else {
          display_draw_dialog_panel();
          display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_030513ac);
          display_draw_number_centered
                    (0x90,0,0xc618,PTR_PTR_030513bc[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
          OSTimeDly_ms_wrapper(500);
        }
      }
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xf7;
      history_queue_pop();
      return;
    }
    scan_state_tick();
    write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_030513c0 + DAT_030513c4),0);
    return;
  }
  OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,&uStack_28);
  uStack_28 = 0;
  if (*(byte *)PTR_DAT_03051208 != 0) {
    uStack_28 = 0;
    iVar8 = 0;
    do {
      iVar8 = iVar8 * 10 + -0x30 + (uint)(byte)PTR_DAT_0305120c[uStack_28];
      uStack_28 = uStack_28 + 1;
    } while (uStack_28 < *(byte *)PTR_DAT_03051208);
    if (iVar8 - 1U < 0xfffcdf) {
      *PTR_DAT_03051210 = iVar8;
      history_queue_pop();
      goto LAB_0305122c;
    }
  }
  dialog_show_icon_and_number
            (3,**(undefined4 **)
                 (PTR_PTR_03051398 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
LAB_0305122c:
  p_radio_mode_state_0003e318->flags_0x4 = p_radio_mode_state_0003e318->flags_0x4 & 0x7f;
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_handler1 @ 0304cf5c (file base 0x03000000; code starts at 0x03001000)
 * Size: 896 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_confirm_apply_handler1(void)

{
  byte bVar1;
  byte *pbVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  vfo_display_state *pvVar6;
  int iVar7;
  
  pvVar6 = p_vfo_display_state;
  puVar5 = PTR_DAT_0304d278;
  puVar4 = PTR_DAT_0304d0b4;
  if ((*(byte *)PTR_DAT_0304d090 & 2) == 0) {
    cVar3 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304d0a8 + 2);
    if (cVar3 == '\0') {
      if (*(char *)p_active_screen_state_word == '\0') {
        iVar7 = zone_change_key_handler(1);
        if (iVar7 == 0) {
          ui_event_notify(0x1b);
          dialog_show_icon_and_number
                    (0,**(undefined4 **)
                         (PTR_PTR_0304d0b0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
        else {
          write_status_mode_byte_pair(0,1);
        }
      }
      else {
        *(byte *)PTR_DAT_0304d0b4 = *(byte *)PTR_DAT_0304d0b4 & 0xfb | 4;
        dtmf_inject_digits_2_0();
        *(byte *)puVar4 = *(byte *)puVar4 & 0xfb;
        ui_event_notify(0x19);
        p_vfo_freq_display_state->flags_0x10 = p_vfo_freq_display_state->flags_0x10 & 0x7f;
        write_status_mode_byte_pair(0,1);
      }
    }
    else if (cVar3 == '\x01') {
      if (*(char *)p_active_screen_state_word == '\0') {
        display_blit_bitmap_1bpp(8,0x28,0x18,0x48,PTR_LAB_0304d0bc,0xffff);
        display_blit_bitmap_1bpp(8,0x28,0x18,0x48,PTR_LAB_0304d0c0,0xffff);
        dialog_show_icon_and_number_from_ptr();
        settings_write_dispatcher(0x32,0);
        zone_record_read(p_vfo_display_state->flags_0x9 & 0x3f);
        if ((p_vfo_freq_display_state->field_0x1 < 2) &&
           (iVar7 = get_current_mode_state1(), iVar7 != 0)) {
          dtmf_digit_input_handler(0);
        }
      }
      else {
        *(char *)PTR_DAT_0304d0c8 = *(char *)p_active_screen_state_word;
        write_status_mode_byte_pair(0x1c,1);
      }
    }
    else if ((byte)(cVar3 - 2U) < 2) {
      bVar1 = ~(cVar3 != '\x02');
      iVar7 = bcd_frequency_pair_validate_and_store(bVar1,_DAT_0304d0cc);
      if (iVar7 == 0) {
        if (bVar1 == 1) {
          bcd_frequency_pair_validate_and_store(1,DAT_0304d26c);
        }
        else {
          bcd_frequency_pair_validate_and_store(0,DAT_0304d25c);
        }
        dialog_show_icon_and_number
                  (0,PTR_PTR_0304d270[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
      }
      else {
        if (bVar1 == 1) {
          memcpy_bytes_iram(DAT_0304d0d0,_DAT_0304d0cc,4);
          settings_write_dispatcher(0x52,0);
        }
        else {
          memcpy_bytes_iram(DAT_0304d25c,_DAT_0304d260,4);
          settings_write_dispatcher(0x53,0);
        }
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_0304d268 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
    }
    else if (cVar3 == '\x04') {
      settings_write_dispatcher(0x57,*(undefined1 *)p_active_screen_state_word);
      menu_row_highlight_draw();
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_0304d268 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    else if ((byte)(cVar3 - 5U) < 2) {
      if ((PTR_DAT_0304d278[3] & 0x80) == 0) {
        if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
          bVar1 = p_vfo_freq_display_state->field_0x5e;
          if ((bVar1 == 0) || (bVar1 == 2)) {
            pbVar2 = &p_vfo_display_state->field_0x11_0;
            p_vfo_display_state->field_0x13_0 = (byte)*(undefined2 *)pbVar2;
            pvVar6->field_0x14 = (char)((ushort)*(undefined2 *)pbVar2 >> 8);
            vfo_frequency_write(1);
            if (p_vfo_freq_display_state->field_0x5e == 2) {
              vfo_frequency_write(0,*(undefined2 *)&p_vfo_display_state->field_0x11_0);
            }
          }
          else if (bVar1 == 1) {
            vfo_frequency_write(0,*(undefined2 *)&p_vfo_display_state->field_0x11_0);
          }
        }
        else {
          bVar1 = p_vfo_freq_display_state->field_0x5e;
          if ((bVar1 == 0) || (bVar1 == 2)) {
            pbVar2 = &p_vfo_display_state->field_0x11_0;
            p_vfo_display_state->field_0x13_0 = (byte)*(undefined2 *)pbVar2;
            pvVar6->field_0x14 = (char)((ushort)*(undefined2 *)pbVar2 >> 8);
            channel_field_write_and_notify(1);
            if (p_vfo_freq_display_state->field_0x5e == 2) {
              channel_field_write_and_notify(0,*(undefined2 *)&p_vfo_display_state->field_0x11_0);
            }
          }
          else if (bVar1 == 1) {
            channel_field_write_and_notify(0,*(undefined2 *)&p_vfo_display_state->field_0x11_0);
          }
        }
        dialog_show_icon_and_number_from_ptr();
        ui_event_notify_alt(8);
        write_status_mode_byte_pair(0,1);
      }
      else {
        PTR_DAT_0304d278[3] = PTR_DAT_0304d278[3] & 0x7f;
        puVar5[4] = puVar5[4] & 0xfe;
        write_status_mode_byte_pair(0,1);
      }
    }
    else if (cVar3 == '\a') {
      p_vfo_freq_display_state->field_0x5e = *(byte *)p_active_screen_state_word;
      flash_field_write_cached(0x11,0xe10);
      menu_row_highlight_draw();
      dialog_show_icon_and_number
                (1,**(undefined4 **)
                     (PTR_PTR_0304d43c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    }
    else if ((*(char *)p_active_screen_option_count == '\0') ||
            (*(char *)PTR_active_screen_subtype_0304d444 == '\x05')) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304d448 + DAT_0304d44c),0);
    }
    else {
      write_status_mode_byte_pair(0x1c,1);
    }
  }
  else if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304d454 + 2) == '\x04') {
    *(undefined1 *)PTR_DAT_0304d458 = 5;
    *(undefined1 *)PTR_DAT_0304d45c = 5;
    bVar1 = *(byte *)p_active_screen_state_word;
    if (bVar1 < 3) {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xe7;
      *(byte *)PTR_DAT_0304d464 = bVar1 + 0x1b;
    }
    else {
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0xe7 | 0x18;
      *(byte *)PTR_DAT_0304d464 = bVar1 + 0x1b;
    }
    write_status_mode_byte_pair(0x62,1);
  }
  else {
    write_status_mode_byte_pair(0x1c,1);
  }
  return;
}


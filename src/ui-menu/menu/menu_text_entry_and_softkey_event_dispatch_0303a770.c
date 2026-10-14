/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_text_entry_and_softkey_event_dispatch @ 0303a770 (file base 0x03000000; code starts at 0x03001000)
 * Size: 830 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_text_entry_and_softkey_event_dispatch(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar3 = PTR_DAT_0303aa50;
  if ((*(byte *)PTR_DAT_0303a854 & 2) == 0) {
    cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303a858[1] + DAT_0303a85c + 2);
    if (cVar1 == '\x04') {
      if ((PTR_DAT_0303a860[8] & 0xf0) == 0) {
        tx_gate_write_call_record(0);
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)(byte)PTR_DAT_0303a848[2] + DAT_0303a84c),0);
      }
      else {
        status_mode_byte_pair_select_and_write();
      }
    }
    else if (cVar1 == '\0') {
      cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303a858[2] + DAT_0303a864 + 2);
      if (cVar1 == '\x01') {
        iVar4 = ascii_digits_to_uint();
        if (iVar4 == 1) {
          iVar4 = talkgroup_binary_search_dispatch_by_radio_mode_flag
                            (*PTR_text_entry_current_char_minus_6_0303a868);
          if (iVar4 == 0) {
            strcpy_ck803s(DAT_0303aa10,DAT_0303aa14);
            write_status_mode_byte_pair(0x1c,1);
          }
          else {
            format_and_write_status_field
                      (0x2d,10,**(undefined4 **)
                                 (PTR_PTR_0303a86c + ((byte)PTR_DAT_0303a830[0x30] >> 6 & 1) * 8));
            PTR_DAT_0303a870[5] = PTR_DAT_0303a870[5] & 0xf3;
          }
        }
        else {
          write_status_mode_byte_pair
                    (*(undefined1 *)((uint)(byte)PTR_DAT_0303aa18[2] + DAT_0303aa1c),0);
        }
      }
      else if (cVar1 == '\x02') {
        *(undefined1 *)PTR_DAT_0303aa20 = 0;
        iVar4 = ascii_digits_to_uint();
        if (iVar4 == 0) {
          write_status_mode_byte_pair
                    (*(undefined1 *)((uint)(byte)PTR_DAT_0303aa18[2] + DAT_0303aa1c),0);
        }
        else if ((PTR_DAT_0303aa24[3] & 4) == 0) {
          PTR_DAT_0303aa24[5] = PTR_DAT_0303aa24[5] & 0xbf;
          write_status_mode_byte_pair(0x1c,1);
        }
        else {
          tx_gate_write_call_record(0);
          PTR_DAT_0303aa24[5] = PTR_DAT_0303aa24[5] & 0xbf | 0x40;
          write_status_mode_byte_pair
                    (*(undefined1 *)((uint)(byte)PTR_DAT_0303aa18[2] + DAT_0303aa1c),0);
        }
      }
      else {
        write_status_mode_byte_pair(0x1c,1);
      }
    }
    else if (cVar1 == '\x01') {
      menu_confirm_apply_handler1();
    }
    else if (cVar1 == '\x02') {
      menu_confirm_apply_zone_handler();
    }
    else if (cVar1 == '\x03') {
      if (*(char *)PTR_active_screen_subtype_0303aa28 == '\n') {
        if (*(char *)PTR_DAT_0303aa2c == '\x03') {
          *(undefined2 *)PTR_DAT_0303aa34 = *(undefined2 *)PTR_text_entry_current_char_0303aa30;
          *(undefined2 *)PTR_text_entry_buffer_minus_4_0303aa3c = *(undefined2 *)PTR_DAT_0303aa38;
          *(undefined1 *)PTR_DAT_0303aa40 = 0xf0;
          write_status_mode_byte_pair(0x1c,1);
        }
        else {
          scan_state_tick();
          write_status_mode_byte_pair
                    (*(undefined1 *)((uint)(byte)PTR_DAT_0303aa18[2] + DAT_0303aa1c),0);
        }
      }
      else if (*(char *)PTR_active_screen_option_count_0303aa44 != '\0') {
        write_status_mode_byte_pair(0x1c,1);
      }
    }
    else if (cVar1 == '\x06') {
      cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303aa48[2] + DAT_0303aa4c + 2);
      if (cVar1 == '\x03') {
        dialog_show_icon_and_two_numbers
                  (0x30,0x30,PTR_DAT_0303aa5c,
                   **(undefined4 **)(PTR_PTR_0303aa54 + ((byte)PTR_DAT_0303aa50[0x30] >> 6 & 1) * 8)
                   ,PTR_LAB_0303aa58);
        flash_dual_range_invalidate();
        dialog_show_icon_and_number
                  (1,**(undefined4 **)(PTR_PTR_0303aa60 + ((byte)puVar3[0x30] >> 6 & 1) * 8));
        history_queue_pop();
      }
      else if (cVar1 == '\0') {
        if (*(char *)PTR_active_screen_state_word_0303aa64 == '\0') {
          if ((PTR_DAT_0303aa24[0x11] & 0x10) == 0) {
            settings_toggle_and_notify_0x45(1);
          }
          else {
            ui_event_notify(0x21);
            format_and_write_status_field2(PTR_PTR_0303aa68[(byte)PTR_DAT_0303aa50[0x30] >> 6 & 1]);
          }
        }
        else {
          settings_toggle_and_notify_0x45(0);
        }
        if ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x10) == 0) {
          menu_row_highlight_draw();
          dialog_show_icon_and_number_from_ptr();
        }
      }
      else if (cVar1 == '\x01') {
        flash_field4_byte_update_with_shadow_copy(*(undefined1 *)p_active_screen_state_word);
        menu_row_highlight_draw();
        dialog_show_icon_and_number_from_ptr();
      }
      else {
        write_status_mode_byte_pair(0x1c,1);
      }
    }
    else if (cVar1 == '\a') {
      if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0303ac04 + 2) == '\x01') {
        *(undefined1 *)PTR_DAT_0303ac08 = *(undefined1 *)p_active_screen_state_word;
      }
      write_status_mode_byte_pair(0x1c,1);
    }
    else if (cVar1 == '\b') {
      backlight_setting_toggle_handler();
    }
    else if (cVar1 == '\t') {
      menu_wrapper_character_dispatch();
    }
    else if (cVar1 == '\x05') {
      if ((p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2] == '\r') &&
         (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0303ac04 + 2) == '\x01')) {
        SUBPIECE_SET(uVar2, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
        SUBPIECE_SET(uVar2, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
        if (3999 < uVar2) {
          dialog_show_icon_and_number(0,PTR_PTR_0303ac14[(byte)PTR_DAT_0303ac10[0x30] >> 6 & 1]);
          return;
        }
        write_status_mode_byte_pair(0x1c,1);
        return;
      }
      write_status_mode_byte_pair(0x1c,1);
    }
    else {
      write_status_mode_byte_pair(0x1c,1);
    }
  }
  else {
    cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303a858[1] + DAT_0303a85c + 2);
    if (cVar1 == '\0') {
      status_mode_reset_and_post_0x62_on_bit1();
    }
    else if (cVar1 == '\x01') {
      menu_confirm_apply_handler1();
    }
  }
  return;
}


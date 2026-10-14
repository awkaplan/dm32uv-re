/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_handler2 @ 030500b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 732 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_confirm_apply_handler2(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 auStack_c [4];
  
  puVar3 = PTR_DAT_030501e0;
  bVar1 = *(byte *)((uint)p_menu_screen_state->index_0x3 + DAT_030501d0 + 2);
  if (1 < bVar1) {
    if (bVar1 == 3) {
      bVar1 = *(byte *)((uint)p_menu_screen_state->index_0x4 + DAT_030501d4 + 2);
      if (bVar1 < 3) {
        cVar2 = *(char *)p_active_screen_state_word;
        if (cVar2 == '\0') {
          if (bVar1 == 0) {
            uVar4 = 1;
          }
          else if (bVar1 == 1) {
            uVar4 = 0;
          }
          else {
            uVar4 = 2;
          }
          if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
            vfo_frequency_write(uVar4,0xffff);
          }
          else {
            channel_field_write_and_notify(uVar4,0xffff);
          }
          menu_row_highlight_draw();
          dialog_show_icon_and_number_from_ptr();
          menu_row_highlight_draw();
          ui_event_notify_alt(8);
        }
        else if (cVar2 == '\x01') {
          write_status_mode_byte_pair(0x2a,1);
        }
        else if ((byte)(cVar2 - 2U) < 2) {
          write_status_mode_byte_pair(0x2a,1);
        }
      }
    }
    else if (bVar1 == 7) {
      if (p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2] == '\0') {
        if (p_vfo_display_state->field_0x1b != *(byte *)PTR_DAT_030501e0) {
          vfo_field_write_byte_at_0x1b();
        }
        dialog_show_icon_and_number_from_ptr();
        history_queue_pop();
      }
      else if (p_active_screen_index_list[*(byte *)p_active_screen_state_word + 2] == '\x03') {
        radio_id_entry_write(*(undefined1 *)PTR_DAT_030501e0,*PTR_DAT_030501e8);
        flash_block0x67_write_indexed_12byte(*(undefined1 *)puVar3,p_list_row_text_buffer);
        if (*(byte *)puVar3 == p_vfo_display_state->field_0x1b) {
          uVar4 = flash_field_block67_signed_threshold_check();
          *PTR_DAT_030501f0 = uVar4;
          call_setup_sm_aux_field24_store();
        }
        if (*(byte *)PTR_DAT_030501f4 <= *(byte *)PTR_DAT_030501e0) {
          *(byte *)PTR_DAT_030501f4 = *(byte *)PTR_DAT_030501f4 + 1;
          flash_block0x67_write_byte_off0();
        }
        dialog_show_icon_and_number_from_ptr();
      }
      else {
        write_status_mode_byte_pair(0x2a,1);
      }
    }
    else if (bVar1 == 0xc) {
      if (*(byte *)PTR_DAT_03050394 < *(byte *)PTR_DAT_03050390) {
        if (*(char *)PTR_active_screen_subtype_0305039c == '\n') {
          if (*(char *)PTR_DAT_030503a0 == '\x03') {
            OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_c);
            *(undefined1 *)PTR_DAT_030503a8 = 0xf0;
            *(undefined1 *)((int)p_text_entry_buffer + (uint)*(byte *)PTR_DAT_030503b0) = 0;
            dmr_user_register_next_free_bitmap_slot();
            dialog_show_icon_and_number_from_ptr();
          }
          else {
            scan_state_tick();
            write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_030503b4 + DAT_030503b8),0);
          }
        }
      }
      else if (*(char *)p_active_screen_state_word == '\0') {
        vfo_field_write_6bit_at_0xf();
        dialog_show_icon_and_number_from_ptr();
      }
      else {
        write_status_mode_byte_pair(0x2a,1);
      }
    }
    else if (bVar1 == 0xd) {
      if (*(char *)PTR_active_screen_subtype_0305039c == '\n') {
        if (*(char *)PTR_DAT_030503a0 == '\x03') {
          OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_c);
          p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xdf;
          *(undefined1 *)PTR_DAT_030503a8 = 0xf0;
          if (*(char *)p_text_entry_buffer == '\0') {
            dialog_show_icon_and_number
                      (0,**(undefined4 **)
                           (PTR_PTR_030503c4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
          }
          else {
            iVar5 = channel_name_exists(p_text_entry_buffer);
            if (iVar5 == 0) {
              write_status_mode_byte_pair(0x2a,1);
            }
            else {
              dialog_show_icon_and_number
                        (0,PTR_PTR_030503c8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
            }
          }
        }
        else {
          scan_state_tick();
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_030503b4 + DAT_030503b8),0);
        }
      }
    }
    else if (bVar1 == 0xf) {
      cVar2 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030503d0 + 2);
      if (cVar2 == '\0') {
        iVar5 = vfo_field_write_bit6_at_0xf(*(undefined1 *)p_active_screen_state_word);
        if (iVar5 == 0) {
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,PTR_DAT_030503dc,
                     **(undefined4 **)
                       (PTR_PTR_030503d8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                     (*(undefined4 **)
                       (PTR_PTR_030503d8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))[1]);
          ui_event_notify(0x1b);
          OSTimeDly_ms_wrapper(1000);
          history_queue_pop();
        }
        else {
          ui_event_notify_alt(8);
          menu_row_highlight_draw();
          dialog_show_icon_and_number
                    (1,**(undefined4 **)
                         (PTR_PTR_030503d4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
        }
      }
      else if (cVar2 == '\x01') {
        vfo_field_write_byte_at_0xe(*(undefined1 *)p_active_screen_state_word);
        ui_event_notify_alt(8);
        menu_row_highlight_draw();
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_03050560 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
    }
  }
  return;
}


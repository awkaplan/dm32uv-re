/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_scan_handler @ 0304f384 (file base 0x03000000; code starts at 0x03001000)
 * Size: 390 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_confirm_apply_scan_handler(void)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_8 [4];
  
  if (*(char *)PTR_active_screen_subtype_0304f48c == '\n') {
    if (*(char *)PTR_DAT_0304f490 == '\x03') {
      OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_8);
      *(undefined1 *)PTR_DAT_0304f498 = 0xf0;
      strcpy_ck803s(p_list_row_text_buffer,p_text_entry_buffer);
      iVar2 = scanned_channel_save_as_contact_flow();
      if (iVar2 == 0) {
        write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f4a4 + DAT_0304f4a8),3);
      }
      else {
        dialog_show_icon_and_number
                  (1,*(undefined4 *)
                      (PTR_PTR_0304f4b0[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 8));
        history_queue_pop();
        p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xf3;
      }
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f4a4 + DAT_0304f4a8),0);
    }
  }
  else {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304f4bc + 2);
    if (cVar1 == '\0') {
      write_status_mode_byte_pair(0x23,1);
    }
    else if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        iVar2 = scan_feature_enabled(0);
        if (iVar2 == 0) {
          display_draw_dialog_panel();
          display_draw_number_centered
                    (0x82,0,0xc618,
                     *(uint *)(PTR_PTR_0304f4b0[(byte)p_dm32_settings_block04[0x30] >> 6 & 1] + 0x10
                              ));
          OSTimeDly_ms_wrapper(1000);
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f4a4 + DAT_0304f4a8),3);
        }
        else {
          status_dialog_request_by_code_dispatch_b();
        }
      }
      else if (cVar1 == '\x03') {
        if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304f5fc + 2) == '\x01') {
          iVar2 = ascii_digits_to_uint();
          if (iVar2 == 0) {
            write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f600 + DAT_0304f604),0);
          }
          else {
            write_status_mode_byte_pair(0x23,1);
          }
        }
        else {
          write_status_mode_byte_pair(0x23,1);
        }
      }
      else if (cVar1 == '\x04') {
        if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304f5fc + 2) == '\x01') {
          *(byte *)PTR_DAT_0304f608 =
               *(byte *)PTR_DAT_0304f608 & 0xfd | (*(byte *)p_active_screen_state_word & 1) << 1;
          packed_flags_0x67_write();
          menu_row_highlight_draw();
          dialog_show_icon_and_number_from_ptr();
        }
        else {
          write_status_mode_byte_pair(0x23,1);
        }
      }
      else {
        write_status_mode_byte_pair(0x23,1);
      }
    }
  }
  return;
}


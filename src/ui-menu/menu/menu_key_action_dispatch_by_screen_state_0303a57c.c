/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_key_action_dispatch_by_screen_state @ 0303a57c (file base 0x03000000; code starts at 0x03001000)
 * Size: 430 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_key_action_dispatch_by_screen_state(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  puVar3 = PTR_DAT_0303a830;
  puVar2 = PTR_DAT_0303a698;
  if ((*(byte *)PTR_DAT_0303a68c & 2) == 0) {
    cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303a690[1] + DAT_0303a6a8 + 2);
    if (cVar1 == '\0') {
      menu_confirm_apply_scan_handler();
    }
    else if (cVar1 == '\x01') {
      dtmf_zone_entry_activate();
    }
    else if (cVar1 == '\x02') {
      dmr_id_log_or_zone_name_confirm_dispatch();
    }
    else if (cVar1 == '\x03') {
      if ((PTR_DAT_0303a6ac[8] & 0xf0) == 0) {
        tx_gate_write_call_record(0);
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)(byte)PTR_DAT_0303a698[2] + DAT_0303a6a4),0);
      }
      else {
        input_message_dispatcher();
      }
    }
    else if (cVar1 == '\x04') {
      menu_item_apply_and_show_or_prompt();
    }
    else if (cVar1 == '\x05') {
      status_mode_or_settings_menu_command_dispatch();
    }
    else if (cVar1 == '\x06') {
      if (*(char *)((uint)(byte)PTR_g_menu_screen_state_0303a690[2] + DAT_0303a694 + 2) == '\x02') {
        cVar1 = PTR_active_screen_index_list_0303a6b0
                [*(byte *)PTR_active_screen_state_word_0303a69c + 2];
        if (cVar1 == '\0') {
          recording_playback_to_speaker(*PTR_DAT_0303a6b4 + 1);
          history_queue_pop();
        }
        else if (cVar1 == '\x01') {
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,PTR_DAT_0303a83c,
                     **(undefined4 **)
                       (PTR_PTR_0303a834 + ((byte)PTR_DAT_0303a830[0x30] >> 6 & 1) * 8),
                     PTR_LAB_0303a838);
          channel_list_compact_and_delete_entry(*(undefined2 *)PTR_DAT_0303a840);
          dialog_show_icon_and_number
                    (1,**(undefined4 **)(PTR_PTR_0303a844 + ((byte)puVar3[0x30] >> 6 & 1) * 8));
          iVar4 = recording_count_scan();
          if (iVar4 == 0) {
            history_queue_pop();
          }
        }
        else if (cVar1 == '\x02') {
          write_status_mode_byte_pair(0x23,1);
        }
      }
    }
    else if (cVar1 == '\a') {
      dmr_menu_field_edit_key_dispatch();
    }
    else if (cVar1 == '\b') {
      write_status_mode_byte_pair(0x23,1);
    }
    else if (cVar1 == '\t') {
      write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_0303a848[2] + DAT_0303a84c),0)
      ;
    }
    else if (*(short *)PTR_active_screen_index_list_0303a850 == 0) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_0303a848[2] + DAT_0303a84c),0)
      ;
    }
    else {
      write_status_mode_byte_pair(0x23,1);
    }
  }
  else {
    cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_0303a690[2] + DAT_0303a694 + 2);
    if (cVar1 == '\x01') {
      PTR_DAT_0303a698[0xa09] = *(char *)PTR_active_screen_state_word_0303a69c + '\x10';
      puVar2[0xa08] = 2;
      *(undefined1 *)PTR_DAT_0303a6a0 = 2;
    }
    else if (cVar1 == '\x02') {
      write_status_mode_byte_pair(*(undefined1 *)((uint)(byte)PTR_DAT_0303a698[2] + DAT_0303a6a4),0)
      ;
      return;
    }
    write_status_mode_byte_pair(0x62,1);
  }
  return;
}


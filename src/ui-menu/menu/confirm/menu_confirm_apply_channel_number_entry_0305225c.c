/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_confirm_apply_channel_number_entry @ 0305225c (file base 0x03000000; code starts at 0x03001000)
 * Size: 572 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_confirm_apply_channel_number_entry(void)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pbVar1 = _DAT_03052500;
  uVar5 = _p_text_entry_buffer;
  if (*(char *)PTR_active_screen_subtype_03052338 == '\b') {
    iVar3 = ascii_digits_to_uint();
    if (iVar3 == 1) {
      uVar5 = *p_text_entry_current_char_alias;
      *PTR_DAT_03052340 = uVar5;
      cVar2 = strlen_ck803s(p_text_entry_buffer);
      *(char *)PTR_DAT_03052348 = cVar2 + '\x01';
      if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
        uVar4 = 3;
      }
      else {
        uVar4 = 4;
      }
      channel_select_commit_and_notify
                (uVar4,uVar5,p_text_entry_buffer,cVar2 + '\x01',p_dm32_settings_block04[0x54]);
    }
    else {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03052330 + DAT_03052334),0);
    }
  }
  else {
    cVar2 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03052354 + 2);
    if (cVar2 == '\0') {
      cVar2 = *(char *)((uint)p_menu_screen_state->index_0x6 + DAT_03052358 + 2);
      if (cVar2 == '\0') {
        if (*(char *)p_active_screen_state_word == '\0') {
          uVar5 = channel_number_decode_from_menu_index
                            (1,p_menu_screen_state->index_0x4 + 1,DAT_03052360);
          *PTR_DAT_03052340 = uVar5;
          channel_select_commit_and_notify
                    (3,uVar5,p_text_entry_buffer,*(undefined1 *)PTR_DAT_03052348,
                     p_dm32_settings_block04[0x54]);
        }
        else if (*(char *)p_active_screen_state_word == '\x01') {
          write_status_mode_byte_pair(0x3f,1);
        }
        else {
          history_queue_pop();
          history_queue_pop();
        }
      }
      else if (cVar2 == '\x01') {
        if (*(char *)((uint)p_menu_screen_state->field_0x7 + _LAB_030524ec + 2) == '\0') {
          history_list_row_lookup(*_DAT_030524f0 + 1);
        }
      }
      else if (cVar2 == '\x02') {
        cVar2 = *(char *)(_p_active_screen_index_list + (uint)*_p_active_screen_state_word + 2);
        if (cVar2 == '\x04') {
          history_queue_pop();
          history_queue_pop();
        }
        else if (cVar2 == '\x03') {
          buffer_prepend_3byte_le(0,_p_text_entry_buffer,*_DAT_03052500);
          contact_edit_save_flow1(uVar5,*pbVar1 + 3,5,0);
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,_DAT_03052510,
                     **(undefined4 **)
                       (_DAT_03052508 + (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 8),
                     _DAT_0305250c);
          OSTimeDly_ms_wrapper(1000);
          history_queue_pop();
          history_queue_pop();
        }
        else {
          write_status_mode_byte_pair(0x3f,1);
        }
      }
    }
    else if (cVar2 == '\x03') {
      if (*(char *)((uint)p_menu_screen_state->index_0x6 + _DAT_03052514 + 2) == '\x02') {
        if (*_p_active_screen_state_word == 0) {
          write_status_mode_byte_pair(0x3f,1);
        }
        else if (*_p_active_screen_state_word == 1) {
          buffer_prepend_3byte_le(0,_p_text_entry_buffer,*_DAT_03052500);
          dialog_show_icon_and_two_numbers
                    (0x30,0x30,_DAT_03052510,
                     **(undefined4 **)
                       (_DAT_03052508 + (*(byte *)(_p_dm32_settings_block04 + 0x30) >> 6 & 1) * 8),
                     _DAT_0305250c);
          contact_edit_save_flow1(uVar5,*pbVar1 + 3,5,0);
          OSTimeDly_ms_wrapper(1000);
          history_queue_pop();
          history_queue_pop();
          history_queue_pop();
        }
      }
      else if (*(char *)((uint)p_menu_screen_state->field_0x7 + _LAB_030524ec + 2) == '\0') {
        history_list_row_lookup(*_DAT_030524f0 + 1);
      }
    }
    else if (cVar2 == '\x04') {
      if ((*(char *)((uint)p_menu_screen_state->index_0x6 + _DAT_03052514 + 2) == '\0') &&
         (*(char *)((uint)p_menu_screen_state->field_0x7 + _LAB_030524ec + 2) == '\0')) {
        history_list_row_lookup(*_DAT_030524f0 + 1);
      }
    }
    else {
      write_status_mode_byte_pair(0x3f,1);
    }
  }
  return;
}


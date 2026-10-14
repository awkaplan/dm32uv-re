/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_or_channel_selection_key_dispatch @ 03052518 (file base 0x03000000; code starts at 0x03001000)
 * Size: 462 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_or_channel_selection_key_dispatch(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = p_text_entry_buffer;
  puVar2 = PTR_DAT_030526bc;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03052698 + 2);
  if (cVar1 == '\x02') {
    if (*(char *)((uint)p_menu_screen_state->index_0x5 + DAT_0305269c + 2) == '\x02') {
      cVar1 = *(char *)((uint)p_menu_screen_state->field_0x8 + DAT_030526a0 + 2);
      if (cVar1 == '\0') {
        history_list_row_lookup(*(short *)PTR_DAT_030526a4 + 1);
      }
      else if (cVar1 == '\x01') {
        iVar3 = ascii_digits_to_uint();
        if (iVar3 == 0) {
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_030526a8 + DAT_030526ac),0);
        }
        else {
          uVar5 = *p_text_entry_current_char_alias;
          *PTR_DAT_030526b4 = uVar5;
          if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
            uVar4 = 3;
          }
          else {
            uVar4 = 4;
          }
          channel_select_commit_and_notify
                    (uVar4,uVar5,p_text_entry_buffer,*(undefined1 *)PTR_DAT_030526bc,
                     p_dm32_settings_block04[0x54]);
        }
      }
    }
  }
  else if (cVar1 == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x6 + DAT_030526c8 + 2);
    if (cVar1 == '\x02') {
      cVar1 = *(char *)((uint)p_menu_screen_state->field_0x8 + DAT_030526a0 + 2);
      if (cVar1 == '\x02') {
        iVar3 = quick_text_insert_and_rewrap(*(undefined1 *)p_active_screen_state_word);
        if (iVar3 == 0) {
          write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_030526a8 + DAT_030526ac),0);
        }
        else {
          history_queue_pop();
          history_queue_pop();
        }
      }
      else if (cVar1 == '\x03') {
        buffer_prepend_3byte_le(0,p_text_entry_buffer,*(undefined1 *)PTR_DAT_030526bc);
        dialog_show_icon_and_two_numbers
                  (0x30,0x30,PTR_DAT_030526d8,
                   **(undefined4 **)
                     (PTR_PTR_030526d0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                   PTR_LAB_030526d4);
        contact_edit_save_flow1(uVar5,*(byte *)puVar2 + 3,5,0);
        OSTimeDly_ms_wrapper(1000);
        history_queue_pop();
        history_queue_pop();
      }
      else if (cVar1 == '\0') {
        history_list_row_lookup(*(short *)PTR_DAT_030526a4 + 1);
      }
      else if (cVar1 == '\x01') {
        uVar5 = *p_text_entry_current_char_alias;
        *PTR_DAT_030526b4 = uVar5;
        if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
          uVar4 = 3;
        }
        else {
          uVar4 = 4;
        }
        channel_select_commit_and_notify
                  (uVar4,uVar5,p_text_entry_buffer,*(undefined1 *)PTR_DAT_030526bc,
                   p_dm32_settings_block04[0x54]);
      }
      else {
        write_status_mode_byte_pair(*(undefined1 *)((uint)*_LAB_03052730 + _LAB_03052734),1);
      }
    }
    else if ((cVar1 == '\0') &&
            (*(char *)((uint)p_menu_screen_state->field_0x8 + _LAB_0305273c + 2) == '\x01')) {
      iVar3 = quick_text_insert_and_rewrap(*_p_active_screen_state_word);
      if (iVar3 == 0) {
        write_status_mode_byte_pair(*(undefined1 *)((uint)*_LAB_03052730 + _LAB_03052734),0);
      }
      else {
        history_queue_pop();
        history_queue_pop();
      }
    }
  }
  return;
}


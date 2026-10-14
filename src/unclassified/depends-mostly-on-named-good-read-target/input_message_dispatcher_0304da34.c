/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: input_message_dispatcher @ 0304da34 (file base 0x03000000; code starts at 0x03001000)
 * Size: 402 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void input_message_dispatcher(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = PTR_DAT_0304dbb4;
  uVar2 = p_text_entry_buffer;
  if (*(char *)PTR_active_screen_subtype_0304db88 == '\n') {
    if (*(char *)PTR_DAT_0304db8c == '\x03') {
      *(undefined1 *)PTR_DAT_0304db90 = 0xf0;
      *(undefined2 *)PTR_DAT_0304db98 = *(undefined2 *)p_text_entry_current_char;
      *(undefined2 *)p_text_entry_buffer_alias = *(undefined2 *)PTR_DAT_0304db9c;
      write_status_mode_byte_pair(0x23,1);
    }
    else {
      scan_state_tick();
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304db80 + DAT_0304db84),0);
    }
  }
  else {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304dba8 + 2);
    if (cVar1 == '\x01') {
      if (p_active_screen_index_list[*p_active_screen_state_word + 2] == '\x03') {
        buffer_prepend_3byte_le(0,p_text_entry_buffer,*(undefined1 *)PTR_DAT_0304dbb4);
        dialog_show_icon_and_two_numbers
                  (0x30,0x30,PTR_DAT_0304dbc4,
                   **(undefined4 **)
                     (PTR_PTR_0304dbbc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                   PTR_LAB_0304dbc0);
        contact_edit_save_flow1(uVar2,*(byte *)puVar3 + 3,5,0);
        OSTimeDly_ms_wrapper(1000);
        history_queue_pop();
        history_queue_pop();
      }
      else if (p_active_screen_index_list[*p_active_screen_state_word + 2] == '\x04') {
        history_queue_pop();
        history_queue_pop();
      }
      else {
        write_status_mode_byte_pair(0x23,1);
      }
    }
    else if (cVar1 == '\0') {
      if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304dbc8 + 2) == '\x01') {
        erase_stored_field_category_by_code(1);
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_0304dbcc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        write_status_mode_byte_pair(0x23,1);
      }
    }
    else if (cVar1 == '\x03') {
      if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304dbc8 + 2) == '\x01') {
        erase_stored_field_category_by_code(3);
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_0304dbcc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        write_status_mode_byte_pair(0x23,1);
      }
    }
    else if (cVar1 == '\x04') {
      if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304dcac + 2) == '\x01') {
        erase_stored_field_category_by_code(5);
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_0304dcb4 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else {
        write_status_mode_byte_pair(0x23,1);
      }
    }
    else {
      write_status_mode_byte_pair(0x23,1);
    }
  }
  return;
}


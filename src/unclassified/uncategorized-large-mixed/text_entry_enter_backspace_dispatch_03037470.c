/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_enter_backspace_dispatch @ 03037470 (file base 0x03000000; code starts at 0x03001000)
 * Size: 322 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_enter_backspace_dispatch(void)

{
  char cVar1;
  undefined1 *value;
  byte bVar2;
  
  if ((PTR_DAT_03037518[8] & 1) == 0) {
    if (*(char *)PTR_active_screen_subtype_03037508 == '\n') {
      if (*(char *)PTR_DAT_03037520 == '\x04') {
        tx_gate_write_call_record(1);
        scan_monitor_display_refresh();
        *(undefined1 *)PTR_DAT_03037520 = 3;
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037514),0);
      }
      else if ((*(char *)PTR_DAT_03037520 == '\x03') && (*(char *)PTR_DAT_0303765c == '\0')) {
        tx_gate_write_call_record(0);
        scan_mode_state_transition_handler();
      }
      else {
        tx_gate_write_call_record(1);
        cVar1 = *(char *)PTR_DAT_03037660;
        if (cVar1 == '\x02') {
          scan_list_row_init_and_render();
        }
        else if (cVar1 == '\x03') {
          text_entry_backspace_delete_char();
        }
        else if (cVar1 == '\x01') {
          dmr_scan_list_row_up_or_exit();
        }
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037668),0);
      }
    }
    else if (*(char *)PTR_active_screen_subtype_03037508 == '\b') {
      if ((*(char *)PTR_DAT_0303766c == '\0') ||
         ((p_radio_mode_state_0003e318->flags_0x6 & 0xc) != 0)) {
        history_queue_pop();
        text_entry_commit_and_clear_mode_flags();
        tx_gate_write_call_record(0);
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037668),0);
      }
      else {
        tx_gate_write_call_record(1);
        *(char *)PTR_DAT_0303766c = *(char *)PTR_DAT_0303766c + -1;
        *(short *)p_text_entry_current_char = *(short *)p_text_entry_current_char + -0xc;
        display_clear_status_row(0x20,0);
        display_format_id_with_separators();
        write_status_mode_byte_pair
                  (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_03037668),0);
      }
    }
  }
  else if (p_dialog_history_ui_state->field_0xa08 == 0) {
    tx_gate_write_call_record(0);
  }
  else {
    tx_gate_write_call_record(1);
    bVar2 = p_dialog_history_ui_state->field_0xa08 - 1;
    p_dialog_history_ui_state->field_0xa08 = bVar2;
    value = p_text_entry_buffer;
    p_text_entry_buffer[(uint)bVar2 * 2] = 0x5f;
    display_draw_number_centered(0x46,0xffff,0,(uint)value);
  }
  return;
}


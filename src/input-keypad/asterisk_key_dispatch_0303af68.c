/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: asterisk_key_dispatch @ 0303af68 (file base 0x03000000; code starts at 0x03001000)
 * Size: 428 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void asterisk_key_dispatch(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (((*(byte *)PTR_DAT_0303b0cc & 2) == 0) && ((PTR_DAT_0303b0d0[8] & 1) == 0)) {
    iVar3 = read_byte_field_03035a18();
    puVar2 = PTR_DAT_0303b104;
    if (iVar3 == 2) {
      tx_gate_write_call_record(1);
      status_message_save_on_confirm();
    }
    else if ((PTR_DAT_0303b0d4[1] == '\x01') || (PTR_DAT_0303b0d4[1] == '\x04')) {
      tx_gate_write_call_record(0);
      dialog_history_menu_step_and_refresh();
    }
    else if ((PTR_DAT_0303b0d4[3] & 1) == 0) {
      if ((*(byte *)p_call_active_flag & 8) == 0) {
        if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0) {
          if (p_dialog_history_ui_state->field_0x3 == 0x69) {
            if ((p_radio_mode_state_0003e318[1].flags_0x7 & 1) != 0) {
              settings_block4_array_entry_read(10,PTR_DAT_0303b104);
              iVar3 = list_screen_event_dispatch(*puVar2,(uint)*(uint3 *)(puVar2 + 1));
              if (iVar3 == 0) {
                ui_event_notify(0x21);
              }
            }
          }
          else if (p_dialog_history_ui_state->field_0x3 == 0) {
            iVar3 = get_current_mode_state1();
            if ((iVar3 == 0) && ((*PTR_DAT_0303b2b4 & 0x2008000) == 0)) {
              mode_transition_cleanup();
              p_radio_mode_state_0003e318[2].field_0x1 =
                   p_radio_mode_state_0003e318[2].field_0x1 & 0xfb |
                   (byte)(((p_radio_mode_state_0003e318[2].field_0x1 ^ 4) >> 2 & 1) << 2);
              vfo_ab_display_redraw_dispatch();
            }
            else {
              ui_event_notify(0x1b);
            }
          }
        }
        else if (*(byte *)PTR_DAT_0303b0f8 < *(byte *)PTR_DAT_0303b0fc) {
          write_flag_and_notify_ui_event0x29(0xe);
          text_input_append_byte_and_scroll(0x2a);
          display_format_id_with_separators();
        }
      }
      else if (*(char *)PTR_active_screen_subtype_0303b0ec == '\x18') {
        *(undefined1 *)PTR_DAT_0303b0f0 = 0x2a;
        dtmf_quicktext_scroll_display_dispatch();
      }
      else {
        *(undefined1 *)PTR_DAT_0303b0f0 = 0x2a;
        write_status_mode_byte_pair(0x70,1);
      }
    }
    else {
      if ((*(byte *)((int)PTR_DAT_0303b0cc + 3) & 2) != 0) {
        radio_idle_state_reset(0);
      }
      puVar1 = PTR_DAT_0303b0d4;
      PTR_DAT_0303b0d4[1] = 1;
      display_draw_dialog_panel();
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_0303b0e4,
                 **(undefined4 **)
                   (PTR_PTR_0303b0dc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 PTR_LAB_0303b0e0);
      tx_gate_write_call_record(1);
      OSTimeDly_ms_wrapper(1000);
      puVar1[3] = puVar1[3] & 0xfe;
      history_queue_pop();
    }
  }
  return;
}


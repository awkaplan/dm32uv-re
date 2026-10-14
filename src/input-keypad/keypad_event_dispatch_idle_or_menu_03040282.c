/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: keypad_event_dispatch_idle_or_menu @ 03040282 (file base 0x03000000; code starts at 0x03001000)
 * Size: 982 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: input-keypad
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void keypad_event_dispatch_idle_or_menu(void)

{
  char cVar1;
  undefined4 *puVar2;
  radio_mode_state_0003e318 *prVar3;
  radio_mode_state_0003e318 *prVar4;
  dialog_history_ui_state *pdVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  int unaff_r4;
  undefined4 in_stack_00000004;
  
  if ((p_dialog_flags_from_flash->flags_0x1 & 3) == 0) {
    iVar6 = get_current_mode_state1();
    puVar2 = PTR_DAT_03040478;
    if (iVar6 == 0) {
      cVar1 = PTR_DAT_03040464[1];
      if (((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x02')) {
        tx_gate_write_call_record(0);
        dialog_history_menu_step_and_refresh();
      }
      else if (((PTR_DAT_03040468[8] & 1) == 0) && ((*(byte *)PTR_DAT_0304046c & 2) == 0)) {
        if (p_dialog_history_ui_state->field_0x3 == 0x69) {
          if ((p_radio_mode_state_0003e318[1].flags_0x7 & 1) != 0) {
            settings_block4_array_entry_read(0xb,PTR_DAT_03040478);
            iVar6 = list_screen_event_dispatch(*puVar2,(uint)*(uint3 *)(puVar2 + 1));
            if (iVar6 == 0) {
              ui_event_notify(0x21);
            }
          }
        }
        else {
          iVar6 = vfo_active_side_mode_nibble();
          prVar4 = p_radio_mode_state_0003e318;
          prVar3 = p_radio_mode_state_0003e318;
          SUBPIECE_SET(in_stack_00000004, 3, 1, (byte)iVar6);
          if ((*(byte *)p_call_active_flag & 8) == 0) {
            if (p_dialog_history_ui_state->index_0x2 == 1) {
              if ((*PTR_DAT_0304046c & 0x18000) == 0x8000) {
                if ((*(byte *)((int)PTR_DAT_0304046c + 2) & 2) == 0) {
                  seek_banner_draw(~((p_dm32_settings_block04[0x2d] & 0x80) != 0));
                  rda5807m_seek_up(*(undefined2 *)PTR_DAT_03040488);
                  *(byte *)((int)PTR_DAT_0304046c + 2) =
                       *(byte *)((int)PTR_DAT_0304046c + 2) & 0xfd | 2;
                }
              }
              else {
                iVar6 = get_current_mode_state2();
                if ((iVar6 != 0) &&
                   (iVar6 = get_current_mode_state2(), puVar2 = PTR_DAT_0304048c, iVar6 != 4)) {
                  *(byte *)PTR_DAT_0304048c = *(byte *)PTR_DAT_0304048c & 0xfb | 4;
                  vfo_exit_dual_watch_and_refresh();
                  *(byte *)puVar2 = *(byte *)puVar2 & 0xfb;
                }
                if ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0) {
                  if (SUBPIECE_SET(in_stack_00000004, 3, 1, = 2) {
                    PTR_DAT_03040618[3] = PTR_DAT_03040618[3] & 0xfd | 2);
                    ui_event_notify_alt(0xd);
                    SUBPIECE_SET(in_stack_00000004, 3, 1, 0);
                  }
                  if (*(byte *)PTR_DAT_0304061c < 200) {
                    if (SUBPIECE_SET(in_stack_00000004, 3, 1, = 0) {
                      p_radio_mode_state_0003e318->flags_0x5 =
                           p_radio_mode_state_0003e318->flags_0x5 & 0xef | 0x10);
                      write_status_mode_byte_pair(0x70);
                    }
                    else {
                      flash_field_read_cached(4,0x504,(int)&stack0x00000004 + 3,1);
                      if ((SUBPIECE(in_stack_00000004, 3, 1) & 0x40) == 0) {
                        ui_event_notify(0x21);
                      }
                      else {
                        ui_event_notify(0x18);
                        menu_screen_entry_generic8();
                      }
                    }
                  }
                  else if ((PTR_DAT_03040624[3] & 2) == 0) {
                    if ((PTR_DAT_03040624[1] & 0x80) == 0) {
                      mode_transition_cleanup();
                      bVar7 = p_vfo_display_state->flags_0x8 & 0xf0;
                      if ((bVar7 == 0) || (bVar7 == 0x20)) {
                        tx_abort_and_radio_state_reset();
                      }
                      else {
                        ui_event_notify(0x21);
                      }
                    }
                    else {
                      ui_event_notify(0x21);
                    }
                  }
                  else {
                    radio_idle_state_reset(1);
                  }
                }
                else {
                  ui_event_notify(0x21);
                }
              }
            }
            else if (((iVar6 == 1) || (iVar6 == 3)) &&
                    ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
              if (((p_radio_mode_state_0003e318->flags_0x5 & 0x40) == 0) ||
                 (*(char *)PTR_active_screen_subtype_0304062c != '\b')) {
                if ((p_radio_mode_state_0003e318->flags_0x5 & 4) == 0) {
                  tx_gate_call_record_on_newline_marker();
                  event_record_guarded_by_state_flags();
                }
                else {
                  p_radio_mode_state_0003e318->flags_0x3 =
                       p_radio_mode_state_0003e318->flags_0x3 & 0xfb |
                       (p_radio_mode_state_0003e318->flags_0x3 >> 2 & 1 ^ 1) << 2;
                  tx_gate_write_call_record(1);
                  display_fill_rect(0,0,200,0x1a,0);
                  display_draw_number_centered
                            (1,0xffff,0,
                             *(uint *)(PTR_PTR_03040808
                                       [(byte)p_dm32_settings_block04[0x30] >> 6 & 1] +
                                      (prVar4->flags_0x3 >> 2 & 1) * 4));
                }
              }
              else {
                p_radio_mode_state_0003e318->flags_0x3 =
                     p_radio_mode_state_0003e318->flags_0x3 & 0xfb |
                     (p_radio_mode_state_0003e318->flags_0x3 >> 2 & 1 ^ 1) << 2;
                tx_gate_write_call_record(1);
                display_fill_rect(0,0,200,0x1a,0);
                display_draw_number_centered
                          (1,0xffff,0,
                           *(uint *)(PTR_PTR_03040634[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]
                                    + (prVar3->flags_0x3 >> 2 & 1) * 4));
                if (*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_0304063c + 2) == '\0') {
                  display_fill_rect(0,0x122,0xf0,0x140,0);
                  display_draw_gb2312_label_bottom_by_config_bit(0);
                  if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
                    display_draw_gb2312_label_top_alt(0);
                  }
                }
              }
            }
            else if ((p_radio_mode_state_0003e318->flags_0x5 & 0x10) == 0) {
              tx_gate_call_record_on_newline_marker();
              event_record_guarded_by_state_flags();
            }
            else if (*(byte *)PTR_DAT_0304080c < *(byte *)PTR_DAT_03040810) {
              write_flag_and_notify_ui_event0x29(0xf);
              text_input_append_byte_and_scroll(0x23);
              display_format_id_with_separators();
            }
          }
          else if (*(char *)PTR_active_screen_subtype_03040480 == '\x18') {
            *(undefined1 *)PTR_DAT_03040460 = 0x23;
            dtmf_quicktext_scroll_display_dispatch();
          }
          else {
            *(undefined1 *)PTR_DAT_03040460 = 0x23;
            write_status_mode_byte_pair(0x70,1);
          }
        }
      }
    }
    else if ((*(byte *)p_call_active_flag & 8) == 0) {
      dtmf_inject_digits_2_0();
      tx_gate_write_call_record(0);
    }
    else if (*(char *)PTR_active_screen_subtype_030402e4 == '\x18') {
      *(undefined1 *)PTR_DAT_030402e8 = 0x23;
      dtmf_quicktext_scroll_display_dispatch();
    }
    else {
      *(undefined1 *)PTR_DAT_03040460 = 0x23;
      write_status_mode_byte_pair(0x70,1);
    }
  }
  else {
    tx_gate_write_call_record(0);
  }
  if (p_dialog_history_ui_state->field_0x4 != 0) {
    history_entry_cancel_pending();
    pdVar5 = p_dialog_history_ui_state;
    uVar8 = PTR_PTR_03040818[(uint)p_dialog_history_ui_state->field_0x3 * 3];
    *PTR_DAT_0304081c = uVar8;
    (*(code *)(uVar8 & 0xfffffffe))();
    pdVar5->field_0x4 = 0;
  }
  if (unaff_r4 == 0x18) {
    PTR_DAT_03040820[1] = 0;
  }
  os_sem_post(p_ucos_mutex_0003e4c0);
  return;
}


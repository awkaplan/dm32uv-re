/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_event_code_dispatch_main @ 0303fa04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 396 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_event_code_dispatch_main(void)

{
  byte bVar1;
  dialog_history_ui_state *pdVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = keymsgq_command_dispatch_and_store();
  uVar5 = uVar3 - 1;
  if (uVar5 < 0x17) {
    event_queue_reset();
    if (((*(byte *)p_call_active_flag & 2) != 0) && ((*(byte *)PTR_DAT_0303fb94 & 2) == 0)) {
      if ((*(byte *)p_dialog_flags_from_flash & 1) == 0) {
        return;
      }
      if (*(char *)((int)PTR_DAT_0303fb9c + 1) == '\0') {
        dialog_idle_ready_state_trigger();
      }
      goto LAB_0303fb46;
    }
    if (PTR_DAT_0303fba0[1] != '\0') {
      return;
    }
    if (((((((*(byte *)p_call_active_flag & 1) != 0) ||
           (iVar4 = get_field_0301ea64_0x14(), iVar4 == 1)) && (1 < uVar5)) &&
         ((uVar3 != 6 && (uVar3 != 5)))) && (uVar3 != 0x17)) &&
       ((9 < uVar3 - 8 && ((*(char *)PTR_active_screen_subtype_0303fba4 != '\n' || (uVar3 != 0x13)))
        ))) {
      tx_gate_write_call_record(0);
      return;
    }
    if (((((*(byte *)p_call_active_flag & 2) != 0) ||
         (iVar4 = get_field_0301ea64_0x14(), iVar4 == 2)) && (1 < uVar5)) &&
       (((*(byte *)p_call_active_flag & 2) != 0 || (uVar3 != 6)))) {
      tx_gate_write_call_record(0);
      return;
    }
    if ((((*(byte *)((int)PTR_DAT_0303fb94 + 3) & 2) != 0) && (1 < uVar5)) &&
       ((uVar3 != 0x12 && (1 < uVar3 - 5)))) {
      tx_gate_write_call_record(0);
      return;
    }
    if ((((p_dialog_flags_from_flash->flags_0x1 & 3) != 0) || (p_tx_ptt_ui_state->field_0x7 == 4))
       && (1 < uVar5)) {
      dialog_clear_flag_bit2_at_1();
      tx_gate_write_call_record(0);
      return;
    }
    if ((p_dialog_flags_from_flash->flags_0x1e & 0x70) == 0x20) {
      return;
    }
    if (uVar3 != 6) goto LAB_0303fb46;
    dialog_tick_idle_check();
    os_sem_pend_ms(p_ucos_mutex_0003e4c0,0);
    PTR_DAT_0303fbb0[10] = 0;
LAB_0303fb60:
    if (*(char *)((int)PTR_DAT_0303fb9c + 1) == '\0') {
      *(undefined1 *)PTR_DAT_0303fb9c = 0;
    }
    if ((p_dialog_flags_from_flash->flags_0x2d & 4) != 0) {
      dialog_clear_flag_bit2_at_1_variant_0305d91c();
    }
  }
  else {
LAB_0303fb46:
    if (0x22 < uVar3) {
      os_sem_pend_ms(p_ucos_mutex_0003e4c0,0);
      if (uVar3 == 0x2c) {
        if (p_dialog_history_ui_state->field_0x3 == 0x54) {
          history_queue_pop();
        }
        bVar1 = p_dialog_history_ui_state->field_0x3;
        write_status_mode_byte_pair(0x5b,1);
        if (bVar1 != 0x5b) {
          dialog_history_flush_and_reset();
        }
        p_dialog_history_ui_state->field_0x4 = 0;
        goto LAB_03040a6a;
      }
      if (uVar3 < 0x2d) {
        if (uVar3 != 0x26) {
          if (uVar3 < 0x27) {
            if (uVar3 == 0x24) {
              if ((*(byte *)PTR_DAT_03040828 & 2) == 0) {
                if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0x10) {
                  call_teardown_and_history_dispatch();
                }
                else {
                  if ((*(byte *)p_call_active_flag & 8) != 0) {
                    PTR_DAT_03040834[1] = PTR_DAT_03040834[1] & 0xfe;
                    channel_switch_teardown_and_apply();
                    if ((PTR_DAT_03040838[6] & 2) != 0) {
                      PTR_DAT_03040838[6] = PTR_DAT_03040838[6] & 0xfd;
                      ui_event_notify(0x1b);
                    }
                    PTR_DAT_03040834[1] = PTR_DAT_03040834[1] & 0xfe | 1;
                  }
                  call_teardown_and_history_dispatch();
                }
                *(undefined1 *)PTR_DAT_0304083c = 0;
                PTR_DAT_03040840[1] = PTR_DAT_03040840[1] & 0xfc;
              }
            }
            else if ((uVar3 == 0x25) && ((*(byte *)PTR_DAT_030409e0 & 0x40) == 0)) {
              if (p_dialog_history_ui_state->field_0x3 == 0x5b) {
                p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xf7 | 8;
              }
              else if (p_dialog_history_ui_state->field_0x3 != 0x54) {
                if (p_dialog_history_ui_state->field_0x3 == 0x46) {
                  channel_info_screen_refresh();
                }
                else if (p_dialog_history_ui_state->field_0x3 == 0x4d) {
                  menu_confirm_apply_handler3();
                }
              }
            }
          }
          else if (uVar3 == 0x2a) {
            screen_mode_static_table_dispatch();
          }
          else if (uVar3 == 0x2b) {
            history_entry_cancel_pending();
            pdVar2 = p_dialog_history_ui_state;
            uVar3 = PTR_PTR_030409d8[(uint)p_dialog_history_ui_state->field_0x3 * 3];
            *PTR_DAT_030409dc = uVar3;
            (*(code *)(uVar3 & 0xfffffffe))();
            pdVar2->field_0x4 = 0;
          }
          goto LAB_03040a6a;
        }
      }
      else {
        if (uVar3 == 0x2f) {
          settings_set_menu_hold_interval(p_dm32_settings_block04[0x3a]);
          reentrant_state_reset_sequence();
          ring_buffer_multi_table_append_and_flush();
          write_status_mode_byte_pair(0x4d,0);
          menu_confirm_apply_handler3();
          goto LAB_03040a6a;
        }
        if (uVar3 < 0x30) {
          if (uVar3 == 0x2d) {
            bVar1 = p_dialog_history_ui_state->field_0x3;
            write_status_mode_byte_pair(0x54,0);
            if (bVar1 != 0x54) {
              ring_buffer_multi_table_append_and_flush();
            }
            gps_lock_status_or_band_select_screen(1);
          }
          else if (uVar3 == 0x2e) {
            iVar4 = read_byte_field_0302e118();
            if (iVar4 == 0) {
              reentrant_state_reset_sequence();
              ring_buffer_multi_table_append_and_flush();
              write_status_mode_byte_pair(0x46,0);
              channel_info_screen_refresh();
            }
            else if (((p_dm32_settings_block04[0x43] & 1) != 0) &&
                    ((*(byte *)PTR_DAT_030409ec & 4) == 0)) {
              character_input_event_dispatcher(0x21);
            }
          }
          goto LAB_03040a6a;
        }
        if (uVar3 == 100) {
          dialog_show_number_or_alt();
          goto LAB_03040a6a;
        }
        if (uVar3 == 0xfe) {
          if (p_dialog_history_ui_state->field_0x3 == 0x54) {
            gps_lock_status_or_band_select_screen(0);
          }
          else {
            uVar3 = PTR_PTR_030409d8[(uint)p_dialog_history_ui_state->field_0x3 * 3];
            *PTR_DAT_030409dc = uVar3;
            (*(code *)(uVar3 & 0xfffffffe))();
          }
          goto LAB_03040a6a;
        }
        if (uVar3 != 0x30) goto LAB_03040a6a;
      }
      if (p_dialog_history_ui_state->field_0x3 == 0x54) {
        *PTR_DAT_030409f0 = 0;
      }
      if ((p_radio_mode_state_0003e318->flags_0x6 & 4) == 0) {
        if ((p_radio_mode_state_0003e318[1].flags_0x7 & 1) == 0) {
          history_queue_pop();
          if (p_dialog_history_ui_state->field_0x3 == 0x77) {
            history_queue_pop();
          }
        }
        else {
          p_radio_mode_state_0003e318[1].flags_0x7 = p_radio_mode_state_0003e318[1].flags_0x7 & 0xfe
          ;
          history_queue_pop();
          history_queue_pop();
        }
        if ((*(char *)PTR_DAT_03040b48 != '\0') &&
           ((p_dialog_flags_from_flash->flags_0x1e & 0x70) != 0x20)) {
          history_queue_pop();
          history_queue_pop();
        }
      }
      else {
        p_dialog_history_ui_state->field_0x3 = 0;
      }
      history_entry_cancel_pending();
      pdVar2 = p_dialog_history_ui_state;
      uVar3 = PTR_PTR_03040b50[(uint)p_dialog_history_ui_state->field_0x3 * 3];
      *PTR_DAT_03040b54 = uVar3;
      (*(code *)(uVar3 & 0xfffffffe))();
      pdVar2->field_0x4 = 0;
      goto LAB_03040a6a;
    }
    os_sem_pend_ms(p_ucos_mutex_0003e4c0,0);
    PTR_DAT_0303fbb0[10] = 0;
    if (uVar5 < 0x17) goto LAB_0303fb60;
  }
  if (uVar3 < 0x19) {
                    /* WARNING: Could not recover jumptable at 0x0303fb8e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0303fbb4[uVar3] & 0xfffffffe))();
    return;
  }
  if (p_dialog_history_ui_state->field_0x4 != 0) {
    history_entry_cancel_pending();
    pdVar2 = p_dialog_history_ui_state;
    uVar5 = PTR_PTR_03040818[(uint)p_dialog_history_ui_state->field_0x3 * 3];
    *PTR_DAT_0304081c = uVar5;
    (*(code *)(uVar5 & 0xfffffffe))();
    pdVar2->field_0x4 = 0;
  }
  if (uVar3 == 0x18) {
    PTR_DAT_03040820[1] = 0;
  }
LAB_03040a6a:
  os_sem_post(p_ucos_mutex_0003e4c0);
  return;
}


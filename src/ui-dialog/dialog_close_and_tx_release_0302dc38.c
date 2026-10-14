/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_close_and_tx_release @ 0302dc38 (file base 0x03000000; code starts at 0x03001000)
 * Size: 724 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_close_and_tx_release(void)

{
  tx_ptt_ui_state *ptVar1;
  tx_ptt_ui_state *ptVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  undefined1 auStack_8 [4];
  
  bVar4 = p_tx_ptt_ui_state->field_0x7;
  if (bVar4 == 0) {
    if ((p_dialog_flags_from_flash->field_0x30 & 1) != 0) {
      ui_event_notify_alt(5);
      dialog_close_reset();
      p_dialog_flags_from_flash->field_0x30 = p_dialog_flags_from_flash->field_0x30 & 0xfe;
    }
    if ((p_tx_ptt_ui_state->flags_0xb & 0x20) != 0) {
      if ((PTR_DAT_0302ddac[10] & 1) != 0) {
        PTR_DAT_0302ddac[10] = PTR_DAT_0302ddac[10] & 0xfe;
      }
      ptVar1 = p_tx_ptt_ui_state;
      bVar4 = p_tx_ptt_ui_state->field_0x2 + 1;
      p_tx_ptt_ui_state->field_0x2 = bVar4;
      ptVar2 = p_tx_ptt_ui_state;
      if ((ptVar1->field_0x5f & 2) == 0) {
        bVar5 = 5;
      }
      else {
        bVar5 = 0x1e;
      }
      if (bVar5 < bVar4) {
        p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xdf;
        ptVar2->flags_0xa = ptVar2->flags_0xa & 0xcf;
        ptVar2->field_0xc = ptVar2->field_0xc & 0xef;
        ptVar2->field_0x5f = ptVar2->field_0x5f & 0xfd;
        PTR_DAT_0302ddb0[3] = PTR_DAT_0302ddb0[3] & 0xbf;
        p_dialog_flags_from_flash->flags_0x1e = p_dialog_flags_from_flash->flags_0x1e & 0xf0;
        if (((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) != 0) &&
           (p_radio_mode_state_0003e318[1].flags_0x6 =
                 p_radio_mode_state_0003e318[1].flags_0x6 & 0x7f, PTR_DAT_0302ddb8[1] != 0)) {
          ui_event_notify_alt(0x17);
        }
        if (*(char *)PTR_DAT_0302ddbc == '[') {
          if (((byte)(p_tx_ptt_ui_state->field_0x9 - 2) < 2) &&
             ((p_dm32_settings_block04[0x43] & 8) != 0)) {
            character_input_event_dispatcher(0x27);
          }
          ptVar1 = p_tx_ptt_ui_state;
          p_tx_ptt_ui_state->field_0x9 = 0;
          if ((ptVar1->field_0xc & 1) == 0) {
            if ((PTR_DAT_0302df1c[0x2b] & 8) == 0) {
              write_field_and_mbox_post(1,0x30);
            }
          }
          else {
            p_tx_ptt_ui_state->field_0xc = p_tx_ptt_ui_state->field_0xc & 0xfe;
            if ((PTR_DAT_0302ddc0[0x2b] & 8) == 0) {
              history_queue_pop();
              if ((PTR_DAT_0302ddc4[1] & 0x80) != 0) {
                rda5807m_fm_off();
              }
              check_mode_nibble_eq1_then_write_field_0x2f();
            }
          }
        }
        p_tx_ptt_ui_state->field_0x9 = 0;
      }
    }
    if ((p_tx_ptt_ui_state->flags_0xa & 4) != 0) {
      p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfb;
    }
    if ((((p_radio_mode_state_0003e318[2].flags_0x2 & 1) != 0) &&
        ((*(byte *)PTR_DAT_0302df28 & 0x90) == 0x80)) &&
       (*(char *)((int)PTR_DAT_0302df28 + 3) == '\0')) {
      tx_release_debounce_timer();
    }
  }
  else {
    if ((p_tx_ptt_ui_state->flags_0xb & 0x20) != 0) {
      p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xdf;
    }
    if (*(char *)PTR_DAT_0302df2c == '[') {
      bVar5 = 0;
    }
    else {
      bVar5 = ~((p_tx_ptt_ui_state->flags_0xb & 0x20) != 0);
    }
    if ((*(char *)PTR_DAT_0302df2c != 'T') && (bVar5 != 0)) {
      if ((byte)(bVar4 - 2) < 2) {
        if (((*(byte *)p_call_active_flag & 1) == 0) &&
           (iVar3 = get_field_0301ea64_0x14(), iVar3 != 1)) {
          OSTmr_state_dispatch_callback(p_ucos_tmr_inputcursor,0,0,auStack_8);
        }
        else {
          p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xbf | 0x40;
        }
      }
      p_tx_ptt_ui_state->field_0x9 = p_tx_ptt_ui_state->field_0x7;
      write_field_and_mbox_post(1,0x2c);
    }
    tx_release_debounce_timer();
    tx_dialog_state_machine_tick();
    if (*(char *)PTR_DAT_0302df2c == '[') {
      os_sem_pend_ms(p_ucos_mutex_0003e098,0);
      if ((p_tx_ptt_ui_state->flags_0xa & 4) != 0) {
        p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0xfb;
      }
      bVar4 = p_tx_ptt_ui_state->field_0x7;
      if ((byte)(bVar4 - 2) < 2) {
        talker_alias_display_debounce_tick();
      }
      else if (bVar4 == 5) {
        caller_info_dialog_show_and_clear_flags();
      }
      else if (bVar4 == 4) {
        post_dialog_close_screen_dispatch();
      }
      else if (bVar4 == 1) {
        handle_incoming_call_display();
      }
      else if (bVar4 == 6) {
        contact_field_dialog_state_advance();
      }
      else if (bVar4 == 7) {
        dialog_panel_update_tick();
      }
      else if (bVar4 == 8) {
        status_datetime_dialog_pending_check();
      }
      os_sem_post(p_ucos_mutex_0003e098);
    }
  }
  return;
}


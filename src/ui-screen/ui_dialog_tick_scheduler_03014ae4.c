/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_dialog_tick_scheduler @ 03014ae4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 512 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 ui_dialog_tick_scheduler(int param_1)

{
  dialog_flags_from_flash *pdVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*PTR_DAT_03014ba4 & 0x40) == 0) {
    if ((PTR_DAT_03014ba4[3] & 2) == 0) {
      dialog_clear_flag_bit2_at_1();
      pdVar1 = p_dialog_flags_from_flash;
      if ((p_dialog_flags_from_flash->flags_0x1 & 3) == 1) {
        if (p_dialog_flags_from_flash->field_0x32 == 1) {
          return 0;
        }
        if (p_dialog_flags_from_flash->field_0x3f == 5) {
          return 0;
        }
        if ((byte)(p_dialog_flags_from_flash->field_0x32 - 3) < 2) {
          p_dialog_flags_from_flash->field_0x32 = 2;
          pdVar1->field_0x3f = 2;
          if ((*(byte *)p_call_active_flag & 8) != 0) {
            tx_led_or_tone_off_conditional();
          }
          write_field_0x18_bit7(0);
          p_tx_ptt_ui_state->flags_0xa = p_tx_ptt_ui_state->flags_0xa & 0x7f | 0x80;
        }
        if (p_dialog_flags_from_flash->field_0x33 == 1) {
          ui_event_notify_alt(5);
          dialog_close_reset();
        }
        if ((p_dialog_flags_from_flash->flags_0x1f & 0x78) == 0x20) {
          if ((p_dialog_flags_from_flash->field_0x20 & 0x10) != 0) {
            return 0;
          }
          dialog_flags_dismiss_if_state_0x20();
        }
      }
      else if (((*(byte *)p_call_active_flag & 4) != 0) ||
              (p_radio_mode_state_0003e318[1].flags_0x2 != 0)) {
        *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfb;
        tx_timeout_cleanup();
      }
      iVar3 = keypad_dispatch_not_inhibited();
      if (iVar3 == 0) {
        uVar2 = 0;
      }
      else if ((p_radio_mode_state_0003e318->flags_0x7 & 0x18) == 0) {
        if ((*(byte *)p_call_active_flag & 8) == 0) {
          if (((*(byte *)p_call_active_flag & 2) == 0) ||
             ((*(byte *)p_dialog_flags_from_flash & 1) != 0)) {
            dialog_tick_idle_check();
            if ((*(byte *)p_dialog_flags_from_flash & 1) != 0) {
              dialog_idle_ready_state_trigger();
            }
            if (PTR_DAT_03014d04[0x328] == '\x01') {
              PTR_DAT_03014d08[10] = PTR_DAT_03014d08[10] & 0xfe | 1;
              dialog_history_show_if_present();
              PTR_DAT_03014d04[0x328] = 0;
            }
            if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x40) == 0) {
              if (((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) != 0) &&
                 (p_radio_mode_state_0003e318[1].flags_0x6 =
                       p_radio_mode_state_0003e318[1].flags_0x6 & 0x7f, PTR_DAT_03014d10[1] != 0)) {
                ui_event_notify_alt(0x17);
              }
            }
            else {
              p_radio_mode_state_0003e318[1].flags_0x6 =
                   p_radio_mode_state_0003e318[1].flags_0x6 & 0xbf;
              if (PTR_DAT_03014d0c[1] != 0) {
                ui_event_notify_alt(0x15);
              }
            }
            if ((p_dialog_flags_from_flash->flags_0x2d & 4) != 0) {
              clear_field_bit3_and_set_dialog_bit();
            }
            if (param_1 == 0) {
              if ((PTR_DAT_03014d14[1] & 1) == 0) {
                uVar2 = 1;
              }
              else {
                PTR_DAT_03014d14[1] = PTR_DAT_03014d14[1] & 0xfe;
                uVar2 = 1;
              }
            }
            else {
              uVar2 = 1;
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        ui_event_notify(0x1b);
        uVar2 = 0;
      }
    }
    else {
      radio_idle_state_reset(1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


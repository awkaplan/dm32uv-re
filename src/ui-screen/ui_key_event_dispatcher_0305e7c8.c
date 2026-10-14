/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_key_event_dispatcher @ 0305e7c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 502 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ui_key_event_dispatcher(void)

{
  dialog_flags_from_flash *pdVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  void *arg;
  byte bVar5;
  uint uVar6;
  
  bVar2 = get_event_flags_byte_dispatch(0xf);
  pdVar1 = p_dialog_flags_from_flash;
  bVar5 = bVar2 & 0xf;
  uVar6 = CONCAT31(extraout_var,bVar2) >> 4 & 0xff;
  if ((bVar2 & 0xf) != 0) {
    if (bVar5 == 1) {
      tx_led_or_tone_on();
      return;
    }
    if (bVar5 == 2) {
      p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xf1 | 6;
      if (uVar6 != 6) {
        return;
      }
      if ((pdVar1->flags_0x2f & 0x70) != 0) {
        p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x10;
      }
      *(undefined1 *)p_tx_ptt_ui_state = 10;
      return;
    }
    if (bVar5 == 3) {
      ui_event_notify(0x1b);
      return;
    }
    if (bVar5 == 4) {
      p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xf1 | 4;
      if (uVar6 == 6) {
        if ((pdVar1->flags_0x2f & 0x70) != 0) {
          p_dialog_flags_from_flash->flags_0x1f =
               p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x18;
        }
        *(undefined1 *)p_tx_ptt_ui_state = 10;
        return;
      }
      if (uVar6 != 2) {
        return;
      }
      dialog_state_set_2bit_at_1(1);
      return;
    }
    if (bVar5 == 5) {
      p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xf1 | 6;
      return;
    }
    if (bVar5 != 6) {
      return;
    }
    tx_led_or_tone_on();
    OSTimeDly_ms_wrapper(0x3c);
    arg = (void *)dialog_state_get_field_0301ecbc();
    if (uVar6 == 1) {
      if ((p_dialog_flags_from_flash->flags_0x2d & 4) == 0) {
        *(void **)&p_dialog_flags_from_flash->field_0x24_0 = arg;
        dialog_state_set_bit3_wrapper(1);
      }
      p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xf3 | 0xc;
      return;
    }
    if (uVar6 == 2) {
      OSTimeDly_ms_wrapper(0x3c);
      dialog_enter_mode2();
      call_setup_sm_reset();
      fd6818b_reg50_tx_audio_unmute_set();
      dialog_request_enqueue(1,arg);
      return;
    }
    if (uVar6 == 3) {
      settings_set_menu_hold_interval(p_dm32_settings_block04[0x3a]);
      ptt_release_handler();
      return;
    }
    if (uVar6 == 4) {
      iVar3 = keypad_dispatch_not_inhibited();
      if (iVar3 != 0) {
        return;
      }
      settings_write_0xf00_wrapper(0xa0);
      flash_quad_enable_and_system_reset();
      return;
    }
    if (uVar6 == 5) {
      return;
    }
    if (uVar6 != 6) {
      return;
    }
    dialog_state_set_flag_0xc(2);
    iVar3 = get_current_mode_state2();
    if (iVar3 != 0) {
      set_flag_byte_03064328(4);
    }
    pdVar1 = p_dialog_flags_from_flash;
    *(void **)&p_dialog_flags_from_flash->field_0x4_0 = arg;
    uVar4 = dialog_state_get_field_0x10();
    *(undefined4 *)&pdVar1->field_0x8_0 = uVar4;
    pdVar1->flags_0x1 = pdVar1->flags_0x1 & 0xf8 | 6;
    return;
  }
  iVar3 = keypad_dispatch_not_inhibited();
  if (iVar3 == 0) {
    if (uVar6 == 6) goto LAB_0305e808;
  }
  else {
    if (uVar6 == 6) {
      if (1 < (byte)(p_dialog_flags_from_flash->field_0x32 - 3)) {
        tx_led_or_tone_off_conditional();
      }
LAB_0305e808:
      dialog_state_set_flag_0xc(1);
      pdVar1 = p_dialog_flags_from_flash;
      p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 8;
      pdVar1->flags_0x1 = pdVar1->flags_0x1 & 0xfc | 1;
      uVar4 = dialog_state_get_field_0x8();
      *(undefined4 *)&pdVar1->field_0x28_0 = uVar4;
      goto LAB_0305e84e;
    }
    tx_led_or_tone_off_conditional();
  }
  *(undefined1 *)p_tx_ptt_ui_state = 8;
  pdVar1 = p_dialog_flags_from_flash;
  p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xf0 | 3;
  pdVar1->flags_0x1e = pdVar1->flags_0x1e & 0xf0 | bVar2 >> 4;
  uVar4 = dialog_state_get_field_0x8();
  *(undefined4 *)&pdVar1->field_0x28_0 = uVar4;
LAB_0305e84e:
  *(undefined1 *)p_tx_ptt_ui_state = 10;
  return;
}


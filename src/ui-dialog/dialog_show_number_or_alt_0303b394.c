/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_show_number_or_alt @ 0303b394 (file base 0x03000000; code starts at 0x03001000)
 * Size: 710 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_show_number_or_alt(void)

{
  ushort uVar1;
  radio_mode_state_0003e318 *prVar2;
  undefined1 *puVar3;
  tx_ptt_ui_state *ptVar4;
  int iVar5;
  undefined1 auStack_3c [52];
  
  iVar5 = keypad_dispatch_not_inhibited();
  if (iVar5 == 0) {
    display_clear_fullscreen();
    iVar5 = read_byte_field_0305dbf4();
    if (iVar5 == 0xa5) {
      display_draw_number_centered
                (100,0xffff,0,
                 *(uint *)(PTR_PTR_0303b500[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                          0xc));
    }
    else {
      display_draw_number_centered
                (100,0xffff,0,PTR_PTR_0303b504[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
    }
  }
  else if ((*(byte *)PTR_DAT_0303b508 & 2) == 0) {
    if ((PTR_DAT_0303b51c[8] & 1) == 0) {
      reentrant_state_reset_sequence();
      SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318->flags_0x6);
      SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318->flags_0x7);
      if ((((uVar1 & 0x180) == 0) && ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) != 0)) &&
         ((p_dm32_settings_block04[0x5d] & 1) != 0)) {
        ui_event_notify(0x20);
      }
      standby_screen_refresh_with_statusbar();
      prVar2 = p_radio_mode_state_0003e318;
      p_radio_mode_state_0003e318->flags_0x3 = p_radio_mode_state_0003e318->flags_0x3 & 0x7f;
      *(undefined1 *)PTR_DAT_0303b520 = 0;
      *(byte *)PTR_DAT_0303b524 = *(byte *)PTR_DAT_0303b524 & 0xfe;
      prVar2[1].flags_0x7 = prVar2[1].flags_0x7 & 0xfe;
      memset_bytes(_DAT_0303b528,0,10);
      text_entry_commit_and_clear_mode_flags();
      PTR_DAT_0303b52c[0x12] = 0;
      if ((*(byte *)(PTR_DAT_0303b508 + 1) & 0x20) == 0) {
        vfo_screen_redraw();
      }
      else {
        if ((*PTR_DAT_0303b508 & 0x18000) == 0x8000) {
          battery_value_display_format((uint)~(int)(char)p_dm32_settings_block04[0x2d] >> 0x1f);
        }
        else {
          if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
            vfo_record_read(auStack_3c,0);
            memcpy_ck803s(DAT_0303b69c,auStack_3c,0x33);
          }
          else {
            vfo_record_read(auStack_3c,1);
            memcpy_ck803s(DAT_0303b6a0,auStack_3c,0x33);
          }
          puVar3 = p_dm32_settings_block04;
          if (((p_dm32_settings_block04[0x2d] & 4) == 0) &&
             ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
            vfo_standby_row_render((byte)p_dm32_settings_block04[0x2d] >> 7);
            display_draw_channel_frequency
                      ((byte)puVar3[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
            vfo_label_draw((byte)puVar3[0x2d] >> 7);
          }
          else {
            display_clear_channel_row_background((byte)p_dm32_settings_block04[0x2d] >> 7,1);
            channel_display_screen();
          }
        }
        *(byte *)(PTR_DAT_0303b6ac + 1) = *(byte *)(PTR_DAT_0303b6ac + 1) & 0xdf;
      }
      if ((*(byte *)PTR_DAT_0303b6ac & 0x10) != 0) {
        conditional_tone_dispatch_by_mode();
      }
      if (((p_dialog_history_ui_state->field_0x3 == 0) &&
          (iVar5 = get_current_mode_state1(), iVar5 == 2)) &&
         ((p_vfo_freq_display_state->field_0x11 & 1) == 0)) {
        dtmf_digit_input_handler(1);
      }
      if ((p_dialog_history_ui_state->field_0x3 == 0) &&
         (iVar5 = get_current_mode_state2(), iVar5 == 4)) {
        if ((*(byte *)p_call_active_flag & 10) == 0) {
          set_flag_byte_03064328(1);
        }
        else {
          set_flag_byte_03064328(3);
        }
      }
      ptVar4 = p_tx_ptt_ui_state;
      p_tx_ptt_ui_state->field_0x8 = 0;
      ptVar4->field_0x9 = 0;
    }
    else {
      reentrant_state_reset_sequence();
      clear_screen_color0();
      p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xef;
      display_draw_number_centered
                (0x46,0xffff,0,
                 **(uint **)(PTR_PTR_0303b6c0 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
      p_dialog_history_ui_state->field_0xa08 = 0;
      text_entry_blank_placeholder_row_draw();
    }
  }
  else {
    reentrant_state_reset_sequence();
    if ((*(byte *)PTR_DAT_0303b50c & 0x40) == 0) {
      clear_screen_color0();
      p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xef;
      display_draw_number_centered(100,0xffff,0,*PTR_DAT_0303b518);
      p_dialog_history_ui_state->field_0xa08 = 0;
      text_entry_blank_placeholder_row_draw_alt();
    }
    else {
      p_dialog_history_ui_state->field_0xa08 = 0xa5;
      write_field_and_mbox_post(1,5);
    }
  }
  return;
}


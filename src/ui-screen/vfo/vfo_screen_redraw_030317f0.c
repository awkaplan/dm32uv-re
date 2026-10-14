/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_screen_redraw @ 030317f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 896 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_screen_redraw(void)

{
  undefined1 *puVar1;
  dialog_flags_from_flash *pdVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  byte bVar7;
  short y0;
  undefined1 auStack_54 [52];
  undefined1 auStack_20 [20];
  
  display_fill_screen(0);
  if ((p_radio_mode_state_0003e318[2].flags_0x2 & 1) != 0) {
    p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xfe;
    pdVar2 = p_dialog_flags_from_flash;
    p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xf7;
    pdVar2->flags_0x2d = pdVar2->flags_0x2d & 0xf3;
    *(byte *)PTR_DAT_030318c0 = *(byte *)PTR_DAT_030318c0 & 0x7f;
  }
  if ((*(byte *)PTR_DAT_030318c4 & 8) == 0) {
    vfo_record_read(auStack_54,0);
    memcpy_ck803s(DAT_030318c8,auStack_54,0x33);
  }
  if ((*(byte *)PTR_DAT_030318c4 & 0x10) == 0) {
    vfo_record_read(auStack_54,1);
    memcpy_ck803s(DAT_030318cc,auStack_54,0x33);
  }
  puVar1 = p_dm32_settings_block04;
  if ((*PTR_DAT_030318d0 & 0x18000) == 0x8000) {
    battery_value_display_format((uint)~(int)(char)p_dm32_settings_block04[0x2d] >> 0x1f);
    if (puVar1[0x6c] != '\0') {
      vfo_standby_frequency_panel_render((byte)puVar1[0x2d] >> 7);
    }
  }
  else if (p_dm32_settings_block04[0x6c] == '\0') {
    iVar4 = value_in_range_multi_band_check(*(undefined4 *)p_vfo_display_state);
    if (iVar4 == 0) {
      vfo_standby_frequency_panel_render((byte)p_dm32_settings_block04[0x2d] >> 7);
    }
    else {
      display_draw_number_centered
                (0x3b,0xffff,0,
                 **(uint **)(PTR_PTR_03031aa8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
    }
  }
  else {
    iVar4 = value_in_range_multi_band_check(*PTR_DAT_03031aa4);
    if (iVar4 == 0) {
      vfo_standby_frequency_panel_render(0);
    }
    else {
      display_draw_number_centered
                (0x3b,0xffff,0,
                 **(uint **)(PTR_PTR_03031aa8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
    }
    iVar4 = value_in_range_multi_band_check(*PTR_DAT_03031aac);
    if (iVar4 == 0) {
      vfo_standby_frequency_panel_render(1);
    }
    else {
      display_draw_number_centered
                (0xb1,0xffff,0,
                 **(uint **)(PTR_PTR_03031aa8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8))
      ;
    }
  }
  uVar5 = vfo_active_side_mode_nibble();
  uVar6 = get_current_mode_state1();
  puVar3 = p_dm32_settings_block04;
  puVar1 = p_dm32_settings_block04;
  if (((1 < uVar6) && ((p_vfo_freq_display_state->field_0x11 & 1) == 0)) &&
     ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
    if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
      display_draw_tone_mode_icon((byte)p_dm32_settings_block04[0x2d] >> 7,uVar5,0xf800);
      display_draw_channel_frequency((byte)puVar3[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
      vfo_label_draw((byte)puVar3[0x2d] >> 7);
    }
    else {
      if (uVar6 == 3) {
        bVar7 = p_vfo_freq_display_state->flags_0x10 >> 5 & 3;
      }
      else {
        bVar7 = p_vfo_display_state->flags_0x8 >> 4;
      }
      display_draw_tone_mode_icon((byte)p_dm32_settings_block04[0x2d] >> 7,bVar7,0xf800);
      if ((puVar1[0x2d] & 0x80) == 0) {
        y0 = 0x62;
      }
      else {
        y0 = 0xd8;
      }
      if (puVar1[0x6c] == '\0') {
        display_fill_rect(0,0x81,0xb4,0x99,0);
      }
      else {
        display_fill_rect(0,y0,0xaa,y0 + 0x10,0);
      }
      puVar1 = p_dm32_settings_block04;
      status_field_glyph_or_ascii_render
                ((byte)p_dm32_settings_block04[0x2d] >> 7,DAT_03031abc,0xffff,0);
      display_clear_channel_row_background((byte)puVar1[0x2d] >> 7,1);
      puVar3 = p_dm32_settings_block04;
      if ((puVar1[0x2d] & 0x20) == 0) {
        if (uVar6 == 3) {
          bVar7 = p_dm32_settings_block04[0x2d];
          uVar5 = channel_frequency_read_decode
                            (*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0);
          display_draw_channel_frequency(bVar7 >> 7,uVar5);
        }
        else {
          display_draw_channel_frequency
                    ((byte)p_dm32_settings_block04[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
        }
      }
      else if (uVar6 == 3) {
        channel_record_read_full(*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0,auStack_20);
        puVar1 = p_dm32_settings_block04;
        display_draw_string_centered_mixed
                  ((byte)p_dm32_settings_block04[0x2d] >> 7,auStack_20,0xffff,0);
        if (puVar1[0x6c] == '\0') {
          bVar7 = puVar1[0x2d];
          uVar5 = channel_frequency_read_decode
                            (*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0);
          display_draw_channel_frequency(bVar7 >> 7,uVar5);
        }
        else {
          bVar7 = p_dm32_settings_block04[0x2d];
          uVar5 = channel_frequency_read_decode
                            (*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0);
          display_draw_frequency(bVar7 >> 7,uVar5);
        }
      }
      else {
        display_draw_string_centered_mixed
                  ((byte)p_dm32_settings_block04[0x2d] >> 7,DAT_03031c80,0xffff,0);
        if (puVar3[0x6c] == '\0') {
          display_draw_channel_frequency((byte)puVar3[0x2d] >> 7,*(undefined4 *)p_vfo_display_state)
          ;
        }
        else {
          display_draw_frequency
                    ((byte)p_dm32_settings_block04[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
        }
      }
      channel_number_indicator_update
                ((byte)p_dm32_settings_block04[0x2d] >> 7,p_dm32_settings_block04[0x26]);
    }
    vfo_frequency_panel_render();
  }
  vfo_active_side_icon_draw((byte)p_dm32_settings_block04[0x2d] >> 7);
  display_update_datetime(1);
  return;
}


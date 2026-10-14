/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_display_screen @ 03031bb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1068 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_display_screen(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  short y0;
  short y;
  undefined1 auStack_28 [20];
  
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    y0 = 0x62;
    y = 0x3b;
  }
  else {
    y0 = 0xd8;
    y = 0xb1;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    y0 = 0x81;
    y = 0x59;
  }
  vfo_active_side_mode_nibble();
  uVar4 = get_current_mode_state1();
  puVar3 = p_dm32_settings_block04;
  puVar2 = p_dm32_settings_block04;
  if (uVar4 < 3) {
    display_draw_status_bar();
    if ((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) {
      if (p_vfo_freq_display_state->field_0x13 == 0) {
        iVar6 = is_memory_channel_not_vfo();
        if (iVar6 == 0) {
          noop_stub_0301a490();
          vfo_standby_row_render((byte)p_dm32_settings_block04[0x2d] >> 7);
          puVar3 = p_dm32_settings_block04;
          puVar2 = p_dm32_settings_block04;
          if ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0) {
            if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
              bVar1 = p_dm32_settings_block04[0x2d];
              uVar5 = channel_freq_bcd_decode_by_slot(bVar1 >> 7,1);
              display_draw_channel_frequency(bVar1 >> 7,uVar5);
              vfo_label_draw((byte)puVar3[0x2d] >> 7);
            }
            else {
              if (p_dm32_settings_block04[0x6c] == '\0') {
                read_channel_field_from_flash
                          (p_dm32_settings_block04[0x26],(byte)p_dm32_settings_block04[0x2d] >> 7,
                           auStack_28);
                display_fill_rect(10,0x3b,0xe6,0x53,0);
                display_draw_string_centered_mixed((byte)puVar3[0x2d] >> 7,auStack_28,0xffff,0);
                bVar1 = puVar3[0x2d];
                uVar5 = channel_list_index_resolve_then_channel_frequency_read_decode
                                  (puVar3[0x29],puVar3[0x26]);
                display_draw_channel_frequency(bVar1 >> 7,uVar5);
              }
              else if ((p_dm32_settings_block04[0x2d] & 0x20) == 0) {
                bVar1 = p_dm32_settings_block04[0x2d];
                uVar5 = channel_list_index_resolve_then_channel_frequency_read_decode
                                  (p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
                display_draw_channel_frequency(bVar1 >> 7,uVar5);
              }
              else {
                display_clear_channel_row_background((byte)p_dm32_settings_block04[0x2d] >> 7,0);
                read_channel_field_from_flash(puVar3[0x26],(byte)puVar3[0x2d] >> 7,auStack_28);
                display_draw_string_centered_mixed((byte)puVar3[0x2d] >> 7,auStack_28,0xffff,0);
                display_draw_frequency((byte)puVar3[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
              }
              channel_number_indicator_update
                        ((byte)p_dm32_settings_block04[0x2d] >> 7,p_dm32_settings_block04[0x26]);
            }
            if ((p_dm32_settings_block04[0x2d] & 4) != 0) {
              if (p_dm32_settings_block04[0x6c] == '\0') {
                display_fill_rect(0,0x81,0xb4,0x99,0);
              }
              else {
                display_fill_rect(0,y0,0xaa,y0 + 0x10,0);
              }
              if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
                status_field_glyph_or_ascii_render
                          ((byte)p_dm32_settings_block04[0x2d] >> 7,p_dm32_settings_block04 + 1,
                           0xffff);
              }
              else {
                status_field_glyph_or_ascii_render
                          ((byte)p_dm32_settings_block04[0x2d] >> 7,p_dm32_settings_block04 + 0x14,
                           0xffff,0);
              }
            }
          }
          else {
            display_draw_channel_frequency
                      ((byte)p_dm32_settings_block04[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
            channel_number_indicator_update((byte)puVar2[0x2d] >> 7,puVar2[0x26]);
          }
        }
      }
      else {
        vfo_screen_redraw();
      }
    }
    else {
      display_draw_number_centered(y,0xffff,0,DAT_03032170);
    }
  }
  else if ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0) {
    if (p_radio_mode_state_0003e318->field_0x1 == 2) {
      if ((p_dm32_settings_block04[0x2d] & 4) == 0) {
        if (PTR_DAT_03031e60[0x180] == 0) {
          if (p_dm32_settings_block04[0x6c] == '\0') {
            display_fill_rect(10,y0,0xe6,y0 + 0x18,0);
          }
          else {
            display_fill_rect(0,y0,0xf0,y0 + 0x10,0);
          }
          PTR_DAT_03031e60[0x180] = 1;
        }
        display_draw_channel_frequency
                  ((byte)p_dm32_settings_block04[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
      }
      else if (PTR_DAT_03031c8c[0x180] == 0) {
        if (p_dm32_settings_block04[0x6c] == '\0') {
          display_fill_rect(0,0x81,0xb4,0x99,0);
        }
        else {
          display_fill_rect(0,y0,0xaa,y0 + 0x10,0);
        }
        status_field_glyph_or_ascii_render
                  ((byte)p_dm32_settings_block04[0x2d] >> 7,DAT_03031e5c,0xffff,0);
        PTR_DAT_03031e60[0x180] = 1;
      }
    }
    else {
      display_clear_status_row_at_y_by_flag((byte)p_dm32_settings_block04[0x2d] >> 7);
      display_clear_channel_row_background((byte)puVar3[0x2d] >> 7,0);
      display_draw_tone_mode_icon
                ((byte)puVar3[0x2d] >> 7,p_vfo_display_state->flags_0x8 >> 4,0xf800);
      if (puVar3[0x6c] == '\0') {
        channel_record_read_full(*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0,auStack_28);
        display_fill_rect(10,0x3b,0xe6,0x53,0);
        display_draw_string_centered_mixed((byte)puVar3[0x2d] >> 7,auStack_28,0xffff,0);
        bVar1 = puVar3[0x2d];
        uVar5 = channel_list_index_resolve_then_channel_frequency_read_decode
                          (puVar3[0x29],puVar3[0x26]);
        display_draw_channel_frequency(bVar1 >> 7,uVar5);
      }
      else if ((p_dm32_settings_block04[0x2d] & 0x24) == 0x24) {
        channel_record_read_full(*(undefined2 *)&p_vfo_freq_display_state->field_0x54_0,auStack_28);
        display_draw_string_centered_mixed
                  ((byte)p_dm32_settings_block04[0x2d] >> 7,auStack_28,0xffff,0);
      }
      else {
        display_draw_channel_frequency
                  ((byte)p_dm32_settings_block04[0x2d] >> 7,
                   *(undefined4 *)&p_vfo_display_state->field_0x4_0);
      }
    }
  }
  else {
    display_draw_channel_frequency
              ((byte)p_dm32_settings_block04[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
    channel_number_indicator_update((byte)puVar2[0x2d] >> 7,puVar2[0x26]);
  }
  return;
}


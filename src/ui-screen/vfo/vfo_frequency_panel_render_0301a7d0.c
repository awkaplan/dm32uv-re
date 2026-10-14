/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_frequency_panel_render @ 0301a7d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 742 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_frequency_panel_render(void)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  short y0;
  undefined1 auStack_20 [20];
  
  iVar3 = get_current_mode_state1();
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    y0 = 0x22;
  }
  else {
    y0 = 0x98;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    y0 = 0x22;
  }
  if ((((*(char *)PTR_DAT_0301a910 == '\0') && (iVar3 != 0)) && (iVar3 != 2)) && (iVar3 != 1)) {
    display_fill_rect(0x6f,y0,0x7f,y0 + 0x10,0);
    if (((*(char *)PTR_DAT_0301a910 != '[') && ((p_dm32_settings_block04[0x2d] & 4) != 0)) &&
       ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
      display_clear_channel_row_background((byte)p_dm32_settings_block04[0x2d] >> 7,1);
    }
    if ((iVar3 == 6) || (iVar3 == 10)) {
      if (((p_dm32_settings_block04[0x2d] & 4) == 0) ||
         ((p_radio_mode_state_0003e318[2].field_0x1 & 4) != 0)) {
        display_blit_image(0x6f,y0,0x10,0x10,PTR_LAB_0301aab0);
      }
      else if (*(short *)&p_vfo_freq_display_state->field_0x8_0 ==
               *(short *)&p_vfo_freq_display_state->field_0x54_0) {
        display_blit_image(0x6f,y0,0x10,0x10,PTR_LAB_0301aaa8);
      }
      else if (*(short *)&p_vfo_freq_display_state->field_0xa_0 ==
               *(short *)&p_vfo_freq_display_state->field_0x54_0) {
        display_blit_image(0x6f,y0,0x10,0x10,PTR_LAB_0301aaac);
      }
      else {
        display_blit_image(0x6f,y0,0x10,0x10,PTR_LAB_0301aab0);
      }
      puVar2 = p_dm32_settings_block04;
      if (*(char *)PTR_DAT_0301aab4 != '[') {
        display_draw_tone_mode_icon
                  ((byte)p_dm32_settings_block04[0x2d] >> 7,p_vfo_display_state->flags_0x8 >> 4,
                   0x7ff);
        if (((puVar2[0x2d] & 4) != 0) && ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
          if ((puVar2[0x2d] & 0x20) == 0) {
            display_draw_channel_frequency
                      ((byte)p_dm32_settings_block04[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
          }
          else {
            display_draw_string_centered_mixed((byte)puVar2[0x2d] >> 7,DAT_0301aabc,0xffff,0);
            if (puVar2[0x6c] == '\0') {
              display_draw_channel_frequency
                        ((byte)puVar2[0x2d] >> 7,*(undefined4 *)p_vfo_display_state);
            }
            else {
              display_draw_frequency
                        ((byte)p_dm32_settings_block04[0x2d] >> 7,*(undefined4 *)p_vfo_display_state
                        );
            }
          }
          channel_number_indicator_update
                    ((byte)p_dm32_settings_block04[0x2d] >> 7,
                     *(undefined2 *)&p_vfo_freq_display_state->field_0x14_0);
        }
      }
    }
    else {
      display_blit_image(0x6f,y0,0x10,0x10,PTR_LAB_0301a918);
      if (*(char *)PTR_DAT_0301a910 != '[') {
        ctcss_dcs_row_render_wrapper(p_vfo_freq_display_state->flags_0x10 >> 5 & 3);
        if (((p_dm32_settings_block04[0x2d] & 4) != 0) &&
           ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
          if ((p_dm32_settings_block04[0x2d] & 0x20) == 0) {
            bVar1 = p_dm32_settings_block04[0x2d];
            uVar4 = channel_frequency_read_decode
                              (*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0);
            display_draw_channel_frequency(bVar1 >> 7,uVar4);
          }
          else {
            channel_record_read_full
                      (*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0,auStack_20);
            puVar2 = p_dm32_settings_block04;
            display_draw_string_centered_mixed
                      ((byte)p_dm32_settings_block04[0x2d] >> 7,auStack_20,0xffff,0);
            if (puVar2[0x6c] == '\0') {
              bVar1 = puVar2[0x2d];
              uVar4 = channel_frequency_read_decode
                                (*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0);
              display_draw_channel_frequency(bVar1 >> 7,uVar4);
            }
            else {
              bVar1 = p_dm32_settings_block04[0x2d];
              uVar4 = channel_frequency_read_decode
                                (*(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0);
              display_draw_frequency(bVar1 >> 7,uVar4);
            }
          }
          channel_number_indicator_update
                    ((byte)p_dm32_settings_block04[0x2d] >> 7,
                     *(undefined2 *)&p_vfo_freq_display_state->field_0x5a_0);
        }
      }
    }
  }
  return;
}


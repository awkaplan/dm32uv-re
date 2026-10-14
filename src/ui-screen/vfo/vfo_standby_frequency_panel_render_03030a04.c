/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_standby_frequency_panel_render @ 03030a04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1072 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_standby_frequency_panel_render(char param_1)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  short y0;
  undefined4 *puVar7;
  short y1;
  int iVar8;
  short sVar9;
  undefined1 auStack_2c [16];
  undefined1 uStack_1c;
  
  puVar5 = p_dm32_settings_block04;
  puVar4 = PTR_DAT_03030cf8;
  puVar3 = p_dm32_settings_block04;
  puVar7 = PTR_DAT_03030b10;
  puVar1 = p_dm32_settings_block04;
  if (param_1 == '\0') {
    if ((p_radio_mode_state_0003e318[2].field_0x1 & 1) == 0) {
      if ((*(byte *)PTR_DAT_03030b10 & 8) == 0) {
        if ((*(byte *)((int)p_dm32_settings_block04 + 0x2d) & 1) == 0) {
          uVar6 = channel_freq_bcd_decode_by_slot(0,1);
          display_draw_channel_frequency(0,uVar6);
          vfo_label_draw(0);
        }
        else {
          if (*(char *)(p_dm32_settings_block04 + 0x1b) == '\0') {
            read_channel_field_from_flash
                      (*(undefined1 *)((int)p_dm32_settings_block04 + 0x27),0,auStack_2c);
            display_draw_string_centered_mixed
                      (0,auStack_2c,PTR_DAT_03030ce0[*(byte *)(puVar3 + 0x19)],0);
            uVar6 = channel_list_index_resolve_then_channel_frequency_read_decode
                              (*(undefined1 *)puVar3,*(undefined1 *)((int)puVar3 + 0x27));
            display_draw_channel_frequency(0,uVar6);
          }
          else if ((*(byte *)((int)p_dm32_settings_block04 + 0x2d) & 8) == 0) {
            uVar6 = channel_list_index_resolve_then_channel_frequency_read_decode
                              (*(undefined1 *)p_dm32_settings_block04,
                               *(undefined1 *)((int)p_dm32_settings_block04 + 0x27));
            display_draw_channel_frequency(0,uVar6);
          }
          else {
            read_channel_field_from_flash
                      (*(undefined1 *)((int)p_dm32_settings_block04 + 0x27),0,auStack_2c);
            display_draw_string_centered_mixed
                      (0,auStack_2c,PTR_DAT_03030ce0[*(byte *)(puVar3 + 0x19)],0);
            display_draw_frequency(0,*PTR_DAT_03030ce4);
          }
          puVar7 = p_dm32_settings_block04;
          channel_number_indicator_update(0,*(undefined1 *)((int)p_dm32_settings_block04 + 0x27));
          status_field_glyph_or_ascii_render
                    (0,(int)puVar7 + 1,PTR_DAT_03030ce0[*(byte *)((int)puVar7 + 0x66)],0);
        }
      }
      else {
        uStack_1c = 0;
        flash_field_read_cached
                  (0x66,(*(byte *)(PTR_DAT_03030b10 + 1) - 1) * 0x1a & 0xfffe,auStack_2c,0x10);
        puVar2 = PTR_DAT_03030b08;
        puVar1 = p_dm32_settings_block04;
        display_draw_string_centered_mixed
                  (0,auStack_2c,PTR_DAT_03030b08[(byte)p_dm32_settings_block04[100]],0);
        flash_field_read_cached(0x65,(*(byte *)((int)puVar7 + 3) - 1) * 0x21 + 0x10,auStack_2c,0x10)
        ;
        status_field_glyph_or_ascii_render(0,auStack_2c,puVar2[(byte)puVar1[0x66]],0);
        if ((puVar1[0x2d] & 1) != 0) {
          channel_number_indicator_update(0,puVar1[0x27]);
        }
      }
    }
    else {
      memcpy_bytes_iram(auStack_2c,PTR_LAB_03030b00 + ((byte)p_dm32_settings_block04[0x2a] - 1) * 4,
                        4);
      uVar6 = bcd_frequency_decode(auStack_2c,4);
      *PTR_DAT_03030b04 = uVar6;
      display_draw_channel_frequency(0,uVar6);
      status_field_glyph_or_ascii_render(0,PTR_LAB_03030b0c,PTR_DAT_03030b08[(byte)puVar1[0x66]],0);
      channel_number_indicator_update(0,puVar1[0x2a]);
    }
    vfo_standby_row_render(0);
    sVar9 = 0x76;
    puVar7 = PTR_DAT_03030e84;
  }
  else {
    if ((p_radio_mode_state_0003e318[2].field_0x1 & 2) == 0) {
      if ((*(byte *)PTR_DAT_03030cf8 & 0x10) == 0) {
        if ((p_dm32_settings_block04[0x2d] & 2) == 0) {
          uVar6 = channel_freq_bcd_decode_by_slot(1,1);
          display_draw_channel_frequency(1,uVar6);
          vfo_label_draw(1);
        }
        else {
          if (p_dm32_settings_block04[0x6c] == '\0') {
            read_channel_field_from_flash(p_dm32_settings_block04[0x28],1,auStack_2c);
            display_draw_string_centered_mixed(1,auStack_2c,PTR_DAT_03030e7c[(byte)puVar5[0x65]],0);
            uVar6 = channel_list_index_resolve_then_channel_frequency_read_decode
                              (puVar5[0x13],puVar5[0x28]);
            display_draw_channel_frequency(1,uVar6);
          }
          else if ((p_dm32_settings_block04[0x2d] & 0x10) == 0) {
            uVar6 = channel_list_index_resolve_then_channel_frequency_read_decode
                              (p_dm32_settings_block04[0x13],p_dm32_settings_block04[0x28]);
            display_draw_channel_frequency(1,uVar6);
          }
          else {
            read_channel_field_from_flash(p_dm32_settings_block04[0x28],1,auStack_2c);
            display_draw_string_centered_mixed(1,auStack_2c,PTR_DAT_03030e7c[(byte)puVar5[0x65]],0);
            display_draw_frequency(1,*PTR_DAT_03030e80);
          }
          puVar1 = p_dm32_settings_block04;
          channel_number_indicator_update(1,p_dm32_settings_block04[0x28]);
          status_field_glyph_or_ascii_render(1,puVar1 + 0x14,PTR_DAT_03030e7c[(byte)puVar1[0x67]],0)
          ;
        }
      }
      else {
        uStack_1c = 0;
        flash_field_read_cached
                  (0x66,(*(byte *)(PTR_DAT_03030cf8 + 1) - 1) * 0x1a & 0xfffe,auStack_2c,0x10);
        puVar2 = PTR_DAT_03030ce0;
        puVar7 = p_dm32_settings_block04;
        display_draw_string_centered_mixed
                  (1,auStack_2c,PTR_DAT_03030ce0[*(byte *)((int)p_dm32_settings_block04 + 0x65)],0);
        flash_field_read_cached(0x65,(*(byte *)((int)puVar4 + 3) - 1) * 0x21 + 0x10,auStack_2c,0x10)
        ;
        status_field_glyph_or_ascii_render(1,auStack_2c,puVar2[*(byte *)((int)puVar7 + 0x67)],0);
        if ((*(byte *)((int)puVar7 + 0x2d) & 2) != 0) {
          channel_number_indicator_update(1,*(undefined1 *)(puVar7 + 10));
        }
      }
    }
    else {
      memcpy_bytes_iram(auStack_2c,
                        PTR_LAB_03030cec + (*(byte *)((int)p_dm32_settings_block04 + 0x2b) - 1) * 4,
                        4);
      uVar6 = bcd_frequency_decode(auStack_2c,4);
      *PTR_DAT_03030cf0 = uVar6;
      display_draw_channel_frequency(1,uVar6);
      status_field_glyph_or_ascii_render
                (1,PTR_LAB_03030cf4,PTR_DAT_03030ce0[*(byte *)((int)puVar3 + 0x67)],0);
      channel_number_indicator_update(1,*(undefined1 *)((int)puVar3 + 0x2b));
    }
    vfo_standby_row_render(param_1);
    sVar9 = 0xec;
    puVar7 = PTR_DAT_03030e88;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    sVar9 = 0x9f;
  }
  display_blit_image(10,sVar9 + 4,0x10,0x10,puVar7);
  y1 = sVar9 + 0x14;
  display_fill_rect(0x1d,sVar9 + 0x12,0xe1,y1,0xffff);
  y0 = sVar9 + 2;
  display_fill_rect(0x1d,y0,0x1f,y1,0xffff);
  display_fill_rect(0xe1,y0,0xe3,y1,0xffff);
  iVar8 = 0x23;
  do {
    display_fill_rect((short)iVar8 + -2,y0,(short)iVar8,sVar9 + 0x11,0x8430);
    iVar8 = iVar8 + 4;
  } while (iVar8 != 0xe3);
  return;
}


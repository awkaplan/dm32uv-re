/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_list_screen_with_add @ 0302ea10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 542 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_list_screen_with_add(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint local_3c;
  uint local_38;
  uint3 uStack_34;
  undefined1 uStack_31;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  
  iVar1 = p_dm32_settings_block04;
  param_2 = param_2 & 0xff;
  param_3 = param_3 & 0xff;
  local_38 = 0;
  _uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (param_3 != 0) {
    uVar3 = (param_2 - (param_1 & 0xff)) + 1 & 0xff;
    uVar2 = 1;
    bVar4 = 1;
    do {
      if (uVar3 + 1 == uVar2) {
        if (uVar2 == 1) {
          if ((*(byte *)(iVar1 + 0x30) & 0x40) == 0) {
            memcpy_bytes_iram(&local_38,PTR_LAB_0302eb14,8);
            SUBPIECE_SET(uStack_30, 0, 2, (ushort)(byte)uStack_30);
          }
          else {
            memcpy_bytes_iram(&local_38,PTR_s_Cur_Chan_0302eb18,8);
            SUBPIECE_SET(uStack_30, 0, 2, (ushort)(byte)uStack_30);
          }
        }
        else if ((int)uVar3 < (int)(param_3 - 1)) {
          flash_field_read_cached
                    (0x11,(*(byte *)PTR_DAT_0302eb1c - 1) * 0x39 + 0x1b + (uVar2 - 2) * 2 & 0xffff,
                     &local_38,2);
          local_3c = local_38 & 0xffff;
          channel_record_read_full(local_3c,&local_38);
        }
        else if ((*(byte *)(iVar1 + 0x30) & 0x40) == 0) {
          memcpy_bytes_iram(&local_38,PTR_LAB_0302eb20,8);
          uStack_30 = uStack_30 & 0xffffff00;
        }
        else {
          memcpy_bytes_iram(&local_38,PTR_s_Add_CH_0302eb24,6);
          uStack_34 = (uint3)(ushort)uStack_34;
        }
        if (uVar3 == param_2) {
          display_draw_list_row(bVar4,&local_38,1);
        }
        else {
          display_draw_list_row(bVar4,&local_38,0);
        }
        *(undefined1 *)PTR_DAT_0302ec7c = 1;
        if (uVar2 == 1) {
          if ((p_vfo_freq_display_state->field_0x4 & 0xf) == 1) {
            if (uVar3 == param_2) {
              display_blit_bitmap_by_palette_variant(1,bVar4,1);
            }
            else {
              display_blit_bitmap_by_palette_variant(1,bVar4,0);
            }
          }
          else if ((p_vfo_freq_display_state->field_0x4 & 0xf0) == 0x10) {
            if (uVar3 == param_2) {
              display_blit_bitmap_by_palette_variant(2,bVar4,1);
            }
            else {
              display_blit_bitmap_by_palette_variant(2,bVar4,0);
            }
          }
        }
        else if ((int)uVar3 < (int)(param_3 - 1)) {
          if ((*(ushort *)&p_vfo_freq_display_state->field_0x8_0 == local_3c) &&
             ((p_vfo_freq_display_state->field_0x4 & 0xf) == 2)) {
            if (uVar3 == param_2) {
              display_blit_bitmap_by_palette_variant(1,bVar4,1);
            }
            else {
              display_blit_bitmap_by_palette_variant(1,bVar4,0);
            }
          }
          else if ((*(ushort *)&p_vfo_freq_display_state->field_0xa_0 == local_3c) &&
                  ((p_vfo_freq_display_state->field_0x4 & 0xf0) == 0x20)) {
            if (uVar3 == param_2) {
              display_blit_bitmap_by_palette_variant(2,bVar4,1);
            }
            else {
              display_blit_bitmap_by_palette_variant(2,bVar4,0);
            }
          }
        }
        uVar3 = uVar3 + 1 & 0xff;
        if ((param_3 <= uVar3) || (bVar4 = bVar4 + 1, 8 < bVar4)) {
          if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
            number_to_string_format_2args(&local_38,PTR_DAT_0302ec88,param_2 + 1,param_3);
          }
          else {
            number_to_string_format_2args
                      (&local_38,PTR_s_CH_List__d__d_0302ec8c,param_2 + 1,param_3);
          }
          display_clear_status_row(0,0);
          display_draw_number_centered(1,0xffff,0,(uint)&local_38);
          return;
        }
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 <= param_3);
  }
  return;
}


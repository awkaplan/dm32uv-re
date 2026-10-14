/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_list_screen @ 03056464 (file base 0x03000000; code starts at 0x03001000)
 * Size: 350 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void zone_list_screen(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined2 local_3c;
  undefined1 auStack_3a [2];
  undefined4 local_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  
  puVar3 = PTR_DAT_030565f0;
  puVar2 = p_dm32_settings_block04;
  param_2 = param_2 & 0xff;
  param_3 = param_3 & 0xff;
  local_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (param_3 != 0) {
    uVar4 = (param_2 - (param_1 & 0xff)) + 1 & 0xff;
    uVar5 = 0;
    do {
      if ((int)uVar4 < (int)(param_3 - 1)) {
        channel_offset_minus_0x10(uVar4 + 1 & 0xff,auStack_3a,&local_3c);
        flash_field_read_cached(auStack_3a[0],local_3c,&local_38,0x10);
        if (uVar4 == param_2) {
          display_draw_list_row(uVar5 + 1,&local_38,1);
          memcpy_bytes_iram(p_list_row_text_buffer,&local_38,0x10);
        }
        else {
          display_draw_list_row(uVar5 + 1,&local_38,0);
        }
        *(undefined1 *)PTR_DAT_030565f8 = 2;
        menu_icon_draw_dispatch(uVar5 + 1,uVar4);
      }
      else {
        if ((puVar2[0x30] & 0x40) == 0) {
          memcpy_bytes_iram(&local_38,PTR_LAB_030565fc,8);
        }
        else {
          memcpy_bytes_iram(&local_38,PTR_s_Add_Zone_03056600,8);
        }
        uStack_30 = uStack_30 & 0xffffff00;
        bVar1 = *(byte *)((int)puVar3 + uVar5);
        if (uVar4 == param_2) {
          display_draw_list_row(uVar5 + 1,&local_38,1);
          display_blit_image(0xc,bVar1 + 4,0x11,0x11,PTR_LAB_03056604);
        }
        else {
          display_draw_list_row(uVar5 + 1,&local_38,0);
          display_blit_image(0xc,bVar1 + 4,0x11,0x11,PTR_LAB_03056608);
        }
      }
      uVar4 = uVar4 + 1 & 0xff;
      if ((param_3 <= uVar4) || (uVar5 == 7)) {
        if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
          number_to_string_format_2args(&local_38,PTR_DAT_0305660c,param_2 + 1,param_3);
        }
        else {
          number_to_string_format_2args
                    (&local_38,PTR_s_Zone_List__d__d_03056610,param_2 + 1,param_3);
        }
        display_clear_status_row(0,0);
        display_draw_number_centered(1,0xffff,0,(uint)&local_38);
        return;
      }
      uVar5 = uVar5 + 1;
    } while ((uVar5 & 0xff) < param_3);
  }
  return;
}


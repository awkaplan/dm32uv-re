/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_update_datetime @ 0301b6a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 334 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_update_datetime(int param_1__w,uint param_2)

{
  char param_1 = (char)param_1__w;
  byte bVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  char cStack_43;
  undefined1 uStack_3f;
  ushort uStack_3e;
  byte abStack_3c [32];
  
  uVar5 = rtc_decode_calendar_date();
  puVar3 = PTR_DAT_0301b804;
  uVar7 = uVar5 & 0xff;
  cStack_43 = (char)(uVar5 >> 8);
  uVar6 = param_2 & 0xff;
  uStack_3f = (undefined1)(param_2 >> 8);
  uStack_3e = (ushort)(param_2 >> 0x10);
  uVar8 = (uint)uStack_3e;
  if (((((*(char *)PTR_DAT_0301b7f8 == '\0') || (param_1 != '\0')) &&
       (bVar1 = p_dm32_settings_block04[0x31], (bVar1 & 8) != 0)) &&
      ((PTR_DAT_0301b800[3] & 2) == 0)) &&
     (((*(byte *)(PTR_DAT_0301b804 + 1) != uVar6 ||
       (*(char *)((int)PTR_DAT_0301b804 + 1) != cStack_43)) || (param_1 != '\0')))) {
    *PTR_DAT_0301b804 = uVar5;
    *(char *)puVar3 = (char)uVar5;
    *(char *)((int)puVar3 + 1) = cStack_43;
    *(char *)(puVar3 + 1) = (char)param_2;
    *(undefined1 *)((int)puVar3 + 5) = uStack_3f;
    *(ushort *)((int)puVar3 + 6) = uStack_3e;
    if ((bVar1 & 0x10) == 0) {
      number_to_string_format_2args
                (abStack_3c,PTR_s__0_4d__0_2d__0_2d_0301b80c,uVar8,uStack_3f,uVar6,uVar5,param_2);
    }
    else {
      number_to_string_format_2args
                (abStack_3c,PTR_s__0_2d__0_2d__0_4d_0301b808,uVar6,uStack_3f,uVar8,uVar5,param_2);
      uVar6 = uVar8;
    }
    puVar4 = PTR_DAT_0301b810;
    puVar2 = p_dm32_settings_block04;
    if ((p_dm32_settings_block04[0x6c] == '\0') && (*(char *)PTR_DAT_0301b7f8 == '\0')) {
      display_draw_number_centered
                (200,PTR_DAT_0301b810[(byte)p_dm32_settings_block04[99]],0,(uint)abStack_3c);
      number_to_string_format_2args
                (abStack_3c,PTR_s__0_2d__0_2d_0301b814,uVar7,cStack_43,uVar6,uVar5,param_2);
      display_draw_number_centered(0xe6,puVar4[(byte)puVar2[99]],0,(uint)abStack_3c);
    }
    else {
      uVar9 = 0;
      display_draw_string_gb2312
                (0x101,0x12,abStack_3c,PTR_DAT_0301b810[(byte)p_dm32_settings_block04[99]],0);
      number_to_string_format_2args
                (abStack_3c,PTR_s__0_2d__0_2d_0301b814,uVar7,cStack_43,uVar9,uVar5,param_2);
      display_draw_string_gb2312(0x101,0xa2,abStack_3c,puVar4[(byte)puVar2[99]],0);
    }
  }
  return;
}


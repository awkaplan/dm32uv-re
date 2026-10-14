/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aprs_log_record_detail_screen @ 030626d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1254 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void aprs_log_record_detail_screen(undefined2 param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  ushort y;
  byte *pbVar11;
  int iVar12;
  undefined4 local_c4;
  byte abStack_c0 [10];
  undefined1 uStack_b6;
  byte abStack_b5 [21];
  byte abStack_a0 [19];
  byte abStack_8d [6];
  undefined1 uStack_87;
  undefined1 uStack_85;
  undefined1 uStack_83;
  char local_78 [4];
  undefined1 auStack_74 [3];
  undefined1 auStack_71 [67];
  ushort uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_c4 = 0;
  aprs_log_record_read(param_1,auStack_74);
  uVar5 = string_find_nth_comma_index(auStack_71,2);
  uVar6 = string_find_nth_comma_index(auStack_71,3);
  local_78[0] = auStack_71[uVar6 & 0xff];
  memcpy_bytes_iram(abStack_8d + 1,auStack_71 + (uVar5 & 0xff),(uVar6 & 0xff) - (uVar5 & 0xff));
  if ((PTR_DAT_030629a4[0xd8] & 0x40) == 0) {
    format_computed_ratio_as_string(1,abStack_8d + 1,abStack_a0);
  }
  else {
    gps_coordinate_seconds_to_hms_string_format(1,abStack_8d + 1,abStack_a0);
  }
  strcat((char *)abStack_a0,local_78);
  pbVar11 = *(byte **)PTR_PTR_030629ac[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2];
  sVar3 = strlen_ck803s(pbVar11);
  display_draw_string_gb2312(0x28,5,pbVar11,0xffff,0);
  display_draw_string_gb2312(0x28,(sVar3 * 0xc & 0xfcU) + 5 & 0xff,abStack_a0,0xffff,0);
  uVar5 = string_find_nth_comma_index(auStack_71,4);
  uVar6 = string_find_nth_comma_index(auStack_71,5);
  local_78[0] = auStack_71[uVar6 & 0xff];
  memcpy_bytes_iram(abStack_8d + 1,auStack_71 + (uVar5 & 0xff),(uVar6 & 0xff) - (uVar5 & 0xff));
  if ((PTR_DAT_030629a4[0xd8] & 0x40) == 0) {
    format_computed_ratio_as_string(0,abStack_8d + 1,abStack_a0);
  }
  else {
    gps_coordinate_seconds_to_hms_string_format(0,abStack_8d + 1,abStack_a0);
  }
  strcat((char *)abStack_a0,local_78);
  puVar1 = p_dm32_settings_block04;
  pbVar11 = *(byte **)(PTR_PTR_030629ac[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 4);
  sVar3 = strlen_ck803s(pbVar11);
  display_draw_string_gb2312(0x46,5,pbVar11,0xffff,0);
  display_draw_string_gb2312(0x46,(sVar3 * 0xc & 0xfcU) + 5 & 0xff,abStack_a0,0xffff,0);
  if ((puVar1[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(abStack_8d + 1,PTR_LAB_030629b0,5);
    uStack_87 = 0;
    y = 0x41;
  }
  else {
    memcpy_bytes_iram(abStack_8d + 1,PTR_s_Distance__030629b4,9);
    uStack_83 = 0;
    y = 0x71;
  }
  display_draw_string_gb2312(100,5,abStack_8d + 1,0xffff,0);
  if (uStack_2e < 0x169) {
    uVar10 = uStack_28;
    uVar7 = soft_double_to_int(uStack_2c,uStack_28);
    local_c4 = uVar7;
    uVar8 = soft_double_pack_constant_two();
    soft_double_sub(uStack_2c,uStack_28,uVar8,uVar10);
    soft_double_multiply();
    uVar10 = soft_double_to_int();
    number_to_string_format_2args(abStack_a0,PTR_s__d__03dkm_030629c0,uVar7,uVar10);
    display_draw_string_gb2312(100,y,abStack_a0,0xffff,0);
  }
  else {
    display_draw_string_gb2312(100,y,PTR_LAB_030629b8,0xffff,0);
  }
  puVar1 = p_dm32_settings_block04;
  pbVar11 = *(byte **)(PTR_PTR_030629ac[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] + 8);
  sVar3 = strlen_ck803s(pbVar11);
  display_draw_string_gb2312(0x82,5,pbVar11,0xffff,0);
  uVar5 = string_find_nth_comma_index(auStack_71,6);
  uVar6 = string_find_nth_comma_index(auStack_71,7);
  iVar12 = ((uVar6 & 0xff) - 1) - (uVar5 & 0xff);
  pbVar11 = abStack_8d + 1;
  memcpy_bytes_iram(pbVar11,auStack_71 + (uVar5 & 0xff),iVar12);
  pbVar11[iVar12] = 0;
  number_to_string_format_2args(abStack_a0,PTR_s__sKM_H_030629c4,pbVar11);
  display_draw_string_gb2312(0x82,(sVar3 * 0xc & 0xfcU) + 5 & 0xff,abStack_a0,0xffff,0);
  if ((puVar1[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(abStack_8d + 1,PTR_LAB_030629c8,7);
  }
  else {
    memcpy_bytes_iram(abStack_8d + 1,PTR_s_Course__03062bd4,7);
  }
  uStack_85 = 0;
  display_draw_string_gb2312(0xa0,5,abStack_8d + 1,0xffff,0);
  if (uStack_2e < 0x169) {
    number_to_string_format_2args(abStack_a0,PTR_LAB_03062bdc,uStack_2e);
    display_draw_string_gb2312(0xa0,0x59,abStack_a0,0xffff,0);
  }
  else {
    display_draw_string_gb2312(0xa0,0x59,PTR_LAB_03062bd8,0xffff,0);
  }
  uVar5 = string_find_nth_comma_index(auStack_71,1);
  pbVar11 = abStack_8d + 1;
  memset_bytes(pbVar11,0,0xb);
  memcpy_bytes_iram(pbVar11,auStack_71,(uVar5 & 0xff) - 1);
  uVar5 = string_find_nth_comma_index(auStack_71,8);
  uVar6 = string_find_nth_comma_index(auStack_71,9);
  memset_bytes(abStack_a0,0,7);
  memcpy_bytes_iram(abStack_a0,auStack_71 + (uVar5 & 0xff),(uVar6 & 0xff) - (uVar5 & 0xff));
  gps_datetime_format(2,abStack_a0,pbVar11,abStack_c0);
  display_draw_string_gb2312(0xbe,5,abStack_b5,0xffff,0);
  uStack_b6 = 0;
  display_draw_string_gb2312(0xdc,5,abStack_c0,0xffff,0);
  display_draw_circle_bresenham(0xbe,0xd7,0x28,0xffff);
  display_draw_circle_bresenham(0xbe,0xd7,0x1e,0xffff);
  draw_line_bresenham(0x96,0xd7,0xe6,0xd8,0xffff);
  draw_line_bresenham(0xbe,0xaf,0xbf,0xff,0xffff);
  uVar10 = 0x9b;
  display_plot_glyph_2color(0xb4,0x9b,0x14,0x3c,PTR_LAB_03062be0,0xf800,0);
  if (uStack_2e < 0x169) {
    if (uStack_2e < 0x5a) {
      sVar3 = uStack_2e + 0x10e;
    }
    else {
      sVar3 = uStack_2e - 0x5a;
    }
    soft_double_from_int(sVar3);
    soft_double_multiply();
    uVar8 = soft_double_divide();
    uVar7 = uVar10;
    uVar9 = soft_double_cos();
    uVar8 = soft_double_sin(uVar8,uVar10);
    puVar2 = PTR_DAT_03062bec;
    soft_double_multiply(uVar9,uVar7,*PTR_DAT_03062bec,PTR_DAT_03062bec[1]);
    soft_double_add();
    sVar3 = soft_double_to_int();
    soft_double_multiply(uVar8,uVar10,*puVar2,puVar2[1]);
    soft_double_add();
    sVar4 = soft_double_to_int();
    display_blit_bitmap_1bpp(sVar3 + -5,sVar4 + -5,10,0x14,PTR_LAB_03062bf8,0xf800);
  }
  memcpy_bytes_iram(&local_c4,auStack_74,3);
  iVar12 = contact_name_lookup_or_format(1,local_c4,abStack_8d + 1,3);
  if (iVar12 == 0) {
    display_draw_number_centered(1,0xffff,0,(uint)PTR_s__d_030afae0_8_03062bfc);
  }
  else {
    display_draw_number_centered(1,0xffff,0,(uint)(abStack_8d + 1));
  }
  return;
}


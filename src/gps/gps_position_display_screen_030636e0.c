/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_position_display_screen @ 030636e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1246 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gps_position_display_screen(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  byte *pbVar12;
  int iVar13;
  byte *pbVar14;
  int iVar15;
  int iVar16;
  byte *pbVar17;
  ushort uVar18;
  byte *pbVar19;
  char local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  int iStack_58;
  undefined4 local_54;
  int iStack_50;
  byte abStack_4c [19];
  byte abStack_39 [6];
  undefined1 uStack_33;
  undefined1 uStack_31;
  undefined1 uStack_2f;
  
  iVar13 = DAT_030638e8;
  local_60 = 0;
  local_64[0] = '\0';
  local_64[1] = '\0';
  uVar6 = string_find_nth_comma_index(DAT_030638e8,2);
  uVar7 = string_find_nth_comma_index(iVar13,3);
  pbVar17 = abStack_39 + 1;
  local_64[0] = *(char *)(iVar13 + (uVar7 & 0xff));
  memcpy_bytes_iram(pbVar17,iVar13 + (uVar6 & 0xff),(uVar7 & 0xff) - (uVar6 & 0xff));
  pbVar12 = pbVar17;
  format_computed_ratio_as_string(1,pbVar17,abStack_4c);
  uVar8 = strtod(abStack_4c);
  strcat((char *)abStack_4c,local_64);
  puVar2 = p_dm32_settings_block04;
  puVar1 = PTR_PTR_030638ec;
  pbVar14 = *(byte **)PTR_PTR_030638ec[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2];
  sVar4 = strlen_ck803s(pbVar14);
  display_draw_string_gb2312(0x28,5,pbVar14,0xffff,0);
  display_draw_string_gb2312(0x28,(sVar4 * 0xc & 0xfcU) + 5 & 0xff,abStack_4c,0xffff,0);
  uVar6 = string_find_nth_comma_index(iVar13,4);
  uVar7 = string_find_nth_comma_index(iVar13,5);
  local_64[0] = *(undefined1 *)(iVar13 + (uVar7 & 0xff));
  memcpy_bytes_iram(pbVar17,iVar13 + (uVar6 & 0xff),(uVar7 & 0xff) - (uVar6 & 0xff));
  pbVar14 = pbVar17;
  format_computed_ratio_as_string(0,pbVar17,abStack_4c);
  uVar9 = strtod(abStack_4c);
  strcat((char *)abStack_4c,local_64);
  pbVar19 = *(byte **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 4);
  sVar4 = strlen_ck803s(pbVar19);
  display_draw_string_gb2312(0x46,5,pbVar19,0xffff,0);
  display_draw_string_gb2312(0x46,(sVar4 * 0xc & 0xfcU) + 5 & 0xff,abStack_4c,0xffff,0);
  pbVar19 = *(byte **)(puVar1[((byte)puVar2[0x30] >> 6 & 1) * 2] + 8);
  sVar4 = strlen_ck803s(pbVar19);
  display_draw_string_gb2312(100,5,pbVar19,0xffff,0);
  uVar6 = string_find_nth_comma_index(iVar13,6);
  uVar7 = string_find_nth_comma_index(iVar13,7);
  iVar15 = ((uVar7 & 0xff) - 1) - (uVar6 & 0xff);
  memcpy_bytes_iram(pbVar17,iVar13 + (uVar6 & 0xff),iVar15);
  pbVar17[iVar15] = 0;
  number_to_string_format_2args(abStack_4c,PTR_s__sKM_H_030638f4,pbVar17);
  display_draw_string_gb2312(100,(sVar4 * 0xc & 0xfcU) + 5 & 0xff,abStack_4c,0xffff,0);
  if ((puVar2[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(abStack_39 + 1,PTR_LAB_030638f8,5);
    uStack_33 = 0;
    uVar18 = 0x41;
  }
  else {
    memcpy_bytes_iram(abStack_39 + 1,PTR_s_Distance__030638fc,9);
    uStack_2f = 0;
    uVar18 = 0x71;
  }
  display_draw_string_gb2312(0x82,5,abStack_39 + 1,0xffff,0);
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(abStack_39 + 1,PTR_LAB_03063900,7);
  }
  else {
    memcpy_bytes_iram(abStack_39 + 1,PTR_s_Course__03063ad0,7);
  }
  uStack_31 = 0;
  display_draw_string_gb2312(0xa0,5,abStack_39 + 1,0xffff,0);
  display_draw_circle_bresenham(0xbe,0xd7,0x28,0xffff);
  display_draw_circle_bresenham(0xbe,0xd7,0x1e,0xffff);
  draw_line_bresenham(0x96,0xd7,0xe6,0xd8,0xffff);
  draw_line_bresenham(0xbe,0xaf,0xbf,0xff,0xffff);
  display_plot_glyph_2color(0xb4,0x9b,0x14,0x3c,PTR_LAB_03063ad4,0xf800,0);
  puVar3 = PTR_LAB_03063c94;
  iVar13 = DAT_03063adc;
  if ((*(byte *)PTR_DAT_03063ad8 & 0x40) == 0) {
    display_draw_string_gb2312(0x82,uVar18,PTR_LAB_03063c94,0xffff,0);
    display_draw_string_gb2312(0xa0,0x59,puVar3,0xffff,0);
    PTR_DAT_03063c98[0x12] = 0xffff;
  }
  else {
    uVar6 = string_find_nth_comma_index(DAT_03063adc,3);
    uVar7 = string_find_nth_comma_index(iVar13,4);
    iVar16 = (uVar7 & 0xff) - (uVar6 & 0xff);
    pbVar19 = abStack_39 + 1;
    iVar15 = iVar13 + (uVar6 & 0xff);
    memcpy_bytes_iram(pbVar19,iVar15,iVar16);
    pbVar19[iVar16] = 0;
    local_54 = strtod(pbVar19);
    iStack_50 = iVar15;
    uVar6 = string_find_nth_comma_index(iVar13,5);
    uVar7 = string_find_nth_comma_index(iVar13,6);
    iVar15 = (uVar7 & 0xff) - (uVar6 & 0xff);
    iVar13 = iVar13 + (uVar6 & 0xff);
    memcpy_bytes_iram(pbVar19,iVar13,iVar15);
    pbVar19[iVar15] = 0;
    local_5c = strtod(pbVar19);
    iStack_58 = iVar13;
    gps_coordinate_normalize_pair(local_54,iStack_50,local_5c,iVar13,&local_54,&local_5c);
    iVar13 = DAT_03063ae0;
    iVar15 = gps_coordinate_pair_distance_calc
                       (local_54,iStack_50,local_5c,iStack_58,uVar8,pbVar12,uVar9,pbVar14,
                        DAT_03063ae0);
    *(char *)(iVar13 + -2) = (char)iVar15;
    if (iVar15 == 0) {
      *(undefined1 *)((int)PTR_DAT_03063ae4 + 0x22) = 3;
    }
    uVar8 = gps_coordinate_distance_soft_float
                      (uVar8,pbVar12,uVar9,pbVar14,local_54,iStack_50,local_5c,iStack_58);
    puVar1 = PTR_DAT_03063ae4;
    PTR_DAT_03063ae4[10] = uVar8;
    puVar1[0xb] = pbVar12;
    pbVar14 = pbVar12;
    uVar9 = soft_double_to_int();
    local_60 = uVar9;
    uVar10 = soft_double_pack_constant_two();
    soft_double_sub(uVar8,pbVar12,uVar10,pbVar14);
    soft_double_multiply();
    uVar8 = soft_double_to_int();
    number_to_string_format_2args(abStack_4c,PTR_s__d__03dkm_03063aec,uVar9,uVar8);
    display_draw_string_gb2312(0x82,uVar18,abStack_4c,0xffff,0);
    number_to_string_format_2args(abStack_4c,PTR_LAB_03063af0,*(undefined2 *)(puVar1 + 9));
    uVar8 = 0x59;
    display_draw_string_gb2312(0xa0,0x59,abStack_4c,0xffff,0);
    uVar18 = *(ushort *)(puVar1 + 9);
    if (uVar18 < 0x5a) {
      sVar4 = uVar18 + 0x10e;
    }
    else {
      sVar4 = uVar18 - 0x5a;
    }
    soft_double_from_int(sVar4);
    soft_double_multiply();
    uVar10 = soft_double_divide();
    uVar9 = uVar8;
    uVar11 = soft_double_cos();
    uVar10 = soft_double_sin(uVar10,uVar8);
    puVar3 = PTR_LAB_03063c84;
    soft_double_multiply
              (uVar11,uVar9,*(undefined4 *)PTR_LAB_03063c84,*(undefined4 *)(PTR_LAB_03063c84 + 4));
    soft_double_add();
    sVar4 = soft_double_to_int();
    soft_double_multiply(uVar10,uVar8,*(undefined4 *)puVar3,*(undefined4 *)(puVar3 + 4));
    soft_double_add();
    sVar5 = soft_double_to_int();
    display_blit_bitmap_1bpp(sVar4 + -5,sVar5 + -5,10,0x14,PTR_LAB_03063c90,0xf800);
  }
  memcpy_bytes_iram(&local_60,DAT_03063c9c,3);
  contact_name_lookup_or_format(1,local_60,abStack_39 + 1,3);
  display_draw_string_gb2312(0xbe,5,DAT_03063ca0,0xffff,0);
  display_draw_string_gb2312(0xbe,0x29,abStack_39 + 1,0xffff,0);
  if ((p_radio_mode_state_0003e318[1].flags_0x7 & 4) == 0) {
    gps_log_record_append_compact(PTR_DAT_03063ca8,PTR_DAT_03063ca8[-1]);
  }
  return;
}


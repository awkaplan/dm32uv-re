/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_standby_row_render @ 03018ed0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1248 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_standby_row_render(char param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint *dest;
  uint *dest_00;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  short y0;
  short y0_00;
  uint uVar9;
  undefined1 auStack_8c [52];
  undefined1 auStack_58 [8];
  byte bStack_50;
  byte bStack_4f;
  byte bStack_4e;
  byte bStack_4b;
  byte bStack_49;
  byte bStack_43;
  
  dest_00 = DAT_03019068;
  dest = DAT_03019060;
  if (param_1 == '\0') {
    vfo_record_read(auStack_8c,0);
    memcpy_ck803s(dest,auStack_8c,0x33);
    memcpy_ck803s(auStack_58,dest,0x33);
    bVar2 = *(byte *)((int)dest + 10);
    uVar7 = *dest;
    uVar9 = dest[1];
    cVar1 = *(char *)((int)dest + 0xe);
    uVar4 = *(undefined2 *)((int)dest + 0x11);
    bVar8 = p_radio_mode_state_0003e318[2].field_0x1;
    y0 = 0x22;
  }
  else {
    vfo_record_read(auStack_8c,1);
    memcpy_ck803s(dest_00,auStack_8c,0x33);
    memcpy_ck803s(auStack_58,dest_00,0x33);
    bVar2 = *(byte *)((int)dest_00 + 10);
    uVar7 = *dest_00;
    uVar9 = dest_00[1];
    cVar1 = *(char *)((int)dest_00 + 0xe);
    uVar4 = *(undefined2 *)((int)dest_00 + 0x11);
    bVar8 = p_radio_mode_state_0003e318[2].field_0x1 >> 1;
    y0 = 0x98;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    y0 = 0x22;
  }
  y0_00 = y0 + -2;
  display_fill_rect(0x19,y0_00,0xc3,y0 + 0x14,0);
  uVar3 = PTR_DAT_03019058[(byte)p_dm32_settings_block04[99]];
  if ((bVar8 & 1) != 0) {
    display_blit_image(0x29,y0_00,0x13,0x12,PTR_LAB_0301906c);
    if ((p_dm32_settings_block04[0x6d] & 4) != 0) {
      display_blit_image(0x3c,y0_00,0xf,0x11,PTR_LAB_03019070);
    }
    display_fill_rect(0xc3,y0,0xe5,y0 + 0x10,0);
    return;
  }
  iVar5 = value_at_or_above_low_bound_check(uVar7);
  if (iVar5 != 0) {
    display_blit_bitmap_1bpp(0x29,y0,0x14,0x30,PTR_LAB_030191f8,0xffff);
    goto LAB_03019408;
  }
  uVar6 = get_current_mode_state1();
  if (uVar6 < 3) {
    if ((bStack_50 & 6) == 0) {
      display_blit_bitmap_1bpp(0x19,y0,0xc,0x1e,PTR_LAB_03019200,uVar3);
    }
    else if ((bStack_50 & 6) == 2) {
      display_blit_bitmap_1bpp(0x19,y0,0xc,0x1e,PTR_LAB_03019204,uVar3);
    }
    else {
      display_blit_bitmap_1bpp(0x19,y0,0xc,0x1e,PTR_LAB_03019208,uVar3);
    }
  }
  else if ((p_vfo_freq_display_state->flags_0x10 & 6) == 0) {
    display_blit_bitmap_1bpp(0x19,y0,0xc,0x1e,PTR_LAB_03019200,uVar3);
  }
  else if ((p_vfo_freq_display_state->flags_0x10 & 6) == 2) {
    display_blit_bitmap_1bpp(0x19,y0,0xc,0x1e,PTR_LAB_03019204,uVar3);
  }
  else {
    display_blit_bitmap_1bpp(0x19,y0,0xc,0x1e,PTR_LAB_03019208,uVar3);
  }
  if (((bStack_50 & 0xf0) == 0) || ((bStack_50 & 0xf0) == 0x20)) {
    iVar5 = tone_signaling_type_classify(uVar4);
    if (iVar5 != 0) {
      if (iVar5 == 1) {
        display_blit_bitmap_1bpp(0x29,y0,0x1e,0x3c,PTR_LAB_0301920c,uVar3);
      }
      else {
        display_blit_bitmap_1bpp(0x29,y0,0x1e,0x3c,PTR_LAB_03019210,uVar3);
      }
    }
    if ((bStack_4f & 0x80) == 0) {
      display_blit_bitmap_1bpp(0x4b,y0,0xc,0x1e,PTR_LAB_03019214,uVar3);
    }
  }
  else {
    display_blit_bitmap_1bpp(0x4b,y0,0xc,0x1e,PTR_LAB_03019214,uVar3);
  }
  if (uVar9 == uVar7) {
    bVar8 = bStack_50 & 0xf0;
    if (bVar8 != 0) {
      if ((bStack_4b & 0x20) == 0) {
        p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xfc;
      }
      else {
        p_radio_mode_state_0003e318->flags_0x2 = p_radio_mode_state_0003e318->flags_0x2 & 0xfc | 2;
        if ((bVar8 == 0x10) || (bVar8 == 0x30)) {
          blit_bitmap_with_mutex(0x5b,y0,0x10,PTR_LAB_0301921c,uVar3);
        }
      }
    }
  }
  else {
    bVar8 = (bVar2 >> 3 & 1) << 3;
    bStack_4e = bStack_4e & 0x77 | bVar8 | bVar2 & 0x80;
    if ((bVar8 | bVar2 & 0x80) == 8) {
      blit_bitmap_with_mutex(0x5b,y0,0x10,PTR_LAB_03019384,uVar3);
    }
    else if (uVar9 < uVar7) {
      blit_bitmap_with_mutex(0x5b,y0,0x10,PTR_LAB_03019388,uVar3);
    }
    else {
      blit_bitmap_with_mutex(0x5b,y0,0x10,PTR_LAB_0301938c,uVar3);
    }
  }
  uVar7 = get_current_mode_state1();
  if (uVar7 < 3) {
    if (((bStack_50 & 0xf0) == 0x10) || ((bStack_50 & 0xf0) == 0x30)) {
      if (((*(byte *)PTR_DAT_03019390 & 1) != 0) &&
         ((*(char *)((int)PTR_DAT_03019390 + 5) != '\0' &&
          ((*(byte *)((int)PTR_DAT_03019394 + 3) & 1) != 0)))) {
        if ((*(byte *)PTR_DAT_03019390 & 4) == 0) {
          display_blit_image(0x6f,y0,0x12,0x12,PTR_s__________________0301939c);
        }
        else {
          display_blit_image(0x6f,y0,0x12,0x12,PTR_s__________________03019398);
        }
      }
      goto LAB_030192e2;
    }
  }
  else {
LAB_030192e2:
    if (((bStack_50 & 0xf0) == 0x10) || ((bStack_50 & 0xf0) == 0x30)) {
      if ((cVar1 != '\0') && ((bStack_49 & 0x40) != 0)) {
        display_blit_image(0x83,y0,0x10,0x10,PTR_LAB_030193a0);
      }
      if (((*(byte *)PTR_DAT_03019394 & 0x10) != 0) && ((PTR_DAT_030193a4[0x2b] & 1) != 0)) {
        display_blit_image(0xaa,y0_00,0x14,0x14,PTR_LAB_030193a8);
      }
    }
  }
  if ((bStack_43 & 0x10) != 0) {
    display_blit_bitmap_1bpp(0x97,y0,0xe,0x16,PTR_DAT_030193ac,uVar3);
  }
LAB_03019408:
  display_blit_bitmap_1bpp(0xc3,y0,0x22,0x50,PTR_DAT_03019594,0xf800);
  bStack_50 = bStack_50 & 0xf0;
  if (bStack_50 == 0x10) {
    display_blit_bitmap_1bpp(0xc3,y0,0x22,0x50,PTR_LAB_030193b0,0xffff);
  }
  else if (bStack_50 == 0x30) {
    display_blit_bitmap_1bpp(0xc3,y0,0x22,0x50,PTR_LAB_03019588,0xffff);
  }
  else if (bStack_50 == 0x20) {
    display_blit_bitmap_1bpp(0xc3,y0,0x22,0x50,PTR_LAB_0301958c,0xffff);
  }
  else {
    display_blit_bitmap_1bpp(0xc3,y0,0x22,0x50,PTR_LAB_03019590,0xffff);
  }
  return;
}


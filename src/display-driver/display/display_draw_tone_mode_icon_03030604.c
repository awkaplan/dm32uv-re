/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_tone_mode_icon @ 03030604 (file base 0x03000000; code starts at 0x03001000)
 * Size: 232 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_tone_mode_icon(char param_1,char param_2,undefined2 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((*PTR_DAT_030306f8 & 0x2001000) != 0) {
    return;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    if ((*PTR_DAT_030306f8 & 0x18000) == 0x8000) {
      return;
    }
    if (param_1 != '\0') {
      uVar2 = 0x22;
LAB_03030654:
      bVar1 = p_radio_mode_state_0003e318[2].field_0x1 >> 1;
      goto LAB_0303065c;
    }
  }
  else if (param_1 != '\0') {
    uVar2 = 0x98;
    goto LAB_03030654;
  }
  bVar1 = p_radio_mode_state_0003e318[2].field_0x1;
  uVar2 = 0x22;
LAB_0303065c:
  if ((bVar1 & 1) == 0) {
    display_blit_bitmap_1bpp(0xc3,uVar2,0x22,0x50,PTR_DAT_03030700,param_3);
    if (param_2 == '\0') {
      display_blit_bitmap_1bpp(0xc3,uVar2,0x22,0x50,PTR_LAB_03030704,0xffff);
    }
    else if (param_2 == '\x02') {
      display_blit_bitmap_1bpp(0xc3,uVar2,0x22,0x50,PTR_LAB_03030708,0xffff);
    }
    else if (param_2 == '\x03') {
      display_blit_bitmap_1bpp(0xc3,uVar2,0x22,0x50,PTR_LAB_0303070c,0xffff);
    }
    else {
      display_blit_bitmap_1bpp(0xc3,uVar2,0x22,0x50,PTR_LAB_03030710,0xffff);
    }
  }
  return;
}


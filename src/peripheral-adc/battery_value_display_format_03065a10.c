/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: battery_value_display_format @ 03065a10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 374 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-adc
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void battery_value_display_format(char param_1)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  short y0;
  short sVar4;
  byte local_30 [12];
  
  if (*(char *)PTR_DAT_03065b4c == '\0') {
    uVar3 = (uint)*(ushort *)PTR_DAT_03065b40 * 10;
    if (uVar3 < 100000) {
      number_to_string_format_2args(local_30,PTR_s__d__03d_03065b50,uVar3 / 1000,uVar3 % 1000);
    }
    else {
      number_to_string_format_2args
                (local_30,PTR_s__d__02d_03065b54,uVar3 / 1000,(uVar3 % 1000) / 10);
    }
    if (param_1 == '\0') {
      sVar1 = 0x22;
      sVar4 = 0x3b;
    }
    else {
      sVar1 = 0x98;
      sVar4 = 0xb1;
    }
    if (p_dm32_settings_block04[0x6c] == '\0') {
      display_fill_rect(0,0x1b,0xf0,0xb1,0);
      sVar1 = 0x3b;
      sVar4 = 0x59;
    }
    y0 = sVar4 + 0x2d;
    display_draw_number_centered(sVar1,0xffff,0,(uint)PTR_LAB_03065b58);
    display_blit_bitmap_1bpp(0x62,sVar4,0x2a,0xe4,PTR_LAB_03065b5c,0xffff);
    display_fill_rect(10,y0,0xe3,sVar4 + 0x48,0);
    if ((PTR_DAT_03065b60[2] & 2) == 0) {
      uVar3 = 0;
      sVar1 = 0x2f;
      do {
        if (local_30[uVar3] == 0x2e) {
          display_plot_glyph_2color(sVar1,sVar4 + 0x41,10,0xe,PTR_LAB_03065b64,0xffff,0);
        }
        else {
          uVar2 = table_index_ptr_0x6c_byte(local_30[uVar3] - 0x30);
          display_plot_glyph_2color(sVar1,y0,0x1b,0x6c,uVar2,0xffff,0);
        }
        if (local_30[uVar3] == 0x2e) {
          sVar1 = sVar1 + 10;
        }
        else if (local_30[uVar3] == 0x31) {
          sVar1 = sVar1 + 0x14;
        }
        else {
          sVar1 = sVar1 + 0x1b;
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while (local_30[uVar3] != 0);
    }
    else {
      display_draw_number_centered(y0,0xffff,0,(uint)PTR_s_Seek____03065b48);
    }
  }
  return;
}


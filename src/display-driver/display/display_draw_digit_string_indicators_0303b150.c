/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_digit_string_indicators @ 0303b150 (file base 0x03000000; code starts at 0x03001000)
 * Size: 240 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_digit_string_indicators(byte *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    uVar4 = 0x3b;
  }
  else {
    uVar4 = 0xb1;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    uVar4 = 0x59;
  }
  uVar1 = table_index_ptr_0x6c_byte(10);
  display_plot_glyph_2color(0x34,uVar4,0x1b,0x6c,uVar1,0xffff,0);
  uVar1 = table_index_ptr_0x6c_byte(0xb);
  display_plot_glyph_2color(0x4f,uVar4,0x1b,0x6c,uVar1,0xffff,0);
  uVar1 = table_index_ptr_0x6c_byte(0xc);
  display_plot_glyph_2color(0x6a,uVar4,0x1b,0x6c,uVar1,0xffff,0);
  uVar2 = (uint)*param_1;
  if (uVar2 != 0) {
    cVar3 = -0x7b;
    do {
      if (uVar2 < 0x30) {
        uVar1 = table_index_ptr_0x6c_byte(0xc);
        display_plot_glyph_2color(cVar3,uVar4,0x1b,0x6c,uVar1,0xffff,0);
      }
      else {
        uVar1 = table_index_ptr_0x6c_byte(uVar2 - 0x30);
        display_plot_glyph_2color(cVar3,uVar4,0x1b,0x6c,uVar1,0xffff,0);
      }
      if (*param_1 == 0x31) {
        cVar3 = cVar3 + '\x14';
      }
      else {
        cVar3 = cVar3 + '\x1b';
      }
      param_1 = param_1 + 1;
      uVar2 = (uint)*param_1;
    } while (uVar2 != 0);
  }
  return;
}


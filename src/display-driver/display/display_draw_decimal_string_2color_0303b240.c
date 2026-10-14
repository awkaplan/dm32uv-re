/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_decimal_string_2color @ 0303b240 (file base 0x03000000; code starts at 0x03001000)
 * Size: 258 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_decimal_string_2color(byte *param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  
  puVar1 = PTR_LAB_0303b4f4;
  if ((*PTR_DAT_0303b2b4 & 0x18000) == 0x8000) {
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      iVar5 = 0xb1;
    }
    else {
      iVar5 = 0x3b;
    }
    if (p_dm32_settings_block04[0x6c] == '\0') {
      iVar5 = 0x59;
    }
    iVar5 = iVar5 + 0x2d;
    sVar4 = 0x2f;
  }
  else if (p_dm32_settings_block04[0x6c] == '\0') {
    sVar4 = 8;
    iVar5 = 0x59;
  }
  else {
    sVar4 = 8;
    if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
      iVar5 = 0x3b;
    }
    else {
      iVar5 = 0xb1;
    }
  }
  uVar2 = (uint)*param_1;
  if (uVar2 != 0) {
    do {
      if (uVar2 < 0x30) {
        if (uVar2 == 0x2d) {
          uVar3 = table_index_ptr_0x6c_byte(0xc);
          display_plot_glyph_2color(sVar4,iVar5,0x1b,0x6c,uVar3,0xffff,0);
        }
        else {
          display_plot_glyph_2color(sVar4,iVar5 + 0x14,10,0xe,puVar1,0xffff,0);
        }
      }
      else {
        uVar3 = table_index_ptr_0x6c_byte(uVar2 - 0x30);
        display_plot_glyph_2color(sVar4,iVar5,0x1b,0x6c,uVar3,0xffff,0);
      }
      if (*param_1 == 0x2e) {
        sVar4 = sVar4 + 10;
      }
      else {
        sVar4 = sVar4 + 0x1b;
      }
      param_1 = param_1 + 1;
      uVar2 = (uint)*param_1;
    } while (uVar2 != 0);
  }
  return;
}


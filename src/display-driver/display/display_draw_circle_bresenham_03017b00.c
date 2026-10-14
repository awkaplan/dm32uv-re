/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_circle_bresenham @ 03017b00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 226 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_circle_bresenham(uint param_1,uint param_2,uint param_3,undefined2 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uStack_38;
  undefined4 uStack_28;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  param_3 = param_3 & 0xff;
  uStack_38 = param_3 * -2 + 3;
  uStack_28 = 4;
  uVar6 = 0;
  iVar7 = 0;
  do {
    uVar1 = param_1 - uVar6 & 0xffff;
    uVar5 = param_3 & 0xffff;
    uVar2 = param_2 - uVar5 & 0xffff;
    display_plot_pixel(uVar1,uVar2,param_4);
    uVar8 = uVar5 + param_1 & 0xffff;
    uVar3 = uVar6 + param_2 & 0xffff;
    display_plot_pixel(uVar8,uVar3,param_4);
    uVar4 = param_2 - uVar6 & 0xffff;
    display_plot_pixel(uVar8,uVar4,param_4);
    uVar8 = uVar5 + param_2 & 0xffff;
    display_plot_pixel(uVar1,uVar8,param_4);
    uVar1 = uVar6 + param_1 & 0xffff;
    display_plot_pixel(uVar1,uVar8,param_4);
    uVar5 = param_1 - uVar5 & 0xffff;
    display_plot_pixel(uVar5,uVar4,param_4);
    display_plot_pixel(uVar1,uVar2,param_4);
    display_plot_pixel(uVar5,uVar3,param_4);
    iVar7 = iVar7 + 1;
    if (uStack_38 < 0) {
      uStack_38 = uStack_28 + uStack_38 + 6;
    }
    else {
      uStack_38 = uStack_38 + 10 + (iVar7 - param_3) * 4;
      param_3 = param_3 - 1;
    }
    uVar6 = uVar6 - 1 & 0xffff;
    uStack_28 = uStack_28 + 4;
  } while (iVar7 <= (int)param_3);
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_line_bresenham @ 03017a50 (file base 0x03000000; code starts at 0x03001000)
 * Size: 174 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_line_bresenham(uint param_1,uint param_2,uint param_3,uint param_4,undefined2 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iStack_2c;
  int iStack_28;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  iVar6 = (param_3 & 0xffff) - param_1;
  iVar5 = (param_4 & 0xffff) - param_2;
  if (iVar6 < 1) {
    if (iVar6 == 0) {
      iStack_2c = 0;
    }
    else {
      iVar6 = -iVar6;
      iStack_2c = -1;
    }
  }
  else {
    iStack_2c = 1;
  }
  if (iVar5 < 1) {
    if (iVar5 == 0) {
      iStack_28 = 0;
    }
    else {
      iVar5 = -iVar5;
      iStack_28 = -1;
    }
  }
  else {
    iStack_28 = 1;
  }
  iVar3 = iVar6;
  if (iVar6 <= iVar5) {
    iVar3 = iVar5;
  }
  if (0 < iVar3 + 1) {
    iVar1 = 0;
    iVar2 = 0;
    uVar4 = 0;
    do {
      display_plot_pixel(param_1 & 0xffff,param_2 & 0xffff,param_5);
      iVar2 = iVar2 + iVar6;
      iVar1 = iVar1 + iVar5;
      if (iVar3 < iVar2) {
        iVar2 = iVar2 - iVar3;
        param_1 = param_1 + iStack_2c;
      }
      if (iVar3 < iVar1) {
        iVar1 = iVar1 - iVar3;
        param_2 = param_2 + iStack_28;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while ((int)uVar4 < iVar3 + 1);
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_blit_packed_bitmap_row @ 03019770 (file base 0x03000000; code starts at 0x03001000)
 * Size: 210 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_blit_packed_bitmap_row(int param_1__w,int param_2__w,uint param_3,uint param_4,byte *param_5,int param_6__w)

{
  short param_1 = (short)param_1__w;
  short param_2 = (short)param_2__w;
  undefined2 param_6 = (undefined2)param_6__w;
  int iVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  uint uVar5;
  uint uStack_48;
  byte *pbStack_40;
  
  param_3 = param_3 & 0xffff;
  iVar1 = (int)(param_3 + 7) >> 3;
  if ((param_4 & 0xffff) != 0) {
    pbStack_40 = param_5 + 1;
    uStack_48 = 0;
    while( true ) {
      if (iVar1 == 1) {
        uVar5 = (uint)*param_5;
      }
      else if (iVar1 == 2) {
        uVar5 = (uint)CONCAT11(*param_5,*pbStack_40);
      }
      else {
        uVar5 = (uint)*param_5 << 0x10 | (uint)*pbStack_40 << 8 | (uint)param_5[2];
      }
      if (param_3 != 0) {
        uVar3 = 0;
        uVar2 = (param_3 - 1) + (iVar1 * 8 - param_3 & 0xff);
        sVar4 = param_1;
        do {
          if ((1 << (uVar2 & 0x3f) & uVar5) != 0) {
            display_plot_pixel(sVar4,param_2,param_6);
          }
          uVar3 = uVar3 + 1;
          uVar2 = uVar2 - 1;
          sVar4 = sVar4 + 1;
        } while (uVar3 < param_3);
      }
      uStack_48 = uStack_48 + 1;
      param_5 = param_5 + iVar1;
      pbStack_40 = pbStack_40 + iVar1;
      if ((param_4 & 0xffff) <= uStack_48) break;
      param_2 = param_2 + 1;
    }
  }
  return;
}


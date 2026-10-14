/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: blit_bitmap_8x8_two_blocks @ 03018128 (file base 0x03000000; code starts at 0x03001000)
 * Size: 166 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void blit_bitmap_8x8_two_blocks(short param_1,short param_2,int param_3,undefined2 param_4)

{
  int iVar1;
  short sVar2;
  byte *pbVar3;
  short sVar4;
  uint uVar5;
  
  uVar5 = 0;
  sVar4 = param_1;
  do {
    iVar1 = 0;
    sVar2 = param_2;
    while( true ) {
      if (((uint)*(byte *)(param_3 + iVar1) & 1 << (uVar5 & 0x3f)) != 0) {
        display_plot_pixel(sVar2,sVar4,param_4);
      }
      iVar1 = iVar1 + 1;
      if (iVar1 == 8) break;
      sVar2 = sVar2 + 1;
    }
    sVar4 = sVar4 + 1;
    uVar5 = uVar5 + 1;
  } while (uVar5 != 8);
  param_1 = param_1 + 8;
  uVar5 = 0;
  while( true ) {
    sVar2 = 8;
    pbVar3 = (byte *)(param_3 + 8);
    sVar4 = param_2;
    while( true ) {
      if (((uint)*pbVar3 & 1 << (uVar5 & 0x3f)) != 0) {
        display_plot_pixel(sVar4,param_1,param_4);
      }
      sVar2 = sVar2 + -1;
      pbVar3 = pbVar3 + 1;
      if (sVar2 == 0) break;
      sVar4 = sVar4 + 1;
    }
    uVar5 = uVar5 + 1;
    if (uVar5 == 8) break;
    param_1 = param_1 + 1;
  }
  return;
}


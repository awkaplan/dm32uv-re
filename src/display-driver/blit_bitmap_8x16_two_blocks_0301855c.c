/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: blit_bitmap_8x16_two_blocks @ 0301855c (file base 0x03000000; code starts at 0x03001000)
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

void blit_bitmap_8x16_two_blocks(short param_1,short param_2,int param_3,undefined2 param_4)

{
  char cVar1;
  int iVar2;
  short sVar3;
  byte *pbVar4;
  short sVar5;
  uint uVar6;
  
  uVar6 = 0;
  sVar5 = param_1;
  do {
    iVar2 = 0;
    sVar3 = param_2;
    while( true ) {
      if (((uint)*(byte *)(param_3 + iVar2) & 1 << (uVar6 & 0x3f)) != 0) {
        display_plot_pixel(sVar3,sVar5,param_4);
      }
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x10) break;
      sVar3 = sVar3 + 1;
    }
    sVar5 = sVar5 + 1;
    uVar6 = uVar6 + 1;
  } while (uVar6 != 8);
  param_1 = param_1 + 8;
  uVar6 = 0;
  while( true ) {
    cVar1 = '\x10';
    pbVar4 = (byte *)(param_3 + 0x10);
    sVar5 = param_2;
    while( true ) {
      if (((uint)*pbVar4 & 1 << (uVar6 & 0x3f)) != 0) {
        display_plot_pixel(sVar5,param_1,param_4);
      }
      cVar1 = cVar1 + -1;
      pbVar4 = pbVar4 + 1;
      if (cVar1 == '\0') break;
      sVar5 = sVar5 + 1;
    }
    uVar6 = uVar6 + 1;
    if (uVar6 == 8) break;
    param_1 = param_1 + 1;
  }
  return;
}


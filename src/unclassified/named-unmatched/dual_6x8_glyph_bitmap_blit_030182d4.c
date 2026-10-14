/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dual_6x8_glyph_bitmap_blit @ 030182d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 172 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dual_6x8_glyph_bitmap_blit(short param_1,uint param_2,byte *param_3,undefined2 param_4)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  short sVar4;
  
  uVar3 = 7;
  sVar4 = param_1;
  do {
    uVar1 = 0;
    pbVar2 = param_3;
    do {
      if (((uint)*pbVar2 & 1 << (uVar3 & 0x3f)) != 0) {
        display_plot_pixel((uVar1 >> 1) + (param_2 & 0xffff) & 0xffff,sVar4,param_4);
      }
      uVar1 = uVar1 + 2 & 0xff;
      pbVar2 = pbVar2 + 2;
    } while (uVar1 != 0xc);
    sVar4 = sVar4 + 1;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0xffffffff);
  param_1 = param_1 + 8;
  uVar3 = 7;
  while( true ) {
    uVar1 = 1;
    pbVar2 = param_3 + 1;
    do {
      if (((uint)*pbVar2 & 1 << (uVar3 & 0x3f)) != 0) {
        display_plot_pixel((uVar1 >> 1) + (param_2 & 0xffff) & 0xffff,param_1,param_4);
      }
      uVar1 = uVar1 + 2 & 0xff;
      pbVar2 = pbVar2 + 2;
    } while (uVar1 != 0xd);
    uVar3 = uVar3 - 1;
    if (uVar3 == 0xffffffff) break;
    param_1 = param_1 + 1;
  }
  return;
}


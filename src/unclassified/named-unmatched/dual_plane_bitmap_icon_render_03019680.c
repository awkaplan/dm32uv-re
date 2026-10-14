/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dual_plane_bitmap_icon_render @ 03019680 (file base 0x03000000; code starts at 0x03001000)
 * Size: 216 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dual_plane_bitmap_icon_render
               (uint param_1,short param_2,uint param_3,int param_4,undefined2 param_5)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  param_3 = param_3 & 0xff;
  os_sem_pend_ms(_DAT_0301976c,0);
  uVar2 = 0;
  uVar4 = 0;
  do {
    if (param_3 != 0) {
      uVar1 = 0;
      do {
        if (((uint)*(byte *)(param_4 + uVar1) & 1 << (uVar4 & 0x3f)) != 0) {
          display_plot_pixel(uVar2 + (param_1 & 0xffff) & 0xffff,param_2,param_5);
        }
        uVar2 = uVar2 + 1 & 0xff;
        if (param_3 <= uVar2) {
          param_2 = param_2 + 1;
          uVar2 = 0;
        }
        uVar1 = uVar1 + 1;
      } while ((uVar1 & 0xff) < param_3);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  uVar4 = 0;
  do {
    if (param_3 != 0) {
      pbVar3 = (byte *)(param_4 + param_3);
      uVar1 = 0;
      do {
        if (((uint)*pbVar3 & 1 << (uVar4 & 0x3f)) != 0) {
          display_plot_pixel(uVar2 + (param_1 & 0xffff) & 0xffff,param_2,param_5);
        }
        uVar2 = uVar2 + 1 & 0xff;
        if (param_3 <= uVar2) {
          param_2 = param_2 + 1;
          uVar2 = 0;
        }
        uVar1 = uVar1 + 1 & 0xff;
        pbVar3 = pbVar3 + 1;
      } while (uVar1 < param_3);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 8);
  os_sem_post(_DAT_0301976c);
  return;
}


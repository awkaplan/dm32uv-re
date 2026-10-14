/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_glyph_ascii @ 0301874c (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_draw_glyph_ascii
               (ushort param_1,uint param_2,int param_3,uint param_4,undefined2 param_5,
               undefined2 param_6)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  
  param_2 = param_2 & 0xffff;
  uVar3 = param_4 & 0xff;
  uVar2 = ((uint)((param_4 & 7) != 0) + (uVar3 >> 3)) * (uVar3 >> 1) & 0xff;
  if ((uVar2 != 0) && (uVar3 == 0x18)) {
    pcVar5 = PTR_LAB_03018934 + (param_3 - 0x20U & 0xff) * 0x24;
    uVar6 = 0;
    uVar3 = param_2;
    do {
      cVar1 = *pcVar5;
      uVar4 = uVar3 + 8;
      while( true ) {
        if (cVar1 < '\0') {
          display_plot_pixel(param_1,uVar3,param_5);
        }
        else {
          display_plot_pixel(param_1,uVar3,param_6);
        }
        uVar3 = uVar3 + 1 & 0xffff;
        if (0x13f < uVar3) {
          return;
        }
        if (uVar3 - param_2 == 0x18) break;
        if (uVar3 == (uVar4 & 0xffff)) goto LAB_030187e2;
        cVar1 = cVar1 * '\x02';
      }
      param_1 = param_1 + 1;
      uVar3 = param_2;
      if (0xef < param_1) {
        return;
      }
LAB_030187e2:
      uVar6 = uVar6 + 1 & 0xff;
      pcVar5 = pcVar5 + 1;
    } while (uVar6 < uVar2);
  }
  return;
}


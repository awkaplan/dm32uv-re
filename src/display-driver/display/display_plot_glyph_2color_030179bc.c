/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_plot_glyph_2color @ 030179bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 148 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_plot_glyph_2color(int param_1__w,int param_2__w,int param_3__w,uint param_4,int param_5,int param_6__w,int param_7__w)

{
  short param_1 = (short)param_1__w;
  short param_2 = (short)param_2__w;
  ushort param_3 = (ushort)param_3__w;
  undefined2 param_6 = (undefined2)param_6__w;
  undefined2 param_7 = (undefined2)param_7__w;
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  os_sem_pend_ms(p_ucos_mutex_00039344,0);
  if ((param_4 & 0xffff) != 0) {
    uVar2 = 0;
    uVar4 = 0;
    do {
      bVar1 = *(byte *)(param_5 + uVar4);
      uVar3 = 7;
      do {
        if (((int)(uint)bVar1 >> (uVar3 & 0x3f) & 1U) == 0) {
          display_plot_pixel(uVar2 + param_1,param_2,param_7);
        }
        else {
          display_plot_pixel(uVar2 + param_1,param_2,param_6);
        }
        uVar2 = uVar2 + 1 & 0xff;
        if (param_3 <= uVar2) {
          param_2 = param_2 + 1;
          uVar2 = 0;
          break;
        }
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0xffffffff);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < (param_4 & 0xffff));
  }
  os_sem_post(p_ucos_mutex_00039344);
  return;
}


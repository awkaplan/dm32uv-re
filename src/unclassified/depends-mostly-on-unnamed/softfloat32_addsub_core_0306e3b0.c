/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softfloat32_addsub_core @ 0306e3b0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 318 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint * softfloat32_addsub_core(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *param_1;
  if (uVar1 < 2) {
    return param_1;
  }
  uVar6 = *param_2;
  if (uVar6 < 2) {
    return param_2;
  }
  if (uVar1 == 4) {
    if (uVar6 != 4) {
      return param_1;
    }
    if (param_1[1] != param_2[1]) {
      param_1 = DAT_0306e560;
    }
    return param_1;
  }
  if (uVar6 == 4) {
    return param_2;
  }
  if (uVar6 == 2) {
    if (uVar1 != 2) {
      return param_1;
    }
    *param_3 = 2;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[1] = param_1[1] & param_2[1];
    return param_3;
  }
  if (uVar1 == 2) {
    return param_2;
  }
  uVar6 = param_1[2];
  uVar3 = param_2[2];
  uVar4 = uVar6 - uVar3;
  uVar1 = uVar4;
  if ((int)uVar4 < 0) {
    uVar1 = ~uVar4 + 1;
  }
  uVar5 = param_1[3];
  uVar2 = param_2[3];
  if ((int)uVar1 < 0x20) {
    uVar3 = uVar6;
    if ((int)uVar4 < 1) {
      if (uVar4 != 0) {
        uVar3 = uVar6 + uVar1;
        uVar5 = uVar5 >> (uVar1 & 0x3f) | (uint)(((1 << (uVar1 & 0x3f)) - 1U & uVar5) != 0);
      }
    }
    else {
      uVar2 = uVar2 >> (uVar1 & 0x3f) | (uint)(((1 << (uVar1 & 0x3f)) - 1U & uVar2) != 0);
    }
LAB_0306e406:
    uVar1 = param_1[1];
    uVar6 = uVar3;
    if (uVar1 != param_2[1]) {
LAB_0306e40e:
      if (uVar1 == 0) {
        uVar2 = uVar5 - uVar2;
        if (-1 < (int)uVar2) goto LAB_0306e418;
LAB_0306e4a4:
        uVar2 = -uVar2;
        param_3[1] = 1;
        param_3[2] = uVar6;
        param_3[3] = uVar2;
      }
      else {
        uVar2 = uVar2 - uVar5;
        if ((int)uVar2 < 0) goto LAB_0306e4a4;
LAB_0306e418:
        param_3[1] = 0;
        param_3[2] = uVar6;
        param_3[3] = uVar2;
      }
      if (uVar2 - 1 < 0x3fffffff) {
        uVar1 = param_3[2];
        do {
          uVar2 = uVar2 * 2;
          uVar1 = uVar1 - 1;
        } while (uVar2 - 1 < 0x3fffffff);
        param_3[3] = uVar2;
        param_3[2] = uVar1;
      }
      *param_3 = 3;
      goto joined_r0x0306e468;
    }
  }
  else {
    if ((int)uVar6 <= (int)uVar3) {
      uVar5 = 0;
      goto LAB_0306e406;
    }
    uVar1 = param_1[1];
    uVar2 = 0;
    if (uVar1 != param_2[1]) goto LAB_0306e40e;
  }
  uVar2 = uVar2 + uVar5;
  param_3[1] = uVar1;
  param_3[2] = uVar6;
  param_3[3] = uVar2;
  *param_3 = 3;
joined_r0x0306e468:
  if (-1 < (int)uVar2) {
    return param_3;
  }
  param_3[3] = uVar2 >> 1 | uVar2 & 1;
  param_3[2] = param_3[2] + 1;
  return param_3;
}


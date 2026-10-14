/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_addsub_core @ 0306e940 (file base 0x03000000; code starts at 0x03001000)
 * Size: 844 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint * soft_double_addsub_core(uint *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uStack_60;
  uint uStack_5c;
  
  uVar2 = *param_1;
  if (uVar2 < 2) {
    return param_1;
  }
  uVar4 = *param_2;
  if (uVar4 < 2) {
    return param_2;
  }
  if (uVar2 == 4) {
    if (uVar4 != 4) {
      return param_1;
    }
    if (param_1[1] == param_2[1]) {
      return param_1;
    }
    return DAT_0306ed0c;
  }
  if (uVar4 == 4) {
    return param_2;
  }
  if (uVar4 == 2) {
    if (uVar2 != 2) {
      return param_1;
    }
    *param_3 = 2;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[4] = param_1[4];
    param_3[1] = param_1[1] & param_2[1];
    return param_3;
  }
  if (uVar2 == 2) {
    return param_2;
  }
  uVar4 = param_1[2];
  uVar8 = param_2[2];
  uVar9 = uVar4 - uVar8;
  uStack_60 = param_1[3];
  uVar6 = param_1[4];
  uVar2 = uVar9;
  if ((int)uVar9 < 0) {
    uVar2 = ~uVar9 + 1;
  }
  uVar5 = param_2[3];
  uVar7 = param_2[4];
  uStack_5c = uVar6;
  if ((int)uVar2 < 0x40) {
    uVar8 = uVar4;
    if ((int)uVar9 < 1) {
      if (uVar9 != 0) {
        uVar8 = uVar2 - 0x20;
        uVar9 = (uVar6 << 1) << (0x1f - uVar2 & 0x3f) | uStack_60 >> (uVar2 & 0x3f);
        if ((uVar8 & 0x80000000) == 0) {
          uVar9 = uVar6 >> (uVar8 & 0x3f);
        }
        uStack_5c = 0;
        if ((uVar8 & 0x80000000) != 0) {
          uStack_5c = uVar6 >> (uVar2 & 0x3f);
        }
        iVar10 = 1 << (uVar8 & 0x3f);
        if ((uVar8 & 0x80000000) != 0) {
          iVar10 = 0;
        }
        iVar3 = 0;
        if ((uVar8 & 0x80000000) != 0) {
          iVar3 = 1 << (uVar2 & 0x3f);
        }
        uVar8 = uVar4 + uVar2;
        uStack_60 = ((iVar3 - 1U & uStack_60) != 0 ||
                    ((iVar10 + -1) - ((int)((uint)(iVar3 != 0) << 0x1f) >> 0x1f) & uVar6) != 0) |
                    uVar9;
      }
    }
    else {
      uVar6 = uVar2 - 0x20;
      uVar4 = (uVar7 << 1) << (0x1f - uVar2 & 0x3f) | uVar5 >> (uVar2 & 0x3f);
      if ((uVar6 & 0x80000000) == 0) {
        uVar4 = uVar7 >> (uVar6 & 0x3f);
      }
      uVar9 = 0;
      if ((uVar6 & 0x80000000) != 0) {
        uVar9 = uVar7 >> (uVar2 & 0x3f);
      }
      iVar10 = 1 << (uVar6 & 0x3f);
      iVar3 = 1 << (uVar2 & 0x3f);
      if ((uVar6 & 0x80000000) != 0) {
        iVar10 = 0;
      }
      if ((uVar6 & 0x80000000) == 0) {
        iVar3 = 0;
      }
      uVar5 = ((iVar3 - 1U & uVar5) != 0 ||
              ((iVar10 + -1) - ((int)((uint)(iVar3 != 0) << 0x1f) >> 0x1f) & uVar7) != 0) | uVar4;
      uVar7 = uVar9;
    }
LAB_0306ea2e:
    uVar6 = param_1[1];
    uVar2 = uVar7;
    uVar4 = uVar8;
    if (uVar6 != param_2[1]) {
LAB_0306ea36:
      if (uVar6 == 0) {
        uVar8 = uStack_60 - uVar5;
        uVar2 = (uStack_5c - uVar2) - (uVar5 <= uStack_60 ^ 1);
        if (-1 < (int)uVar2) goto LAB_0306ea50;
LAB_0306eb7e:
        bVar1 = uVar8 == 0;
        uVar8 = -uVar8;
        uVar2 = -(bVar1 ^ 1) - uVar2;
        param_3[2] = uVar4;
        param_3[1] = 1;
        param_3[3] = uVar8;
        param_3[4] = uVar2;
      }
      else {
        uVar8 = uVar5 - uStack_60;
        uVar2 = (uVar2 - uStack_5c) - (uStack_60 <= uVar5 ^ 1);
        if ((int)uVar2 < 0) goto LAB_0306eb7e;
LAB_0306ea50:
        param_3[1] = 0;
        param_3[2] = uVar4;
        param_3[3] = uVar8;
        param_3[4] = uVar2;
      }
      uVar4 = (uVar2 - 1) - ((int)((uint)(uVar8 != 0) << 0x1f) >> 0x1f);
      if ((uVar4 < 0x10000000) && ((uVar4 != 0xfffffff || (uVar8 != 0)))) {
        uVar4 = param_3[2];
        do {
          bVar1 = CARRY4(uVar8,uVar8);
          uVar8 = uVar8 * 2;
          uVar2 = uVar2 * 2 - ((int)((uint)bVar1 << 0x1f) >> 0x1f);
          uVar6 = (uVar2 - 1) - ((int)((uint)(uVar8 != 0) << 0x1f) >> 0x1f);
          uVar4 = uVar4 - 1;
          if (0xfffffff < uVar6) break;
        } while ((uVar6 != 0xfffffff) || (uVar8 != 0));
        param_3[3] = uVar8;
        param_3[4] = uVar2;
        param_3[2] = uVar4;
      }
      goto LAB_0306eac0;
    }
  }
  else {
    if ((int)uVar4 <= (int)uVar8) {
      uStack_60 = 0;
      uStack_5c = 0;
      goto LAB_0306ea2e;
    }
    uVar6 = param_1[1];
    uVar5 = 0;
    uVar7 = 0;
    uVar2 = uVar5;
    if (uVar6 != param_2[1]) goto LAB_0306ea36;
  }
  uVar8 = uVar5 + uStack_60;
  uVar2 = (uVar7 + uStack_5c) - ((int)((uint)CARRY4(uVar5,uStack_60) << 0x1f) >> 0x1f);
  param_3[1] = uVar6;
  param_3[2] = uVar4;
  param_3[3] = uVar8;
  param_3[4] = uVar2;
LAB_0306eac0:
  *param_3 = 3;
  if (0x1fffffff < uVar2) {
    param_3[3] = uVar8 & 1 | uVar2 << 0x1f | uVar8 >> 1;
    param_3[4] = uVar2 >> 1;
    param_3[2] = param_3[2] + 1;
  }
  return param_3;
}


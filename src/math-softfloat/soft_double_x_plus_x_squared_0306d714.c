/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_x_plus_x_squared @ 0306d714 (file base 0x03000000; code starts at 0x03001000)
 * Size: 474 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint soft_double_x_plus_x_squared(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  if ((param_2 & 0x7ff00000) == 0x7ff00000) {
    uVar5 = param_2;
    uVar3 = soft_double_multiply(param_1,param_2,param_1,param_2);
    uVar5 = soft_double_add(param_1,param_2,uVar3,uVar5);
    return uVar5;
  }
  if ((int)param_2 < 1) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return param_1;
    }
    if (param_2 != 0) {
      soft_double_sub(param_1,param_2,param_1,param_2);
      uVar5 = soft_double_divide();
      return uVar5;
    }
    iVar4 = 0;
    do {
      iVar10 = iVar4;
      param_2 = param_1 >> 0xb;
      param_1 = param_1 << 0x15;
      iVar4 = iVar10 + -0x15;
    } while (param_2 == 0);
    iVar10 = iVar10 + -0x14;
LAB_0306d83e:
    uVar5 = 0;
    if ((param_2 & 0x100000) == 0) {
      do {
        param_2 = param_2 * 2;
        uVar5 = uVar5 + 1;
      } while ((param_2 & 0x100000) == 0);
      uVar7 = 0x20 - uVar5;
    }
    else {
      uVar7 = 0x20;
      uVar5 = 0;
    }
    iVar10 = iVar10 - uVar5;
    param_2 = param_2 | param_1 >> (uVar7 & 0x3f);
    param_1 = param_1 << (uVar5 & 0x3f);
  }
  else {
    iVar10 = (int)param_2 >> 0x14;
    if (iVar10 == 0) {
      iVar10 = 1;
      goto LAB_0306d83e;
    }
  }
  uVar5 = param_2 & 0xfffff | 0x100000;
  if ((iVar10 - 0x3ffU & 1) != 0) {
    uVar5 = uVar5 * 2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 * 2;
  }
  uVar7 = 0;
  iVar10 = uVar5 * 2 - ((int)param_1 >> 0x1f);
  param_1 = param_1 * 2;
  iVar8 = 0x16;
  uVar5 = 0x200000;
  iVar4 = 0;
  do {
    iVar1 = iVar4 + uVar5;
    iVar8 = iVar8 + -1;
    if (iVar1 <= iVar10) {
      iVar10 = iVar10 - iVar1;
      iVar4 = iVar1 + uVar5;
      uVar7 = uVar7 + uVar5;
    }
    iVar10 = iVar10 * 2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 * 2;
    uVar5 = uVar5 >> 1;
  } while (iVar8 != 0);
  uVar6 = 0x80000000;
  uVar5 = 0;
  uVar9 = 0;
  iVar8 = 0x20;
  do {
    while( true ) {
      iVar1 = iVar8;
      uVar2 = uVar6 + uVar9;
      if ((iVar10 <= iVar4) &&
         ((iVar8 = iVar4, iVar10 != iVar4 || (iVar8 = iVar10, param_1 < uVar2)))) break;
      uVar9 = uVar2 + uVar6;
      iVar8 = iVar4;
      if (((uVar2 & 0x80000000) == 0x80000000) && ((uVar9 & 0x80000000) == 0)) {
        iVar8 = iVar4 + 1;
      }
      iVar10 = iVar10 - iVar4;
      if (param_1 < uVar2) {
        iVar10 = iVar10 + -1;
      }
      uVar5 = uVar5 + uVar6;
      iVar10 = iVar10 * 2 - ((int)(param_1 - uVar2) >> 0x1f);
      param_1 = (param_1 - uVar2) * 2;
      uVar6 = uVar6 >> 1;
      iVar4 = iVar8;
      iVar8 = iVar1 + -1;
      if (iVar1 + -1 == 0) goto LAB_0306d7e2;
    }
    iVar10 = iVar10 * 2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 * 2;
    uVar6 = uVar6 >> 1;
    iVar4 = iVar8;
    iVar8 = iVar1 + -1;
  } while (iVar1 + -1 != 0);
LAB_0306d7e2:
  uVar9 = iVar1 - 1;
  if (param_1 != 0 || iVar10 != 0) {
    if (uVar5 == 0xffffffff) {
      uVar7 = uVar7 + 1;
      goto LAB_0306d7f8;
    }
    uVar5 = uVar5 + (uVar5 & 1);
  }
  uVar9 = uVar5 >> 1;
LAB_0306d7f8:
  if ((uVar7 & 1) != 0) {
    uVar9 = uVar9 | 0x80000000;
  }
  return uVar9;
}


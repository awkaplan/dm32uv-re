/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softdouble_divide_guarded @ 0306e0c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 638 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint softdouble_divide_guarded(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar4 = param_4 & 0x7fffffff;
  if (((uVar4 == 0 && param_3 == 0) ||
      (uVar6 = param_2 & 0x80000000 ^ param_2, 0x7fefffff < (int)uVar6)) ||
     (0x7ff00000 < ((-param_3 | param_3) >> 0x1f | uVar4))) {
    soft_double_multiply();
    uVar4 = soft_double_divide();
    return uVar4;
  }
  if ((int)uVar6 <= (int)uVar4) {
    if (((int)uVar4 <= (int)uVar6) && (param_3 <= param_1)) {
      if (param_1 != param_3) goto LAB_0306e12c;
      param_1 = PTR_DAT_0306e258[((int)param_2 >> 0x1f) * -2];
    }
    return param_1;
  }
LAB_0306e12c:
  if ((int)uVar6 < 0x100000) {
    if (uVar6 == 0) {
      if ((int)param_1 < 1) {
        iVar2 = -0x413;
      }
      else {
        iVar2 = -0x413;
        uVar1 = param_1;
        do {
          uVar1 = uVar1 * 2;
          iVar2 = iVar2 + -1;
        } while (0 < (int)uVar1);
      }
    }
    else {
      iVar3 = param_2 << 0xb;
      if (iVar3 < 1) {
        iVar2 = -0x3fe;
      }
      else {
        iVar2 = -0x3fe;
        do {
          iVar3 = iVar3 * 2;
          iVar2 = iVar2 + -1;
        } while (0 < iVar3);
      }
    }
  }
  else {
    iVar2 = ((int)uVar6 >> 0x14) + -0x3ff;
  }
  if (uVar4 < 0x100000) {
    if (uVar4 == 0) {
      if ((int)param_3 < 1) {
        iVar3 = -0x413;
      }
      else {
        iVar3 = -0x413;
        uVar1 = param_3;
        do {
          uVar1 = uVar1 * 2;
          iVar3 = iVar3 + -1;
        } while (0 < (int)uVar1);
      }
    }
    else {
      iVar5 = param_4 << 0xb;
      if (iVar5 < 1) {
        iVar3 = -0x3fe;
      }
      else {
        iVar3 = -0x3fe;
        do {
          iVar5 = iVar5 * 2;
          iVar3 = iVar3 + -1;
        } while (0 < iVar5);
      }
    }
  }
  else {
    iVar3 = ((int)uVar4 >> 0x14) + -0x3ff;
  }
  if (iVar2 < -0x3fe) {
    uVar1 = -iVar2 - 0x3fe;
    if ((int)uVar1 < 0x20) {
      uVar6 = param_1 >> (0x20 - uVar1 & 0x3f) | uVar6 << (uVar1 & 0x3f);
      param_1 = param_1 << (uVar1 & 0x3f);
    }
    else {
      uVar6 = param_1 << (-iVar2 - 0x41eU & 0x3f);
      param_1 = 0;
    }
  }
  else {
    uVar6 = uVar6 & 0xfffff | 0x100000;
  }
  if (iVar3 < -0x3fe) {
    uVar1 = -iVar3 - 0x3fe;
    if ((int)uVar1 < 0x20) {
      uVar4 = param_3 >> (0x20 - uVar1 & 0x3f) | uVar4 << (uVar1 & 0x3f);
      param_3 = param_3 << (uVar1 & 0x3f);
    }
    else {
      uVar4 = param_3 << (-iVar3 - 0x41eU & 0x3f);
      param_3 = 0;
    }
  }
  else {
    uVar4 = param_4 & 0xfffff | 0x100000;
  }
  iVar2 = iVar2 - iVar3;
  while( true ) {
    iVar5 = uVar6 - uVar4;
    if (param_1 < param_3) {
      iVar5 = iVar5 + -1;
    }
    uVar1 = param_1 - param_3;
    if (iVar2 == 0) break;
    if (iVar5 < 0) {
      uVar6 = uVar6 * 2 - ((int)param_1 >> 0x1f);
      param_1 = param_1 * 2;
      iVar2 = iVar2 + -1;
    }
    else {
      if (iVar5 == 0 && uVar1 == 0) goto LAB_0306e1ea;
      uVar6 = iVar5 * 2 - ((int)uVar1 >> 0x1f);
      param_1 = uVar1 * 2;
      iVar2 = iVar2 + -1;
    }
  }
  uVar4 = uVar6 - uVar4;
  if (param_1 < param_3) {
    uVar4 = uVar4 - 1;
  }
  if (-1 < (int)uVar4) {
    uVar6 = uVar4;
    param_1 = uVar1;
  }
  if (uVar6 != 0 || param_1 != 0) {
    for (; (int)uVar6 < 0x100000; uVar6 = uVar6 * 2 - iVar2) {
      iVar2 = (int)param_1 >> 0x1f;
      param_1 = param_1 * 2;
      iVar3 = iVar3 + -1;
    }
    if (iVar3 < -0x3fe) {
      uVar4 = -iVar3 - 0x3fe;
      if ((int)uVar4 < 0x15) {
        uVar6 = uVar6 << (0x20 - uVar4 & 0x3f) | param_1 >> (uVar4 & 0x3f);
      }
      else if ((int)uVar4 < 0x20) {
        uVar6 = uVar6 << (0x20 - uVar4 & 0x3f) | param_1 >> (uVar4 & 0x3f);
      }
      else {
        uVar6 = (int)uVar6 >> (-iVar3 - 0x41eU & 0x3f);
      }
      return uVar6;
    }
    return param_1;
  }
LAB_0306e1ea:
  return PTR_DAT_0306e258[((int)param_2 >> 0x1f) * -2];
}


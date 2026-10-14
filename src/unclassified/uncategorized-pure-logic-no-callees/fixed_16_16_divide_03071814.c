/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fixed_16_16_divide @ 03071814 (file base 0x03000000; code starts at 0x03001000)
 * Size: 980 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint fixed_16_16_divide(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_4 != 0) {
    if (param_2 < param_4) {
      uVar1 = 0;
    }
    else {
      if (param_4 < 0x10000) {
        if (param_4 < 0x100) {
          iVar4 = 0;
        }
        else {
          iVar4 = 8;
        }
      }
      else if (param_4 < 0x1000000) {
        iVar4 = 0x10;
      }
      else {
        iVar4 = 0x18;
      }
      uVar1 = (uint)(byte)PTR_DAT_030719b8[param_4 >> iVar4] + iVar4;
      uVar2 = 0x20 - uVar1;
      if (uVar2 == 0) {
        if ((param_4 < param_2) || (param_3 <= param_1)) {
          return 1;
        }
        uVar1 = 0;
      }
      else {
        uVar6 = param_4 << (uVar2 & 0x3f) | param_3 >> (uVar1 & 0x3f);
        uVar10 = param_2 >> (uVar1 & 0x3f);
        uVar5 = uVar6 >> 0x10;
        uVar8 = uVar10 / uVar5;
        uVar3 = param_2 << (uVar2 & 0x3f) | param_1 >> (uVar1 & 0x3f);
        uVar9 = uVar8 * (uVar6 & 0xffff);
        uVar10 = (uVar10 - uVar8 * uVar5) * 0x10000 | uVar3 >> 0x10;
        param_3 = param_3 << (uVar2 & 0x3f);
        uVar1 = uVar8;
        if (uVar10 < uVar9) {
          uVar10 = uVar10 + uVar6;
          uVar1 = uVar8 - 1;
          if ((uVar6 <= uVar10) && (uVar10 < uVar9)) {
            uVar1 = uVar8 - 2;
            uVar10 = uVar10 + uVar6;
          }
        }
        uVar8 = (uVar10 - uVar9) / uVar5;
        uVar7 = uVar8 * (uVar6 & 0xffff);
        uVar9 = ((uVar10 - uVar9) - uVar8 * uVar5) * 0x10000 | uVar3 & 0xffff;
        uVar3 = uVar8;
        if (uVar9 < uVar7) {
          uVar9 = uVar9 + uVar6;
          uVar3 = uVar8 - 1;
          if ((uVar6 <= uVar9) && (uVar9 < uVar7)) {
            uVar3 = uVar8 - 2;
            uVar9 = uVar9 + uVar6;
          }
        }
        uVar1 = uVar3 | uVar1 << 0x10;
        uVar6 = param_3 & 0xffff;
        param_3 = param_3 >> 0x10;
        uVar8 = (uVar3 & 0xffff) * uVar6;
        uVar6 = (uVar1 >> 0x10) * uVar6;
        uVar3 = param_3 * (uVar3 & 0xffff) + uVar6 + (uVar8 >> 0x10);
        iVar4 = (uVar1 >> 0x10) * param_3;
        if (uVar3 < uVar6) {
          iVar4 = iVar4 + 0x10000;
        }
        uVar6 = iVar4 + (uVar3 >> 0x10);
        if ((uVar9 - uVar7 < uVar6) ||
           ((uVar9 - uVar7 == uVar6 &&
            (param_1 << (uVar2 & 0x3f) < uVar3 * 0x10000 + (uVar8 & 0xffff))))) {
          uVar1 = uVar1 - 1;
        }
      }
    }
    return uVar1;
  }
  if (param_2 < param_3) {
    if (param_3 < 0x10000) {
      iVar4 = 0;
      if (0xff < param_3) {
        iVar4 = 8;
      }
    }
    else if (param_3 < 0x1000000) {
      iVar4 = 0x10;
    }
    else {
      iVar4 = 0x18;
    }
    uVar1 = param_3 >> iVar4;
    uVar2 = 0x20 - ((uint)(byte)PTR_DAT_030719b8[uVar1] + iVar4);
    if (uVar2 != 0) {
      param_3 = param_3 << (uVar2 & 0x3f);
      param_2 = param_2 << (uVar2 & 0x3f) |
                param_1 >> ((uint)(byte)PTR_DAT_030719b8[uVar1] + iVar4 & 0x3f);
      param_1 = param_1 << (uVar2 & 0x3f);
    }
    uVar3 = param_3 >> 0x10;
    uVar8 = param_2 / uVar3;
    uVar2 = uVar8 * (param_3 & 0xffff);
    uVar6 = (param_2 - uVar8 * uVar3) * 0x10000 | param_1 >> 0x10;
    uVar1 = uVar8;
    if (uVar6 < uVar2) {
      uVar6 = uVar6 + param_3;
      uVar1 = uVar8 - 1;
      if ((param_3 <= uVar6) && (uVar6 < uVar2)) {
        uVar1 = uVar8 - 2;
        uVar6 = uVar6 + param_3;
      }
    }
    uVar8 = (uVar6 - uVar2) / uVar3;
    uVar9 = uVar8 * (param_3 & 0xffff);
    uVar3 = param_1 & 0xffff | ((uVar6 - uVar2) - uVar8 * uVar3) * 0x10000;
    uVar2 = uVar8;
    if (uVar3 < uVar9) {
      uVar3 = uVar3 + param_3;
      uVar2 = uVar8 - 1;
      if ((param_3 <= uVar3) && (uVar3 < uVar9)) {
        uVar2 = uVar8 - 2;
      }
    }
    return uVar2 | uVar1 << 0x10;
  }
  if (param_3 == 0) {
    param_3 = 1 / 0;
  }
  else {
    if (0xffff < param_3) {
      if (param_3 < 0x1000000) {
        iVar4 = 0x10;
      }
      else {
        iVar4 = 0x18;
      }
      goto LAB_0307192a;
    }
    if (0xff < param_3) {
      iVar4 = 8;
      goto LAB_0307192a;
    }
  }
  iVar4 = 0;
LAB_0307192a:
  uVar1 = (uint)(byte)PTR_DAT_030719b8[param_3 >> iVar4] + iVar4;
  uVar2 = 0x20 - uVar1;
  if (uVar2 == 0) {
    param_2 = param_2 - param_3;
    uVar9 = param_3 >> 0x10;
    uVar3 = param_3 & 0xffff;
  }
  else {
    param_3 = param_3 << (uVar2 & 0x3f);
    uVar6 = param_2 >> (uVar1 & 0x3f);
    uVar9 = param_3 >> 0x10;
    uVar8 = uVar6 / uVar9;
    uVar5 = param_2 << (uVar2 & 0x3f) | param_1 >> (uVar1 & 0x3f);
    uVar3 = param_3 & 0xffff;
    uVar1 = (uVar6 - uVar8 * uVar9) * 0x10000 | uVar5 >> 0x10;
    uVar8 = uVar8 * uVar3;
    param_1 = param_1 << (uVar2 & 0x3f);
    if (((uVar1 < uVar8) && (uVar1 = uVar1 + param_3, param_3 <= uVar1)) && (uVar1 < uVar8)) {
      uVar1 = uVar1 + param_3;
    }
    uVar2 = (uVar1 - uVar8) / uVar9;
    uVar6 = uVar2 * uVar3;
    param_2 = ((uVar1 - uVar8) - uVar2 * uVar9) * 0x10000 | uVar5 & 0xffff;
    if (((param_2 < uVar6) && (param_2 = param_2 + param_3, param_3 <= param_2)) &&
       (param_2 < uVar6)) {
      param_2 = param_2 + param_3;
    }
    param_2 = param_2 - uVar6;
  }
  uVar8 = param_2 / uVar9;
  uVar2 = uVar8 * uVar3;
  uVar6 = (param_2 - uVar8 * uVar9) * 0x10000 | param_1 >> 0x10;
  uVar1 = uVar8;
  if (uVar6 < uVar2) {
    uVar6 = uVar6 + param_3;
    uVar1 = uVar8 - 1;
    if ((param_3 <= uVar6) && (uVar6 < uVar2)) {
      uVar1 = uVar8 - 2;
      uVar6 = uVar6 + param_3;
    }
  }
  uVar8 = (uVar6 - uVar2) / uVar9;
  uVar6 = param_1 & 0xffff | ((uVar6 - uVar2) - uVar8 * uVar9) * 0x10000;
  uVar2 = uVar8;
  if (uVar6 < uVar8 * uVar3) {
    uVar6 = uVar6 + param_3;
    uVar2 = uVar8 - 1;
    if ((param_3 <= uVar6) && (uVar6 < uVar8 * uVar3)) {
      uVar2 = uVar8 - 2;
    }
  }
  return uVar1 << 0x10 | uVar2;
}


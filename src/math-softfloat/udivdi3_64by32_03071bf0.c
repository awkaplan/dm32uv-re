/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: udivdi3_64by32 @ 03071bf0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 960 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint udivdi3_64by32(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iStack_34;
  
  if (param_4 != 0) {
    if (param_2 < param_4) {
      return param_1;
    }
    if (param_4 < 0x10000) {
      if (param_4 < 0x100) {
        iVar7 = 0;
      }
      else {
        iVar7 = 8;
      }
    }
    else if (param_4 < 0x1000000) {
      iVar7 = 0x10;
    }
    else {
      iVar7 = 0x18;
    }
    uVar5 = (uint)(byte)PTR_DAT_03071da0[param_4 >> iVar7] + iVar7;
    uVar8 = 0x20 - uVar5;
    if (uVar8 == 0) {
      if ((param_4 < param_2) || (param_3 <= param_1)) {
        param_1 = param_1 - param_3;
      }
      return param_1;
    }
    uVar1 = param_4 << (uVar8 & 0x3f) | param_3 >> (uVar5 & 0x3f);
    uVar3 = param_2 >> (uVar5 & 0x3f);
    uVar2 = uVar1 >> 0x10;
    uVar4 = uVar3 / uVar2;
    uVar6 = param_2 << (uVar8 & 0x3f) | param_1 >> (uVar5 & 0x3f);
    uVar11 = uVar4 * (uVar1 & 0xffff);
    uVar9 = (uVar3 - uVar4 * uVar2) * 0x10000 | uVar6 >> 0x10;
    param_3 = param_3 << (uVar8 & 0x3f);
    param_1 = param_1 << (uVar8 & 0x3f);
    uVar3 = uVar4;
    if (uVar9 < uVar11) {
      uVar9 = uVar9 + uVar1;
      uVar3 = uVar4 - 1;
      if ((uVar1 <= uVar9) && (uVar9 < uVar11)) {
        uVar3 = uVar4 - 2;
        uVar9 = uVar9 + uVar1;
      }
    }
    uVar10 = (uVar9 - uVar11) / uVar2;
    uVar4 = uVar10 * (uVar1 & 0xffff);
    uVar2 = ((uVar9 - uVar11) - uVar10 * uVar2) * 0x10000 | uVar6 & 0xffff;
    uVar6 = uVar10;
    if (uVar2 < uVar4) {
      uVar2 = uVar2 + uVar1;
      uVar6 = uVar10 - 1;
      if ((uVar1 <= uVar2) && (uVar2 < uVar4)) {
        uVar6 = uVar10 - 2;
        uVar2 = uVar2 + uVar1;
      }
    }
    uVar3 = (uVar6 | uVar3 << 0x10) >> 0x10;
    uVar9 = (uVar6 & 0xffff) * (param_3 & 0xffff);
    uVar11 = uVar3 * (param_3 & 0xffff);
    uVar6 = (param_3 >> 0x10) * (uVar6 & 0xffff) + uVar11 + (uVar9 >> 0x10);
    uVar2 = uVar2 - uVar4;
    iVar7 = uVar3 * (param_3 >> 0x10);
    if (uVar6 < uVar11) {
      iVar7 = iVar7 + 0x10000;
    }
    iStack_34 = 0;
    uVar4 = iVar7 + (uVar6 >> 0x10);
    uVar3 = (uVar9 & 0xffff) + uVar6 * 0x10000;
    if (uVar4 <= uVar2) {
      if (uVar2 != uVar4) {
        iStack_34 = uVar2 - uVar4;
        goto LAB_03071ec0;
      }
      if (uVar3 <= param_1) goto LAB_03071ec0;
    }
    iStack_34 = uVar2 - ((uVar4 - uVar1) - (uint)(byte)~(uVar3 - param_3 <= uVar3));
    uVar3 = uVar3 - param_3;
LAB_03071ec0:
    return param_1 - uVar3 >> (uVar8 & 0x3f) |
           iStack_34 - (uint)(byte)~(param_1 - uVar3 <= param_1) << (uVar5 & 0x3f);
  }
  if (param_2 < param_3) {
    if (param_3 < 0x10000) {
      iVar7 = 0;
      if (0xff < param_3) {
        iVar7 = 8;
      }
    }
    else if (param_3 < 0x1000000) {
      iVar7 = 0x10;
    }
    else {
      iVar7 = 0x18;
    }
    uVar5 = param_3 >> iVar7;
    uVar8 = 0x20 - ((uint)(byte)PTR_DAT_03071da0[uVar5] + iVar7);
    if (uVar8 != 0) {
      param_3 = param_3 << (uVar8 & 0x3f);
      param_2 = param_2 << (uVar8 & 0x3f) |
                param_1 >> ((uint)(byte)PTR_DAT_03071da0[uVar5] + iVar7 & 0x3f);
      param_1 = param_1 << (uVar8 & 0x3f);
    }
    uVar3 = param_3 >> 0x10;
    uVar6 = (param_3 & 0xffff) * (param_2 / uVar3);
    uVar5 = (param_2 - (param_2 / uVar3) * uVar3) * 0x10000 | param_1 >> 0x10;
    if (((uVar5 < uVar6) && (uVar5 = uVar5 + param_3, param_3 <= uVar5)) && (uVar5 < uVar6)) {
      uVar5 = uVar5 + param_3;
    }
    uVar2 = (uVar5 - uVar6) / uVar3;
    uVar1 = uVar2 * (param_3 & 0xffff);
    uVar5 = param_1 & 0xffff | ((uVar5 - uVar6) - uVar2 * uVar3) * 0x10000;
    if (((uVar5 < uVar1) && (uVar5 = uVar5 + param_3, param_3 <= uVar5)) && (uVar5 < uVar1)) {
      uVar5 = param_3 + uVar5;
    }
    return uVar5 - uVar1 >> (uVar8 & 0x3f);
  }
  if (param_3 == 0) {
    param_3 = 1 / 0;
  }
  else {
    if (0xffff < param_3) {
      if (param_3 < 0x1000000) {
        iVar7 = 0x10;
      }
      else {
        iVar7 = 0x18;
      }
      goto LAB_03071d14;
    }
    if (0xff < param_3) {
      iVar7 = 8;
      goto LAB_03071d14;
    }
  }
  iVar7 = 0;
LAB_03071d14:
  uVar5 = (uint)(byte)PTR_DAT_03071da0[param_3 >> iVar7] + iVar7;
  uVar8 = 0x20 - uVar5;
  if (uVar8 == 0) {
    param_2 = param_2 - param_3;
    uVar9 = param_3 >> 0x10;
    uVar3 = param_3 & 0xffff;
  }
  else {
    param_3 = param_3 << (uVar8 & 0x3f);
    uVar2 = param_2 >> (uVar5 & 0x3f);
    uVar9 = param_3 >> 0x10;
    uVar1 = uVar2 / uVar9;
    uVar6 = param_2 << (uVar8 & 0x3f) | param_1 >> (uVar5 & 0x3f);
    uVar3 = param_3 & 0xffff;
    uVar5 = (uVar2 - uVar1 * uVar9) * 0x10000 | uVar6 >> 0x10;
    uVar1 = uVar3 * uVar1;
    param_1 = param_1 << (uVar8 & 0x3f);
    if (((uVar5 < uVar1) && (uVar5 = uVar5 + param_3, param_3 <= uVar5)) && (uVar5 < uVar1)) {
      uVar5 = uVar5 + param_3;
    }
    uVar4 = (uVar5 - uVar1) / uVar9;
    uVar2 = uVar4 * uVar3;
    param_2 = uVar6 & 0xffff | ((uVar5 - uVar1) - uVar4 * uVar9) * 0x10000;
    if (((param_2 < uVar2) && (param_2 = param_2 + param_3, param_3 <= param_2)) &&
       (param_2 < uVar2)) {
      param_2 = param_2 + param_3;
    }
    param_2 = param_2 - uVar2;
  }
  uVar6 = uVar3 * (param_2 / uVar9);
  uVar5 = (param_2 - (param_2 / uVar9) * uVar9) * 0x10000 | param_1 >> 0x10;
  if (((uVar5 < uVar6) && (uVar5 = uVar5 + param_3, param_3 <= uVar5)) && (uVar5 < uVar6)) {
    uVar5 = uVar5 + param_3;
  }
  uVar1 = (uVar5 - uVar6) / uVar9;
  uVar3 = uVar3 * uVar1;
  uVar5 = param_1 & 0xffff | ((uVar5 - uVar6) - uVar1 * uVar9) * 0x10000;
  if (((uVar5 < uVar3) && (uVar5 = uVar5 + param_3, param_3 <= uVar5)) && (uVar5 < uVar3)) {
    uVar5 = param_3 + uVar5;
  }
  return uVar5 - uVar3 >> (uVar8 & 0x3f);
}


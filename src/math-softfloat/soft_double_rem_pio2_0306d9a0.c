/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_rem_pio2 @ 0306d9a0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 880 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int soft_double_rem_pio2(uint param_1,uint param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  
  uVar10 = param_2 & 0x7fffffff;
  if ((int)uVar10 <= DAT_0306db90) {
    *param_3 = param_1;
    param_3[1] = param_2;
    param_3[2] = 0;
    param_3[3] = 0;
    return 0;
  }
  if (DAT_0306db94 < (int)uVar10) {
    if (DAT_0306dba4 < (int)uVar10) {
      if (0x468fffff < uVar10) {
        uVar10 = ((uVar10 >> 0x14) - 0x469) / 0x36;
        param_1 = soft_double_multiply
                            (param_1,param_2,PTR_DAT_0306dba8[uVar10 * 2],
                             PTR_DAT_0306dba8[uVar10 * 2 + 1]);
      }
      uVar11 = param_1 & 0xfc000000;
      uVar10 = param_2;
      uVar9 = soft_double_sub(param_1,param_2,uVar11,param_2);
      puVar1 = PTR_DAT_0306dbb0;
      uVar4 = param_2;
      puVar13 = PTR_DAT_0306dbac;
      uVar2 = soft_double_multiply(uVar11,param_2,*PTR_DAT_0306dbac,PTR_DAT_0306dbac[1]);
      uVar7 = uVar10;
      uVar3 = soft_double_multiply(uVar9,uVar10,*puVar1,puVar1[1]);
      uVar2 = soft_double_add(uVar2,uVar4,uVar3,uVar7);
      soft_double_multiply(uVar11,param_2,*puVar1,puVar1[1]);
      uVar3 = soft_double_add();
      uVar7 = param_2;
      uVar6 = soft_double_sub();
      uVar2 = soft_double_sub(uVar2,uVar4,uVar6,uVar7);
      soft_double_modulo_or_remainder(uVar3,param_2,DAT_0306dbb4,DAT_0306dbb8);
      soft_double_divide();
      soft_double_multiply();
      soft_double_add();
      iVar12 = softdouble_to_int32();
      uVar3 = soft_double_modulo_or_remainder(uVar3,param_2,DAT_0306dbb4,DAT_0306dbc8);
      uVar9 = soft_double_multiply(uVar9,uVar10,*puVar13,puVar13[1]);
      uVar9 = soft_double_add(uVar2,uVar4,uVar9,uVar10);
      soft_double_add(uVar3,param_2,uVar9,uVar4);
      soft_double_modulo_or_remainder();
      uVar10 = soft_double_divide();
      *param_3 = uVar10;
      param_3[1] = param_2;
      return iVar12 / 2;
    }
    uVar4 = param_2;
    uVar9 = noop_stub_0306d5a8();
    uVar7 = uVar4;
    soft_double_multiply();
    soft_double_add();
    iVar12 = softdouble_to_int32();
    uVar2 = soft_double_from_int();
    uVar11 = uVar7;
    uVar3 = soft_double_multiply();
    uVar9 = soft_double_sub(uVar9,uVar4,uVar3,uVar11);
    uVar11 = uVar7;
    uVar3 = soft_double_multiply(uVar2,uVar7,*PTR_DAT_0306dd5c,PTR_DAT_0306dd5c[1]);
    uVar8 = uVar4;
    uVar5 = soft_double_sub(uVar9,uVar4,uVar3,uVar11);
    uVar11 = uVar4;
    if (0x10 < (int)(((int)uVar10 >> 0x14) - (uVar8 >> 0x14 & 0x7ff))) {
      uVar10 = uVar7;
      uVar3 = soft_double_multiply(uVar2,uVar7,*PTR_DAT_0306dd60,PTR_DAT_0306dd60[1]);
      uVar3 = soft_double_sub(uVar9,uVar4,uVar3,uVar10);
      uVar10 = uVar7;
      uVar9 = soft_double_multiply(uVar2,uVar7,*PTR_DAT_0306dd68,PTR_DAT_0306dd68[1]);
      uVar11 = uVar4;
      uVar9 = soft_double_sub(uVar3,uVar4,uVar9,uVar10);
      soft_double_sub(uVar3,uVar4,uVar9,uVar11);
      soft_double_sub();
      soft_double_multiply(uVar2,uVar7,*PTR_DAT_0306dd6c,PTR_DAT_0306dd6c[1],uVar10);
      uVar2 = soft_double_sub();
      uVar8 = uVar11;
      uVar5 = soft_double_sub(uVar9,uVar11,uVar2,uVar7);
    }
    *param_3 = uVar5;
    param_3[1] = uVar8;
    soft_double_sub(uVar9);
    uVar10 = soft_double_sub();
    param_3[2] = uVar10;
    param_3[3] = uVar11;
    if ((int)param_2 < 0) {
      param_3[1] = param_3[1] + 0x80000000;
      param_3[3] = uVar11 + 0x80000000;
      iVar12 = -iVar12;
    }
  }
  else {
    uVar4 = DAT_0306db9c;
    if (0 < (int)param_2) {
      uVar4 = DAT_0306db98;
    }
    uVar9 = 0x3ff00000;
    if ((int)param_2 < 1) {
      iVar12 = -1;
      uVar9 = 0xbff00000;
    }
    else {
      iVar12 = 1;
    }
    uVar2 = soft_double_sub(param_1,param_2,0x54400000,uVar4);
    if (uVar10 == DAT_0306db98) {
      uVar3 = uVar9;
      uVar6 = soft_double_multiply(0,uVar9,*PTR_DAT_0306dd60,PTR_DAT_0306dd60[1]);
      uVar2 = soft_double_sub(uVar2,param_2,uVar6,uVar3);
      uVar3 = soft_double_multiply(0,uVar9,*PTR_DAT_0306dd64,PTR_DAT_0306dd64[1]);
    }
    else {
      uVar3 = soft_double_multiply(0,uVar9,*PTR_DAT_0306dba0,PTR_DAT_0306dba0[1]);
    }
    uVar10 = param_2;
    uVar4 = soft_double_sub(uVar2,param_2,uVar3,uVar9);
    *param_3 = uVar4;
    param_3[1] = uVar10;
    soft_double_sub(uVar2,param_2,uVar4,uVar10);
    uVar10 = soft_double_sub();
    param_3[2] = uVar10;
    param_3[3] = param_2;
  }
  return iVar12;
}


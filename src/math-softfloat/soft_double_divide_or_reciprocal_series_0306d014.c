/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_divide_or_reciprocal_series @ 0306d014 (file base 0x03000000; code starts at 0x03001000)
 * Size: 954 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int soft_double_divide_or_reciprocal_series(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  
  uVar13 = param_2 & 0x7fffffff;
  if (0x3fefffff < uVar13) {
    if (uVar13 != 0x3ff00000 || param_1 != 0) {
      soft_double_sub(param_1,param_2,param_1,param_2);
      iVar1 = soft_double_divide();
      return iVar1;
    }
    uVar13 = param_2;
    uVar6 = soft_double_multiply(param_1,param_2,*PTR_DAT_0306d410,PTR_DAT_0306d410[1]);
    uVar7 = soft_double_multiply(param_1,param_2,*PTR_DAT_0306d414,PTR_DAT_0306d414[1]);
    iVar1 = soft_double_add(uVar6,uVar13,uVar7,param_2);
    return iVar1;
  }
  puVar14 = PTR_DAT_0306d418;
  if (uVar13 < 0x3fe00000) {
    if (0x3e3fffff < uVar13) {
      uVar13 = param_2;
      uVar6 = soft_double_multiply(param_1,param_2,param_1,param_2);
      uVar12 = uVar13;
      soft_double_multiply();
      soft_double_add();
      soft_double_multiply();
      soft_double_sub();
      soft_double_multiply();
      soft_double_add();
      soft_double_multiply();
      soft_double_sub();
      soft_double_multiply();
      soft_double_add();
      uVar7 = soft_double_multiply();
      soft_double_multiply(uVar6,uVar13,*PTR_DAT_0306d438,PTR_DAT_0306d438[1]);
      soft_double_sub();
      soft_double_multiply();
      soft_double_add();
      soft_double_multiply();
      soft_double_sub();
      soft_double_multiply();
      uVar6 = soft_double_add();
      uVar6 = soft_double_divide(uVar7,uVar12,uVar6,uVar13);
      uVar13 = param_2;
      uVar6 = soft_double_multiply(param_1,param_2,uVar6,uVar12);
      iVar1 = soft_double_add(param_1,param_2,uVar6,uVar13);
      return iVar1;
    }
    soft_double_add(param_1,param_2,*PTR_DAT_0306d1d4,PTR_DAT_0306d1d4[1]);
    puVar14 = PTR_DAT_0306d1d8;
    iVar1 = softdouble_compare_le();
    if (0 < iVar1) {
      return param_1;
    }
  }
  uVar12 = param_2;
  uVar6 = noop_stub_0306d5a8(param_1,param_2);
  uVar9 = puVar14[1];
  soft_double_sub(*puVar14,uVar9,uVar6,uVar12);
  uVar2 = soft_double_multiply();
  uVar6 = uVar9;
  soft_double_multiply();
  soft_double_add();
  soft_double_multiply();
  soft_double_sub();
  soft_double_multiply();
  soft_double_add();
  soft_double_multiply();
  soft_double_sub();
  soft_double_multiply();
  soft_double_add();
  uVar3 = soft_double_multiply();
  uVar7 = uVar9;
  soft_double_multiply(uVar2,uVar9,*PTR_DAT_0306d1f8,PTR_DAT_0306d1f8[1]);
  soft_double_sub();
  soft_double_multiply();
  soft_double_add();
  soft_double_multiply();
  soft_double_sub();
  soft_double_multiply();
  uVar4 = soft_double_add();
  uVar10 = uVar9;
  uVar5 = soft_double_x_plus_x_squared(uVar2);
  if (DAT_0306d208 < (int)uVar13) {
    uVar7 = soft_double_divide(uVar3,uVar6,uVar4,uVar7);
    soft_double_multiply(uVar5,uVar10,uVar7,uVar6);
    soft_double_add();
    soft_double_add();
    uVar6 = soft_double_sub();
    iVar1 = soft_double_sub(*PTR_DAT_0306d210,PTR_DAT_0306d210[1],uVar6,uVar10);
  }
  else {
    uVar11 = uVar10;
    uVar8 = soft_double_add();
    uVar7 = soft_double_divide(uVar3,uVar6,uVar4,uVar7);
    uVar7 = soft_double_multiply(uVar8,uVar11,uVar7,uVar6);
    uVar6 = uVar10;
    uVar3 = soft_double_multiply(0,uVar10,0,uVar10);
    uVar2 = soft_double_sub(uVar2,uVar9,uVar3,uVar6);
    uVar6 = uVar10;
    uVar3 = soft_double_add(uVar5,uVar10,0,uVar10);
    soft_double_divide(uVar2,uVar9,uVar3,uVar6);
    uVar6 = soft_double_add();
    uVar2 = PTR_DAT_0306d414[1];
    uVar6 = soft_double_sub(*PTR_DAT_0306d414,uVar2,uVar6,uVar9);
    uVar6 = soft_double_sub(uVar7,uVar11,uVar6,uVar2);
    uVar7 = soft_double_add(0,uVar10,0,uVar10);
    puVar14 = PTR_DAT_0306d41c;
    uVar2 = PTR_DAT_0306d41c[1];
    uVar7 = soft_double_sub(*PTR_DAT_0306d41c,uVar2,uVar7,uVar10);
    uVar6 = soft_double_sub(uVar6,uVar11,uVar7,uVar2);
    iVar1 = soft_double_sub(*puVar14,puVar14[1],uVar6,uVar11);
  }
  if (0 < (int)param_2) {
    return iVar1;
  }
  return iVar1;
}


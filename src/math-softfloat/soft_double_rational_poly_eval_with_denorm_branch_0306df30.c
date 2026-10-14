/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_rational_poly_eval_with_denorm_branch @ 0306df30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 362 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void soft_double_rational_poly_eval_with_denorm_branch
               (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = param_2 & 0x7fffffff;
  if ((uVar8 < 0x3e400000) && (iVar1 = softdouble_to_int32(), iVar1 == 0)) {
    return;
  }
  uVar5 = param_2;
  uVar2 = soft_double_multiply(param_1,param_2,param_1,param_2);
  uVar6 = uVar5;
  soft_double_multiply();
  uVar3 = soft_double_add();
  uVar7 = uVar5;
  soft_double_multiply(uVar2,uVar5,uVar3,uVar6);
  uVar3 = soft_double_sub();
  uVar6 = uVar5;
  soft_double_multiply(uVar2,uVar5,uVar3,uVar7);
  uVar3 = soft_double_add();
  uVar7 = uVar5;
  soft_double_multiply(uVar2,uVar5,uVar3,uVar6);
  uVar3 = soft_double_sub();
  uVar6 = uVar5;
  soft_double_multiply(uVar2,uVar5,uVar3,uVar7);
  uVar3 = soft_double_add();
  uVar7 = uVar5;
  uVar3 = soft_double_multiply(uVar2,uVar5,uVar3,uVar6);
  uVar6 = uVar5;
  uVar3 = soft_double_multiply(uVar2,uVar5,uVar3,uVar7);
  uVar4 = soft_double_multiply(param_1,param_2,param_3,param_4);
  soft_double_sub(uVar3,uVar6,uVar4,param_2);
  soft_double_multiply(uVar2,uVar5,*PTR_DAT_0306e0b4,PTR_DAT_0306e0b4[1]);
  uVar2 = soft_double_sub();
  if (DAT_0306e0b8 < (int)uVar8) {
    if (uVar8 < 0x3fe90001) {
      iVar1 = uVar8 - 0x200000;
      uVar4 = PTR_DAT_0306e0bc[1];
      uVar3 = soft_double_sub(*PTR_DAT_0306e0bc,uVar4,0,iVar1);
    }
    else {
      uVar3 = 0;
      uVar4 = 0x3fe70000;
      iVar1 = 0x3fd20000;
    }
    uVar2 = soft_double_sub(uVar2,uVar5,0,iVar1);
    soft_double_sub(uVar3,uVar4,uVar2,uVar5);
    return;
  }
  soft_double_sub(*PTR_DAT_0306e0bc,PTR_DAT_0306e0bc[1],uVar2,uVar5);
  return;
}


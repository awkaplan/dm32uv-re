/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: softdouble_piecewise_poly_eval @ 0306ddb0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 356 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
softdouble_piecewise_poly_eval
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if ((0x3e3fffff < (param_2 & 0x7fffffff)) || (iVar1 = softdouble_to_int32(), iVar1 != 0)) {
    uVar5 = param_2;
    uVar2 = soft_double_multiply(param_1,param_2,param_1,param_2);
    uVar6 = uVar5;
    uVar3 = soft_double_multiply();
    uVar7 = uVar5;
    soft_double_multiply(uVar2,uVar5,*PTR_DAT_0306df14,PTR_DAT_0306df14[1]);
    uVar4 = soft_double_sub();
    uVar8 = uVar5;
    soft_double_multiply(uVar2,uVar5,uVar4,uVar7);
    uVar4 = soft_double_add();
    uVar7 = uVar5;
    soft_double_multiply(uVar2,uVar5,uVar4,uVar8);
    uVar4 = soft_double_sub();
    uVar8 = uVar5;
    soft_double_multiply(uVar2,uVar5,uVar4,uVar7);
    uVar4 = soft_double_add();
    if (param_5 == 0) {
      soft_double_multiply(uVar2,uVar5,uVar4,uVar8);
      soft_double_sub();
      uVar2 = soft_double_multiply();
      uVar2 = soft_double_add(param_1,param_2,uVar2,uVar5);
      return uVar2;
    }
    uVar2 = soft_double_multiply(param_3,param_4,*PTR_DAT_0306df28,PTR_DAT_0306df28[1]);
    uVar5 = uVar6;
    uVar4 = soft_double_multiply(uVar3,uVar6,uVar4,uVar8);
    soft_double_sub(uVar2,param_4,uVar4,uVar5);
    soft_double_multiply();
    uVar2 = soft_double_sub();
    uVar3 = soft_double_multiply(uVar3,uVar6,*PTR_DAT_0306df2c,PTR_DAT_0306df2c[1]);
    uVar2 = soft_double_add(uVar2,param_4,uVar3,uVar6);
    param_1 = soft_double_sub(param_1,param_2,uVar2,param_4);
  }
  return param_1;
}


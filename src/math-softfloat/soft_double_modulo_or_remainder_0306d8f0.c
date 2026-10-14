/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_modulo_or_remainder @ 0306d8f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
soft_double_modulo_or_remainder
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar1 = softdouble_divide_guarded();
  iVar2 = softdouble_compare_le();
  if (0 < iVar2) {
    soft_double_multiply(param_3,param_4,*PTR_DAT_0306d99c,PTR_DAT_0306d99c[1]);
    iVar2 = soft_double_compare_packed();
    if (iVar2 < 0) {
      uVar1 = soft_double_sub(uVar1,param_2,param_3,param_4);
      iVar2 = soft_double_compare_packed(uVar1,param_2,0,0);
      goto joined_r0x0306d956;
    }
  }
  iVar2 = soft_double_compare_packed(uVar1,param_2,0,0);
joined_r0x0306d956:
  if (iVar2 < 0) {
    uVar5 = param_2;
    uVar3 = noop_stub_0306d5a8(uVar1,param_2);
    uVar6 = param_4;
    uVar4 = soft_double_multiply(param_3,param_4,*PTR_DAT_0306d99c,PTR_DAT_0306d99c[1]);
    iVar2 = softdouble_compare_le(uVar3,uVar5,uVar4,uVar6);
    if (0 < iVar2) {
      uVar1 = soft_double_add(uVar1,param_2,param_3,param_4);
      return uVar1;
    }
  }
  return uVar1;
}


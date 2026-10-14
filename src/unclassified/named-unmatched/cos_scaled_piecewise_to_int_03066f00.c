/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cos_scaled_piecewise_to_int @ 03066f00 (file base 0x03000000; code starts at 0x03001000)
 * Size: 118 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined1 cos_scaled_piecewise_to_int(int param_1__w,undefined4 param_2)

{
  undefined2 param_1 = (undefined2)param_1__w;
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  soft_double_pack_constant_two(param_1);
  soft_double_divide();
  soft_double_multiply();
  soft_double_multiply();
  soft_double_multiply();
  soft_double_cos();
  uVar2 = soft_double_multiply();
  iVar3 = softdouble_compare_le();
  if (iVar3 < 1) {
    soft_double_add(uVar2,param_2,*(undefined4 *)PTR_LAB_03066f94,
                    *(undefined4 *)(PTR_LAB_03066f94 + 4));
  }
  else {
    soft_double_add(uVar2,param_2,*(undefined4 *)PTR_LAB_03066f90,
                    *(undefined4 *)(PTR_LAB_03066f90 + 4));
  }
  uVar1 = soft_double_to_int();
  return uVar1;
}


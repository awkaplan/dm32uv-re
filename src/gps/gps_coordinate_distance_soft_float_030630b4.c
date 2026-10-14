/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_coordinate_distance_soft_float @ 030630b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 222 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_coordinate_distance_soft_float
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar1 = soft_double_multiply_then_soft_double_divide();
  uVar2 = soft_double_multiply_then_soft_double_divide(param_5,param_6);
  uVar3 = soft_double_multiply_then_soft_double_divide(param_3,param_4);
  uVar4 = soft_double_multiply_then_soft_double_divide(param_7);
  uVar6 = param_2;
  soft_double_sub(uVar1,param_2,uVar2,param_6);
  soft_double_multiply();
  soft_double_sin();
  uVar5 = soft_double_multiply();
  uVar1 = soft_double_cos(uVar1);
  uVar2 = soft_double_cos(uVar2,param_6);
  soft_double_sub(uVar3,param_4,uVar4,param_8);
  soft_double_multiply();
  soft_double_sin();
  soft_double_multiply();
  soft_double_multiply(uVar1,param_2,uVar2,param_6);
  uVar1 = soft_double_multiply();
  soft_double_add(uVar5,uVar6,uVar1,param_2);
  soft_double_x_plus_x_squared();
  soft_double_divide_or_reciprocal_series();
  soft_double_add();
  soft_double_multiply();
  return;
}


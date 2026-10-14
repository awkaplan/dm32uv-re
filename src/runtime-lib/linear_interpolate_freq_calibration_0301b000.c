/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: linear_interpolate_freq_calibration @ 0301b000 (file base 0x03000000; code starts at 0x03001000)
 * Size: 118 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int linear_interpolate_freq_calibration
              (int param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  float a;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  
  soft_double_pack_constant_two(param_4 - param_2);
  soft_double_divide();
  uVar1 = softdouble_extract_exponent_mantissa();
  soft_double_pack_constant_two(param_1 - param_2);
  soft_double_divide();
  a = (float)softdouble_extract_exponent_mantissa();
  if (param_3 < param_5) {
    uVar2 = float32_pack_const_two(param_5 - param_3);
    fVar3 = (float)decimal_string_pair_to_fixed(uVar2,uVar1);
    softfloat32_mul(a,fVar3);
    iVar4 = mutex_guarded_call_wrapper();
  }
  else {
    uVar2 = float32_pack_const_two(param_3 - param_5);
    fVar3 = (float)decimal_string_pair_to_fixed(uVar2,uVar1);
    softfloat32_mul(a,fVar3);
    iVar4 = mutex_guarded_call_wrapper();
    iVar4 = -iVar4;
  }
  return iVar4 + param_3;
}


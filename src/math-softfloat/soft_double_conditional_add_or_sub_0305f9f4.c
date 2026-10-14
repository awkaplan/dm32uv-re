/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_conditional_add_or_sub @ 0305f9f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void soft_double_conditional_add_or_sub(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = softdouble_compare_le(param_1,param_2,*PTR_DAT_0305fa30,PTR_DAT_0305fa30[1]);
  if (iVar1 < 1) {
    soft_double_sub(param_1,param_2,*PTR_DAT_0305fa34,PTR_DAT_0305fa34[1]);
    soft_double_to_int_round_trunc_variant();
  }
  else {
    soft_double_add(param_1,param_2,*PTR_DAT_0305fa34,PTR_DAT_0305fa34[1]);
    soft_double_to_int_round_ceil_variant();
  }
  return;
}


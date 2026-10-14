/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_multiply_then_soft_double_divide @ 03063094 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void soft_double_multiply_then_soft_double_divide(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = soft_double_multiply(param_1,param_2,*PTR_LAB_030630ac,PTR_LAB_030630ac[1]);
  soft_double_divide(uVar1,param_2,*PTR_LAB_030630b0,PTR_LAB_030630b0[1]);
  return;
}


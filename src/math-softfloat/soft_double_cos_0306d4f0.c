/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_cos @ 0306d4f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 180 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void soft_double_cos(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  local_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  if (DAT_0306d5a4 < (int)(param_2 & 0x7fffffff)) {
    if ((param_2 & 0x7fffffff) < 0x7ff00000) {
      uVar1 = soft_double_rem_pio2(param_1,param_2,&local_1c,param_2);
      uVar1 = uVar1 & 3;
      if (uVar1 == 1) {
        softdouble_piecewise_poly_eval(local_1c,uStack_18,uStack_14,uStack_10,1);
      }
      else if (uVar1 == 2) {
        soft_double_rational_poly_eval_with_denorm_branch(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else if (uVar1 == 0) {
        soft_double_rational_poly_eval_with_denorm_branch(local_1c,uStack_18,uStack_14,uStack_10);
      }
      else {
        softdouble_piecewise_poly_eval(local_1c,uStack_18,uStack_14,uStack_10,1);
      }
    }
    else {
      soft_double_sub(param_1,param_2,param_1);
    }
    return;
  }
  soft_double_rational_poly_eval_with_denorm_branch(param_1,param_2,0,0);
  return;
}


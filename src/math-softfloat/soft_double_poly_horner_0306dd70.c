/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_poly_horner @ 0306dd70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: math-softfloat
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void soft_double_poly_horner(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined4 *)(param_1 + param_2 * 8);
  uVar1 = *puVar2;
  if (param_2 != 0) {
    param_2 = param_2 + -1;
    uVar3 = puVar2[1];
    do {
      uVar4 = param_4;
      soft_double_multiply(param_3,param_4,uVar1,uVar3);
      uVar1 = soft_double_add();
      param_2 = param_2 + -1;
      uVar3 = uVar4;
    } while (param_2 != -1);
  }
  return;
}


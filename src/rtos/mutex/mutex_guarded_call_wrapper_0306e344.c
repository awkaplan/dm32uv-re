/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: mutex_guarded_call_wrapper @ 0306e344 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int mutex_guarded_call_wrapper(double param_1__w)

{
  float param_1 = (float)param_1__w;
  int iVar1;
  
  iVar1 = softfloat32_compare(param_1,0x4f000000);
  if (iVar1 < 0) {
    iVar1 = atoi_clamped(param_1);
    return iVar1;
  }
  softfloat32_sub(param_1,2.1474836e+09);
  iVar1 = atoi_clamped();
  return iVar1 + -0x80000000;
}


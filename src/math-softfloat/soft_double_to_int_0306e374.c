/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_to_int @ 0306e374 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int soft_double_to_int(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_0306e3ac;
  iVar2 = softdouble_compare_ne(param_1,param_2,*PTR_DAT_0306e3ac,PTR_DAT_0306e3ac[1]);
  if (iVar2 < 0) {
    iVar2 = softdouble_to_int32(param_1,param_2);
    return iVar2;
  }
  soft_double_sub(param_1,param_2,*puVar1,puVar1[1]);
  iVar2 = softdouble_to_int32();
  return iVar2 + -0x80000000;
}


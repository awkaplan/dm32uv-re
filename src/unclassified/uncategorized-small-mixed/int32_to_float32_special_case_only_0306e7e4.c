/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: int32_to_float32_special_case_only @ 0306e7e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 int32_to_float32_special_case_only(int param_1)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  int iStack_10;
  
  iStack_10 = -(param_1 >> 0x1f);
  if (param_1 == 0) {
    uStack_14 = 2;
    uVar1 = float32_pack_round(&uStack_14,3,2,&uStack_14);
  }
  else {
    if ((iStack_10 == 0) || (param_1 != -0x80000000)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = 0xcf000000;
  }
  return uVar1;
}


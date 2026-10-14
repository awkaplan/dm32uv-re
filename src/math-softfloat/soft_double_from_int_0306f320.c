/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: soft_double_from_int @ 0306f320 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: math-softfloat
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 soft_double_from_int(int param_1)

{
  undefined4 uVar1;
  undefined4 uStack_1c;
  int iStack_18;
  
  iStack_18 = -(param_1 >> 0x1f);
  if (param_1 == 0) {
    uStack_1c = 2;
    uVar1 = soft_double_pack_and_round(&uStack_1c,3,2,&uStack_1c);
  }
  else {
    if ((iStack_18 == 0) || (param_1 != -0x80000000)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = 0;
  }
  return uVar1;
}


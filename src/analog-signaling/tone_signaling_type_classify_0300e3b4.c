/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_signaling_type_classify @ 0300e3b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined2 tone_signaling_type_classify(ushort param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  
  uVar2 = param_1 & 0xf000;
  if (((short)uVar2 < 0) || (param_1 == 0)) {
    if (uVar2 == 0x8000) {
      uVar1 = 2;
    }
    else if (uVar2 == 0xc000) {
      uVar1 = 3;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


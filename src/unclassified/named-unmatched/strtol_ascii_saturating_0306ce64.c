/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: strtol_ascii_saturating @ 0306ce64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint strtol_ascii_saturating(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  uint uVar1;
  char cStack_9;
  
  uVar1 = strtoul_ascii_to_uint_radix(param_1,param_2,param_3,1,&cStack_9);
  if (cStack_9 == '\0') {
    if ((uVar1 & 0x80000000) != 0) {
      uVar1 = 0x7fffffff;
    }
  }
  else if ((int)uVar1 < 0) {
    uVar1 = 0x80000000;
  }
  else {
    uVar1 = -uVar1;
  }
  return uVar1;
}


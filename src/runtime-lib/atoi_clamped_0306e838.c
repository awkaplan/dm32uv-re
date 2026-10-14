/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: atoi_clamped @ 0306e838 (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: runtime-lib
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint atoi_clamped(undefined4 param_1)

{
  uint uVar1;
  uint local_1c;
  int iStack_18;
  int iStack_14;
  uint uStack_10;
  undefined4 local_c;
  
  local_c = param_1;
  float32_unpack(&local_c,&local_1c);
  if ((local_1c == 2) || (local_1c < 2)) {
    return 0;
  }
  if (local_1c != 4) {
    if (iStack_14 < 0) {
      return 0;
    }
    if (iStack_14 < 0x1f) {
      uStack_10 = uStack_10 >> (0x1eU - iStack_14 & 0x3f);
      if (iStack_18 == 0) {
        return uStack_10;
      }
      return -uStack_10;
    }
  }
  uVar1 = 0x80000000;
  if (iStack_18 == 0) {
    uVar1 = 0x7fffffff;
  }
  return uVar1;
}


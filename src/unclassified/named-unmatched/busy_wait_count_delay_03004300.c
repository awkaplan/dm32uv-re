/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: busy_wait_count_delay @ 03004300 (file base 0x03000000; code starts at 0x03001000)
 * Size: 198 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void busy_wait_count_delay(uint param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = 0;
    do {
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_1);
  }
  return;
}


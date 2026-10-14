/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: input_state_arm_if_not_busy @ 030394a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void input_state_arm_if_not_busy(void)

{
  if ((*(byte *)PTR_DAT_030394ec & 2) == 0) {
    *(undefined1 *)PTR_DAT_030394f0 = 1;
    *(undefined1 *)PTR_DAT_030394f4 = 0;
    *(undefined1 *)PTR_DAT_030394f8 = 0;
  }
  return;
}


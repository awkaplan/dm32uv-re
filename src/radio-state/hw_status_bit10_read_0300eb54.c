/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: hw_status_bit10_read @ 0300eb54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 14 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint hw_status_bit10_read(void)

{
  uint uVar1;
  
  uVar1 = fd6818_reg_read(FD6818_PAGE0_REG_0CH);
  return uVar1 >> 10 & 3;
}


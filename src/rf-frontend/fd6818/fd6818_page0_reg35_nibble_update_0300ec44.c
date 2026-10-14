/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818_page0_reg35_nibble_update @ 0300ec44 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818_page0_reg35_nibble_update(void)

{
  ushort uVar1;
  ushort unaff_r6;
  
  uVar1 = fd6818_reg_read(FD6818_PAGE0_REG_35H);
  fd6818b_reg_write(FD6818_PAGE0_REG_35H,uVar1 & 0xfff0 | unaff_r6);
  return;
}


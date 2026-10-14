/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_fd6818b_page0_cfg_r41_81c1_b @ 0300eac4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_fd6818b_page0_cfg_r41_81c1_b(void)

{
  fd6818b_reg_write(FD6818_PAGE0_REG_40H,0x3500);
  fd6818b_reg_write(FD6818_PAGE0_REG_41H,0x81c1);
  fd6818b_reg_write(FD6818_PAGE0_REG_3BH,0x1000);
  fd6818b_reg_write(FD6818_PAGE0_REG_3CH,0x2708);
  fd6818b_reg_write(FD6818_PAGE0_REG_3DH,0x3555);
  return;
}


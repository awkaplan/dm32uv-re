/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_table_init_group1_variant_0300f130 @ 0300f130 (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void config_table_init_group1_variant_0300f130(void)

{
  fd6818b_reg_write(FD6818_PAGE0_REG_43H,0x48);
  fd6818b_reg_write(FD6818_PAGE0_REG_47H,0x6740);
  fd6818b_reg_write(FD6818_PAGE0_REG_13H,0x3ff);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X4A,0x5450);
  return;
}


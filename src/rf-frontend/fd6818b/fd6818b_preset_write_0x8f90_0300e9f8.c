/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_preset_write_0x8f90 @ 0300e9f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818b_preset_write_0x8f90(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_1 == 0) {
    if (param_4 == 0) {
      fd6818b_reg_write(FD6818_PAGE0_REG_54H,0x8f90);
      fd6818b_reg_write(FD6818_PAGE0_REG_0X55,0x31f3);
    }
    else if (param_4 == 1) {
      fd6818b_reg_write(FD6818_PAGE0_REG_75H,0x8f90);
    }
  }
  else if (param_1 == 1) {
    if (param_4 == 0) {
      fd6818b_reg_write(FD6818_PAGE0_REG_44H,0x8f90);
      fd6818b_reg_write(FD6818_PAGE0_REG_0X45,0x31f3);
    }
    else if (param_4 == 1) {
      fd6818b_reg_write(FD6818_PAGE0_REG_0X74,0x8f90);
    }
  }
  return;
}


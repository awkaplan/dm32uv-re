/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_band_mode_clear_regs @ 0300e94c (file base 0x03000000; code starts at 0x03001000)
 * Size: 28 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_band_mode_clear_regs(char param_1,char param_2,uint param_3)

{
  if (param_2 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0300e99e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0300e9a0[param_3 & 0xf] & 0xfffffffe))();
    return;
  }
  if (param_2 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x0300e966. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0300e968[param_3 & 0xf] & 0xfffffffe))();
    return;
  }
  if (param_1 == '\0') {
    if (param_2 == '\0') {
      fd6818b_reg_write(FD6818_PAGE0_REG_54H,0);
      fd6818b_reg_write(FD6818_PAGE0_REG_0X55,0);
    }
    else if (param_2 == '\x01') {
      fd6818b_reg_write(FD6818_PAGE0_REG_75H,0);
    }
  }
  else if (param_1 == '\x01') {
    if (param_2 == '\0') {
      fd6818b_reg_write(FD6818_PAGE0_REG_44H,0);
      fd6818b_reg_write(FD6818_PAGE0_REG_0X45,0);
    }
    else if (param_2 == '\x01') {
      fd6818b_reg_write(FD6818_PAGE0_REG_0X74,0);
    }
  }
  return;
}


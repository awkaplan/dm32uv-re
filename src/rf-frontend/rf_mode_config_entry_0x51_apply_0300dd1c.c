/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_mode_config_entry_0x51_apply @ 0300dd1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void rf_mode_config_entry_0x51_apply(char param_1)

{
  if (param_1 == '\x03') {
    fd6818b_reg_write(FD6818_PAGE0_REG_51H,(byte)PTR_DAT_0300de04[0x2d] | 0xa000);
  }
  else if (param_1 == '\x04') {
    if (((p_dm32_settings_block04[0x6d] & 4) == 0) ||
       ((p_radio_mode_state_0003e318[2].field_0x1 & 4) == 0)) {
      fd6818b_reg_write(FD6818_PAGE0_REG_51H,(byte)PTR_DAT_0300de04[0x2d] | 0x9000);
    }
    else {
      fd6818b_reg_write(FD6818_PAGE0_REG_51H,0x1400);
    }
  }
  else if (param_1 == '\x02') {
    fd6818b_reg_write(FD6818_PAGE0_REG_51H,(byte)PTR_DAT_0300de04[0x2d] | 0x8000);
  }
  else {
    fd6818b_reg_write(FD6818_PAGE0_REG_51H,0);
  }
  return;
}


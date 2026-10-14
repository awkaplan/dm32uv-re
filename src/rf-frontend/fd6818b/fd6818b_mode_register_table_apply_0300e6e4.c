/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_mode_register_table_apply @ 0300e6e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 174 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818b_mode_register_table_apply(char param_1)

{
  if (param_1 == '\0') {
    fd6818b_reg_write(FD6818_PAGE0_REG_13H,0x3be);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X12,0x37b);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X11,0x27b);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X10,0x7a);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X14,0x19);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X49,0x2a38);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X7B,0x8420);
  }
  else if (param_1 == '\x01') {
    fd6818b_reg_write(FD6818_PAGE0_REG_13H,0x3be);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X12,0xb7c);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X11,0x35b);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X10,0x31a);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X14,600);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X49,0x2a38);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X7B,0x318c);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X7C,0x595e);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X20,0x8def);
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_page0_enable_config @ 03067564 (file base 0x03000000; code starts at 0x03001000)
 * Size: 144 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818b_page0_enable_config(char param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == '\0') {
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X58,0);
  }
  else {
    fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xe0);
    fd6818b_reg_write(FD6818_PAGE0_REG_72H,0x3065);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X58,0x3f03);
    puVar1 = PTR_DAT_03067658;
    fd6818b_reg_write(FD6818_PAGE0_REG_5AH,CONCAT11(PTR_DAT_03067658[1],PTR_DAT_03067658[2]));
    fd6818b_reg_write(FD6818_PAGE0_REG_5BH,CONCAT11(puVar1[3],puVar1[4]));
    fd6818b_reg_write(FD6818_PAGE0_REG_5CH,0x5625);
    fd6818b_reg_write(FD6818_PAGE0_REG_5EH,0x201);
    fd6818b_reg_write(FD6818_PAGE0_REG_5DH,0xd00);
    fd6818b_reg_write(FD6818_PAGE0_REG_59H,0xc008);
    fd6818b_reg_write(FD6818_PAGE0_REG_59H,0x1008);
    fd6818b_reg_write(FD6818_PAGE0_REG_02H,0);
  }
  return;
}


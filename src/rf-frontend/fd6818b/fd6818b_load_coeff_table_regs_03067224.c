/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_load_coeff_table_regs @ 03067224 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818b_load_coeff_table_regs(void)

{
  undefined2 *puVar1;
  undefined2 value;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  flash_block3_unpack_cfg_0x36_0x41();
  puVar1 = PTR_DAT_0306733c;
  value = cos_scaled_piecewise_to_int(PTR_DAT_0306733c[6]);
  uVar2 = cos_scaled_piecewise_to_int(puVar1[7]);
  uVar3 = cos_scaled_piecewise_to_int(puVar1[8]);
  uVar4 = cos_scaled_piecewise_to_int(puVar1[9]);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,value);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,uVar2 | 0x1000);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,uVar3 | 0x2000);
  fd6818b_reg_write(FD6818_PAGE0_REG_09H,uVar4 | 0x3000);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X21,0x6fd);
  fd6818b_reg_write(FD6818_PAGE0_REG_24H,0x8c23);
  return;
}


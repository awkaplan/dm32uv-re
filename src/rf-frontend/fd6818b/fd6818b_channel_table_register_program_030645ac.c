/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_channel_table_register_program @ 030645ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818b_channel_table_register_program(uint param_1)

{
  ushort uVar1;
  int iVar2;
  short *psVar3;
  
  psVar3 = (short *)(_DAT_03064688 + (param_1 & 0xff) * 0x20);
  iVar2 = 0;
  do {
    uVar1 = cos_scaled_piecewise_to_int((int)*psVar3);
    fd6818b_reg_write(FD6818_PAGE0_REG_09H,(ushort)(iVar2 << 0xc) | uVar1);
    iVar2 = iVar2 + 1;
    psVar3 = psVar3 + 1;
  } while (iVar2 != 0x10);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X21,0x6fd);
  fd6818b_reg_write(FD6818_PAGE0_REG_24H,0x8c2f);
  return;
}


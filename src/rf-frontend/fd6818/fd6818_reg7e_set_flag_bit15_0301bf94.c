/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818_reg7e_set_flag_bit15 @ 0301bf94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818_reg7e_set_flag_bit15(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = fd6818_reg_read(FD6818_PAGE0_REG_7EH);
  uVar2 = 0x8000;
  if ((uVar1 ^ 0x8000) >> 0xf != (param_1 & 0xff)) {
    if ((param_1 & 0xff) != 0) {
      uVar2 = 0;
    }
    fd6818b_reg_write(FD6818_PAGE0_REG_7EH,uVar2 | uVar1 & 0xfff | 0x3000);
  }
  return;
}


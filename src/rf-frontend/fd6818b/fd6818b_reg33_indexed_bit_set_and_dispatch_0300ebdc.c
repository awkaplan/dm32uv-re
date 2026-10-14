/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fd6818b_reg33_indexed_bit_set_and_dispatch @ 0300ebdc (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void fd6818b_reg33_indexed_bit_set_and_dispatch(uint param_1,undefined4 param_2,byte param_3)

{
  ushort uVar1;
  
  uVar1 = fd6818_reg_read(FD6818_PAGE0_REG_0X33);
  fd6818b_reg_write(FD6818_PAGE0_REG_0X33,
                    uVar1 & ~(ushort)(0x4040 >> (param_1 & 0x3f)) |
                    (ushort)((int)((uint)param_3 << 6) >> (param_1 & 0x3f)));
  if ((param_1 & 0xff) < 7) {
                    /* WARNING: Could not recover jumptable at 0x0300ec0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0300ec10[param_1 & 0xff] & 0xfffffffe))();
    return;
  }
  return;
}


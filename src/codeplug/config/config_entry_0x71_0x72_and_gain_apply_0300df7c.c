/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_entry_0x71_0x72_and_gain_apply @ 0300df7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void config_entry_0x71_0x72_and_gain_apply(int param_1__w,int param_2__w,int param_3__w)

{
  undefined2 param_1 = (undefined2)param_1__w;
  undefined2 param_2 = (undefined2)param_2__w;
  undefined2 param_3 = (undefined2)param_3__w;
  fd6818b_reg_write(FD6818_PAGE0_REG_71H,param_1);
  fd6818b_reg_write(FD6818_PAGE0_REG_72H,param_2);
  fd6818b_reg50_write_3b18();
  wait_for_status_byte_clear(param_3);
  return;
}


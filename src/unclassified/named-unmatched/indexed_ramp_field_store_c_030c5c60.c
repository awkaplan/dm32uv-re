/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: indexed_ramp_field_store_c @ 030c5c60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void indexed_ramp_field_store_c(undefined4 param_1,uint param_2)

{
  if (6 < (param_2 & 0xff)) {
    func_0x030de010(_DAT_030c5d1c,param_1,0x31);
    return;
  }
  func_0x030de010(_DAT_030c5d1c,param_1,(param_2 & 0x1f) << 3);
  return;
}


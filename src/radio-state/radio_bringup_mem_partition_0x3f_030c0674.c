/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_bringup_mem_partition_0x3f @ 030c0674 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_bringup_mem_partition_0x3f(undefined4 param_1)

{
  *PTR_DAT_030c0738 = 0;
  OSTaskCreate_variant2
            (_DAT_030c0748,_DAT_030c074c,_DAT_030c0750,0,0x3f,*(undefined4 *)PTR_LAB_030c073c,
             *(undefined4 *)PTR_LAB_030c0740,*(undefined4 *)PTR_LAB_030c0744,0,0,0,0xb,param_1);
  return;
}


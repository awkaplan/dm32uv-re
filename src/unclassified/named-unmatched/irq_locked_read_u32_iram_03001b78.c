/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: irq_locked_read_u32_iram @ 03001b78 (file base 0x03000000; code starts at 0x03001000)
 * Size: 18 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 irq_locked_read_u32_iram(void)

{
  undefined4 sr;
  undefined4 uVar1;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  uVar1 = *PTR_DAT_03001b8c;
  cpu_sr_restore_irq_iram(sr);
  return uVar1;
}


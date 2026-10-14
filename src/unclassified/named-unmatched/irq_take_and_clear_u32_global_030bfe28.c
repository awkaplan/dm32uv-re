/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: irq_take_and_clear_u32_global @ 030bfe28 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 irq_take_and_clear_u32_global(void)

{
  undefined4 uVar1;
  undefined4 sr;
  
  uVar1 = irq_snapshot_sat_sub_a();
  sr = cpu_sr_save_and_disable_irq_variant2();
  *PTR_DAT_030bff10 = 0;
  cpu_sr_restore_irq_variant2(sr);
  return uVar1;
}


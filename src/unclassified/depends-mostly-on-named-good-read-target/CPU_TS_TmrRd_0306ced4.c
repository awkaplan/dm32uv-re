/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: CPU_TS_TmrRd @ 0306ced4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 18 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 CPU_TS_TmrRd(void)

{
  undefined4 sr;
  undefined4 uVar1;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  uVar1 = *PTR_DAT_0306cef0;
  cpu_sr_restore_irq_iram(sr);
  return uVar1;
}


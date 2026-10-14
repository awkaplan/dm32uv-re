/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: cpu_sr_save_and_disable_irq @ 030020d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint cpu_sr_save_and_disable_irq(void)

{
  undefined4 in_r0;
  uint uVar1;
  
  uVar1 = control_register_read(in_r0);
  control_register_write(uVar1 & 0xffffffaf,uVar1);
  return uVar1;
}


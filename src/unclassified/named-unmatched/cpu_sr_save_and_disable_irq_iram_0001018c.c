/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: cpu_sr_save_and_disable_irq_iram @ 0001018c (IRAM address; the boot stub copies these bytes from program flash 0x030bfdac)
 * Size: 16 bytes
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

uint cpu_sr_save_and_disable_irq_iram(void)

{
  undefined4 in_r0;
  uint uVar1;
  
  uVar1 = control_register_read(in_r0);
  control_register_write(uVar1 & 0xffffffaf,uVar1);
  return uVar1;
}


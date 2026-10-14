/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: irq_lock_release_global_value @ 00010224 (IRAM address; the boot stub copies these bytes from program flash 0x030bfe44)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void irq_lock_release_global_value(void)

{
  undefined4 sr;
  undefined4 uVar1;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  uVar1 = *(undefined4 *)PTR_DAT_000102f4;
  cpu_sr_restore_irq_iram(sr);
  func_0x000101a4(uVar1);
  return;
}


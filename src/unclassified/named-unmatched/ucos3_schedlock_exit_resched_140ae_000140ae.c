/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ucos3_schedlock_exit_resched_140ae @ 000140ae (IRAM address; the boot stub copies these bytes from program flash 0x030c3cce)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos3_schedlock_exit_resched_140ae(void)

{
  undefined4 *unaff_r5;
  undefined4 unaff_r6;
  
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(unaff_r6);
  *unaff_r5 = 0x7151;
  OSSched();
  return;
}


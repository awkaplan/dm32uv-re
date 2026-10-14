/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ucos3_sched_unlock_and_resched @ 00012614 (IRAM address; the boot stub copies these bytes from program flash 0x030c2234)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 ucos3_sched_unlock_and_resched(undefined4 param_1)

{
  char cVar1;
  undefined4 sr;
  short unaff_r4;
  undefined4 *unaff_r6;
  
  cpu_sr_restore_irq_iram(param_1);
  func_0x0306ced4();
  msg_node_retire_by_state(0);
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_000127a4;
  *PTR_OSSchedLockNestingCtr_000127a4 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(sr);
  if (-1 < unaff_r4) {
    OSSched();
  }
  *unaff_r6 = 0;
  return 1;
}


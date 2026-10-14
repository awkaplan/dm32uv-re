/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos3_sched_lock_time_stop_irq_restore @ 030699a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos3_sched_lock_time_stop_irq_restore(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_r4;
  undefined4 *unaff_r5;
  undefined4 *unaff_r8;
  
  if (unaff_r5 != (undefined4 *)0x0) {
    *unaff_r5 = *(undefined4 *)(param_3 + 0x40);
  }
  *unaff_r8 = 0x5dc2;
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(unaff_r4);
  return;
}


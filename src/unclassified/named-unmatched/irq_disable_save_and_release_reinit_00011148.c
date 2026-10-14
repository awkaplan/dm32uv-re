/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: irq_disable_save_and_release_reinit @ 00011148 (IRAM address; the boot stub copies these bytes from program flash 0x030c0d68)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void irq_disable_save_and_release_reinit(void)

{
  undefined *puVar1;
  undefined4 sr;
  
  sr = cpu_sr_save_and_disable_irq_iram();
  *PTR_OSPrioHighRdy_00011228 = 0;
  puVar1 = PTR_OSIntQTaskTCB_0001122c;
  *(undefined **)PTR_OSTCBHighRdyPtr_00011230 = PTR_OSIntQTaskTCB_0001122c;
  *(int *)(puVar1 + 0x90) = *(int *)(puVar1 + 0x90) + 1;
  *(int *)PTR_OSTaskCtxSwCtr_00011234 = *(int *)PTR_OSTaskCtxSwCtr_00011234 + 1;
  OSCtxSw();
  cpu_sr_restore_irq_iram(sr);
  return;
}


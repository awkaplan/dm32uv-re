/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_0001232c @ 0001232c (IRAM address; the boot stub copies these bytes from program flash 0x030c1f4c)
 * Size: 149 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_0001232c(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 sr;
  int iVar3;
  undefined4 *unaff_r5;
  
  OS_SchedLockTimeMeasStart();
  iVar3 = *(int *)PTR_OSTCBCurPtr_00012480;
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(param_1);
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_00012484;
  *PTR_OSSchedLockNestingCtr_00012484 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  uVar2 = func_0x030695b4(iVar3 + 100);
  sr = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_00012484;
  *PTR_OSSchedLockNestingCtr_00012484 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
    if (*(short *)PTR_DAT_00012488 == 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      irq_disable_save_and_release_reinit();
    }
  }
  else {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
  }
  *unaff_r5 = 0;
  return uVar2;
}


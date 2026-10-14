/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_SemPost @ 00011fe8 (IRAM address; the boot stub copies these bytes from program flash 0x030c1c08)
 * Size: 228 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int OS_SemPost(int param_1,ushort param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  if (*(short *)(param_1 + 0x10) == 0) {
    if (*(int *)(param_1 + 0x20) == -1) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_4 = 0x6dc5;
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x20) + 1;
      *(int *)(param_1 + 0x20) = iVar4;
      *(undefined4 *)(param_1 + 0x24) = param_3;
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_4 = 0;
    }
  }
  else {
    cVar1 = *PTR_OSSchedLockNestingCtr_000120cc;
    *PTR_OSSchedLockNestingCtr_000120cc = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      OS_SchedLockTimeMeasStart_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    if ((param_2 & 0x200) == 0) {
      iVar4 = *(int *)(param_1 + 8);
      sVar3 = 1;
      goto LAB_00012070;
    }
    iVar4 = *(int *)(param_1 + 8);
    for (sVar3 = *(short *)(param_1 + 0x10); sVar3 != 0; sVar3 = sVar3 + -1) {
LAB_00012070:
      iVar5 = *(int *)(iVar4 + 4);
      work_item_advance_or_complete_and_unlink(param_1,*(undefined4 *)(iVar4 + 8),0,0,param_3);
      iVar4 = iVar5;
    }
    iVar4 = *(int *)(param_1 + 0x20);
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *PTR_OSSchedLockNestingCtr_000120cc;
    *PTR_OSSchedLockNestingCtr_000120cc = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    if (-1 < (short)param_2) {
      OSSched();
    }
    *param_4 = 0;
  }
  return iVar4;
}


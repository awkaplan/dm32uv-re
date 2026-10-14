/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_TaskSemPost @ 000133f4 (IRAM address; the boot stub copies these bytes from program flash 0x030c3014)
 * Size: 610 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int OS_TaskSemPost(int param_1,short param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_00013554;
  *PTR_OSSchedLockNestingCtr_00013554 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  if (param_1 == 0) {
    param_1 = *(int *)PTR_OSTCBCurPtr_00013550;
  }
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *param_4 = 0;
  if (*(byte *)(param_1 + 0x36) < 8) {
    uVar3 = 1 << ((int)*(char *)(param_1 + 0x36) & 0x3fU);
    if ((uVar3 & 0xcc) != 0) {
      if (*(char *)(param_1 + 0x34) == '\a') {
        work_item_advance_or_complete_and_unlink(0,param_1,0,0,param_3);
        iVar4 = *(int *)(param_1 + 0x44);
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *PTR_OSSchedLockNestingCtr_00013554;
        *PTR_OSSchedLockNestingCtr_00013554 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        if (param_2 < 0) {
          return iVar4;
        }
        OSSched();
        return iVar4;
      }
      if (*(int *)(param_1 + 0x44) == -1) {
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *PTR_OSSchedLockNestingCtr_000136b8;
        *PTR_OSSchedLockNestingCtr_000136b8 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
          if (*(short *)PTR_DAT_000136bc == 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
            irq_disable_save_and_release_reinit();
          }
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
        *param_4 = 0x6dc5;
        return 0;
      }
      iVar4 = *(int *)(param_1 + 0x44) + 1;
      *(int *)(param_1 + 0x44) = iVar4;
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_000136b8;
      *PTR_OSSchedLockNestingCtr_000136b8 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_000136bc != 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          irq_disable_save_and_release_reinit();
          return iVar4;
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        return iVar4;
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      return iVar4;
    }
    if ((uVar3 & 0x33) != 0) {
      if (*(int *)(param_1 + 0x44) == -1) {
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *PTR_OSSchedLockNestingCtr_00013554;
        *PTR_OSSchedLockNestingCtr_00013554 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
          if (*(short *)PTR_DAT_00013558 == 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
            irq_disable_save_and_release_reinit();
          }
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
        *param_4 = 0x6dc5;
        return 0;
      }
      iVar4 = *(int *)(param_1 + 0x44) + 1;
      *(int *)(param_1 + 0x44) = iVar4;
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_00013554;
      *PTR_OSSchedLockNestingCtr_00013554 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_00013558 != 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          irq_disable_save_and_release_reinit();
          return iVar4;
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        return iVar4;
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      return iVar4;
    }
  }
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_000136b8;
  *PTR_OSSchedLockNestingCtr_000136b8 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
    if (*(short *)PTR_DAT_000136bc == 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      irq_disable_save_and_release_reinit();
    }
  }
  else {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
  }
  *param_4 = 0x6e2d;
  return 0;
}


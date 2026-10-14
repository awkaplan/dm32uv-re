/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scheduled_task_state_advance_with_queue_promotion @ 03069738 (file base 0x03000000; code starts at 0x03001000)
 * Size: 598 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scheduled_task_state_advance_with_queue_promotion
               (int *param_1,undefined4 param_2,short param_3,int *param_4,undefined4 *param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_3c [32];
  
  if (*(char *)PTR_OSIntNestingCtr_030698a8 != '\0') {
    *param_5 = 0x61ae;
    return;
  }
  if (param_1 == (int *)0x0) {
    *param_5 = 0x5dc3;
    return;
  }
  if ((param_3 != 0) && (param_3 != -0x8000)) {
    *param_5 = 0x5e25;
    return;
  }
  if (*param_1 != _DAT_030698ac) {
    *param_5 = 0x5dc4;
    return;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    iVar3 = *PTR_OSTCBCurPtr_030698b0;
    param_1[8] = iVar3;
    *(undefined1 *)(param_1 + 9) = *(undefined1 *)(iVar3 + 0x37);
    *(undefined1 *)((int)param_1 + 0x25) = 1;
    if (param_4 != (int *)0x0) {
      *param_4 = param_1[10];
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0;
    return;
  }
  if (param_1[8] == *PTR_OSTCBCurPtr_030698b0) {
    *(char *)((int)param_1 + 0x25) = *(char *)((int)param_1 + 0x25) + '\x01';
    if (param_4 != (int *)0x0) {
      *param_4 = param_1[10];
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0x5782;
    return;
  }
  if (param_3 < 0) {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0x61b0;
    return;
  }
  if (*(char *)PTR_OSSchedLockNestingCtr_030698b4 != '\0') {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    *param_5 = 0x6d63;
    return;
  }
  *(undefined1 *)PTR_OSSchedLockNestingCtr_030698b4 = 1;
  OS_SchedLockTimeMeasStart_variant4();
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  iVar3 = param_1[8];
  if (*(byte *)(*PTR_OSTCBCurPtr_030698b0 + 0x37) < *(byte *)(iVar3 + 0x37)) {
    if (7 < *(byte *)(iVar3 + 0x36)) {
LAB_030698c6:
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069a20;
      *(char *)PTR_OSSchedLockNestingCtr_03069a20 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_03069a24 == 0) {
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
      *param_5 = 0x6e2d;
      return;
    }
    uVar4 = 1 << ((int)*(char *)(iVar3 + 0x36) & 0x3fU);
    if ((uVar4 & 0xcc) == 0) {
      if ((uVar4 & 0x32) == 0) {
        if ((uVar4 & 1) == 0) goto LAB_030698c6;
        OS_RdyListRemove(iVar3);
        *(undefined1 *)(iVar3 + 0x37) = *(undefined1 *)(*PTR_OSTCBCurPtr_030698b0 + 0x37);
        OS_PrioInsert();
        hashtable_bucket_insert_tail(iVar3);
      }
      else {
        *(byte *)(iVar3 + 0x37) = *(byte *)(*PTR_OSTCBCurPtr_030698b0 + 0x37);
      }
    }
    else {
      FUN_00010c98(iVar3);
    }
  }
  OS_Pend(auStack_3c,param_1,4,param_2);
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069a20;
  *(char *)PTR_OSSchedLockNestingCtr_03069a20 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  OSSched();
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  iVar3 = *PTR_OSTCBCurPtr_03069a28;
  cVar1 = *(char *)(iVar3 + 0x35);
  if (cVar1 == '\x01') {
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(iVar3 + 0x40);
    }
    *param_5 = 0x61a9;
  }
  else if (cVar1 == '\0') {
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(iVar3 + 0x40);
    }
    *param_5 = 0;
  }
  else if (cVar1 == '\x02') {
    if (param_4 != (int *)0x0) {
      *param_4 = *(int *)(iVar3 + 0x40);
    }
    *param_5 = 0x5dc2;
  }
  else if (cVar1 == '\x03') {
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
    *param_5 = 0x72d9;
  }
  else {
    *param_5 = 0x6e2e;
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  return;
}


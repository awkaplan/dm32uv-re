/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_msg_queue_post_or_pend_variant @ 03069e1c (file base 0x03000000; code starts at 0x03001000)
 * Size: 684 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

short ucos_msg_queue_post_or_pend_variant(int *param_1,ushort param_2,undefined4 *param_3)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  
  if (*(char *)PTR_OSIntNestingCtr_03069f58 != '\0') {
    *param_3 = 0x32c9;
    return 0;
  }
  if (param_1 == (int *)0x0) {
    *param_3 = 0x5dc3;
    return 0;
  }
  if (1 < param_2) {
    *param_3 = 0x5e25;
    return 0;
  }
  if (*param_1 != _DAT_03069f5c) {
    *param_3 = 0x5dc4;
    return 0;
  }
  uVar3 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069f60;
  *(char *)PTR_OSSchedLockNestingCtr_03069f60 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar3);
  sVar2 = (short)param_1[4];
  if (param_2 == 0) {
    if (sVar2 == 0) {
      dlist_unlink_msgq(param_1);
      *(short *)PTR_DAT_03069f64 = *(short *)PTR_DAT_03069f64 + -1;
      FUN_03069cdc(param_1);
      uVar3 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069f60;
      *(char *)PTR_OSSchedLockNestingCtr_03069f60 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_03069f68 == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar3);
      }
      *param_3 = 0;
      return 0;
    }
    uVar3 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069f60;
    *(char *)PTR_OSSchedLockNestingCtr_03069f60 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_03069f68 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar3);
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar3);
        irq_disable_save_and_release_reinit();
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar3);
    }
    *param_3 = 0x715f;
    return sVar2;
  }
  if (param_2 != 1) {
    uVar3 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *_DAT_0306a0f0;
    *_DAT_0306a0f0 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*_DAT_0306a0f4 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar3);
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar3);
        irq_disable_save_and_release_reinit();
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar3);
    }
    *param_3 = 0x5e25;
    return sVar2;
  }
  iVar6 = param_1[8];
  if ((iVar6 != 0) && (*(char *)(iVar6 + 0x37) != (char)param_1[9])) {
    if (7 < *(byte *)(iVar6 + 0x36)) {
LAB_03069fd2:
      uVar3 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *_DAT_0306a0f0;
      *_DAT_0306a0f0 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*_DAT_0306a0f4 == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar3);
      }
      *param_3 = 0x6e2d;
      return 0;
    }
    uVar4 = 1 << ((int)*(char *)(iVar6 + 0x36) & 0x3fU);
    if ((uVar4 & 0xcc) == 0) {
      if ((uVar4 & 0x32) == 0) {
        if ((uVar4 & 1) == 0) goto LAB_03069fd2;
        OS_RdyListRemove(iVar6);
        *(char *)(iVar6 + 0x37) = (char)param_1[9];
        OS_PrioInsert();
        timer_object_register_into_bucket_list(iVar6);
      }
      else {
        *(char *)(iVar6 + 0x37) = (char)param_1[9];
      }
    }
    else {
      FUN_00010c98(iVar6);
    }
  }
  uVar3 = CPU_TS_TmrRd();
  for (sVar5 = sVar2; sVar5 != 0; sVar5 = sVar5 + -1) {
    sched_obj_state_reset_and_unlink(param_1,*(undefined4 *)(param_1[2] + 8),uVar3);
  }
  dlist_unlink_msgq(param_1);
  *_DAT_0306a0f8 = *_DAT_0306a0f8 + -1;
  FUN_03069cdc(param_1);
  uVar3 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *_DAT_0306a0f0;
  *_DAT_0306a0f0 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar3);
  OSSched();
  *param_3 = 0;
  return sVar2;
}


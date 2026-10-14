/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_TaskSemPost_variant3 @ 030c3014 (file base 0x03000000; code starts at 0x03001000)
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

int OS_TaskSemPost_variant3(int param_1,short param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3174;
  *(char *)PTR_OSSchedLockNestingCtr_030c3174 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    conditional_cached_value_refresh();
  }
  OS_SchedLockTimeMeasStop_variant3();
  cpu_sr_restore_irq_variant2(uVar2);
  if (param_1 == 0) {
    param_1 = *PTR_OSTCBCurPtr_030c3170;
  }
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *param_4 = 0;
  if (*(byte *)(param_1 + 0x36) < 8) {
    uVar3 = 1 << ((int)*(char *)(param_1 + 0x36) & 0x3fU);
    if ((uVar3 & 0xcc) != 0) {
      if (*(char *)(param_1 + 0x34) == '\a') {
        queued_event_dispatch_immediate_or_deferred(0,param_1,0,0,param_3);
        iVar4 = *(int *)(param_1 + 0x44);
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3174;
        *(char *)PTR_OSSchedLockNestingCtr_030c3174 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        if (param_2 < 0) {
          return iVar4;
        }
        OS_Sched();
        return iVar4;
      }
      if (*(int *)(param_1 + 0x44) == -1) {
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c32d8;
        *(char *)PTR_OSSchedLockNestingCtr_030c32d8 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
          if (*(short *)PTR_DAT_030c32dc == 0) {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
            ucos_lock_release_cleanup_and_notify();
          }
        }
        else {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
        }
        *param_4 = 0x6dc5;
        return 0;
      }
      iVar4 = *(int *)(param_1 + 0x44) + 1;
      *(int *)(param_1 + 0x44) = iVar4;
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c32d8;
      *(char *)PTR_OSSchedLockNestingCtr_030c32d8 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track();
        if (*(short *)PTR_DAT_030c32dc != 0) {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          ucos_lock_release_cleanup_and_notify();
          return iVar4;
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        return iVar4;
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      return iVar4;
    }
    if ((uVar3 & 0x33) != 0) {
      if (*(int *)(param_1 + 0x44) == -1) {
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3174;
        *(char *)PTR_OSSchedLockNestingCtr_030c3174 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
          if (*(short *)PTR_DAT_030c3178 == 0) {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
            ucos_lock_release_cleanup_and_notify();
          }
        }
        else {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
        }
        *param_4 = 0x6dc5;
        return 0;
      }
      iVar4 = *(int *)(param_1 + 0x44) + 1;
      *(int *)(param_1 + 0x44) = iVar4;
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3174;
      *(char *)PTR_OSSchedLockNestingCtr_030c3174 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track();
        if (*(short *)PTR_DAT_030c3178 != 0) {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          ucos_lock_release_cleanup_and_notify();
          return iVar4;
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        return iVar4;
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      return iVar4;
    }
  }
  uVar2 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c32d8;
  *(char *)PTR_OSSchedLockNestingCtr_030c32d8 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    ucos_crit_section_nest_exit_with_lock_time_track();
    if (*(short *)PTR_DAT_030c32dc == 0) {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
    }
    else {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      ucos_lock_release_cleanup_and_notify();
    }
  }
  else {
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar2);
  }
  *param_4 = 0x6e2d;
  return 0;
}


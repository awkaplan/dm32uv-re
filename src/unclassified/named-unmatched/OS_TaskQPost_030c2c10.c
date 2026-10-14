/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_TaskQPost @ 030c2c10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 454 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_TaskQPost(int param_1,undefined4 param_2,undefined2 param_3,short param_4,undefined4 param_5
                 ,undefined4 *param_6)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2ccc;
  *(char *)PTR_OSSchedLockNestingCtr_030c2ccc = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    conditional_cached_value_refresh();
  }
  OS_SchedLockTimeMeasStop_variant3();
  cpu_sr_restore_irq_variant2(uVar2);
  if (param_1 == 0) {
    param_1 = *PTR_OSTCBCurPtr_030c2cdc;
  }
  *param_6 = 0;
  if (*(byte *)(param_1 + 0x36) < 8) {
    uVar3 = 1 << ((int)*(char *)(param_1 + 0x36) & 0x3fU);
    if ((uVar3 & 0xcc) != 0) {
      if (*(char *)(param_1 + 0x34) == '\x02') {
        queued_event_dispatch_immediate_or_deferred(0,param_1,param_2,param_3,param_5);
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2e5c;
        *(char *)PTR_OSSchedLockNestingCtr_030c2e5c = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        if (param_4 < 0) {
          return;
        }
        OS_Sched();
        return;
      }
      func_0x06119290(param_1 + 100,param_2,param_3,param_4,param_5,param_6);
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2e5c;
      *(char *)PTR_OSSchedLockNestingCtr_030c2e5c = cVar1 + -1;
      if ((char)(cVar1 + -1) != '\0') {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        return;
      }
      ucos_crit_section_nest_exit_with_lock_time_track();
      if (*(short *)PTR_DAT_030c2e60 != 0) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        ucos_lock_release_cleanup_and_notify();
        return;
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      return;
    }
    if ((uVar3 & 0x33) != 0) {
      func_0x06119290(param_1 + 100,param_2,param_3,param_4,param_5,param_6);
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2ccc;
      *(char *)PTR_OSSchedLockNestingCtr_030c2ccc = cVar1 + -1;
      if ((char)(cVar1 + -1) != '\0') {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        return;
      }
      ucos_crit_section_nest_exit_with_lock_time_track();
      if (*(short *)PTR_DAT_030c2cd8 != 0) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        ucos_lock_release_cleanup_and_notify();
        return;
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      return;
    }
  }
  uVar2 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2e5c;
  *(char *)PTR_OSSchedLockNestingCtr_030c2e5c = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    ucos_crit_section_nest_exit_with_lock_time_track();
    if (*(short *)PTR_DAT_030c2e60 == 0) {
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
  *param_6 = 0x6e2d;
  return;
}


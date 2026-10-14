/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_SemPost_variant2 @ 030c1c08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 228 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int OS_SemPost_variant2(int param_1,ushort param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  if (*(short *)(param_1 + 0x10) == 0) {
    if (*(int *)(param_1 + 0x20) == -1) {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      *param_4 = 0x6dc5;
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x20) + 1;
      *(int *)(param_1 + 0x20) = iVar4;
      *(undefined4 *)(param_1 + 0x24) = param_3;
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      *param_4 = 0;
    }
  }
  else {
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1cec;
    *(char *)PTR_OSSchedLockNestingCtr_030c1cec = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      conditional_cached_value_refresh();
    }
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar2);
    if ((param_2 & 0x200) == 0) {
      iVar4 = *(int *)(param_1 + 8);
      sVar3 = 1;
      goto LAB_030c1c90;
    }
    iVar4 = *(int *)(param_1 + 8);
    for (sVar3 = *(short *)(param_1 + 0x10); sVar3 != 0; sVar3 = sVar3 + -1) {
LAB_030c1c90:
      iVar5 = *(int *)(iVar4 + 4);
      queued_event_dispatch_immediate_or_deferred(param_1,*(undefined4 *)(iVar4 + 8),0,0,param_3);
      iVar4 = iVar5;
    }
    iVar4 = *(int *)(param_1 + 0x20);
    uVar2 = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1cec;
    *(char *)PTR_OSSchedLockNestingCtr_030c1cec = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      ucos_crit_section_nest_exit_with_lock_time_track();
    }
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar2);
    if (-1 < (short)param_2) {
      OS_Sched();
    }
    *param_4 = 0;
  }
  return iVar4;
}


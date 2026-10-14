/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_TaskSemPost_variant2 @ 030034c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 610 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int OS_TaskSemPost_variant2(int param_1,short param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  cVar1 = *(char *)PTR_LAB_03003660;
  *(char *)PTR_LAB_03003660 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    ucos_timer_live_count_decrement_hook();
  }
  OS_SchedLockTimeMeasStop_variant2();
  func_0x030020e4(uVar2);
  if (param_1 == 0) {
    param_1 = *PTR_DAT_03003664;
  }
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *param_4 = 0;
  if (*(byte *)(param_1 + 0x36) < 8) {
    uVar3 = 1 << ((int)*(char *)(param_1 + 0x36) & 0x3fU);
    if ((uVar3 & 0xcc) != 0) {
      if (*(char *)(param_1 + 0x34) == '\a') {
        serial_command_phase_tracker_and_dispatch(0,param_1,0,0,param_3);
        iVar4 = *(int *)(param_1 + 0x44);
        uVar2 = cpu_sr_save_and_disable_irq();
        OS_SchedLockTimeMeasStart_variant2();
        cVar1 = *(char *)PTR_LAB_03003660;
        *(char *)PTR_LAB_03003660 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track_variant2();
        }
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
        if (param_2 < 0) {
          return iVar4;
        }
        bounded_queue_lock_release_pair_variant();
        return iVar4;
      }
      if (*(int *)(param_1 + 0x44) == -1) {
        uVar2 = cpu_sr_save_and_disable_irq();
        OS_SchedLockTimeMeasStart_variant2();
        cVar1 = *(char *)PTR_LAB_03003660;
        *(char *)PTR_LAB_03003660 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track_variant2();
          if (*(short *)PTR_DAT_03003668 == 0) {
            OS_SchedLockTimeMeasStop_variant2();
            func_0x030020e4(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop_variant2();
            func_0x030020e4(uVar2);
            queued_task_event_dispatch_with_counter();
          }
        }
        else {
          OS_SchedLockTimeMeasStop_variant2();
          func_0x030020e4(uVar2);
        }
        *param_4 = 0x6dc5;
        return 0;
      }
      iVar4 = *(int *)(param_1 + 0x44) + 1;
      *(int *)(param_1 + 0x44) = iVar4;
      uVar2 = cpu_sr_save_and_disable_irq();
      OS_SchedLockTimeMeasStart_variant2();
      cVar1 = *_LAB_03003734;
      *_LAB_03003734 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track_variant2();
        if (*_LAB_03003738 != 0) {
          OS_SchedLockTimeMeasStop_variant2();
          func_0x030020e4(uVar2);
          queued_task_event_dispatch_with_counter();
          return iVar4;
        }
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
        return iVar4;
      }
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      return iVar4;
    }
    if ((uVar3 & 0x33) != 0) {
      if (*(int *)(param_1 + 0x44) == -1) {
        uVar2 = cpu_sr_save_and_disable_irq();
        OS_SchedLockTimeMeasStart_variant2();
        cVar1 = *(char *)PTR_LAB_03003660;
        *(char *)PTR_LAB_03003660 = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track_variant2();
          if (*(short *)PTR_DAT_03003668 == 0) {
            OS_SchedLockTimeMeasStop_variant2();
            func_0x030020e4(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop_variant2();
            func_0x030020e4(uVar2);
            queued_task_event_dispatch_with_counter();
          }
        }
        else {
          OS_SchedLockTimeMeasStop_variant2();
          func_0x030020e4(uVar2);
        }
        *param_4 = 0x6dc5;
        return 0;
      }
      iVar4 = *(int *)(param_1 + 0x44) + 1;
      *(int *)(param_1 + 0x44) = iVar4;
      uVar2 = cpu_sr_save_and_disable_irq();
      OS_SchedLockTimeMeasStart_variant2();
      cVar1 = *(char *)PTR_LAB_03003660;
      *(char *)PTR_LAB_03003660 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track_variant2();
        if (*(short *)PTR_DAT_03003668 != 0) {
          OS_SchedLockTimeMeasStop_variant2();
          func_0x030020e4(uVar2);
          queued_task_event_dispatch_with_counter();
          return iVar4;
        }
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
        return iVar4;
      }
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      return iVar4;
    }
  }
  uVar2 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  cVar1 = *_LAB_03003734;
  *_LAB_03003734 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    ucos_crit_section_nest_exit_with_lock_time_track_variant2();
    if (*_LAB_03003738 == 0) {
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
    }
    else {
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      queued_task_event_dispatch_with_counter();
    }
  }
  else {
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar2);
  }
  *param_4 = 0x6e2d;
  return 0;
}


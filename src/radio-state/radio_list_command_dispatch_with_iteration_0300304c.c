/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_list_command_dispatch_with_iteration @ 0300304c (file base 0x03000000; code starts at 0x03001000)
 * Size: 228 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int radio_list_command_dispatch_with_iteration
              (int param_1,ushort param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  if (*(short *)(param_1 + 0x10) == 0) {
    if (*(int *)(param_1 + 0x14) == -1) {
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      *param_4 = 0x6dc5;
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x14) + 1;
      *(int *)(param_1 + 0x14) = iVar4;
      *(undefined4 *)(param_1 + 0x18) = param_3;
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      *param_4 = 0;
    }
  }
  else {
    cVar1 = *(char *)PTR_LAB_03003130;
    *(char *)PTR_LAB_03003130 = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      ucos_timer_live_count_decrement_hook();
    }
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar2);
    if ((param_2 & 0x200) == 0) {
      iVar4 = *(int *)(param_1 + 8);
      sVar3 = 1;
      goto LAB_030030d4;
    }
    iVar4 = *(int *)(param_1 + 8);
    for (sVar3 = *(short *)(param_1 + 0x10); sVar3 != 0; sVar3 = sVar3 + -1) {
LAB_030030d4:
      iVar5 = *(int *)(iVar4 + 4);
      serial_command_phase_tracker_and_dispatch(param_1,*(undefined4 *)(iVar4 + 8),0,0,param_3);
      iVar4 = iVar5;
    }
    iVar4 = *(int *)(param_1 + 0x14);
    uVar2 = cpu_sr_save_and_disable_irq();
    OS_SchedLockTimeMeasStart_variant2();
    cVar1 = *(char *)PTR_LAB_03003130;
    *(char *)PTR_LAB_03003130 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      ucos_crit_section_nest_exit_with_lock_time_track_variant2();
    }
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar2);
    if (-1 < (short)param_2) {
      bounded_queue_lock_release_pair_variant();
    }
    *param_4 = 0;
  }
  return iVar4;
}


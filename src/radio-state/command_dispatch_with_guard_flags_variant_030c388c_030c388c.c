/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: command_dispatch_with_guard_flags_variant_030c388c @ 030c388c (file base 0x03000000; code starts at 0x03001000)
 * Size: 242 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void command_dispatch_with_guard_flags_variant_030c388c(int param_1,ushort param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)PTR_OSIntNestingCtr_030c39e8 != '\0') {
    *param_3 = 0x7275;
    return;
  }
  if (*(char *)PTR_OSSchedLockNestingCtr_030c39ec != '\0') {
    *param_3 = 0x6d63;
    return;
  }
  if (param_2 == 2) {
LAB_030c38ca:
    if (param_1 == 0) {
      *param_3 = 0x727e;
      return;
    }
LAB_030c38de:
    uVar2 = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c39ec;
    *(char *)PTR_OSSchedLockNestingCtr_030c39ec = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      conditional_cached_value_refresh();
    }
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar2);
    iVar3 = *PTR_OSTCBCurPtr_030c39f0;
    *(undefined1 *)(iVar3 + 0x36) = 1;
    timer_entry_insert_hash_bucketed_list_030c(iVar3,param_1,param_2,param_3);
    if (*param_3 == 0) {
      linked_list_slot_free_and_unlink(*PTR_OSTCBCurPtr_030c39f0);
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c39ec;
      *(char *)PTR_OSSchedLockNestingCtr_030c39ec = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track();
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      OS_Sched();
      *param_3 = 0;
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c39ec;
      *(char *)PTR_OSSchedLockNestingCtr_030c39ec = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track();
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 0) goto LAB_030c38ca;
    }
    else {
      if (param_2 == 4) goto LAB_030c38de;
      if (param_2 == 8) goto LAB_030c38ca;
    }
    *param_3 = 0x5e25;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_frequency_or_dmr_mode_configure @ 030c1d8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 398 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_frequency_or_dmr_mode_configure(int param_1,byte param_2,undefined4 *param_3)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (*(char *)PTR_OSIntNestingCtr_030c1f1c != '\0') {
    *param_3 = 0x7149;
    return;
  }
  if (param_2 == 0) {
    *param_3 = 0x6273;
    return;
  }
  if (0x3e < param_2) {
    *param_3 = 0x6273;
    return;
  }
  bVar2 = param_1 != 0;
  if (!bVar2) {
    uVar3 = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    param_1 = *PTR_OSTCBCurPtr_030c1f20;
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar3);
  }
  uVar3 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1f24;
  *(char *)PTR_OSSchedLockNestingCtr_030c1f24 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    conditional_cached_value_refresh();
  }
  OS_SchedLockTimeMeasStop_variant3();
  cpu_sr_restore_irq_variant2(uVar3);
  if (*(byte *)(param_1 + 0x36) < 8) {
    uVar4 = 1 << ((int)*(char *)(param_1 + 0x36) & 0x3fU);
    if ((uVar4 & 0xcc) == 0) {
      if ((uVar4 & 0x32) == 0) {
        if ((uVar4 & 1) == 0) goto LAB_030c1e98;
        linked_list_slot_free_and_unlink(param_1);
        *(byte *)(param_1 + 0x37) = param_2;
        FUN_030c1634(param_2);
        if (bVar2) {
          slot_list_push_back_b(param_1);
        }
        else {
          slot_list_push_front_b(param_1);
        }
      }
      else {
        *(byte *)(param_1 + 0x37) = param_2;
      }
    }
    else if (*(byte *)(param_1 + 0x34) < 8) {
      uVar4 = 1 << ((int)*(char *)(param_1 + 0x34) & 0x3fU);
      if ((uVar4 & 0x86) == 0) {
        if ((uVar4 & 0x78) != 0) {
          FUN_030c08b8(param_1,param_2);
        }
      }
      else {
        *(byte *)(param_1 + 0x37) = param_2;
      }
    }
    uVar3 = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1f24;
    *(char *)PTR_OSSchedLockNestingCtr_030c1f24 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      ucos_crit_section_nest_exit_with_lock_time_track();
    }
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar3);
    OS_Sched();
    *param_3 = 0;
  }
  else {
LAB_030c1e98:
    uVar3 = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1f24;
    *(char *)PTR_OSSchedLockNestingCtr_030c1f24 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      ucos_crit_section_nest_exit_with_lock_time_track();
      if (*(short *)PTR_DAT_030c1f28 == 0) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
      }
      else {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
        ucos_lock_release_cleanup_and_notify();
      }
    }
    else {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar3);
    }
    *param_3 = 0x6e2d;
  }
  return;
}


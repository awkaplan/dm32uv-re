/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_list_command_dispatch_jumptable @ 030c285c (file base 0x03000000; code starts at 0x03001000)
 * Size: 218 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_list_command_dispatch_jumptable(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_030c28f8 == '\0') {
    if (param_1 == _DAT_030c28fc) {
      *param_2 = 0x714c;
    }
    else if (param_1 == _DAT_030c2900) {
      *param_2 = 0x714d;
    }
    else {
      if (param_1 == 0) {
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        param_1 = *PTR_OSTCBCurPtr_030c2904;
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
      }
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2908;
      *(char *)PTR_OSSchedLockNestingCtr_030c2908 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        conditional_cached_value_refresh();
      }
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
      if (*(byte *)(param_1 + 0x36) < 8) {
                    /* WARNING: Could not recover jumptable at 0x030c28e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(PTR_LAB_030c290c[*(byte *)(param_1 + 0x36)] & 0xfffffffe))();
        return;
      }
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2b04;
      *(char *)PTR_OSSchedLockNestingCtr_030c2b04 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track();
        if (*(short *)PTR_DAT_030c2b08 == 0) {
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
      *param_2 = 0x6e2d;
    }
  }
  else {
    *param_2 = 0x714e;
  }
  return;
}


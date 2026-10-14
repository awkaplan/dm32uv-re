/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: reentrant_lock_section_guard_variant2 @ 030c1f2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 182 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 reentrant_lock_section_guard_variant2(int param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 sr;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_030c209c == '\0') {
    if (param_1 == 0) {
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      param_1 = *PTR_OSTCBCurPtr_030c20a0;
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar2);
    }
    uVar2 = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c20a4;
    *(char *)PTR_OSSchedLockNestingCtr_030c20a4 = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      conditional_cached_value_refresh();
    }
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar2);
    uVar2 = func_0x061191d4(param_1 + 100);
    sr = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c20a4;
    *(char *)PTR_OSSchedLockNestingCtr_030c20a4 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      ucos_crit_section_nest_exit_with_lock_time_track();
      if (*(short *)PTR_DAT_030c20a8 == 0) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
      }
      else {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
        ucos_lock_release_cleanup_and_notify();
      }
    }
    else {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(sr);
    }
    *param_2 = 0;
  }
  else {
    *param_2 = 0x3b00;
    uVar2 = 0;
  }
  return uVar2;
}


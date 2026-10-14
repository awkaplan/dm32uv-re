/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: sched_lock_unlock_with_max_duration_tracking @ 0306a100 (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 sched_lock_unlock_with_max_duration_tracking(int *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 sr;
  undefined4 uVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_0306a264 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_2 = 0x5dc3;
      uVar2 = 0;
    }
    else if (*param_1 == DAT_0306a268) {
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306a26c;
      *(char *)PTR_OSSchedLockNestingCtr_0306a26c = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      uVar2 = FUN_030695b4(param_1 + 8);
      sr = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306a26c;
      *(char *)PTR_OSSchedLockNestingCtr_0306a26c = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_0306a270 == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
      }
      *param_2 = 0;
    }
    else {
      *param_2 = 0x5dc4;
      uVar2 = 0;
    }
  }
  else {
    *param_2 = 0x3b00;
    uVar2 = 0;
  }
  return uVar2;
}


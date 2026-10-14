/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSTimeDlyResume @ 030c3b58 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTimeDlyResume(int param_1,undefined4 *param_2)

{
  undefined4 sr;
  
  if (*(char *)PTR_OSIntNestingCtr_030c3bbc == '\0') {
    if (param_1 == 0) {
      *param_2 = 0x7151;
    }
    else {
      sr = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      if (param_1 == *PTR_OSTCBCurPtr_030c3bb8) {
        *param_2 = 0x7151;
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
      }
      else {
        if (*(byte *)(param_1 + 0x36) < 8) {
                    /* WARNING: Could not recover jumptable at 0x030c3bae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(PTR_LAB_030c3bc0[*(byte *)(param_1 + 0x36)] & 0xfffffffe))();
          return;
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
        *param_2 = 0x6e2d;
        OS_Sched();
      }
    }
  }
  else {
    *param_2 = 0x7276;
  }
  return;
}


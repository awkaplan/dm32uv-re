/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: locked_queue_pop_dequeue @ 0306c244 (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 locked_queue_pop_dequeue(int *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 sr;
  uint uVar1;
  undefined4 uVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_1 == (int *)0x0) {
    *param_3 = 0x2711;
    uVar2 = 0;
  }
  else if (param_2 == 0) {
    *param_3 = 0x2793;
    uVar2 = 0;
  }
  else {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    if (*param_1 == DAT_0306c304) {
      if ((uint)param_1[0xc] < param_2) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_3 = 0x2793;
        uVar2 = 0;
      }
      else {
        uVar1 = param_1[9];
        if (uVar1 == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_3 = 0x27de;
          uVar2 = 0;
        }
        else if ((uint)param_1[0xb] < uVar1) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_3 = 0x2795;
          uVar2 = 0;
        }
        else {
          param_1[9] = uVar1 - 1;
          uVar2 = *(undefined4 *)(param_1[8] + (uVar1 - 1) * 4);
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_3 = 10000;
        }
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_3 = 0x2788;
      uVar2 = 0;
    }
  }
  return uVar2;
}


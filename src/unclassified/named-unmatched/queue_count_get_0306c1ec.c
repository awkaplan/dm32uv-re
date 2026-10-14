/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_count_get @ 0306c1ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int queue_count_get(int *param_1,undefined4 *param_2)

{
  undefined4 sr;
  int iVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_1 == (int *)0x0) {
    *param_2 = 0x2711;
    iVar1 = 0;
  }
  else {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    if (*param_1 == DAT_0306c304) {
      iVar1 = param_1[9];
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_2 = 10000;
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_2 = 0x2788;
      iVar1 = 0;
    }
  }
  return iVar1;
}


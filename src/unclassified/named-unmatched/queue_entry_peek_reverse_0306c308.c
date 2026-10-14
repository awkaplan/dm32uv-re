/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_entry_peek_reverse @ 0306c308 (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 queue_entry_peek_reverse(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 sr;
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_3 == (undefined4 *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_1 == (int *)0x0) {
    *param_3 = 0x2711;
    uVar2 = 0;
  }
  else {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    if (*param_1 == _DAT_0306c4c4) {
      uVar1 = param_1[0xb];
      if ((uint)param_1[9] < uVar1) {
        uVar3 = (uVar1 - 1) - param_2;
        if (uVar3 < uVar1) {
          if (uVar3 < (uint)param_1[9]) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_3 = 0x2795;
            uVar2 = 0;
          }
          else {
            uVar2 = *(undefined4 *)(param_1[8] + uVar3 * 4);
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_3 = 10000;
          }
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_3 = 0x2795;
          uVar2 = 0;
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_3 = 0x2795;
        uVar2 = 0;
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


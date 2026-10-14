/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scheduler_locked_padded_block_alloc @ 0306bc60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 202 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int scheduler_locked_padded_block_alloc(uint param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  undefined4 sr;
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uStack_24;
  
  if (param_4 == (undefined4 *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_3 == (uint *)0x0) {
    param_3 = &uStack_24;
  }
  *param_3 = 0;
  if (param_1 == 0) {
    *param_4 = 0x2774;
    iVar2 = 0;
  }
  else if (param_2 == 0) {
    *param_4 = 0x2775;
    iVar2 = 0;
  }
  else {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    uVar3 = PTR_DAT_0306bdd4[0x11];
    uVar1 = padded_block_total_size_with_overflow_guard(PTR_DAT_0306bdd4[0xf],1,param_1,param_2);
    if (uVar1 == 0) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_3 = param_1;
      *param_4 = 0x27e3;
      iVar2 = 0;
    }
    else if (uVar3 < uVar1) {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_3 = uVar1 - uVar3;
      *param_4 = 0x27e2;
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0306ba04(PTR_DAT_0306bdd4,param_1,param_2);
      if (iVar2 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_3 = uVar1;
        *param_4 = 0x27e2;
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_4 = 10000;
      }
    }
  }
  return iVar2;
}


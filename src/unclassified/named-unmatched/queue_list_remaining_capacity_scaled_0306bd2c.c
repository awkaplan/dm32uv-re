/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_list_remaining_capacity_scaled @ 0306bd2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 166 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int queue_list_remaining_capacity_scaled(int *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 sr;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 == (undefined4 *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_2 == 0) {
    *param_3 = 0x2775;
    iVar2 = 0;
  }
  else if (param_2 < 0x1001) {
    if (param_1 == (int *)0x0) {
      *param_3 = 0x2711;
      iVar2 = 0;
    }
    else {
      sr = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      if ((*param_1 == _DAT_0306bdd8) || (*param_1 == _DAT_0306bddc)) {
        puVar1 = (undefined4 *)param_1[1];
        if (((undefined4 *)param_1[1])[0xe] == 0) {
          puVar1 = PTR_DAT_0306bdd4;
        }
        iVar2 = puVar1[0x11];
        uVar3 = puVar1[0xf];
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        if (1 < param_2) {
          iVar4 = uVar3 - param_2 * (uVar3 / param_2);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = param_2 - iVar4;
          }
          iVar2 = iVar2 - iVar4;
        }
        *param_3 = 10000;
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_3 = 0x2788;
        iVar2 = 0;
      }
    }
  }
  else {
    *param_3 = 0x2775;
    iVar2 = 0;
  }
  return iVar2;
}


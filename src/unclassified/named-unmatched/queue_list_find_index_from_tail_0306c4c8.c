/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_list_find_index_from_tail @ 0306c4c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 286 bytes
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

int queue_list_find_index_from_tail(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 sr;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  if (param_3 == (undefined4 *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_1 == (int *)0x0) {
    *param_3 = 0x2711;
    iVar1 = -1;
  }
  else if (param_2 == 0) {
    *param_3 = 0x2711;
    iVar1 = -1;
  }
  else {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    if (*param_1 == _DAT_0306c5e8) {
      iVar1 = FUN_0306b908(param_1,param_2);
      if (iVar1 == 1) {
        uVar2 = param_1[9];
        if (uVar2 == 0) {
LAB_0306c57a:
          uVar4 = param_1[0xb];
          if (uVar2 < uVar4) {
            if (*(int *)(param_1[8] + uVar2 * 4) != param_2) {
              piVar3 = (int *)(param_1[8] + (uVar2 + 1) * 4);
              do {
                uVar2 = uVar2 + 1;
                if (uVar4 <= uVar2) {
                  OS_SchedLockTimeMeasStop();
                  cpu_sr_restore_irq_iram(sr);
                  *param_3 = 0x2788;
                  return -1;
                }
                iVar1 = *piVar3;
                piVar3 = piVar3 + 1;
              } while (iVar1 != param_2);
            }
            iVar1 = (uVar4 - 1) - uVar2;
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_3 = 10000;
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_3 = 0x27dd;
            iVar1 = -1;
          }
        }
        else {
          piVar3 = (int *)param_1[8];
          if (*piVar3 != param_2) {
            uVar4 = 0;
            do {
              piVar3 = piVar3 + 1;
              uVar4 = uVar4 + 1;
              if (uVar2 <= uVar4) goto LAB_0306c57a;
            } while (*piVar3 != param_2);
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_3 = 0x2798;
          iVar1 = -1;
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_3 = 0x2797;
        iVar1 = -1;
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_3 = 0x2788;
      iVar1 = -1;
    }
  }
  return iVar1;
}


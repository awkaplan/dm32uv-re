/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_list_insert_unique @ 0306c3b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 272 bytes
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

void queue_list_insert_unique(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 sr;
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (param_3 == (undefined4 *)0x0) {
    assert_null_ptr_spin();
  }
  if (param_1 == (int *)0x0) {
    *param_3 = 0x2711;
  }
  else if (param_2 == 0) {
    *param_3 = 0x2711;
  }
  else {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    if (*param_1 == _DAT_0306c4c4) {
      iVar1 = FUN_0306b908(param_1,param_2);
      if (iVar1 == 1) {
        uVar2 = param_1[9];
        if (uVar2 == 0) {
LAB_0306c452:
          if (uVar2 < (uint)param_1[0xb]) {
            iVar1 = param_1[8];
            iVar6 = *(int *)(iVar1 + uVar2 * 4);
            if (iVar6 != param_2) {
              piVar3 = (int *)(iVar1 + (uVar2 + 1) * 4);
              do {
                uVar2 = uVar2 + 1;
                if ((uint)param_1[0xb] <= uVar2) {
                  OS_SchedLockTimeMeasStop();
                  cpu_sr_restore_irq_iram(sr);
                  *param_3 = 0x2788;
                  return;
                }
                iVar4 = *piVar3;
                piVar3 = piVar3 + 1;
              } while (iVar4 != param_2);
            }
            *(int *)(iVar1 + uVar2 * 4) = iVar6;
            *(int *)(param_1[8] + param_1[9] * 4) = param_2;
            param_1[9] = param_1[9] + 1;
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_3 = 10000;
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(sr);
            *param_3 = 0x27dd;
          }
        }
        else {
          piVar3 = (int *)param_1[8];
          if (*piVar3 != param_2) {
            uVar5 = 0;
            do {
              piVar3 = piVar3 + 1;
              uVar5 = uVar5 + 1;
              if (uVar2 <= uVar5) goto LAB_0306c452;
            } while (*piVar3 != param_2);
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(sr);
          *param_3 = 0x2798;
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_3 = 0x2797;
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(sr);
      *param_3 = 0x2788;
    }
  }
  return;
}


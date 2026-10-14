/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskSemPend @ 00012720 (IRAM address; the boot stub copies these bytes from program flash 0x030c2340)
 * Size: 390 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int OSTaskSemPend(undefined4 param_1,int param_2__w,undefined4 *param_3,undefined4 *param_4)

{
  short param_2 = (short)param_2__w;
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*PTR_OSIntNestingCtr_000127b0 == '\0') {
    if ((param_2 == 0) || (param_2 == -0x8000)) {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 0;
      }
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      puVar1 = PTR_OSSchedLockNestingCtr_000129a4;
      iVar5 = *(int *)PTR_OSTCBCurPtr_000127a8;
      if (*(int *)(iVar5 + 0x44) == 0) {
        if (param_2 < 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          *param_4 = 0x61b0;
          iVar7 = 0;
        }
        else if (*PTR_OSSchedLockNestingCtr_000129a4 == '\0') {
          *PTR_OSSchedLockNestingCtr_000129a4 = 1;
          OS_SchedLockTimeMeasStart_variant4();
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          OS_Pend(0,0,7,param_1);
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar4 = *puVar1 + -1;
          *puVar1 = cVar4;
          if (cVar4 == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          OSSched();
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          iVar5 = *(int *)PTR_OSTCBCurPtr_000129a8;
          cVar4 = *(char *)(iVar5 + 0x35);
          if (cVar4 == '\x01') {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = *(undefined4 *)(iVar5 + 0x40);
            }
            *param_4 = 0x61a9;
          }
          else if (cVar4 == '\0') {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = *(undefined4 *)(iVar5 + 0x40);
              iVar5 = func_0x0306ced4();
              iVar7 = *(int *)PTR_OSTCBCurPtr_000129a8;
              uVar3 = iVar5 - *(int *)(iVar7 + 0x40);
              *(uint *)(iVar7 + 0xa4) = uVar3;
              if (*(uint *)(iVar7 + 0xa8) < uVar3) {
                *(uint *)(iVar7 + 0xa8) = uVar3;
              }
            }
            *param_4 = 0;
          }
          else if (cVar4 == '\x03') {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = 0;
            }
            *param_4 = 0x72d9;
          }
          else {
            *param_4 = 0x6e2e;
          }
          iVar7 = *(int *)(*(int *)PTR_OSTCBCurPtr_000129a8 + 0x44);
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          *param_4 = 0x6d63;
          iVar7 = 0;
        }
      }
      else {
        iVar7 = *(int *)(iVar5 + 0x44) + -1;
        *(int *)(iVar5 + 0x44) = iVar7;
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = *(undefined4 *)(iVar5 + 0x40);
        }
        iVar5 = func_0x0306ced4();
        iVar6 = *(int *)PTR_OSTCBCurPtr_000127a8;
        uVar3 = iVar5 - *(int *)(iVar6 + 0x40);
        *(uint *)(iVar6 + 0xa4) = uVar3;
        if (*(uint *)(iVar6 + 0xa8) < uVar3) {
          *(uint *)(iVar6 + 0xa8) = uVar3;
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        *param_4 = 0;
      }
    }
    else {
      *param_4 = 0x5e25;
      iVar7 = 0;
    }
  }
  else {
    *param_4 = 0x61ae;
    iVar7 = 0;
  }
  return iVar7;
}


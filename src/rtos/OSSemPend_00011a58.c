/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSSemPend @ 00011a58 (IRAM address; the boot stub copies these bytes from program flash 0x030c1678)
 * Size: 402 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int OSSemPend(int *param_1,undefined4 param_2,short param_3,int *param_4,undefined4 *param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined1 auStack_40 [32];
  
  if (*pcRam00011bc4 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_5 = 0x5dc3;
      iVar4 = 0;
    }
    else if ((param_3 == 0) || (param_3 == -0x8000)) {
      if (*param_1 == iRam00011bc8) {
        if (param_4 != (int *)0x0) {
          *param_4 = 0;
        }
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        puVar1 = PTR_OSSchedLockNestingCtr_00011bcc;
        if (param_1[8] == 0) {
          iVar4 = 0;
          if (param_3 < 0) {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
            *param_5 = 0x61b0;
          }
          else if (*PTR_OSSchedLockNestingCtr_00011bcc == '\0') {
            *PTR_OSSchedLockNestingCtr_00011bcc = 1;
            OS_SchedLockTimeMeasStart_variant4();
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
            OS_Pend(auStack_40,param_1,6,param_2);
            uVar2 = cpu_sr_save_and_disable_irq_iram();
            OS_SchedLockTimeMeasStart();
            cVar3 = *puVar1 + -1;
            *puVar1 = cVar3;
            if (cVar3 == '\0') {
              OS_SchedLockTimeMeasStop_variant4();
            }
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
            OSSched();
            uVar2 = cpu_sr_save_and_disable_irq_iram();
            OS_SchedLockTimeMeasStart();
            iVar4 = *(int *)PTR_OSTCBCurPtr_00011bd0;
            cVar3 = *(char *)(iVar4 + 0x35);
            if (cVar3 == '\x01') {
              if (param_4 != (int *)0x0) {
                *param_4 = *(int *)(iVar4 + 0x40);
              }
              *param_5 = 0x61a9;
            }
            else if (cVar3 == '\0') {
              if (param_4 != (int *)0x0) {
                *param_4 = *(int *)(iVar4 + 0x40);
              }
              *param_5 = 0;
            }
            else if (cVar3 == '\x02') {
              if (param_4 != (int *)0x0) {
                *param_4 = *(int *)(iVar4 + 0x40);
              }
              *param_5 = 0x5dc2;
            }
            else {
              if (cVar3 != '\x03') {
                *param_5 = 0x6e2e;
                OS_SchedLockTimeMeasStop();
                cpu_sr_restore_irq_iram(uVar2);
                return 0;
              }
              if (param_4 != (int *)0x0) {
                *param_4 = 0;
              }
              *param_5 = 0x72d9;
            }
            iVar4 = param_1[8];
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar2);
            *param_5 = 0x6d63;
          }
        }
        else {
          param_1[8] = param_1[8] + -1;
          if (param_4 != (int *)0x0) {
            *param_4 = param_1[9];
          }
          iVar4 = param_1[8];
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          *param_5 = 0;
        }
      }
      else {
        *param_5 = 0x5dc4;
        iVar4 = 0;
      }
    }
    else {
      *param_5 = 0x5e25;
      iVar4 = 0;
    }
  }
  else {
    *param_5 = 0x61ae;
    iVar4 = 0;
  }
  return iVar4;
}


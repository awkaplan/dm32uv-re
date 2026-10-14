/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskStkChk @ 000129f4 (IRAM address; the boot stub copies these bytes from program flash 0x030c2614)
 * Size: 88 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskStkChk(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 sr;
  int iVar1;
  int *piVar2;
  
  if (*PTR_OSIntNestingCtr_00012afc == '\0') {
    if (param_2 == (int *)0x0) {
      *param_4 = 0x62d5;
    }
    else if (param_3 == (int *)0x0) {
      *param_4 = 0x62d5;
    }
    else {
      sr = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      if (param_1 == (int *)0x0) {
        param_1 = *(int **)PTR_OSTCBCurPtr_00012b00;
      }
      if (*param_1 == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_2 = 0;
        *param_3 = 0;
        *param_4 = 0x7152;
      }
      else if ((*(ushort *)(param_1 + 0xf) & 1) == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        *param_2 = 0;
        *param_3 = 0;
        *param_4 = 0x7154;
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(sr);
        piVar2 = (int *)param_1[9];
        iVar1 = 0;
        if (*piVar2 == 0) {
          do {
            piVar2 = piVar2 + 1;
            iVar1 = iVar1 + 1;
          } while (*piVar2 == 0);
        }
        else {
          iVar1 = 0;
        }
        *param_2 = iVar1;
        *param_3 = param_1[0xe] - iVar1;
        *param_4 = 0;
      }
    }
  }
  else {
    *param_4 = 0x7159;
  }
  return;
}


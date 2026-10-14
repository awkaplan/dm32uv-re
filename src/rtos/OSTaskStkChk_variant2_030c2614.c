/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSTaskStkChk_variant2 @ 030c2614 (file base 0x03000000; code starts at 0x03001000)
 * Size: 178 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskStkChk_variant2(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 sr;
  int iVar1;
  int *piVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_030c271c == '\0') {
    if (param_2 == (int *)0x0) {
      *param_4 = 0x62d5;
    }
    else if (param_3 == (int *)0x0) {
      *param_4 = 0x62d5;
    }
    else {
      sr = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      if (param_1 == (int *)0x0) {
        param_1 = (int *)*PTR_OSTCBCurPtr_030c2720;
      }
      if (*param_1 == 0) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
        *param_2 = 0;
        *param_3 = 0;
        *param_4 = 0x7152;
      }
      else if ((*(ushort *)(param_1 + 0xf) & 1) == 0) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
        *param_2 = 0;
        *param_3 = 0;
        *param_4 = 0x7154;
      }
      else {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
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


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSSemDel @ 00011e84 (IRAM address; the boot stub copies these bytes from program flash 0x030c1aa4)
 * Size: 306 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

short OSSemDel(int *param_1,ushort param_2,undefined4 *param_3)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  short sVar4;
  
  if (*PTR_OSIntNestingCtr_00011ef4 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_3 = 0x5dc3;
      sVar2 = 0;
    }
    else if (param_2 < 2) {
      if (*param_1 == iRam00011efc) {
        uVar3 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        sVar2 = (short)param_1[4];
        if (param_2 == 0) {
          if (sVar2 == 0) {
            func_0x00011e54(param_1);
            *(short *)PTR_DAT_000120c8 = *(short *)PTR_DAT_000120c8 + -1;
            func_0x00011d84(param_1);
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar3);
            sVar2 = 0;
            *param_3 = 0;
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar3);
            *param_3 = 0x715f;
          }
        }
        else if (param_2 == 1) {
          cVar1 = *PTR_OSSchedLockNestingCtr_000120cc;
          *PTR_OSSchedLockNestingCtr_000120cc = cVar1 + '\x01';
          if ((char)(cVar1 + '\x01') == '\x01') {
            OS_SchedLockTimeMeasStart_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
          uVar3 = func_0x0306ced4();
          for (sVar4 = sVar2; sVar4 != 0; sVar4 = sVar4 + -1) {
            sched_obj_state_reset_and_unlink(param_1,*(undefined4 *)(param_1[2] + 8),uVar3);
          }
          func_0x00011e54(param_1);
          *(short *)PTR_DAT_000120c8 = *(short *)PTR_DAT_000120c8 + -1;
          func_0x00011d84(param_1);
          uVar3 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *PTR_OSSchedLockNestingCtr_000120cc;
          *PTR_OSSchedLockNestingCtr_000120cc = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
          OSSched();
          *param_3 = 0;
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
          *param_3 = 0x5e25;
        }
      }
      else {
        *param_3 = 0x5dc4;
        sVar2 = 0;
      }
    }
    else {
      *param_3 = 0x5e25;
      sVar2 = 0;
    }
  }
  else {
    *param_3 = 0x32c9;
    sVar2 = 0;
  }
  return sVar2;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: radio_command_jumptable_dispatch_iram @ 00012c3c (IRAM address; the boot stub copies these bytes from program flash 0x030c285c)
 * Size: 218 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_command_jumptable_dispatch_iram(undefined *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*PTR_OSIntNestingCtr_00012cd8 == '\0') {
    if (param_1 == PTR_DAT_00012cdc) {
      *param_2 = 0x714c;
    }
    else if (param_1 == PTR_OSIntQTaskTCB_00012ce0) {
      *param_2 = 0x714d;
    }
    else {
      if (param_1 == (undefined *)0x0) {
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        param_1 = *(undefined **)PTR_OSTCBCurPtr_00012ce4;
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
      }
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_00012ce8;
      *PTR_OSSchedLockNestingCtr_00012ce8 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      if ((byte)param_1[0x36] < 8) {
                    /* WARNING: Could not recover jumptable at 0x00012cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(*(uint *)(DAT_00012cec + (uint)(byte)param_1[0x36] * 4) & 0xfffffffe))();
        return;
      }
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_00012ee4;
      *PTR_OSSchedLockNestingCtr_00012ee4 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
        if (*(short *)PTR_DAT_00012ee8 == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          irq_disable_save_and_release_reinit();
        }
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
      }
      *param_2 = 0x6e2d;
    }
  }
  else {
    *param_2 = 0x714e;
  }
  return;
}


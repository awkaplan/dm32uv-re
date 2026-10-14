/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: ucos_event_flag_ready_bits_dispatch @ 00012ff0 (IRAM address; the boot stub copies these bytes from program flash 0x030c2c10)
 * Size: 454 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ucos_event_flag_ready_bits_dispatch
               (int param_1,undefined4 param_2,undefined2 param_3,short param_4,undefined4 param_5,
               undefined4 *param_6)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_000130ac;
  *PTR_OSSchedLockNestingCtr_000130ac = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  if (param_1 == 0) {
    param_1 = *(int *)PTR_OSTCBCurPtr_000130bc;
  }
  *param_6 = 0;
  if (*(byte *)(param_1 + 0x36) < 8) {
    uVar3 = 1 << ((int)*(char *)(param_1 + 0x36) & 0x3fU);
    if ((uVar3 & 0xcc) != 0) {
      if (*(char *)(param_1 + 0x34) == '\x02') {
        work_item_advance_or_complete_and_unlink(0,param_1,param_2,param_3,param_5);
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *PTR_OSSchedLockNestingCtr_0001323c;
        *PTR_OSSchedLockNestingCtr_0001323c = cVar1 + -1;
        if ((char)(cVar1 + -1) == '\0') {
          OS_SchedLockTimeMeasStop_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        if (param_4 < 0) {
          return;
        }
        OSSched();
        return;
      }
      func_0x03069670(param_1 + 100,param_2,param_3,param_4,param_5,param_6);
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_0001323c;
      *PTR_OSSchedLockNestingCtr_0001323c = cVar1 + -1;
      if ((char)(cVar1 + -1) != '\0') {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        return;
      }
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_00013240 != 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        irq_disable_save_and_release_reinit();
        return;
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      return;
    }
    if ((uVar3 & 0x33) != 0) {
      func_0x03069670(param_1 + 100,param_2,param_3,param_4,param_5,param_6);
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_000130ac;
      *PTR_OSSchedLockNestingCtr_000130ac = cVar1 + -1;
      if ((char)(cVar1 + -1) != '\0') {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        return;
      }
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_000130b8 != 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        irq_disable_save_and_release_reinit();
        return;
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      return;
    }
  }
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *PTR_OSSchedLockNestingCtr_0001323c;
  *PTR_OSSchedLockNestingCtr_0001323c = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    OS_SchedLockTimeMeasStop_variant4();
    if (*(short *)PTR_DAT_00013240 == 0) {
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
  *param_6 = 0x6e2d;
  return;
}


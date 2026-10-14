/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSSemCreate @ 00011dbc (IRAM address; the boot stub copies these bytes from program flash 0x030c19dc)
 * Size: 152 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSSemCreate(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*PTR_OSIntNestingCtr_00011ef4 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      *param_4 = 0x5dc3;
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_00011ef8;
      *PTR_OSSchedLockNestingCtr_00011ef8 = cVar1 + '\x01';
      if ((char)(cVar1 + '\x01') == '\x01') {
        OS_SchedLockTimeMeasStart_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_1 = uRam00011efc;
      param_1[8] = param_3;
      param_1[9] = 0;
      param_1[1] = param_2;
      ucos3_pend_list_init(param_1 + 2);
      func_0x00011d9c(param_1);
      *psRam00011f00 = *psRam00011f00 + 1;
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_00011ef8;
      *PTR_OSSchedLockNestingCtr_00011ef8 = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      *param_4 = 0;
    }
  }
  else {
    *param_4 = 0x2ee1;
  }
  return;
}


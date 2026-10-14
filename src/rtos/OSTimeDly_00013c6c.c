/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTimeDly @ 00013c6c (IRAM address; the boot stub copies these bytes from program flash 0x030c388c)
 * Size: 242 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTimeDly(int param_1,ushort param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*PTR_OSIntNestingCtr_00013dc8 != '\0') {
    *param_3 = 0x7275;
    return;
  }
  if (*PTR_OSSchedLockNestingCtr_00013dcc != '\0') {
    *param_3 = 0x6d63;
    return;
  }
  if (param_2 == 2) {
LAB_00013caa:
    if (param_1 == 0) {
      *param_3 = 0x727e;
      return;
    }
LAB_00013cbe:
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *PTR_OSSchedLockNestingCtr_00013dcc;
    *PTR_OSSchedLockNestingCtr_00013dcc = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      OS_SchedLockTimeMeasStart_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    iVar3 = *(int *)PTR_OSTCBCurPtr_00013dd0;
    *(undefined1 *)(iVar3 + 0x36) = 1;
    func_0x000138e8(iVar3,param_1,param_2,param_3);
    if (*param_3 == 0) {
      OS_RdyListRemove(*(undefined4 *)PTR_OSTCBCurPtr_00013dd0);
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_00013dcc;
      *PTR_OSSchedLockNestingCtr_00013dcc = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
      OSSched();
      *param_3 = 0;
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq_iram();
      OS_SchedLockTimeMeasStart();
      cVar1 = *PTR_OSSchedLockNestingCtr_00013dcc;
      *PTR_OSSchedLockNestingCtr_00013dcc = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        OS_SchedLockTimeMeasStop_variant4();
      }
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 0) goto LAB_00013caa;
    }
    else {
      if (param_2 == 4) goto LAB_00013cbe;
      if (param_2 == 8) goto LAB_00013caa;
    }
    *param_3 = 0x5e25;
  }
  return;
}


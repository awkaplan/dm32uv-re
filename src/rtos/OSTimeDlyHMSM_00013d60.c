/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTimeDlyHMSM @ 00013d60 (IRAM address; the boot stub copies these bytes from program flash 0x030c3980)
 * Size: 460 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTimeDlyHMSM(uint param_1,uint param_2,uint param_3,uint param_4,ushort param_5,int *param_6)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xffff;
  param_3 = param_3 & 0xffff;
  if (*PTR_OSIntNestingCtr_00013dc8 != '\0') {
    *param_6 = 0x7275;
    return;
  }
  if (*PTR_OSSchedLockNestingCtr_00013dcc != '\0') {
    *param_6 = 0x6d63;
    return;
  }
  uVar4 = param_5 & 0xe;
  if (uVar4 == 2) {
LAB_00013db0:
    if ((((param_4 == 0) && (param_3 == 0)) && (param_2 == 0)) && (param_1 == 0)) {
      *param_6 = 0x727e;
      return;
    }
LAB_00013ddc:
    if ((param_5 & 0xffe1) == 0) {
      if ((param_5 & 0x10) == 0) {
        if (999 < param_4) {
          *param_6 = 0x727b;
          return;
        }
        if (0x3b < param_3) {
          *param_6 = 0x727a;
          return;
        }
        if (0x3b < param_2) {
          *param_6 = 0x7279;
          return;
        }
        if (99 < param_1) {
          *param_6 = 0x7278;
          return;
        }
      }
      else {
        if (9999 < param_2) {
          *param_6 = 0x7279;
          return;
        }
        if (999 < param_1) {
          *param_6 = 0x7278;
          return;
        }
      }
      uVar6 = *puRam00013f90;
      iVar5 = (uVar6 * (param_4 + 500 / uVar6)) / 1000 +
              (param_2 * 0x3c + param_3 + param_1 * 0xe10) * uVar6;
      if (iVar5 == 0) {
        *param_6 = 0x727e;
      }
      else {
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *PTR_OSSchedLockNestingCtr_00013f94;
        *PTR_OSSchedLockNestingCtr_00013f94 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          OS_SchedLockTimeMeasStart_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        iVar3 = *(int *)PTR_OSTCBCurPtr_00013f98;
        *(undefined1 *)(iVar3 + 0x36) = 1;
        func_0x000138e8(iVar3,iVar5,uVar4,param_6);
        if (*param_6 == 0) {
          OS_RdyListRemove(*(undefined4 *)PTR_OSTCBCurPtr_00013f98);
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *PTR_OSSchedLockNestingCtr_00013f94;
          *PTR_OSSchedLockNestingCtr_00013f94 = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          OSSched();
          *param_6 = 0;
        }
        else {
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *PTR_OSSchedLockNestingCtr_00013f94;
          *PTR_OSSchedLockNestingCtr_00013f94 = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
      }
    }
    else {
      *param_6 = 0x5e25;
    }
  }
  else {
    if (uVar4 < 3) {
      if ((param_5 & 0xe) == 0) goto LAB_00013db0;
    }
    else {
      if (uVar4 == 4) goto LAB_00013ddc;
      if (uVar4 == 8) goto LAB_00013db0;
    }
    *param_6 = 0x5e25;
  }
  return;
}


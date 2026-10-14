/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OSTaskCreate @ 00012dd8 (IRAM address; the boot stub copies these bytes from program flash 0x030c29f8)
 * Size: 504 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskCreate(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5__w,undefined4 *param_6,uint param_7,uint param_8,int param_9__w,int param_10,undefined4 param_11,int param_12__w,undefined4 *param_13)

{
  byte param_5 = (byte)param_5__w;
  undefined2 param_9 = (undefined2)param_9__w;
  ushort param_12 = (ushort)param_12__w;
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  if (*PTR_OSIntNestingCtr_00012ef0 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      *param_13 = 0x71ad;
    }
    else if (param_3 == 0) {
      *param_13 = 0x714f;
    }
    else if (param_6 == (undefined4 *)0x0) {
      *param_13 = 0x6e2f;
    }
    else if (param_8 < *puRam00012ef4) {
      *param_13 = 0x6e30;
    }
    else if (param_7 < param_8) {
      if (param_5 < 0x40) {
        if (param_5 == 0) {
          if (param_1 != (undefined4 *)PTR_OSIntQTaskTCB_00012ef8) {
            *param_13 = 0x6273;
            return;
          }
        }
        else if ((param_5 == 0x3f) && (param_1 != (undefined4 *)PTR_DAT_00012efc)) {
          *param_13 = 0x6273;
          return;
        }
        func_0x00012b84(param_1);
        *param_13 = 0;
        if (((param_12 & 3) == 3) && (param_8 != 0)) {
          uVar4 = 0;
          puVar3 = param_6;
          do {
            *puVar3 = 0;
            puVar3 = puVar3 + 1;
            uVar4 = uVar4 + 1;
          } while (uVar4 < param_8);
        }
        uVar2 = func_0x00010748(param_3,param_4,param_6,param_6 + param_7,param_8,param_12);
        param_1[10] = param_3;
        param_1[0xb] = param_4;
        param_1[8] = param_2;
        *(byte *)((int)param_1 + 0x37) = param_5;
        *param_1 = uVar2;
        param_1[2] = param_6 + param_7;
        param_1[0x15] = param_10;
        if (param_10 == 0) {
          param_1[0x16] = *(undefined4 *)PTR_DAT_00012f00;
        }
        else {
          param_1[0x16] = param_10;
        }
        param_1[1] = param_11;
        param_1[9] = param_6;
        param_1[0xe] = param_8;
        *(ushort *)(param_1 + 0xf) = param_12;
        param_1[0x1f] = 0;
        func_0x030695f0(param_1 + 0x19,param_9);
        func_0x00010718(param_1);
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *PTR_OSSchedLockNestingCtr_000130ac;
        *PTR_OSSchedLockNestingCtr_000130ac = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          OS_SchedLockTimeMeasStart_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        OS_PrioInsert(*(undefined1 *)((int)param_1 + 0x37));
        timer_object_register_into_bucket_list(param_1);
        func_0x00012b08(param_1);
        *(short *)PTR_DAT_000130b0 = *(short *)PTR_DAT_000130b0 + 1;
        if (*PTR_DAT_000130b4 == '\x01') {
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *PTR_OSSchedLockNestingCtr_000130ac;
          *PTR_OSSchedLockNestingCtr_000130ac = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          OSSched();
        }
        else {
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *PTR_OSSchedLockNestingCtr_000130ac;
          *PTR_OSSchedLockNestingCtr_000130ac = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
            if (*(short *)PTR_DAT_000130b8 == 0) {
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
        }
      }
      else {
        *param_13 = 0x6273;
      }
    }
    else {
      *param_13 = 0x6e31;
    }
  }
  else {
    *param_13 = 0x714a;
  }
  return;
}


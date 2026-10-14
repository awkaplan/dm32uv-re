/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: guarded_request_command_dispatch @ 0306a1b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 482 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4
guarded_request_command_dispatch
          (int *param_1,undefined4 param_2,short param_3,undefined2 *param_4,undefined4 *param_5,
          int *param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined1 auStack_44 [32];
  
  if (*(char *)PTR_OSIntNestingCtr_0306a264 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_6 = 0x5dc3;
      uVar5 = 0;
    }
    else if (param_4 == (undefined2 *)0x0) {
      *param_6 = 0x62d5;
      uVar5 = 0;
    }
    else if ((param_3 == 0) || (param_3 == -0x8000)) {
      if (*param_1 == DAT_0306a268) {
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = 0;
        }
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        uVar5 = queue_node_dequeue_and_free(param_1 + 8,param_4,param_5,param_6);
        puVar1 = PTR_OSSchedLockNestingCtr_0306a3fc;
        if (*param_6 == 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
        else if (param_3 < 0) {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          *param_6 = 0x61b0;
          uVar5 = 0;
        }
        else if (*(char *)PTR_OSSchedLockNestingCtr_0306a3fc == '\0') {
          *(undefined1 *)PTR_OSSchedLockNestingCtr_0306a3fc = 1;
          OS_SchedLockTimeMeasStart_variant4();
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          OS_Pend(auStack_44,param_1,5,param_2);
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar4 = *(char *)puVar1 + -1;
          *(char *)puVar1 = cVar4;
          if (cVar4 == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          OSSched();
          uVar2 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          iVar3 = *PTR_OSTCBCurPtr_0306a400;
          cVar4 = *(char *)(iVar3 + 0x35);
          if (cVar4 == '\x01') {
            *param_4 = 0;
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = *(undefined4 *)(*PTR_OSTCBCurPtr_0306a400 + 0x40);
            }
            *param_6 = 0x61a9;
            uVar5 = 0;
          }
          else if (cVar4 == '\0') {
            uVar5 = *(undefined4 *)(iVar3 + 0x5c);
            *param_4 = *(undefined2 *)(iVar3 + 0x60);
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = *(undefined4 *)(*PTR_OSTCBCurPtr_0306a400 + 0x40);
            }
            *param_6 = 0;
          }
          else if (cVar4 == '\x02') {
            *param_4 = 0;
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = *(undefined4 *)(*PTR_OSTCBCurPtr_0306a400 + 0x40);
            }
            *param_6 = 0x5dc2;
            uVar5 = 0;
          }
          else if (cVar4 == '\x03') {
            *param_4 = 0;
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = 0;
            }
            *param_6 = 0x72d9;
            uVar5 = 0;
          }
          else {
            *param_4 = 0;
            *param_6 = 0x6e2e;
            uVar5 = 0;
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          *param_6 = 0x6d63;
          uVar5 = 0;
        }
      }
      else {
        *param_6 = 0x5dc4;
        uVar5 = 0;
      }
    }
    else {
      *param_6 = 0x5e25;
      uVar5 = 0;
    }
  }
  else {
    *param_6 = 0x61ae;
    uVar5 = 0;
  }
  return uVar5;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scheduled_task_advance_or_requeue @ 03069ae0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 484 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scheduled_task_advance_or_requeue(int *param_1,short param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  
  if (*(char *)PTR_OSIntNestingCtr_03069bc0 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_3 = 0x5dc3;
    }
    else if ((param_2 == 0) || (param_2 == -0x8000)) {
      if (*param_1 == _DAT_03069bb8) {
        uVar2 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        if (param_1[8] == *PTR_OSTCBCurPtr_03069bc4) {
          cVar5 = *(char *)PTR_OSSchedLockNestingCtr_03069bbc;
          *(char *)PTR_OSSchedLockNestingCtr_03069bbc = cVar5 + '\x01';
          if ((char)(cVar5 + '\x01') == '\x01') {
            OS_SchedLockTimeMeasStart_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          iVar3 = CPU_TS_TmrRd();
          param_1[10] = iVar3;
          cVar5 = *(char *)((int)param_1 + 0x25) + -1;
          *(char *)((int)param_1 + 0x25) = cVar5;
          if (cVar5 == '\0') {
            if ((short)param_1[4] == 0) {
              param_1[8] = 0;
              *(undefined1 *)((int)param_1 + 0x25) = 0;
              uVar2 = cpu_sr_save_and_disable_irq_iram();
              OS_SchedLockTimeMeasStart();
              cVar5 = *(char *)PTR_OSSchedLockNestingCtr_03069dc0;
              *(char *)PTR_OSSchedLockNestingCtr_03069dc0 = cVar5 + -1;
              if ((char)(cVar5 + -1) == '\0') {
                OS_SchedLockTimeMeasStop_variant4();
                if (*(short *)PTR_DAT_03069dc4 == 0) {
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
              *param_3 = 0;
            }
            else {
              if (*(char *)(*PTR_OSTCBCurPtr_03069dc8 + 0x37) != (char)param_1[9]) {
                OS_RdyListRemove();
                puVar1 = PTR_OSTCBCurPtr_03069dc8;
                *(char *)(*PTR_OSTCBCurPtr_03069dc8 + 0x37) = (char)param_1[9];
                OS_PrioInsert();
                timer_object_register_into_bucket_list(*puVar1);
                *(undefined1 *)PTR_DAT_03069dcc = *(undefined1 *)(*puVar1 + 0x37);
              }
              iVar4 = *(int *)(param_1[2] + 8);
              param_1[8] = iVar4;
              *(undefined1 *)(param_1 + 9) = *(undefined1 *)(iVar4 + 0x37);
              *(undefined1 *)((int)param_1 + 0x25) = 1;
              work_item_advance_or_complete_and_unlink(param_1,iVar4,0,0,iVar3);
              uVar2 = cpu_sr_save_and_disable_irq_iram();
              OS_SchedLockTimeMeasStart();
              cVar5 = *(char *)PTR_OSSchedLockNestingCtr_03069dc0;
              *(char *)PTR_OSSchedLockNestingCtr_03069dc0 = cVar5 + -1;
              if ((char)(cVar5 + -1) == '\0') {
                OS_SchedLockTimeMeasStop_variant4();
              }
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(uVar2);
              if (-1 < param_2) {
                OSSched();
              }
              *param_3 = 0;
            }
          }
          else {
            uVar2 = cpu_sr_save_and_disable_irq_iram();
            OS_SchedLockTimeMeasStart();
            cVar5 = *(char *)PTR_OSSchedLockNestingCtr_03069bbc;
            *(char *)PTR_OSSchedLockNestingCtr_03069bbc = cVar5 + -1;
            if ((char)(cVar5 + -1) == '\0') {
              OS_SchedLockTimeMeasStop_variant4();
              if (*(short *)PTR_DAT_03069bc8 == 0) {
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
            *param_3 = 0x5783;
          }
        }
        else {
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar2);
          *param_3 = 0x5781;
        }
      }
      else {
        *param_3 = 0x5dc4;
      }
    }
    else {
      *param_3 = 0x5e25;
    }
  }
  else {
    *param_3 = 0x620e;
  }
  return;
}


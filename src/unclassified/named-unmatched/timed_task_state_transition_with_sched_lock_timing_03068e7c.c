/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timed_task_state_transition_with_sched_lock_timing @ 03068e7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 498 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

short timed_task_state_transition_with_sched_lock_timing
                (int *param_1,ushort param_2,undefined4 *param_3)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  short sVar4;
  
  if (*(char *)PTR_OSIntNestingCtr_03068ed8 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_3 = 0x5dc3;
      sVar2 = 0;
    }
    else if (param_2 < 2) {
      if (*param_1 == _DAT_03068ee0) {
        uVar3 = cpu_sr_save_and_disable_irq_iram();
        OS_SchedLockTimeMeasStart();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069070;
        *(char *)PTR_OSSchedLockNestingCtr_03069070 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          OS_SchedLockTimeMeasStart_variant4();
        }
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar3);
        sVar2 = (short)param_1[4];
        if (param_2 == 0) {
          if (sVar2 == 0) {
            dlist_unlink_timed(param_1);
            *(short *)PTR_DAT_03069074 = *(short *)PTR_DAT_03069074 + -1;
            FUN_03068d6c(param_1);
            uVar3 = cpu_sr_save_and_disable_irq_iram();
            OS_SchedLockTimeMeasStart();
            cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069070;
            *(char *)PTR_OSSchedLockNestingCtr_03069070 = cVar1 + -1;
            if ((char)(cVar1 + -1) == '\0') {
              OS_SchedLockTimeMeasStop_variant4();
              if (*(short *)PTR_DAT_03069078 == 0) {
                OS_SchedLockTimeMeasStop();
                cpu_sr_restore_irq_iram(uVar3);
              }
              else {
                OS_SchedLockTimeMeasStop();
                cpu_sr_restore_irq_iram(uVar3);
                irq_disable_save_and_release_reinit();
              }
            }
            else {
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(uVar3);
            }
            sVar2 = 0;
            *param_3 = 0;
          }
          else {
            uVar3 = cpu_sr_save_and_disable_irq_iram();
            OS_SchedLockTimeMeasStart();
            cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069070;
            *(char *)PTR_OSSchedLockNestingCtr_03069070 = cVar1 + -1;
            if ((char)(cVar1 + -1) == '\0') {
              OS_SchedLockTimeMeasStop_variant4();
              if (*(short *)PTR_DAT_03069078 == 0) {
                OS_SchedLockTimeMeasStop();
                cpu_sr_restore_irq_iram(uVar3);
              }
              else {
                OS_SchedLockTimeMeasStop();
                cpu_sr_restore_irq_iram(uVar3);
                irq_disable_save_and_release_reinit();
              }
            }
            else {
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(uVar3);
            }
            *param_3 = 0x715f;
          }
        }
        else if (param_2 == 1) {
          uVar3 = CPU_TS_TmrRd();
          for (sVar4 = sVar2; sVar4 != 0; sVar4 = sVar4 + -1) {
            sched_obj_state_reset_and_unlink(param_1,*(undefined4 *)(param_1[2] + 8),uVar3);
          }
          dlist_unlink_timed(param_1);
          *(short *)PTR_DAT_03069074 = *(short *)PTR_DAT_03069074 + -1;
          FUN_03068d6c(param_1);
          uVar3 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069070;
          *(char *)PTR_OSSchedLockNestingCtr_03069070 = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
          }
          OS_SchedLockTimeMeasStop();
          cpu_sr_restore_irq_iram(uVar3);
          OSSched();
          *param_3 = 0;
        }
        else {
          uVar3 = cpu_sr_save_and_disable_irq_iram();
          OS_SchedLockTimeMeasStart();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_03069070;
          *(char *)PTR_OSSchedLockNestingCtr_03069070 = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            OS_SchedLockTimeMeasStop_variant4();
            if (*(short *)PTR_DAT_03069078 == 0) {
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(uVar3);
            }
            else {
              OS_SchedLockTimeMeasStop();
              cpu_sr_restore_irq_iram(uVar3);
              irq_disable_save_and_release_reinit();
            }
          }
          else {
            OS_SchedLockTimeMeasStop();
            cpu_sr_restore_irq_iram(uVar3);
          }
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


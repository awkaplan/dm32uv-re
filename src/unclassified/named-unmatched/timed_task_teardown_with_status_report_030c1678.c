/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timed_task_teardown_with_status_report @ 030c1678 (file base 0x03000000; code starts at 0x03001000)
 * Size: 420 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int timed_task_teardown_with_status_report
              (int *param_1,undefined4 param_2,short param_3,int *param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  undefined1 auStack_40 [32];
  
  if (*(char *)PTR_OSIntNestingCtr_030c17e4 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_5 = 0x5dc3;
      iVar4 = 0;
    }
    else if ((param_3 == 0) || (param_3 == -0x8000)) {
      if (*param_1 == _DAT_030c17e8) {
        if (param_4 != (int *)0x0) {
          *param_4 = 0;
        }
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        puVar1 = PTR_OSSchedLockNestingCtr_030c17ec;
        if (param_1[8] == 0) {
          iVar4 = 0;
          if (param_3 < 0) {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
            *param_5 = 0x61b0;
          }
          else if (*(char *)PTR_OSSchedLockNestingCtr_030c17ec == '\0') {
            *(undefined1 *)PTR_OSSchedLockNestingCtr_030c17ec = 1;
            conditional_cached_value_refresh();
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
            OS_Pend_variant2(auStack_40,param_1,6,param_2);
            uVar2 = cpu_sr_save_and_disable_irq_variant2();
            OS_SchedLockTimeMeasStart_variant3();
            cVar3 = *(char *)puVar1 + -1;
            *(char *)puVar1 = cVar3;
            if (cVar3 == '\0') {
              ucos_crit_section_nest_exit_with_lock_time_track();
            }
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
            OS_Sched();
            uVar2 = cpu_sr_save_and_disable_irq_variant2();
            OS_SchedLockTimeMeasStart_variant3();
            iVar4 = *PTR_OSTCBCurPtr_030c17f0;
            cVar3 = *(char *)(iVar4 + 0x35);
            if (cVar3 == '\x01') {
              if (param_4 != (int *)0x0) {
                *param_4 = *(int *)(iVar4 + 0x40);
              }
              *param_5 = 0x61a9;
            }
            else if (cVar3 == '\0') {
              if (param_4 != (int *)0x0) {
                *param_4 = *(int *)(iVar4 + 0x40);
              }
              *param_5 = 0;
            }
            else if (cVar3 == '\x02') {
              if (param_4 != (int *)0x0) {
                *param_4 = *(int *)(iVar4 + 0x40);
              }
              *param_5 = 0x5dc2;
            }
            else {
              if (cVar3 != '\x03') {
                *param_5 = 0x6e2e;
                OS_SchedLockTimeMeasStop_variant3();
                cpu_sr_restore_irq_variant2(uVar2);
                return 0;
              }
              if (param_4 != (int *)0x0) {
                *param_4 = 0;
              }
              *param_5 = 0x72d9;
            }
            iVar4 = param_1[8];
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
          }
          else {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
            *param_5 = 0x6d63;
          }
        }
        else {
          param_1[8] = param_1[8] + -1;
          if (param_4 != (int *)0x0) {
            *param_4 = param_1[9];
          }
          iVar4 = param_1[8];
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          *param_5 = 0;
        }
      }
      else {
        *param_5 = 0x5dc4;
        iVar4 = 0;
      }
    }
    else {
      *param_5 = 0x5e25;
      iVar4 = 0;
    }
  }
  else {
    *param_5 = 0x61ae;
    iVar4 = 0;
  }
  return iVar4;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timed_task_advance_with_timestamp_delta_tracking @ 030c2340 (file base 0x03000000; code starts at 0x03001000)
 * Size: 390 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

int timed_task_advance_with_timestamp_delta_tracking
              (undefined4 param_1,short param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(char *)PTR_OSIntNestingCtr_030c23d0 == '\0') {
    if ((param_2 == 0) || (param_2 == -0x8000)) {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = 0;
      }
      uVar2 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      puVar1 = PTR_OSSchedLockNestingCtr_030c25c4;
      iVar5 = *PTR_OSTCBCurPtr_030c23c8;
      if (*(int *)(iVar5 + 0x44) == 0) {
        if (param_2 < 0) {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          *param_4 = 0x61b0;
          iVar7 = 0;
        }
        else if (*(char *)PTR_OSSchedLockNestingCtr_030c25c4 == '\0') {
          *(undefined1 *)PTR_OSSchedLockNestingCtr_030c25c4 = 1;
          conditional_cached_value_refresh();
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          OS_Pend_variant2(0,0,7,param_1);
          uVar2 = cpu_sr_save_and_disable_irq_variant2();
          OS_SchedLockTimeMeasStart_variant3();
          cVar4 = *(char *)puVar1 + -1;
          *(char *)puVar1 = cVar4;
          if (cVar4 == '\0') {
            ucos_crit_section_nest_exit_with_lock_time_track();
          }
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          OS_Sched();
          uVar2 = cpu_sr_save_and_disable_irq_variant2();
          OS_SchedLockTimeMeasStart_variant3();
          iVar5 = *PTR_OSTCBCurPtr_030c25c8;
          cVar4 = *(char *)(iVar5 + 0x35);
          if (cVar4 == '\x01') {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = *(undefined4 *)(iVar5 + 0x40);
            }
            *param_4 = 0x61a9;
          }
          else if (cVar4 == '\0') {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = *(undefined4 *)(iVar5 + 0x40);
              iVar5 = func_0x0611caf4();
              iVar7 = *PTR_OSTCBCurPtr_030c25c8;
              uVar3 = iVar5 - *(int *)(iVar7 + 0x40);
              *(uint *)(iVar7 + 0xa4) = uVar3;
              if (*(uint *)(iVar7 + 0xa8) < uVar3) {
                *(uint *)(iVar7 + 0xa8) = uVar3;
              }
            }
            *param_4 = 0;
          }
          else if (cVar4 == '\x03') {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = 0;
            }
            *param_4 = 0x72d9;
          }
          else {
            *param_4 = 0x6e2e;
          }
          iVar7 = *(int *)(*PTR_OSTCBCurPtr_030c25c8 + 0x44);
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
        }
        else {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          *param_4 = 0x6d63;
          iVar7 = 0;
        }
      }
      else {
        iVar7 = *(int *)(iVar5 + 0x44) + -1;
        *(int *)(iVar5 + 0x44) = iVar7;
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = *(undefined4 *)(iVar5 + 0x40);
        }
        iVar5 = func_0x0611caf4();
        iVar6 = *PTR_OSTCBCurPtr_030c23c8;
        uVar3 = iVar5 - *(int *)(iVar6 + 0x40);
        *(uint *)(iVar6 + 0xa4) = uVar3;
        if (*(uint *)(iVar6 + 0xa8) < uVar3) {
          *(uint *)(iVar6 + 0xa8) = uVar3;
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        *param_4 = 0;
      }
    }
    else {
      *param_4 = 0x5e25;
      iVar7 = 0;
    }
  }
  else {
    *param_4 = 0x61ae;
    iVar7 = 0;
  }
  return iVar7;
}


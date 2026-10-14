/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ucos_sem_pend_wait @ 030c1fe4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 424 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
ucos_sem_pend_wait(undefined4 param_1,short param_2,undefined2 *param_3,int *param_4,int *param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  
  if (*(char *)PTR_OSIntNestingCtr_030c209c == '\0') {
    if (param_3 == (undefined2 *)0x0) {
      *param_5 = 0x62d5;
      uVar8 = 0;
    }
    else if ((param_2 == 0) || (param_2 == -0x8000)) {
      if (param_4 != (int *)0x0) {
        *param_4 = 0;
      }
      uVar3 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      uVar8 = func_0x06119220(*PTR_OSTCBCurPtr_030c20a0 + 100,param_3,param_4,param_5);
      puVar2 = PTR_OSSchedLockNestingCtr_030c2214;
      puVar1 = PTR_OSTCBCurPtr_030c20a0;
      if (*param_5 == 0) {
        if (param_4 != (int *)0x0) {
          iVar7 = *PTR_OSTCBCurPtr_030c20a0;
          iVar4 = func_0x0611caf4();
          *(int *)(iVar7 + 0x74) = iVar4 - *param_4;
          iVar4 = *puVar1;
          if (*(uint *)(iVar4 + 0x78) < *(uint *)(iVar4 + 0x74)) {
            *(uint *)(iVar4 + 0x78) = *(uint *)(iVar4 + 0x74);
          }
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
      }
      else if (param_2 < 0) {
        *param_5 = 0x61b0;
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
        uVar8 = 0;
      }
      else if (*(char *)PTR_OSSchedLockNestingCtr_030c2214 == '\0') {
        *(undefined1 *)PTR_OSSchedLockNestingCtr_030c2214 = 1;
        conditional_cached_value_refresh();
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
        OS_Pend_variant2(0,0,2,param_1);
        uVar3 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar6 = *(char *)puVar2 + -1;
        *(char *)puVar2 = cVar6;
        if (cVar6 == '\0') {
          ucos_crit_section_nest_exit_with_lock_time_track();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
        OS_Sched();
        uVar3 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        iVar4 = *PTR_OSTCBCurPtr_030c2218;
        if (*(char *)(iVar4 + 0x35) == '\0') {
          uVar8 = *(undefined4 *)(iVar4 + 0x5c);
          *param_3 = *(undefined2 *)(iVar4 + 0x60);
          puVar1 = PTR_OSTCBCurPtr_030c2218;
          if (param_4 != (int *)0x0) {
            *param_4 = *(int *)(*PTR_OSTCBCurPtr_030c2218 + 0x40);
            iVar4 = func_0x0611caf4();
            iVar7 = *puVar1;
            uVar5 = iVar4 - *(int *)(iVar7 + 0x40);
            *(uint *)(iVar7 + 0x74) = uVar5;
            if (*(uint *)(iVar7 + 0x78) < uVar5) {
              *(uint *)(iVar7 + 0x78) = uVar5;
            }
          }
          *param_5 = 0;
        }
        else if (*(char *)(iVar4 + 0x35) == '\x01') {
          *param_3 = 0;
          if (param_4 != (int *)0x0) {
            *param_4 = 0;
          }
          *param_5 = 0x61a9;
          uVar8 = 0;
        }
        else {
          *param_3 = 0;
          if (param_4 != (int *)0x0) {
            *param_4 = *(int *)(*PTR_OSTCBCurPtr_030c2218 + 0x40);
          }
          *param_5 = 0x72d9;
          uVar8 = 0;
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
      }
      else {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar3);
        *param_5 = 0x6d63;
        uVar8 = 0;
      }
    }
    else {
      *param_5 = 0x5e25;
      uVar8 = 0;
    }
  }
  else {
    *param_5 = 0x61ae;
    uVar8 = 0;
  }
  return uVar8;
}


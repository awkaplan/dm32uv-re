/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OSTaskCreate_variant2 @ 030c29f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 504 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OSTaskCreate_variant2
               (undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,byte param_5,
               undefined4 *param_6,uint param_7,uint param_8,undefined2 param_9,int param_10,
               undefined4 param_11,ushort param_12,undefined4 *param_13)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  if (*(char *)PTR_OSIntNestingCtr_030c2b10 == '\0') {
    if (param_1 == (undefined4 *)0x0) {
      *param_13 = 0x71ad;
    }
    else if (param_3 == 0) {
      *param_13 = 0x714f;
    }
    else if (param_6 == (undefined4 *)0x0) {
      *param_13 = 0x6e2f;
    }
    else if (param_8 < (uint)*PTR_LAB_030c2b14) {
      *param_13 = 0x6e30;
    }
    else if (param_7 < param_8) {
      if (param_5 < 0x40) {
        if (param_5 == 0) {
          if (param_1 != _DAT_030c2b18) {
            *param_13 = 0x6273;
            return;
          }
        }
        else if ((param_5 == 0x3f) && (param_1 != _DAT_030c2b1c)) {
          *param_13 = 0x6273;
          return;
        }
        FUN_030c27a4(param_1);
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
        uVar2 = FUN_030c0368(param_3,param_4,param_6,param_6 + param_7,param_8,param_12);
        param_1[10] = param_3;
        param_1[0xb] = param_4;
        param_1[8] = param_2;
        *(byte *)((int)param_1 + 0x37) = param_5;
        *param_1 = uVar2;
        param_1[2] = param_6 + param_7;
        param_1[0x15] = param_10;
        if (param_10 == 0) {
          param_1[0x16] = *PTR_DAT_030c2b20;
        }
        else {
          param_1[0x16] = param_10;
        }
        param_1[1] = param_11;
        param_1[9] = param_6;
        param_1[0xe] = param_8;
        *(ushort *)(param_1 + 0xf) = param_12;
        param_1[0x1f] = 0;
        func_0x06119210(param_1 + 0x19,param_9);
        FUN_030c0338(param_1);
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2ccc;
        *(char *)PTR_OSSchedLockNestingCtr_030c2ccc = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          conditional_cached_value_refresh();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        FUN_030c1634(*(undefined1 *)((int)param_1 + 0x37));
        slot_list_push_back_b(param_1);
        registry_list_push_front_b(param_1);
        *(short *)PTR_DAT_030c2cd0 = *(short *)PTR_DAT_030c2cd0 + 1;
        if (*(char *)PTR_DAT_030c2cd4 == '\x01') {
          uVar2 = cpu_sr_save_and_disable_irq_variant2();
          OS_SchedLockTimeMeasStart_variant3();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2ccc;
          *(char *)PTR_OSSchedLockNestingCtr_030c2ccc = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            ucos_crit_section_nest_exit_with_lock_time_track();
          }
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          OS_Sched();
        }
        else {
          uVar2 = cpu_sr_save_and_disable_irq_variant2();
          OS_SchedLockTimeMeasStart_variant3();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c2ccc;
          *(char *)PTR_OSSchedLockNestingCtr_030c2ccc = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            ucos_crit_section_nest_exit_with_lock_time_track();
            if (*(short *)PTR_DAT_030c2cd8 == 0) {
              OS_SchedLockTimeMeasStop_variant3();
              cpu_sr_restore_irq_variant2(uVar2);
            }
            else {
              OS_SchedLockTimeMeasStop_variant3();
              cpu_sr_restore_irq_variant2(uVar2);
              ucos_lock_release_cleanup_and_notify();
            }
          }
          else {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar2);
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


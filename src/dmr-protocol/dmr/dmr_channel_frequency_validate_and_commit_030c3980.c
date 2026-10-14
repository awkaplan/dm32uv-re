/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_channel_frequency_validate_and_commit @ 030c3980 (file base 0x03000000; code starts at 0x03001000)
 * Size: 460 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_channel_frequency_validate_and_commit
               (uint param_1,uint param_2,uint param_3,uint param_4,ushort param_5,int *param_6)

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
  if (*(char *)PTR_OSIntNestingCtr_030c39e8 != '\0') {
    *param_6 = 0x7275;
    return;
  }
  if (*(char *)PTR_OSSchedLockNestingCtr_030c39ec != '\0') {
    *param_6 = 0x6d63;
    return;
  }
  uVar4 = param_5 & 0xe;
  if (uVar4 == 2) {
LAB_030c39d0:
    if ((((param_4 == 0) && (param_3 == 0)) && (param_2 == 0)) && (param_1 == 0)) {
      *param_6 = 0x727e;
      return;
    }
LAB_030c39fc:
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
      uVar6 = *PTR_LAB_030c3bb0;
      iVar5 = (uVar6 * (param_4 + 500 / uVar6)) / 1000 +
              (param_2 * 0x3c + param_3 + param_1 * 0xe10) * uVar6;
      if (iVar5 == 0) {
        *param_6 = 0x727e;
      }
      else {
        uVar2 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3bb4;
        *(char *)PTR_OSSchedLockNestingCtr_030c3bb4 = cVar1 + '\x01';
        if ((char)(cVar1 + '\x01') == '\x01') {
          conditional_cached_value_refresh();
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(uVar2);
        iVar3 = *PTR_OSTCBCurPtr_030c3bb8;
        *(undefined1 *)(iVar3 + 0x36) = 1;
        timer_entry_insert_hash_bucketed_list_030c(iVar3,iVar5,uVar4,param_6);
        if (*param_6 == 0) {
          linked_list_slot_free_and_unlink(*PTR_OSTCBCurPtr_030c3bb8);
          uVar2 = cpu_sr_save_and_disable_irq_variant2();
          OS_SchedLockTimeMeasStart_variant3();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3bb4;
          *(char *)PTR_OSSchedLockNestingCtr_030c3bb4 = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            ucos_crit_section_nest_exit_with_lock_time_track();
          }
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
          OS_Sched();
          *param_6 = 0;
        }
        else {
          uVar2 = cpu_sr_save_and_disable_irq_variant2();
          OS_SchedLockTimeMeasStart_variant3();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3bb4;
          *(char *)PTR_OSSchedLockNestingCtr_030c3bb4 = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            ucos_crit_section_nest_exit_with_lock_time_track();
          }
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar2);
        }
      }
    }
    else {
      *param_6 = 0x5e25;
    }
  }
  else {
    if (uVar4 < 3) {
      if ((param_5 & 0xe) == 0) goto LAB_030c39d0;
    }
    else {
      if (uVar4 == 4) goto LAB_030c39fc;
      if (uVar4 == 8) goto LAB_030c39d0;
    }
    *param_6 = 0x5e25;
  }
  return;
}


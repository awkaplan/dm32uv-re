/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_list_item_remove_by_handle_variant @ 030c1aa4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 306 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

short radio_list_item_remove_by_handle_variant(int *param_1,ushort param_2,undefined4 *param_3)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  short sVar4;
  
  if (*(char *)PTR_OSIntNestingCtr_030c1b14 == '\0') {
    if (param_1 == (int *)0x0) {
      *param_3 = 0x5dc3;
      sVar2 = 0;
    }
    else if (param_2 < 2) {
      if (*param_1 == _DAT_030c1b1c) {
        uVar3 = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        sVar2 = (short)param_1[4];
        if (param_2 == 0) {
          if (sVar2 == 0) {
            dlist_unlink_radio_variant(param_1);
            *(short *)PTR_DAT_030c1ce8 = *(short *)PTR_DAT_030c1ce8 + -1;
            FUN_030c19a4(param_1);
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar3);
            sVar2 = 0;
            *param_3 = 0;
          }
          else {
            OS_SchedLockTimeMeasStop_variant3();
            cpu_sr_restore_irq_variant2(uVar3);
            *param_3 = 0x715f;
          }
        }
        else if (param_2 == 1) {
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1cec;
          *(char *)PTR_OSSchedLockNestingCtr_030c1cec = cVar1 + '\x01';
          if ((char)(cVar1 + '\x01') == '\x01') {
            conditional_cached_value_refresh();
          }
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar3);
          uVar3 = func_0x0611caf4();
          for (sVar4 = sVar2; sVar4 != 0; sVar4 = sVar4 + -1) {
            message_phase_advance_dual_path(param_1,*(undefined4 *)(param_1[2] + 8),uVar3);
          }
          dlist_unlink_radio_variant(param_1);
          *(short *)PTR_DAT_030c1ce8 = *(short *)PTR_DAT_030c1ce8 + -1;
          FUN_030c19a4(param_1);
          uVar3 = cpu_sr_save_and_disable_irq_variant2();
          OS_SchedLockTimeMeasStart_variant3();
          cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c1cec;
          *(char *)PTR_OSSchedLockNestingCtr_030c1cec = cVar1 + -1;
          if ((char)(cVar1 + -1) == '\0') {
            ucos_crit_section_nest_exit_with_lock_time_track();
          }
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar3);
          OS_Sched();
          *param_3 = 0;
        }
        else {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(uVar3);
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


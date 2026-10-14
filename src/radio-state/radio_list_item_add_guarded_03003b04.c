/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_list_item_add_guarded @ 03003b04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 242 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_list_item_add_guarded(int param_1,ushort param_2,int *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)PTR_DAT_03003bf8 != '\0') {
    *param_3 = 0x7275;
    return;
  }
  if (*(char *)PTR_LAB_03003bfc != '\0') {
    *param_3 = 0x6d63;
    return;
  }
  if (param_2 == 2) {
LAB_03003b42:
    if (param_1 == 0) {
      *param_3 = 0x727e;
      return;
    }
LAB_03003b56:
    uVar2 = cpu_sr_save_and_disable_irq();
    OS_SchedLockTimeMeasStart_variant2();
    cVar1 = *(char *)PTR_LAB_03003bfc;
    *(char *)PTR_LAB_03003bfc = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      ucos_timer_live_count_decrement_hook();
    }
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar2);
    iVar3 = *PTR_DAT_03003c00;
    *(undefined1 *)(iVar3 + 0x36) = 1;
    timer_entry_insert_hash_bucketed_list_0300(iVar3,param_1,param_2,param_3);
    if (*param_3 == 0) {
      list_node_unlink_and_free_slot(*PTR_DAT_03003c00);
      uVar2 = cpu_sr_save_and_disable_irq();
      OS_SchedLockTimeMeasStart_variant2();
      cVar1 = *(char *)PTR_LAB_03003bfc;
      *(char *)PTR_LAB_03003bfc = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track_variant2();
      }
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      bounded_queue_lock_release_pair_variant();
      *param_3 = 0;
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq();
      OS_SchedLockTimeMeasStart_variant2();
      cVar1 = *(char *)PTR_LAB_03003bfc;
      *(char *)PTR_LAB_03003bfc = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track_variant2();
      }
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 0) goto LAB_03003b42;
    }
    else {
      if (param_2 == 4) goto LAB_03003b56;
      if (param_2 == 8) goto LAB_03003b42;
    }
    *param_3 = 0x5e25;
  }
  return;
}


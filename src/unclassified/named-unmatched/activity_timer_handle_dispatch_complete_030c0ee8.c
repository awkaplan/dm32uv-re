/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: activity_timer_handle_dispatch_complete @ 030c0ee8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
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

void activity_timer_handle_dispatch_complete(int *param_1)

{
  undefined4 sr;
  int iVar1;
  int iVar2;
  
  if (*(char *)PTR_DAT_030c0fd0 == '\x01') {
    sr = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    iVar2 = *param_1;
    if (iVar2 == 0) {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(sr);
    }
    else if (iVar2 == _DAT_030c0fd4) {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(sr);
    }
    else {
      if ((*(int *)(iVar2 + 0x58) != 0) &&
         (iVar1 = *(int *)(iVar2 + 0x58) + -1, *(int *)(iVar2 + 0x58) = iVar1, iVar1 != 0)) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
        return;
      }
      if (*(ushort *)(param_1 + 2) < 2) {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
      }
      else if (*(char *)PTR_OSSchedLockNestingCtr_030c0fcc == '\0') {
        queued_event_list_swap_or_rotate_head(param_1);
        iVar2 = *param_1;
        if (*(int *)(iVar2 + 0x54) == 0) {
          *(undefined4 *)(iVar2 + 0x58) = *PTR_DAT_030c0fd8;
        }
        else {
          *(int *)(iVar2 + 0x58) = *(int *)(iVar2 + 0x54);
        }
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
      }
      else {
        OS_SchedLockTimeMeasStop_variant3();
        cpu_sr_restore_irq_variant2(sr);
      }
    }
  }
  return;
}


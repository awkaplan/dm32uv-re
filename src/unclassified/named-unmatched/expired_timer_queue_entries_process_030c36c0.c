/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: expired_timer_queue_entries_process @ 030c36c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 376 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void expired_timer_queue_entries_process(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar4 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c37e0;
  *(char *)PTR_OSSchedLockNestingCtr_030c37e0 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    conditional_cached_value_refresh();
  }
  OS_SchedLockTimeMeasStop_variant3();
  cpu_sr_restore_irq_variant2(uVar4);
  iVar5 = func_0x0611caf4();
  uVar7 = *PTR_DAT_030c37e4 + 1;
  *PTR_DAT_030c37e4 = uVar7;
  puVar3 = PTR_DAT_030c37e4;
  iVar6 = PTR_DAT_030c37d0
          [(uVar7 - (uVar7 / *(ushort *)PTR_LAB_030c37d8) * (uint)*(ushort *)PTR_LAB_030c37d8 &
           0xffff) * 2];
  while (iVar9 = iVar6, iVar9 != 0) {
    iVar6 = *(int *)(iVar9 + 0x14);
    bVar2 = *(byte *)(iVar9 + 0x36);
    if (bVar2 == 3) {
      iVar8 = *puVar3;
      *(int *)(iVar9 + 0x50) = *(int *)(iVar9 + 0x4c) - iVar8;
      if (*(int *)(iVar9 + 0x4c) != iVar8) break;
      *(undefined4 *)(iVar9 + 0x5c) = 0;
      *(undefined2 *)(iVar9 + 0x60) = 0;
      uVar4 = func_0x0611caf4();
      *(undefined4 *)(iVar9 + 0x40) = uVar4;
      pend_list_drain_and_clear(iVar9);
      queued_timer_event_dispatch_if_not_flagged(iVar9);
      *(undefined1 *)(iVar9 + 0x36) = 0;
      *(undefined1 *)(iVar9 + 0x35) = 3;
      *(undefined1 *)(iVar9 + 0x34) = 0;
    }
    else if (bVar2 < 4) {
      if (bVar2 == 1) {
        iVar8 = *puVar3;
        *(int *)(iVar9 + 0x50) = *(int *)(iVar9 + 0x4c) - iVar8;
        if (*(int *)(iVar9 + 0x4c) != iVar8) break;
        *(undefined1 *)(iVar9 + 0x36) = 0;
        queued_timer_event_dispatch_if_not_flagged(iVar9);
      }
    }
    else if (bVar2 == 5) {
      iVar8 = *puVar3;
      *(int *)(iVar9 + 0x50) = *(int *)(iVar9 + 0x4c) - iVar8;
      if (*(int *)(iVar9 + 0x4c) != iVar8) break;
      *(undefined1 *)(iVar9 + 0x36) = 4;
      queued_event_list_unlink(iVar9);
    }
    else if (bVar2 == 7) {
      iVar8 = *puVar3;
      *(int *)(iVar9 + 0x50) = *(int *)(iVar9 + 0x4c) - iVar8;
      if (*(int *)(iVar9 + 0x4c) != iVar8) break;
      *(undefined4 *)(iVar9 + 0x5c) = 0;
      *(undefined2 *)(iVar9 + 0x60) = 0;
      uVar4 = func_0x0611caf4();
      *(undefined4 *)(iVar9 + 0x40) = uVar4;
      pend_list_drain_and_clear(iVar9);
      queued_event_list_unlink(iVar9);
      *(undefined1 *)(iVar9 + 0x36) = 4;
      *(undefined1 *)(iVar9 + 0x35) = 3;
      *(undefined1 *)(iVar9 + 0x34) = 0;
    }
  }
  iVar6 = func_0x0611caf4();
  if ((uint)*PTR_DAT_030c387c < (uint)(iVar6 - iVar5)) {
    *PTR_DAT_030c387c = iVar6 - iVar5;
  }
  uVar4 = cpu_sr_save_and_disable_irq_variant2();
  OS_SchedLockTimeMeasStart_variant3();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_030c3880;
  *(char *)PTR_OSSchedLockNestingCtr_030c3880 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    ucos_crit_section_nest_exit_with_lock_time_track();
    if (*(short *)PTR_DAT_030c3884 == 0) {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar4);
    }
    else {
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar4);
      ucos_lock_release_cleanup_and_notify();
    }
  }
  else {
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar4);
  }
  return;
}


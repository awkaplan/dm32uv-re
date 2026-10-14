/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_TickListUpdate @ 03003978 (file base 0x03000000; code starts at 0x03001000)
 * Size: 332 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_TickListUpdate(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar4 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  cVar1 = *(char *)PTR_LAB_03003ac4;
  *(char *)PTR_LAB_03003ac4 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    ucos_timer_live_count_decrement_hook();
  }
  OS_SchedLockTimeMeasStop_variant2();
  func_0x030020e4(uVar4);
  uVar5 = *PTR_DAT_03003ac8 + 1;
  *PTR_DAT_03003ac8 = uVar5;
  puVar3 = PTR_DAT_03003ac8;
  iVar8 = PTR_DAT_03003ad0
          [(uVar5 - (uVar5 / *(ushort *)PTR_LAB_03003acc) * (uint)*(ushort *)PTR_LAB_03003acc &
           0xffff) * 2];
  while (iVar7 = iVar8, iVar7 != 0) {
    iVar8 = *(int *)(iVar7 + 0x14);
    bVar2 = *(byte *)(iVar7 + 0x36);
    if (bVar2 == 3) {
      iVar6 = *puVar3;
      *(int *)(iVar7 + 0x50) = *(int *)(iVar7 + 0x4c) - iVar6;
      if (*(int *)(iVar7 + 0x4c) != iVar6) break;
      *(undefined4 *)(iVar7 + 0x40) = 0;
      timer_wheel_bucket_drain_and_reset(iVar7);
      feature_activate_if_not_already_set(iVar7);
      *(undefined1 *)(iVar7 + 0x36) = 0;
      *(undefined1 *)(iVar7 + 0x35) = 3;
      *(undefined1 *)(iVar7 + 0x34) = 0;
    }
    else if (bVar2 < 4) {
      if (bVar2 == 1) {
        iVar6 = *puVar3;
        *(int *)(iVar7 + 0x50) = *(int *)(iVar7 + 0x4c) - iVar6;
        if (*(int *)(iVar7 + 0x4c) != iVar6) break;
        *(undefined1 *)(iVar7 + 0x36) = 0;
        feature_activate_if_not_already_set(iVar7);
      }
    }
    else if (bVar2 == 5) {
      iVar6 = *puVar3;
      *(int *)(iVar7 + 0x50) = *(int *)(iVar7 + 0x4c) - iVar6;
      if (*(int *)(iVar7 + 0x4c) != iVar6) break;
      *(undefined1 *)(iVar7 + 0x36) = 4;
      timer_list_unlink_node(iVar7);
    }
    else if (bVar2 == 7) {
      iVar6 = *puVar3;
      *(int *)(iVar7 + 0x50) = *(int *)(iVar7 + 0x4c) - iVar6;
      if (*(int *)(iVar7 + 0x4c) != iVar6) break;
      *(undefined4 *)(iVar7 + 0x40) = 0;
      timer_wheel_bucket_drain_and_reset(iVar7);
      timer_list_unlink_node(iVar7);
      *(undefined1 *)(iVar7 + 0x36) = 4;
      *(undefined1 *)(iVar7 + 0x35) = 3;
      *(undefined1 *)(iVar7 + 0x34) = 0;
    }
  }
  uVar4 = cpu_sr_save_and_disable_irq();
  OS_SchedLockTimeMeasStart_variant2();
  cVar1 = *(char *)PTR_LAB_03003ac4;
  *(char *)PTR_LAB_03003ac4 = cVar1 + -1;
  if ((char)(cVar1 + -1) == '\0') {
    ucos_crit_section_nest_exit_with_lock_time_track_variant2();
    if (*(short *)PTR_DAT_03003ad4 == 0) {
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar4);
    }
    else {
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar4);
      queued_task_event_dispatch_with_counter();
    }
  }
  else {
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar4);
  }
  return;
}


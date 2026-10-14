/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: protocol_request_struct_build_and_dispatch @ 030032ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 398 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: host-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void protocol_request_struct_build_and_dispatch
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               char param_5,undefined4 *param_6,int param_7,uint param_8,undefined2 param_9,
               int param_10,undefined4 param_11,ushort param_12,undefined4 *param_13)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  if (*(char *)PTR_DAT_0300347c == '\0') {
    if (param_5 == '\0') {
      if (param_1 != _DAT_03003480) {
        *param_13 = 0x6273;
        return;
      }
    }
    else if ((param_5 == '\a') && (param_1 != _DAT_03003484)) {
      *param_13 = 0x6273;
      return;
    }
    FUN_03003294(param_1);
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
    uVar2 = FUN_03002368(param_3,param_4,param_6,param_6 + param_7,param_8,param_12,param_9);
    param_1[10] = param_3;
    param_1[0xb] = param_4;
    param_1[8] = param_2;
    *(char *)((int)param_1 + 0x37) = param_5;
    *param_1 = uVar2;
    param_1[2] = param_6 + param_7;
    param_1[0x15] = param_10;
    if (param_10 == 0) {
      param_1[0x16] = *PTR_DAT_03003488;
    }
    else {
      param_1[0x16] = param_10;
    }
    param_1[1] = param_11;
    param_1[9] = param_6;
    param_1[0xe] = param_8;
    *(ushort *)(param_1 + 0xf) = param_12;
    FUN_03002360(param_1);
    uVar2 = cpu_sr_save_and_disable_irq();
    OS_SchedLockTimeMeasStart_variant2();
    cVar1 = *(char *)PTR_LAB_0300348c;
    *(char *)PTR_LAB_0300348c = cVar1 + '\x01';
    if ((char)(cVar1 + '\x01') == '\x01') {
      ucos_timer_live_count_decrement_hook();
    }
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar2);
    FUN_03002ff4(*(undefined1 *)((int)param_1 + 0x37));
    slot_list_push_back_a(param_1);
    *(short *)PTR_DAT_03003490 = *(short *)PTR_DAT_03003490 + 1;
    if (*(char *)PTR_LAB_00016d4c_1_03003494 == '\x01') {
      uVar2 = cpu_sr_save_and_disable_irq();
      OS_SchedLockTimeMeasStart_variant2();
      cVar1 = *(char *)PTR_LAB_0300348c;
      *(char *)PTR_LAB_0300348c = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track_variant2();
      }
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar2);
      bounded_queue_lock_release_pair_variant();
    }
    else {
      uVar2 = cpu_sr_save_and_disable_irq();
      OS_SchedLockTimeMeasStart_variant2();
      cVar1 = *(char *)PTR_LAB_0300348c;
      *(char *)PTR_LAB_0300348c = cVar1 + -1;
      if ((char)(cVar1 + -1) == '\0') {
        ucos_crit_section_nest_exit_with_lock_time_track_variant2();
        if (*(short *)PTR_DAT_03003498 == 0) {
          OS_SchedLockTimeMeasStop_variant2();
          func_0x030020e4(uVar2);
        }
        else {
          OS_SchedLockTimeMeasStop_variant2();
          func_0x030020e4(uVar2);
          queued_task_event_dispatch_with_counter();
        }
      }
      else {
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar2);
      }
    }
  }
  else {
    *param_13 = 0x714a;
  }
  return;
}


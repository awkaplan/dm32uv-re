/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c0c24 @ 030c0c24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 152 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030c0c24(undefined4 *param_1)

{
  undefined4 sr;
  int iVar1;
  int iVar2;
  
  if (*(char *)PTR_OSIntNestingCtr_030c0cb4 == '\0') {
    if (*(char *)PTR_OSSchedLockNestingCtr_030c0cb8 == '\0') {
      if (*(char *)PTR_DAT_030c0cbc == '\x01') {
        sr = cpu_sr_save_and_disable_irq_variant2();
        OS_SchedLockTimeMeasStart_variant3();
        iVar1 = _DAT_030c0cac;
        if (*(ushort *)((uint)*(byte *)PTR_DAT_030c0cb0 * 0xc + _DAT_030c0ca8) < 2) {
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(sr);
          *param_1 = 0x697a;
        }
        else {
          iVar2 = (uint)*(byte *)PTR_DAT_030c0cb0 * 0xc;
          queued_event_list_swap_or_rotate_head(_DAT_030c0cac + iVar2);
          iVar1 = *(int *)(iVar2 + iVar1);
          if (*(int *)(iVar1 + 0x54) == 0) {
            *(undefined4 *)(iVar1 + 0x58) = *PTR_DAT_030c0cc0;
          }
          else {
            *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x54);
          }
          OS_SchedLockTimeMeasStop_variant3();
          cpu_sr_restore_irq_variant2(sr);
          OS_Sched();
          *param_1 = 0;
        }
      }
      else {
        *param_1 = 0x697b;
      }
    }
    else {
      *param_1 = 0x6d63;
    }
  }
  else {
    *param_1 = 0x84d1;
  }
  return;
}


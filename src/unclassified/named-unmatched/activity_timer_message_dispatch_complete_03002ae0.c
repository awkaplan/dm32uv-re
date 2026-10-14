/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: activity_timer_message_dispatch_complete @ 03002ae0 (file base 0x03000000; code starts at 0x03001000)
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

void activity_timer_message_dispatch_complete(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)PTR_DAT_03002b80 == '\x01') {
    uVar1 = cpu_sr_save_and_disable_irq();
    OS_SchedLockTimeMeasStart_variant2();
    iVar3 = *param_1;
    if (iVar3 == 0) {
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar1);
    }
    else if (iVar3 == _DAT_03002b84) {
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar1);
    }
    else {
      if ((*(int *)(iVar3 + 0x58) != 0) &&
         (iVar2 = *(int *)(iVar3 + 0x58) + -1, *(int *)(iVar3 + 0x58) = iVar2, iVar2 != 0)) {
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar1);
        return;
      }
      if (*(ushort *)(param_1 + 2) < 2) {
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar1);
      }
      else if (*(char *)PTR_LAB_03002b88 == '\0') {
        timer_list_swap_or_rotate_head(param_1);
        iVar3 = *param_1;
        if (*(int *)(iVar3 + 0x54) == 0) {
          *(undefined4 *)(iVar3 + 0x58) = *PTR_DAT_03002b8c;
        }
        else {
          *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x54);
        }
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar1);
      }
      else {
        OS_SchedLockTimeMeasStop_variant2();
        func_0x030020e4(uVar1);
      }
    }
  }
  return;
}


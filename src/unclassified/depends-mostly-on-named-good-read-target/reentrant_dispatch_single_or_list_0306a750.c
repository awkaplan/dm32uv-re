/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: reentrant_dispatch_single_or_list @ 0306a750 (file base 0x03000000; code starts at 0x03001000)
 * Size: 288 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void reentrant_dispatch_single_or_list
               (int param_1,undefined4 param_2,undefined2 param_3,ushort param_4,undefined4 param_5,
               undefined4 *param_6)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  
  uVar2 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306a8c8;
  *(char *)PTR_OSSchedLockNestingCtr_0306a8c8 = cVar1 + '\x01';
  if ((char)(cVar1 + '\x01') == '\x01') {
    OS_SchedLockTimeMeasStart_variant4();
  }
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar2);
  sVar4 = *(short *)(param_1 + 0x10);
  if (sVar4 == 0) {
    queue_node_alloc_and_enqueue(param_1 + 0x20,param_2,param_3);
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306a8c8;
    *(char *)PTR_OSSchedLockNestingCtr_0306a8c8 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
      if (*(short *)PTR_DAT_0306a8cc == 0) {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
      }
      else {
        OS_SchedLockTimeMeasStop();
        cpu_sr_restore_irq_iram(uVar2);
        irq_disable_save_and_release_reinit();
      }
    }
    else {
      OS_SchedLockTimeMeasStop();
      cpu_sr_restore_irq_iram(uVar2);
    }
  }
  else {
    if ((param_4 & 0x200) == 0) {
      sVar4 = 1;
    }
    iVar3 = *(int *)(param_1 + 8);
    do {
      iVar5 = *(int *)(iVar3 + 4);
      work_item_advance_or_complete_and_unlink
                (param_1,*(undefined4 *)(iVar3 + 8),param_2,param_3,param_5);
      sVar4 = sVar4 + -1;
      iVar3 = iVar5;
    } while (sVar4 != 0);
    uVar2 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    cVar1 = *(char *)PTR_OSSchedLockNestingCtr_0306a8c8;
    *(char *)PTR_OSSchedLockNestingCtr_0306a8c8 = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      OS_SchedLockTimeMeasStop_variant4();
    }
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar2);
    if (-1 < (short)param_4) {
      OSSched();
    }
    *param_6 = 0;
  }
  return;
}


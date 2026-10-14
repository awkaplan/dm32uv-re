/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_state_and_linked_list_node_fields_zero_reset @ 0306a93c (file base 0x03000000; code starts at 0x03001000)
 * Size: 238 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: radio-state
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void radio_state_and_linked_list_node_fields_zero_reset(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  *PTR_DAT_0306aaf8 = 0;
  *(undefined2 *)PTR_DAT_0306aafc = 0;
  *(undefined2 *)PTR_DAT_0306ab00 = 0;
  *PTR_DAT_0306ab04 = 0;
  *PTR_DAT_0306ab08 = 0;
  *PTR_DAT_0306ab0c = 0;
  *PTR_DAT_0306ab10 = 0;
  *PTR_DAT_0306ab14 = 0;
  PTR_DAT_0306ab18[4] = 0;
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar1);
  uVar1 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  iVar3 = *PTR_DAT_0306ab1c;
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar1);
  while (iVar3 != 0) {
    uVar1 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    *(undefined4 *)(iVar3 + 0xb4) = 0;
    *(undefined4 *)(iVar3 + 0xb8) = 0;
    *(undefined4 *)(iVar3 + 0x78) = 0;
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    *(undefined4 *)(iVar3 + 0x90) = 0;
    *(undefined2 *)(iVar3 + 0x8c) = 0;
    *(undefined2 *)(iVar3 + 0x8e) = 0;
    *(undefined4 *)(iVar3 + 0x9c) = 0;
    *(undefined4 *)(iVar3 + 0xa0) = 0;
    uVar2 = CPU_TS_TmrRd();
    *(undefined4 *)(iVar3 + 0x98) = uVar2;
    *(undefined2 *)(iVar3 + 0x70) = 0;
    iVar3 = *(int *)(iVar3 + 0xc0);
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar1);
  }
  uVar1 = cpu_sr_save_and_disable_irq_iram();
  OS_SchedLockTimeMeasStart();
  iVar3 = *PTR_DAT_0306ab20;
  OS_SchedLockTimeMeasStop();
  cpu_sr_restore_irq_iram(uVar1);
  while (iVar3 != 0) {
    uVar1 = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    *(undefined2 *)(iVar3 + 0x2c) = 0;
    iVar3 = *(int *)(iVar3 + 0x18);
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(uVar1);
  }
  FUN_00013a84();
  array_clear_first_field_stride8();
  *param_1 = 0;
  return;
}


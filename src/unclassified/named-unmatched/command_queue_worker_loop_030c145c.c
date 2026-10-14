/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: command_queue_worker_loop @ 030c145c (file base 0x03000000; code starts at 0x03001000)
 * Size: 142 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void command_queue_worker_loop(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  puVar4 = PTR_DAT_030c15c8;
  puVar3 = PTR_DAT_030c15c4;
  puVar2 = PTR_OSRdyList_030c15c0;
  puVar1 = PTR_DAT_030c15bc;
  do {
    while( true ) {
      uVar5 = cpu_sr_save_and_disable_irq_variant2();
      OS_SchedLockTimeMeasStart_variant3();
      if (*(short *)puVar1 != 0) break;
      *(undefined2 *)(puVar2 + 2) = 0;
      *puVar2 = 0;
      puVar2[1] = 0;
      FUN_030c1654(0);
      OS_SchedLockTimeMeasStop_variant3();
      cpu_sr_restore_irq_variant2(uVar5);
      OS_Sched();
    }
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar5);
    iVar6 = func_0x0611caf4();
    settings_block_command_dispatch();
    iVar7 = func_0x0611caf4();
    if ((uint)*puVar3 < (uint)(iVar7 - iVar6)) {
      *puVar3 = iVar7 - iVar6;
    }
    uVar5 = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    *puVar4 = *(undefined4 *)(*puVar4 + 4);
    *(short *)puVar1 = *(short *)puVar1 + -1;
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(uVar5);
  } while( true );
}


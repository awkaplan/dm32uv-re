/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: message_queue_consumer_task @ 03002e2c (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void message_queue_consumer_task(void)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  puVar3 = PTR_DAT_03002ea8;
  puVar2 = PTR_LAB_03002ea4;
  puVar1 = PTR_DAT_03002ea0;
  do {
    while( true ) {
      uVar4 = cpu_sr_save_and_disable_irq();
      OS_SchedLockTimeMeasStart_variant2();
      if (*puVar1 != 0) break;
      *(undefined2 *)(puVar2 + 2) = 0;
      *puVar2 = 0;
      puVar2[1] = 0;
      FUN_03003018(0);
      OS_SchedLockTimeMeasStop_variant2();
      func_0x030020e4(uVar4);
      bounded_queue_lock_release_pair_variant();
    }
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar4);
    message_type_handler_dispatch_03002d8c();
    uVar4 = cpu_sr_save_and_disable_irq();
    OS_SchedLockTimeMeasStart_variant2();
    *puVar3 = *(undefined4 *)(*puVar3 + 4);
    *puVar1 = *puVar1 + -1;
    OS_SchedLockTimeMeasStop_variant2();
    func_0x030020e4(uVar4);
  } while( true );
}


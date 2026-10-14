/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_IdleTask_variant3 @ 030c0488 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_IdleTask_variant3(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 sr;
  
  puVar2 = PTR_DAT_030c05b4;
  puVar1 = PTR_DAT_030c05b0;
  do {
    sr = cpu_sr_save_and_disable_irq_variant2();
    OS_SchedLockTimeMeasStart_variant3();
    *puVar1 = *puVar1 + 1;
    *puVar2 = *puVar2 + 1;
    OS_SchedLockTimeMeasStop_variant3();
    cpu_sr_restore_irq_variant2(sr);
    FUN_030c02ec();
  } while( true );
}


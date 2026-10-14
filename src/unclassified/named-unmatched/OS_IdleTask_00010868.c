/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_IdleTask @ 00010868 (IRAM address; the boot stub copies these bytes from program flash 0x030c0488)
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

void OS_IdleTask(void)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 sr;
  
  puVar2 = PTR_DAT_00010994;
  puVar1 = PTR_DAT_00010990;
  do {
    sr = cpu_sr_save_and_disable_irq_iram();
    OS_SchedLockTimeMeasStart();
    *(int *)puVar1 = *(int *)puVar1 + 1;
    *(int *)puVar2 = *(int *)puVar2 + 1;
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(sr);
    func_0x000106cc();
  } while( true );
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_SchedLockTimeMeasStart_variant4 @ 0001117c (IRAM address; the boot stub copies these bytes from program flash 0x030c0d9c)
 * Size: 20 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_SchedLockTimeMeasStart_variant4(void)

{
  undefined4 uVar1;
  
  if (*PTR_OSSchedLockNestingCtr_00011238 == '\x01') {
    uVar1 = func_0x0306ced4();
    *(undefined4 *)PTR_DAT_0001123c = uVar1;
  }
  return;
}


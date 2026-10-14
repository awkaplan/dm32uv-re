/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_SchedLockTimeMeasStart @ 0001023c (IRAM address; the boot stub copies these bytes from program flash 0x030bfe5c)
 * Size: 36 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_SchedLockTimeMeasStart(void)

{
  undefined4 uVar1;
  
  *(short *)PTR_DAT_000102f8 = *(short *)PTR_DAT_000102f8 + 1;
  if (*(short *)PTR_DAT_000102fc == 0) {
    uVar1 = func_0x0306ced4();
    *(undefined4 *)PTR_DAT_00010300 = uVar1;
  }
  *(short *)PTR_DAT_000102fc = *(short *)PTR_DAT_000102fc + 1;
  return;
}


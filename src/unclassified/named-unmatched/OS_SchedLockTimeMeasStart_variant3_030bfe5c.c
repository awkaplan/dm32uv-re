/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_SchedLockTimeMeasStart_variant3 @ 030bfe5c (file base 0x03000000; code starts at 0x03001000)
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

void OS_SchedLockTimeMeasStart_variant3(void)

{
  undefined4 uVar1;
  
  *(short *)PTR_DAT_030bff18 = *(short *)PTR_DAT_030bff18 + 1;
  if (*(short *)PTR_DAT_030bff1c == 0) {
    uVar1 = func_0x0611caf4();
    *PTR_DAT_030bff20 = uVar1;
  }
  *(short *)PTR_DAT_030bff1c = *(short *)PTR_DAT_030bff1c + 1;
  return;
}


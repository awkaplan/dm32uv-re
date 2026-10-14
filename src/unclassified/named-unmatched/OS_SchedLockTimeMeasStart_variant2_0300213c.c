/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_SchedLockTimeMeasStart_variant2 @ 0300213c (file base 0x03000000; code starts at 0x03001000)
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

void OS_SchedLockTimeMeasStart_variant2(void)

{
  undefined4 uVar1;
  
  *(short *)PTR_LAB_03002160 = *(short *)PTR_LAB_03002160 + 1;
  if (*(short *)PTR_LAB_03002164 == 0) {
    uVar1 = func_0x05ff3ac0();
    *PTR_LAB_03002168 = uVar1;
  }
  *(short *)PTR_LAB_03002164 = *(short *)PTR_LAB_03002164 + 1;
  return;
}


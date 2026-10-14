/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: OS_SchedLockTimeMeasStop_variant3 @ 030bfe80 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_SchedLockTimeMeasStop_variant3(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  sVar1 = *(short *)PTR_DAT_030bff1c;
  *(short *)PTR_DAT_030bff1c = sVar1 + -1;
  if ((short)(sVar1 + -1) == 0) {
    iVar2 = func_0x0611caf4();
    *PTR_DAT_030bff24 = iVar2;
    uVar3 = iVar2 - *PTR_DAT_030bff20;
    if ((uint)*PTR_DAT_030bff10 < uVar3) {
      *PTR_DAT_030bff10 = uVar3;
    }
    if ((uint)*PTR_DAT_030bff14 < uVar3) {
      *PTR_DAT_030bff14 = uVar3;
    }
  }
  return;
}


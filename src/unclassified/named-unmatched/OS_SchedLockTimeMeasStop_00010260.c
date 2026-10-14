/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_SchedLockTimeMeasStop @ 00010260 (IRAM address; the boot stub copies these bytes from program flash 0x030bfe80)
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

void OS_SchedLockTimeMeasStop(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  sVar1 = *(short *)PTR_DAT_000102fc;
  *(short *)PTR_DAT_000102fc = sVar1 + -1;
  if ((short)(sVar1 + -1) == 0) {
    iVar2 = func_0x0306ced4();
    *(int *)PTR_DAT_00010304 = iVar2;
    uVar3 = iVar2 - *(int *)PTR_DAT_00010300;
    if (*(uint *)PTR_DAT_000102f0 < uVar3) {
      *(uint *)PTR_DAT_000102f0 = uVar3;
    }
    if (*(uint *)PTR_DAT_000102f4 < uVar3) {
      *(uint *)PTR_DAT_000102f4 = uVar3;
    }
  }
  return;
}


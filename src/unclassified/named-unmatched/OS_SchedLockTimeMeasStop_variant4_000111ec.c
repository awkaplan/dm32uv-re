/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_SchedLockTimeMeasStop_variant4 @ 000111ec (IRAM address; the boot stub copies these bytes from program flash 0x030c0e0c)
 * Size: 46 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_SchedLockTimeMeasStop_variant4(void)

{
  int iVar1;
  uint uVar2;
  
  if (*PTR_OSSchedLockNestingCtr_00011238 == '\0') {
    iVar1 = func_0x0306ced4();
    uVar2 = iVar1 - *(int *)PTR_DAT_0001123c;
    if (*(uint *)PTR_DAT_00011248 < uVar2) {
      *(uint *)PTR_DAT_00011248 = uVar2;
    }
    if (*(uint *)PTR_DAT_0001124c < uVar2) {
      *(uint *)PTR_DAT_0001124c = uVar2;
    }
  }
  return;
}


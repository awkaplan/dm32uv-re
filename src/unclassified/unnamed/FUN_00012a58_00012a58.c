/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00012a58 @ 00012a58 (IRAM address; the boot stub copies these bytes from program flash 0x030c2678)
 * Size: 78 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00012a58(void)

{
  int iVar1;
  uint in_r3;
  int *piVar2;
  int unaff_r4;
  int *unaff_r5;
  undefined4 *unaff_r6;
  int *unaff_r7;
  undefined4 unaff_r8;
  
  if ((in_r3 & 1) == 0) {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(unaff_r8);
    *unaff_r5 = 0;
    *unaff_r7 = 0;
    *unaff_r6 = 0x7154;
  }
  else {
    OS_SchedLockTimeMeasStop();
    cpu_sr_restore_irq_iram(unaff_r8);
    piVar2 = *(int **)(unaff_r4 + 0x24);
    iVar1 = 0;
    if (*piVar2 == 0) {
      do {
        piVar2 = piVar2 + 1;
        iVar1 = iVar1 + 1;
      } while (*piVar2 == 0);
    }
    else {
      iVar1 = 0;
    }
    *unaff_r5 = iVar1;
    *unaff_r7 = *(int *)(unaff_r4 + 0x38) - iVar1;
    *unaff_r6 = 0;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: dll_node_remove @ 00013a48 (IRAM address; the boot stub copies these bytes from program flash 0x030c3668)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rtos
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dll_node_remove(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x1c);
  if (piVar3 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    if (*piVar3 == param_1) {
      iVar1 = *(int *)(*piVar3 + 0x14);
      *piVar3 = iVar1;
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x18) = 0;
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x18);
      iVar2 = *(int *)(param_1 + 0x14);
      *(int *)(iVar1 + 0x14) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0x18) = iVar1;
      }
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(short *)(piVar3 + 1) = (short)piVar3[1] + -1;
  }
  return;
}


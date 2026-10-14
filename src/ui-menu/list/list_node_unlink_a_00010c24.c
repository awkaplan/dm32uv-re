/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: list_node_unlink_a @ 00010c24 (IRAM address; the boot stub copies these bytes from program flash 0x030c0844)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_node_unlink_a(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(short *)(param_1 + 2) == 1) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    iVar2 = *param_2;
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)param_2[1];
      *puVar3 = 0;
      *param_1 = puVar3;
    }
    else {
      piVar1 = (int *)param_2[1];
      if (piVar1 == (int *)0x0) {
        *(undefined4 *)(iVar2 + 4) = 0;
        param_1[1] = iVar2;
      }
      else {
        *(int **)(iVar2 + 4) = piVar1;
        *piVar1 = iVar2;
      }
    }
  }
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + -1;
  param_2[1] = 0;
  *param_2 = 0;
  return;
}


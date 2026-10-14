/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_node_unlink_b @ 030026c8 (file base 0x03000000; code starts at 0x03001000)
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

void list_node_unlink_b(undefined4 *param_1,int *param_2)

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


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: pend_list_insert_by_prio_b @ 030c07d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void pend_list_insert_by_prio_b(undefined4 *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  
  bVar1 = *(byte *)(param_2[2] + 0x37);
  if (*(short *)(param_1 + 2) == 0) {
    *(undefined2 *)(param_1 + 2) = 1;
    param_2[1] = 0;
    *param_2 = 0;
    *param_1 = param_2;
    param_1[1] = param_2;
  }
  else {
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
    piVar4 = (int *)*param_1;
    if (piVar4 == (int *)0x0) {
LAB_030c0836:
      param_2[1] = 0;
      iVar3 = param_1[1];
      *param_2 = iVar3;
      *(int **)(iVar3 + 4) = param_2;
      param_1[1] = param_2;
    }
    else {
      bVar2 = *(byte *)(piVar4[2] + 0x37);
      while (bVar2 <= bVar1) {
        piVar4 = (int *)piVar4[1];
        if (piVar4 == (int *)0x0) goto LAB_030c0836;
        bVar2 = *(byte *)(piVar4[2] + 0x37);
      }
      iVar3 = *piVar4;
      if (iVar3 == 0) {
        *piVar4 = (int)param_2;
        *param_2 = 0;
        param_2[1] = (int)piVar4;
        *param_1 = param_2;
      }
      else {
        *param_2 = iVar3;
        param_2[1] = (int)piVar4;
        *(int **)(iVar3 + 4) = param_2;
        *piVar4 = (int)param_2;
      }
    }
  }
  return;
}


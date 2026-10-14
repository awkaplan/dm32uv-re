/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_node_dequeue_and_free @ 03069600 (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int queue_node_dequeue_and_free
              (undefined4 *param_1,undefined2 *param_2,int *param_3,undefined4 *param_4)

{
  undefined2 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(short *)((int)param_1 + 10) == 0) {
    *param_2 = 0;
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
    }
    *param_4 = 0x6592;
    iVar4 = 0;
  }
  else {
    piVar3 = (int *)param_1[1];
    iVar4 = piVar3[1];
    *param_2 = (short)piVar3[2];
    if (param_3 != (int *)0x0) {
      *param_3 = piVar3[3];
    }
    iVar2 = *piVar3;
    param_1[1] = iVar2;
    if (iVar2 == 0) {
      *param_1 = 0;
      *(undefined2 *)((int)param_1 + 10) = 0;
    }
    else {
      *(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + -1;
    }
    puVar1 = PTR_DAT_030696e8;
    *piVar3 = *(int *)PTR_DAT_030696e8;
    *(int **)puVar1 = piVar3;
    puVar1[2] = puVar1[2] + 1;
    puVar1[3] = puVar1[3] + -1;
    *param_4 = 0;
  }
  return iVar4;
}


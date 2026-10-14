/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: queue_node_alloc_and_enqueue @ 03069670 (file base 0x03000000; code starts at 0x03001000)
 * Size: 184 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void queue_node_alloc_and_enqueue(undefined4 *param_1,undefined4 param_2,int param_3__w,uint param_4,undefined4 param_5,undefined4 *param_6)

{
  undefined2 param_3 = (undefined2)param_3__w;
  ushort uVar1;
  short *psVar2;
  undefined2 *puVar3;
  ushort uVar4;
  undefined4 *puVar5;
  
  puVar3 = PTR_DAT_030696e8;
  uVar1 = *(ushort *)((int)param_1 + 10);
  if (uVar1 < *(ushort *)(param_1 + 2)) {
    psVar2 = PTR_DAT_030696e8 + 2;
    if (*psVar2 == 0) {
      *param_6 = 0x571d;
    }
    else {
      puVar5 = *(undefined4 **)PTR_DAT_030696e8;
      *(undefined4 *)PTR_DAT_030696e8 = *puVar5;
      puVar3[2] = *psVar2 + -1;
      uVar4 = puVar3[3] + 1;
      puVar3[3] = uVar4;
      if ((ushort)puVar3[4] < uVar4) {
        PTR_DAT_030696e8[4] = uVar4;
      }
      if (uVar1 == 0) {
        *param_1 = puVar5;
        param_1[1] = puVar5;
        *(undefined2 *)((int)param_1 + 10) = 1;
        *puVar5 = 0;
      }
      else {
        if ((param_4 & 0x10) == 0) {
          *(undefined4 **)*param_1 = puVar5;
          *param_1 = puVar5;
          *puVar5 = 0;
        }
        else {
          *puVar5 = param_1[1];
          param_1[1] = puVar5;
        }
        *(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + 1;
      }
      if (*(ushort *)(param_1 + 3) < *(ushort *)((int)param_1 + 10)) {
        *(ushort *)(param_1 + 3) = *(ushort *)((int)param_1 + 10);
      }
      puVar5[1] = param_2;
      *(undefined2 *)(puVar5 + 2) = param_3;
      puVar5[3] = param_5;
      *param_6 = 0;
    }
  }
  else {
    *param_6 = 0x6593;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03069544 @ 03069544 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03069544(undefined4 *param_1)

{
  short sVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)*_DAT_030696e0;
  if (puVar5 == (undefined4 *)0x0) {
    *param_1 = 0x571e;
  }
  else {
    sVar1 = *(short *)PTR_LAB_030696e4;
    if (sVar1 == 0) {
      *param_1 = 0x571d;
    }
    else {
      puVar4 = puVar5;
      if (sVar1 != 1) {
        do {
          puVar3 = puVar4 + 4;
          *puVar4 = puVar3;
          puVar4[1] = 0;
          *(undefined2 *)(puVar4 + 2) = 0;
          puVar4[3] = 0;
          puVar4 = puVar3;
        } while (puVar3 != puVar5 + (uint)(ushort)(sVar1 - 2) * 4 + 4);
        puVar4 = puVar5 + ((ushort)(sVar1 - 2) + 1) * 4;
      }
      *puVar4 = 0;
      puVar4[1] = 0;
      *(undefined2 *)(puVar4 + 2) = 0;
      puVar4[3] = 0;
      puVar2 = PTR_DAT_030696e8;
      *(undefined4 **)PTR_DAT_030696e8 = puVar5;
      puVar2[2] = sVar1;
      puVar2[3] = 0;
      puVar2[4] = 0;
      *param_1 = 0;
    }
  }
  return;
}


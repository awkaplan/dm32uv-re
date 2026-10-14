/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030695b4 @ 030695b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030695b4(undefined4 *param_1)

{
  short sVar1;
  undefined2 *puVar2;
  
  puVar2 = PTR_DAT_030696e8;
  if (*(short *)((int)param_1 + 10) != 0) {
    *(undefined4 *)*param_1 = *(undefined4 *)PTR_DAT_030696e8;
    *(undefined4 *)puVar2 = param_1[1];
    sVar1 = *(short *)((int)param_1 + 10);
    puVar2[3] = puVar2[3] - sVar1;
    puVar2[2] = sVar1 + puVar2[2];
    *(undefined2 *)((int)param_1 + 10) = 0;
    *(undefined2 *)(param_1 + 3) = 0;
    *param_1 = 0;
    param_1[1] = 0;
  }
  return;
}


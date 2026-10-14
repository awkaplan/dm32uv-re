/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c7050 @ 030c7050 (file base 0x03000000; code starts at 0x03001000)
 * Size: 166 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

short FUN_030c7050(undefined2 *param_1,undefined2 *param_2,int param_3,short param_4,short param_5,
                  short param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  short sStack_28;
  short sStack_26;
  
  sStack_26 = param_4;
  iVar2 = FUN_030ca8ec(param_3 + param_5 * 4,5,&sStack_26);
  sStack_28 = param_4;
  iVar3 = FUN_030ca8ec(param_3 + param_6 * 4,5,&sStack_28);
  sVar1 = sStack_26;
  if (sStack_26 < sStack_28) {
    sVar1 = sStack_28;
  }
  uVar4 = (uint)(short)(sStack_26 - sVar1);
  if ((int)uVar4 < 0) {
    uVar5 = (undefined2)((uint)(iVar2 >> (-uVar4 & 0x3f)) >> 0x10);
  }
  else {
    uVar5 = (undefined2)((uint)(iVar2 << (uVar4 & 0x3f)) >> 0x10);
  }
  uVar4 = (uint)(short)(sStack_28 - sVar1);
  if (-1 < (int)uVar4) {
    *param_1 = uVar5;
    *param_2 = (short)((uint)(iVar3 << (uVar4 & 0x3f)) >> 0x10);
    return sVar1;
  }
  *param_1 = uVar5;
  *param_2 = (short)((uint)(iVar3 >> (-uVar4 & 0x3f)) >> 0x10);
  return sVar1;
}


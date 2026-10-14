/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c4524 @ 030c4524 (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

uint FUN_030c4524(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = (uint)param_1[3] + (uint)*param_1 * 0x1000000 + (uint)param_1[1] * 0x10000 +
          (uint)param_1[2] * 0x100;
  iVar5 = 0x10;
  do {
    uVar1 = uVar3 & 0x4040002;
    uVar2 = uVar3 & 0x821;
    uVar4 = uVar3 >> 2;
    iVar5 = iVar5 + -1;
    uVar3 = uVar4 | (uVar2 ^ uVar2 >> 0xb ^ uVar2 >> 5 | uVar1 ^ uVar1 >> 0x19 ^ uVar1 >> 0x11) <<
                    0x1e;
  } while (iVar5 != 0);
  *param_1 = (byte)(uVar3 >> 0x18);
  param_1[1] = (byte)(uVar4 >> 0x10);
  param_1[2] = (byte)(uVar4 >> 8);
  param_1[3] = (byte)uVar4;
  return uVar3;
}


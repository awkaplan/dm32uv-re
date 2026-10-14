/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0300c0f0 @ 0300c0f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0300c0f0(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  param_1 = param_1 & 0xff;
  if ((param_2 & 0xff) != 0) {
    uVar2 = 0;
    do {
      if ((uVar2 & 7) == 0) {
        param_4 = (uint)*(byte *)(param_3 + (uVar2 >> 3));
      }
      if (param_1 >> 7 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 6;
      }
      if ((param_4 << (uVar2 & 7) & 0x80) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 7;
      }
      param_1 = (param_1 * 2 & 0xff | param_1 >> 7) ^ uVar1 ^ uVar3;
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < (param_2 & 0xff));
  }
  return;
}


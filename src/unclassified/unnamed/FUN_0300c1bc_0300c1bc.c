/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0300c1bc @ 0300c1bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0300c1bc(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  param_1 = param_1 & 0xffff;
  if ((param_2 & 0xffff) != 0) {
    uVar1 = 0;
    do {
      if ((uVar1 & 7) == 0) {
        param_4 = (uint)*(byte *)(param_3 + (uVar1 >> 3 & 0xff));
      }
      uVar2 = 0x1020;
      if (param_1 >> 0xf == 0) {
        uVar2 = 0;
      }
      if ((param_4 << (uVar1 & 7) & 0x80) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0x1021;
      }
      param_1 = (param_1 * 2 & 0xffff | param_1 >> 0xf) ^ uVar2 ^ uVar3;
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < (param_2 & 0xffff));
  }
  return;
}


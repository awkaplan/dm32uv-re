/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030ca758 @ 030ca758 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030ca758(int *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  
  for (; 0 < param_3; param_3 = param_3 + -1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = ((uVar1 & 0xffff) * (uVar1 & 0xffff) +
               ((int)uVar1 >> 0x10 & 0xffffU) * ((int)uVar1 >> 0x10 & 0xffffU)) * 2;
    param_1 = param_1 + 1;
  }
  return;
}


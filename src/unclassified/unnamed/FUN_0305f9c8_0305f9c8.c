/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0305f9c8 @ 0305f9c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0305f9c8(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 != 0) {
    uVar1 = 0;
    do {
      *(undefined1 *)(param_1 + uVar1) = *(undefined1 *)(param_2 + uVar1 + 1);
      *(undefined1 *)(param_1 + uVar1 + 1) = *(undefined1 *)(param_2 + uVar1);
      uVar1 = uVar1 + 2 & 0xff;
    } while (uVar1 < param_3);
  }
  return;
}


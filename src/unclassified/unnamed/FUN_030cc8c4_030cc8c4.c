/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030cc8c4 @ 030cc8c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 36 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_030cc8c4(int param_1,short param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((3 << ((int)param_2 + 2U & 0x3f) & (int)*(short *)(param_1 + 0x44)) != 0) {
    *(undefined4 *)(param_1 + 0x40) = 0xfa000;
    uVar1 = 0x400;
  }
  return uVar1;
}


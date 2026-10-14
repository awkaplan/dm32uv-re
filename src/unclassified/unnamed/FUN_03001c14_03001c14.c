/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03001c14 @ 03001c14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_03001c14(uint param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  
  if (param_1 < 0x40) {
    if (param_2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      FUN_00012a4c(&uStack_14);
      PTR_DAT_03001c4c[param_1] = param_2;
      FUN_00012a58(uStack_14);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


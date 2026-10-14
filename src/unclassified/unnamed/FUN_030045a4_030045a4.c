/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030045a4 @ 030045a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_030045a4(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 & 0xffff) != 0) {
    uVar2 = 0;
    do {
      iVar1 = FUN_03004580(param_1 + uVar2,param_3);
      if (iVar1 != 0) {
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (param_2 & 0xffff));
  }
  return 1;
}


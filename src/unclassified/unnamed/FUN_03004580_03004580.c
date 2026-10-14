/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03004580 @ 03004580 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_03004580(undefined4 param_1,int param_2)

{
  int iVar1;
  
  do {
    if (param_2 == 0) {
      return 0xffffffff;
    }
    iVar1 = FUN_030042a0(param_1);
    param_2 = param_2 + -1;
  } while (iVar1 != 1);
  return 0;
}


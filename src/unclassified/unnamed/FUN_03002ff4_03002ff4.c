/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03002ff4 @ 03002ff4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03002ff4(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0xff) >> 5;
  *(uint *)(_DAT_03003014 + uVar1 * 4) =
       1 << (~(param_1 & 0xff) & 0x1f) | *(uint *)(_DAT_03003014 + uVar1 * 4);
  return;
}


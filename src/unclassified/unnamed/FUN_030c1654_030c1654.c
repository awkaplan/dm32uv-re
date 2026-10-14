/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c1654 @ 030c1654 (file base 0x03000000; code starts at 0x03001000)
 * Size: 30 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030c1654(uint param_1)

{
  uint uVar1;
  
  uVar1 = ~(param_1 & 0xff) & 0x1f;
  PTR_OSPrioTbl_030c1674[(param_1 & 0xff) >> 5] =
       (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & PTR_OSPrioTbl_030c1674[(param_1 & 0xff) >> 5];
  return;
}


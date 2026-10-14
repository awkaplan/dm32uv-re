/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0300e1c8 @ 0300e1c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

uint FUN_0300e1c8(uint param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  uVar1 = param_1 & 0xfff | 0x800;
  cVar2 = '\f';
  uVar3 = uVar1;
  do {
    if ((uVar3 & 1) != 0) {
      uVar3 = uVar3 ^ 0xc75;
    }
    uVar3 = uVar3 >> 1;
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  return uVar1 | uVar3 << 0xc;
}


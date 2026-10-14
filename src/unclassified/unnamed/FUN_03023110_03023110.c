/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03023110 @ 03023110 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

int FUN_03023110(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < 1) {
    iVar1 = 1;
  }
  else {
    iVar1 = 1;
    iVar2 = 1;
    do {
      iVar1 = param_1 * iVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 <= param_2);
  }
  return iVar1;
}


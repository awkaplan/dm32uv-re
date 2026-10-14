/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030020ec @ 030020ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 4 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

int FUN_030020ec(uint param_1)

{
  int iVar1;
  
  if (*DAT_030020fc < param_1) {
    iVar1 = param_1 - *DAT_030020fc;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


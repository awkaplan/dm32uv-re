/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0301f158 @ 0301f158 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0301f158(uint param_1)

{
  undefined2 *puVar1;
  
  puVar1 = PTR_DAT_0301f2f4;
  PTR_DAT_0301f2f4[1] = 0;
  puVar1[2] = (short)param_1 + (short)(param_1 / 0x1f) * -0x1f + 0x81;
  return;
}


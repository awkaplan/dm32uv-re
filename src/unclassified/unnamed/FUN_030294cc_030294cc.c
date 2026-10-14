/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030294cc @ 030294cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 42 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030294cc(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = PTR_DAT_0302960c + 0x1c2;
  puVar3 = PTR_DAT_0302960c;
  do {
    *(undefined1 *)puVar3 = 0;
    puVar3[8] = 0;
    puVar1 = PTR_DAT_03029610;
    puVar3 = puVar3 + 9;
  } while (puVar3 != puVar2);
  PTR_DAT_03029610[0x29] = 0;
  puVar1[0x2a] = 0;
  puVar1[0x2b] = 0;
  puVar1[0x2c] = 0;
  return;
}


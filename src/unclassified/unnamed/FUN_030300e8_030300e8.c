/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030300e8 @ 030300e8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030300e8(void)

{
  byte bVar1;
  
  if (((*(uint *)PTR_DAT_030301fc & 0x80000020) == 0x80000020) &&
     (bVar1 = *_DAT_03030200, *_DAT_03030200 = bVar1 + 1, 0x1d < (byte)(bVar1 + 1))) {
    *_DAT_03030200 = 0;
    PTR_DAT_030301fc[4] = PTR_DAT_030301fc[4] & 0xfe | 1;
  }
  return;
}


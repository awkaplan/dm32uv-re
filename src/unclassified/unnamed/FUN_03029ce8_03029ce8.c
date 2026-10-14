/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03029ce8 @ 03029ce8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03029ce8(void)

{
  byte bVar1;
  undefined4 *puVar2;
  
  puVar2 = PTR_DAT_03029d8c;
  bVar1 = *(byte *)(_DAT_03029d94 + 4);
  *(undefined1 *)(PTR_DAT_03029d8c + (uint)bVar1 * 3 + 0x2d) = 1;
  *(undefined1 *)((int)puVar2 + (uint)bVar1 * 0xc + 0xb6) = 0x10;
  puVar2[(uint)bVar1 * 3 + 0x2f] = *(undefined4 *)(_DAT_03029d98 + 0x24);
  return;
}


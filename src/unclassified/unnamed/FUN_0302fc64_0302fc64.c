/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_0302fc64 @ 0302fc64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0302fc64(void)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  byte bVar4;
  
  puVar2 = _DAT_0302fe1c;
  bVar1 = _DAT_0302fe1c[1];
  bVar4 = bVar1 & 0xf;
  if (bVar4 < 9) {
    uVar3 = 1 << (int)(char)bVar4;
    if ((uVar3 & 0x108) != 0) {
      *_DAT_0302fe1c = 0x75;
      return;
    }
    if ((uVar3 & 0x84) != 0) {
      *_DAT_0302fe1c = 0x50;
      return;
    }
    if ((uVar3 & 0x42) != 0) {
      *_DAT_0302fe1c = 0x25;
      return;
    }
  }
  *_DAT_0302fe1c = 0;
  if ((bVar1 & 0xf) != 0) {
    if (bVar4 == 9) {
      puVar2[1] = bVar1 & 0xf0 | 8;
      *puVar2 = 0x75;
    }
    else {
      _DAT_0302fe1c[1] = bVar1 & 0xf0 | 5;
    }
  }
  return;
}


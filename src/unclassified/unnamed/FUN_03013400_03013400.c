/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_03013400 @ 03013400 (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_03013400(void)

{
  byte bVar1;
  
  if ((*(byte *)(_DAT_03013540 + 8) & 0xf0) == 0x10) {
    bVar1 = 0x32;
  }
  else {
    bVar1 = 0x1e;
  }
  if ((*_DAT_03013544 & 2) != 0) {
    if (*(byte *)(_DAT_03013548 + 7) < bVar1) {
      *(byte *)(_DAT_03013548 + 7) = *(byte *)(_DAT_03013548 + 7) + 1;
    }
    else {
      *(undefined1 *)(_DAT_03013548 + 7) = 0;
      *_DAT_03013544 = *_DAT_03013544 & 0xfd;
      *(byte *)(_DAT_0301354c + 1) = *(byte *)(_DAT_0301354c + 1) & 0xfe | 1;
    }
  }
  if ((*_DAT_03013544 & 4) != 0) {
    if (*(byte *)(_DAT_03013548 + 8) < bVar1) {
      *(byte *)(_DAT_03013548 + 8) = *(byte *)(_DAT_03013548 + 8) + 1;
    }
    else {
      *(undefined1 *)(_DAT_03013548 + 8) = 0;
      *_DAT_03013544 = *_DAT_03013544 & 0xfb;
      *(byte *)(_DAT_0301354c + 1) = *(byte *)(_DAT_0301354c + 1) & 0xfe | 1;
    }
  }
  return;
}


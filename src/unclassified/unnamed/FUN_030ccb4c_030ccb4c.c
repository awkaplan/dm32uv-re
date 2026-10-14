/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030ccb4c @ 030ccb4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_030ccb4c(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar2 = _DAT_030ccc98;
  iVar1 = _DAT_030ccc90;
  iVar5 = 0;
  do {
    pbVar4 = (byte *)(iVar2 + iVar5);
    cVar3 = '\0';
    do {
      cVar3 = cVar3 + '\x01';
      *pbVar4 = *(byte *)((*pbVar4 & 0xf0) + iVar1 + 0x100 + (*pbVar4 & 0xf));
      pbVar4 = pbVar4 + 4;
    } while (cVar3 != '\x04');
    iVar5 = iVar5 + 1;
  } while (iVar5 != 4);
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030023e4 @ 030023e4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 38 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_030023e4(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_0300211c();
  iVar2 = *PTR_DAT_0300240c;
  if (*(uint *)(iVar2 + 0x68) < uVar1) {
    *(uint *)(iVar2 + 0x68) = uVar1;
  }
  if (*(uint *)(iVar2 + 0x6c) < (uint)*PTR_DAT_03002410) {
    *(undefined4 *)(iVar2 + 0x6c) = *PTR_DAT_03002410;
  }
  *PTR_DAT_03002410 = 0;
  return;
}


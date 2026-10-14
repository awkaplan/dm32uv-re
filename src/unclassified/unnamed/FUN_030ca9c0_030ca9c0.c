/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030ca9c0 @ 030ca9c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_030ca9c0(undefined4 param_1,int param_2,short param_3,undefined2 *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 < 1) {
    FUN_030ca778();
    *param_4 = *param_4;
    return;
  }
  iVar1 = 0;
  uVar2 = 0;
  do {
    uVar3 = (uint)*(short *)(param_2 + iVar1);
    iVar1 = iVar1 + 2;
    if ((int)uVar3 < 0) {
      uVar3 = ~uVar3 + 1;
    }
    if ((int)uVar2 < (int)uVar3) {
      uVar2 = uVar3;
    }
  } while (iVar1 != ((ushort)(param_3 - 1) + 1) * 2);
  if ((uVar2 & 0xffff) != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_030ca778();
  *param_4 = *param_4;
  return;
}


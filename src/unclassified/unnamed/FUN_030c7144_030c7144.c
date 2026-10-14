/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c7144 @ 030c7144 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_030c7144(undefined4 param_1,undefined4 param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 1;
  do {
    param_3 = param_3 + 1;
    iVar1 = uVar3 * *param_3;
    uVar3 = uVar3 + 1 & 0xffff;
    iVar2 = iVar2 + iVar1 * 2;
  } while (uVar3 != 5);
  if (iVar2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


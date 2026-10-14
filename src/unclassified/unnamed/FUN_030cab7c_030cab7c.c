/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030cab7c @ 030cab7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_030cab7c(int param_1,int param_2,short param_3,short param_4,short param_5)

{
  uint uVar1;
  int iVar2;
  
  if (0 < param_3) {
    iVar2 = 0;
    do {
      uVar1 = (uint)*(ushort *)(param_2 + iVar2) << 0x10;
      if (*(ushort *)(param_2 + iVar2) != 0) {
        if (-1 < (short)(param_4 - param_5)) {
          if (-1 < (int)uVar1) {
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        uVar1 = (uint)((int)uVar1 >> ((int)(short)-(param_4 - param_5) & 0x3fU)) >> 0x10;
      }
      *(short *)(param_1 + iVar2) = (short)uVar1;
      iVar2 = iVar2 + 2;
    } while (iVar2 != ((ushort)(param_3 - 1) + 1) * 2);
  }
  return;
}


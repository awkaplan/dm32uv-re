/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c87ec @ 030c87ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_030c87ec(undefined4 param_1,undefined4 param_2,ushort *param_3,short param_4)

{
  int *piVar1;
  int aiStack_160 [84];
  
  piVar1 = aiStack_160;
  if (0 < param_4) {
    do {
      *piVar1 = (int)((uint)*param_3 << 0x10) >> 2;
      piVar1 = piVar1 + 1;
      param_3 = param_3 + 1;
    } while (piVar1 != aiStack_160 + (ushort)(param_4 - 1) + 1);
    FUN_030c864c(aiStack_160,aiStack_160,param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_030c864c(aiStack_160,aiStack_160,param_1);
  return;
}


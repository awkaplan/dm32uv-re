/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c7290 @ 030c7290 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_030c7290(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  
  if (param_3 < 1) {
    return 0;
  }
  sVar1 = 1;
  do {
    sVar1 = sVar1 + 1;
  } while (sVar1 != 5);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


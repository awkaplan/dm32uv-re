/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c9000 @ 030c9000 (file base 0x03000000; code starts at 0x03001000)
 * Size: 46 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

uint FUN_030c9000(int param_1,short param_2,short param_3)

{
  uint uVar1;
  
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar1 = (uint)(short)(param_2 - param_3);
  if (-1 < (int)uVar1) {
    return (0 << (uVar1 & 0x3f)) + 0x8000U >> 0x10;
  }
  return (0 >> (-uVar1 & 0x3f)) + 0x8000U >> 0x10;
}


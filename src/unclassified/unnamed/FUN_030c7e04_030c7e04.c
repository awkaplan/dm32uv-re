/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c7e04 @ 030c7e04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 26 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Control flow encountered bad instruction data */

void FUN_030c7e04(undefined4 param_1,int param_2,short param_3)

{
  signed_divide_saturating_halved(param_2 << 0x10,(int)param_3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


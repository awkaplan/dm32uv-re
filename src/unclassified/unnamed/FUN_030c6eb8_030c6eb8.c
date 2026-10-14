/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: FUN_030c6eb8 @ 030c6eb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_030c6eb8(void)

{
  return (uint)*_DAT_030c6ee8 * 0x1000000 + (uint)_DAT_030c6ee8[1] * 0x10000 +
         (uint)_DAT_030c6ee8[3] + (uint)_DAT_030c6ee8[2] * 0x100;
}


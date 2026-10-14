/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aes_subword_sbox_substitute @ 030ccaa8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

int aes_subword_sbox_substitute(uint param_1)

{
  return (((uint)*(byte *)((param_1 >> 0x18) + _DAT_030ccc90) * 0x100 +
          (uint)*(byte *)((param_1 >> 0x10 & 0xff) + _DAT_030ccc90)) * 0x100 +
         (uint)*(byte *)((param_1 >> 8 & 0xff) + _DAT_030ccc90)) * 0x100 +
         (uint)*(byte *)((param_1 & 0xff) + _DAT_030ccc90);
}


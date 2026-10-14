/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aes_shift_rows @ 030ccb88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
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

void aes_shift_rows(void)

{
  int iVar1;
  
  iVar1 = _DAT_030ccc94;
  rotate_uint32_bytes(_DAT_030ccc94 + 4,1);
  rotate_uint32_bytes(iVar1 + 8,2);
  rotate_uint32_bytes(iVar1 + 0xc,3);
  return;
}


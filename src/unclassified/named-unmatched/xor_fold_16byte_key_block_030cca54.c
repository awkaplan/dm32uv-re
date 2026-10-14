/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: xor_fold_16byte_key_block @ 030cca54 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void xor_fold_16byte_key_block(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    *(byte *)(param_1 + iVar1) = (byte)((uint)*param_2 >> 0x18) ^ *(byte *)(param_1 + iVar1);
    *(byte *)(param_1 + 4 + iVar1) = (byte)((uint)*param_2 >> 0x10) ^ *(byte *)(param_1 + 4 + iVar1)
    ;
    *(byte *)(param_1 + 8 + iVar1) = (byte)((uint)*param_2 >> 8) ^ *(byte *)(param_1 + 8 + iVar1);
    *(byte *)(param_1 + 0xc + iVar1) = *(byte *)(param_1 + 0xc + iVar1) ^ (byte)*param_2;
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 1;
  } while (iVar1 != 4);
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: u32_to_bcd4_encode @ 0305f4f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void u32_to_bcd4_encode(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  do {
    uVar2 = (param_1 % 100) / 10;
    *(byte *)(param_2 + iVar1) = (char)(param_1 % 100) + (char)uVar2 * -10 | (byte)(uVar2 << 4);
    iVar1 = iVar1 + 1;
    param_1 = param_1 / 100;
  } while (iVar1 != 4);
  return;
}


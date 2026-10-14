/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: int_to_bcd_bytes @ 0305f6e0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void int_to_bcd_bytes(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_3 & 0xff) != 0) {
    uVar1 = 0;
    do {
      uVar2 = (param_2 % 100) / 10;
      *(byte *)(param_1 + uVar1) = (char)(param_2 % 100) + (char)uVar2 * -10 | (byte)(uVar2 << 4);
      uVar1 = uVar1 + 1;
      param_2 = param_2 / 100;
    } while ((uVar1 & 0xff) < (param_3 & 0xff));
  }
  return;
}


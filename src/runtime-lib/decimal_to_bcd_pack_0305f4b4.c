/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: decimal_to_bcd_pack @ 0305f4b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint decimal_to_bcd_pack(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar3 = 0;
  do {
    uVar2 = param_1 / 10;
    uVar1 = uVar1 | param_1 % 10 << ((uVar3 & 0xf) << 2);
    uVar3 = uVar3 + 1 & 0xff;
    param_1 = uVar2;
  } while (uVar2 != 0);
  return uVar1;
}


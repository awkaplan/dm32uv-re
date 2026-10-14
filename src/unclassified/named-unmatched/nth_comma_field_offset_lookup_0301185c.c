/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: nth_comma_field_offset_lookup @ 0301185c (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint nth_comma_field_offset_lookup(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)*(ushort *)PTR_DAT_030119a0;
  if (*(ushort *)(PTR_DAT_030119a0 + 4) != 0) {
    uVar3 = 0;
    uVar1 = 0;
    do {
      if (0x3ff < uVar2) {
        uVar2 = 0;
      }
      if ((PTR_DAT_030119a4[uVar2] == ',') && (uVar3 = uVar3 + 1, uVar3 == (param_1 & 0xff))) {
        uVar2 = uVar2 + 1;
        break;
      }
      uVar2 = uVar2 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(ushort *)(PTR_DAT_030119a0 + 4));
  }
  if (0x3ff < uVar2) {
    uVar2 = 0;
  }
  return uVar2;
}


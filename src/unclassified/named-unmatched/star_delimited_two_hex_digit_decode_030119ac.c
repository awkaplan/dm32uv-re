/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: star_delimited_two_hex_digit_decode @ 030119ac (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte star_delimited_two_hex_digit_decode(int param_1)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar4 = (uint)*(ushort *)PTR_DAT_03011b20;
  if (*(ushort *)(PTR_DAT_03011b20 + 1) != 0) {
    uVar3 = 0;
    do {
      if (0x3ff < uVar4) {
        uVar4 = 0;
      }
      if (*(char *)(param_1 + uVar4) == '*') break;
      uVar4 = uVar4 + 1 & 0xffff;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(ushort *)(PTR_DAT_03011b20 + 1));
  }
  cVar1 = hex_digit_to_value(*(undefined1 *)(param_1 + uVar4 + 1));
  bVar2 = hex_digit_to_value(*(undefined1 *)(param_1 + uVar4 + 2));
  return bVar2 | cVar1 << 4;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: nmea_sentence_checksum_from_ring_buffer @ 0301192c (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: gps
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte nmea_sentence_checksum_from_ring_buffer(int param_1)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar4 = *(ushort *)PTR_DAT_030119a0;
  uVar1 = *(ushort *)(PTR_DAT_030119a0 + 4);
  if (uVar1 == 0) {
    return 0;
  }
  uVar3 = 0;
  while( true ) {
    uVar5 = (uint)uVar4;
    if (0x3ff < uVar5) {
      uVar5 = 0;
    }
    if (*(char *)(param_1 + uVar5) == '$') break;
    uVar3 = uVar3 + 1;
    if (uVar1 <= uVar3) {
      return 0;
    }
    uVar4 = (short)uVar5 + 1;
  }
  if (uVar1 <= uVar3) {
    return 0;
  }
  bVar2 = 0;
  while( true ) {
    uVar5 = uVar5 + 1 & 0xffff;
    if (0x3ff < uVar5) {
      uVar5 = 0;
    }
    if (*(byte *)(param_1 + uVar5) == 0x2a) break;
    bVar2 = bVar2 ^ *(byte *)(param_1 + uVar5);
    uVar3 = uVar3 + 1;
    if (uVar1 <= uVar3) {
      return bVar2;
    }
  }
  return bVar2;
}


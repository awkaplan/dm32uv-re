/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bitarray_set_or_clear_bit @ 03052dc4 (file base 0x03000000; code starts at 0x03001000)
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

void bitarray_set_or_clear_bit(uint param_1,int param_2,char param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar2 = (param_1 & 0xff) - 1;
  uVar4 = uVar2;
  if ((uVar2 & 0x80000000) != 0) {
    uVar4 = (param_1 & 0xff) + 6;
  }
  pbVar5 = (byte *)(param_2 + (uVar4 >> 3 & 0xff));
  uVar2 = uVar2 & 0x80000007;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  bVar1 = (byte)(1 << (uVar2 & 0x3f));
  bVar3 = *pbVar5 & ~bVar1;
  *pbVar5 = bVar3;
  if (param_3 == '\0') {
    *pbVar5 = bVar1 | bVar3;
  }
  return;
}


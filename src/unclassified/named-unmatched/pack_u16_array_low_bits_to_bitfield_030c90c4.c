/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: pack_u16_array_low_bits_to_bitfield @ 030c90c4 (file base 0x03000000; code starts at 0x03001000)
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

ushort pack_u16_array_low_bits_to_bitfield(int param_1,short param_2)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  
  if (param_2 < 1) {
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    uVar2 = 0;
    do {
      puVar1 = (ushort *)(param_1 + iVar3);
      iVar3 = iVar3 + 2;
      uVar2 = uVar2 * 2 | *puVar1;
    } while (iVar3 != ((ushort)(param_2 - 1) + 1) * 2);
  }
  return uVar2;
}


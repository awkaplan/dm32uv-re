/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: unpack_bits_lsb_first_to_u16_array_signed @ 030c9128 (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int unpack_bits_lsb_first_to_u16_array_signed(uint param_1,int param_2,int param_3__w)

{
  short param_3 = (short)param_3__w;
  short sVar1;
  ushort *puVar2;
  
  sVar1 = param_3 + -1;
  if (-1 < sVar1) {
    puVar2 = (ushort *)(sVar1 * 2 + param_2);
    do {
      sVar1 = sVar1 + -1;
      *puVar2 = (ushort)param_1 & 1;
      param_1 = ((param_1 & 0xffff) >> 1 ^ 0x4000) - 0x4000;
      puVar2 = puVar2 + -1;
    } while (-1 < sVar1);
  }
  return param_2 + param_3 * 2;
}


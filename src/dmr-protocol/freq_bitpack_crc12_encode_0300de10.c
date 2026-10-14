/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: freq_bitpack_crc12_encode @ 0300de10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint freq_bitpack_crc12_encode(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  
  uVar2 = (param_1 & 0xffff) >> 1 & 0x38 | (param_1 & 0xffff) >> 2 & 0x1c0 | param_1 & 7 | 0x800;
  uVar1 = 0;
  cVar4 = '\0';
  uVar3 = uVar2;
  while( true ) {
    if (((uVar1 >> 1 ^ uVar3) & 1) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0xc75;
    }
    uVar1 = uVar1 >> 1 ^ uVar5;
    cVar4 = cVar4 + '\x01';
    if (cVar4 == '\f') break;
    uVar3 = uVar3 >> 1;
  }
  return uVar2 | uVar1 << 0xb;
}


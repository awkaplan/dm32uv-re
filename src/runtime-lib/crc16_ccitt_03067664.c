/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: crc16_ccitt @ 03067664 (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: runtime-lib
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

ushort crc16_ccitt(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    uVar6 = 0;
    do {
      uVar2 = byte_bit_reverse(*(undefined1 *)(param_1 + uVar6));
      iVar4 = 8;
      uVar5 = 0x80;
      do {
        uVar3 = uVar1 & 0x8000;
        if ((uVar5 & uVar2) != 0) {
          uVar3 = uVar3 ^ 0x8000;
        }
        uVar1 = uVar1 * 2;
        if (uVar3 != 0) {
          uVar1 = uVar1 ^ 0x1021;
        }
        uVar5 = uVar5 >> 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_2);
  }
  uVar1 = u16_byte_swap_via_lookup(uVar1);
  return ~uVar1;
}


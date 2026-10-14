/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_num_to_block_offset @ 03055924 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_num_to_block_offset(ushort param_1,short *param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  
  if (param_1 < 0x55) {
    sVar1 = (param_1 - 1) * 0x30 + 0x20;
    sVar2 = 0x12;
  }
  else {
    param_1 = param_1 - 0x54;
    uVar3 = param_1 / 0x55;
    sVar2 = uVar3 + 0x13;
    if ((uint)param_1 % 0x55 == 0) {
      sVar2 = uVar3 + 0x12;
      uVar3 = uVar3 - 1;
    }
    sVar1 = ((param_1 + uVar3 * -0x55 & 0xff) - 1) * 0x30 + 0x10;
  }
  *param_2 = sVar2;
  *param_3 = sVar1;
  return;
}


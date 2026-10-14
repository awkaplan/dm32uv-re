/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bcd_pack_and_write_flash_block4_0x702 @ 03065918 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void bcd_pack_and_write_flash_block4_0x702(uint param_1)

{
  uint uVar1;
  byte *pbVar2;
  byte local_10 [3];
  byte bStack_d;
  
  pbVar2 = local_10;
  do {
    uVar1 = (param_1 % 100) / 10;
    *pbVar2 = (char)(param_1 % 100) + (char)uVar1 * -10 | (byte)(uVar1 << 4);
    pbVar2 = pbVar2 + 1;
    param_1 = param_1 / 100;
  } while (pbVar2 != &bStack_d);
  flash_block_write(4,0x702,local_10,3);
  return;
}


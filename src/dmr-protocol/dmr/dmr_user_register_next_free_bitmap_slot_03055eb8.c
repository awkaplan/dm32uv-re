/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_user_register_next_free_bitmap_slot @ 03055eb8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_user_register_next_free_bitmap_slot(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  byte abStack_14 [4];
  
  uVar2 = count_set_bits_in_flash_field();
  if (uVar2 < 0x20) {
    flash_field_read_cached(0xf,0,abStack_14,4);
    uVar3 = uVar2 >> 3 & 0xff;
    abStack_14[uVar3] = (byte)(1 << (uVar2 & 7)) | abStack_14[uVar3];
    flash_block_write(0xf,0,abStack_14,4);
    sVar1 = count_set_bits_in_flash_field();
    *(char *)PTR_DAT_03056020 = (char)sVar1;
    flash_block_write(0xf,(sVar1 + -1) * 0x6d + 0x11,param_1,0xb);
  }
  return;
}


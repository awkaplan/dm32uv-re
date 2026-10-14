/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_read_modify_write_96b @ 03055c4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 116 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_block_read_modify_write_96b(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_70 [96];
  
  param_1 = param_1 & 0xff;
  memset_bytes(auStack_70,0,0x60);
  uVar2 = ((param_2 & 0xff) - 1) * 3 & 0xff;
  if (uVar2 != 0) {
    flash_field_read_cached(0xf,(param_1 - 1) * 0x6d + 0x1c & 0xffff,auStack_70,uVar2);
  }
  uVar1 = (param_2 & 0xff) * 3 & 0xff;
  if (uVar1 < 0x60) {
    flash_field_read_cached
              (0xf,uVar1 + 0x1c + (param_1 - 1) * 0x6d & 0xffff,auStack_70 + uVar2,
               0x60 - uVar1 & 0xffff);
  }
  flash_block_write(0xf,(param_1 - 1) * 0x6d + 0x1c & 0xffff,auStack_70,0x60);
  return;
}


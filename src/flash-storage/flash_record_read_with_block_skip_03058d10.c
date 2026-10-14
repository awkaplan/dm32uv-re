/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_read_with_block_skip @ 03058d10 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_record_read_with_block_skip(uint param_1,char param_2,void *param_3)

{
  ushort block_id;
  byte bVar1;
  char cVar2;
  ushort local_1e;
  
  local_1e = 0x15;
  cVar2 = *(char *)(*(int *)(PTR_LAB_03058e38 + (param_1 & 0xff) * 4) + 4) + '\x01';
  block_id = flash_block_id_resolve_locked(PTR_LAB_03058e38[(param_1 & 0xff) - 1]);
  if (cVar2 != param_2) {
    bVar1 = 0;
    do {
      flash_block_read(block_id,(uint)local_1e,&local_1e,2);
      bVar1 = bVar1 + 1;
    } while (bVar1 < (byte)(cVar2 - param_2));
  }
  flash_block_read(block_id,(uint)(ushort)(local_1e + 5),param_3,9);
  return;
}


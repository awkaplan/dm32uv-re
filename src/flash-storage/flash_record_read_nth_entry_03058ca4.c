/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_record_read_nth_entry @ 03058ca4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 flash_record_read_nth_entry(uint param_1,char param_2)

{
  ushort block_id;
  byte bVar1;
  char cVar2;
  undefined4 local_20;
  ushort local_1a;
  
  local_20 = 0;
  local_1a = 0x15;
  cVar2 = *(char *)(*(int *)(PTR_LAB_03058e38 + (param_1 & 0xff) * 4) + 4) + '\x01';
  block_id = flash_block_id_resolve_locked(PTR_LAB_03058e38[(param_1 & 0xff) - 1]);
  if (cVar2 != param_2) {
    bVar1 = 0;
    do {
      flash_block_read(block_id,(uint)local_1a,&local_1a,2);
      bVar1 = bVar1 + 1;
    } while (bVar1 < (byte)(cVar2 - param_2));
  }
  flash_block_read(block_id,(uint)(ushort)(local_1a + 2),&local_20,3);
  return local_20;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_chain_walk_to_slot @ 03058f18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

ushort flash_chain_walk_to_slot(uint param_1,char param_2)

{
  ushort block_id;
  byte bVar1;
  char cVar2;
  ushort uStack_1a;
  
  uStack_1a = 0x15;
  cVar2 = *(char *)(*(int *)(PTR_LAB_03058f9c + (param_1 & 0xff) * 4) + 4) + '\x01';
  block_id = flash_block_id_resolve_locked(PTR_LAB_03058f9c[(param_1 & 0xff) - 1]);
  if (cVar2 != param_2) {
    bVar1 = 0;
    do {
      flash_block_read(block_id,(uint)uStack_1a,&uStack_1a,2);
      bVar1 = bVar1 + 1;
    } while (bVar1 < (byte)(cVar2 - param_2));
  }
  return uStack_1a;
}


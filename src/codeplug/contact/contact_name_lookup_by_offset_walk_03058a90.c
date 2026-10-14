/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_name_lookup_by_offset_walk @ 03058a90 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_name_lookup_by_offset_walk(uint param_1,char param_2,undefined4 param_3)

{
  byte bVar1;
  undefined *puVar2;
  ushort block_id;
  byte bVar3;
  int iVar4;
  char cVar5;
  undefined4 local_28;
  ushort local_22;
  
  puVar2 = PTR_LAB_03058c70;
  local_28 = 0;
  local_22 = 0x15;
  bVar1 = p_vfo_display_state->flags_0x8;
  iVar4 = (param_1 & 0xff) - 1;
  block_id = flash_block_id_resolve_locked(PTR_LAB_03058c70[iVar4]);
  cVar5 = *(char *)(*(int *)(puVar2 + iVar4 * 4 + 4) + 4) + '\x01';
  if (cVar5 != param_2) {
    bVar3 = 0;
    do {
      flash_block_read(block_id,(uint)local_22,&local_22,2);
      bVar3 = bVar3 + 1;
    } while (bVar3 < (byte)(cVar5 - param_2));
  }
  flash_block_read(block_id,(uint)(ushort)(local_22 + 2),&local_28,3);
  contact_name_lookup_or_format(bVar1 >> 4,local_28,param_3,3);
  return;
}


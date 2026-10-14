/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: roam_zone_slot_byte_write_with_wear_count @ 030666d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 78 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void roam_zone_slot_byte_write_with_wear_count(uint param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_28 [16];
  
  iVar1 = (param_1 & 0xff) * 0x21;
  iVar3 = iVar1 + 0x21;
  flash_field_read_cached(0x65,iVar3,auStack_28,0x10);
  puVar2 = PTR_DAT_03066730;
  auStack_28[*(byte *)PTR_DAT_03066730] = param_2;
  flash_block_write(0x65,iVar3,auStack_28,0x10);
  *(char *)puVar2 = *(char *)puVar2 + '\x01';
  flash_field_write_cached(0x65,iVar1 + 0x20);
  roam_zone_record_init();
  return;
}


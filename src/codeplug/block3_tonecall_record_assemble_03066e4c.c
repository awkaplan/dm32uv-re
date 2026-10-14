/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block3_tonecall_record_assemble @ 03066e4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void block3_tonecall_record_assemble(void)

{
  ushort block_id;
  byte bStack_14;
  undefined1 uStack_13;
  
  block_id = flash_block_id_resolve_locked(3);
  flash_block_read(block_id,0x30,PTR_DAT_03066efc,5);
  flash_block_read(block_id,0x3f,&bStack_14,2);
  if ((bStack_14 & 2) == 0) {
    PTR_DAT_03066efc[6] = PTR_DAT_03066efc[6] & 0xfe;
  }
  else {
    PTR_DAT_03066efc[6] = PTR_DAT_03066efc[6] & 0xfe | 1;
  }
  PTR_DAT_03066efc[5] = uStack_13;
  return;
}


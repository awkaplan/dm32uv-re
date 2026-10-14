/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bdc_table_lookup_by_id @ 03067fb4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 bdc_table_lookup_by_id(undefined2 param_1,undefined2 *param_2)

{
  ushort block_id;
  ushort uVar1;
  uint uVar2;
  uint offset;
  uint uVar3;
  ushort local_28;
  char cStack_25;
  
  block_id = flash_block_id_resolve_locked(6);
  uVar2 = bdc_table_count_read();
  uVar1 = decimal_to_bcd_pack(param_1);
  if (uVar2 != 0) {
    offset = 0xab0;
    uVar3 = 0;
    do {
      flash_block_read(block_id,offset,&local_28,4);
      if ((local_28 == uVar1) && (cStack_25 == '\0')) {
        *param_2 = (short)uVar3;
        return 1;
      }
      uVar3 = uVar3 + 1 & 0xffff;
      offset = offset + 0x14 & 0xffff;
    } while (uVar3 < uVar2);
  }
  return 0;
}


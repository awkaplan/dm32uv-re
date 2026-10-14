/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_u16_scan_find_index @ 030347d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

short flash_block_u16_scan_find_index(ushort param_1,ushort param_2)

{
  ushort block_id;
  uint offset;
  ushort uVar1;
  ushort local_22;
  
  block_id = flash_block_id_resolve_locked(0xb);
  if (param_2 != 0) {
    offset = 0x740;
    uVar1 = 0;
    do {
      flash_block_read(block_id,offset,&local_22,2);
      local_22 = local_22 & 0xfff;
      if (local_22 == param_1) {
        if (param_2 <= uVar1) {
          return 0;
        }
        return uVar1 + 1;
      }
      uVar1 = uVar1 + 1;
      offset = offset + 2 & 0xffff;
    } while (uVar1 < param_2);
  }
  return 0;
}


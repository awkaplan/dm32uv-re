/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_list_index_resolve @ 03056264 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

ushort channel_list_index_resolve(undefined1 param_1,ushort param_2)

{
  short local_18;
  byte local_15;
  undefined1 local_14 [2];
  ushort local_12;
  
  channel_offset_minus_0x10(param_1,local_14,&local_18);
  flash_field_read_cached(local_14[0],local_18 + 0x10,&local_15,1);
  if ((ushort)local_15 < (param_2 & 0xff)) {
    local_12 = 1;
  }
  else {
    flash_field_read_cached(local_14[0],local_18 + 0x11 + ((param_2 & 0xff) - 1) * 2,&local_12,2);
    if (4000 < local_12) {
      local_12 = 1;
    }
  }
  return local_12;
}


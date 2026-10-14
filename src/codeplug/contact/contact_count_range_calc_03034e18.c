/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_count_range_calc @ 03034e18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

short contact_count_range_calc(int param_1__w)

{
  char param_1 = (char)param_1__w;
  ushort block_id;
  short local_1c;
  short local_1a;
  undefined1 auStack_18 [2];
  undefined1 auStack_16 [2];
  byte bStack_14;
  
  local_1c = 0;
  block_id = flash_block_id_resolve_locked(0xb);
  flash_block_read(block_id,0,auStack_18,5);
  memcpy_bytes_iram(&local_1a,auStack_18,2);
  memcpy_bytes_iram(&local_1c,auStack_16,2);
  if (param_1 == '\x05') {
    local_1a = (local_1a - local_1c) - (ushort)bStack_14;
  }
  else if (param_1 == '\x02') {
    local_1a = local_1a - (ushort)bStack_14;
  }
  else if (param_1 == '\x06') {
    local_1a = local_1c;
  }
  return local_1a;
}


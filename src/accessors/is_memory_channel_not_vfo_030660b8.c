/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: is_memory_channel_not_vfo @ 030660b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool is_memory_channel_not_vfo(void)

{
  bool bVar1;
  
  if (((*(byte *)PTR_DAT_03066180 & 8) == 0) || ((p_dm32_settings_block04[0x2d] & 0x80) != 0)) {
    if ((*(byte *)PTR_DAT_03066180 & 0x10) == 0) {
      bVar1 = false;
    }
    else {
      bVar1 = (p_dm32_settings_block04[0x2d] & 0x80) != 0;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


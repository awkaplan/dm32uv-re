/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_id_resolve_helper2 @ 0300f6c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint flash_block_id_resolve_helper2(char param_1)

{
  uint uVar1;
  
  if ((byte)*PTR_DAT_0300f83c == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
    do {
      if ((0xfd < (byte)(PTR_DAT_0300f840[uVar1] - 1)) && (PTR_DAT_0300f840[uVar1] != param_1))
      break;
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 <= (byte)*PTR_DAT_0300f83c);
  }
  spi_flash_sector_erase(uVar1);
  return uVar1 & 0xff;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_page_invalidate_range @ 0300f318 (file base 0x03000000; code starts at 0x03001000)
 * Size: 52 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_page_invalidate_range(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  puVar2 = PTR_DAT_0300f4f0;
  puVar1 = PTR_DAT_0300f4ec;
  uVar3 = (uint)*DAT_0300f4e8;
  if (uVar3 <= *(byte *)PTR_DAT_0300f4ec) {
    do {
      spi_flash_read_seq(uVar3,0xfff,puVar2 + uVar3,1);
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 <= *(byte *)puVar1);
  }
  return;
}


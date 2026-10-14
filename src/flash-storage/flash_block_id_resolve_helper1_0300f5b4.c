/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_block_id_resolve_helper1 @ 0300f5b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

uint flash_block_id_resolve_helper1(void)

{
  undefined4 *puVar1;
  uint uVar2;
  ushort uVar3;
  char local_1d;
  
  uVar2 = flash_block_id_resolve(0xff);
  puVar1 = PTR_DAT_0300f684;
  if ((byte)*PTR_DAT_0300f6a8 < uVar2) {
    uVar3 = (ushort)*(byte *)PTR_DAT_0300f67c;
    if (uVar3 <= *(byte *)PTR_DAT_0300f684) {
      do {
        spi_flash_read_seq(uVar3,0xfff,&local_1d,1);
        if (local_1d == '\0') {
          spi_flash_sector_erase(uVar3);
          break;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 <= *(byte *)puVar1);
    }
    flash_page_invalidate_range();
    uVar2 = flash_block_id_resolve(0xff);
  }
  else {
    spi_flash_sector_erase();
  }
  return uVar2 & 0xff;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_dual_range_invalidate @ 03010b40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 148 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_dual_range_invalidate(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined1 local_d;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  puVar1 = PTR_DAT_03010ce0;
  uVar2 = (uint)*(ushort *)PTR_DAT_03010cdc;
  if (uVar2 <= (uint)*PTR_DAT_03010ce0) {
    do {
      spi_flash_sector_erase(uVar2);
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 <= (uint)*puVar1);
  }
  puVar1 = PTR_DAT_03010ce8;
  uVar2 = (uint)*(ushort *)PTR_DAT_03010ce4;
  if (uVar2 <= (uint)*PTR_DAT_03010ce8) {
    do {
      spi_flash_sector_erase(uVar2);
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 <= (uint)*puVar1);
  }
  local_d = 0xa5;
  spi_flash_program_pagesplit(*(undefined2 *)PTR_DAT_03010cdc,0xfff,&local_d,1);
  puVar1 = PTR_DAT_03010ce4;
  spi_flash_program_pagesplit(*(undefined2 *)PTR_DAT_03010ce4,0xfff,&local_d,1);
  local_d = 0xa6;
  spi_flash_program_pagesplit(*puVar1 + 1 & 0xffff,0xfff,&local_d,1);
  os_sem_post(p_ucos_mutex_0003944c);
  return;
}


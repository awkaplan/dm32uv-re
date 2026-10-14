/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_pagesplit_write_with_split_markers @ 030611d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void flash_pagesplit_write_with_split_markers(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined1 uStack_d;
  
  puVar1 = PTR_DAT_03061274;
  uVar2 = (uint)*(ushort *)PTR_DAT_03061270;
  if (uVar2 <= (uint)*PTR_DAT_03061274) {
    do {
      spi_flash_sector_erase(uVar2);
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 <= (uint)*puVar1);
  }
  puVar1 = PTR_DAT_0306127c;
  uVar2 = (uint)*(ushort *)PTR_DAT_03061278;
  if (uVar2 <= (uint)*PTR_DAT_0306127c) {
    do {
      spi_flash_sector_erase(uVar2);
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 <= (uint)*puVar1);
  }
  uStack_d = 0xa5;
  spi_flash_program_pagesplit(*(undefined2 *)PTR_DAT_03061270,0xfff,&uStack_d,1);
  puVar1 = PTR_DAT_03061278;
  spi_flash_program_pagesplit(*(undefined2 *)PTR_DAT_03061278,0xfff,&uStack_d,1);
  uStack_d = 0xa6;
  spi_flash_program_pagesplit(*puVar1 + 1 & 0xffff,0xfff,&uStack_d,1);
  return;
}


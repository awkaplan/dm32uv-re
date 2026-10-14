/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: spi_flash_pending_update_scan_and_invalidate @ 0300f3d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 278 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-spi
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void spi_flash_pending_update_scan_and_invalidate(void)

{
  undefined4 *puVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  byte bStack_26;
  byte bStack_25;
  
  os_sem_pend_ms(_DAT_0300f4f4,0);
  puVar1 = PTR_DAT_0300f4ec;
  uVar4 = (ushort)*DAT_0300f4e8;
  if (uVar4 <= *(byte *)PTR_DAT_0300f4ec) {
    uVar5 = uVar4;
    do {
      uVar5 = uVar5 + 1 & 0xff;
      spi_flash_read_seq(uVar4,0xfff,&bStack_25,1);
      if (bStack_25 == 0x7f) {
        spi_flash_sector_erase(uVar4);
      }
      else if ((bStack_25 ^ 0x80) < 0x7f) {
        spi_flash_sector_erase(uVar4);
        busy_wait_delay_loop_short(0x32);
      }
      else if (((byte)(bStack_25 - 1) < 0xfe) && (uVar3 = uVar5, uVar5 <= *(byte *)puVar1)) {
        do {
          spi_flash_read_seq(uVar3,0xfff,&bStack_26,1);
          if (bStack_25 == bStack_26) {
            spi_flash_sector_erase(uVar3);
          }
          uVar3 = uVar3 + 1 & 0xff;
        } while (uVar3 <= *(byte *)puVar1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= *(byte *)puVar1);
  }
  flash_page_invalidate_range();
  uVar2 = flash_block_id_resolve(0xff);
  puVar1 = PTR_DAT_0300f4ec;
  if ((byte)*PTR_DAT_0300f4f8 < uVar2) {
    uVar4 = (ushort)*DAT_0300f4e8;
    if (uVar4 <= *(byte *)PTR_DAT_0300f4ec) {
      do {
        spi_flash_read_seq(uVar4,0xfff,&bStack_25,1);
        if (bStack_25 == 0) {
          spi_flash_sector_erase(uVar4);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 <= *(byte *)puVar1);
    }
    flash_page_invalidate_range();
  }
  os_sem_post(_DAT_0300f4f4);
  return;
}


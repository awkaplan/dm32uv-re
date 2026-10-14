/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_bitmap_flash_rebuild @ 03061b0c (file base 0x03000000; code starts at 0x03001000)
 * Size: 470 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_bitmap_flash_rebuild(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  int local_34;
  ushort local_28;
  ushort local_26;
  
  uVar4 = flash_page_tag_search(1,0xa5);
  uVar5 = flash_page_tag_search(0,0xa5);
  spi_flash_read_seq(uVar5,0,PTR_DAT_03061ce4,0x200);
  puVar3 = PTR_DAT_03061cec;
  puVar2 = PTR_DAT_03061ce8;
  puVar1 = PTR_DAT_03061ce4;
  local_34 = 0;
  do {
    spi_flash_read_seq(uVar4,local_34,&local_28,2);
    iVar9 = 0x1e;
    sVar8 = 0;
    do {
      if (sVar8 == 0) {
        local_26 = local_28;
      }
      else {
        spi_flash_read_seq(local_28,iVar9,&local_26,2);
      }
      uVar7 = (uint)local_26;
      if (uVar7 == 0xffff) break;
      if ((uint)*puVar2 < uVar7) {
        if ((PTR_DAT_03061cf0[0x2b] & 4) != 0) {
          os_sem_post(p_ucos_mutex_0003944c);
          recording_stop_tx_finalize();
          recording_stop_rx_finalize();
          os_sem_pend_ms(p_ucos_mutex_0003944c,0);
        }
        os_sem_post(p_ucos_mutex_0003944c);
        flash_dual_range_invalidate();
        os_sem_pend_ms(p_ucos_mutex_0003944c,0);
        uVar4 = flash_page_tag_search(1,0xa5);
        uVar5 = flash_page_tag_search(0,0xa5);
        spi_flash_read_seq(uVar5,0,puVar1,0x200);
        break;
      }
      uVar7 = uVar7 - *puVar3;
      local_26 = (ushort)uVar7;
      uVar6 = (uVar7 & 0xffff) >> 3;
      if (0x1ff < uVar6) break;
      *(byte *)((int)puVar1 + uVar6) = (byte)(1 << (uVar7 & 7)) | *(byte *)((int)puVar1 + uVar6);
      sVar8 = sVar8 + 1;
      iVar9 = iVar9 + 2;
    } while (sVar8 != 0x7f1);
    local_34 = local_34 + 2;
    if (local_34 == 0x28) {
      local_26 = flash_page_find_first_free(0);
      spi_flash_sector_erase();
      puVar1 = PTR_DAT_03061ce4;
      spi_flash_program_pagesplit(local_26,0,PTR_DAT_03061ce4,0x200);
      local_28 = flash_page_find_first_free(1);
      spi_flash_sector_erase();
      memset_ck803s(puVar1,0xff,0xff0);
      iVar9 = 0x28;
      do {
        spi_flash_read_seq(uVar4,iVar9,(int)puVar1 + iVar9 + -0x28,2);
        iVar9 = iVar9 + 2;
      } while (iVar9 != 0xff0);
      spi_flash_shadow_addr_set(local_28,0);
      puVar1 = PTR_DAT_03061ce4;
      spi_flash_write_chunk_pagesplit(PTR_DAT_03061ce4,*PTR_DAT_03061cf8,0xff0);
      *(undefined1 *)puVar1 = 0xa5;
      spi_flash_program_pagesplit(local_26,0xfff,puVar1,1);
      spi_flash_program_pagesplit(local_28,0xfff,puVar1,1);
      *(undefined1 *)puVar1 = 0;
      spi_flash_program_pagesplit(uVar5,0xfff,puVar1,1);
      spi_flash_program_pagesplit(uVar4,0xfff,puVar1,1);
      return;
    }
  } while( true );
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_list_compact_and_delete_entry @ 03010978 (file base 0x03000000; code starts at 0x03001000)
 * Size: 440 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_list_compact_and_delete_entry(ushort param_1)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  undefined1 local_29;
  ushort local_28;
  ushort local_26;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  puVar4 = malloc_best_fit(0x200);
  if (puVar4 != (undefined1 *)0x0) {
    if (param_1 < 0x7f9) {
      uVar2 = flash_page_tag_search(1,0xa5);
      local_29 = 0xa5;
    }
    else {
      uVar2 = flash_page_tag_search(1,0xa6);
      param_1 = param_1 - 0x7f8;
      local_29 = 0xa6;
    }
    uVar3 = flash_page_tag_search(0,0xa5);
    spi_flash_read_seq(uVar3,0,puVar4,0x200);
    spi_flash_read_seq(uVar2,param_1 * 2,&local_28,2);
    puVar1 = PTR_DAT_03010b34;
    iVar10 = 0x1e;
    sVar7 = 0;
    do {
      if (sVar7 == 0) {
        local_26 = local_28;
      }
      else {
        spi_flash_read_seq(local_28,iVar10,&local_26,2);
      }
      if (local_26 == 0xffff) break;
      uVar6 = (uint)local_26 - *puVar1;
      local_26 = (ushort)uVar6;
      uVar5 = (uVar6 & 0xffff) >> 3;
      if (0x1ff < uVar5) break;
      puVar4[uVar5] = (byte)(1 << (uVar6 & 7)) | puVar4[uVar5];
      sVar7 = sVar7 + 1;
      iVar10 = iVar10 + 2;
    } while (sVar7 != 0x7f1);
    local_26 = flash_page_find_first_free(0);
    spi_flash_sector_erase();
    spi_flash_program_pagesplit(local_26,0,puVar4,0x200);
    local_28 = flash_page_find_first_free(1);
    spi_flash_sector_erase();
    memset_ck803s(DAT_03010b38,0xff,0xff0);
    iVar10 = DAT_03010b38;
    iVar9 = 0;
    uVar8 = 0;
    uVar5 = 0;
    do {
      if (uVar8 != param_1) {
        spi_flash_read_seq(uVar2,iVar9,iVar10 + uVar5,2);
        uVar5 = uVar5 + 2 & 0xffff;
      }
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 2;
    } while (uVar8 != 0x7f8);
    spi_flash_shadow_addr_set(local_28,0);
    spi_flash_write_chunk_pagesplit(DAT_03010b38,*PTR_DAT_03010b3c,0xff0);
    *puVar4 = 0xa5;
    spi_flash_program_pagesplit(local_26,0xfff,puVar4,1);
    spi_flash_program_pagesplit(local_28,0xfff,&local_29,1);
    *puVar4 = 0;
    spi_flash_program_pagesplit(uVar3,0xfff,puVar4,1);
    spi_flash_program_pagesplit(uVar2,0xfff,puVar4,1);
    heap_free_with_adjacent_coalesce(puVar4);
  }
  os_sem_post(p_ucos_mutex_0003944c);
  return;
}


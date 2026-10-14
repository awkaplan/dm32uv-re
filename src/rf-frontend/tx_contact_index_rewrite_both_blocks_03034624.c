/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_contact_index_rewrite_both_blocks @ 03034624 (file base 0x03000000; code starts at 0x03001000)
 * Size: 406 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_contact_index_rewrite_both_blocks(int param_1__w,uint param_2)

{
  ushort param_1 = (ushort)param_1__w;
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  byte abStack_a4 [34];
  byte abStack_82 [93];
  undefined1 uStack_25;
  
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar2 = flash_block_id_resolve_helper1();
  iVar3 = flash_block_id_resolve(0x42);
  flash_page_tag_write(uVar2,0x7f);
  uVar8 = 0;
  do {
    iVar9 = (uVar8 & 0x1ff) << 7;
    spi_flash_read_seq(iVar3,iVar9,abStack_a4,0x80);
    uVar5 = 0;
    do {
      bVar1 = abStack_a4[uVar5];
      bVar7 = (byte)(param_2 & 0xffff);
      if ((ushort)((bVar1 & 0xf0) << 4 | (ushort)abStack_a4[uVar5 + 1]) == param_1) {
        abStack_a4[uVar5] = bVar1 & 0xf | bVar7;
      }
      uVar5 = uVar5 + 2 & 0xff;
    } while (uVar5 != 0x80);
    if (uVar8 == 0x1f) {
      uStack_25 = 0x42;
      spi_flash_program_pagesplit(uVar2,0xf80,abStack_a4,0x80);
      break;
    }
    spi_flash_program_pagesplit(uVar2,iVar9,abStack_a4,0x80);
    uVar8 = uVar8 + 1;
  } while (uVar8 != 0x20);
  flash_page_tag_write(iVar3,0);
  uVar2 = flash_block_id_resolve_helper1();
  iVar3 = flash_block_id_resolve(0x43);
  flash_page_tag_write(uVar2,0x7f);
  uVar8 = 0;
  while( true ) {
    iVar9 = (uVar8 & 0x1ff) << 7;
    spi_flash_read_seq(iVar3,iVar9,abStack_a4,0x80);
    if ((uVar8 & 0xff) < 0x10) {
      uVar5 = 0;
      do {
        bVar1 = abStack_a4[uVar5];
        if ((ushort)((bVar1 & 0xf0) << 4 | (ushort)abStack_a4[uVar5 + 1]) == param_1) {
          abStack_a4[uVar5] = bVar1 & 0xf | bVar7;
        }
        uVar5 = uVar5 + 2 & 0xff;
      } while (uVar5 != 0x80);
    }
    else if ((uVar8 & 0xff) < 0x11) {
      pbVar4 = abStack_a4 + 1;
      pbVar6 = abStack_a4;
      do {
        if ((ushort)((ushort)*pbVar6 | (ushort)*pbVar4 << 4) == param_1) {
          *pbVar6 = bVar7;
          *pbVar4 = (byte)((param_2 & 0xffff) >> 8);
        }
        pbVar4 = pbVar4 + 2;
        pbVar6 = pbVar6 + 2;
      } while (pbVar6 != abStack_82);
    }
    if (uVar8 == 0x1f) break;
    spi_flash_program_pagesplit(uVar2,iVar9,abStack_a4,0x80);
    uVar8 = uVar8 + 1;
    if (uVar8 == 0x20) {
LAB_030347bc:
      flash_page_tag_write(iVar3,0);
      flash_page_invalidate_range();
      os_sem_post(p_ucos_mutex_0003944c);
      return;
    }
  }
  uStack_25 = 0x43;
  spi_flash_program_pagesplit(uVar2,0xf80,abStack_a4,0x80);
  goto LAB_030347bc;
}


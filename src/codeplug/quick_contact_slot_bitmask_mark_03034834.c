/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: quick_contact_slot_bitmask_mark @ 03034834 (file base 0x03000000; code starts at 0x03001000)
 * Size: 414 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 quick_contact_slot_bitmask_mark(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  byte local_a9;
  undefined1 auStack_a8 [16];
  byte abStack_98 [112];
  ushort local_28;
  ushort local_26;
  
  uVar2 = get_block0xb_u16_field0();
  uVar3 = flash_block_id_resolve_locked(0xb);
  os_sem_pend_ms(p_ucos_mutex_0003e40c,0);
  flash_block_read((ushort)uVar3,((param_2 & 0xffff) + 0x7f) * 2 & 0xffff,&local_26,2);
  local_26 = local_26 & 0xfff;
  iVar4 = flash_block_u16_scan_find_index(local_26,uVar2);
  os_sem_pend_ms(p_ucos_mutex_0003944c,0);
  uVar5 = flash_block_id_resolve_helper1();
  flash_page_tag_write(uVar5,0x7f);
  spi_flash_read_seq(uVar3,0,auStack_a8,0x80);
  local_28 = (short)uVar2 - 1;
  memcpy_bytes_iram(auStack_a8,&local_28,2);
  index_1based_to_slot_and_bit(local_26,&local_28,&local_a9);
  auStack_a8[local_28 + 0x10] = (byte)(1 << (local_a9 & 0x3f)) | auStack_a8[local_28 + 0x10];
  spi_flash_program_pagesplit(uVar5,0,auStack_a8,0x80);
  iVar1 = DAT_030349bc;
  local_28 = 0;
  if (uVar2 == 0) {
    spi_flash_shadow_addr_set(uVar5,0x100);
    spi_flash_write_chunk_pagesplit(DAT_03034b98,*PTR_DAT_03034b9c,0);
    local_28 = 0;
    uVar6 = 0;
  }
  else {
    uVar6 = 0;
    uVar7 = 0;
    do {
      if ((param_2 & 0xffff) != uVar6 + 1) {
        spi_flash_read_seq(uVar3,(uVar6 + 0x80) * 2 & 0xffff,iVar1 + uVar7,2);
        uVar7 = uVar7 + 2 & 0xffff;
      }
      local_28 = local_28 + 1;
      uVar6 = (uint)local_28;
    } while (uVar6 < uVar2);
    spi_flash_shadow_addr_set(uVar5,0x100);
    spi_flash_write_chunk_pagesplit(DAT_030349bc,*PTR_DAT_030349c0,uVar7);
    iVar1 = DAT_030349bc;
    local_28 = 0;
    uVar7 = 0;
    uVar6 = 0;
    do {
      if (uVar7 + 1 != iVar4) {
        spi_flash_read_seq(uVar3,(uVar7 + 0x3a0) * 2 & 0xffff,iVar1 + uVar6,2);
        uVar6 = uVar6 + 2 & 0xffff;
      }
      local_28 = local_28 + 1;
      uVar7 = (uint)local_28;
    } while (uVar7 < uVar2);
  }
  spi_flash_shadow_addr_set(uVar5,0x740);
  spi_flash_write_chunk_pagesplit(DAT_030349bc,*PTR_DAT_030349c0,uVar6);
  flash_page_tag_write(uVar5,0xb);
  flash_page_tag_write(uVar3,0);
  flash_page_invalidate_range();
  os_sem_post(p_ucos_mutex_0003944c);
  os_sem_post(p_ucos_mutex_0003e40c);
  return 1;
}


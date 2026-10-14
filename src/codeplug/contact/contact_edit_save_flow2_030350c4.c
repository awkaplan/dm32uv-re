/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_edit_save_flow2 @ 030350c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 800 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 contact_edit_save_flow2(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  short sStack_ca;
  ushort uStack_c8;
  byte bStack_c5;
  undefined1 auStack_c4 [16];
  byte abStack_b4 [112];
  undefined4 uStack_44;
  ushort uStack_40;
  ushort uStack_3e;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  byte bStack_38;
  byte bStack_37;
  undefined1 auStack_36 [17];
  undefined1 auStack_25 [5];
  
  os_sem_pend_ms(p_ucos_mutex_0003e40c,0);
  uStack_c8 = get_block0xb_u16_field0();
  sStack_ca = contact_count_range_calc(6);
  dmr_contact_record_copy(&bStack_38,param_1,0);
  cVar2 = talkgroup_lookup_by_name(auStack_36,&uStack_3e,uStack_c8);
  if (cVar2 == '\0') {
    uStack_44 = 0;
    memcpy_bytes_iram(&uStack_44,auStack_25,3);
    if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
      cVar2 = talkgroup_binary_search_by_id_and_flag(uStack_44,&uStack_40,uStack_c8,3);
    }
    else {
      cVar2 = talkgroup_binary_search_by_id_and_flag(uStack_44,&uStack_40,uStack_c8,4);
      sStack_ca = sStack_ca + 1;
    }
    if (cVar2 == '\0') {
      flash_bitmap_find_free_slot(&uStack_3a);
      talkgroup_index_decode_paged(uStack_3a,&uStack_3c,&bStack_c5);
      flash_block_write((undefined1)uStack_3c,(bStack_c5 - 1) * 0x18 & 0xfff8,&bStack_38);
      uStack_3c = flash_block_id_resolve_locked(0xb);
      PTR_DAT_03035288[1] = uStack_3a;
      os_sem_pend_ms(p_ucos_mutex_0003944c,0);
      uStack_c8 = uStack_c8 + 1;
      uVar3 = flash_block_id_resolve_helper1();
      flash_page_tag_write(uVar3,0x7f);
      bStack_38 = (byte)(uStack_3a >> 3);
      if ((uStack_3a & 7) == 0) {
        bStack_38 = bStack_38 - 1;
        bStack_37 = 8;
      }
      else {
        bStack_37 = (byte)uStack_3a & 7;
      }
      bStack_37 = bStack_37 - 1;
      spi_flash_read_seq(uStack_3c,0,auStack_c4,0x80);
      memcpy_bytes_iram(auStack_c4,&uStack_c8,2);
      memcpy_bytes_iram(auStack_c4 + 2,&sStack_ca,2);
      auStack_c4[bStack_38 + 0x10] =
           ((byte)(-2 << (bStack_37 & 0x3f)) | (byte)(0xfffffffe >> 0x20 - (bStack_37 & 0x3f))) &
           auStack_c4[bStack_38 + 0x10];
      spi_flash_program_pagesplit(uVar3,0,auStack_c4,0x80);
      memset_ck803s(DAT_03035290,0xff,0x640);
      iVar1 = DAT_03035290;
      if (0 < (int)(uStack_c8 - 1)) {
        uVar5 = 0;
        do {
          if ((int)uVar5 < (int)(uStack_3e - 1)) {
            spi_flash_read_seq(uStack_3c,(uVar5 + 0x80) * 2 & 0xffff,iVar1 + uVar5 * 2,2);
          }
          else {
            spi_flash_read_seq(uStack_3c,(uVar5 + 0x80) * 2 & 0xffff,iVar1 + (uVar5 + 1) * 2,2);
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while ((int)uVar5 < (int)(uStack_c8 - 1));
      }
      iVar1 = DAT_030354b8;
      if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
        uStack_3a = uStack_3a | 0x3000;
      }
      else {
        uStack_3a = uStack_3a | 0x4000;
      }
      puVar4 = (undefined1 *)((uStack_3e - 1) * 2 + DAT_030354b8);
      *puVar4 = (undefined1)uStack_3a;
      puVar4[1] = SUBPIECE(uStack_3a, 1, 1);
      spi_flash_shadow_addr_set(uVar3,0x100);
      spi_flash_write_chunk_pagesplit(iVar1,*PTR_DAT_030354bc,uStack_c8 * 2);
      iVar1 = DAT_030354b8;
      if (0 < (int)(uStack_c8 - 1)) {
        uVar5 = 0;
        do {
          if ((int)uVar5 < (int)(uStack_40 - 1)) {
            spi_flash_read_seq(uStack_3c,(uVar5 + 0x3a0) * 2 & 0xffff,iVar1 + uVar5 * 2,2);
          }
          else {
            spi_flash_read_seq(uStack_3c,(uVar5 + 0x3a0) * 2 & 0xffff,iVar1 + (uVar5 + 1) * 2,2);
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while ((int)uVar5 < (int)(uStack_c8 - 1));
      }
      iVar1 = DAT_030354b8;
      puVar4 = (undefined1 *)((uStack_40 - 1) * 2 + DAT_030354b8);
      *puVar4 = (undefined1)uStack_3a;
      puVar4[1] = SUBPIECE(uStack_3a, 1, 1);
      spi_flash_shadow_addr_set(uVar3,0x740);
      spi_flash_write_chunk_pagesplit(iVar1,*PTR_DAT_030354bc,uStack_c8 * 2);
      flash_page_tag_write(uVar3,0xb);
      flash_page_tag_write(uStack_3c,0);
      flash_page_invalidate_range();
      os_sem_post(p_ucos_mutex_0003944c);
      os_sem_post(p_ucos_mutex_0003e40c);
      return 1;
    }
    *param_2 = 3;
  }
  else {
    *param_2 = 3;
  }
  os_sem_post(p_ucos_mutex_0003e40c);
  dialog_show_icon_and_two_numbers
            (0x30,0x30,PTR_DAT_030354d4,
             **(undefined4 **)
               (PTR_PTR_030354cc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
             PTR_LAB_030354d0);
  return 0;
}


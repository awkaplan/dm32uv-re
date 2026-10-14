/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: codeplug_factory_defaults_write @ 03032434 (file base 0x03000000; code starts at 0x03001000)
 * Size: 2512 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void codeplug_factory_defaults_write(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  char cVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 uStack_51;
  undefined1 uStack_4f;
  undefined1 uStack_4d;
  undefined1 uStack_4b;
  undefined1 uStack_49;
  undefined1 uStack_47;
  undefined1 uStack_45;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  undefined1 uStack_3d;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_35;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  
  display_clear_fullscreen();
  display_draw_number_centered
            (100,0xffff,0,PTR_PTR_030324e8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
  memset_bytes(&uStack_54,0,0x30);
  memset_bytes(p_vfo_display_state,0,0x33);
  memset_bytes(PTR_DAT_030324f0,0,0x1000);
  iVar5 = 0;
  do {
    iVar4 = flash_block_id_resolve((byte)(iVar5 + 0x12));
    spi_flash_sector_erase();
    flash_page_tag_write(iVar4,iVar5 + 0x12);
    puVar9 = PTR_DAT_030324f0;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x30);
  *(undefined1 *)PTR_DAT_030324f0 = 0x10;
  puVar1 = p_dm32_settings_block04;
  puVar9 = puVar9 + 4;
  iVar5 = 0;
  puVar8 = PTR_LAB_030324f4;
  do {
    if ((puVar1[0x30] & 0x40) == 0) {
      number_to_string_format_2args(&uStack_54,PTR_DAT_03032814,iVar5 + 1);
    }
    else {
      number_to_string_format_2args(&uStack_54,PTR_s_Channel__d_030324f8,iVar5 + 1);
    }
    memcpy_bytes_iram(&uStack_44,puVar8,4);
    memcpy_bytes_iram(&uStack_40,&uStack_44,4);
    uStack_3c = 0x14;
    uStack_38 = 0x30;
    uStack_37 = 1;
    uStack_35 = 1;
    uStack_33 = 0xff;
    uStack_32 = 0xff;
    uStack_31 = 0xff;
    uStack_30 = 0xff;
    memcpy_bytes_iram(puVar9,&uStack_54,0x30);
    puVar2 = p_dm32_settings_block04;
    iVar5 = iVar5 + 1;
    puVar8 = puVar8 + 4;
    puVar9 = puVar9 + 0xc;
  } while (iVar5 != 9);
  iVar4 = 0;
  puVar8 = PTR_LAB_03032818;
  iVar5 = DAT_0303281c;
  do {
    if ((puVar2[0x30] & 0x40) == 0) {
      number_to_string_format_2args(&uStack_54,PTR_DAT_03032814,iVar4 + 10);
    }
    else {
      number_to_string_format_2args(&uStack_54,PTR_s_Channel__d_03032824,iVar4 + 10);
    }
    memcpy_bytes_iram(&uStack_44,puVar8,4);
    memcpy_bytes_iram(&uStack_40,&uStack_44,4);
    uStack_3c = 4;
    uStack_3b = 0x80;
    uStack_38 = 0x30;
    uStack_35 = 0;
    uStack_33 = 0xff;
    uStack_32 = 0xff;
    uStack_31 = 0xff;
    uStack_30 = 0xff;
    memcpy_bytes_iram(iVar5,&uStack_54,0x30);
    puVar9 = PTR_DAT_03032828;
    iVar4 = iVar4 + 1;
    puVar8 = puVar8 + 4;
    iVar5 = iVar5 + 0x30;
  } while (iVar4 != 7);
  *(undefined1 *)((int)PTR_DAT_03032828 + 0xfff) = 0x12;
  iVar5 = flash_block_id_resolve(0x12);
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  memset_bytes(&uStack_54,0,0x30);
  uStack_43 = 0x25;
  uStack_42 = 0x41;
  uStack_41 = 0x14;
  uStack_3f = 0x25;
  uStack_3e = 0x41;
  uStack_3d = 0x14;
  uStack_3c = 4;
  uStack_3b = 0x80;
  uStack_38 = 0x30;
  uStack_35 = 0;
  uStack_33 = 0xff;
  uStack_32 = 0xff;
  uStack_31 = 0xff;
  uStack_30 = 0xff;
  memcpy_bytes_iram((int)puVar9 + 3999,&uStack_54,0x30);
  uStack_42 = 1;
  uStack_41 = 0x43;
  uStack_3e = 1;
  uStack_3d = 0x43;
  uStack_3c = 0x14;
  uStack_38 = 0x30;
  uStack_37 = 1;
  uStack_35 = 1;
  uStack_33 = 0xff;
  uStack_32 = 0xff;
  uStack_31 = 0xff;
  uStack_30 = 0xff;
  memcpy_bytes_iram((int)puVar9 + 0xfcf,&uStack_54,0x30);
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x41;
  iVar5 = flash_block_id_resolve(0x41);
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0x42);
  spi_flash_sector_erase();
  memset_bytes(&uStack_54,0,0x12);
  uStack_53 = 1;
  uStack_51 = 1;
  uStack_4f = 1;
  uStack_4d = 1;
  uStack_4b = 1;
  uStack_49 = 1;
  uStack_47 = 1;
  uStack_45 = 1;
  uStack_43 = 1;
  memcpy_bytes_iram(puVar9,&uStack_54,0x12);
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x42;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0x43);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x43;
  *(undefined1 *)((int)puVar9 + 0xffb) = 1;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0xb);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0xb;
  *(undefined1 *)puVar9 = 3;
  *(undefined1 *)((int)puVar9 + 2) = 2;
  *(undefined1 *)(puVar9 + 1) = 1;
  *(undefined1 *)(puVar9 + 4) = 0xf8;
  memset_bytes((int)puVar9 + 0x11,0xff,0x6f);
  *(undefined1 *)(puVar9 + 0x40) = 2;
  *(undefined1 *)((int)puVar9 + 0x101) = 0x50;
  *(undefined1 *)((int)puVar9 + 0x102) = 1;
  *(undefined1 *)((int)puVar9 + 0x103) = 0x40;
  *(undefined1 *)(puVar9 + 0x41) = 3;
  *(undefined1 *)((int)puVar9 + 0x105) = 0x40;
  *(undefined1 *)(puVar9 + 0x1d0) = 1;
  *(undefined1 *)((int)puVar9 + 0x741) = 0x40;
  *(undefined1 *)((int)puVar9 + 0x742) = 3;
  *(undefined1 *)((int)puVar9 + 0x743) = 0x40;
  *(undefined1 *)(puVar9 + 0x1d1) = 2;
  *(undefined1 *)((int)puVar9 + 0x745) = 0x50;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0x44);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x44;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03032a0c,PTR_LAB_03032a10,8);
  }
  else {
    memcpy_bytes_iram(DAT_0303282c,PTR_s_Call_1_03032830,6);
  }
  puVar9 = PTR_DAT_03032a14;
  *(undefined1 *)((int)PTR_DAT_03032a14 + 0x13) = 1;
  *(undefined1 *)((int)puVar9 + 0x16) = 4;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03032a1c,PTR_LAB_03032a24,4);
  }
  else {
    memcpy_bytes_iram(DAT_03032a1c,PTR_s_All_Call_03032a20,8);
  }
  puVar9 = PTR_DAT_03032a14;
  *(undefined1 *)((int)PTR_DAT_03032a14 + 0x2b) = 0xff;
  *(undefined1 *)(puVar9 + 0xb) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x2d) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x2e) = 5;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03032a28,PTR_LAB_03032a30,8);
  }
  else {
    memcpy_bytes_iram(DAT_03032a28,PTR_s_Call_2_03032a2c,6);
  }
  puVar9 = PTR_DAT_03032a14;
  *(undefined1 *)((int)PTR_DAT_03032a14 + 0x43) = 2;
  *(undefined1 *)((int)puVar9 + 0x46) = 4;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  cVar7 = '\0';
  sVar6 = 0x45;
  do {
    iVar5 = flash_block_id_resolve(cVar7 + 0x45);
    spi_flash_sector_erase();
    *(char *)((int)puVar9 + 0xfff) = (char)sVar6;
    spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
    puVar3 = PTR_DAT_03032a14;
    sVar6 = sVar6 + 1;
    cVar7 = cVar7 + '\x01';
  } while (sVar6 != 0x49);
  memset_bytes(PTR_DAT_03032a14,0,0x1000);
  iVar5 = flash_block_id_resolve(0xf);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar3 + 0xfff) = 0xf;
  *(undefined1 *)puVar3 = 1;
  *(undefined1 *)(puVar3 + 4) = 1;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03032a34,PTR_DAT_03032a3c,6);
  }
  else {
    memcpy_bytes_iram(DAT_03032a34,PTR_s_List_1_03032a38,6);
  }
  puVar9 = PTR_DAT_03032a14;
  *(undefined1 *)(PTR_DAT_03032a14 + 7) = 1;
  *(undefined1 *)((int)puVar9 + 0x1f) = 2;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0x5c);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x5c;
  *(undefined1 *)puVar9 = 2;
  *(undefined1 *)((int)puVar9 + 1) = 1;
  *(undefined1 *)((int)puVar9 + 3) = 1;
  *(undefined1 *)((int)puVar9 + 5) = 1;
  *(undefined1 *)((int)puVar9 + 7) = 2;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03032a40,PTR_LAB_03032a48,8);
  }
  else {
    memcpy_bytes_iram(DAT_03032a40,PTR_s_Zone_Ana_03032a44,8);
  }
  puVar9 = PTR_DAT_03032a14;
  *(undefined1 *)(PTR_DAT_03032a14 + 8) = 7;
  *(undefined1 *)((int)puVar9 + 0x21) = 10;
  *(undefined1 *)((int)puVar9 + 0x23) = 0xb;
  *(undefined1 *)((int)puVar9 + 0x25) = 0xc;
  *(undefined1 *)((int)puVar9 + 0x27) = 0xd;
  *(undefined1 *)((int)puVar9 + 0x29) = 0xe;
  *(undefined1 *)((int)puVar9 + 0x2b) = 0xf;
  *(undefined1 *)((int)puVar9 + 0x2d) = 0x10;
  *(undefined1 *)((int)puVar9 + 0x2f) = 0x10;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03032c84,PTR_DAT_03032c88,8);
  }
  else {
    memcpy_bytes_iram(DAT_03032a4c,PTR_s_Zone_Dig_03032a50,8);
  }
  puVar9 = PTR_DAT_03032c8c;
  *(undefined1 *)((int)PTR_DAT_03032c8c + 0xb1) = 9;
  *(undefined1 *)((int)puVar9 + 0xb2) = 1;
  *(undefined1 *)(puVar9 + 0x2d) = 2;
  *(undefined1 *)((int)puVar9 + 0xb6) = 3;
  *(undefined1 *)(puVar9 + 0x2e) = 4;
  *(undefined1 *)((int)puVar9 + 0xba) = 5;
  *(undefined1 *)(puVar9 + 0x2f) = 6;
  *(undefined1 *)((int)puVar9 + 0xbe) = 7;
  *(undefined1 *)(puVar9 + 0x30) = 8;
  *(undefined1 *)((int)puVar9 + 0xc2) = 9;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  iVar5 = 0;
  do {
    iVar4 = flash_block_id_resolve((byte)(iVar5 + 0x5d));
    spi_flash_sector_erase();
    flash_page_tag_write(iVar4,iVar5 + 0x5d);
    puVar9 = PTR_DAT_03032c8c;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 8);
  memset_bytes(PTR_DAT_03032c8c,0,0x1000);
  iVar5 = flash_block_id_resolve(0x11);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x11;
  *(undefined1 *)puVar9 = 1;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03032c94,PTR_LAB_03032c9c,10);
  }
  else {
    memcpy_bytes_iram(DAT_03032c94,PTR_s_List_1_03032c98,6);
  }
  puVar9 = PTR_DAT_03032c8c;
  *(undefined1 *)(PTR_DAT_03032c8c + 3) = 9;
  *(undefined1 *)((int)puVar9 + 0xd) = 3;
  *(undefined1 *)((int)puVar9 + 0xe) = 6;
  *(undefined1 *)(puVar9 + 4) = 1;
  *(undefined1 *)((int)puVar9 + 0x16) = 10;
  *(undefined1 *)((int)puVar9 + 0x19) = 1;
  *(undefined1 *)((int)puVar9 + 0x1b) = 1;
  *(undefined1 *)((int)puVar9 + 0x1d) = 2;
  *(undefined1 *)((int)puVar9 + 0x1f) = 3;
  *(undefined1 *)((int)puVar9 + 0x21) = 4;
  *(undefined1 *)((int)puVar9 + 0x23) = 5;
  *(undefined1 *)((int)puVar9 + 0x25) = 6;
  *(undefined1 *)((int)puVar9 + 0x27) = 7;
  *(undefined1 *)((int)puVar9 + 0x29) = 8;
  *(undefined1 *)((int)puVar9 + 0x2b) = 9;
  *(undefined1 *)((int)puVar9 + 0x2d) = 10;
  *(undefined1 *)((int)puVar9 + 0x2f) = 0xb;
  *(undefined1 *)((int)puVar9 + 0x31) = 0xc;
  *(undefined1 *)((int)puVar9 + 0x33) = 0xd;
  *(undefined1 *)((int)puVar9 + 0x35) = 0xe;
  *(undefined1 *)((int)puVar9 + 0x37) = 0xf;
  *(undefined1 *)((int)puVar9 + 0xe01) = 0x36;
  *(undefined1 *)((int)puVar9 + 0xe02) = 1;
  *(undefined1 *)((int)puVar9 + 0xe03) = 0x74;
  *(undefined1 *)(puVar9 + 0x381) = 1;
  *(undefined1 *)((int)puVar9 + 0xe06) = 4;
  *(undefined1 *)((int)puVar9 + 0xe07) = 0x70;
  *(undefined1 *)(puVar9 + 0x382) = 4;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0x66);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x66;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(PTR_DAT_03032c8c,PTR_DAT_03032ca4,10);
  }
  else {
    memcpy_bytes_iram(puVar9,PTR_s_Roam_Channel_1_03032ca0,0xe);
  }
  puVar9 = PTR_DAT_03032c8c;
  *(undefined1 *)(PTR_DAT_03032c8c + 4) = 0;
  *(undefined1 *)((int)puVar9 + 0x11) = 0x75;
  *(undefined1 *)((int)puVar9 + 0x12) = 0x23;
  *(undefined1 *)((int)puVar9 + 0x13) = 0x42;
  *(undefined1 *)(puVar9 + 5) = 0;
  *(undefined1 *)((int)puVar9 + 0x15) = 0x75;
  *(undefined1 *)((int)puVar9 + 0x16) = 0x23;
  *(undefined1 *)((int)puVar9 + 0x17) = 0x41;
  *(undefined1 *)(puVar9 + 6) = 1;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0x65);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x65;
  *(undefined1 *)puVar9 = 1;
  *(undefined1 *)((int)puVar9 + 2) = 1;
  *(undefined1 *)((int)puVar9 + 3) = 1;
  puVar3 = PTR_DAT_03033084;
  puVar9 = PTR_DAT_03032ca8;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    *(undefined1 *)PTR_DAT_03033084 = 0xc2;
    *(undefined1 *)((int)puVar3 + 1) = 0xfe;
    *(undefined1 *)((int)puVar3 + 2) = 0xd3;
    *(undefined1 *)((int)puVar3 + 3) = 0xce;
    *(undefined1 *)(puVar3 + 1) = 199;
    *(undefined1 *)((int)puVar3 + 5) = 0xf8;
    *(undefined1 *)((int)puVar3 + 6) = 0xd3;
    *(undefined1 *)((int)puVar3 + 7) = 0xf2;
    *(undefined1 *)(puVar3 + 2) = 0x20;
    *(undefined1 *)((int)puVar3 + 9) = 0x31;
  }
  else {
    *(undefined1 *)PTR_DAT_03032ca8 = 0x52;
    *(undefined1 *)((int)puVar9 + 1) = 0x6f;
    *(undefined1 *)((int)puVar9 + 2) = 0x61;
    *(undefined1 *)((int)puVar9 + 3) = 0x6d;
    *(undefined1 *)(puVar9 + 1) = 0x20;
    *(undefined1 *)((int)puVar9 + 5) = 0x5a;
    *(undefined1 *)((int)puVar9 + 6) = 0x6f;
    *(undefined1 *)((int)puVar9 + 7) = 0x6e;
    *(undefined1 *)(puVar9 + 2) = 0x65;
    *(undefined1 *)((int)puVar9 + 9) = 0x20;
    *(undefined1 *)((int)puVar9 + 10) = 0x31;
  }
  puVar9 = PTR_DAT_03033088;
  *(undefined1 *)(PTR_DAT_03033088 + 8) = 1;
  *(undefined1 *)((int)puVar9 + 0x21) = 1;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(0x67);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 0x67;
  *(undefined1 *)puVar9 = 1;
  *(undefined1 *)(puVar9 + 4) = 1;
  *(undefined1 *)((int)puVar9 + 0x11) = 0;
  *(undefined1 *)((int)puVar9 + 0x12) = 0;
  *(undefined1 *)((int)puVar9 + 0x13) = 0x52;
  *(undefined1 *)(puVar9 + 5) = 0x61;
  *(undefined1 *)((int)puVar9 + 0x15) = 100;
  *(undefined1 *)((int)puVar9 + 0x16) = 0x69;
  *(undefined1 *)((int)puVar9 + 0x17) = 0x6f;
  *(undefined1 *)(puVar9 + 6) = 0x20;
  *(undefined1 *)((int)puVar9 + 0x19) = 0x31;
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar4 = flash_block_id_resolve(4);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 4;
  iVar5 = DAT_03033090;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    memcpy_bytes_iram(DAT_03033090,PTR_LAB_0303309c,10);
    memcpy_bytes_iram(iVar5 + 0xe,PTR_LAB_030330a0,9);
  }
  else {
    memcpy_bytes_iram(DAT_03033090,PTR_s_WELCOME_03033094,7);
    memcpy_bytes_iram(iVar5 + 0xe,PTR_s_DMR_Radio_03033098,9);
  }
  puVar9 = PTR_DAT_03033088;
  *(undefined1 *)((int)PTR_DAT_03033088 + 0x1d) = 1;
  *(undefined1 *)(puVar9 + 8) = 0x61;
  *(undefined1 *)((int)puVar9 + 0x21) = 0xc0;
  *(undefined1 *)(puVar9 + 0xc) = 4;
  *(undefined1 *)((int)puVar9 + 0x31) = 2;
  *(undefined1 *)((int)puVar9 + 0x32) = 2;
  puVar9 = PTR_DAT_03033088;
  if ((p_dm32_settings_block04[0x30] & 0x40) == 0) {
    *(undefined1 *)((int)PTR_DAT_03033088 + 0x33) = 1;
    *(undefined1 *)(puVar9 + 0x10) = 0x40;
    *(undefined1 *)((int)puVar9 + 0x41) = 0x14;
    *(undefined1 *)((int)puVar9 + 0x42) = 5;
    *(undefined1 *)(puVar9 + 0x18) = 3;
    *(undefined1 *)((int)puVar9 + 0x61) = 2;
    *(undefined1 *)((int)puVar9 + 0x62) = 0xc;
    *(undefined1 *)((int)puVar9 + 99) = 3;
    *(undefined1 *)(puVar9 + 0x19) = 3;
    *(undefined1 *)((int)puVar9 + 0x65) = 0x2b;
    *(undefined1 *)(puVar9 + 0x20) = 0x40;
    *(undefined1 *)((int)puVar9 + 0x81) = 1;
    *(undefined1 *)((int)puVar9 + 0xa3) = 10;
  }
  else {
    *(undefined1 *)((int)PTR_DAT_03033088 + 0x33) = 9;
    *(undefined1 *)(puVar9 + 0x10) = 0x40;
    *(undefined1 *)((int)puVar9 + 0x41) = 0x14;
    *(undefined1 *)((int)puVar9 + 0x42) = 5;
    *(undefined1 *)(puVar9 + 0x18) = 3;
    *(undefined1 *)((int)puVar9 + 0x61) = 2;
    *(undefined1 *)((int)puVar9 + 0x62) = 0xc;
    *(undefined1 *)((int)puVar9 + 99) = 3;
    *(undefined1 *)(puVar9 + 0x19) = 3;
    *(undefined1 *)((int)puVar9 + 0x65) = 0x2b;
    *(undefined1 *)(puVar9 + 0x20) = 0x40;
    *(undefined1 *)((int)puVar9 + 0x81) = 1;
    *(undefined1 *)((int)puVar9 + 0xa3) = 10;
    *(undefined1 *)(puVar9 + 0x29) = 0x22;
  }
  puVar9 = PTR_DAT_03033088;
  *(undefined1 *)((int)PTR_DAT_03033088 + 0xa5) = 0x23;
  *(undefined1 *)((int)puVar9 + 0xa6) = 2;
  *(undefined1 *)((int)puVar9 + 0xa7) = 2;
  *(undefined1 *)((int)puVar9 + 0x306) = 0x32;
  *(undefined1 *)((int)puVar9 + 0x307) = 0x33;
  *(undefined1 *)(puVar9 + 0xc2) = 0x2e;
  *(undefined1 *)((int)puVar9 + 0x309) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x30a) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x30b) = 0x30;
  *(undefined1 *)(puVar9 + 0xc3) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x30d) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x30e) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x30f) = 0x4e;
  *(undefined1 *)(puVar9 + 0xc4) = 0x31;
  *(undefined1 *)((int)puVar9 + 0x311) = 0x31;
  *(undefined1 *)((int)puVar9 + 0x312) = 0x38;
  *(undefined1 *)((int)puVar9 + 0x313) = 0x2e;
  *(undefined1 *)(puVar9 + 0xc5) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x315) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x316) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x317) = 0x30;
  *(undefined1 *)(puVar9 + 0xc6) = 0x30;
  *(undefined1 *)((int)puVar9 + 0x319) = 0x45;
  *(undefined1 *)((int)puVar9 + 0x332) = 1;
  *(undefined1 *)(puVar9 + 0x140) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x501) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x502) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x503) = 0xff;
  *(undefined1 *)(puVar9 + 0x141) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x505) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x506) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x507) = 0xff;
  *(undefined1 *)((int)puVar9 + 0x601) = 10;
  *(undefined1 *)((int)puVar9 + 0x602) = 10;
  *(undefined1 *)(puVar9 + 0x1c0) = 0xf;
  spi_flash_write_chunk_pagesplit(puVar9,iVar4 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(10);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 10;
  *(undefined1 *)puVar9 = 5;
  *(undefined1 *)(puVar9 + 4) = 0xc;
  memcpy_bytes_iram((int)puVar9 + 0x11,PTR_s_How_are_you__030330a4,0xc);
  *(undefined1 *)((int)puVar9 + 0x91) = 0x10;
  memcpy_bytes_iram((int)puVar9 + 0x92,PTR_s_Nice_to_meet_you_030330a8,0x10);
  *(undefined1 *)((int)puVar9 + 0x112) = 0x11;
  memcpy_bytes_iram((int)puVar9 + 0x113,PTR_s_How_have_you_been_030330ac,0x11);
  *(undefined1 *)((int)puVar9 + 0x193) = 0x18;
  memcpy_bytes_iram(puVar9 + 0x65,PTR_s_Are_you_making_progress__030330b0,0x18);
  *(undefined1 *)(puVar9 + 0x85) = 0x16;
  memcpy_ck803s((void *)((int)puVar9 + 0x215),PTR_s_How_do_you_feel_today__030330b4,0x16);
  spi_flash_write_chunk_pagesplit(puVar9,iVar5 << 0xc,0x1000);
  memset_bytes(puVar9,0,0x1000);
  iVar5 = flash_block_id_resolve(6);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar9 + 0xfff) = 6;
  iVar4 = 0;
  do {
    *(undefined1 *)(puVar9 + iVar4 * 4) = 0xff;
    puVar3 = PTR_DAT_03033088;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x10);
  *(undefined1 *)(PTR_DAT_03033088 + 0x40) = 0xf;
  *(undefined1 *)(puVar3 + 0x41) = 10;
  *(undefined1 *)((int)puVar3 + 0x105) = 1;
  *(undefined1 *)((int)puVar3 + 0x109) = 0xff;
  *(undefined1 *)((int)puVar3 + 0x10a) = 10;
  *(undefined1 *)(puVar3 + 0x44) = 0xff;
  *(undefined1 *)(puVar3 + 0x48) = 0xff;
  *(undefined1 *)(puVar3 + 0x4c) = 0xff;
  *(undefined1 *)(puVar3 + 0x50) = 0xff;
  *(undefined1 *)((int)puVar3 + 0x1ff) = 1;
  memcpy_bytes_iram(puVar3 + 0x80,PTR_s_AContact_1_030330b8,10);
  *(undefined1 *)(puVar3 + 0x84) = 1;
  memset_bytes((int)puVar3 + 0x211,0xff,4);
  *(undefined1 *)(puVar3 + 0x288) = 1;
  *(undefined1 *)((int)puVar3 + 0xa22) = 1;
  *(undefined1 *)(puVar3 + 0x289) = 0xf;
  *(undefined1 *)((int)puVar3 + 0xa25) = 3;
  *(undefined1 *)((int)puVar3 + 0xa26) = 5;
  *(undefined1 *)((int)puVar3 + 0xa27) = 10;
  *(undefined1 *)(puVar3 + 0x2a4) = 1;
  *(undefined1 *)((int)puVar3 + 0xa92) = 1;
  memcpy_bytes_iram(puVar3 + 0x2a8,PTR_s_MDC_Link_1_030331b8,10);
  *(undefined1 *)(puVar3 + 0x2ac) = 1;
  *(undefined1 *)((int)puVar3 + 0xab1) = 0xe0;
  *(undefined1 *)((int)puVar3 + 0xab3) = 1;
  spi_flash_write_chunk_pagesplit(puVar3,iVar5 << 0xc,0x1000);
  memset_bytes(puVar3,0,0x1000);
  iVar5 = flash_block_id_resolve(0x10);
  spi_flash_sector_erase();
  *(undefined1 *)((int)puVar3 + 0xfff) = 0x10;
  memcpy_bytes_iram(puVar3,PTR_s_Sys_1_030331bc,5);
  *(undefined1 *)((int)puVar3 + 0xb) = 1;
  *(undefined1 *)((int)puVar3 + 0xe) = 0xf;
  *(undefined1 *)((int)puVar3 + 0xf) = 5;
  *(undefined1 *)(puVar3 + 4) = 1;
  *(undefined1 *)((int)puVar3 + 0x12) = 1;
  *(undefined1 *)((int)puVar3 + 0x13) = 1;
  *(undefined1 *)(puVar3 + 0x2c) = 1;
  *(undefined1 *)(puVar3 + 0xc0) = 1;
  memcpy_bytes_iram((int)puVar3 + 0x301,PTR_s_Privacy_1_030331c0,9);
  *(undefined1 *)((int)puVar3 + 0x30b) = 1;
  *(undefined1 *)(puVar3 + 0xc3) = 0x12;
  *(undefined1 *)((int)puVar3 + 0x30d) = 0x34;
  *(undefined1 *)((int)puVar3 + 0x30e) = 0x56;
  *(undefined1 *)((int)puVar3 + 0x30f) = 0x78;
  *(undefined1 *)(puVar3 + 0xc4) = 0x90;
  *(undefined1 *)((int)puVar3 + 0x311) = 0xab;
  *(undefined1 *)((int)puVar3 + 0x312) = 0xcd;
  *(undefined1 *)((int)puVar3 + 0xb01) = 10;
  *(undefined1 *)((int)puVar3 + 0xb02) = 10;
  *(undefined1 *)((int)puVar3 + 0xb07) = 10;
  *(undefined1 *)(puVar3 + 0x2c2) = 10;
  *(undefined1 *)((int)puVar3 + 0xb09) = 5;
  spi_flash_write_chunk_pagesplit(puVar3,iVar5 << 0xc,0x1000);
  aprs_log_clear();
  flash_dual_range_invalidate();
  flash_record_erase_and_clear_cache(1);
  flash_record_erase_and_clear_cache(2);
  flash_record_erase_and_clear_cache(3);
  erase_stored_field_category_by_code(1);
  erase_stored_field_category_by_code(3);
  erase_stored_field_category_by_code(5);
  flash_quad_enable_and_system_reset();
  return;
}


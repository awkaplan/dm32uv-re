/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rf_config_load_from_flash_block2 @ 0300d568 (file base 0x03000000; code starts at 0x03001000)
 * Size: 642 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rf_config_load_from_flash_block2(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  ushort block_id;
  ushort uVar3;
  int iVar4;
  undefined2 uStack_14;
  byte bStack_12;
  byte bStack_11;
  
  block_id = flash_block_id_resolve_locked(2);
  puVar1 = PTR_DAT_0300d7ec;
  flash_block_read(block_id,0xe,PTR_DAT_0300d7ec,2);
  flash_block_read(block_id,0xc,(void *)((int)puVar1 + 2),2);
  uVar3 = *(ushort *)puVar1;
  *(ushort *)puVar1 = uVar3 & 0xfff;
  if (999 < (ushort)((uVar3 & 0xfff) - 1)) {
    *(undefined2 *)(PTR_DAT_0300d7f0 + 0x2e) = 0x284;
  }
  flash_field_read_cached(4,0xa6,&uStack_14,2);
  PTR_DAT_0300d7f4[0x6b] = SUBPIECE(uStack_14, 1, 1);
  if (7 < SUBPIECE(uStack_14, 1, 1)) {
    PTR_DAT_0300d7f4[0x6b] = 7;
  }
  puVar2 = PTR_DAT_0300d7f4;
  modem_buffer_indexed_byte_write_0301e5d8(PTR_DAT_0300d7f4[0x6b]);
  puVar2[0x6a] = (byte)uStack_14;
  if (4 < (byte)uStack_14) {
    puVar2[0x6a] = 2;
  }
  FUN_0301e5fc(0);
  flash_block_read(block_id,0,&uStack_14,4);
  iVar4 = bcd_frequency_decode(&uStack_14,2);
  puVar2 = PTR_DAT_0300d7f0;
  *(int *)(PTR_DAT_0300d7f0 + 0x10) = iVar4 * 10000;
  iVar4 = bcd_frequency_decode(&bStack_12,2);
  *(int *)(puVar2 + 0x14) = iVar4 * 10000;
  if (_DAT_0300d7f8 < *(int *)(puVar2 + 0x10) - 1U) {
    *(undefined4 *)(puVar2 + 0x10) = _DAT_0300d7fc;
  }
  if (_DAT_0300d7f8 < iVar4 * 10000 - 1U) {
    *(undefined4 *)(PTR_DAT_0300d7f0 + 0x14) = _DAT_0300d800;
  }
  flash_block_read(block_id,0xcc,&uStack_14,4);
  iVar4 = bcd_frequency_decode(&uStack_14,2);
  puVar2 = PTR_DAT_0300d7f0;
  *(int *)(PTR_DAT_0300d7f0 + 0x18) = iVar4 * 10000;
  iVar4 = bcd_frequency_decode(&bStack_12,2);
  *(int *)(puVar2 + 0x1c) = iVar4 * 10000;
  if (_DAT_0300d7f8 < *(int *)(puVar2 + 0x18) - 1U) {
    *(undefined4 *)(puVar2 + 0x18) = 13600000;
  }
  if (_DAT_0300d7f8 < iVar4 * 10000 - 1U) {
    *(undefined4 *)(PTR_DAT_0300d7f0 + 0x1c) = _DAT_0300d804;
  }
  puVar2 = PTR_DAT_0300d7f0;
  *(undefined4 *)(PTR_DAT_0300d7f0 + 0x20) = _DAT_0300d808;
  *(undefined4 *)(puVar2 + 0x24) = 13600000;
  flash_block_read(block_id,0x206,&uStack_14,4);
  puVar2[0x3d] = (byte)uStack_14 & 0x1f;
  puVar2[0x3e] = SUBPIECE(uStack_14, 1, 1) & 0x7f;
  puVar2[0x3f] = bStack_12 & 0xf;
  puVar2[0x40] = bStack_11 & 0xf;
  flash_block_read(block_id,0x27,&uStack_14,2);
  set_global_upper_16bits(uStack_14);
  flash_block_read(block_id,0x16,&uStack_14,1);
  mmio_11000108_high_word_write_from_byte((byte)uStack_14);
  flash_block_read(block_id,0x203,&uStack_14,2);
  if (0x1f < (byte)uStack_14) {
    uStack_14 = CONCAT11(SUBPIECE(uStack_14, 1, 1),9);
  }
  PTR_DAT_0300d7f0[0x3b] = (byte)uStack_14;
  puVar2 = PTR_DAT_0300d7f0;
  if (0x1f < SUBPIECE(uStack_14, 1, 1)) {
    uStack_14 = CONCAT11(9,(byte)uStack_14);
  }
  PTR_DAT_0300d7f0[0x3c] = SUBPIECE(uStack_14, 1, 1);
  flash_block_read(block_id,0x205,&uStack_14,1);
  puVar2[0x35] = puVar2[0x35] & 0xf | (byte)uStack_14 << 4;
  if (3 < (((byte)uStack_14 & 0xf) + 8 & 0xf)) {
    puVar2[0x35] = puVar2[0x35] & 0xf | 0xb0;
  }
  uVar3 = flash_block_id_resolve_locked(4);
  puVar2 = PTR_DAT_0300d7f0;
  *(undefined4 *)PTR_DAT_0300d7f0 = _DAT_0300d7fc;
  *(undefined4 *)(puVar2 + 4) = _DAT_0300d800;
  *(undefined4 *)(puVar2 + 8) = 13600000;
  *(undefined4 *)(puVar2 + 0xc) = _DAT_0300d804;
  flash_block_read(uVar3,0xa5,&uStack_14,1);
  puVar1 = PTR_DAT_0300d80c;
  *(byte *)PTR_DAT_0300d80c = *(byte *)PTR_DAT_0300d80c & 0xf3 | ((byte)uStack_14 & 3) << 2;
  if (3 < ((byte)uStack_14 & 3)) {
    *(byte *)puVar1 = *(byte *)puVar1 & 0xf3;
  }
  PTR_DAT_0300d7f4[0x6d] = PTR_DAT_0300d7f4[0x6d] & 0xe7 | ((byte)uStack_14 >> 4 & 3) << 3;
  return;
}


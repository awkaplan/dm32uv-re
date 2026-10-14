/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block_cipher_decrypt_16byte_variant_a @ 030cce18 (file base 0x03000000; code starts at 0x03001000)
 * Size: 470 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: flash-storage
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void block_cipher_decrypt_16byte_variant_a
               (undefined1 *param_1,undefined1 *param_2,int param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char cVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  int iVar16;
  
  param_4 = param_4 & 0xff;
  iVar16 = 0;
  do {
    puVar9 = PTR_DAT_030ccff8 + iVar16;
    cVar11 = '\0';
    puVar10 = param_1;
    do {
      cVar11 = cVar11 + '\x01';
      *puVar9 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar9 = puVar9 + 4;
    } while (cVar11 != '\x04');
    iVar16 = iVar16 + 1;
    param_1 = param_1 + 4;
  } while (iVar16 != 4);
  xor_fold_16byte_key_block(PTR_DAT_030ccff8,param_3 + param_4 * 0x10);
  FUN_030ccb4c();
  aes_inv_shift_rows();
  pbVar12 = PTR_DAT_030ccff8;
  while (param_4 = param_4 - 1 & 0xff, PTR_DAT_030ccff8 = pbVar12, param_4 != 0) {
    xor_fold_16byte_key_block(pbVar12,param_3 + param_4 * 0x10);
    pbVar15 = pbVar12 + 4;
    pbVar14 = pbVar12 + 8;
    pbVar13 = pbVar12 + 0xc;
    do {
      bVar5 = *pbVar12;
      bVar1 = gf256_multiply_aes(bVar5,0xe);
      bVar6 = *pbVar15;
      bVar2 = gf256_multiply_aes(bVar6,0xb);
      bVar7 = *pbVar14;
      bVar3 = gf256_multiply_aes(bVar7,0xd);
      bVar8 = *pbVar13;
      bVar4 = gf256_multiply_aes(bVar8,9);
      *pbVar12 = bVar3 ^ bVar1 ^ bVar2 ^ bVar4;
      bVar1 = gf256_multiply_aes(bVar5,9);
      bVar2 = gf256_multiply_aes(bVar6,0xe);
      bVar3 = gf256_multiply_aes(bVar7,0xb);
      bVar4 = gf256_multiply_aes(bVar8,0xd);
      *pbVar15 = bVar3 ^ bVar1 ^ bVar2 ^ bVar4;
      bVar1 = gf256_multiply_aes(bVar5,0xd);
      bVar2 = gf256_multiply_aes(bVar6,9);
      bVar3 = gf256_multiply_aes(bVar7,0xe);
      bVar4 = gf256_multiply_aes(bVar8,0xb);
      *pbVar14 = bVar3 ^ bVar1 ^ bVar2 ^ bVar4;
      bVar5 = gf256_multiply_aes(bVar5,0xb);
      bVar6 = gf256_multiply_aes(bVar6,0xd);
      bVar7 = gf256_multiply_aes(bVar7,9);
      bVar8 = gf256_multiply_aes(bVar8,0xe);
      puVar10 = PTR_DAT_030ccffc;
      pbVar12 = pbVar12 + 1;
      *pbVar13 = bVar7 ^ bVar5 ^ bVar6 ^ bVar8;
      pbVar15 = pbVar15 + 1;
      pbVar14 = pbVar14 + 1;
      pbVar13 = pbVar13 + 1;
    } while (pbVar12 != puVar10);
    FUN_030ccb4c();
    aes_inv_shift_rows();
    pbVar12 = PTR_DAT_030ccff8;
  }
  xor_fold_16byte_key_block(pbVar12,param_3);
  iVar16 = 0;
  do {
    puVar9 = PTR_DAT_030ccff8 + iVar16;
    cVar11 = '\x04';
    puVar10 = param_2;
    do {
      cVar11 = cVar11 + -1;
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 4;
      puVar10 = puVar10 + 1;
    } while (cVar11 != '\0');
    iVar16 = iVar16 + 1;
    param_2 = param_2 + 4;
  } while (iVar16 != 4);
  return;
}


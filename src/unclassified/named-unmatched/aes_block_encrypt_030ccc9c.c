/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: aes_block_encrypt @ 030ccc9c (file base 0x03000000; code starts at 0x03001000)
 * Size: 378 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void aes_block_encrypt(undefined1 *param_1,undefined1 *param_2,int param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  uint uStack_34;
  
  param_4 = param_4 & 0xff;
  iVar14 = 0;
  do {
    puVar7 = PTR_DAT_030ccff0 + iVar14;
    cVar9 = '\0';
    puVar8 = param_1;
    do {
      cVar9 = cVar9 + '\x01';
      *puVar7 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar7 = puVar7 + 4;
    } while (cVar9 != '\x04');
    iVar14 = iVar14 + 1;
    param_1 = param_1 + 4;
  } while (iVar14 != 4);
  xor_fold_16byte_key_block(PTR_DAT_030ccff0,param_3);
  if (1 < param_4) {
    uStack_34 = 1;
    do {
      pbVar10 = PTR_DAT_030ccff0;
      FUN_030ccb1c();
      aes_shift_rows();
      pbVar13 = pbVar10 + 4;
      pbVar12 = pbVar10 + 8;
      pbVar11 = pbVar10 + 0xc;
      do {
        bVar5 = *pbVar10;
        bVar3 = gf256_multiply_aes(bVar5,2);
        bVar1 = *pbVar13;
        bVar2 = *pbVar12;
        bVar6 = *pbVar11;
        bVar4 = gf256_multiply_aes(bVar1,3);
        *pbVar10 = bVar3 ^ bVar6 ^ bVar2 ^ bVar4;
        bVar3 = gf256_multiply_aes(bVar1,2);
        bVar4 = gf256_multiply_aes(bVar2,3);
        *pbVar13 = bVar3 ^ bVar6 ^ bVar5 ^ bVar4;
        bVar3 = gf256_multiply_aes(bVar2,2);
        bVar4 = gf256_multiply_aes(bVar6,3);
        *pbVar12 = bVar3 ^ bVar1 ^ bVar5 ^ bVar4;
        bVar5 = gf256_multiply_aes(bVar5,3);
        bVar6 = gf256_multiply_aes(bVar6,2);
        puVar8 = PTR_DAT_030ccff4;
        pbVar10 = pbVar10 + 1;
        *pbVar11 = bVar5 ^ bVar1 ^ bVar2 ^ bVar6;
        pbVar13 = pbVar13 + 1;
        pbVar12 = pbVar12 + 1;
        pbVar11 = pbVar11 + 1;
      } while (pbVar10 != puVar8);
      xor_fold_16byte_key_block(PTR_DAT_030ccff0,param_3 + uStack_34 * 0x10);
      uStack_34 = uStack_34 + 1 & 0xff;
    } while (uStack_34 < param_4);
  }
  FUN_030ccb1c();
  aes_shift_rows();
  xor_fold_16byte_key_block(PTR_DAT_030ccff0,param_3 + param_4 * 0x10);
  iVar14 = 0;
  do {
    puVar7 = PTR_DAT_030ccff0 + iVar14;
    cVar9 = '\x04';
    puVar8 = param_2;
    do {
      cVar9 = cVar9 + -1;
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 4;
      puVar8 = puVar8 + 1;
    } while (cVar9 != '\0');
    iVar14 = iVar14 + 1;
    param_2 = param_2 + 4;
  } while (iVar14 != 4);
  return;
}


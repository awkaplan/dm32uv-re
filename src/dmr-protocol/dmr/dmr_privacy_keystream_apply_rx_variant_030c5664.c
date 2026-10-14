/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_privacy_keystream_apply_rx_variant @ 030c5664 (file base 0x03000000; code starts at 0x03001000)
 * Size: 298 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_privacy_keystream_apply_rx_variant(char *param_1,int param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined1 auStack_144 [256];
  undefined1 auStack_44 [32];
  
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    func_0x030dec8c(auStack_144,param_1 + 0x23c,0x100);
    rc4_keystream_xor_cipher(auStack_144,param_2,param_3);
  }
  else if (cVar1 == '\x02') {
    dmr_privacy_mi_expand_lfsr(param_1 + 0x23,auStack_44,1);
    pcVar8 = param_1 + 0x13c;
    pcVar7 = param_1 + 0x33c;
    dmr_privacy_alg2_block_encrypt_stub(auStack_44,pcVar8,pcVar7);
    dmr_privacy_alg2_block_op_stub(pcVar7,auStack_44,pcVar8);
    if (param_3 != 0) {
      uVar6 = 0;
      pbVar5 = (byte *)(param_1 + 0x344);
      do {
        dmr_privacy_alg2_block_op_stub(pbVar5,pcVar7,pcVar8);
        iVar2 = 0;
        pbVar3 = pbVar5;
        uVar4 = uVar6;
        do {
          iVar2 = iVar2 + 1;
          if (param_3 <= uVar4) {
            return;
          }
          *(byte *)(param_2 + uVar4) = *(byte *)(param_2 + uVar4) ^ *pbVar3;
          pbVar3 = pbVar3 + 1;
          uVar4 = uVar4 + 1;
        } while (iVar2 != 8);
        func_0x030dec8c(pcVar7,pbVar5);
        uVar6 = uVar6 + 8;
      } while (uVar6 < param_3);
    }
  }
  else {
    if (cVar1 == '\x04') {
      uVar9 = 10;
    }
    else if (cVar1 == '\x05') {
      uVar9 = 0xe;
    }
    else {
      uVar9 = 0;
    }
    dmr_privacy_mi_expand_lfsr(param_1 + 0x23,auStack_44,3);
    pcVar7 = param_1 + 0x33c;
    aes_block_encrypt(auStack_44,pcVar7,param_1 + 0x4c,uVar9);
    if (param_3 != 0) {
      uVar6 = 0;
      pbVar5 = (byte *)(param_1 + 0x34c);
      do {
        aes_block_encrypt(pcVar7,pbVar5,param_1 + 0x4c,uVar9);
        iVar2 = 0;
        pbVar3 = pbVar5;
        uVar4 = uVar6;
        do {
          iVar2 = iVar2 + 1;
          if (param_3 <= uVar4) {
            return;
          }
          *(byte *)(param_2 + uVar4) = *(byte *)(param_2 + uVar4) ^ *pbVar3;
          pbVar3 = pbVar3 + 1;
          uVar4 = uVar4 + 1;
        } while (iVar2 != 0x10);
        func_0x030dec8c(pcVar7,pbVar5);
        uVar6 = uVar6 + 0x10;
      } while (uVar6 < param_3);
    }
  }
  return;
}


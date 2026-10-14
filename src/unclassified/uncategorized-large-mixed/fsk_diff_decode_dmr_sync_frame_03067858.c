/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: fsk_diff_decode_dmr_sync_frame @ 03067858 (file base 0x03000000; code starts at 0x03001000)
 * Size: 286 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4
fsk_diff_decode_dmr_sync_frame
          (int param_1,uint param_2,undefined1 *param_3,undefined1 *param_4,undefined2 *param_5)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  memset_bytes(PTR_DAT_03067ae4,0,0x40);
  puVar2 = PTR_DAT_03067ae4;
  if (param_2 != 0) {
    uVar9 = 0;
    do {
      bVar1 = *(byte *)(param_1 + uVar9);
      uVar8 = 7;
      do {
        *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)puVar2;
        uVar5 = (int)(uint)bVar1 >> (uVar8 & 0x3f) & 1;
        *(char *)puVar2 = (char)uVar5;
        uVar6 = (uVar5 ^ *(byte *)((int)puVar2 + 2)) & 1;
        *(char *)((int)puVar2 + 2) = (char)uVar6;
        uVar6 = uVar6 | puVar2[1] * 2;
        puVar2[1] = uVar6;
        uVar5 = puVar2[2] + 1;
        puVar2[2] = uVar5;
        if (puVar2[3] == 0) {
          if (0x27 < uVar5) {
            uVar5 = uVar6 ^ DAT_03067ae8;
            uVar6 = uVar6 ^ DAT_03067aec;
            iVar7 = 0x28;
            iVar4 = 0;
            iVar10 = 0;
            do {
              iVar10 = iVar10 + (uVar5 & 1);
              iVar4 = iVar4 + (uVar6 & 1);
              uVar5 = uVar5 >> 1;
              uVar6 = uVar6 >> 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            if ((0x1f < 0x28U - iVar10) || (0x1f < 0x28U - iVar4)) {
              *(char *)(puVar2 + 4) = ~(0x28U - iVar4 <= 0x28U - iVar10);
              puVar2[5] = 0;
              puVar2[2] = 0;
              puVar2[3] = 1;
            }
          }
        }
        else if (7 < uVar5) {
          puVar2[2] = 0;
          iVar4 = puVar2[5];
          *(char *)((int)puVar2 + iVar4 + 0x18) = (char)uVar6;
          uVar5 = iVar4 + 1;
          puVar2[5] = uVar5;
          if (0xd < uVar5) {
            iVar4 = block_bit_transpose_crc_verify(DAT_03067af0);
            puVar3 = PTR_DAT_03067ae4;
            if (iVar4 != 0) {
              *param_3 = *(undefined1 *)(PTR_DAT_03067ae4 + 6);
              *param_4 = *(undefined1 *)((int)puVar3 + 0x19);
              *param_5 = CONCAT11(*(undefined1 *)((int)puVar3 + 0x1a),
                                  *(undefined1 *)((int)puVar3 + 0x1b));
              memset_bytes_wrapper();
              return 1;
            }
            memset_bytes_wrapper();
          }
        }
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0xffffffff);
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_2);
  }
  memset_bytes_wrapper();
  return 0;
}


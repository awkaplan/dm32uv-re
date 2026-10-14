/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: encode_name_tag_field @ 0301ef14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 264 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void encode_name_tag_field(int param_1)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  byte *pbVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  char *pcVar11;
  char cVar12;
  
  puVar1 = PTR_DAT_0301f030;
  bVar2 = PTR_DAT_0301f030[3] & 0x78;
  if ((PTR_DAT_0301f030[3] & 0x78) == 0) {
    if (PTR_DAT_0301f030[4] != '\0') {
      cVar12 = '\0';
      uVar6 = 0;
      uVar10 = 0;
      cVar5 = '\0';
      uVar8 = 7;
      pbVar4 = PTR_DAT_0301f034;
      do {
        uVar7 = uVar6 * 2 | (int)(uint)*pbVar4 >> (uVar8 & 0x3f);
        uVar6 = uVar7 & 0xff;
        cVar5 = cVar5 + '\x01';
        if (cVar5 == '\a') {
          if (cVar12 == '\0') {
            uVar6 = 0;
            cVar5 = '\0';
          }
          else {
            *(byte *)(param_1 + uVar10) = (byte)uVar7 & 0x7f;
            uVar10 = uVar10 + 1 & 0xff;
            uVar6 = 0;
            cVar5 = '\0';
          }
        }
        uVar8 = uVar8 - 1;
      } while ((uVar8 != 0xffffffff) ||
              ((cVar12 = cVar12 + '\x01', cVar12 != '\x12' &&
               (pbVar4 = pbVar4 + 1, uVar8 = 7, uVar10 < (byte)puVar1[4]))));
    }
    *(undefined1 *)(param_1 + (uint)(byte)PTR_DAT_0301f030[4]) = 0;
  }
  else {
    if ((bVar2 != 8) && (bVar2 != 0x10)) {
      pcVar11 = PTR_DAT_0301f03c + 0x1e;
      uVar8 = 0;
      pcVar9 = PTR_DAT_0301f03c;
      do {
        if (pcVar9[-1] == '\0') {
          if (*pcVar9 == '\0') {
LAB_0301f014:
            *(undefined1 *)(param_1 + uVar8) = 0;
            return;
          }
          *(char *)(param_1 + uVar8) = *pcVar9;
        }
        else {
          uVar3 = name_tag_encoded_length_table_lookup(CONCAT11(pcVar9[-1],*pcVar9));
          *(char *)(param_1 + uVar8) = (char)((ushort)uVar3 >> 8);
          uVar8 = uVar8 + 1 & 0xff;
          *(char *)(param_1 + uVar8) = (char)uVar3;
        }
        uVar8 = uVar8 + 1 & 0xff;
        if ((0xf < uVar8) || (pcVar9 = pcVar9 + 2, pcVar9 == pcVar11)) goto LAB_0301f014;
      } while( true );
    }
    bVar2 = strlen_ck803s(DAT_0301f038);
    if (0x12 < bVar2) {
      bVar2 = 0x12;
    }
    memcpy_bytes_iram(param_1,DAT_0301f038,(uint)bVar2);
    *(undefined1 *)(param_1 + (uint)bVar2) = 0;
  }
  return;
}


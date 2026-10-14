/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gb2312_string_reencode @ 0305d020 (file base 0x03000000; code starts at 0x03001000)
 * Size: 960 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void gb2312_string_reencode(char param_1,int param_2,uint param_3,undefined1 *param_4)

{
  byte bVar1;
  byte bVar2;
  radio_mode_state_0003e318 *prVar3;
  undefined *puVar4;
  undefined1 uVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  
  param_3 = param_3 & 0xffff;
  if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
    if (p_radio_mode_state_0003e318[1].flags_0x5 == 1) {
      *param_4 = 0xd;
      param_4[1] = 0;
      param_4[2] = 10;
      param_4[3] = 0;
      uVar6 = 4;
    }
    else if (p_radio_mode_state_0003e318[1].flags_0x5 == 2) {
      *param_4 = 0;
      param_4[1] = 0;
      param_4[2] = 2;
      param_4[3] = 1;
      param_4[4] = 1;
      if (param_1 == '\x03') {
        param_4[2] = 0;
        uVar6 = 5;
      }
      else {
        uVar6 = 5;
      }
    }
    else {
      *param_4 = 0;
      param_4[1] = 0;
      uVar6 = 2;
    }
    puVar4 = PTR_LAB_0305d1d8;
    prVar3 = p_radio_mode_state_0003e318;
    uVar8 = 0;
    while ((int)uVar8 < (int)(param_3 - 1)) {
      pbVar9 = (byte *)(param_2 + uVar8);
      bVar1 = *pbVar9;
      if ((char)bVar1 < '\0') {
        bVar2 = pbVar9[1];
        uVar7 = CONCAT11(bVar1,bVar2);
        uVar10 = (uint)uVar7;
        if (uVar10 < 0xd8a1) {
          if ((uVar10 + 0x4f5f & 0xffff) < 0x2759) {
            uVar7 = *(ushort *)
                     (puVar4 + (((uint)bVar2 + (uint)bVar1 * 0x5e) - 0x4141 & 0xffff) * 2 + 0x596);
          }
          else if ((uVar10 + 0x5e5e & 0xffff) < 0x5d) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa1a2) * 2);
          }
          else if ((uVar10 + 0x5d5f & 0xffff) < 10) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa244) * 2);
          }
          else if ((uVar10 + 0x5d4f & 0xffff) < 0x3e) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa24a) * 2);
          }
          else if ((uVar10 + 0x5d0f & 0xffff) < 0xc) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa24e) * 2);
          }
          else if ((uVar10 + 0x5c5f & 0xffff) < 0x5d) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa2f2) * 2);
          }
          else if ((uVar10 + 0x5b5f & 0xffff) < 0x53) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa395) * 2);
          }
          else if ((uVar10 + 0x5a5f & 0xffff) < 0x56) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa442) * 2);
          }
          else if ((uVar10 + 0x595f & 0xffff) < 0x18) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa4ec) * 2);
          }
          else if ((uVar10 + 0x593f & 0xffff) < 0x18) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa4f4) * 2);
          }
          else if ((uVar10 + 0x5920 & 0xffff) < 0xc) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa4fb) * 2);
          }
          else if ((uVar10 + 0x5912 & 0xffff) < 8) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa4fd) * 2);
          }
          else if ((uVar10 + 0x585f & 0xffff) < 0x21) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa5a9) * 2);
          }
          else if ((uVar10 + 0x582f & 0xffff) < 0x21) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa5b8) * 2);
          }
          else if ((uVar10 + 0x575f & 0xffff) < 0x20) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa667) * 2);
          }
          else if ((uVar10 + 0x573b & 0xffff) < 0x25) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa057) * 2);
          }
          else if ((uVar10 + 0x565c & 0xffff) < 0x4c) {
            uVar7 = *(ushort *)(puVar4 + (uVar10 - 0xa725) * 2);
          }
        }
        else {
          uVar7 = *(ushort *)
                   (puVar4 + ((((uint)bVar2 + (uint)bVar1 * 0x5e) - 0x4ff1 & 0xffff) + 0x1176) * 2);
        }
        uVar5 = (undefined1)(uVar7 >> 8);
        if (prVar3[1].flags_0x5 == 2) {
          param_4[uVar6] = uVar5;
          uVar6 = uVar6 + 1 & 0xffff;
          param_4[uVar6] = (char)uVar7;
        }
        else {
          param_4[uVar6] = (char)uVar7;
          uVar6 = uVar6 + 1 & 0xffff;
          param_4[uVar6] = uVar5;
        }
        uVar6 = uVar6 + 1 & 0xffff;
        uVar8 = uVar8 + 2 & 0xffff;
      }
      else {
        if ((prVar3[1].flags_0x5 == 2) && ((prVar3[1].flags_0x7 & 4) == 0)) {
          param_4[uVar6] = 0;
          uVar6 = uVar6 + 1 & 0xffff;
          param_4[uVar6] = *pbVar9;
          uVar6 = uVar6 + 1 & 0xffff;
        }
        else {
          param_4[uVar6] = bVar1;
          uVar6 = uVar6 + 1 & 0xffff;
          if ((prVar3[1].flags_0x7 & 4) == 0) {
            param_4[uVar6] = 0;
            uVar6 = uVar6 + 1 & 0xffff;
          }
        }
        uVar8 = uVar8 + 1 & 0xffff;
      }
    }
  }
  else {
    *param_4 = 0x27;
    param_4[1] = 0x7e;
    param_4[2] = 0x27;
    param_4[3] = 0x7e;
    if (param_3 == 0) {
      uVar6 = 4;
    }
    else {
      uVar6 = 0;
      uVar8 = 4;
      do {
        param_4[uVar8] = *(undefined1 *)(param_2 + uVar6);
        uVar8 = uVar8 + 1 & 0xffff;
        uVar6 = uVar6 + 1;
      } while ((uVar6 & 0xffff) < param_3);
      uVar6 = param_3 + 4 & 0xffff;
    }
  }
  param_4[uVar6 + 1] = 0;
  param_4[uVar6] = 0;
  return;
}


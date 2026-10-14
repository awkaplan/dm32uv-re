/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_message_fragment_and_link @ 03026694 (file base 0x03000000; code starts at 0x03001000)
 * Size: 710 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 history_message_fragment_and_link(int param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uStack_40;
  undefined1 local_3c;
  undefined1 auStack_3b [23];
  
  uVar6 = (uint)(byte)PTR_DAT_03026798[0x26];
  if (uVar6 != 0) {
    uVar11 = 0;
    uStack_40 = param_1 + 0x4b;
    do {
      if ((param_2 != '\0') ||
         (((int)(uint)*(byte *)(param_1 + (uVar11 >> 3) + 0x37) >> (uVar11 & 7) & 1U) == 0)) {
        if ((int)uVar11 < (int)(uVar6 - 1)) {
          iVar1 = history_slot_allocate();
          if (iVar1 == 0) {
            OSTimeDly_ms_wrapper(0x3c);
            iVar1 = history_slot_allocate();
            if (iVar1 == 0) {
              return 1;
            }
          }
          memset_bytes(iVar1 + 5,0,0x18);
          *(undefined1 *)(iVar1 + 2) = 0;
          *(undefined1 *)(iVar1 + 3) = *(undefined1 *)(param_1 + 0x35);
          iVar4 = *(byte *)(param_1 + 0x34) - 2;
          uVar6 = uVar11 * iVar4;
          uVar7 = uVar6 & 0xffff;
          *(short *)(param_1 + 0x36e) = (short)uVar6;
          if ((int)(uint)*(ushort *)(param_1 + 0x36c) < (int)(iVar4 + uVar7)) {
            memcpy_bytes_iram(iVar1 + 7,uStack_40 + uVar7,*(ushort *)(param_1 + 0x36c) - uVar7);
          }
          else {
            memcpy_bytes_iram(iVar1 + 7,uStack_40 + uVar7);
          }
          *(char *)(iVar1 + 5) = (char)uVar11 * '\x02';
          uVar2 = crc9_bitserial(0,(*(char *)(param_1 + 0x34) + -2) * '\b',iVar1 + 7);
          *(short *)(param_1 + 0x370) = (short)uVar2;
          uVar6 = crc9_bitserial(uVar2,7,iVar1 + 5);
          uVar6 = ((uint)*(ushort *)(param_1 + 0x372) ^ ~uVar6) & 0x1ff;
          *(short *)(param_1 + 0x370) = (short)uVar6;
          *(byte *)(iVar1 + 5) = (byte)(uVar6 >> 8) | *(byte *)(iVar1 + 5);
          *(char *)(iVar1 + 6) = (char)*(undefined2 *)(param_1 + 0x370);
          history_slot_link_append(iVar1);
        }
        else {
          iVar1 = history_slot_allocate();
          if (iVar1 == 0) {
            OSTimeDly_ms_wrapper(0x3c);
            iVar1 = history_slot_allocate();
            if (iVar1 == 0) {
              return 1;
            }
          }
          memset_bytes(iVar1 + 5,0,0x18);
          *(undefined1 *)(iVar1 + 2) = 0;
          *(undefined1 *)(iVar1 + 3) = *(undefined1 *)(param_1 + 0x35);
          uVar6 = uVar11 * (*(byte *)(param_1 + 0x34) - 2);
          uVar7 = uVar6 & 0xffff;
          *(short *)(param_1 + 0x36e) = (short)uVar6;
          if (uVar7 < *(ushort *)(param_1 + 0x36c)) {
            memcpy_bytes_iram(iVar1 + 7,uStack_40 + uVar7,*(ushort *)(param_1 + 0x36c) - uVar7);
          }
          *(undefined4 *)(param_1 + 0x374) = 0;
          uVar6 = (uint)(ushort)((ushort)*(byte *)(param_1 + 0xf) + *(short *)(param_1 + 0x36c));
          uVar7 = uVar6 / 0x18;
          if (uVar7 == 0) {
            uVar10 = 0;
          }
          else {
            uVar9 = 0;
            uVar10 = 0;
            do {
              puVar3 = (undefined1 *)(param_1 + uVar10 + 0x4b);
              puVar5 = (undefined1 *)((int)&uStack_40 + 3);
              uVar8 = 0;
              do {
                if ((uVar8 & 1) == 0) {
                  puVar5[2] = *puVar3;
                }
                else {
                  *puVar5 = *puVar3;
                }
                uVar8 = uVar8 + 1;
                puVar3 = puVar3 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar8 != 0x18);
              uVar10 = uVar10 + 0x18 & 0xffff;
              uVar2 = crc32_mpeg2_bitserial(*(undefined4 *)(param_1 + 0x374),0xc0,&local_3c);
              *(undefined4 *)(param_1 + 0x374) = uVar2;
              uVar9 = uVar9 + 1 & 0xff;
            } while (uVar9 < uVar7);
          }
          uVar6 = uVar6 % 0x18;
          if (uVar6 != 0) {
            uVar7 = 0;
            do {
              if ((uVar7 & 1) == 0) {
                auStack_3b[uVar7] = *(undefined1 *)(param_1 + uVar10 + uVar7 + 0x4b);
              }
              else {
                *(undefined1 *)((int)&uStack_40 + uVar7 + 3) =
                     *(undefined1 *)(param_1 + uVar10 + uVar7 + 0x4b);
              }
              uVar7 = uVar7 + 1 & 0xff;
            } while (uVar7 < uVar6);
            uVar2 = crc32_mpeg2_bitserial(*(undefined4 *)(param_1 + 0x374),uVar6 << 3,&local_3c);
            *(undefined4 *)(param_1 + 0x374) = uVar2;
          }
          *(char *)(iVar1 + (uint)*(byte *)(param_1 + 0x34) + 1) =
               (char)*(undefined4 *)(param_1 + 0x374);
          *(char *)(iVar1 + (uint)*(byte *)(param_1 + 0x34) + 2) =
               (char)((uint)*(undefined4 *)(param_1 + 0x374) >> 8);
          *(char *)(iVar1 + (uint)*(byte *)(param_1 + 0x34) + 3) =
               (char)*(undefined2 *)(param_1 + 0x376);
          *(undefined1 *)(iVar1 + (uint)*(byte *)(param_1 + 0x34) + 4) =
               *(undefined1 *)(param_1 + 0x377);
          *(char *)(iVar1 + 5) = (char)uVar11 * '\x02';
          uVar2 = crc9_bitserial(0,(*(char *)(param_1 + 0x34) + -2) * '\b',iVar1 + 7);
          *(short *)(param_1 + 0x370) = (short)uVar2;
          uVar6 = crc9_bitserial(uVar2,7,iVar1 + 5);
          uVar6 = ((uint)*(ushort *)(param_1 + 0x372) ^ ~uVar6) & 0x1ff;
          *(short *)(param_1 + 0x370) = (short)uVar6;
          *(byte *)(iVar1 + 5) = (byte)(uVar6 >> 8) | *(byte *)(iVar1 + 5);
          *(char *)(iVar1 + 6) = (char)*(undefined2 *)(param_1 + 0x370);
          history_slot_link_append(iVar1);
        }
      }
      uVar11 = uVar11 + 1 & 0xff;
      uVar6 = (uint)*(byte *)((int)PTR_DAT_03026a9c + 0x26);
    } while (uVar11 < uVar6);
  }
  return 0;
}


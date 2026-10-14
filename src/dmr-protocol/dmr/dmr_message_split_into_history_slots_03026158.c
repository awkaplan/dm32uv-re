/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_message_split_into_history_slots @ 03026158 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1108 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 dmr_message_split_into_history_slots(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b [23];
  
  if (*(char *)(param_1 + 1) == '\0') {
    *(undefined4 *)(param_1 + 0x374) = 0;
    if (0 < (int)(*(byte *)(param_1 + 0x26) - 1)) {
      uVar9 = 0;
      local_40 = param_1 + 0x4b;
      do {
        iVar2 = history_slot_allocate();
        if (iVar2 == 0) {
          OSTimeDly_ms_wrapper(0x3c);
          iVar2 = history_slot_allocate();
          if (iVar2 == 0) {
            return 1;
          }
        }
        iVar5 = iVar2 + 5;
        memset_bytes(iVar5,0,0x18);
        *(undefined1 *)(iVar2 + 2) = 0;
        *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(param_1 + 0x35);
        uVar7 = (uint)*(ushort *)(param_1 + 0x36e);
        uVar8 = (uint)*(ushort *)(param_1 + 0x36c);
        if (uVar8 < *(byte *)(param_1 + 0x34) + uVar7) {
          if (uVar7 <= uVar8) {
            memcpy_bytes_iram(iVar5,local_40 + uVar7,uVar8 - uVar7);
          }
        }
        else {
          memcpy_bytes_iram(iVar5,local_40 + uVar7);
        }
        uVar7 = (uint)*(byte *)(param_1 + 0x34);
        *(ushort *)(param_1 + 0x36e) =
             (ushort)*(byte *)(param_1 + 0x34) + *(short *)(param_1 + 0x36e);
        if (uVar7 != 0) {
          puVar10 = (undefined1 *)(iVar2 + 5);
          puVar4 = (undefined1 *)((int)&local_40 + 3);
          uVar8 = 0;
          do {
            if ((uVar8 & 1) == 0) {
              puVar4[2] = *puVar10;
            }
            else {
              *puVar4 = *puVar10;
            }
            uVar8 = uVar8 + 1;
            puVar10 = puVar10 + 1;
            puVar4 = puVar4 + 1;
          } while ((uVar8 & 0xff) < uVar7);
        }
        uVar3 = crc32_mpeg2_bitserial(*(undefined4 *)(param_1 + 0x374),uVar7 << 3,&local_3c);
        *(undefined4 *)(param_1 + 0x374) = uVar3;
        history_slot_link_append(iVar2);
        uVar9 = uVar9 + 1 & 0xff;
      } while ((int)uVar9 < (int)(*(byte *)(param_1 + 0x26) - 1));
    }
    iVar2 = history_slot_allocate();
    if (iVar2 == 0) {
      OSTimeDly_ms_wrapper(0x3c);
      iVar2 = history_slot_allocate();
      if (iVar2 == 0) {
        return 1;
      }
    }
    memset_bytes(iVar2 + 5,0,0x18);
    *(undefined1 *)(iVar2 + 2) = 0;
    *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(param_1 + 0x35);
    uVar9 = (uint)*(ushort *)(param_1 + 0x36e);
    if (uVar9 < *(ushort *)(param_1 + 0x36c)) {
      memcpy_bytes_iram(iVar2 + 5,param_1 + 0x4b + uVar9,*(ushort *)(param_1 + 0x36c) - uVar9);
    }
    iVar5 = *(byte *)(param_1 + 0x34) - 4;
    if (0 < iVar5) {
      uVar9 = 0;
      do {
        if ((uVar9 & 1) == 0) {
          local_3b[uVar9] = *(undefined1 *)(iVar2 + uVar9 + 5);
        }
        else {
          *(undefined1 *)((int)&local_40 + uVar9 + 3) = *(undefined1 *)(iVar2 + uVar9 + 5);
        }
        uVar9 = uVar9 + 1 & 0xff;
      } while ((int)uVar9 < iVar5);
    }
    uVar3 = crc32_mpeg2_bitserial(*(undefined4 *)(param_1 + 0x374),iVar5 * 8 & 0xfff8,&local_3c);
    *(undefined4 *)(param_1 + 0x374) = uVar3;
    *(char *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 1) = (char)uVar3;
    *(char *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 2) =
         (char)((uint)*(undefined4 *)(param_1 + 0x374) >> 8);
    *(char *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 3) = (char)*(undefined2 *)(param_1 + 0x376);
    *(undefined1 *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 4) = *(undefined1 *)(param_1 + 0x377);
    history_slot_link_append(iVar2);
  }
  else {
    *(undefined4 *)(param_1 + 0x374) = 0;
    if ((int)(*(byte *)(param_1 + 0x11) - 1) < 1) {
      uVar9 = 0;
    }
    else {
      uVar9 = 0;
      local_40 = param_1 + 0x4b;
      do {
        iVar2 = history_slot_allocate();
        if (iVar2 == 0) {
          OSTimeDly_ms_wrapper(0x3c);
          iVar2 = history_slot_allocate();
          if (iVar2 == 0) {
            return 1;
          }
        }
        memset_bytes(iVar2 + 5,0,0x18);
        *(undefined1 *)(iVar2 + 2) = 0;
        *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(param_1 + 0x35);
        uVar7 = (uint)*(ushort *)(param_1 + 0x36e);
        if ((int)(uint)*(ushort *)(param_1 + 0x36c) < (int)(uVar7 + *(byte *)(param_1 + 0x34) + -2))
        {
          memcpy_bytes_iram(iVar2 + 7,local_40 + uVar7,*(ushort *)(param_1 + 0x36c) - uVar7);
        }
        else {
          memcpy_bytes_iram(iVar2 + 7,local_40 + uVar7,*(byte *)(param_1 + 0x34) - 2);
        }
        *(ushort *)(param_1 + 0x36e) =
             *(short *)(param_1 + 0x36e) + -2 + (ushort)*(byte *)(param_1 + 0x34);
        *(char *)(iVar2 + 5) = (char)uVar9 * '\x02';
        puVar10 = (undefined1 *)(iVar2 + 7);
        uVar3 = crc9_bitserial(0,(*(char *)(param_1 + 0x34) + -2) * '\b',puVar10);
        *(short *)(param_1 + 0x370) = (short)uVar3;
        uVar7 = crc9_bitserial(uVar3,7,iVar2 + 5);
        uVar7 = ((uint)*(ushort *)(param_1 + 0x372) ^ ~uVar7) & 0x1ff;
        *(short *)(param_1 + 0x370) = (short)uVar7;
        *(byte *)(iVar2 + 5) = (byte)(uVar7 >> 8) | *(byte *)(iVar2 + 5);
        *(char *)(iVar2 + 6) = (char)*(undefined2 *)(param_1 + 0x370);
        uVar7 = (uint)*(byte *)(param_1 + 0x34);
        if (2 < uVar7) {
          puVar4 = (undefined1 *)((int)&local_40 + 3);
          bVar6 = false;
          uVar8 = 2;
          do {
            if (bVar6) {
              *puVar4 = *puVar10;
            }
            else {
              puVar4[2] = *puVar10;
            }
            uVar8 = uVar8 + 1 & 0xff;
            bVar6 = (bool)(bVar6 ^ 1);
            puVar10 = puVar10 + 1;
            puVar4 = puVar4 + 1;
          } while (uVar8 < uVar7);
        }
        uVar3 = crc32_mpeg2_bitserial
                          (*(undefined4 *)(param_1 + 0x374),(uVar7 - 2) * 8 & 0xfff8,&local_3c);
        *(undefined4 *)(param_1 + 0x374) = uVar3;
        history_slot_link_append(iVar2);
        uVar9 = uVar9 + 1 & 0xff;
      } while ((int)uVar9 < (int)(*(byte *)(param_1 + 0x11) - 1));
    }
    iVar2 = history_slot_allocate();
    if (iVar2 == 0) {
      OSTimeDly_ms_wrapper(0x3c);
      iVar2 = history_slot_allocate();
      if (iVar2 == 0) {
        return 1;
      }
    }
    memset_bytes(iVar2 + 5,0,0x18);
    *(undefined1 *)(iVar2 + 2) = 0;
    *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(param_1 + 0x35);
    uVar7 = (uint)*(ushort *)(param_1 + 0x36e);
    if (uVar7 < *(ushort *)(param_1 + 0x36c)) {
      memcpy_bytes_iram(iVar2 + 7,param_1 + 0x4b + uVar7,*(ushort *)(param_1 + 0x36c) - uVar7);
    }
    bVar1 = *(byte *)(param_1 + 0x34);
    iVar5 = bVar1 - 4;
    if (2 < iVar5) {
      uVar7 = 2;
      do {
        if ((uVar7 & 1) == 0) {
          *(undefined1 *)((int)&local_40 + uVar7 + 3) = *(undefined1 *)(iVar2 + uVar7 + 5);
        }
        else {
          *(undefined1 *)((int)&local_40 + uVar7 + 1) = *(undefined1 *)(iVar2 + uVar7 + 5);
        }
        uVar7 = uVar7 + 1 & 0xff;
      } while ((int)uVar7 < iVar5);
    }
    uVar3 = crc32_mpeg2_bitserial
                      (*(undefined4 *)(param_1 + 0x374),(bVar1 - 6) * 8 & 0xfff8,&local_3c);
    *(undefined4 *)(param_1 + 0x374) = uVar3;
    *(char *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 1) = (char)uVar3;
    *(char *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 2) =
         (char)((uint)*(undefined4 *)(param_1 + 0x374) >> 8);
    *(char *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 3) = (char)*(undefined2 *)(param_1 + 0x376);
    *(undefined1 *)(iVar2 + (uint)*(byte *)(param_1 + 0x34) + 4) = *(undefined1 *)(param_1 + 0x377);
    *(char *)(iVar2 + 5) = (char)uVar9 * '\x02';
    uVar3 = crc9_bitserial(0,(*(char *)(param_1 + 0x34) + -2) * '\b',iVar2 + 7);
    *(short *)(param_1 + 0x370) = (short)uVar3;
    uVar9 = crc9_bitserial(uVar3,7,iVar2 + 5);
    uVar9 = ((uint)*(ushort *)(param_1 + 0x372) ^ ~uVar9) & 0x1ff;
    *(short *)(param_1 + 0x370) = (short)uVar9;
    *(byte *)(iVar2 + 5) = (byte)(uVar9 >> 8) | *(byte *)(iVar2 + 5);
    *(char *)(iVar2 + 6) = (char)*(undefined2 *)(param_1 + 0x370);
    history_slot_link_append(iVar2);
  }
  return 0;
}


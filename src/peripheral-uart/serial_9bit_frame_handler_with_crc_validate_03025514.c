/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: serial_9bit_frame_handler_with_crc_validate @ 03025514 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1662 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: peripheral-uart
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void serial_9bit_frame_handler_with_crc_validate(int param_1__w)

{
  char param_1 = (char)param_1__w;
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  ushort uVar9;
  undefined4 uVar10;
  int iVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  undefined1 *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined4 uStack_58;
  undefined1 local_54;
  byte local_53 [19];
  byte abStack_40 [28];
  
  if (PTR_DAT_030255c8[6] != p_call_setup_sm_state_aux->field_0x5) {
    return;
  }
  p_dmr_call_config_state->field_0x3 = 1;
  if (param_1 == '\a') {
    PTR_DAT_030255c4[0x1c5] = 0xf0;
    uVar19 = 0xc;
  }
  else if (param_1 == '\b') {
    PTR_DAT_030255c4[0x1c5] = 0x1ff;
    uVar19 = 0x12;
  }
  else {
    if (param_1 != '\n') {
      return;
    }
    PTR_DAT_030255c4[0x1c5] = 0x10f;
    uVar19 = 0x18;
  }
  if (*(char *)((uint)*(byte *)p_dmr_call_config_state + p_dmr_config_unpack_state + 2) != '\x01') {
    return;
  }
  *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
  copy_bytes_from_offset_table(0,abStack_40 + 4,uVar19);
  puVar8 = PTR_DAT_03025ae0;
  puVar7 = PTR_DAT_0302579c;
  puVar6 = PTR_DAT_030255c4;
  if (*(char *)((int)PTR_DAT_030255c4 + 1) == '\x01') {
    if (*(char *)((int)PTR_DAT_030255c4 + 0xb) == '\x01') {
      *(char *)((int)PTR_DAT_030255c4 + 0x3b) = (char)uVar19 + -2;
      memcpy_bytes_iram((int)puVar6 + *(int *)(puVar6 + 0x1c2) + 0x5a,abStack_40 + 6);
      *(uint *)(puVar6 + 0x1c2) = (uint)*(byte *)((int)puVar6 + 0x3b) + *(int *)(puVar6 + 0x1c2);
    }
    else {
      *(char *)((int)PTR_DAT_0302579c + 0x3b) = (char)(uVar19 - 2);
      iVar11 = (uVar19 - 2 & 0xff) * (uint)(abStack_40[4] >> 1);
      puVar7[0xe1] = iVar11;
      memcpy_bytes_iram((int)puVar7 + iVar11 + 0x5a,abStack_40 + 6);
      puVar7[0xe1] = (uint)*(byte *)((int)puVar7 + 0x3b) + puVar7[0xe1];
    }
    puVar7 = PTR_DAT_0302579c;
    uVar10 = crc9_bitserial(0,(*(byte *)((int)PTR_DAT_0302579c + 0x3b) & 0x1f) << 3,abStack_40 + 6);
    *(short *)(puVar7 + 0xe2) = (short)uVar10;
    uVar9 = crc9_bitserial(uVar10,7,abStack_40 + 4);
    uVar9 = (*(ushort *)((int)puVar7 + 0x38a) ^ ~uVar9) & 0x1ff;
    *(ushort *)(puVar7 + 0xe2) = uVar9;
    puVar8 = PTR_DAT_0302579c;
    if (uVar9 == (ushort)((abStack_40[4] & 1) * 0x100 + (ushort)abStack_40[5])) {
      *(byte *)(puVar7 + 0xf) = (abStack_40[4] >> 1) + 1;
    }
    else {
      bVar3 = *(byte *)(PTR_DAT_0302579c + 0xf);
      *(byte *)((int)PTR_DAT_0302579c + (bVar3 >> 3) + 0x3e) =
           ((byte)(-2 << (bVar3 & 7)) | (byte)(0xfffffffe >> 0x20 - (bVar3 & 7))) &
           *(byte *)((int)PTR_DAT_0302579c + (bVar3 >> 3) + 0x3e);
      *(byte *)(puVar8 + 0xf) = bVar3 + 1;
      *(undefined1 *)((int)puVar8 + 0x11) = 2;
      *(undefined1 *)((int)puVar8 + 0x12) = 0;
      *(undefined1 *)((int)puVar8 + 0x13) = *(undefined1 *)((int)puVar8 + 0xe);
      *(byte *)(puVar8 + 0xe5) = *(byte *)(puVar8 + 0xe5) | 1;
    }
    puVar8 = PTR_DAT_0302591c;
    puVar7 = PTR_DAT_0302579c;
    if (*(byte *)(PTR_DAT_0302579c + 0xf) < *(byte *)(PTR_DAT_0302579c + 3)) {
      if (2 < uVar19) {
        pbVar12 = abStack_40 + 6;
        pbVar14 = (byte *)((int)&uStack_58 + 3);
        uVar16 = 0;
        do {
          if ((uVar16 & 1) == 0) {
            pbVar14[2] = *pbVar12;
          }
          else {
            *pbVar14 = *pbVar12;
          }
          uVar16 = uVar16 + 1;
          pbVar12 = pbVar12 + 1;
          pbVar14 = pbVar14 + 1;
        } while (uVar16 != (uVar19 - 3 & 0xff) + 1);
      }
      uVar10 = crc32_mpeg2_bitserial(PTR_DAT_0302579c[0xe3],(uVar19 - 2) * 8 & 0xfff0,&local_54);
      puVar7[0xe3] = uVar10;
      return;
    }
    if (*(char *)((int)PTR_DAT_0302579c + 0xb) == '\x01') {
      PTR_DAT_0302579c[0xe4] =
           (uint)abStack_40[uVar19 + 2] * 0x10000 + (uint)abStack_40[uVar19 + 3] * 0x1000000 +
           (uint)abStack_40[uVar19] + (uint)abStack_40[uVar19 + 1] * 0x100;
      puVar7 = PTR_DAT_0302579c;
      if (2 < (int)(uVar19 - 4)) {
        uVar16 = 2;
        do {
          if ((uVar16 & 1) == 0) {
            *(byte *)((int)&uStack_58 + uVar16 + 3) = abStack_40[uVar16 + 4];
          }
          else {
            *(byte *)((int)&uStack_58 + uVar16 + 1) = abStack_40[uVar16 + 4];
          }
          uVar16 = uVar16 + 1 & 0xff;
        } while ((int)uVar16 < (int)(uVar19 - 4));
      }
      iVar11 = crc32_mpeg2_bitserial(PTR_DAT_0302579c[0xe3],(uVar19 - 6) * 8 & 0xfff0,&local_54);
      puVar7[0xe3] = iVar11;
      puVar8 = PTR_DAT_0302591c;
      if (iVar11 == puVar7[0xe4]) {
        *(undefined1 *)((int)puVar7 + 0x11) = 0;
        *(undefined1 *)((int)puVar7 + 0x12) = 1;
        *(undefined1 *)((int)puVar7 + 0x13) = *(undefined1 *)((int)puVar7 + 0xe);
      }
      else {
        *(undefined1 *)((int)PTR_DAT_0302591c + 0x11) = 1;
        *(undefined1 *)((int)puVar8 + 0x12) = 1;
        *(undefined1 *)((int)puVar8 + 0x13) = *(undefined1 *)((int)puVar8 + 0xe);
        *(byte *)(puVar8 + 0xe5) = *(byte *)(puVar8 + 0xe5) | 2;
      }
      cVar1 = *(char *)(PTR_DAT_0302591c + 1);
      if ((byte)(cVar1 - 2U) < 2) {
        if (*(byte *)((int)PTR_DAT_0302591c + 10) + 4 < (uint)PTR_DAT_0302591c[0xe1]) {
          PTR_DAT_0302591c[0xdf] =
               (PTR_DAT_0302591c[0xe1] - 4) - (uint)*(byte *)((int)PTR_DAT_0302591c + 10);
        }
        else {
          PTR_DAT_0302591c[0xdf] = 0;
        }
      }
      else if ((byte)(cVar1 - 0xdU) < 2) {
        uVar19 = (uint)(*(byte *)((int)PTR_DAT_0302591c + 0x1a) >> 3);
        if (uVar19 + 4 < (uint)PTR_DAT_0302591c[0xe1]) {
          PTR_DAT_0302591c[0xdf] = (PTR_DAT_0302591c[0xe1] - 4) - uVar19;
        }
        else {
          PTR_DAT_0302591c[0xdf] = 0;
        }
      }
      else if (cVar1 == '\0') {
        uVar19 = (uint)(*(byte *)((int)PTR_DAT_0302591c + 0x1d) >> 1);
        if (uVar19 + 4 < (uint)PTR_DAT_0302591c[0xe1]) {
          PTR_DAT_0302591c[0xdf] = (PTR_DAT_0302591c[0xe1] - 4) - uVar19;
        }
        else {
          PTR_DAT_0302591c[0xdf] = 0;
        }
      }
      else if ((uint)PTR_DAT_0302591c[0xe1] < 5) {
        PTR_DAT_0302591c[0xdf] = 0;
      }
      else {
        PTR_DAT_0302591c[0xdf] = PTR_DAT_0302591c[0xe1] - 4;
      }
      serial_frame_classify_and_extract_ids(PTR_DAT_0302591c);
      OSFlagPost_wrapper_set_passthrough();
      return;
    }
    PTR_DAT_0302591c[0xe3] = 0;
    puVar7 = PTR_DAT_0302591c;
    uStack_58 = (uint)*(byte *)((int)puVar8 + 10) + puVar8[0xdf] & 0xffff;
    uVar16 = uStack_58 / 0x18;
    if (uVar16 == 0) {
      uVar20 = 0;
    }
    else {
      uVar20 = 0;
      uVar18 = 0;
      do {
        puVar13 = (undefined1 *)((int)puVar7 + uVar20 + 0x5a);
        puVar15 = (undefined1 *)((int)&uStack_58 + 3);
        uVar17 = 0;
        do {
          if ((uVar17 & 1) == 0) {
            puVar15[2] = *puVar13;
          }
          else {
            *puVar15 = *puVar13;
          }
          uVar17 = uVar17 + 1;
          puVar13 = puVar13 + 1;
          puVar15 = puVar15 + 1;
        } while (uVar17 != 0x18);
        uVar20 = uVar20 + 0x18 & 0xffff;
        uVar10 = crc32_mpeg2_bitserial(puVar7[0xe3],0xc0,&local_54);
        puVar7[0xe3] = uVar10;
        uVar18 = uVar18 + 1 & 0xff;
      } while (uVar18 < uVar16);
    }
    puVar7 = PTR_DAT_03025ae0;
    uVar16 = uStack_58 % 0x18;
    if (uVar16 != 0) {
      uVar18 = 0;
      do {
        if ((uVar18 & 1) == 0) {
          local_53[uVar18] = *(byte *)((int)PTR_DAT_0302591c + uVar18 + uVar20 + 0x5a);
        }
        else {
          *(undefined1 *)((int)&uStack_58 + uVar18 + 3) =
               *(undefined1 *)((int)PTR_DAT_0302591c + uVar18 + uVar20 + 0x5a);
        }
        uVar18 = uVar18 + 1 & 0xff;
      } while (uVar18 < uVar16);
      uVar10 = crc32_mpeg2_bitserial(PTR_DAT_03025ae0[0xe3],uVar16 << 3,&local_54);
      puVar7[0xe3] = uVar10;
    }
    if (*(char *)((int)PTR_DAT_03025ae0 + 0x3d) == (byte)((abStack_40[4] >> 1) + 1)) {
      PTR_DAT_03025ae0[0xe4] =
           (uint)abStack_40[uVar19 + 3] * 0x1000000 + (uint)abStack_40[uVar19 + 2] * 0x10000 +
           (uint)abStack_40[uVar19] + (uint)abStack_40[uVar19 + 1] * 0x100;
    }
    puVar7 = PTR_DAT_03025ae0;
    if (PTR_DAT_03025ae0[0xe4] == PTR_DAT_03025ae0[0xe3]) {
      *(undefined1 *)((int)PTR_DAT_03025ae0 + 0x11) = 0;
      *(undefined1 *)((int)puVar7 + 0x12) = 1;
      *(undefined1 *)((int)puVar7 + 0x13) = *(undefined1 *)((int)puVar7 + 0xe);
    }
    else {
      *(undefined1 *)((int)PTR_DAT_03025ae0 + 0x11) = 1;
      *(undefined1 *)((int)puVar7 + 0x12) = 1;
      *(undefined1 *)((int)puVar7 + 0x13) = *(undefined1 *)((int)puVar7 + 0xe);
      *(byte *)(puVar7 + 0xe5) = *(byte *)(puVar7 + 0xe5) | 2;
    }
    serial_frame_classify_and_extract_ids(PTR_DAT_03025ae0);
    OSFlagPost_wrapper_set_passthrough();
    return;
  }
  *(char *)((int)PTR_DAT_03025ae0 + 0x3b) = (char)uVar19;
  memcpy_bytes_iram((int)puVar8 + puVar8[0xe1] + 0x5a,abStack_40 + 4,uVar19);
  puVar8[0xe1] = (uint)*(byte *)((int)puVar8 + 0x3b) + puVar8[0xe1];
  cVar1 = *(char *)(puVar8 + 0xf);
  *(byte *)(puVar8 + 0xf) = cVar1 + 1U;
  puVar7 = PTR_DAT_03025ae0;
  if ((byte)(cVar1 + 1U) < *(byte *)(puVar8 + 3)) {
    if (uVar19 != 0) {
      pbVar12 = (byte *)((int)&uStack_58 + 3);
      uVar16 = 0;
      do {
        if ((uVar16 & 1) == 0) {
          pbVar12[2] = abStack_40[uVar16 + 4];
        }
        else {
          *pbVar12 = abStack_40[uVar16 + 4];
        }
        uVar16 = uVar16 + 1;
        pbVar12 = pbVar12 + 1;
      } while ((uVar16 & 0xff) < uVar19);
    }
    uVar10 = crc32_mpeg2_bitserial(PTR_DAT_03025ae0[0xe3],uVar19 << 3,&local_54);
    puVar7[0xe3] = uVar10;
    return;
  }
  iVar11 = uVar19 - 4;
  if (0 < iVar11) {
    uVar16 = 0;
    do {
      if ((uVar16 & 1) == 0) {
        local_53[uVar16] = abStack_40[uVar16 + 4];
      }
      else {
        *(byte *)((int)&uStack_58 + uVar16 + 3) = abStack_40[uVar16 + 4];
      }
      uVar16 = uVar16 + 1 & 0xff;
    } while ((int)uVar16 < iVar11);
  }
  iVar11 = crc32_mpeg2_bitserial(PTR_DAT_03025ae0[0xe3],iVar11 * 8 & 0xfff0,&local_54);
  puVar7[0xe3] = iVar11;
  bVar4 = abStack_40[uVar19 + 3];
  bVar3 = abStack_40[uVar19 + 2];
  bVar5 = abStack_40[uVar19];
  bVar2 = abStack_40[uVar19 + 1];
  *(undefined1 *)((uint)*(byte *)p_dmr_call_config_state + p_dmr_config_unpack_state + 2) = 0;
  if (iVar11 != (uint)bVar3 * 0x10000 + (uint)bVar4 * 0x1000000 + (uint)bVar5 + (uint)bVar2 * 0x100)
  {
    *(byte *)(puVar7 + 0xe5) = *(byte *)(puVar7 + 0xe5) | 2;
    return;
  }
  cVar1 = *(char *)(PTR_DAT_03025c50 + 1);
  if ((byte)(cVar1 - 2U) < 2) {
    if ((uint)PTR_DAT_03025c50[0xe1] <= *(byte *)((int)PTR_DAT_03025c50 + 10) + 4) {
      PTR_DAT_03025c50[0xdf] = 0;
      goto LAB_03025bae;
    }
    PTR_DAT_03025c50[0xdf] =
         (PTR_DAT_03025c50[0xe1] - 4) - (uint)*(byte *)((int)PTR_DAT_03025c50 + 10);
  }
  else if ((byte)(cVar1 - 0xdU) < 2) {
    uVar19 = (uint)(*(byte *)((int)PTR_DAT_03025c50 + 0x1a) >> 3);
    if ((uint)PTR_DAT_03025c50[0xe1] <= uVar19 + 4) {
      PTR_DAT_03025c50[0xdf] = 0;
      goto LAB_03025bae;
    }
    PTR_DAT_03025c50[0xdf] = (PTR_DAT_03025c50[0xe1] - 4) - uVar19;
  }
  else if (cVar1 == '\0') {
    uVar19 = (uint)(*(byte *)((int)PTR_DAT_03025c50 + 0x1d) >> 1);
    if ((uint)PTR_DAT_03025c50[0xe1] <= uVar19 + 4) {
      PTR_DAT_03025c50[0xdf] = 0;
      goto LAB_03025bae;
    }
    PTR_DAT_03025c50[0xdf] = (PTR_DAT_03025c50[0xe1] - 4) - uVar19;
  }
  else {
    if ((uint)PTR_DAT_03025c50[0xe1] < 5) {
      PTR_DAT_03025c50[0xdf] = 0;
      goto LAB_03025bae;
    }
    PTR_DAT_03025c50[0xdf] = PTR_DAT_03025c50[0xe1] - 4;
  }
  if (600 < (uint)PTR_DAT_03025c50[0xdf]) {
    PTR_DAT_03025c50[0xdf] = 600;
  }
LAB_03025bae:
  serial_frame_classify_and_extract_ids(PTR_DAT_03025c50);
  OSFlagPost_wrapper_set_passthrough();
  return;
}


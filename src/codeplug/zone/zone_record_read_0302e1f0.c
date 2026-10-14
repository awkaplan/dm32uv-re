/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: zone_record_read @ 0302e1f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 880 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void zone_record_read(int param_1__w)

{
  ushort param_1 = (ushort)param_1__w;
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined1 uVar5;
  vfo_freq_display_state *pvVar6;
  vfo_freq_display_state *pvVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  ushort block_id;
  undefined2 uVar12;
  short *psVar13;
  byte bVar14;
  uint uVar15;
  short *psVar16;
  uint uVar17;
  uint uVar18;
  short sStack_68;
  undefined1 auStack_66 [2];
  short asStack_64 [16];
  short asStack_44 [16];
  byte bStack_23;
  ushort uStack_22;
  
  pvVar6 = p_vfo_freq_display_state;
  p_vfo_freq_display_state->field_0x5c = 0;
  if ((param_1 & 0xff) == 0) {
    pvVar6->field_0x1 = 0;
  }
  else {
    block_id = flash_block_id_resolve_locked(0x11);
    puVar8 = PTR_DAT_0302e3c0;
    sVar1 = ((param_1 & 0xff) - 1) * 0x39;
    flash_block_read(block_id,(uint)(ushort)(sVar1 + 0xc),PTR_DAT_0302e3c0,4);
    puVar9 = PTR_DAT_0302e3c4;
    if ((byte)(*puVar8 - 2) < 0xf) {
      flash_block_read(block_id,(uint)(ushort)(sVar1 + 0x10),PTR_DAT_0302e3c4,7);
      flash_block_read(block_id,(uint)(ushort)(sVar1 + 0x19),puVar9 + 4,
                       (uint)*(byte *)((int)puVar9 + -5) << 1);
      *(undefined2 *)(puVar9 + 4) = *(undefined2 *)((int)puVar9 + 0x4e);
      if (2 < *(byte *)(puVar9 + -1) >> 4) {
        p_vfo_freq_display_state->field_0x2 = p_vfo_freq_display_state->field_0x2 & 0xf;
      }
      puVar9 = PTR_DAT_0302e3c8;
      flash_block_read(block_id,(uint)(ushort)(sVar1 + 1),PTR_DAT_0302e3c8,0xb);
      *(undefined1 *)((int)puVar9 + 0xb) = 0;
      *(undefined1 *)(puVar9 + 3) = 0;
      if ((4000 < *(ushort *)((int)puVar9 + -0x2e)) &&
         ((p_vfo_freq_display_state->field_0x4 & 0xf) == 2)) {
        p_vfo_freq_display_state->field_0x4 = 0;
      }
      asStack_44[0] = 0;
      bVar14 = p_vfo_freq_display_state->field_0x4 & 0xf;
      if (bVar14 == 1) {
        asStack_44[0] = *(short *)&p_vfo_freq_display_state->field_0x16_0;
      }
      else if (bVar14 == 2) {
        asStack_44[0] = *(short *)&p_vfo_freq_display_state->field_0x8_0;
      }
      if ((p_vfo_freq_display_state->field_0x4 & 0xf) != 0) {
        p_vfo_freq_display_state->field_0x5c = p_vfo_freq_display_state->field_0x5c + 1;
      }
      pvVar6 = p_vfo_freq_display_state;
      *(short *)&p_vfo_freq_display_state->field_0x8_0 = asStack_44[0];
      bVar14 = pvVar6->field_0x4 & 0xf0;
      if (bVar14 == 0x10) {
        asStack_44[0] = *(short *)&p_vfo_freq_display_state->field_0x16_0;
      }
      else if (bVar14 == 0x20) {
        asStack_44[0] = *(short *)&p_vfo_freq_display_state->field_0xa_0;
      }
      if (p_vfo_freq_display_state->field_0x4 >> 4 != 0) {
        p_vfo_freq_display_state->field_0x5c = p_vfo_freq_display_state->field_0x5c + 1;
      }
      pvVar6 = p_vfo_freq_display_state;
      *(short *)&p_vfo_freq_display_state->field_0xa_0 = asStack_44[0];
      iVar11 = DAT_0302e560;
      iVar10 = DAT_0302e55c;
      pvVar7 = p_vfo_freq_display_state;
      if ((pvVar6->field_0x2 & 0xf0) == 0x20) {
        channel_offset_from_num
                  (*(undefined2 *)&p_vfo_freq_display_state->field_0x6,auStack_66,&sStack_68);
        flash_field_read_cached(auStack_66[0],sStack_68,&pvVar7->field_0x42,0xb);
        channel_num_to_block_offset(*(undefined2 *)&pvVar7->field_0x6,auStack_66,&sStack_68);
        flash_field_read_cached(auStack_66[0],sStack_68 + 8,&bStack_23,1);
        pvVar7->flags_0x10 =
             pvVar7->flags_0x10 & 0xe1 | (bStack_23 >> 1 & 3) << 1 | (bStack_23 >> 6) << 3;
        uVar5 = pvVar7->field_0x7;
        pvVar7->field_0x58 = pvVar7->field_0x6;
        pvVar7->field_0x59 = uVar5;
      }
      else {
        memcpy_bytes_iram(DAT_0302e55c,DAT_0302e560,0x11);
        *(byte *)(iVar10 + -0x32) =
             *(byte *)(iVar10 + -0x32) & 0xe1 | (*(byte *)(iVar11 + -0x18) >> 1 & 3) << 1 |
             (*(byte *)(iVar11 + -0x18) >> 4 & 3) << 3;
        uVar12 = channel_list_index_resolve
                           (p_dm32_settings_block04[0x29],p_dm32_settings_block04[0x26]);
        *(undefined2 *)(iVar10 + 0x16) = uVar12;
      }
      p_vfo_freq_display_state->field_0x4c = 0;
      flash_block_read(block_id,(uint)(ushort)(sVar1 + 0x17),&uStack_22,2);
      if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
        uStack_22 = uStack_22 & 0xfffe;
      }
      else {
        uStack_22 = uStack_22 | 1;
      }
      bVar14 = p_vfo_freq_display_state->field_0x1;
      if (bVar14 == 0) {
        uVar18 = 0;
        uVar17 = 0;
      }
      else {
        sVar1 = *(short *)&p_vfo_freq_display_state->field_0x16_0;
        sVar2 = *(short *)&p_vfo_freq_display_state->field_0x8_0;
        sVar4 = *(short *)&p_vfo_freq_display_state->field_0xa_0;
        uVar15 = 0;
        uVar18 = 0;
        uVar17 = 0;
        do {
          if (((int)(uint)uStack_22 >> (uVar15 & 0x3f) & 1U) == 0) {
            sVar3 = *(short *)(&p_vfo_freq_display_state->field_0x16_0 + uVar15 * 2);
            if (sVar1 == sVar3) {
              if (uVar15 == 0) goto LAB_0302e4e4;
            }
            else if (uVar15 == 0) {
LAB_0302e4e4:
              if ((sVar2 != sVar3) && (sVar4 != sVar3)) {
                asStack_64[uVar18] = sVar1;
                uVar18 = uVar18 + 1 & 0xff;
              }
            }
            else if ((sVar2 != sVar3) && (sVar4 != sVar3)) {
              asStack_64[uVar18] = sVar3;
              uVar18 = uVar18 + 1 & 0xff;
            }
          }
          else {
            sVar3 = *(short *)(&p_vfo_freq_display_state->field_0x16_0 + uVar15 * 2);
            if (sVar3 == sVar1) {
              if (uVar15 == 0) goto LAB_0302e4a8;
            }
            else if (uVar15 == 0) {
LAB_0302e4a8:
              if ((sVar3 != sVar2) && (sVar3 != sVar4)) {
                asStack_44[uVar17] = sVar1;
                uVar17 = uVar17 + 1 & 0xff;
              }
            }
            else if ((sVar3 != sVar2) && (sVar3 != sVar4)) {
              asStack_44[uVar17] = sVar3;
              uVar17 = uVar17 + 1 & 0xff;
            }
          }
          uVar15 = uVar15 + 1 & 0xff;
        } while (uVar15 < bVar14);
        bStack_23 = 0;
        if (uVar18 != 0) {
          psVar16 = asStack_64;
          psVar13 = PTR_DAT_0302e570;
          do {
            *psVar13 = *psVar16;
            psVar16 = psVar16 + 1;
            psVar13 = psVar13 + 1;
          } while (psVar16 != asStack_64 + (uVar18 - 1 & 0xff) + 1);
        }
        bStack_23 = 0;
        if (uVar17 != 0) {
          psVar16 = asStack_44;
          psVar13 = (short *)((uVar18 + 10) * 2 + DAT_0302e574);
          do {
            *psVar13 = *psVar16;
            psVar16 = psVar16 + 1;
            psVar13 = psVar13 + 1;
          } while (psVar16 != asStack_44 + (uVar17 - 1 & 0xff) + 1);
        }
      }
      pvVar6 = p_vfo_freq_display_state;
      bVar14 = (char)uVar18 + (char)uVar17;
      p_vfo_freq_display_state->field_0x1 = bVar14;
      pvVar6->field_0x5c = bVar14 + pvVar6->field_0x5c;
    }
  }
  return;
}


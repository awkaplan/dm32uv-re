/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_rx_burst_dispatch @ 0302499c (file base 0x03000000; code starts at 0x03001000)
 * Size: 1342 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_rx_burst_dispatch(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  dword dVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte bVar19;
  
  uVar11 = (uint)(*(byte *)(param_1 + 3) >> 5) | (uint)*(byte *)(param_1 + 2) << 3;
  bVar15 = *(byte *)(param_1 + 3) & 0x1f;
  bVar1 = *(byte *)(param_1 + 5);
  bVar2 = *(byte *)(param_1 + 6);
  bVar3 = *(byte *)(param_1 + 9);
  bVar19 = (bVar2 & 1) * '\x02' | bVar3 & 1;
  uVar12 = (uint)*(byte *)(param_1 + 4) << 0xc | (uint)(bVar2 >> 3) | (bVar1 & 0xfe) << 4;
  uVar13 = bVar2 >> 1 & 3;
  uVar17 = uVar12 | uVar13 << 0x14;
  uVar14 = (*(byte *)(param_1 + 8) & 0xfe) << 4 |
           (uint)(bVar3 >> 3) | (uint)*(byte *)(param_1 + 7) << 0xc;
  uVar16 = bVar3 >> 1 & 3;
  uVar18 = uVar14 | uVar16 << 0x14;
  if (*(char *)PTR_DAT_03024a84 == '\x01') {
    if ((bVar19 < 3) &&
       (*(char *)((uint)*(byte *)p_dmr_call_config_state + p_dmr_config_unpack_state + 2) != '\0'))
    {
      *(undefined1 *)((uint)*(byte *)p_dmr_call_config_state + p_dmr_config_unpack_state + 2) = 0;
    }
    if ((*(char *)(PTR_DAT_03024a84 + 1) == '\x05') &&
       (*(char *)((int)PTR_DAT_03024a84 + 3) != '\0')) {
      if (bVar19 < 2) {
        return;
      }
      if (uVar17 < (uint)PTR_DAT_03024a84[3]) {
        return;
      }
      if (uVar18 < (uint)PTR_DAT_03024a84[3]) {
        return;
      }
      osmbox_post_candidate2_on_check_0300c778();
    }
    uVar13 = PTR_DAT_03024a84[3];
    if (uVar13 < uVar17) {
      if (1 < bVar19) {
        dVar6 = SystemControl_Type_11000000.LAYER2_CONTROL;
        SystemControl_Type_11000000.LAYER2_CONTROL = dVar6 & 0xfffffffd;
        osmbox_post_candidate2_on_check_0300c780();
        protocol_state_write_and_apply_sequence(uVar17,uVar11,bVar15);
      }
    }
    else if (uVar17 < uVar13) {
      if (*(ushort *)((int)PTR_DAT_03024c00 + 0x12) >> 4 < uVar16) {
        dVar6 = SystemControl_Type_11000000.LAYER2_CONTROL;
        SystemControl_Type_11000000.LAYER2_CONTROL = dVar6 & 0xfffffffd;
        osmbox_post_candidate2_on_check_0300c780();
        dmr_burst_assemble_and_dispatch(uVar16,uVar14);
      }
      else {
        dmr_burst_freq_field_pack_and_timer_arm(uVar13);
      }
    }
    else {
      uVar5 = *(ushort *)(PTR_DAT_03024c00 + 2);
      iVar10 = circular_gap_classify_u16(uVar11 % 0x21c,(uVar5 & 0x7ff) % 0x21c,10);
      puVar7 = PTR_DAT_03024c00;
      if (iVar10 == 0) {
        iVar10 = circular_gap_classify_u16(uVar11,uVar5 & 0x7ff,10);
        if (iVar10 != 0) {
          dmr_burst_freq_field_pack_and_timer_arm(uVar13);
        }
      }
      else if (1 < bVar19) {
        do {
          uVar13 = lcg_rand_next();
          uVar13 = uVar13 & 0x800fffff;
          if ((int)uVar13 < 0) {
            uVar13 = (uVar13 - 1 | 0xfff00000) + 1;
          }
        } while (uVar13 == (puVar7[4] & 0xfffff));
        uVar13 = uVar13 & 0xfffff;
        PTR_DAT_03024c00[4] = PTR_DAT_03024c00[4] & 0xfff00000 | uVar13;
        if (uVar13 < uVar12) {
          osmbox_post_candidate2_on_check_0300c780(uVar12,0,uVar13,0);
          protocol_state_write_and_apply_sequence(uVar17,uVar11,bVar15);
        }
      }
    }
  }
  else {
    if ((bVar19 < 3) &&
       (*(char *)((uint)*(byte *)p_dmr_call_config_state + p_dmr_config_unpack_state + 2) != '\0'))
    {
      *(undefined1 *)((uint)*(byte *)p_dmr_call_config_state + p_dmr_config_unpack_state + 2) = 0;
    }
    if ((*(char *)PTR_DAT_03024c00 == '\x03') && (*(char *)((int)PTR_DAT_03024c00 + 3) != '\0')) {
      if ((uVar17 == 0) || (uVar13 < *(ushort *)((int)PTR_DAT_03024c00 + 0x12) >> 4)) {
        dmr_rx_control_state_update_from_status();
        return;
      }
      osmbox_post_candidate2_on_check_0300c778();
    }
    else if ((*(char *)PTR_DAT_03024c00 == '\x02') && (*(char *)((int)PTR_DAT_03024c00 + 3) != '\0')
            ) {
      cVar4 = *(char *)(PTR_DAT_03024c00 + 1);
      if (cVar4 == '\x02') {
        if ((uVar17 < (uint)PTR_DAT_03024c00[3]) && (uVar18 <= (uint)PTR_DAT_03024c00[3])) {
          return;
        }
        osmbox_post_candidate2_on_check_0300c778();
      }
      else if (cVar4 == '\x04') {
        uVar12 = PTR_DAT_03024d9c[3];
        if ((uVar17 <= uVar12) && (uVar18 <= uVar12)) {
          if (uVar17 != uVar12) {
            return;
          }
          if (bVar19 != 3) {
            return;
          }
          iVar10 = circular_gap_classify_u16(uVar11,*(ushort *)(PTR_DAT_03024d9c + 2) & 0x7ff,1);
          if (iVar10 != 0) {
            return;
          }
          osmbox_post_candidate2_on_check_0300c778();
          return;
        }
        osmbox_post_candidate2_on_check_0300c778();
      }
      else if (cVar4 == '\x01') {
        if (bVar19 < 2) {
          return;
        }
        if (uVar17 < (uint)PTR_DAT_03024d9c[3]) {
          return;
        }
        if ((uVar17 == PTR_DAT_03024d9c[3]) &&
           (iVar10 = circular_gap_classify_u16(uVar11,*(ushort *)(PTR_DAT_03024d9c + 2) & 0x7ff,1),
           iVar10 != 1)) {
          return;
        }
        osmbox_post_candidate2_on_check_0300c778();
      }
      else if (cVar4 == '\x05') {
        if (bVar19 < 2) {
          return;
        }
        if (uVar17 < (uint)PTR_DAT_03024d9c[3]) {
          return;
        }
        if (uVar18 < (uint)PTR_DAT_03024d9c[3]) {
          return;
        }
        osmbox_post_candidate2_on_check_0300c778();
      }
    }
    puVar7 = PTR_DAT_03024d9c;
    if ((uVar17 == PTR_DAT_03024d9c[4]) && ((bVar1 & 1) != 0)) {
      if ((bVar1 & 1) == 1) {
        *(undefined1 *)PTR_DAT_03024d9c = 1;
        control_reg_conditional_set_with_status_xor();
        puVar7[3] = uVar17;
        *(ushort *)(puVar7 + 2) = *(ushort *)(puVar7 + 2) & 0xf800 | (ushort)uVar11;
        *(byte *)((int)puVar7 + 9) = *(byte *)((int)puVar7 + 9) & 7;
        osmbox_post_candidate2_on_check_0300c780();
        protocol_timer_ensure_valid_or_recreate_wrapper(500);
        dmr_rx_burst_timer_setup_and_start();
      }
      else {
        do {
          uVar11 = lcg_rand_next();
          uVar11 = uVar11 & 0x800fffff;
          if ((int)uVar11 < 0) {
            uVar11 = (uVar11 - 1 | 0xfff00000) + 1;
          }
        } while (uVar11 == (puVar7[4] & 0xfffff));
        PTR_DAT_03024d9c[4] = PTR_DAT_03024d9c[4] & 0xfff00000 | uVar11 & 0xfffff;
      }
    }
    else {
      if (uVar14 == (PTR_DAT_03024d9c[4] & 0xfffff)) {
        do {
          uVar12 = lcg_rand_next();
          uVar12 = uVar12 & 0x800fffff;
          if ((int)uVar12 < 0) {
            uVar12 = (uVar12 - 1 | 0xfff00000) + 1;
          }
        } while (uVar12 == (puVar7[4] & 0xfffff));
        PTR_DAT_03024d9c[4] = PTR_DAT_03024d9c[4] & 0xfff00000 | uVar12 & 0xfffff;
      }
      uVar12 = PTR_DAT_03024d9c[3];
      if (uVar12 == 0) {
        dmr_rx_control_state_update_from_status();
        puVar8 = _LAB_03024ef8;
        if (uVar17 == 0) {
          if ((bVar3 >> 1 & 3) == 0) {
            uVar11 = (uint)(*(ushort *)(_LAB_03024ef8 + 0x12) >> 4);
            if (uVar11 <= uVar16) {
              return;
            }
          }
          else {
            uVar11 = (uint)(*(ushort *)((int)PTR_DAT_03024d9c + 0x12) >> 4);
            if (uVar11 <= uVar16) {
              dmr_burst_assemble_and_dispatch(uVar16,uVar14);
              return;
            }
          }
          _LAB_03024ef8[4] = 1;
          puVar8[6] = 3;
          puVar9 = _LAB_03024efc;
          _LAB_03024efc[3] = _LAB_03024efc[3] & 7;
          *(ushort *)(puVar9 + 2) = *(ushort *)(puVar9 + 2) & 0xf800;
          puVar9[4] = 0;
          *(undefined4 *)(puVar9 + 8) = 0;
          puVar9[0xc] = (char)uVar11;
          *(uint *)(puVar9 + 0x10) = *(uint *)(puVar8 + 0x10) & 0xfffff;
          *puVar9 = 0;
          puVar9[1] = 0;
          scan_timer_apply_random_jitter(puVar8[2]);
          guarded_timer_config_apply_wrapper_b(120000);
        }
        else if (1 < bVar19) {
          protocol_state_write_and_apply_sequence(uVar17,uVar11,bVar15);
        }
      }
      else if (bVar19 == 1) {
        if (uVar17 < uVar12) {
          dmr_burst_freq_field_pack_and_timer_arm(uVar12);
        }
      }
      else if (uVar17 < uVar12) {
        dmr_burst_freq_field_pack_and_timer_arm(uVar12);
      }
      else if (uVar12 < uVar17) {
        if (bVar19 == 3) {
          dmr_rx_control_state_update_from_status();
          protocol_frame_field_pack_and_send_0x12(uVar17,uVar11,bVar15);
        }
        else if (bVar19 == 2) {
          protocol_state_write_and_apply_sequence(uVar17,uVar11,bVar15);
        }
      }
      else {
        iVar10 = circular_gap_classify_u16(uVar11,*(ushort *)(_LAB_03024ef8 + 8) & 0x7ff,2);
        if (iVar10 == 2) {
          dmr_burst_freq_field_pack_and_timer_arm(uVar12);
        }
        else if (iVar10 == 1) {
          dmr_rx_control_state_update_from_status();
          puVar8 = _LAB_03024ef8;
          if (bVar19 == 3) {
            protocol_frame_field_pack_and_send_0x12(uVar17,uVar11,bVar15);
          }
          else if (bVar19 == 2) {
            *_LAB_03024ef8 = 2;
            *(ushort *)(puVar8 + 8) = *(ushort *)(puVar8 + 8) & 0xf800 | (ushort)uVar11;
          }
        }
        else if ((byte)_LAB_03024ef8[9] >> 3 < bVar15) {
          *_LAB_03024ef8 = 2;
        }
        else {
          if (bVar15 < (byte)_LAB_03024ef8[9] >> 3) {
            _LAB_03024ef8[9] = _LAB_03024ef8[9] & 7 | (bVar15 + 1) * '\b';
          }
          *_LAB_03024ef8 = 2;
          dmr_rx_control_state_update_from_status();
          if (bVar19 == 3) {
            protocol_frame_field_pack_and_send_0x12(uVar17,uVar11,bVar15);
          }
        }
      }
    }
  }
  return;
}


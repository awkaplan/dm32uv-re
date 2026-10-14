/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_response_process_and_signal @ 03028338 (file base 0x03000000; code starts at 0x03001000)
 * Size: 864 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: dmr-protocol
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dmr_call_setup_response_process_and_signal(void)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  dword dVar4;
  undefined1 *puVar5;
  dmr_call_config_state *pdVar6;
  undefined4 *puVar7;
  call_setup_sm_state_aux *pcVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  byte bVar12;
  byte bVar13;
  int iVar14;
  uint uVar15;
  undefined4 uStack_1c;
  undefined1 auStack_18 [4];
  
  pdVar6 = p_dmr_call_config_state;
  dVar4 = SystemControl_Type_11000000.RX_TYPE_INFO;
  uVar15 = dVar4 >> 2 & 3;
  if (*(char *)PTR_DAT_0302840c != '\0') {
    return;
  }
  if ((dVar4 >> 0x19 & 1) != 0) {
    return;
  }
  if ((PTR_DAT_030283f4[6] != p_call_setup_sm_state_aux->field_0x5) &&
     ((p_call_setup_sm_state->flags_0x18 & 8) == 0)) {
    return;
  }
  p_dmr_call_config_state->field_0x3 = 1;
  iVar9 = DAT_03028410;
  copy_bytes_from_offset_table(0,DAT_03028410 + (uint)*(byte *)pdVar6 * 0xc,0xc);
  uVar11 = (uint)*(byte *)pdVar6;
  iVar14 = iVar9 + -0x28 + uVar11 * 0xc;
  cVar1 = *(char *)(iVar14 + 0x29);
  bVar12 = *(byte *)(iVar14 + 0x28);
  bVar13 = bVar12 & 0x3f;
  if (cVar1 != '\0') {
    if (cVar1 != '\x10') {
      return;
    }
    *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
    if ((bVar12 & 4) != 0) {
      iVar9 = call_setup_target_id_decode_and_check(1,iVar9 + uVar11 * 0xc,auStack_18,&uStack_1c);
      puVar5 = PTR_DAT_030285dc;
      pdVar6 = p_dmr_call_config_state;
      puVar7 = PTR_DAT_030285c8;
      if (iVar9 == 0) {
        *(undefined1 *)((int)PTR_DAT_030285c8 + 10) = 0;
        bVar12 = *(byte *)p_dmr_call_config_state;
        bVar10 = *(byte *)((int)puVar7 + (uint)bVar12 * 0xc + 0x2a);
        *(byte *)((int)puVar7 + 0xb) = bVar10;
        bVar10 = bVar10 & 0x30;
        if ((bVar10 == 0x20) || (bVar10 == 0x30)) {
          *(undefined1 *)((int)PTR_DAT_030285c8 + 9) = 1;
          *(undefined4 *)((uint)bVar12 * 0xc + DAT_030285d0) = uStack_1c;
        }
        else {
          *(undefined1 *)((int)PTR_DAT_030285c8 + 9) = 0;
        }
        puVar7 = PTR_DAT_030285c8;
        bVar12 = *(byte *)p_dmr_call_config_state;
        *(undefined1 *)((int)PTR_DAT_030285c8 + bVar12 + 0xc) = 1;
        *(undefined1 *)((int)puVar7 + bVar12 + 0x12) = 0;
        *(undefined1 *)((int)puVar7 + bVar12 + 0x10) = 0;
        if (bVar13 == 4) {
          *(undefined1 *)(PTR_DAT_030285c8 + 2) = 1;
        }
        else if (bVar13 == 7) {
          *(undefined1 *)(PTR_DAT_030285c8 + 2) = 0;
        }
        puVar7 = PTR_DAT_030285c8;
        uVar15 = (uint)*(byte *)p_dmr_call_config_state;
        PTR_DAT_030285c8[uVar15 + 6] =
             (uint)*(byte *)((int)PTR_DAT_030285c8 + uVar15 * 0xc + 0x2d) +
             (uint)*(byte *)((int)PTR_DAT_030285c8 + uVar15 * 0xc + 0x2b) * 0x10000 +
             (uint)*(byte *)(PTR_DAT_030285c8 + uVar15 * 3 + 0xb) * 0x100;
        puVar7[uVar15 + 8] =
             (uint)*(byte *)((int)puVar7 + uVar15 * 0xc + 0x2f) * 0x100 +
             (uint)*(byte *)(puVar7 + uVar15 * 3 + 0xc);
        OSFlagPost_wrapper_set_fixed_grp(2);
      }
      else if (p_call_setup_sm_state_aux->field_0x15 == 0) {
        cVar1 = *(char *)((uint)*(byte *)p_dmr_call_config_state * 0xc + DAT_030285d8);
        PTR_DAT_030285dc[0x73] = cVar1;
        pcVar8 = p_call_setup_sm_state_aux;
        bVar12 = cVar1 + 1U & 1;
        p_call_setup_sm_state_aux->field_0x3 = bVar12;
        pcVar8->field_0x4 = bVar12;
        pdVar6->field_0x2 = bVar12;
        pdVar6->field_0x4 = bVar12;
        iVar9 = call_index_get_1based();
        iVar14 = (int)((byte)puVar5[0x73] + 1) >> 1;
        if (iVar9 != iVar14) {
          call_abort_by_index(iVar14);
        }
      }
      puVar7 = PTR_DAT_030285c8;
      uVar15 = (uint)*(byte *)p_dmr_call_config_state;
      uVar2 = *(undefined1 *)((int)PTR_DAT_030285c8 + uVar15 * 0xc + 0x2a);
      *(undefined1 *)((int)PTR_DAT_030285c8 + uVar15 + 0x14) = uVar2;
      *(undefined1 *)((int)puVar7 + uVar15 + 0x16) = uVar2;
      return;
    }
    iVar9 = call_setup_target_id_decode_and_check(1,iVar9 + uVar11 * 0xc,auStack_18,&uStack_1c);
    puVar7 = PTR_DAT_0302877c;
    if (iVar9 == 0) {
      *(undefined1 *)((int)PTR_DAT_0302877c + 10) = 0;
      bVar10 = *(byte *)p_dmr_call_config_state;
      uVar11 = (uint)bVar10;
      bVar3 = *(byte *)((int)puVar7 + uVar11 * 0xc + 0x2a);
      *(byte *)((int)puVar7 + 0xb) = bVar3;
      if ((bVar3 & 0x30) == 0x20) {
        *(undefined1 *)((int)puVar7 + 9) = 1;
      }
      else {
        *(undefined1 *)((int)PTR_DAT_0302877c + 9) = 0;
      }
      pdVar6 = p_dmr_call_config_state;
      if (uVar15 == 0) {
        p_dmr_call_config_state->field_0x2 = bVar10;
        pdVar6->field_0x4 = bVar10;
      }
      puVar7 = PTR_DAT_0302877c;
      *(undefined1 *)((int)PTR_DAT_0302877c + uVar11 + 0xc) = 1;
      *(undefined1 *)((int)puVar7 + uVar11 + 0x12) = 0;
      *(undefined1 *)((int)puVar7 + uVar11 + 0x10) = 0;
      if ((bVar12 & 0x3f) == 0) {
        *(undefined1 *)(PTR_DAT_0302877c + 2) = 1;
      }
      else if (bVar13 == 3) {
        *(undefined1 *)(PTR_DAT_0302877c + 2) = 0;
      }
      puVar7 = PTR_DAT_0302877c;
      uVar15 = (uint)*(byte *)p_dmr_call_config_state;
      PTR_DAT_0302877c[uVar15 + 6] =
           (uint)*(byte *)((int)PTR_DAT_0302877c + uVar15 * 0xc + 0x2d) +
           (uint)*(byte *)((int)PTR_DAT_0302877c + uVar15 * 0xc + 0x2b) * 0x10000 +
           (uint)*(byte *)(PTR_DAT_0302877c + uVar15 * 3 + 0xb) * 0x100;
      puVar7[uVar15 + 8] =
           (uint)*(byte *)((int)puVar7 + uVar15 * 0xc + 0x2f) * 0x100 +
           (uint)*(byte *)((int)puVar7 + uVar15 * 0xc + 0x2e) * 0x10000 +
           (uint)*(byte *)(puVar7 + uVar15 * 3 + 0xc);
      OSFlagPost_wrapper_set_fixed_grp(2);
      return;
    }
    bVar12 = *(byte *)p_dmr_call_config_state;
    bVar13 = *(byte *)((int)PTR_DAT_0302877c + (uint)bVar12 * 0xc + 0x2a);
    *(byte *)((int)PTR_DAT_0302877c + 0xb) = bVar13;
    if ((bVar13 & 0x30) == 0x20) {
      *(undefined1 *)((int)PTR_DAT_0302877c + 9) = 1;
      pdVar6 = p_dmr_call_config_state;
      if (uVar15 != 0) {
        return;
      }
      p_dmr_call_config_state->field_0x2 = bVar12;
      pdVar6->field_0x4 = bVar12;
      return;
    }
    *(undefined1 *)((int)PTR_DAT_0302877c + 9) = 0;
    return;
  }
  iVar9 = call_setup_target_id_decode_and_check(1,iVar9 + uVar11 * 0xc,auStack_18,&uStack_1c);
  if (iVar9 != 0) {
    return;
  }
  *(undefined2 *)&pdVar6->field_0x10 = 0;
  bVar10 = *(byte *)pdVar6;
  uVar11 = (uint)bVar10;
  PTR_DAT_030283f4[0xb] = PTR_DAT_030283f4[uVar11 * 0xc + 0x2a];
  if (uVar15 == 0) {
    pdVar6->field_0x2 = bVar10;
    pdVar6->field_0x4 = bVar10;
  }
  puVar5 = PTR_DAT_030283f4;
  PTR_DAT_030283f4[9] = 0;
  puVar5[uVar11 + 0xc] = 1;
  puVar5[uVar11 + 0x12] = 0;
  puVar5[uVar11 + 0x10] = 0;
  if ((bVar12 & 0x3f) == 0) {
    PTR_DAT_030283f4[8] = 1;
  }
  else {
    if (bVar13 == 3) {
      *(undefined1 *)(PTR_DAT_030285c8 + 2) = 0;
    }
    else if (*(char *)(PTR_DAT_030285c8 + 2) != '\0') goto LAB_03028440;
    if ((*(byte *)((int)PTR_DAT_030285c8 + 0xb) >> 4 & 2) != 0) {
      *(undefined1 *)((int)PTR_DAT_030285c8 + 10) = 1;
      goto LAB_03028446;
    }
  }
LAB_03028440:
  *(undefined1 *)((int)PTR_DAT_030285c8 + 10) = 0;
LAB_03028446:
  puVar7 = PTR_DAT_030285c8;
  uVar15 = (uint)*(byte *)p_dmr_call_config_state;
  PTR_DAT_030285c8[uVar15 + 6] =
       (uint)*(byte *)((int)PTR_DAT_030285c8 + uVar15 * 0xc + 0x2d) +
       (uint)*(byte *)((int)PTR_DAT_030285c8 + uVar15 * 0xc + 0x2b) * 0x10000 +
       (uint)*(byte *)(PTR_DAT_030285c8 + uVar15 * 3 + 0xb) * 0x100;
  puVar7[uVar15 + 8] =
       (uint)*(byte *)((int)puVar7 + uVar15 * 0xc + 0x2f) * 0x100 +
       (uint)*(byte *)((int)puVar7 + uVar15 * 0xc + 0x2e) * 0x10000 +
       (uint)*(byte *)(puVar7 + uVar15 * 3 + 0xc);
  OSFlagPost_wrapper_set_fixed_grp(2);
  return;
}


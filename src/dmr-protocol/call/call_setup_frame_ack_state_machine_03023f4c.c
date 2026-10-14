/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_frame_ack_state_machine @ 03023f4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 466 bytes
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

void call_setup_frame_ack_state_machine(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  call_setup_sm_state_aux *pcVar3;
  dmr_call_config_state *pdVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  byte bStack_11;
  
  puVar1 = PTR_DAT_030240dc;
  PTR_DAT_030240dc[0x1e] = 0;
  puVar2 = PTR_DAT_030240dc;
  if (*(char *)((int)puVar1 + 0x72) == '\0') {
    *(undefined1 *)((int)PTR_DAT_030240dc + 0x72) = 1;
    uVar7 = *(byte *)(param_1 + 2) & 0x1f;
    *(char *)((int)puVar2 + 0x73) = (char)uVar7;
    pcVar3 = p_call_setup_sm_state_aux;
    iVar8 = uVar7 + 1;
    bVar6 = (byte)iVar8 & 1;
    p_call_setup_sm_state_aux->field_0x3 = bVar6;
    pcVar3->field_0x4 = bVar6;
    iVar5 = call_index_get_1based();
    pdVar4 = p_dmr_call_config_state;
    iVar8 = iVar8 >> 1;
    if (iVar5 == iVar8) {
      *(byte *)p_dmr_call_config_state = *(byte *)(param_1 + 2) >> 5 & 1;
      pdVar4->field_0x9 = 1;
      pdVar4->field_0x7 = 1;
      pdVar4->field_0x2 = bVar6;
      pdVar4->field_0x4 = bVar6;
      OSFlagPost_wrapper_set_fixed_grp(0x8000000);
    }
    else {
      call_abort_by_index(iVar8);
    }
    p_dmr_call_config_state->field_0x3 = 0;
  }
  else if (p_dmr_call_config_state->field_0x9 == 0) {
    if (p_call_setup_sm_state_aux->field_0x15 == 0) {
      iVar5 = bitmask_table_index_lookup
                        (param_1,*(undefined1 *)((int)PTR_DAT_030240dc + 0x73),&bStack_11);
      pdVar4 = p_dmr_call_config_state;
      if (iVar5 == 0) {
        if ((uint)*(byte *)((int)PTR_DAT_030240dc + 0x73) == (uint)bStack_11) {
          *(byte *)p_dmr_call_config_state = *(byte *)(param_1 + 2) >> 5 & 1;
          pdVar4->field_0x9 = 1;
          pdVar4->field_0x7 = 1;
          pcVar3 = p_call_setup_sm_state_aux;
          pdVar4->field_0x2 = p_call_setup_sm_state_aux->field_0x4;
          pdVar4->field_0x4 = pcVar3->field_0x3;
          OSFlagPost_wrapper_set_fixed_grp(0x8000000);
        }
        else {
          *(byte *)((int)PTR_DAT_030240dc + 0x73) = bStack_11;
          pcVar3 = p_call_setup_sm_state_aux;
          iVar8 = bStack_11 + 1;
          bVar6 = (byte)iVar8 & 1;
          p_call_setup_sm_state_aux->field_0x3 = bVar6;
          pcVar3->field_0x4 = bVar6;
          pdVar4 = p_dmr_call_config_state;
          p_dmr_call_config_state->field_0x2 = bVar6;
          pdVar4->field_0x4 = bVar6;
          iVar5 = call_index_get_1based();
          iVar8 = iVar8 >> 1;
          if (iVar5 != iVar8) {
            call_abort_by_index(iVar8);
          }
        }
      }
      else {
        uVar7 = *(byte *)(param_1 + 2) & 0x1f;
        *(char *)((int)PTR_DAT_030240dc + 0x73) = (char)uVar7;
        pcVar3 = p_call_setup_sm_state_aux;
        iVar8 = uVar7 + 1;
        bVar6 = (byte)iVar8 & 1;
        p_call_setup_sm_state_aux->field_0x3 = bVar6;
        pcVar3->field_0x4 = bVar6;
        iVar5 = call_index_get_1based();
        pdVar4 = p_dmr_call_config_state;
        iVar8 = iVar8 >> 1;
        if (iVar5 == iVar8) {
          *(byte *)p_dmr_call_config_state = *(byte *)(param_1 + 2) >> 5 & 1;
          pdVar4->field_0x9 = 1;
          pdVar4->field_0x7 = 1;
          pdVar4->field_0x2 = bVar6;
          pdVar4->field_0x4 = bVar6;
          OSFlagPost_wrapper_set_fixed_grp(0x8000000);
        }
        else {
          call_abort_by_index(iVar8);
        }
        p_dmr_call_config_state->field_0x3 = 0;
      }
    }
  }
  else if (p_call_setup_sm_state_aux->field_0x15 == 0) {
    iVar5 = bitmask_table_index_lookup
                      (param_1,*(undefined1 *)((int)PTR_DAT_030240dc + 0x73),&bStack_11);
    if (iVar5 == 0) {
      if ((uint)*(byte *)((int)PTR_DAT_030240dc + 0x73) != (uint)bStack_11) {
        *(byte *)((int)PTR_DAT_030240dc + 0x73) = bStack_11;
        pcVar3 = p_call_setup_sm_state_aux;
        iVar8 = bStack_11 + 1;
        bVar6 = (byte)iVar8 & 1;
        p_call_setup_sm_state_aux->field_0x3 = bVar6;
        pcVar3->field_0x4 = bVar6;
        pdVar4 = p_dmr_call_config_state;
        p_dmr_call_config_state->field_0x2 = bVar6;
        pdVar4->field_0x4 = bVar6;
        iVar5 = call_index_get_1based();
        iVar8 = iVar8 >> 1;
        if (iVar5 != iVar8) {
          call_abort_by_index(iVar8);
        }
      }
    }
    else {
      uVar7 = *(byte *)(param_1 + 2) & 0x1f;
      if (*(byte *)(_DAT_0302412c + 0x73) != uVar7) {
        *(char *)(_DAT_0302412c + 0x73) = (char)uVar7;
        pcVar3 = p_call_setup_sm_state_aux;
        bVar6 = (byte)(uVar7 + 1) & 1;
        p_call_setup_sm_state_aux->field_0x3 = bVar6;
        pcVar3->field_0x4 = bVar6;
        pdVar4 = p_dmr_call_config_state;
        p_dmr_call_config_state->field_0x2 = bVar6;
        pdVar4->field_0x4 = bVar6;
        iVar5 = call_index_get_1based();
        iVar8 = (int)(uVar7 + 1) >> 1;
        if (iVar5 != iVar8) {
          call_abort_by_index(iVar8);
        }
      }
      p_dmr_call_config_state->field_0x3 = 0;
    }
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_incoming_call_setup_conflict_resolve @ 0302741c (file base 0x03000000; code starts at 0x03001000)
 * Size: 478 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_incoming_call_setup_conflict_resolve(void)

{
  dmr_call_config_state *pdVar1;
  call_setup_sm_state_aux *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  byte bStack_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  
  if (((uint)*PTR_DAT_030274e8 >> 0x1e & 1) == 0) {
    *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
    copy_bytes_from_offset_table(0x2b,&bStack_10,5);
    if (bStack_10 >> 4 == 0xf) {
      PTR_DAT_030274d8[0x1e] = 0;
      puVar3 = PTR_DAT_03027668;
      if (((bStack_f >> 2 & 1) != 0) && ((byte)((bStack_d >> 4) + bStack_e * '\x10') == -1)) {
        iVar10 = (bStack_f & 1) * 0x10 + (uint)(bStack_e >> 4);
        iVar5 = call_index_get_1based();
        uVar7 = iVar10 + 1;
        iVar9 = (int)uVar7 >> 1;
        cVar6 = (char)iVar10;
        if (iVar5 != iVar9) {
          call_abort_by_index(iVar9);
          if (*(char *)((uint)p_dmr_call_config_state->field_0x2 + _DAT_03027664) == '\x01') {
            *(undefined1 *)((uint)p_dmr_call_config_state->field_0x2 + _DAT_03027664) = 0;
            OSFlagPost_wrapper_set_fixed_grp(4);
          }
          *(undefined1 *)((uint)p_dmr_call_config_state->field_0x2 + _DAT_03027664 + 2) = 0;
          modem_stop();
          PTR_DAT_03027668[0x73] = cVar6;
          pcVar2 = p_call_setup_sm_state_aux;
          bVar8 = cVar6 + 1U & 1;
          p_call_setup_sm_state_aux->field_0x3 = bVar8;
          pcVar2->field_0x4 = bVar8;
          return;
        }
        if ((uint)p_call_setup_sm_state_aux->field_0x4 == (uVar7 & 1)) {
          return;
        }
        if (*(char *)((uint)p_dmr_call_config_state->field_0x2 + _DAT_030274ec) == '\x01') {
          *(undefined1 *)((uint)p_dmr_call_config_state->field_0x2 + _DAT_030274ec) = 0;
          OSFlagPost_wrapper_set_fixed_grp(4);
        }
        pdVar1 = p_dmr_call_config_state;
        *(undefined1 *)((uint)p_dmr_call_config_state->field_0x2 + _DAT_030274ec + 2) = 0;
        *(char *)((int)PTR_DAT_030274d8 + 0x73) = cVar6;
        pcVar2 = p_call_setup_sm_state_aux;
        bVar8 = cVar6 + 1U & 1;
        p_call_setup_sm_state_aux->field_0x3 = bVar8;
        pcVar2->field_0x4 = bVar8;
        pdVar1->field_0x2 = bVar8;
        pdVar1->field_0x4 = bVar8;
        return;
      }
      PTR_DAT_03027668[0x75] = bStack_f >> 1 & 1;
      puVar4 = PTR_DAT_03027668;
      if ((bStack_f >> 1 & 1) == 0) {
        if (puVar3[0x72] == '\0') {
          puVar3[0x72] = 1;
          cVar6 = (bStack_f & 1) * '\x10' + (bStack_e >> 4);
          puVar3[0x73] = cVar6;
          pcVar2 = p_call_setup_sm_state_aux;
          bVar8 = cVar6 + 1U & 1;
          p_call_setup_sm_state_aux->field_0x3 = bVar8;
          pcVar2->field_0x4 = bVar8;
          iVar5 = call_index_get_1based();
          iVar9 = (int)((byte)puVar3[0x73] + 1) >> 1;
          if (iVar5 == iVar9) {
            p_dmr_call_config_state->field_0x7 = 1;
            OSFlagPost_wrapper_set_fixed_grp(0x10000000);
          }
          else {
            call_abort_by_index(iVar9);
          }
        }
        else if (p_dmr_call_config_state->field_0x9 == 0) {
          if (p_call_setup_sm_state_aux->field_0x15 == 0) {
            p_dmr_call_config_state->field_0x7 = 1;
            OSFlagPost_wrapper_set_fixed_grp(0x10000000);
          }
        }
        else if ((p_call_setup_sm_state_aux->field_0x15 == 0) && (PTR_DAT_03027668[0x74] == '\x01'))
        {
          PTR_DAT_03027668[0x74] = 0;
          cVar6 = (bStack_f & 1) * '\x10' + (bStack_e >> 4);
          puVar4[0x73] = cVar6;
          pcVar2 = p_call_setup_sm_state_aux;
          bVar8 = cVar6 + 1U & 1;
          p_call_setup_sm_state_aux->field_0x3 = bVar8;
          pcVar2->field_0x4 = bVar8;
          iVar5 = call_index_get_1based();
          iVar9 = (int)((byte)puVar4[0x73] + 1) >> 1;
          if (iVar5 == iVar9) {
            p_dmr_call_config_state->field_0x7 = 1;
            OSFlagPost_wrapper_set_fixed_grp(0x10000000);
          }
          else {
            call_abort_by_index(iVar9);
          }
        }
      }
    }
  }
  return;
}


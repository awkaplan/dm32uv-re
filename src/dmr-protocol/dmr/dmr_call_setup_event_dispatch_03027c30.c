/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_event_dispatch @ 03027c30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 548 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_call_setup_event_dispatch(void)

{
  dword dVar1;
  undefined4 *puVar2;
  dmr_call_config_state *pdVar3;
  undefined1 *puVar4;
  call_setup_sm_state_aux *pcVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  byte abStack_2c [12];
  uint local_20;
  int local_1c;
  byte local_18;
  char cStack_17;
  byte bStack_16;
  undefined1 uStack_15;
  char cStack_11;
  
  dVar1 = SystemControl_Type_11000000.RX_TYPE_INFO;
  if ((dVar1 >> 0x1a & 1) == 0) {
    if (p_call_setup_sm_state_aux->field_0x5 == *(byte *)((int)PTR_DAT_03027e10 + 6)) {
      copy_bytes_from_offset_table(0,&local_18,0xc);
      if ((cStack_17 == '\x10') && ((local_18 & 0x3f) == 0x3e)) {
        p_dmr_call_config_state->field_0x3 = 0;
      }
      else {
        p_dmr_call_config_state->field_0x3 = 1;
      }
      iVar6 = call_setup_target_id_decode_and_check(3,&local_18,&local_1c,&local_20);
      puVar4 = PTR_DAT_03028210;
      pdVar3 = p_dmr_call_config_state;
      if (iVar6 == 0) {
        *(undefined2 *)&p_dmr_call_config_state->field_0x10 = 0;
        if ((dVar1 >> 2 & 3) == 0) {
          pdVar3->field_0x2 = *(byte *)pdVar3;
        }
        puVar2 = PTR_DAT_03027e10;
        local_18 = local_18 & 0x3f;
        if (cStack_17 == '\0') {
          if (local_18 == 5) {
            bVar7 = *(byte *)p_dmr_call_config_state;
            PTR_DAT_03027e10[bVar7 + 6] = local_1c;
            puVar2[bVar7 + 8] = local_20;
            puVar4 = PTR_DAT_03027e1c;
            PTR_DAT_03027e1c[2] = bStack_16;
            puVar4[3] = uStack_15;
            if (((PTR_DAT_03027e20[7] & 1) != 0) &&
               (local_1c == *(int *)&p_call_setup_sm_state_aux->field_0x24_0)) {
              PTR_DAT_03027e20[7] = PTR_DAT_03027e20[7] & 0xfe;
              p_call_setup_sm_state->field_0x5 = 0;
              ui_mode_dispatch(1);
              if (p_call_setup_sm_state_aux->field_0xb == 1) {
                dmr_lc_call_setup_header_build(abStack_2c,local_20);
                FUN_00015bd4(1,DAT_03027e28);
                *(undefined1 *)p_call_setup_sm_state = 2;
                call_event_record_append_to_history
                          (0,PTR_DAT_03027e20[4],1,abStack_2c,local_20,local_1c);
              }
              else {
                *(undefined1 *)p_call_setup_sm_state = 2;
                memset_bytes(abStack_2c,0,0xc);
                call_event_record_append_to_history
                          (0,PTR_DAT_03027e20[4],0,abStack_2c,local_20,local_1c);
              }
            }
          }
          else if (local_18 == 0x26) {
            bVar7 = *(byte *)p_dmr_call_config_state;
            PTR_DAT_03027e10[bVar7 + 6] = local_1c;
            puVar2[bVar7 + 8] = local_20;
            puVar4 = PTR_DAT_03027e1c;
            PTR_DAT_03027e1c[4] = bStack_16 >> 6 & 1;
            puVar4[5] = bStack_16 & 0x3f;
            puVar4[6] = uStack_15;
            if (local_1c == *(int *)&p_call_setup_sm_state_aux->field_0x24_0) {
              if ((PTR_DAT_03027e20[7] & 1) == 0) {
                if ((*(byte *)p_dmr_status_flags & 0x40) != 0) {
                  *(byte *)p_dmr_status_flags = *(byte *)p_dmr_status_flags & 0xbf;
                  dialog_state_set_substate(2);
                }
              }
              else {
                PTR_DAT_03027e20[7] = PTR_DAT_03027e20[7] & 0xfe;
                ui_mode_dispatch(5);
              }
            }
          }
          else if (local_18 == 4) {
            bVar7 = *(byte *)p_dmr_call_config_state;
            PTR_DAT_03027e10[bVar7 + 6] = local_1c;
            puVar2[bVar7 + 8] = local_20;
            PTR_DAT_03027e1c[2] = bStack_16;
            if (local_20 != *(uint *)&p_call_setup_sm_state_aux->field_0x24_0) {
              OSFlagPost_wrapper_set_fixed_grp(0x800);
            }
          }
        }
        else if (((cStack_17 == '\x10') &&
                 (*(uint *)&p_call_setup_sm_state_aux->field_0x24_0 != local_20)) &&
                ((byte)(local_18 - 0x1d) < 0x22)) {
                    /* WARNING: Could not recover jumptable at 0x03027e70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)(PTR_PTR_03027e7c[(byte)(local_18 - 0x1d)] & 0xfffffffe))();
          return;
        }
      }
      else if (((cStack_17 == '\x10') && ((local_18 & 0x3f) == 0x3d)) &&
              (p_call_setup_sm_state_aux->mode_0x1 == 2)) {
        if (p_call_setup_sm_state_aux->field_0x15 == 0) {
          PTR_DAT_03028210[0x73] = cStack_11;
          pcVar5 = p_call_setup_sm_state_aux;
          bVar7 = cStack_11 + 1U & 1;
          p_call_setup_sm_state_aux->field_0x3 = bVar7;
          pcVar5->field_0x4 = bVar7;
          pdVar3 = p_dmr_call_config_state;
          p_dmr_call_config_state->field_0x2 = bVar7;
          pdVar3->field_0x4 = bVar7;
          iVar6 = call_index_get_1based();
          iVar8 = (int)((byte)puVar4[0x73] + 1) >> 1;
          if (iVar6 != iVar8) {
            call_abort_by_index(iVar8);
          }
        }
        p_dmr_call_config_state->field_0x3 = 0;
      }
    }
    else if ((*(byte *)((int)PTR_DAT_03027e10 + 6) == 0xf) &&
            (p_call_setup_sm_state_aux->mode_0x1 == 4)) {
      copy_bytes_from_offset_table(0,&local_18,0xc);
      if (((local_18 & 0x3f) == 7) && (cStack_17 == '\0')) {
        dmr_rx_burst_dispatch(&local_18);
      }
    }
  }
  return;
}


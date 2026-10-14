/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_state_machine_step @ 0301e034 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1230 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int call_setup_state_machine_step(char param_1,char param_2,byte *param_3)

{
  ushort uVar1;
  call_setup_sm_state_aux *pcVar2;
  call_setup_sm_state *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  byte bVar6;
  undefined4 uVar7;
  int iStack_28;
  
  *param_3 = 0;
  if (*(char *)p_call_setup_sm_state_aux == '\0') {
    bVar6 = p_call_setup_sm_state_aux->mode_0x1;
    if (bVar6 == 1) {
      iVar5 = dmr_call_config_state_not_idle();
      if ((iVar5 == 0) && (iVar5 = dmr_call_config_field0x9_not_one(), iVar5 == 0)) {
        iVar5 = call_setup_step_permitted(param_1,param_2,param_3);
      }
      else {
        iVar5 = dmr_call_config_state_not_idle();
        if (iVar5 == 1) {
          iVar5 = read_byte_field_0300c3ac();
          puVar4 = PTR_DAT_0301e360;
          pcVar3 = p_call_setup_sm_state;
          pcVar2 = p_call_setup_sm_state_aux;
          if ((iVar5 == 1) && (param_2 == '\x01')) {
            p_call_setup_sm_state_aux->field_0x13 = 1;
            *param_3 = 1;
            return 1;
          }
          if (p_call_setup_sm_state_aux->field_0x19 == 0) {
            bVar6 = 0;
          }
          else {
            bVar6 = 0;
            uVar7 = 0x18000000;
            do {
              os_flag_post_clear_0300c784(0x18000000);
              puVar4[7] = puVar4[7] & 0xfd | 2;
              if (((pcVar3->flags_0x19 & 1) != 0) || ((PTR_DAT_0301e364[5] & 4) != 0)) break;
              history_record_build_type3
                        (0xffffff,*(undefined4 *)&pcVar2->field_0x24_0,PTR_DAT_0301e364,0,uVar7);
              *(undefined1 *)pcVar3 = 2;
              ui_mode_dispatch(6);
              modem_mode_select(1,2);
              osflag_pend_consume_with_decisecond_timeout
                        (0x10000000,0,*(undefined2 *)&pcVar2->field_0x1c,&iStack_28);
              iVar5 = noop_stub_0300c434();
              if (iVar5 == iStack_28) {
                os_flag_post_clear_0300c784(0x10000000);
                break;
              }
              bVar6 = bVar6 + 1;
            } while (bVar6 < pcVar2->field_0x19);
          }
        }
        else {
          bVar6 = 0;
        }
        PTR_DAT_0301e360[7] = PTR_DAT_0301e360[7] & 0xfd;
        if ((p_call_setup_sm_state->flags_0x19 & 1) == 0) {
          if ((PTR_DAT_0301e364[5] & 4) == 0) {
            if (bVar6 < p_call_setup_sm_state_aux->field_0x19) {
              osflag_pend_consume_with_decisecond_timeout(0x8000000,0,0x168,&iStack_28);
              iVar5 = noop_stub_0300c434();
              if (iVar5 == iStack_28) {
                os_flag_post_clear_0300c784(0x8000000);
                ui_mode_group2_flag_set(4,4);
                call_setup_step_permitted(param_1,param_2,param_3);
                iVar5 = 0;
              }
              else {
                ui_mode_group2_flag_set(4,1);
                p_call_setup_sm_state->field_0x5 = 0;
                *param_3 = 2;
                iVar5 = 1;
              }
            }
            else {
              ui_mode_group2_flag_set(4,1);
              p_call_setup_sm_state->field_0x5 = 0;
              *param_3 = 2;
              iVar5 = 1;
            }
          }
          else {
            OSFlagPost_wrapper_set_passthrough(0x1000);
            ui_mode_group2_flag_set(4,1);
            p_call_setup_sm_state->field_0x5 = 0;
            *param_3 = 2;
            iVar5 = 1;
          }
        }
        else {
          OSFlagPost_wrapper_set_passthrough(0x1000);
          ui_mode_group2_flag_set(4,1);
          p_call_setup_sm_state->field_0x5 = 0;
          *param_3 = 2;
          iVar5 = 1;
        }
      }
    }
    else if (bVar6 == 0) {
      if (param_1 == '\x02') {
        iVar5 = dmr_call_setup_block_d_byte5_read();
        if (iVar5 == 0) {
          modem_mode_select(p_call_setup_sm_state_aux->mode_0x1,2);
          iVar5 = 0;
        }
        else {
          iVar5 = 0;
        }
      }
      else if (param_1 == '\x03') {
        iVar5 = read_byte_field_0300c3ac();
        if (iVar5 == 1) {
          p_call_setup_sm_state_aux->field_0x13 = 1;
          *param_3 = 1;
          iVar5 = 1;
        }
        else {
          *(undefined1 *)p_call_setup_sm_state = 0;
          iVar5 = 0;
        }
      }
      else if (param_2 == '\0') {
        *(undefined1 *)p_call_setup_sm_state = 2;
        modem_mode_select(0,2);
        iVar5 = 0;
      }
      else if (param_2 == '\x01') {
        iVar5 = read_byte_field_0300c3ac();
        if (iVar5 == 1) {
          p_call_setup_sm_state_aux->field_0x13 = 1;
          *param_3 = 1;
          iVar5 = 1;
        }
        else {
          *(undefined1 *)p_call_setup_sm_state = 0;
          modem_mode_select(p_call_setup_sm_state_aux->mode_0x1,2);
          iVar5 = 0;
        }
      }
      else if (param_2 == '\x02') {
        iVar5 = read_byte_field_0300c3ac();
        if (iVar5 == 1) {
          iVar5 = call_setup_state_advance_gate();
          if (iVar5 == 0) {
            p_call_setup_sm_state_aux->field_0x13 = 1;
            *param_3 = 1;
            iVar5 = 1;
          }
          else {
            *(undefined1 *)p_call_setup_sm_state = 0;
            modem_mode_select(p_call_setup_sm_state_aux->mode_0x1,2);
            iVar5 = 0;
          }
        }
        else {
          *(undefined1 *)p_call_setup_sm_state = 0;
          modem_mode_select(p_call_setup_sm_state_aux->mode_0x1,2);
          iVar5 = 0;
        }
      }
      else {
        iVar5 = 0;
      }
    }
    else if (bVar6 == 2) {
      iVar5 = call_setup_sm_field0x72_not_one();
      if (iVar5 == 0) {
        iVar5 = dmr_call_config_state_not_idle();
        pcVar2 = p_call_setup_sm_state_aux;
        if (iVar5 == 0) {
          iVar5 = call_setup_step_ready_gate(param_1,param_2,param_3);
        }
        else {
          if (p_call_setup_sm_state_aux->field_0x19 != 0) {
            bVar6 = 0;
            do {
              os_flag_post_clear_0300c784(0x8000000);
              history_record_build_type3(0xffffff,*(undefined4 *)&pcVar2->field_0x24_0);
              *(undefined1 *)p_call_setup_sm_state = 2;
              modem_mode_select(2,2);
              uVar1 = *(ushort *)&pcVar2->field_0x1c;
              iVar5 = max_linked_list_length_of_two();
              osflag_pend_consume_with_decisecond_timeout
                        (0x8000000,0,iVar5 * 0x3c + (uint)uVar1,&iStack_28);
              iVar5 = noop_stub_0300c434();
              if (iVar5 == iStack_28) {
                os_flag_post_clear_0300c784(0x8000000);
                if (bVar6 < p_call_setup_sm_state_aux->field_0x19) {
                  iVar5 = call_setup_step_ready_gate(param_1,param_2,param_3);
                  return iVar5;
                }
                break;
              }
              bVar6 = bVar6 + 1;
            } while (bVar6 < pcVar2->field_0x19);
          }
          *param_3 = 2;
          call_setup_sm_field0x72_and_0x78_clear();
          iVar5 = 1;
        }
      }
      else {
        *param_3 = 3;
        iVar5 = 1;
      }
    }
    else if (bVar6 == 4) {
      if (param_1 == '\x02') {
        modem_mode_select(4,2);
        iVar5 = 0;
      }
      else if (param_1 == '\x03') {
        iVar5 = read_byte_field_0300c3ac();
        if (iVar5 == 1) {
          p_call_setup_sm_state_aux->field_0x13 = 1;
          *param_3 = 1;
          iVar5 = 1;
        }
        else {
          *(undefined1 *)p_call_setup_sm_state = 0;
          iVar5 = 0;
        }
      }
      else if (param_2 == '\0') {
        *(undefined1 *)p_call_setup_sm_state = 2;
        modem_mode_select(4,2);
        iVar5 = 0;
      }
      else if (param_2 == '\x01') {
        iVar5 = read_byte_field_0300c3ac();
        if (iVar5 == 1) {
          p_call_setup_sm_state_aux->field_0x13 = 1;
          *param_3 = 1;
          iVar5 = 1;
        }
        else {
          *(undefined1 *)p_call_setup_sm_state = 0;
          modem_mode_select(p_call_setup_sm_state_aux->mode_0x1,2);
          iVar5 = 0;
        }
      }
      else if (param_2 == '\x02') {
        iVar5 = read_byte_field_0300c3ac();
        if (iVar5 == 1) {
          iVar5 = call_setup_state_advance_gate();
          if (iVar5 == 0) {
            p_call_setup_sm_state_aux->field_0x13 = 1;
            *param_3 = 1;
            iVar5 = 1;
          }
          else {
            *(undefined1 *)p_call_setup_sm_state = 0;
            modem_mode_select(p_call_setup_sm_state_aux->mode_0x1,2);
            iVar5 = 0;
          }
        }
        else {
          *(undefined1 *)p_call_setup_sm_state = 0;
          modem_mode_select(p_call_setup_sm_state_aux->mode_0x1,2);
          iVar5 = 0;
        }
      }
      else {
        iVar5 = 0;
      }
    }
    else {
      iVar5 = 0;
    }
  }
  else if (param_2 == '\0') {
    iVar5 = 0;
  }
  else if (param_2 == '\x01') {
    iVar5 = read_byte_field_0300c3ac();
    if (iVar5 == 1) {
      p_call_setup_sm_state_aux->field_0x13 = 1;
      iVar5 = 1;
    }
    else {
      iVar5 = 0;
    }
  }
  else if (param_2 == '\x03') {
    iVar5 = read_byte_field_0300c3ac();
    if (iVar5 == 1) {
      iVar5 = noop_stub_030273ec();
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        p_call_setup_sm_state_aux->field_0x13 = 1;
        iVar5 = 1;
      }
    }
    else {
      iVar5 = 0;
    }
  }
  else if (param_2 == '\x04') {
    iVar5 = read_byte_field_0300c3ac();
    if (iVar5 == 1) {
      iVar5 = noop_stub_030273f0();
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        p_call_setup_sm_state_aux->field_0x13 = 1;
        iVar5 = 1;
      }
    }
    else {
      iVar5 = 0;
    }
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_setup_ack_retry_and_history_log_loop @ 0301f1c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 3148 bytes
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

undefined1 call_setup_ack_retry_and_history_log_loop(void)

{
  char cVar1;
  undefined2 *puVar2;
  call_setup_sm_state_aux *pcVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  call_setup_sm_state *pcVar6;
  call_setup_sm_state *pcVar7;
  radio_mode_state_0003e318 *prVar8;
  radio_mode_state_0003e318 *prVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ushort uVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  byte bVar18;
  int iStack_2c;
  undefined1 uStack_25;
  
  uVar16 = (uint)p_call_setup_sm_state_aux->field_0x22;
  iVar10 = call_setup_state_machine_step(1,p_call_setup_sm_state_aux->field_0x8,&uStack_25);
  puVar5 = PTR_DAT_0301ff7c;
  if (iVar10 == 0) {
    if (p_call_setup_sm_state_aux->field_0x7 == 1) {
      os_flag_post_clear_0300c8d4(0x200);
      puVar5 = PTR_DAT_0301f6c0;
      if (*(char *)PTR_DAT_0301f2f4 == '\0') {
        if (*(char *)((int)PTR_DAT_0301f2f4 + 1) == '\x01') {
          call_setup_set_pending_flag();
          iVar10 = DAT_0301f300;
          pcVar3 = p_call_setup_sm_state_aux;
          puVar2 = PTR_DAT_0301f2f4;
          if (p_call_setup_sm_state_aux->field_0x16 != 0) {
            uVar17 = 0;
            do {
              if (uVar17 == 0) {
                history_log_type3_packet_builder
                          (*(undefined1 *)puVar2,*(undefined1 *)((int)puVar2 + 1),0,uVar16,
                           *(undefined4 *)(puVar2 + 8),puVar2[10],puVar2[1],puVar2[2],
                           *(undefined4 *)(puVar2 + 4),*(undefined4 *)&pcVar3->field_0x24_0,0);
                ui_mode_dispatch(8);
              }
              os_flag_post_clear_0300c8d4(0x80);
              osflag_pend_consume_with_decisecond_timeout_alt
                        (0x80,0,uVar16 * 0x3c + 2000,&iStack_2c);
              os_flag_post_clear_0300c8d4(0x80);
              iVar11 = noop_stub_0300c42c();
              if (iVar11 == iStack_2c) {
                iVar11 = call_setup_state_machine_step(1,pcVar3->field_0x8,&uStack_25);
                if (iVar11 != 0) {
                  clear_byte_field_dat03023b88_0x15();
                  return uStack_25;
                }
                history_log_type3_packet_builder
                          (*(undefined1 *)puVar2,*(undefined1 *)((int)puVar2 + 1),0,uVar16,
                           *(undefined4 *)(puVar2 + 8),puVar2[10],puVar2[1],puVar2[2],
                           *(undefined4 *)(puVar2 + 4),*(undefined4 *)&pcVar3->field_0x24_0,1);
              }
              else {
                iVar11 = noop_stub_0300c434();
                puVar4 = PTR_DAT_0301f4cc;
                if (iVar11 == iStack_2c) {
                  cVar1 = PTR_DAT_0301f304[0x11];
                  if (cVar1 == '\0') {
                    clear_byte_field_dat03023b88_0x15();
                    uVar15 = (uint)p_call_setup_sm_state_aux->field_0x16;
                    if (uVar15 <= uVar17) goto LAB_0301f400;
                    OSTimeDly_ms_wrapper(0x1e0);
                    call_setup_set_pending_flag();
                    osflag_pend_consume_with_decisecond_timeout_alt
                              (0x200,0,uVar16 * 0x3c + 10000,&iStack_2c);
                    os_flag_post_clear_0300c8d4(0x200);
                    iVar10 = noop_stub_0300c42c();
                    puVar2 = PTR_DAT_0301f4cc;
                    if (iVar10 == iStack_2c) {
                      PTR_DAT_0301f4cc[1] = PTR_DAT_0301f4cc[1] + 1;
                      uVar13 = puVar2[2] + 1;
                      puVar2[2] = uVar13;
                      if (0x9f < uVar13) {
                        PTR_DAT_0301f4cc[2] = 0x81;
                      }
                      clear_byte_field_dat03023b88_0x15();
                      return 6;
                    }
                    iVar10 = noop_stub_0300c434();
                    puVar2 = PTR_DAT_0301f4cc;
                    if (iVar10 == iStack_2c) {
                      PTR_DAT_0301f4cc[1] = PTR_DAT_0301f4cc[1] + 1;
                      uVar13 = puVar2[2] + 1;
                      puVar2[2] = uVar13;
                      if (0x9f < uVar13) {
                        PTR_DAT_0301f4cc[2] = 0x81;
                      }
                      clear_byte_field_dat03023b88_0x15();
                      return 0;
                    }
                    goto LAB_0301f4d8;
                  }
                  if (cVar1 == '\x01') {
                    if (PTR_DAT_0301f4c8[0x12] != '\x01') {
                      PTR_DAT_0301f4cc[1] = PTR_DAT_0301f4cc[1] + 1;
                      uVar13 = puVar4[2] + 1;
                      puVar4[2] = uVar13;
                      if (0x9f < uVar13) {
                        PTR_DAT_0301f4cc[2] = 0x81;
                      }
                      clear_byte_field_dat03023b88_0x15();
                      return 5;
                    }
                    dmr_history_bitmask_record_builder(pcVar3->field_0x22,1,0,0);
                  }
                  else if (cVar1 == '\x02') {
                    dmr_history_bitmask_record_builder
                              (pcVar3->field_0x22,0,DAT_0301f4d0,*(undefined1 *)(iVar10 + 0x322));
                  }
                }
              }
              uVar17 = uVar17 + 1 & 0xff;
            } while (uVar17 < pcVar3->field_0x16);
          }
          uVar15 = (uint)p_call_setup_sm_state_aux->field_0x16;
LAB_0301f400:
          puVar2 = PTR_DAT_0301f4cc;
          if (uVar15 * 2000 < 10000) {
            OSTimeDly_ms_wrapper(0x1e0);
            call_setup_set_pending_flag();
            osflag_pend_consume_with_decisecond_timeout_alt
                      (0x200,0,(uint)p_call_setup_sm_state_aux->field_0x16 * -2000 + 10000,
                       &iStack_2c);
            os_flag_post_clear_0300c8d4(0x200);
            iVar10 = noop_stub_0300c42c();
            puVar2 = PTR_DAT_0301f4cc;
            if (iVar10 == iStack_2c) {
              PTR_DAT_0301f4cc[1] = PTR_DAT_0301f4cc[1] + 1;
              uVar13 = puVar2[2] + 1;
              puVar2[2] = uVar13;
              if (0x9f < uVar13) {
                PTR_DAT_0301f4cc[2] = 0x81;
              }
              clear_byte_field_dat03023b88_0x15();
              uStack_25 = 6;
            }
            else {
              iVar10 = noop_stub_0300c434();
              puVar2 = PTR_DAT_0301f4cc;
              if (iVar10 == iStack_2c) {
                PTR_DAT_0301f4cc[1] = PTR_DAT_0301f4cc[1] + 1;
                uVar13 = puVar2[2] + 1;
                puVar2[2] = uVar13;
                if (0x9f < uVar13) {
                  PTR_DAT_0301f4cc[2] = 0x81;
                }
                clear_byte_field_dat03023b88_0x15();
                uStack_25 = 0;
              }
              else {
LAB_0301f4d8:
                clear_byte_field_dat03023b88_0x15();
                uStack_25 = 0;
              }
            }
          }
          else {
            PTR_DAT_0301f4cc[1] = PTR_DAT_0301f4cc[1] + 1;
            uVar13 = puVar2[2] + 1;
            puVar2[2] = uVar13;
            if (0x9f < uVar13) {
              PTR_DAT_0301f4cc[2] = 0x81;
            }
            clear_byte_field_dat03023b88_0x15();
            uStack_25 = 4;
          }
        }
        else {
          history_log_type3_packet_builder
                    (0,*(char *)((int)PTR_DAT_0301f2f4 + 1),0,uVar16,PTR_DAT_0301f6c0[4],
                     *(undefined2 *)(PTR_DAT_0301f6c0 + 5),
                     *(undefined2 *)((int)PTR_DAT_0301f6c0 + 2),
                     *(undefined2 *)(PTR_DAT_0301f6c0 + 1),PTR_DAT_0301f6c0[2],
                     *(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0,0);
          ui_mode_dispatch(8);
          osflag_pend_consume_with_decisecond_timeout_alt(0x200,0,uVar16 * 0x3c + 10000,&iStack_2c);
          os_flag_post_clear_0300c8d4(0x200);
          iVar10 = noop_stub_0300c42c();
          puVar5 = PTR_DAT_0301f6c0;
          if (iVar10 == iStack_2c) {
            *(short *)((int)PTR_DAT_0301f6c0 + 2) = *(short *)((int)PTR_DAT_0301f6c0 + 2) + 1;
            uVar13 = *(short *)(puVar5 + 1) + 1;
            *(ushort *)(puVar5 + 1) = uVar13;
            if (uVar13 < 0xa0) {
              uStack_25 = 6;
            }
            else {
              *(undefined2 *)(PTR_DAT_0301f6c0 + 1) = 0x81;
              uStack_25 = 6;
            }
          }
          else {
            iVar10 = noop_stub_0300c434();
            puVar5 = PTR_DAT_0301f6c0;
            if (iVar10 == iStack_2c) {
              *(short *)((int)PTR_DAT_0301f6c0 + 2) = *(short *)((int)PTR_DAT_0301f6c0 + 2) + 1;
              uVar13 = *(short *)(puVar5 + 1) + 1;
              *(ushort *)(puVar5 + 1) = uVar13;
              if (uVar13 < 0xa0) {
                uStack_25 = 0;
              }
              else {
                *(undefined2 *)(PTR_DAT_0301f6c0 + 1) = 0x81;
                uStack_25 = 0;
              }
            }
            else {
              uStack_25 = 0;
            }
          }
        }
      }
      else {
        history_log_type3_packet_builder
                  (*(char *)PTR_DAT_0301f2f4,*(undefined1 *)((int)PTR_DAT_0301f6c0 + 1),0,uVar16,
                   PTR_DAT_0301f6c0[4],*(undefined2 *)(PTR_DAT_0301f6c0 + 5),
                   *(undefined2 *)((int)PTR_DAT_0301f6c0 + 2),*(undefined2 *)(PTR_DAT_0301f6c0 + 1),
                   PTR_DAT_0301f6c0[2],*(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0,0);
        *(short *)((int)puVar5 + 2) = *(short *)((int)puVar5 + 2) + 1;
        sVar14 = *(short *)(puVar5 + 1);
        *(ushort *)(puVar5 + 1) = sVar14 + 1U;
        if ((ushort)(sVar14 + 1U) < 0xa0) {
          uStack_25 = 0;
        }
        else {
          *(undefined2 *)(puVar5 + 1) = 0x81;
          uStack_25 = 0;
        }
      }
    }
    else if (*(char *)PTR_DAT_0301f6c0 == '\0') {
      os_flag_post_clear_0300c8d4(0x200);
      if (*(char *)((int)PTR_DAT_0301f6c0 + 1) == '\x01') {
        call_setup_set_pending_flag();
        iVar10 = DAT_0301f6cc;
        pcVar6 = p_call_setup_sm_state;
        pcVar3 = p_call_setup_sm_state_aux;
        puVar5 = PTR_DAT_0301f6c0;
        bVar18 = 0;
        do {
          if (bVar18 == 0) {
            dmr_text_packet_builder_and_log
                      (*(undefined1 *)puVar5,*(undefined1 *)((int)puVar5 + 1),0,uVar16,puVar5[4],
                       *(undefined2 *)(puVar5 + 5),*(undefined2 *)((int)puVar5 + 2),
                       *(undefined2 *)(puVar5 + 1),puVar5[2],*(undefined4 *)&pcVar3->field_0x24_0,0)
            ;
            ui_mode_dispatch(8);
          }
          os_flag_post_clear_0300c8d4(0x80);
          pcVar6->field_0x1a = 1;
          iVar11 = max_linked_list_length_of_two();
          osflag_pend_consume_with_decisecond_timeout_alt(0x80,0,iVar11 * 0x3c + 2000,&iStack_2c);
          os_flag_post_clear_0300c8d4(0x80);
          pcVar7 = p_call_setup_sm_state;
          if ((pcVar6->flags_0x19 & 8) != 0) {
            p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7;
            ui_mode_group2_flag_set(2,2);
            if ((pcVar7->field_0x5 == 8) || (pcVar7->field_0x5 == 10)) {
              p_call_setup_sm_state->field_0x5 = 0;
            }
            clear_byte_field_dat03023b88_0x15();
            return uStack_25;
          }
          iVar11 = noop_stub_0300c42c();
          if (iVar11 == iStack_2c) {
            iVar11 = call_setup_state_machine_step(1,pcVar3->field_0x8,&uStack_25);
            if (iVar11 != 0) {
              ui_mode_group2_flag_set(2,2);
              p_call_setup_sm_state->field_0x5 = 0;
              clear_byte_field_dat03023b88_0x15();
              return uStack_25;
            }
            if (bVar18 < 3) {
              *(char *)(puVar5[4] + 1) = *(char *)(puVar5[4] + 1) + '\x01';
              dmr_text_packet_builder_and_log
                        (*(undefined1 *)puVar5,*(undefined1 *)((int)puVar5 + 1),0,uVar16,puVar5[4],
                         *(undefined2 *)(puVar5 + 5),*(undefined2 *)((int)puVar5 + 2),
                         *(undefined2 *)(puVar5 + 1),puVar5[2],*(undefined4 *)&pcVar3->field_0x24_0,
                         1);
              ui_mode_dispatch(8);
            }
          }
          else {
            iVar11 = noop_stub_0300c434();
            puVar2 = PTR_DAT_0301f8ec;
            if (iVar11 == iStack_2c) {
              cVar1 = PTR_DAT_0301f8e8[0x11];
              if (cVar1 == '\0') {
                clear_byte_field_dat03023b88_0x15();
                if (bVar18 < 4) {
                  if (p_radio_mode_state_0003e318[1].flags_0x5 == 0) {
                    ui_mode_group2_flag_set(2,1);
                    p_call_setup_sm_state->field_0x5 = 0;
                    clear_byte_field_dat03023b88_0x15();
                    return 0;
                  }
                  if (p_radio_mode_state_0003e318[1].flags_0x5 == 2) {
                    ui_mode_group2_flag_set(2,1);
                    p_call_setup_sm_state->field_0x5 = 0;
                    puVar2 = PTR_DAT_0301f8ec;
                    PTR_DAT_0301f8ec[1] = PTR_DAT_0301f8ec[1] + 1;
                    uVar13 = puVar2[2] + 1;
                    puVar2[2] = uVar13;
                    if (0x9f < uVar13) {
                      PTR_DAT_0301f8ec[2] = 0x81;
                    }
                    clear_byte_field_dat03023b88_0x15();
                    return 0;
                  }
                  OSTimeDly_ms_wrapper(0x1e0);
                  call_setup_set_pending_flag();
                  p_call_setup_sm_state->field_0x1a = 2;
                  iVar10 = max_linked_list_length_of_two();
                  osflag_pend_consume_with_decisecond_timeout_alt
                            (0x200,0,iVar10 * 0x3c + 10000,&iStack_2c);
                  os_flag_post_clear_0300c8d4(0x200);
                  iVar10 = noop_stub_0300c42c();
                  if ((iVar10 != iStack_2c) && ((p_call_setup_sm_state->flags_0x19 & 8) == 0)) {
                    iVar10 = noop_stub_0300c434();
                    puVar5 = PTR_DAT_0301fb40;
                    if (iVar10 == iStack_2c) {
                      *(short *)((int)PTR_DAT_0301fb40 + 2) =
                           *(short *)((int)PTR_DAT_0301fb40 + 2) + 1;
                      uVar13 = *(short *)(puVar5 + 1) + 1;
                      *(ushort *)(puVar5 + 1) = uVar13;
                      if (0x9f < uVar13) {
                        *(undefined2 *)(PTR_DAT_0301fb40 + 1) = 0x81;
                      }
                      ui_mode_group2_flag_set(2,1);
                      p_call_setup_sm_state->field_0x5 = 0;
                      clear_byte_field_dat03023b88_0x15();
                      return 0;
                    }
                    return 0;
                  }
                  p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7;
                  puVar2 = PTR_DAT_0301f8ec;
                  PTR_DAT_0301f8ec[1] = PTR_DAT_0301f8ec[1] + 1;
                  uVar13 = puVar2[2] + 1;
                  puVar2[2] = uVar13;
                  if (0x9f < uVar13) {
                    PTR_DAT_0301f8ec[2] = 0x81;
                  }
                  ui_mode_group2_flag_set(2,2);
                  if ((p_call_setup_sm_state->field_0x5 == 8) ||
                     (p_call_setup_sm_state->field_0x5 == 10)) {
                    p_call_setup_sm_state->field_0x5 = 0;
                  }
                  clear_byte_field_dat03023b88_0x15();
                  return 6;
                }
                break;
              }
              if (cVar1 == '\x01') {
                if (PTR_DAT_0301f8e8[0x12] != '\x01') {
                  PTR_DAT_0301f8ec[1] = PTR_DAT_0301f8ec[1] + 1;
                  uVar13 = puVar2[2] + 1;
                  puVar2[2] = uVar13;
                  if (0x9f < uVar13) {
                    PTR_DAT_0301f8ec[2] = 0x81;
                  }
                  ui_mode_group2_flag_set(2,4);
                  p_call_setup_sm_state->field_0x5 = 0;
                  clear_byte_field_dat03023b88_0x15();
                  return 5;
                }
                dmr_history_bitmask_record_builder(pcVar3->field_0x22,1,0,0);
              }
              else if (cVar1 == '\x02') {
                dmr_history_bitmask_record_builder
                          (pcVar3->field_0x22,0,iVar10,*(undefined1 *)(iVar10 + 0x322));
              }
            }
          }
          bVar18 = bVar18 + 1;
        } while (bVar18 != 4);
        if (p_radio_mode_state_0003e318[1].flags_0x5 == 0) {
          ui_mode_group2_flag_set(2,2);
          p_call_setup_sm_state->field_0x5 = 0;
          uStack_25 = 4;
        }
        else {
          OSTimeDly_ms_wrapper(0x1e0);
          call_setup_set_pending_flag();
          p_call_setup_sm_state->field_0x1a = 2;
          osflag_pend_consume_with_decisecond_timeout_alt
                    (0x200,0,(uint)p_call_setup_sm_state_aux->field_0x16 * -2000 + 10000,&iStack_2c)
          ;
          os_flag_post_clear_0300c8d4(0x200);
          iVar10 = noop_stub_0300c42c();
          if ((iVar10 == iStack_2c) || ((p_call_setup_sm_state->flags_0x19 & 8) != 0)) {
            p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7;
            puVar5 = PTR_DAT_0301fb40;
            *(short *)((int)PTR_DAT_0301fb40 + 2) = *(short *)((int)PTR_DAT_0301fb40 + 2) + 1;
            uVar13 = *(short *)(puVar5 + 1) + 1;
            *(ushort *)(puVar5 + 1) = uVar13;
            if (0x9f < uVar13) {
              *(undefined2 *)(PTR_DAT_0301fb40 + 1) = 0x81;
            }
            ui_mode_group2_flag_set(2,2);
            if ((p_call_setup_sm_state->field_0x5 == 8) || (p_call_setup_sm_state->field_0x5 == 10))
            {
              p_call_setup_sm_state->field_0x5 = 0;
            }
            clear_byte_field_dat03023b88_0x15();
            uStack_25 = 6;
          }
          else {
            iVar10 = noop_stub_0300c434();
            puVar5 = PTR_DAT_0301fb40;
            if (iVar10 == iStack_2c) {
              *(short *)((int)PTR_DAT_0301fb40 + 2) = *(short *)((int)PTR_DAT_0301fb40 + 2) + 1;
              uVar13 = *(short *)(puVar5 + 1) + 1;
              *(ushort *)(puVar5 + 1) = uVar13;
              if (0x9f < uVar13) {
                *(undefined2 *)(PTR_DAT_0301fb40 + 1) = 0x81;
              }
              ui_mode_group2_flag_set(2,1);
              p_call_setup_sm_state->field_0x5 = 0;
              clear_byte_field_dat03023b88_0x15();
              uStack_25 = 0;
            }
            else {
              uStack_25 = 0;
            }
          }
        }
      }
      else {
        dmr_text_packet_builder_and_log
                  (*(undefined1 *)PTR_DAT_0301fb40,*(char *)((int)PTR_DAT_0301f6c0 + 1),0,uVar16,
                   PTR_DAT_0301fb40[4],*(undefined2 *)(PTR_DAT_0301fb40 + 5),
                   *(undefined2 *)((int)PTR_DAT_0301fb40 + 2),*(undefined2 *)(PTR_DAT_0301fb40 + 1),
                   PTR_DAT_0301fb40[2],*(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0,0);
        puVar5 = PTR_DAT_0301fb40;
        if ((p_radio_mode_state_0003e318[1].flags_0x6 & 0x80) == 0) {
          if ((p_radio_mode_state_0003e318[1].flags_0x7 & 4) == 0) {
            if (p_radio_mode_state_0003e318[1].flags_0x5 == 0) {
              ui_mode_dispatch(8);
              uStack_25 = 0;
            }
            else if (p_radio_mode_state_0003e318[1].flags_0x5 == 2) {
              ui_mode_dispatch(8);
              puVar2 = PTR_DAT_0301fdb8;
              PTR_DAT_0301fdb8[1] = PTR_DAT_0301fdb8[1] + 1;
              uVar13 = puVar2[2] + 1;
              puVar2[2] = uVar13;
              if (uVar13 < 0xa0) {
                uStack_25 = 0;
              }
              else {
                PTR_DAT_0301fdb8[2] = 0x81;
                uStack_25 = 0;
              }
            }
            else {
              ui_mode_dispatch(8);
              p_call_setup_sm_state->field_0x1a = 2;
              iVar10 = max_linked_list_length_of_two();
              osflag_pend_consume_with_decisecond_timeout_alt
                        (0x200,0,iVar10 * 0x3c + 10000,&iStack_2c);
              os_flag_post_clear_0300c8d4(0x200);
              iVar10 = noop_stub_0300c42c();
              if ((iVar10 == iStack_2c) || ((p_call_setup_sm_state->flags_0x19 & 8) != 0)) {
                p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7;
                puVar2 = PTR_DAT_0301fdb8;
                PTR_DAT_0301fdb8[1] = PTR_DAT_0301fdb8[1] + 1;
                uVar13 = puVar2[2] + 1;
                puVar2[2] = uVar13;
                if (0x9f < uVar13) {
                  PTR_DAT_0301fdb8[2] = 0x81;
                }
                ui_mode_group2_flag_set(2,2);
                if ((p_call_setup_sm_state->field_0x5 == 8) ||
                   (p_call_setup_sm_state->field_0x5 == 10)) {
                  p_call_setup_sm_state->field_0x5 = 0;
                  uStack_25 = 6;
                }
                else {
                  uStack_25 = 6;
                }
              }
              else {
                iVar10 = noop_stub_0300c434();
                puVar5 = PTR_DAT_0301ff7c;
                if (iVar10 == iStack_2c) {
                  *(short *)((int)PTR_DAT_0301ff7c + 2) = *(short *)((int)PTR_DAT_0301ff7c + 2) + 1;
                  uVar13 = *(short *)(puVar5 + 1) + 1;
                  *(ushort *)(puVar5 + 1) = uVar13;
                  if (0x9f < uVar13) {
                    *(undefined2 *)(PTR_DAT_0301ff7c + 1) = 0x81;
                  }
                  ui_mode_group2_flag_set(2,1);
                  p_call_setup_sm_state->field_0x5 = 0;
                  uStack_25 = 0;
                }
                else {
                  uStack_25 = 0;
                }
              }
            }
          }
          else {
            call_setup_set_pending_flag();
            iVar11 = DAT_0301fb54;
            iVar10 = _DAT_0301fb50;
            pcVar3 = p_call_setup_sm_state_aux;
            pcVar6 = p_call_setup_sm_state;
            puVar5 = PTR_DAT_0301fb40;
            while( true ) {
              ui_mode_dispatch(8);
              pcVar6->field_0x1a = 3;
              iVar12 = max_linked_list_length_of_two();
              osflag_pend_consume_with_decisecond_timeout_alt
                        (0x4000,0,iVar12 * 0x3c + 2000,&iStack_2c);
              os_flag_post_clear_0300c8d4(0x4000);
              pcVar7 = p_call_setup_sm_state;
              if ((pcVar6->flags_0x19 & 8) != 0) break;
              iVar12 = noop_stub_0300c42c();
              if (iVar12 == iStack_2c) {
                iVar12 = call_setup_state_machine_step(1,pcVar3->field_0x8,&uStack_25);
                if (iVar12 != 0) {
                  ui_mode_group2_flag_set(2,2);
                  p_call_setup_sm_state->field_0x5 = 0;
                  p_radio_mode_state_0003e318[1].flags_0x7 =
                       p_radio_mode_state_0003e318[1].flags_0x7 & 0xfb;
                  clear_byte_field_dat03023b88_0x15();
                  return uStack_25;
                }
                *(char *)(puVar5[4] + 1) = *(char *)(puVar5[4] + 1) + '\x01';
                sVar14 = *(short *)((int)puVar5 + 2) + 1;
                *(short *)((int)puVar5 + 2) = sVar14;
                dmr_text_packet_builder_and_log
                          (*(undefined1 *)puVar5,*(undefined1 *)((int)puVar5 + 1),0,uVar16,puVar5[4]
                           ,*(undefined2 *)(puVar5 + 5),sVar14,*(undefined2 *)(puVar5 + 1),puVar5[2]
                           ,*(undefined4 *)&pcVar3->field_0x24_0,1);
                ui_mode_dispatch(8);
              }
              else {
                iVar12 = noop_stub_0300c434();
                puVar2 = PTR_DAT_0301fdb8;
                prVar8 = p_radio_mode_state_0003e318;
                if (iVar12 == iStack_2c) {
                  cVar1 = *(char *)(iVar10 + 0x11);
                  if (cVar1 == '\0') {
                    p_radio_mode_state_0003e318[1].flags_0x7 =
                         p_radio_mode_state_0003e318[1].flags_0x7 & 0xf7 | 8;
                    clear_byte_field_dat03023b88_0x15();
                    prVar9 = p_radio_mode_state_0003e318;
                    if ((prVar8[1].flags_0x7 & 8) == 0) {
                      ui_mode_group2_flag_set(2,2);
                      p_call_setup_sm_state->field_0x5 = 0;
                      return 4;
                    }
                    p_radio_mode_state_0003e318[1].flags_0x7 =
                         p_radio_mode_state_0003e318[1].flags_0x7 & 0xf7;
                    puVar2 = PTR_DAT_0301fdb8;
                    if ((byte)(prVar9[1].flags_0x5 - 1) < 2) {
                      PTR_DAT_0301fdb8[1] = PTR_DAT_0301fdb8[1] + 1;
                      uVar13 = puVar2[2] + 1;
                      puVar2[2] = uVar13;
                      if (0x9f < uVar13) {
                        PTR_DAT_0301fdb8[2] = 0x81;
                      }
                    }
                    ui_mode_group2_flag_set(2,1);
                    p_call_setup_sm_state->field_0x5 = 0;
                    clear_byte_field_dat03023b88_0x15();
                    return 0;
                  }
                  if (cVar1 == '\x01') {
                    if (*(char *)(iVar10 + 0x12) != '\x01') {
                      PTR_DAT_0301fdb8[1] = PTR_DAT_0301fdb8[1] + 1;
                      uVar13 = puVar2[2] + 1;
                      puVar2[2] = uVar13;
                      if (0x9f < uVar13) {
                        PTR_DAT_0301fdb8[2] = 0x81;
                      }
                      ui_mode_group2_flag_set(2,4);
                      p_call_setup_sm_state->field_0x5 = 0;
                      p_radio_mode_state_0003e318[1].flags_0x7 =
                           p_radio_mode_state_0003e318[1].flags_0x7 & 0xfb;
                      clear_byte_field_dat03023b88_0x15();
                      return 5;
                    }
                    dmr_history_bitmask_record_builder(pcVar3->field_0x22,1,0,0);
                  }
                  else if (cVar1 == '\x02') {
                    dmr_history_bitmask_record_builder
                              (pcVar3->field_0x22,0,DAT_0301fdbc,*(undefined1 *)(iVar11 + 0x322));
                  }
                }
              }
            }
            p_call_setup_sm_state->flags_0x19 = p_call_setup_sm_state->flags_0x19 & 0xf7;
            PTR_DAT_0301fb58[10] = PTR_DAT_0301fb58[10] & 0xfe | 1;
            ui_mode_group2_flag_set(2,2);
            p_radio_mode_state_0003e318[1].flags_0x7 =
                 p_radio_mode_state_0003e318[1].flags_0x7 & 0xfb;
            if (1 < (byte)(pcVar7->field_0x5 - 1)) {
              pcVar7->field_0x5 = 0;
            }
            clear_byte_field_dat03023b88_0x15();
          }
        }
        else {
          *(short *)((int)PTR_DAT_0301fb40 + 2) = *(short *)((int)PTR_DAT_0301fb40 + 2) + 1;
          uVar13 = *(short *)(puVar5 + 1) + 1;
          *(ushort *)(puVar5 + 1) = uVar13;
          if (0x9f < uVar13) {
            *(undefined2 *)(PTR_DAT_0301fb40 + 1) = 0x81;
          }
          ui_mode_dispatch(8);
          uStack_25 = 0;
        }
      }
    }
    else {
      dmr_text_packet_builder_and_log
                (*(char *)PTR_DAT_0301f6c0,*(undefined1 *)((int)PTR_DAT_0301ff7c + 1),0,uVar16,
                 PTR_DAT_0301ff7c[4],*(undefined2 *)(PTR_DAT_0301ff7c + 5),
                 *(undefined2 *)((int)PTR_DAT_0301ff7c + 2),*(undefined2 *)(PTR_DAT_0301ff7c + 1),
                 PTR_DAT_0301ff7c[2],*(undefined4 *)&p_call_setup_sm_state_aux->field_0x24_0,0);
      *(short *)((int)puVar5 + 2) = *(short *)((int)puVar5 + 2) + 1;
      sVar14 = *(short *)(puVar5 + 1);
      *(ushort *)(puVar5 + 1) = sVar14 + 1U;
      if (0x9f < (ushort)(sVar14 + 1U)) {
        *(undefined2 *)(puVar5 + 1) = 0x81;
      }
      ui_mode_dispatch(8);
      uStack_25 = 0;
    }
  }
  return uStack_25;
}


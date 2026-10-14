/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dmr_call_setup_teardown_event_loop @ 03020044 (file base 0x03000000; code starts at 0x03001000)
 * Size: 1600 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: dmr-protocol
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dmr_call_setup_teardown_event_loop(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  byte bVar13;
  int iStack_2c;
  undefined1 uStack_25;
  
  puVar7 = PTR_DAT_03020154;
  puVar6 = PTR_DAT_03020150;
  iVar5 = DAT_0302014c;
  puVar4 = PTR_DAT_03020148;
  iVar3 = DAT_03020140;
  uStack_25 = 0;
  uVar11 = (uint)(byte)PTR_DAT_03020144[0x22];
  iVar12 = uVar11 * 0x3c + 2000;
  puVar10 = PTR_DAT_03020148 + 0x3e;
  do {
    *(undefined1 *)(iVar3 + 1) = 0;
    clear_byte_field_dat03023b88_0x15();
    uVar8 = osflag_pend_consume_with_decisecond_timeout_alt(0xa81f,0,0,&iStack_2c);
    *(undefined1 *)(iVar3 + 1) = 1;
    call_setup_set_pending_flag();
    if ((puVar4[0x394] & 2) == 0) {
      if ((uVar8 & 0xa001) != 0) {
        os_flag_post_clear_0300c8d4(1);
        os_flag_post_clear_0300c8d4(0x2000);
        os_flag_post_clear_0300c8d4(0x8000);
        cVar1 = *(char *)(iVar5 + 0xf);
        if ((cVar1 == '\x01') && ((uVar8 & 1) != 0)) {
          *puVar6 = *puVar4;
          puVar6[1] = puVar4[1];
          *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(puVar4 + 0x34);
          *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(puVar4 + 0x38);
          *(undefined4 *)(puVar6 + 8) = *(undefined4 *)(puVar4 + 0x2c);
          *(undefined4 *)(puVar6 + 0xc) = *(undefined4 *)(puVar4 + 0x30);
LAB_03020116:
          *(undefined4 *)(puVar6 + 0x10) = 0x22;
          if (0x21 < *(uint *)(puVar4 + 0x37c)) {
            *(uint *)(puVar6 + 0x14) = *(uint *)(puVar4 + 0x37c) - 0x22;
          }
        }
        else {
          if (((cVar1 != '\x02') || ((uVar8 & 0x8000) == 0)) && ((uVar8 & 0x2000) == 0))
          goto LAB_0302031e;
          *puVar6 = *puVar4;
          puVar6[1] = puVar4[1];
          *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(puVar4 + 0x34);
          *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(puVar4 + 0x38);
          *(undefined4 *)(puVar6 + 8) = *(undefined4 *)(puVar4 + 0x2c);
          *(undefined4 *)(puVar6 + 0xc) = *(undefined4 *)(puVar4 + 0x30);
          if ((uVar8 & 1) != 0) goto LAB_03020116;
          *(undefined4 *)(puVar6 + 0x14) = *(undefined4 *)(puVar4 + 0x37c);
        }
        if (*(uint *)(puVar4 + 0x37c) < 0x259) {
          memcpy_bytes_iram(DAT_03020308,DAT_0302030c);
          if ((uVar8 & 0x8001) == 0) {
            ui_mode_group_flag_set_and_post(2,2);
          }
          else if (*(short *)(puVar4 + 0x36) != *(short *)(puVar4 + 0x34)) {
            *(short *)(puVar4 + 0x36) = *(short *)(puVar4 + 0x34);
            ui_mode_group_flag_set_and_post(2,1);
          }
        }
        if ((*puVar6 == '\0') && ((uVar8 & 0x2000) == 0)) {
          if (puVar6[1] == '\x01') {
            osflag_pend_consume_with_decisecond_timeout_alt(0x100,0,0x78,&iStack_2c);
            os_flag_post_clear_0300c8d4(0x100);
            history_record_build_typed_dispatch
                      (0,1,puVar4[0x13],*(undefined4 *)(puVar4 + 0x30),
                       *(undefined4 *)(puVar4 + 0x2c),0,0);
          }
          clear_byte_field_dat03023b88_0x15();
          if (PTR_DAT_03020310[0x1b] == '\x01') {
            call_setup_set_pending_flag();
            iVar9 = dmr_call_setup_block_d_byte5_read();
            if (iVar9 == 0) {
              modem_mode_select(0,2);
            }
            if (PTR_DAT_03020310[0x16] != '\0') {
              bVar13 = 0;
              do {
                if (bVar13 == 0) {
                  call_teardown_packet_build_and_history_push
                            (*puVar6,1,0,uVar11,*(undefined2 *)(puVar6 + 2),
                             *(undefined2 *)(puVar6 + 4),*(undefined4 *)(puVar6 + 0xc),
                             *(undefined4 *)(puVar6 + 8),0);
                }
                osflag_pend_consume_with_decisecond_timeout_alt(0x80,0,iVar12,&iStack_2c);
                os_flag_post_clear_0300c8d4(0x80);
                iVar9 = noop_stub_0300c42c();
                if (iVar9 == iStack_2c) {
                  iVar9 = call_setup_state_machine_step(1,PTR_DAT_03020310[8],&uStack_25);
                  if (iVar9 != 0) break;
                  call_teardown_packet_build_and_history_push
                            (*puVar6,1,0,uVar11,*(undefined2 *)(puVar6 + 2),
                             *(undefined2 *)(puVar6 + 4),*(undefined4 *)(puVar6 + 0xc),
                             *(undefined4 *)(puVar6 + 8),1);
                }
                else {
                  iVar9 = noop_stub_0300c434();
                  if (iVar9 == iStack_2c) {
                    cVar1 = puVar4[0x11];
                    if (cVar1 == '\0') break;
                    if (cVar1 == '\x01') {
                      if (puVar4[0x12] != '\x01') break;
                      dmr_history_bitmask_record_builder(PTR_DAT_03020310[0x22],1,0,0);
                    }
                    else if (cVar1 == '\x02') {
                      dmr_history_bitmask_record_builder
                                (PTR_DAT_03020310[0x22],0,DAT_0302030c,
                                 *(undefined1 *)(puVar7 + 0x191));
                    }
                  }
                }
                bVar13 = bVar13 + 1;
              } while (bVar13 < (byte)PTR_DAT_03020310[0x16]);
            }
          }
          else {
            iVar9 = dmr_call_setup_block_d_byte5_read();
            if (iVar9 == 0) {
              modem_mode_select(PTR_DAT_03020310[1],2);
            }
            call_teardown_packet_build_and_history_push
                      (*puVar6,0,0,uVar11,*(undefined2 *)(puVar6 + 2),*(undefined2 *)(puVar6 + 4),
                       *(undefined4 *)(puVar6 + 0xc),*(undefined4 *)(puVar6 + 8),0);
          }
        }
      }
LAB_0302031e:
      if ((uVar8 & 2) != 0) {
        os_flag_post_clear_0300c8d4(2);
        OSFlagPost_wrapper_set_passthrough(0x200);
        if (puVar4[1] == '\x01') {
          osflag_pend_consume_with_decisecond_timeout_alt(0x100,0,0x78,&iStack_2c);
          os_flag_post_clear_0300c8d4(0x100);
          history_record_build_typed_dispatch
                    (0,1,puVar4[0x13],*(undefined4 *)(puVar4 + 0x30),*(undefined4 *)(puVar4 + 0x2c),
                     0,0);
        }
        clear_byte_field_dat03023b88_0x15();
      }
      if ((uVar8 & 4) != 0) {
        os_flag_post_clear_0300c8d4(4);
        *puVar6 = *puVar4;
        puVar6[1] = puVar4[1];
        *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(puVar4 + 0x34);
        *(undefined4 *)(puVar6 + 8) = *(undefined4 *)(puVar4 + 0x2c);
        *(undefined4 *)(puVar6 + 0xc) = *(undefined4 *)(puVar4 + 0x30);
        *(undefined4 *)(puVar6 + 0x10) = 9;
        if (8 < *(uint *)(puVar4 + 0x37c)) {
          *(uint *)(puVar6 + 0x14) = *(uint *)(puVar4 + 0x37c) - 9;
        }
        memcpy_bytes_iram(DAT_03020528,DAT_0302052c);
        sVar2 = puVar7[-0x13];
        if (puVar7[-0x12] != sVar2) {
          *(short *)(puVar4 + 0x36) = sVar2;
        }
        if (*puVar6 == '\0') {
          if (*(short *)(puVar4 + 0x36) != sVar2) {
            *(short *)(puVar4 + 0x36) = sVar2;
          }
          if (puVar6[1] == '\x01') {
            osflag_pend_consume_with_decisecond_timeout_alt(0x100,0,0x78,&iStack_2c);
            os_flag_post_clear_0300c8d4(0x100);
            history_record_build_typed_dispatch
                      (0,1,puVar4[0x13],*(undefined4 *)(puVar4 + 0x30),
                       *(undefined4 *)(puVar4 + 0x2c),0,0);
          }
          clear_byte_field_dat03023b88_0x15();
          OSTimeDly_ms_wrapper(0x1e0);
          if (PTR_DAT_03020530[0x1b] == '\x01') {
            call_setup_set_pending_flag();
            iVar9 = dmr_call_setup_block_d_byte5_read();
            if (iVar9 == 0) {
              modem_mode_select(0,2);
            }
            if (PTR_DAT_03020530[0x16] != '\0') {
              bVar13 = 0;
              do {
                if (bVar13 == 0) {
                  call_setup_packet_build_and_history_push
                            (*puVar6,1,0,uVar11,*(undefined2 *)(puVar6 + 2),
                             *(undefined2 *)(puVar4 + 0x38),*(undefined4 *)(puVar6 + 0xc),
                             *(undefined4 *)(puVar6 + 8),0);
                }
                osflag_pend_consume_with_decisecond_timeout_alt(0x80,0,iVar12,&iStack_2c);
                os_flag_post_clear_0300c8d4(0x80);
                iVar9 = noop_stub_0300c42c();
                if (iVar9 == iStack_2c) {
                  iVar9 = call_setup_state_machine_step(1,PTR_DAT_03020530[8],&uStack_25);
                  if (iVar9 != 0) break;
                  call_setup_packet_build_and_history_push
                            (*puVar6,1,0,uVar11,*(undefined2 *)(puVar6 + 2),
                             *(undefined2 *)(puVar4 + 0x38),*(undefined4 *)(puVar6 + 0xc),
                             *(undefined4 *)(puVar6 + 8),1);
                }
                else {
                  iVar9 = noop_stub_0300c434();
                  if (iVar9 == iStack_2c) {
                    cVar1 = puVar4[0x11];
                    if (cVar1 == '\0') break;
                    if (cVar1 == '\x01') {
                      if (puVar4[0x12] != '\x01') break;
                      dmr_history_bitmask_record_builder(PTR_DAT_03020530[0x22],1,0,0);
                    }
                    else if (cVar1 == '\x02') {
                      dmr_history_bitmask_record_builder
                                (PTR_DAT_03020530[0x22],0,DAT_0302052c,
                                 *(undefined1 *)(puVar7 + 0x191));
                    }
                  }
                }
                bVar13 = bVar13 + 1;
              } while (bVar13 < (byte)PTR_DAT_03020530[0x16]);
            }
          }
          else {
            iVar9 = dmr_call_setup_block_d_byte5_read();
            if (iVar9 == 0) {
              modem_mode_select(0,2);
            }
            call_setup_packet_build_and_history_push
                      (*puVar6,0,0,uVar11,*(undefined2 *)(puVar6 + 2),*(undefined2 *)(puVar4 + 0x38)
                       ,*(undefined4 *)(puVar6 + 0xc),*(undefined4 *)(puVar6 + 8),0);
            clear_byte_field_dat03023b88_0x15();
          }
        }
      }
      if ((uVar8 & 8) != 0) {
        os_flag_post_clear_0300c8d4(8);
        OSFlagPost_wrapper_set_passthrough(0x200);
        if (puVar4[1] == '\x01') {
          osflag_pend_consume_with_decisecond_timeout_alt(0x100,0,0x78,&iStack_2c);
          os_flag_post_clear_0300c8d4(0x100);
          history_record_build_typed_dispatch
                    (0,1,puVar4[0x13],*(undefined4 *)(puVar4 + 0x30),*(undefined4 *)(puVar4 + 0x2c),
                     0,0);
        }
        clear_byte_field_dat03023b88_0x15();
      }
      if (((uVar8 & 0x10) != 0) &&
         (os_flag_post_clear_0300c8d4(0x10), *(char *)(iVar5 + 0xf) == '\0')) {
        *puVar6 = *puVar4;
        puVar6[1] = puVar4[1];
        *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(puVar4 + 0x34);
        *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(puVar4 + 0x38);
        *(undefined4 *)(puVar6 + 8) = *(undefined4 *)(puVar4 + 0x2c);
        *(undefined4 *)(puVar6 + 0xc) = *(undefined4 *)(puVar4 + 0x30);
        uVar8 = *(uint *)(puVar4 + 0x37c);
        *(uint *)(puVar6 + 0x14) = uVar8;
        if (uVar8 < 600) {
          memcpy_bytes_iram(DAT_03020714,DAT_03020718);
          *(undefined1 *)PTR_DAT_0302071c = 0;
          if (*puVar7 == 0) {
            *(undefined1 *)(iVar3 + 2) = 1;
            ui_mode_group_flag_set_and_post(2,1);
          }
          else if (*(char *)(iVar3 + 2) == '\0') {
            *(undefined1 *)(iVar3 + 2) = 1;
            ui_mode_group_flag_set_and_post(2,1);
          }
        }
        if (*puVar6 == '\0') {
          if (puVar6[1] == '\x01') {
            osflag_pend_consume_with_decisecond_timeout_alt(0x100,0,0x78,&iStack_2c);
            os_flag_post_clear_0300c8d4(0x100);
            history_record_build_typed_dispatch
                      (0,1,puVar4[0x13],*(undefined4 *)(puVar4 + 0x30),
                       *(undefined4 *)(puVar4 + 0x2c),0,0);
          }
          clear_byte_field_dat03023b88_0x15();
        }
      }
    }
    else if ((puVar4[0x394] & 1) == 0) {
      os_flag_post_clear_0300c8d4(uVar8);
      osflag_pend_consume_with_decisecond_timeout_alt(0x100,0,0x78,&iStack_2c);
      os_flag_post_clear_0300c8d4(0x100);
      history_record_build_typed_dispatch
                (1,1,puVar4[0x13],*(undefined4 *)(puVar4 + 0x30),*(undefined4 *)(puVar4 + 0x2c),0,0)
      ;
    }
    else {
      os_flag_post_clear_0300c8d4(uVar8);
      osflag_pend_consume_with_decisecond_timeout_alt(0x100,0,0x78,&iStack_2c);
      os_flag_post_clear_0300c8d4(0x100);
      history_record_build_typed_dispatch
                (2,0,puVar4[0x13],*(undefined4 *)(puVar4 + 0x30),*(undefined4 *)(puVar4 + 0x2c),
                 puVar10,(byte)puVar4[0x3c] + 7 >> 3);
    }
    clear_byte_field_dat03023b88_0x15();
  } while( true );
}


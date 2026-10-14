/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rxvoice_task_entry @ 03020778 (file base 0x03000000; code starts at 0x03001000)
 * Size: 702 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void rxvoice_task_entry(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_39;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  
  puVar7 = PTR_DAT_03020a0c;
  iVar6 = DAT_03020a08;
  iVar5 = DAT_03020a04;
  puVar4 = PTR_DAT_03020a00;
  puVar3 = PTR_DAT_030209fc;
  do {
    *(undefined1 *)puVar3 = 0;
    clear_byte_field_dat03023b88_0x15();
    uVar9 = osflag_pend_consume_with_decisecond_timeout(0x40006807,0,0,auStack_28);
    *(undefined1 *)puVar3 = 1;
    call_setup_set_pending_flag();
    *(undefined1 *)((int)puVar4 + 9) = *(undefined1 *)(iVar5 + 0xb);
    bVar2 = *(byte *)(iVar6 + 2);
    puVar4[3] = *(undefined4 *)(iVar5 + (bVar2 + 6) * 4);
    puVar4[4] = *(undefined4 *)(iVar5 + (bVar2 + 8) * 4);
    if ((uVar9 & 0x2000) != 0) {
      os_flag_post_clear_0300c784(0x2000);
      history_slot_allocate_and_init(1,puVar4[4]);
      *(undefined1 *)puVar4 = 2;
      OSTimeDly_ms_wrapper(0x168);
      tx_voice_end_stop_tx_record();
    }
    if ((uVar9 & 0x800) != 0) {
      os_flag_post_clear_0300c784(0x800);
      if ((byte)PTR_DAT_03020a10[1] < 2) {
        mode_gated_field_copy_or_invert(0);
      }
      uStack_3c = 5;
      uStack_3b = 0;
      uStack_39 = 0x20;
      uStack_30 = puVar4[4];
      uStack_2c = puVar4[3];
      history_record_push_type3(&uStack_3c);
      *(undefined1 *)puVar4 = 1;
    }
    if ((uVar9 & 2) != 0) {
      os_flag_post_clear_0300c784(2);
      cVar1 = *(char *)(iVar5 + 8);
      *puVar7 = cVar1;
      bVar2 = *(byte *)(iVar6 + 2);
      iVar10 = *(int *)(iVar5 + (bVar2 + 6) * 4);
      *(int *)(puVar7 + 4) = iVar10;
      *(undefined4 *)(puVar7 + 8) = *(undefined4 *)(iVar5 + (bVar2 + 8) * 4);
      if (cVar1 == '\x01') {
        if (iVar10 - 1U < 0xfffcdf) {
          puVar7[1] = 1;
        }
        else if (iVar10 - 0xffffe0U < 0x10) {
          puVar7[1] = 2;
        }
        else if (iVar10 - 0xfffff0U < 0x10) {
          puVar7[1] = 3;
        }
      }
      else {
        puVar7[1] = 0;
      }
      *(undefined1 *)puVar4 = 1;
      *(undefined1 *)((int)puVar4 + 1) = 1;
      iVar10 = dmr_call_setup_block_d_byte5_read();
      if (iVar10 == 2) {
        modem_mode_select(0,1);
      }
      if ((*(byte *)(puVar4 + 6) & 4) == 0) {
        if ((*(byte *)PTR_DAT_03020a14 & 8) != 0) {
          tx_abort_on_condition();
        }
        if (((*(byte *)PTR_DAT_03020a18 & 0x40) == 0) ||
           (*(char *)((int)PTR_DAT_03020a18 + 3) != '\x06')) {
          ui_mode_group_flag_set_and_post(1,2);
          if ((*(byte *)((int)PTR_DAT_03020a18 + 1) & 3) == 0) {
            call_setup_sm_arm(*(byte *)(iVar5 + 8),1);
          }
          if (((*(char *)(PTR_DAT_03020a18 + 3) != '\x01') || ((*(byte *)(puVar4 + 6) & 0x80) == 0))
             && ((PTR_DAT_03020a1c[1] & 8) == 0)) {
            rx_voice_start_begin_record();
            if ((PTR_DAT_03020a20[5] & 2) != 0) {
              PTR_DAT_03020a20[5] = PTR_DAT_03020a20[5] & 0xfd;
            }
            audio_pa_enable_gate(1);
          }
        }
      }
    }
    if ((uVar9 & 4) != 0) {
      os_flag_post_clear_0300c784(4);
      *(undefined1 *)puVar4 = 0;
      if (PTR_DAT_03020a24[5] != '\0') {
        OSFlagPost_wrapper_set_fixed_grp(0x20000000);
      }
      rx_voice_end_stop_rx_record();
      modem_control_state_stop();
      *(undefined1 *)((int)puVar4 + 1) = 0;
      ui_group_flag_set_and_notify(1,1);
    }
    if ((uVar9 & 1) != 0) {
      os_flag_post_clear_0300c784(1);
      puVar8 = PTR_DAT_03020a28;
      bVar2 = *(byte *)(iVar6 + 2);
      iVar10 = iVar5 + (uint)bVar2 * 0xc;
      if ((*(char *)((int)PTR_DAT_03020a28 + 1) == *(char *)(iVar10 + 0x72)) &&
         (*(byte *)PTR_DAT_03020a28 == (*(byte *)(iVar10 + 0x70) & 7))) {
        *(undefined1 *)((int)PTR_DAT_03020a28 + 2) = 1;
        iVar10 = iVar5 + (uint)bVar2 * 0xc;
        *(undefined1 *)((int)puVar8 + 0x23) = *(undefined1 *)(iVar10 + 0x73);
        *(undefined1 *)(puVar8 + 9) = *(undefined1 *)(iVar10 + 0x74);
        *(undefined1 *)((int)puVar8 + 0x25) = *(undefined1 *)(iVar10 + 0x75);
        *(undefined1 *)((int)puVar8 + 0x26) = *(undefined1 *)(iVar10 + 0x76);
        FUN_0002b320(1);
      }
      else {
        PTR_DAT_03020bc0[2] = 0;
      }
    }
    if ((uVar9 & 0x4000) != 0) {
      os_flag_post_clear_0300c784(0x4000);
    }
    if ((uVar9 & 0x40000000) != 0) {
      os_flag_post_clear_0300c784(0x40000000);
      ui_mode_group_flag_set_and_post(8,2);
    }
    clear_byte_field_dat03023b88_0x15();
  } while( true );
}


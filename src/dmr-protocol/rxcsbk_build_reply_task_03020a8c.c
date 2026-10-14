/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: rxcsbk_build_reply_task @ 03020a8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 842 bytes
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

void rxcsbk_build_reply_task(void)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  undefined1 auStack_3c [4];
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_31;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  pbVar6 = p_dmr_status_flags;
  iVar5 = p_call_setup_sm_state_aux;
  iVar4 = _DAT_03020bd0;
  iVar3 = DAT_03020bcc;
  puVar2 = p_call_setup_sm_state;
  do {
    *(undefined1 *)(iVar3 + 1) = 0;
    clear_byte_field_dat03023b88_0x15();
    uVar7 = osflag_pend_consume_with_decisecond_timeout(0x7540000,0,0,auStack_3c);
    *(undefined1 *)(iVar3 + 1) = 1;
    call_setup_set_pending_flag();
    bVar1 = p_dmr_call_config_state[2];
    *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(iVar4 + (bVar1 + 8) * 4);
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(iVar4 + (bVar1 + 6) * 4);
    if (*(char *)(iVar5 + 1) == '\x04') {
      OSTimeDly_ms_wrapper(0x78);
    }
    else {
      OSTimeDly_ms_wrapper(0x3c);
    }
    if ((uVar7 & 0x40000) != 0) {
      os_flag_post_clear_0300c784(0x40000);
      if ((puVar2[0x18] & 2) == 0) {
        if ((*pbVar6 & 8) == 0) {
          uStack_38 = 0x26;
          uStack_37 = 0;
          pbVar6[1] = pbVar6[1] & 0xef;
        }
        else {
          uStack_38 = 0x24;
          uStack_37 = 0x10;
          uStack_36 = 0;
          uStack_31 = 0xfe;
          pbVar6[1] = pbVar6[1] & 0xef | 0x10;
        }
        pbVar6[3] = 4;
        uStack_2c = *(undefined4 *)(puVar2 + 0x10);
        uStack_28 = *(undefined4 *)(puVar2 + 0xc);
        history_record_push_type3(&uStack_38);
        tx_led_or_tone_off_conditional();
      }
      else {
        pbVar6[3] = 4;
        dialog_state_set_substate(6);
      }
      *puVar2 = 1;
    }
    if ((uVar7 & 0x100000) != 0) {
      os_flag_post_clear_0300c784(0x100000);
      if ((puVar2[0x18] & 2) == 0) {
        if ((*pbVar6 & 4) == 0) {
          uStack_38 = 0x26;
          uStack_37 = 0;
          pbVar6[1] = pbVar6[1] & 0xef;
        }
        else {
          uStack_38 = 0x24;
          uStack_37 = 0x10;
          uStack_36 = 0;
          uStack_31 = 0xff;
          pbVar6[1] = pbVar6[1] & 0xef | 0x10;
        }
        pbVar6[3] = 3;
        uStack_2c = *(undefined4 *)(puVar2 + 0x10);
        uStack_28 = *(undefined4 *)(puVar2 + 0xc);
        history_record_push_type3(&uStack_38);
        tx_led_or_tone_off_conditional();
      }
      else {
        pbVar6[3] = 3;
        dialog_state_set_substate(6);
      }
      *puVar2 = 1;
    }
    if ((uVar7 & 0x400000) != 0) {
      os_flag_post_clear_0300c784(0x400000);
      if ((puVar2[0x18] & 2) == 0) {
        if ((*pbVar6 & 0x10) == 0) {
          uStack_38 = 0x26;
          uStack_37 = 0;
          pbVar6[1] = pbVar6[1] & 0xef;
        }
        else {
          uStack_38 = 0x24;
          uStack_37 = 0x10;
          uStack_36 = 0;
          uStack_31 = 0x80;
          pbVar6[1] = pbVar6[1] & 0xef | 0x10;
        }
        pbVar6[3] = 5;
        uStack_2c = *(undefined4 *)(puVar2 + 0x10);
        uStack_28 = *(undefined4 *)(puVar2 + 0xc);
        history_record_push_type3(&uStack_38);
        tx_led_or_tone_off_conditional();
      }
      *puVar2 = 1;
    }
    if (((uVar7 & 0x1000000) != 0) && (os_flag_post_clear_0300c784(0x1000000), pbVar6[0xc] != 1)) {
      if ((puVar2[0x18] & 0x42) == 0x40) {
        uStack_38 = 0x20;
        uStack_37 = 0x10;
        uStack_35 = 0xa7;
        uStack_31 = 0;
        uStack_2c = *(undefined4 *)(puVar2 + 0x10);
        uStack_28 = *(undefined4 *)(iVar5 + 0x24);
        *(undefined4 *)(pbVar6 + 0x10) = *(undefined4 *)(puVar2 + 0xc);
        history_record_push_type3(&uStack_38);
        *puVar2 = 1;
        pbVar6[3] = 6;
        pbVar6[1] = pbVar6[1] & 0xef | 0x10;
        tx_led_or_tone_off_conditional();
      }
      else {
        *(undefined4 *)(pbVar6 + 0x10) = *(undefined4 *)(puVar2 + 0xc);
        *puVar2 = 1;
        pbVar6[3] = 6;
        dialog_state_set_substate(6);
      }
    }
    if ((uVar7 & 0x2000000) != 0) {
      os_flag_post_clear_0300c784(0x2000000);
      if ((puVar2[0x18] & 2) == 0) {
        if ((*pbVar6 & 1) == 0) {
          uStack_38 = 0x26;
          uStack_37 = 0;
          pbVar6[1] = pbVar6[1] & 0xef;
        }
        else {
          uStack_38 = 0x20;
          uStack_37 = 0x10;
          uStack_35 = 0x9f;
          uStack_31 = 0;
          pbVar6[1] = pbVar6[1] & 0xef | 0x10;
        }
        uStack_2c = *(undefined4 *)(puVar2 + 0x10);
        uStack_28 = *(undefined4 *)(puVar2 + 0xc);
        pbVar6[3] = 1;
        history_record_push_type3(&uStack_38);
        tx_led_or_tone_off_conditional();
      }
      else {
        pbVar6[3] = 1;
        dialog_state_set_substate(6);
      }
      *puVar2 = 1;
    }
    if (((uVar7 & 0x4000000) != 0) &&
       (os_flag_post_clear_0300c784(0x4000000), (puVar2[0x18] & 2) == 0)) {
      if ((*pbVar6 & 2) == 0) {
        uStack_38 = 0x26;
        uStack_37 = 0;
        pbVar6[1] = pbVar6[1] & 0xef;
      }
      else {
        uStack_38 = 0x20;
        uStack_37 = 0x10;
        uStack_35 = 0x9d;
        uStack_31 = 0;
        pbVar6[1] = pbVar6[1] & 0xef | 0x10;
      }
      pbVar6[3] = 2;
      uStack_2c = *(undefined4 *)(puVar2 + 0x10);
      uStack_28 = *(undefined4 *)(puVar2 + 0xc);
      history_record_push_type3(&uStack_38);
      *puVar2 = 2;
    }
    clear_byte_field_dat03023b88_0x15();
  } while( true );
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_log_writer_task_loop @ 0302df64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 394 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_log_writer_task_loop(void)

{
  void *flaggrp;
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *src;
  undefined1 auStack_28 [4];
  
  puVar5 = PTR_DAT_0302e108;
  iVar4 = DAT_0302e104;
  puVar3 = PTR_DAT_0302e100;
  puVar2 = PTR_DAT_0302e0fc;
  iVar1 = DAT_0302e0f8;
  flaggrp = DAT_0302e0f4;
  iVar9 = (int)PTR_DAT_0302e108 + 2;
  src = PTR_DAT_0302e0fc + 3;
  do {
    while( true ) {
      do {
        OSFlagPend_wrapper_consume(flaggrp,0x1000,0,0,auStack_28);
        OSFlagPost_wrapper_clr(flaggrp,0x1000);
        ptt_ui_state_machine_update();
        dialog_close_and_tx_release();
      } while ((*(byte *)(iVar1 + 7) & 0x20) != 0);
      if ((*(byte *)(puVar2 + 3) & 2) != 0) {
        memcpy_ck803s(&stack0xffffff7c,src,0x5c);
        flash_history_record_append_with_date(1,*puVar2,puVar2[1],puVar2[2]);
        *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0xfd;
      }
      if (((*(byte *)(puVar2 + 3) & 4) != 0) && (iVar7 = get_field_0301ea64_0x14(), iVar7 != 2)) {
        if ((*(byte *)(puVar2 + 3) & 0x10) == 0) {
          memcpy_ck803s(&stack0xffffff7c,src,0x5c);
          flash_history_record_append_with_date(3,*puVar2,puVar2[1],puVar2[2]);
        }
        else {
          memcpy_ck803s(&stack0xffffff7c,src,0x5c);
          flash_history_record_append_with_date(2,*puVar2,puVar2[1],puVar2[2]);
        }
        *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0xfb;
      }
      if ((*(byte *)(puVar2 + 3) & 0x20) != 0) {
        contact_edit_save_via_temp_buffer();
        *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0xdf;
      }
      if ((*(byte *)(puVar2 + 3) & 0x40) == 0) break;
      if ((PTR_DAT_0302e10c[1] & 0x80) != 0) {
        rda5807m_fm_off();
      }
      settings_set_menu_hold_interval(*(undefined1 *)(iVar4 + 0x3a));
      uVar8 = text_to_encoded_message_with_len_prefix_and_mode_branch
                        (puVar5[0xc9],DAT_0302e110,*(undefined2 *)puVar5,iVar9);
      *(short *)puVar5 = (short)uVar8;
      contact_edit_save_flow1(iVar9,uVar8,1,*(byte *)PTR_DAT_0302e114 >> 6);
      write_field_and_mbox_post(1,0x2e);
      *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0xbf;
    }
    if ((*(byte *)(puVar2 + 3) & 0x80) != 0) {
      if ((*puVar3 & 4) != 0) {
        settings_set_menu_hold_interval(*(undefined1 *)(iVar4 + 0x3a));
        uVar6 = record_build_value_plus_csv_field
                          (puVar5[0xc9],DAT_0302e110,*(undefined2 *)puVar5,iVar9);
        *(undefined2 *)puVar5 = uVar6;
        text_field_copy_and_status_write(0x1b,0x32,iVar9);
      }
      *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) & 0x7f;
    }
  } while( true );
}


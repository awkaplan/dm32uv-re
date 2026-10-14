/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: history_list_row_lookup @ 030396d0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 138 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void history_list_row_lookup(short param_1)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  undefined4 local_38;
  undefined1 auStack_34 [19];
  undefined1 auStack_21 [3];
  char cStack_1e;
  
  uVar3 = get_block0xb_u16_field0();
  local_38 = 0;
  if (uVar3 == 0) {
    write_status_mode_byte_pair
              (*(undefined1 *)((uint)p_dialog_history_ui_state->index_0x2 + DAT_030397e8),0);
  }
  else {
    sVar5 = 0;
    uVar4 = 1;
    do {
      history_record_lookup_by_type(2,uVar4,auStack_34);
      if ((cStack_1e != '\x05') && (sVar5 = sVar5 + 1, sVar5 == param_1)) break;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 <= uVar3);
    memcpy_bytes_iram(&local_38,auStack_21,3);
    uVar1 = p_text_entry_buffer;
    cVar2 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_030397dc = cVar2 + '\x01';
    channel_select_commit_and_notify
              (cStack_1e,local_38,uVar1,cVar2 + '\x01',p_dm32_settings_block04[0x54]);
  }
  return;
}


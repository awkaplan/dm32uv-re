/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_char_dispatcher_null_and_0x01 @ 030505a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 134 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_char_dispatcher_null_and_0x01(void)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  cVar2 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03050720 + 2);
  if (cVar2 == '\0') {
    history_list_row_lookup(*(short *)PTR_DAT_03050724 + 1);
  }
  else if (cVar2 == '\x01') {
    iVar3 = ascii_digits_to_uint();
    if (iVar3 == 0) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_03050728 + DAT_0305072c),0);
    }
    else {
      uVar4 = *p_text_entry_current_char_alias;
      *PTR_DAT_03050734 = uVar4;
      puVar1 = p_text_entry_buffer;
      if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
        uVar5 = 3;
      }
      else {
        uVar5 = 4;
      }
      cVar2 = strlen_ck803s(p_text_entry_buffer);
      *(char *)PTR_DAT_03050740 = cVar2 + '\x01';
      channel_select_commit_and_notify
                (uVar5,uVar4,puVar1,cVar2 + '\x01',p_dm32_settings_block04[0x54]);
    }
  }
  return;
}


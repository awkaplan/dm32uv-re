/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_entry_command_byte_router @ 0304f548 (file base 0x03000000; code starts at 0x03001000)
 * Size: 176 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_entry_command_byte_router(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_0304f610 + 2);
  if (cVar1 == '\0') {
    history_list_row_lookup(*(short *)PTR_DAT_0304f614 + 1);
  }
  else if (cVar1 == '\x01') {
    iVar2 = ascii_digits_to_uint();
    if (iVar2 == 0) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f600 + DAT_0304f604),0);
    }
    else {
      uVar4 = *p_text_entry_current_char_alias;
      *PTR_DAT_0304f61c = uVar4;
      if ((p_radio_mode_state_0003e318->flags_0x3 & 4) == 0) {
        uVar3 = 3;
      }
      else {
        uVar3 = 4;
      }
      channel_select_commit_and_notify
                (uVar3,uVar4,p_text_entry_buffer,*(undefined1 *)PTR_DAT_0304f624,
                 p_dm32_settings_block04[0x54]);
    }
  }
  else if (cVar1 == '\x02') {
    iVar2 = quick_text_insert_and_rewrap(*(undefined1 *)p_active_screen_state_word);
    if (iVar2 == 0) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f600 + DAT_0304f604),0);
    }
    else {
      history_queue_pop();
      history_queue_pop();
    }
  }
  else {
    write_status_mode_byte_pair(0x2a,1);
  }
  return;
}


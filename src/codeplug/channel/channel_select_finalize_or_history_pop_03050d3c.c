/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_select_finalize_or_history_pop @ 03050d3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 110 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void channel_select_finalize_or_history_pop(void)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char *)p_active_screen_state_word == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03050de0 + 2);
    if (cVar1 == '\0') {
      uVar2 = 1;
    }
    else if (cVar1 == '\x01') {
      uVar2 = 2;
    }
    else {
      uVar2 = 3;
    }
    uVar2 = flash_record_read_nth_entry(uVar2,p_menu_screen_state->index_0x3 + 1);
    *PTR_DAT_03050de4 = uVar2;
    channel_select_commit_and_notify
              (3,uVar2,p_text_entry_buffer,*(undefined1 *)PTR_DAT_03050dc8,
               p_dm32_settings_block04[0x54]);
  }
  else if (*(char *)p_active_screen_state_word == '\x01') {
    write_status_mode_byte_pair(0x31,1);
  }
  else {
    history_queue_pop();
    history_queue_pop();
  }
  return;
}


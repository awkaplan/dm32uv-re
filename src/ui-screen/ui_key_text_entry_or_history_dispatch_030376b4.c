/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ui_key_text_entry_or_history_dispatch @ 030376b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 98 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ui_key_text_entry_or_history_dispatch(void)

{
  char cVar1;
  
  cVar1 = *(char *)PTR_active_screen_subtype_03037800;
  if ((cVar1 == '\b') || (cVar1 == '\n')) {
    text_entry_enter_backspace_dispatch();
  }
  else if (cVar1 == '/') {
    if ((PTR_DAT_03037804[3] & 0x80) != 0) {
      PTR_DAT_03037804[3] = PTR_DAT_03037804[3] & 0x7f;
    }
    *(undefined1 *)PTR_active_screen_state_word_03037808 = 0;
    PTR_DAT_03037804[4] = PTR_DAT_03037804[4] & 0xfe;
    ui_event_notify_alt(8);
    write_status_mode_byte_pair(0,1);
  }
  else {
    *(undefined1 *)PTR_DAT_0303780c = 0;
    history_queue_pop();
  }
  return;
}


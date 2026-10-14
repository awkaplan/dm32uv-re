/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_edit_mode_0x02_save_or_pop @ 0304f1b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 66 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void contact_edit_mode_0x02_save_or_pop(void)

{
  int iVar1;
  
  if (*(char *)p_active_screen_state_word == '\x02') {
    iVar1 = contact_edit_validate_and_save();
    if (iVar1 == 0) {
      write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0304f2e0 + DAT_0304f2e4),3);
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


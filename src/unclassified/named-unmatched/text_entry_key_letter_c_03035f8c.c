/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: text_entry_key_letter_c @ 03035f8c (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void text_entry_key_letter_c(void)

{
  if ((PTR_DAT_03036098[5] & 0x10) == 0) {
    *(undefined1 *)PTR_DAT_0303609c = 0x43;
    dtmf_quicktext_scroll_display_dispatch();
    write_status_mode_byte_pair(0x70,0);
  }
  else {
    write_status_mode_byte_pair(0x70,0);
    write_flag_and_notify_ui_event0x29(0xc);
    text_input_append_byte_and_scroll(0x43);
    display_format_id_with_separators();
  }
  return;
}


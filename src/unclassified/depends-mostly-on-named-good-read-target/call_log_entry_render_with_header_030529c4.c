/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_log_entry_render_with_header @ 030529c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 108 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_log_entry_render_with_header(void)

{
  undefined1 local_1c [20];
  
  if ((PTR_DAT_03052b28[1] & 3) == 1) {
    local_1c[0] = 4;
  }
  else if ((PTR_DAT_03052b28[1] & 3) == 2) {
    local_1c[0] = 5;
  }
  else {
    local_1c[0] = 3;
  }
  contact_name_lookup_or_format
            (p_vfo_display_state->flags_0x8 >> 4,*p_text_entry_current_char_alias,local_1c,
             local_1c[0]);
  display_draw_string_wrapped(0x20,5,p_text_entry_buffer,0);
  display_clear_status_row(0,0);
  display_draw_number_centered(1,0xffff,0,(uint)local_1c);
  dialog_header_draw_two_lines();
  return;
}


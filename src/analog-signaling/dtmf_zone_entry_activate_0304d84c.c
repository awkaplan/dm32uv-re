/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_zone_entry_activate @ 0304d84c (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dtmf_zone_entry_activate(void)

{
  int iVar1;
  
  if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304d998 + 2) == '\x01') {
    if (*(char *)p_active_screen_state_word == '\0') {
      dialog_show_icon_and_number_from_ptr();
      settings_write_dispatcher(0x32,p_menu_screen_state->index_0x3);
      zone_record_read(p_vfo_display_state->flags_0x9 & 0x3f);
      if ((p_vfo_freq_display_state->field_0x1 < 2) &&
         (iVar1 = get_current_mode_state1(), iVar1 != 0)) {
        dtmf_digit_input_handler(0);
      }
    }
    else {
      write_status_mode_byte_pair(0x23,1);
    }
  }
  return;
}


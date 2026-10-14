/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scanlist_membership_remove_or_prompt @ 03050b30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 106 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void scanlist_membership_remove_or_prompt(void)

{
  if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03050c2c + 2) == '\x01') {
    if (p_menu_screen_state->index_0x5 < p_vfo_freq_display_state->field_0x1) {
      if (*(char *)p_active_screen_state_word == '\x01') {
        scanlist_channel_membership_remove
                  (*(undefined1 *)PTR_DAT_03050c38,p_menu_screen_state->index_0x5 + 1);
        dialog_show_icon_and_number
                  (1,**(undefined4 **)
                       (PTR_PTR_03050c3c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
      }
      else if (*(char *)p_active_screen_state_word == '\0') {
        write_status_mode_byte_pair(0x31,1);
      }
    }
    else {
      channel_lock_icon_update(*(undefined1 *)PTR_DAT_03050c38,*(short *)PTR_DAT_03050c40 + 1);
    }
  }
  return;
}


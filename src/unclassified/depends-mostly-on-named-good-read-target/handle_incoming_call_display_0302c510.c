/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: handle_incoming_call_display @ 0302c510 (file base 0x03000000; code starts at 0x03001000)
 * Size: 104 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: unclassified
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void handle_incoming_call_display(void)

{
  if ((p_tx_ptt_ui_state->flags_0xb & 0x10) == 0) {
    if ((*(byte *)p_call_active_flag & 0x80) != 0) {
      dialog_show_icon_and_two_numbers
                (0x30,0x30,PTR_DAT_0302c664,
                 **(undefined4 **)
                   (PTR_PTR_0302c65c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8),
                 PTR_LAB_0302c660);
      ui_event_notify(0x1b);
      *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0x7f;
    }
  }
  else {
    incoming_call_display_screen();
    p_tx_ptt_ui_state->flags_0xb = p_tx_ptt_ui_state->flags_0xb & 0xef;
  }
  return;
}


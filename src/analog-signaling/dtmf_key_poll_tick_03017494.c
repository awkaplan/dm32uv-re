/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dtmf_key_poll_tick @ 03017494 (file base 0x03000000; code starts at 0x03001000)
 * Size: 158 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dtmf_key_poll_tick(void)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  
  bVar3 = p_vfo_display_state->flags_0x8 >> 4;
  if (((p_radio_mode_state_0003e318->flags_0x3 & 0x40) == 0) &&
     (iVar2 = poll_condition_group(0x11), iVar2 != 0)) {
    iVar2 = get_current_mode_state1();
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else if (iVar2 == 3) {
      if ((p_vfo_freq_display_state->flags_0x10 & 0x18) == 0) {
        dtmf_digit_input_handler(6);
        channel_load_synchronized(*(undefined2 *)&p_vfo_freq_display_state->field_0x6,8);
        bVar3 = p_vfo_display_state->flags_0x8 >> 4;
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = true;
    }
    if ((bVar3 == 0) && (bVar1)) {
      if (p_radio_mode_state_0003e318[1].flags_0x2 == 0) {
        ptt_preamble_end_ui_audio_setup_2();
      }
      else {
        tx_timeout_cleanup();
      }
      if ((*(char *)PTR_DAT_03017544 == '\0') || (*(char *)PTR_DAT_03017544 == '[')) {
        display_draw_status_bar();
      }
    }
    else {
      ui_event_notify(0x21);
    }
  }
  return;
}


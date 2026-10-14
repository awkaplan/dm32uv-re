/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_release_handler @ 0305dc40 (file base 0x03000000; code starts at 0x03001000)
 * Size: 84 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ptt_release_handler(void)

{
  int iVar1;
  
  iVar1 = keypad_dispatch_not_inhibited();
  if (iVar1 != 0) {
    clear_bit1_set_bit2_and_dialog_state();
    if ((PTR_DAT_0305dd8c[1] & 0x80) != 0) {
      rda5807m_fm_off();
    }
    key_event_state_clear_preserve_bit0();
    iVar1 = get_current_mode_state1();
    if (iVar1 != 0) {
      dtmf_digit_input_handler(0xb);
    }
    tx_led_or_tone_off();
    tx_led_or_tone_on();
    audio_pa_enable_gate(0);
    call_setup_sm_reset();
    settings_write_0xf00_wrapper(0xa5);
    write_field_and_mbox_post(3,100);
  }
  return;
}


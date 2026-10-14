/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_timeout_cleanup @ 0305fc24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 114 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_timeout_cleanup(void)

{
  if (p_radio_mode_state_0003e318[1].flags_0x2 != 0) {
    if (((*(byte *)p_call_active_flag & 4) == 0) && ((p_vfo_display_state->flags_0x8 & 0xf0) == 0))
    {
      fd6818b_reg47_afout_clear_mode();
      audio_pa_enable_gate(0);
      audio_ctrl_fm_play_set(0);
      tx_led_or_tone_off();
      status_byte_bit5_set_clear_wrapper(0,1);
    }
    if ((*(char *)PTR_DAT_0305fd6c == '\0') || (*(char *)PTR_DAT_0305fd6c == '[')) {
      display_fill_rect(0xa1,0,0xb3,0x1a,0);
    }
    p_radio_mode_state_0003e318[1].flags_0x2 = 0;
  }
  return;
}


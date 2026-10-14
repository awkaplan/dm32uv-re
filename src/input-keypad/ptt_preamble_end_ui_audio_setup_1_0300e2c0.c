/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_preamble_end_ui_audio_setup_1 @ 0300e2c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 160 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ptt_preamble_end_ui_audio_setup_1(void)

{
  if ((*(byte *)p_call_active_flag & 4) == 0) {
    status_byte_bit5_set_clear_wrapper(0,0);
    if ((*PTR_DAT_0300e3ec & 0x18000) != 0x8000) {
      fd6818b_reg47_tx_bypass_or_rx_afout();
      audio_pa_enable_gate(1);
    }
    *PTR_DAT_0300e3f4 = (uint)(byte)p_dm32_settings_block04[0x58];
    if ((PTR_DAT_0300e3f8[3] & 1) != 0) {
      PTR_DAT_0300e3f8[3] = PTR_DAT_0300e3f8[3] & 0xbf | 0x40;
      PTR_DAT_0300e3fc[0x21] = 0;
      tone_or_volume_step_lookup(*(undefined1 *)PTR_DAT_0300e400);
    }
    settings_set_menu_hold_interval(p_dm32_settings_block04[0x3a]);
    pending_request_set_code(1);
    display_refresh_tone_mode_icon();
    if ((*(byte *)PTR_DAT_0300e3ec & 2) == 0) {
      noop_stub_0301a5d0(PTR_DAT_0300e404[1] & 1);
    }
    *(byte *)p_call_active_flag = *(byte *)p_call_active_flag & 0xfb | 4;
  }
  return;
}


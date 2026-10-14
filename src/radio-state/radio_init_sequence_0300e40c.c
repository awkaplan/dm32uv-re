/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: radio_init_sequence @ 0300e40c (file base 0x03000000; code starts at 0x03001000)
 * Size: 144 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void radio_init_sequence(void)

{
  ushort uVar1;
  byte bVar2;
  
  antenna_switch_select_gpio_24_22(0);
  config_table_init_entries_0300f050();
  config_table_init_entries_0300f03c();
  config_table_entry_0x24();
  pa_band_select_vhf_uhf_gpio(1);
  uVar1 = *(ushort *)&p_vfo_display_state->field_0x13_0;
  bVar2 = tone_signaling_type_classify(uVar1);
  bVar2 = bVar2 & 3;
  PTR_DAT_0300e5c0[0x35] = PTR_DAT_0300e5c0[0x35] & 0xfc | bVar2;
  if (bVar2 == 0) {
    ctcss_dcs_tone_apply(0,0xffff);
  }
  else if (bVar2 == 1) {
    ctcss_dcs_tone_apply(1,uVar1);
  }
  else if (bVar2 == 2) {
    ctcss_dcs_tone_apply(2,uVar1 & 0x7ff);
  }
  else {
    ctcss_dcs_tone_apply(3,uVar1 & 0x7ff);
  }
  fd6818b_reg_write_wrapper();
  fd6818b_retune_and_reinit_sequence(*PTR_DAT_0300e5c4);
  tx_audio_dac_envelope_ramp(1,1,PTR_DAT_0300e5c0[0x28]);
  return;
}


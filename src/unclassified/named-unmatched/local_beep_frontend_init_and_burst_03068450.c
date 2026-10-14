/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: local_beep_frontend_init_and_burst @ 03068450 (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void local_beep_frontend_init_and_burst(void)

{
  int_to_double_divide_convert(800);
  audio_pa_enable_gate(1);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0xc000);
  if ((p_radio_mode_state_0003e318[2].flags_0x2 & 0x20) == 0) {
    fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0);
    fd6818b_reg_write(FD6818_PAGE0_REG_0X30,0x302);
  }
  else {
    config_table_init_group1();
  }
  fd6818b_reg50_write_3b18();
  fd6818b_reg47_write_byte_or_6042(3);
  busy_wait_delay_n_units(800);
  fd6818b_reg47_afout_clear_mode();
  busy_wait_delay_n_units(0x32);
  int_to_double_divide_convert(800);
  fd6818b_reg47_write_byte_or_6042(3);
  busy_wait_delay_n_units(800);
  audio_pa_enable_gate(0);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
  fd6818b_reg47_afout_clear_mode();
  fd6818b_reg50_tx_audio_mute_set();
  if ((p_radio_mode_state_0003e318[2].flags_0x2 & 0x20) == 0) {
    fd6818b_filter_select_then_chipmode_normal();
  }
  else {
    fd6818b_init_seq_filter_ctcss_chipmode();
  }
  return;
}


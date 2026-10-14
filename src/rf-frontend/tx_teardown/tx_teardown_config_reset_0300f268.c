/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_teardown_config_reset @ 0300f268 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rf-frontend
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void tx_teardown_config_reset(void)

{
  fd6818b_reg50_write_bb18();
  config_table_entry_0x30();
  fd6818b_reg47_write_byte_or_6042(0);
  fd6818b_reg_write(FD6818_PAGE0_REG_70H,0);
  config_table_entry_0x24();
  fd6818b_filter_select_then_chipmode_normal();
  audio_pa_enable_gate(0);
  audio_ctrl_fm_play_set(0);
  p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xfd;
  return;
}


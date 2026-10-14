/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_change_apply_squelch @ 0300df08 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_change_apply_squelch(void)

{
  undefined1 *puVar1;
  
  hw_register_0x78_write_from_byte_pair(*(undefined1 *)(PTR_DAT_0300df4c + 1));
  rf_retune_and_apply_channel_mode(PTR_DAT_0300df50[1]);
  puVar1 = PTR_DAT_0300df58;
  if ((p_radio_mode_state_0003e318[1].flags_0x7 & 0x20) != 0) {
    zero_fields_by_index_pair(PTR_DAT_0300df58[1] & 1);
    rf_agc_step_adaptive_control_loop(puVar1[1] & 1);
  }
  antenna_switch_select_gpio_24_22(1);
  return;
}


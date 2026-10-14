/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_display_config_apply @ 0300dd94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void vfo_display_config_apply(void)

{
  undefined1 uVar1;
  
  uVar1 = flash_field_read_signed_select(*(undefined4 *)&p_vfo_display_state->field_0x4_0,0x670);
  if ((PTR_DAT_0300de04[0x35] & 3) == 0) {
    PTR_DAT_0300de04[0x2d] = uVar1;
    rf_mode_config_entry_0x51_apply(4);
  }
  else if ((PTR_DAT_0300de04[0x35] & 3) == 1) {
    config_table_entry_dispatch(4);
  }
  else {
    config_table_entry_dispatch(0);
  }
  busy_wait_delay_n_units(300);
  return;
}


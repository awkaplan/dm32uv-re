/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_mode9_poll_toggle_vfo_bit4 @ 03015de0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 124 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_mode9_poll_toggle_vfo_bit4(void)

{
  int iVar1;
  
  scan_entry_get_mode_bits(9);
  if ((PTR_DAT_03015f8c[3] & 0x40) == 0) {
    iVar1 = poll_condition_group(9);
    tx_timeout_cleanup();
    if (iVar1 == 0) {
      if ((*(byte *)PTR_call_active_flag_03015f98 & 10) == 0) {
        ui_event_notify(0x21);
      }
    }
    else {
      if ((PTR_DAT_03015f90[0x30] & 1) == 0) {
        ui_event_notify(0x18);
        vfo_field_write_bit4_at_0x15(1);
      }
      else {
        ui_event_notify(0x19);
        vfo_field_write_bit4_at_0x15(0);
      }
      if (*(char *)PTR_DAT_03015f94 == '\0') {
        vfo_standby_row_render((byte)PTR_DAT_03015f90[0x2d] >> 7);
      }
    }
  }
  return;
}


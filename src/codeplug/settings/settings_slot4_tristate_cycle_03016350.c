/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_slot4_tristate_cycle @ 03016350 (file base 0x03000000; code starts at 0x03001000)
 * Size: 130 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_slot4_tristate_cycle(void)

{
  int iVar1;
  
  scan_entry_get_mode_bits(5);
  if ((((PTR_DAT_03016498[3] & 0x40) == 0) && (*(char *)PTR_DAT_0301649c == '\0')) &&
     (iVar1 = poll_condition_group(5), iVar1 != 0)) {
    tx_timeout_cleanup();
    iVar1 = settings_read_dispatcher(4);
    if (iVar1 == 2) {
      ui_event_notify(0x19);
      settings_write_dispatcher(4,0);
    }
    else if (iVar1 == 1) {
      ui_event_notify(0x18);
      settings_write_dispatcher(4,2);
    }
    else {
      ui_event_notify(0x18);
      settings_write_dispatcher(4,1);
    }
    if (*(char *)PTR_DAT_030164a0 == '\0') {
      vfo_standby_row_render((byte)PTR_DAT_030164a4[0x2d] >> 7);
    }
  }
  return;
}


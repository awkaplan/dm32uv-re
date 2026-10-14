/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: gps_refresh_gated_by_tx_state @ 03015824 (file base 0x03000000; code starts at 0x03001000)
 * Size: 154 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: gps
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void gps_refresh_gated_by_tx_state(void)

{
  int iVar1;
  
  if ((PTR_DAT_0301595c[3] & 2) == 0) {
    if ((*(byte *)PTR_DAT_03015960 & 4) == 0) {
      ui_event_notify(0x21);
    }
    else {
      iVar1 = tx_is_inhibited();
      if ((iVar1 == 0) && ((PTR_DAT_03015964[0x10] & 0x80) == 0)) {
        iVar1 = scan_entry_get_mode_bits(0x1d);
        if ((((*(byte *)PTR_DAT_03015968 & 0x40) == 0) && ((*(byte *)PTR_DAT_0301596c & 4) == 0)) ||
           (((*(byte *)PTR_DAT_0301596c & 1) == 0 ||
            ((((iVar1 != 1 && (iVar1 != 3)) || (iVar1 = get_current_mode_state1(), iVar1 != 0)) ||
             ((PTR_DAT_03015964[7] & 0x18) != 0)))))) {
          ui_event_notify(0x1b);
        }
        else {
          ui_event_notify(0x1a);
          gps_display_refresh_and_notify();
        }
      }
    }
  }
  return;
}


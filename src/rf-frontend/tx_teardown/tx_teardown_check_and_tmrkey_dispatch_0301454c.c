/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_teardown_check_and_tmrkey_dispatch @ 0301454c (file base 0x03000000; code starts at 0x03001000)
 * Size: 54 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_teardown_check_and_tmrkey_dispatch(void)

{
  if (((PTR_DAT_03014604[5] & 0x10) != 0) && ((PTR_DAT_03014604[6] & 2) != 0)) {
    tx_teardown_config_reset();
  }
  if ((*(byte *)PTR_call_active_flag_0301460c & 8) == 0) {
    keypad_tmrkey_state_dispatch();
  }
  return;
}


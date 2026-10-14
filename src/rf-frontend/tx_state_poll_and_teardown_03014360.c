/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_state_poll_and_teardown @ 03014360 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_state_poll_and_teardown(void)

{
  if ((*PTR_DAT_030144a8 != 0) && (*(byte *)PTR_DAT_030144ac < 200)) {
    write_field_and_mbox_post(2,6);
    *PTR_DAT_030144a8 = 0;
  }
  if (((PTR_DAT_030144b0[5] & 0x10) != 0) && ((PTR_DAT_030144b0[6] & 2) != 0)) {
    tx_teardown_config_reset();
  }
  return;
}


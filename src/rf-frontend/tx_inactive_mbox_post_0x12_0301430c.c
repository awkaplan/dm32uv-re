/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_inactive_mbox_post_0x12 @ 0301430c (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_inactive_mbox_post_0x12(void)

{
  if (((PTR_DAT_0301435c[5] & 0x10) == 0) || ((PTR_DAT_0301435c[6] & 2) == 0)) {
    if (*(byte *)PTR_DAT_03014348 < 200) {
      write_field_and_mbox_post(2,0x12);
    }
  }
  else {
    tx_teardown_config_reset();
  }
  return;
}


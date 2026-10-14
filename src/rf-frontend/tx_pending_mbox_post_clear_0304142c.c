/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_pending_mbox_post_clear @ 0304142c (file base 0x03000000; code starts at 0x03001000)
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

void tx_pending_mbox_post_clear(void)

{
  if ((*(char *)PTR_DAT_03041554 == 'T') &&
     (write_field_and_mbox_post(1,0x26), (PTR_DAT_03041558[8] & 0x40) != 0)) {
    PTR_DAT_03041558[8] = PTR_DAT_03041558[8] & 0xbf;
    if ((PTR_DAT_0304155c[1] != '\0') && (PTR_DAT_0304155c[1] != '\x03')) {
      PTR_DAT_0304155c[1] = 1;
    }
  }
  return;
}


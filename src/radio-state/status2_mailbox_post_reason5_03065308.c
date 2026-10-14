/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status2_mailbox_post_reason5 @ 03065308 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: radio-state
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

undefined4 status2_mailbox_post_reason5(void)

{
  *(undefined1 *)PTR_active_screen_subtype_03065430 = 2;
  PTR_DAT_03065434[1] = 5;
  write_field_and_mbox_post(1,0x18);
  return 1;
}


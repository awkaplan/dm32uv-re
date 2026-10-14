/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: alert_code_post_0xc @ 030653b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: audio
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 alert_code_post_0xc(void)

{
  *(undefined1 *)PTR_active_screen_subtype_03065430 = 2;
  PTR_DAT_03065434[1] = 0xc;
  write_field_and_mbox_post(1,0x18);
  return 1;
}


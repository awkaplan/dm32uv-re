/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: status_mode_write_from_indexed_field_c @ 03050438 (file base 0x03000000; code starts at 0x03001000)
 * Size: 22 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void status_mode_write_from_indexed_field_c(void)

{
  write_status_mode_byte_pair(*(undefined1 *)((uint)*DAT_0305056c + DAT_03050570),0);
  return;
}


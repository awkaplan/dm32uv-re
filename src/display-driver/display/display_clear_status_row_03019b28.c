/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_clear_status_row @ 03019b28 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_clear_status_row(short param_1,ushort param_2)

{
  if (param_1 == 0) {
    display_fill_rect(0,0,0xf0,0x1a,param_2);
  }
  else {
    display_fill_rect(0,param_1,0xe5,param_1 + 0x18,param_2);
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: clear_two_state_bytes_03029fc8 @ 03029f30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 12 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void clear_two_state_bytes_03029fc8(void)

{
  *(undefined1 *)PTR_DAT_03029fc8 = 0;
  *(undefined1 *)PTR_DAT_03029fcc = 0;
  return;
}


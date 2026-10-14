/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: update_event_flags_byte14 @ 0300cf7c (file base 0x03000000; code starts at 0x03001000)
 * Size: 14 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: accessors
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void update_event_flags_byte14(undefined4 param_1,byte param_2)

{
  PTR_DAT_0300d024[0x60e] = PTR_DAT_0300d024[0x60e] & ~param_2;
  return;
}


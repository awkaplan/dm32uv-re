/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_set_window @ 03017c38 (file base 0x03000000; code starts at 0x03001000)
 * Size: 24 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_set_window(ushort param_1,ushort param_2,ushort param_3,ushort param_4)

{
  display_set_x_window(param_1,param_3);
  display_set_y_window(param_2,param_4);
  return;
}


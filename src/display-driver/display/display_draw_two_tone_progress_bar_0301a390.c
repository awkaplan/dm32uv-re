/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_draw_two_tone_progress_bar @ 0301a390 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_draw_two_tone_progress_bar(short param_1,short param_2,uint param_3,uint param_4)

{
  short x1;
  
  x1 = ((ushort)(((param_3 & 0xffff) * 0x9e) / (param_4 & 0xffff)) & 0xff) + 0x29;
  display_fill_rect(0x29,param_1,x1,param_2 + param_1,0x7e0);
  display_fill_rect(x1,param_1,199,param_2 + param_1,0xffff);
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_clear_channel_row_background @ 03019b60 (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_clear_channel_row_background(int param_1__w)

{
  char param_1 = (char)param_1__w;
  short sVar1;
  
  if (param_1 == '\0') {
    sVar1 = 0x3b;
  }
  else {
    sVar1 = 0xb1;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    display_fill_rect(8,0x56,0xef,0x74,0);
  }
  else {
    display_fill_rect(8,sVar1 + -5,0xef,sVar1 + 0x23,0);
  }
  return;
}


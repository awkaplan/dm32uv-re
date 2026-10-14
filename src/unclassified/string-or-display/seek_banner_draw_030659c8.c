/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: seek_banner_draw @ 030659c8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void seek_banner_draw(char param_1)

{
  short sVar1;
  
  if (param_1 == '\0') {
    sVar1 = 0x3b;
  }
  else {
    sVar1 = 0xb1;
  }
  if (p_dm32_settings_block04[0x6c] == '\0') {
    sVar1 = 0x59;
  }
  display_fill_rect(10,sVar1 + 0x2d,0xe3,sVar1 + 0x48,0);
  display_draw_number_centered(sVar1 + 0x2d,0xffff,0,(uint)PTR_s_Seek____03065b48);
  return;
}


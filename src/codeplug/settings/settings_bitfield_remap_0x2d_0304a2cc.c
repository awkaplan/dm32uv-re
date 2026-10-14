/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_bitfield_remap_0x2d @ 0304a2cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_bitfield_remap_0x2d(void)

{
  byte bVar1;
  
  if ((p_dm32_settings_block04[0x2d] & 0x80) == 0) {
    bVar1 = p_dm32_settings_block04[0x2d];
    p_dm32_settings_block04[0x2d] = bVar1 & 0xdb | (bVar1 & 1) << 2 | (bVar1 >> 3 & 1) << 5;
    p_radio_mode_state_0003e318[2].field_0x1 =
         p_radio_mode_state_0003e318[2].field_0x1 & 0xfb |
         (p_radio_mode_state_0003e318[2].field_0x1 & 1) << 2;
  }
  else {
    bVar1 = p_dm32_settings_block04[0x2d];
    p_dm32_settings_block04[0x2d] = bVar1 & 0xdb | (bVar1 >> 1 & 1) << 2 | (bVar1 >> 4 & 1) << 5;
    p_radio_mode_state_0003e318[2].field_0x1 =
         p_radio_mode_state_0003e318[2].field_0x1 & 0xfb |
         (p_radio_mode_state_0003e318[2].field_0x1 >> 1 & 1) << 2;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_apply_active_side_config @ 030641f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_apply_active_side_config(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = p_dm32_settings_block04;
  if ((PTR_DAT_03064328[1] & 1) == 0) {
    p_dm32_settings_block04[0x26] = p_dm32_settings_block04[0x27];
    puVar2[0x2d] = puVar2[0x2d] & 0xfb | (puVar2[0x2d] & 1) << 2;
    bVar1 = p_radio_mode_state_0003e318[2].field_0x1 & 1;
    p_radio_mode_state_0003e318[2].field_0x1 =
         p_radio_mode_state_0003e318[2].field_0x1 & 0xfb | bVar1 << 2;
    if (bVar1 != 0) {
      p_dm32_settings_block04[0x26] = p_dm32_settings_block04[0x2a];
    }
  }
  else {
    p_dm32_settings_block04[0x26] = p_dm32_settings_block04[0x28];
    puVar2[0x2d] = puVar2[0x2d] & 0xfb | ((byte)puVar2[0x2d] >> 1 & 1) << 2;
    bVar1 = p_radio_mode_state_0003e318[2].field_0x1 >> 1;
    p_radio_mode_state_0003e318[2].field_0x1 =
         p_radio_mode_state_0003e318[2].field_0x1 & 0xfb | (bVar1 & 1) << 2;
    if ((bVar1 & 1) != 0) {
      p_dm32_settings_block04[0x26] = p_dm32_settings_block04[0x2b];
    }
  }
  ui_event_notify_alt(0x12);
  return;
}


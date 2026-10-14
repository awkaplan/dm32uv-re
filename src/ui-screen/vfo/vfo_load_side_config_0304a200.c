/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_load_side_config @ 0304a200 (file base 0x03000000; code starts at 0x03001000)
 * Size: 188 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_load_side_config(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = p_dm32_settings_block04;
  if ((*(byte *)((int)p_dm32_settings_block04 + 0x2d) & 0x80) == 0) {
    *(undefined1 *)((int)p_dm32_settings_block04 + 0x26) =
         *(undefined1 *)((int)p_dm32_settings_block04 + 0x27);
    *(undefined1 *)(puVar2 + 0xb) = *(undefined1 *)((int)puVar2 + 0x12);
    *(undefined1 *)((int)puVar2 + 0x29) = *(undefined1 *)puVar2;
    bVar1 = *(byte *)((int)puVar2 + 0x2d);
    *(byte *)((int)puVar2 + 0x2d) =
         bVar1 & 0x9b | (byte)((bVar1 & 1) << 2) | (bVar1 >> 3 & 1) << 5 | (byte)((bVar1 & 1) << 6);
    bVar1 = p_radio_mode_state_0003e318[2].field_0x1 & 1;
    p_radio_mode_state_0003e318[2].field_0x1 =
         p_radio_mode_state_0003e318[2].field_0x1 & 0xfb | bVar1 << 2;
    if (bVar1 != 0) {
      *(undefined1 *)((int)p_dm32_settings_block04 + 0x26) =
           *(undefined1 *)((int)p_dm32_settings_block04 + 0x2a);
    }
  }
  else {
    *(undefined1 *)((int)p_dm32_settings_block04 + 0x26) =
         *(undefined1 *)(p_dm32_settings_block04 + 10);
    *(undefined1 *)(puVar2 + 0xb) = *(undefined1 *)((int)puVar2 + 0x25);
    *(undefined1 *)((int)puVar2 + 0x29) = *(undefined1 *)((int)puVar2 + 0x13);
    bVar1 = *(byte *)((int)puVar2 + 0x2d);
    uVar3 = bVar1 >> 1 & 1;
    *(byte *)((int)puVar2 + 0x2d) =
         bVar1 & 0x9b | (byte)(uVar3 << 2) | (bVar1 >> 4 & 1) << 5 | (byte)(uVar3 << 6);
    bVar1 = p_radio_mode_state_0003e318[2].field_0x1 >> 1;
    p_radio_mode_state_0003e318[2].field_0x1 =
         p_radio_mode_state_0003e318[2].field_0x1 & 0xfb | (bVar1 & 1) << 2;
    if ((bVar1 & 1) != 0) {
      *(undefined1 *)((int)p_dm32_settings_block04 + 0x26) =
           *(undefined1 *)((int)p_dm32_settings_block04 + 0x2b);
    }
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_exit_dual_watch_and_refresh @ 03064280 (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-screen
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void vfo_exit_dual_watch_and_refresh(void)

{
  undefined1 *puVar1;
  
  if ((PTR_DAT_03064338[8] & 1) == 0) {
    set_flag_byte_03064328(4);
    puVar1 = PTR_DAT_0306432c;
    PTR_DAT_0306432c[0x1d] = 0;
    puVar1[0x1c] = 0;
    vfo_load_side_config();
    settings_bitfield_remap_0x2d();
    PTR_DAT_03064328[1] = PTR_DAT_03064328[1] & 0xfe | (byte)p_dm32_settings_block04[0x2d] >> 7;
    ui_event_notify_alt(0x13);
  }
  return;
}


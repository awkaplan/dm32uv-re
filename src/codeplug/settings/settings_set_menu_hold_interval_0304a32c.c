/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_set_menu_hold_interval @ 0304a32c (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_set_menu_hold_interval(ushort param_1)

{
  param_1 = param_1 & 0xff;
  if (param_1 == 0) {
    p_dm32_settings_block04[0x5a] = p_dm32_settings_block04[0x5a] & 0xf0;
  }
  else {
    p_dm32_settings_block04[0x5a] = p_dm32_settings_block04[0x5a] & 0xf0 | 1;
    if (param_1 < 7) {
      PTR_DAT_0304a454[6] = param_1 * 5;
    }
    else {
      PTR_DAT_0304a454[6] = param_1 * 0x3c + -0x168;
    }
  }
  settings_read_dispatch_0x31_then_hook();
  noop_stub_03060b70();
  PTR_DAT_0304a458[2] = PTR_DAT_0304a458[2] & 0xef;
  *(undefined1 *)PTR_DAT_0304a45c = 0;
  return;
}


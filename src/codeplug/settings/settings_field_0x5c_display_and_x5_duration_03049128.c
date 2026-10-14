/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_field_0x5c_display_and_x5_duration @ 03049128 (file base 0x03000000; code starts at 0x03001000)
 * Size: 50 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_field_0x5c_display_and_x5_duration(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = p_active_screen_state_word;
  puVar1 = p_dm32_settings_block04;
  *(undefined1 *)p_active_screen_state_word = p_dm32_settings_block04[0x5c];
  display_draw_number_centered
            (100,0,0x7e0,*(uint *)(PTR_PTR_0304929c[((byte)puVar1[0x30] >> 6 & 1) * 2] + 0x2c));
  duration_seconds_decimal_display((uint)*(byte *)puVar2 * 5);
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_dual_value_display_and_field_0x57_to_0x3c_sync @ 030490ec (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void settings_dual_value_display_and_field_0x57_to_0x3c_sync(void)

{
  undefined1 *puVar1;
  
  puVar1 = p_dm32_settings_block04;
  display_draw_number_centered
            (100,0,0x7e0,
             **(uint **)(PTR_PTR_03049290 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  display_draw_number_centered(0x82,0,0x7e0,(uint)PTR_s__d_S__03049294);
  puVar1[0x3c] = puVar1[0x57];
  return;
}


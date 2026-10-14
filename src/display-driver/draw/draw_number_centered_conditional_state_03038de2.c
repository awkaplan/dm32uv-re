/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_number_centered_conditional_state @ 03038de2 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_number_centered_conditional_state(void)

{
  undefined *value;
  
  value = PTR_LAB_03039018;
  if ((*(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03038e60 + 2) == '\x03') &&
     ((p_radio_mode_state_0003e318->flags_0x6 & 0x10) != 0)) {
    display_draw_number_centered
              (1,0xffff,0,
               **(uint **)(PTR_PTR_03038e50 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4));
    value = PTR_LAB_03038e58;
  }
  display_draw_number_centered(1,0xffff,0,(uint)value);
  return;
}


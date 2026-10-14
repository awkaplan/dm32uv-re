/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: draw_number_centered_ptr_030387a0 @ 03038660 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void draw_number_centered_ptr_030387a0(void)

{
  display_draw_number_centered
            (1,0xffff,0,
             *(uint *)(PTR_PTR_030387a0[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                      (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03038790 + 2) * 4))
  ;
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_channel_icon_draw @ 030598d4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 112 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void scan_channel_icon_draw(byte param_1)

{
  if (((p_radio_mode_state_0003e318->flags_0x5 & 0xc0) == 0) &&
     ((*(byte *)p_call_active_flag & 8) == 0)) {
    display_fill_rect(10,2,0x2e,0x1a,0);
    format_number_and_draw_display
              (2,10,0xffff,0,PTR_s__d_030afae0_8_03059994,
               (*(ushort *)PTR_DAT_03059970 + 1) - (uint)*(byte *)PTR_DAT_03059968);
  }
  display_blit_image(0xd2,3,0x12,0x10,PTR_PTR_03059998[param_1]);
  PTR_DAT_0305999c[800] = param_1;
  return;
}


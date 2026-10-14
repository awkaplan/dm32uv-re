/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ctcss_or_dcs_code_display @ 03030044 (file base 0x03000000; code starts at 0x03001000)
 * Size: 162 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: analog-signaling
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void ctcss_or_dcs_code_display(uint param_1)

{
  uint uVar1;
  undefined1 local_14;
  undefined1 uStack_13;
  
  if (*(char *)PTR_DAT_030301e8 == '\0') {
    local_14 = (undefined1)(param_1 & 0xffff);
    uStack_13 = (undefined1)((param_1 & 0xffff) >> 8);
    uVar1 = bcd_frequency_decode(&local_14,2);
    number_to_string_format_2args
              (&local_14,PTR_s__d__dHz_030301ec,(uVar1 & 0xffff) / 10,(uVar1 & 0xffff) % 10);
  }
  else {
    number_to_string_format_2args(&local_14,PTR_LAB_030301f0,param_1 & 0x7fff);
  }
  display_fill_rect(0,0x82,0xf0,0x9a,0);
  display_draw_number_centered(0x82,0xffff,0,(uint)&local_14);
  display_draw_number_centered
            (0xa0,0xffff,0,PTR_PTR_030301f8[(byte)p_dm32_settings_block04[0x30] >> 6 & 1]);
  PTR_DAT_030301fc[3] = PTR_DAT_030301fc[3] & 0xfb | 4;
  return;
}


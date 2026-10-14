/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_monitor_display_refresh @ 03059b4c (file base 0x03000000; code starts at 0x03001000)
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

void scan_monitor_display_refresh(void)

{
  display_draw_dialog_panel_variant_0301a378();
  scan_channel_icon_draw(PTR_DAT_03059ce8[800]);
  display_fill_rect(0,0x122,0xf0,0x140,0);
  display_draw_gb2312_label_top_by_config_bit(0);
  if (*(char *)PTR_DAT_03059cec == '\x01') {
    display_draw_string_from_table(0);
  }
  else {
    display_draw_gb2312_label_bottom_by_config_bit(0);
    display_draw_string_wrapped2
              (0x20,5,p_text_entry_buffer + (uint)*p_text_entry_current_char_alias,0xffff,0);
  }
  return;
}


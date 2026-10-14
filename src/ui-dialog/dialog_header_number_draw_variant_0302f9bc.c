/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_header_number_draw_variant @ 0302f9bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 94 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_header_number_draw_variant(void)

{
  antenna_switch_select_gpio_24_22(0);
  if ((PTR_DAT_0302fb64[3] & 0x10) == 0) {
    display_plot_glyph_2color(0x14,0x46,0x17,0x27,PTR_DAT_0302fb6c,0xf800,0);
    gpio_set_output_bit(0x22);
  }
  else {
    display_plot_glyph_2color(0x14,0x46,0x17,0x27,PTR_DAT_0302fb68,0xf800,0);
    gpio_set_output_bit(0x24);
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_show_icon_and_number_from_ptr @ 0303a4dc (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_show_icon_and_number_from_ptr(void)

{
  display_draw_dialog_panel();
  display_blit_image(0x60,0x56,0x30,0x30,PTR_DAT_0303a674);
  display_draw_number_centered
            (0x90,0,0xc618,
             **(uint **)(PTR_PTR_0303a67c + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  OSTimeDly_ms_wrapper(1000);
  history_queue_pop();
  return;
}


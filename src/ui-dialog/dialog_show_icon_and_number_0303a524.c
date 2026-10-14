/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_show_icon_and_number @ 0303a524 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-dialog
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dialog_show_icon_and_number(char param_1,uint param_2)

{
  undefined4 *puVar1;
  
  display_draw_dialog_panel();
  puVar1 = PTR_DAT_0303a674;
  if (((param_1 != '\x01') && (puVar1 = (undefined4 *)PTR_DAT_0303a688, param_1 != '\0')) &&
     (puVar1 = (undefined4 *)PTR_DAT_0303a680, param_1 == '\x02')) {
    puVar1 = PTR_DAT_0303a684;
  }
  display_blit_image(0x60,0x56,0x30,0x30,puVar1);
  display_draw_number_centered(0x90,0,0xc618,param_2);
  OSTimeDly_ms_wrapper(1000);
  history_queue_pop();
  return;
}


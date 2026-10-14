/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_show_icon_and_two_numbers @ 0301aba8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 74 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_show_icon_and_two_numbers(int param_1__w,int param_2__w,undefined4 param_3,uint param_4,char *param_5)

{
  undefined1 param_1 = (undefined1)param_1__w;
  undefined1 param_2 = (undefined1)param_2__w;
  display_draw_dialog_panel();
  display_blit_image(0x60,0x56,param_1,param_2,param_3);
  display_draw_number_centered(0x90,0,0xc618,param_4);
  if (*param_5 != '\0') {
    display_draw_number_centered(0xae,0,0xc618,(uint)param_5);
  }
  return;
}


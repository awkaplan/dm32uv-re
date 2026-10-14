/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_icon_draw_dispatch @ 03039e64 (file base 0x03000000; code starts at 0x03001000)
 * Size: 250 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_icon_draw_dispatch(uint param_1,uint param_2)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = param_1 & 0xffff;
  param_2 = param_2 & 0xff;
  if ((*PTR_DAT_03039fc4 & 2) == 0) {
    bVar1 = p_dialog_history_ui_state->field_0xa0a;
    if (bVar1 == 0) {
      if ((PTR_DAT_03039fc4[1] & 0x40) == 0) {
        display_blit_bitmap_1bpp_clipped(8,uVar3,0x18,0x18,PTR_DAT_03039fcc[param_2]);
      }
      else {
        display_blit_bitmap_1bpp_clipped(8,uVar3,0x18,0x18,PTR_DAT_03039fc8[param_2]);
      }
    }
    else if (bVar1 == 1) {
      if ((PTR_DAT_03039fc4[1] & 0x40) == 0) {
        menu_icon_with_index_label_draw(param_1 & 0xff,param_2,0xffff,0);
      }
      else {
        menu_icon_with_index_label_draw(param_1 & 0xff,param_2,0,0);
      }
    }
    else if (bVar1 == 2) {
      uVar2 = PTR_DAT_03039fd0[uVar3];
      display_blit_bitmap_1bpp(8,uVar2,0x18,0x48,PTR_LAB_03039fd4,0xffff);
      if (*(byte *)p_menu_selected_item_index == param_2) {
        display_blit_bitmap_1bpp(8,uVar2,0x18,0x48,PTR_LAB_03039fdc,0xffff);
      }
    }
  }
  else if ((PTR_DAT_03039fc4[1] & 0x40) == 0) {
    menu_icon_with_index_label_draw(param_1 & 0xff,param_2,0xffff,0);
  }
  else {
    menu_icon_with_index_label_draw(param_1 & 0xff,param_2,0,0);
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_row_highlight_draw @ 03041598 (file base 0x03000000; code starts at 0x03001000)
 * Size: 170 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_row_highlight_draw(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  char cVar6;
  
  puVar4 = PTR_DAT_0304186c;
  puVar3 = PTR_active_screen_visible_rows_03041868;
  puVar2 = p_active_screen_state_word;
  if (1 < *(byte *)PTR_active_screen_visible_rows_03041868 + 1) {
    cVar6 = (*(char *)p_active_screen_state_word + '\x01') - *(char *)p_active_screen_flag_0003e5d5;
    uVar5 = 1;
    while( true ) {
      uVar1 = *(undefined1 *)((int)puVar4 + (uVar5 - 1));
      if (*(char *)puVar2 == cVar6) {
        display_plot_glyph_2color(8,uVar1,0x18,0x48,PTR_LAB_03041870,0xffff,0xc618);
        display_blit_bitmap_1bpp(8,uVar1,0x18,0x48,PTR_LAB_03041874,0xffff);
      }
      else {
        display_plot_glyph_2color(8,uVar1,0x18,0x48,PTR_LAB_03041870,0xffff,0);
      }
      uVar5 = uVar5 + 1 & 0xff;
      if (*(byte *)puVar3 + 1 <= uVar5) break;
      cVar6 = cVar6 + '\x01';
    }
  }
  return;
}


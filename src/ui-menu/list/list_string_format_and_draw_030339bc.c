/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_string_format_and_draw @ 030339bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 200 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_string_format_and_draw(void)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  short sVar4;
  ushort y;
  uint uVar5;
  uint uVar6;
  byte abStack_38 [20];
  
  puVar3 = p_active_screen_option_ptr_array;
  puVar2 = p_active_screen_index_list;
  if (1 < *(byte *)PTR_active_screen_visible_rows_03033b40 + 1) {
    uVar5 = (*(byte *)p_active_screen_state_word + 1) - (uint)*(byte *)p_active_screen_flag_0003e5d5
    ;
    uVar6 = 1;
    while( true ) {
      uVar5 = uVar5 & 0xff;
      sVar4 = strlen_ck803s(*(undefined4 *)(*puVar3 + (uint)*(byte *)((int)puVar2 + uVar5 + 2) * 4))
      ;
      y = sVar4 * 0xc + 5U & 0xff;
      bVar1 = PTR_DAT_03033b4c[uVar6 - 1];
      fixed_field_copy_and_format_dispatch(uVar5,abStack_38);
      if (*(byte *)p_active_screen_flag_0003e5d5 == uVar6) {
        display_draw_list_row
                  (uVar6,*(undefined4 *)(*puVar3 + (uint)*(byte *)((int)puVar2 + uVar5 + 2) * 4),1);
        display_draw_string_gb2312((ushort)bVar1,y,abStack_38,0,0xc618);
      }
      else {
        display_draw_list_row
                  (uVar6,*(undefined4 *)(*puVar3 + (uint)*(byte *)((int)puVar2 + uVar5 + 2) * 4),0);
        display_draw_string_gb2312((ushort)bVar1,y,abStack_38,0xffff,0);
      }
      uVar6 = uVar6 + 1 & 0xff;
      if (*(byte *)PTR_active_screen_visible_rows_03033b40 + 1 <= uVar6) break;
      uVar5 = uVar5 + 1;
    }
  }
  return;
}


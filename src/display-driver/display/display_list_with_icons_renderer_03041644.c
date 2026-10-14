/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_list_with_icons_renderer @ 03041644 (file base 0x03000000; code starts at 0x03001000)
 * Size: 186 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: display-driver
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void display_list_with_icons_renderer(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = _DAT_03041880;
  puVar3 = p_active_screen_option_ptr_array;
  iVar2 = p_active_screen_index_list;
  puVar1 = p_active_screen_flag_0003e5d5;
  if (1 < *(byte *)PTR_active_screen_visible_rows_03041868 + 1) {
    uVar5 = (*(byte *)p_active_screen_state_word + 1) - (uint)*(byte *)p_active_screen_flag_0003e5d5
    ;
    uVar6 = 1;
    while( true ) {
      uVar5 = uVar5 & 0xff;
      if (*(byte *)puVar1 == uVar6) {
        display_draw_list_row
                  (uVar6,*(undefined4 *)(*puVar3 + (uint)*(byte *)(iVar2 + uVar5 + 2) * 4),1);
        *(byte *)(iVar4 + 1) = *(byte *)(iVar4 + 1) & 0xbf | 0x40;
      }
      else {
        display_draw_list_row
                  (uVar6,*(undefined4 *)(*puVar3 + (uint)*(byte *)(iVar2 + uVar5 + 2) * 4),0);
        *(byte *)(iVar4 + 1) = *(byte *)(iVar4 + 1) & 0xbf;
      }
      if (*(char *)PTR_DAT_03041884 == '\0') {
        menu_icon_draw_dispatch(uVar6,*(undefined1 *)(iVar2 + uVar5 + 2));
      }
      else {
        menu_icon_draw_dispatch(uVar6,uVar5);
      }
      uVar6 = uVar6 + 1 & 0xff;
      if (*(byte *)PTR_active_screen_visible_rows_03041868 + 1 <= uVar6) break;
      uVar5 = uVar5 + 1;
    }
  }
  return;
}


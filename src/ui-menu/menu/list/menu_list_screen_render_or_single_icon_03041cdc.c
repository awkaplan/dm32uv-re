/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_list_screen_render_or_single_icon @ 03041cdc (file base 0x03000000; code starts at 0x03001000)
 * Size: 76 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_list_screen_render_or_single_icon(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = PTR_DAT_03041e24;
  if (*(char *)(*(int *)(PTR_LAB_03041e18 + (uint)p_menu_screen_state->index_0x2 * 4) + 4) == '\0')
  {
    dialog_show_icon_and_number
              (0,**(undefined4 **)
                   (PTR_PTR_03041e20 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else {
    bVar1 = PTR_DAT_03041e24[4];
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03041e30 = puVar2[5];
    build_sequential_index_list
              ((ushort)bVar1,(ushort *)p_active_screen_index_list,p_active_screen_index_list + 2);
  }
  return;
}


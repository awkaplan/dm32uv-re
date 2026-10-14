/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_select_or_show_icon @ 03042c48 (file base 0x03000000; code starts at 0x03001000)
 * Size: 120 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_select_or_show_icon(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = PTR_PTR_03042de4;
  puVar1 = PTR_DAT_03042dcc;
  if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03042dc8 + 2) == '\0') {
    *(undefined1 *)p_active_screen_option_count = PTR_DAT_03042dcc[4];
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar1;
    *(undefined1 *)PTR_active_screen_subtype_03042dd8 = puVar1[5];
    *(undefined1 *)PTR_DAT_03042ddc = 1;
  }
  else if (PTR_DAT_03042dcc[4] == '\0') {
    dialog_show_icon_and_number
              (0,**(undefined4 **)
                   (PTR_PTR_03042de8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  }
  else {
    uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03042de4 + uVar3 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03042dd8 = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5)
    ;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_option_list_selector @ 03043ff4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 178 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_option_list_selector(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = PTR_PTR_030440d0;
  puVar3 = PTR_DAT_030440c0;
  puVar2 = PTR_DAT_030440b0;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x4 + DAT_030440ac + 2);
  if (cVar1 == '\x01') {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030440c0 + 1);
    *p_active_screen_option_ptr_array = *puVar3;
    *(undefined1 *)PTR_active_screen_subtype_030440bc = *(undefined1 *)((int)puVar3 + 5);
    if (*(char *)PTR_DAT_030440c4 == '\x01') {
      dialog_request_init(0x80);
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030440b0 + 1);
    *p_active_screen_option_ptr_array = *puVar2;
    *(undefined1 *)PTR_active_screen_subtype_030440bc = *(undefined1 *)((int)puVar2 + 5);
    display_fill_screen(0);
    list_item_select_screen(2,p_menu_screen_state->index_0x3 + 1);
    display_fill_rect(0,0x122,0xf0,0x140,0);
    display_draw_string_from_table(0);
  }
  else if (cVar1 == '\x02') {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_030440d0 + uVar5 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar4[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_030440bc = *(undefined1 *)((int)puVar4 + uVar5 * 8 + 5)
    ;
  }
  return;
}


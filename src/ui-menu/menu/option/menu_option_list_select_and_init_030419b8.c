/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_select_and_init @ 030419b8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 96 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_option_list_select_and_init(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xbf | 0x40;
  *(undefined1 *)PTR_DAT_03041a4c = 1;
  puVar1 = p_active_screen_index_list;
  menu_option_list_dispatch
            (0x10,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
  puVar2 = PTR_DAT_03041a50;
  if (*(short *)puVar1 == 0) {
    history_queue_pop();
  }
  else {
    *(undefined1 *)p_active_screen_option_count = PTR_DAT_03041a50[4];
    *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
    *(undefined1 *)PTR_active_screen_subtype_03041a28 = puVar2[5];
    if (*(char *)PTR_DAT_03041a10 == '\x01') {
      if ((*(byte *)PTR_DAT_03041a54 & 1) == 0) {
        init_field_pair_0x20_5();
      }
      else {
        *(undefined2 *)p_text_entry_current_char = 8;
      }
    }
  }
  return;
}


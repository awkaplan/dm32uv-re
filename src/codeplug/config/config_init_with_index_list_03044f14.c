/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_init_with_index_list @ 03044f14 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void config_init_with_index_list(void)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  
  puVar3 = PTR_PTR_03045058;
  bVar1 = *(byte *)(PTR_PTR_03045058 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = *puVar3;
  *(undefined1 *)PTR_active_screen_subtype_03045038 = *(undefined1 *)((int)puVar3 + 5);
  build_sequential_index_list
            ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  if (p_radio_mode_state_0003e318[1].flags_0x5 == 0) {
    *(undefined1 *)p_active_screen_state_word = 0;
  }
  else if (p_radio_mode_state_0003e318[1].flags_0x5 == 1) {
    *(undefined1 *)p_active_screen_state_word = 1;
  }
  else {
    *(undefined1 *)p_active_screen_state_word = 2;
  }
  cVar2 = *(char *)p_active_screen_state_word;
  *(char *)p_active_screen_flag_0003e5d5 = cVar2 + '\x01';
  *(char *)p_menu_selected_item_index = cVar2;
  *(undefined1 *)PTR_DAT_03045050 = 2;
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_entry_with_history_pop_var_30 @ 03041f04 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_entry_with_history_pop_var_30(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (*(char *)PTR_DAT_03041fa0 == '\x01') {
    menu_option_list_dispatch
              (0x30,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
  }
  puVar1 = PTR_PTR_03041fc4;
  if (*(short *)p_active_screen_index_list == 0) {
    history_queue_pop();
  }
  else {
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03041fc4 + 1);
    uVar2 = *puVar1;
    *p_active_screen_option_ptr_array = uVar2;
    *PTR_DAT_03041fb4 = uVar2;
    *(undefined1 *)PTR_active_screen_subtype_03041fb8 = *(undefined1 *)((int)puVar1 + 5);
  }
  return;
}


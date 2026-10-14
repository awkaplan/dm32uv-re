/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_restore_state_and_dispatch @ 0303c97c (file base 0x03000000; code starts at 0x03001000)
 * Size: 126 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_screen_restore_state_and_dispatch(void)

{
  undefined1 *puVar1;
  
  if (PTR_DAT_0303caa8[4] == '\x01') {
    dialog_history_flush_and_reset();
    if ((*(byte *)PTR_DAT_0303caac & 1) == 0) {
      init_field_pair_0x20_5();
      *(byte *)PTR_DAT_0303caac = *(byte *)PTR_DAT_0303caac & 0xfe | 1;
      memset_bytes(DAT_0303cab0,0,9);
    }
  }
  puVar1 = PTR_DAT_0303cab8;
  if ((*(byte *)PTR_call_active_flag_0303cab4 & 8) == 0) {
    *(undefined1 *)PTR_active_screen_option_count_0303cabc = PTR_DAT_0303cab8[4];
    *PTR_active_screen_option_ptr_array_0303cac0 = *(undefined4 *)puVar1;
    *(undefined1 *)PTR_active_screen_subtype_0303cac4 = puVar1[5];
    PTR_DAT_0303cac8[5] = PTR_DAT_0303cac8[5] & 0xef | 0x10;
  }
  else {
    *(undefined1 *)PTR_active_screen_option_count_0303cabc = PTR_DAT_0303cab8[4];
    *PTR_active_screen_option_ptr_array_0303cac0 = *(undefined4 *)puVar1;
    *(undefined1 *)PTR_active_screen_subtype_0303cac4 = 0x18;
  }
  main_menu_screen_dispatch();
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_with_dualwatch_index_range @ 03045a4c (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_option_list_init_with_dualwatch_index_range(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  
  if (*(char *)PTR_DAT_03045be4 == '\x01') {
    *(undefined2 *)PTR_DAT_03045be8 = 0;
    *(undefined2 *)PTR_DAT_03045bec = 1;
  }
  puVar2 = PTR_DAT_03045bf0;
  *(undefined1 *)p_active_screen_option_count = PTR_DAT_03045bf0[4];
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
  *(undefined1 *)PTR_active_screen_subtype_03045bfc = puVar2[5];
  SUBPIECE_SET(uVar1, 0, 1, p_radio_mode_state_0003e318[1].field_0x8);
  SUBPIECE_SET(uVar1, 1, 1, p_radio_mode_state_0003e318[1].field_0x9);
  *(ushort *)PTR_DAT_03045c04 = uVar1;
  if (uVar1 < 2) {
    *(undefined2 *)p_active_screen_index_list = 0;
  }
  else {
    *(undefined2 *)p_active_screen_index_list = 2;
  }
  return;
}


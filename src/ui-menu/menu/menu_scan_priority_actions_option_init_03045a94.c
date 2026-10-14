/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_scan_priority_actions_option_init @ 03045a94 (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_scan_priority_actions_option_init(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = PTR_PTR_03045c18;
  if (p_menu_screen_state->index_0x5 < p_vfo_freq_display_state->field_0x1) {
    uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar1 = *(byte *)(PTR_PTR_03045c18 + uVar3 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03045bfc = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5)
    ;
    build_sequential_index_list
              ((ushort)bVar1,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
    if (p_menu_screen_state->index_0x5 == 0) {
      *(short *)p_active_screen_index_list = *(short *)p_active_screen_index_list + -1;
    }
  }
  else {
    menu_option_list_init_with_dualwatch_index_range();
  }
  *(undefined1 *)PTR_DAT_03045c1c = 1;
  return;
}


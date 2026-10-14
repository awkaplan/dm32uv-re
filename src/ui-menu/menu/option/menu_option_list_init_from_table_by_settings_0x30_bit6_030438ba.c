/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_from_table_by_settings_0x30_bit6 @ 030438ba (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_option_list_init_from_table_by_settings_0x30_bit6(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = PTR_PTR_03043994;
  uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03043994 + uVar2 * 2 + 1);
  *p_active_screen_option_ptr_array = puVar1[uVar2 * 2];
  *(undefined1 *)PTR_active_screen_subtype_0304396c = *(undefined1 *)((int)puVar1 + uVar2 * 8 + 5);
  return;
}


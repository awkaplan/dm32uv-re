/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_from_fixed_table_and_history_draw @ 030437d8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 34 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_option_list_init_from_fixed_table_and_history_draw(void)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_03043960;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03043960 + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_0304396c = *(undefined1 *)((int)puVar1 + 5);
  history_record_detail_screen_draw(*(short *)PTR_DAT_03043970 + 1);
  return;
}


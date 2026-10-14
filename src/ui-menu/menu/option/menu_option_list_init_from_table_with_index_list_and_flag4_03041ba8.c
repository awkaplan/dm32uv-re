/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_option_list_init_from_table_with_index_list_and_flag4 @ 03041ba8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_option_list_init_from_table_with_index_list_and_flag4(void)

{
  byte bVar1;
  undefined1 *puVar2;
  
  puVar2 = PTR_DAT_03041cc0;
  bVar1 = PTR_DAT_03041cc0[4];
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = *(undefined4 *)puVar2;
  *(undefined1 *)PTR_active_screen_subtype_03041ca8 = puVar2[5];
  *(ushort *)p_active_screen_index_list = (ushort)bVar1;
  *(undefined1 *)PTR_DAT_03041cbc = 4;
  return;
}


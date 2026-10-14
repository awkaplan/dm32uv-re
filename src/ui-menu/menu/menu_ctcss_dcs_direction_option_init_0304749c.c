/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_ctcss_dcs_direction_option_init @ 0304749c (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_ctcss_dcs_direction_option_init(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = PTR_PTR_0304758c;
  uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar1 = *(byte *)(PTR_PTR_0304758c + uVar3 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
  *(undefined1 *)PTR_active_screen_subtype_0304754c = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5);
  if (*(char *)PTR_DAT_03047550 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  return;
}


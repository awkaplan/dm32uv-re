/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_select_index_list_build_with_state_reset @ 030476cc (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_entry_select_index_list_build_with_state_reset(void)

{
  byte bVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  
  puVar2 = PTR_PTR_0304777c;
  uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar1 = *(byte *)(PTR_PTR_0304777c + uVar4 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03047740 = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5);
  if (*(char *)PTR_DAT_03047744 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar1,(ushort *)p_active_screen_index_list,
               (byte *)((int)p_active_screen_index_list + 2));
  }
  *(short *)p_active_screen_index_list = *(short *)p_active_screen_index_list + -1;
  cVar3 = vfo_active_side_mode_nibble();
  *(char *)p_active_screen_state_word = cVar3;
  *(char *)p_active_screen_flag_0003e5d5 = cVar3 + '\x01';
  *(undefined1 *)PTR_DAT_03047758 = 2;
  *(char *)p_menu_selected_item_index = cVar3;
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: table_entry_select_two_mode_dispatch @ 03046a88 (file base 0x03000000; code starts at 0x03001000)
 * Size: 132 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void table_entry_select_two_mode_dispatch(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  puVar4 = PTR_PTR_03046b38;
  puVar3 = PTR_PTR_03046b1c;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x6 + DAT_03046b14 + 2);
  if (cVar1 == '\0') {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar2 = *(byte *)(PTR_PTR_03046b1c + uVar5 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar2;
    *p_active_screen_option_ptr_array = puVar3[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03046b28 = *(undefined1 *)((int)puVar3 + uVar5 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03046b2c == '\x01') {
      build_sequential_index_list
                ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
    }
  }
  else if (cVar1 == '\x02') {
    uVar5 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03046b38 + uVar5 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar4[uVar5 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03046b28 = *(undefined1 *)((int)puVar4 + uVar5 * 8 + 5)
    ;
  }
  return;
}


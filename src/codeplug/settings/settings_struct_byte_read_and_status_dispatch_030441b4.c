/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_struct_byte_read_and_status_dispatch @ 030441b4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_struct_byte_read_and_status_dispatch(uint param_1)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte bVar4;
  
  puVar2 = PTR_PTR_03044238;
  uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar4 = *(byte *)(PTR_PTR_03044238 + uVar3 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar4;
  *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03044220 = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5);
  if (*(char *)PTR_DAT_03044228 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar4,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  uVar3 = (param_1 & 0xff) - 4 & 0xff;
  if (uVar3 < 6) {
                    /* WARNING: Could not recover jumptable at 0x03044208. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03044240[uVar3] & 0xfffffffe))();
    return;
  }
  *(undefined1 *)PTR_DAT_030442e8 = 2;
  cVar1 = *(char *)p_active_screen_state_word;
  *(char *)p_menu_selected_item_index = cVar1;
  bVar4 = cVar1 + 1;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar4;
  if (8 < bVar4) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}


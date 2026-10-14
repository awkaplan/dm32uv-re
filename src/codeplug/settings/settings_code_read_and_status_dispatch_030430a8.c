/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_code_read_and_status_dispatch @ 030430a8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 80 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_code_read_and_status_dispatch(uint param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  uint uVar4;
  byte bVar5;
  
  puVar2 = PTR_PTR_0304312c;
  uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar5 = *(byte *)(PTR_PTR_0304312c + uVar4 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar5;
  *p_active_screen_option_ptr_array = puVar2[uVar4 * 2];
  *(undefined1 *)PTR_active_screen_subtype_03043114 = *(undefined1 *)((int)puVar2 + uVar4 * 8 + 5);
  if (*(char *)PTR_DAT_03043118 == '\x01') {
    build_sequential_index_list
              ((ushort)bVar5,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  }
  if ((param_1 & 0xff) < 10) {
                    /* WARNING: Could not recover jumptable at 0x030430f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_03043130[param_1 & 0xff] & 0xfffffffe))();
    return;
  }
  uVar3 = settings_read_dispatcher(0x4f);
  *(undefined1 *)p_active_screen_state_word = uVar3;
  *(undefined1 *)PTR_DAT_030432f0 = 2;
  cVar1 = *(char *)p_active_screen_state_word;
  *(char *)p_menu_selected_item_index = cVar1;
  bVar5 = cVar1 + 1;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar5;
  if (8 < bVar5) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_capability_dispatch @ 0304c750 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_capability_dispatch(uint param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_0304c79c;
  uVar4 = (byte)p_dm32_settings_block04->field_0x30 >> 6 & 1;
  bVar1 = *(byte *)(PTR_PTR_0304c79c + uVar4 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar1;
  *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
  *(undefined1 *)PTR_active_screen_subtype_0304c7a8 = *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5);
  build_sequential_index_list
            ((ushort)bVar1,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  if ((param_1 & 0xff) < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x0304c796. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0304c7b0[param_1 & 0xff] & 0xfffffffe))();
    return;
  }
  *(undefined1 *)PTR_DAT_0304cab0 = 2;
  cVar2 = *(char *)p_active_screen_state_word;
  *(char *)p_menu_selected_item_index = cVar2;
  *(char *)p_active_screen_flag_0003e5d5 = cVar2 + '\x01';
  return;
}


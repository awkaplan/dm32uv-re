/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_mode_selector_apply @ 030443c0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void config_mode_selector_apply(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte bVar4;
  
  puVar2 = PTR_PTR_030444f0;
  puVar1 = p_dm32_settings_block04;
  uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
  bVar4 = *(byte *)(PTR_PTR_030444f0 + uVar3 * 2 + 1);
  *(byte *)p_active_screen_option_count = bVar4;
  *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
  *(undefined1 *)PTR_active_screen_subtype_030444d4 = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5);
  build_sequential_index_list
            ((ushort)bVar4,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1));
  bVar4 = (byte)puVar1[0x44] >> 2 & 3;
  *(byte *)p_active_screen_state_word = bVar4;
  *(undefined1 *)PTR_DAT_030444e4 = 2;
  *(byte *)p_menu_selected_item_index = bVar4;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar4 + 1;
  return;
}


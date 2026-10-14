/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_0x67_clamp_and_list_init @ 0304760e (file base 0x03000000; code starts at 0x03001000)
 * Size: 88 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_field_0x67_clamp_and_list_init(void)

{
  byte bVar1;
  undefined4 *puVar2;
  byte bVar3;
  
  bVar3 = flash_field_read_cached_block0x67_off0();
  *(byte *)PTR_DAT_03047760 = bVar3;
  if (0xfa < bVar3) {
    *(undefined1 *)PTR_DAT_03047760 = 1;
  }
  *(undefined1 *)PTR_DAT_03047758 = 2;
  bVar3 = p_vfo_display_state->field_0x1b;
  *(byte *)p_active_screen_state_word = bVar3;
  *(undefined1 *)PTR_active_screen_subtype_03047740 = 0x31;
  puVar2 = p_active_screen_index_list;
  bVar1 = *(byte *)PTR_DAT_03047760;
  *(ushort *)p_active_screen_index_list = (ushort)bVar1;
  if (bVar1 < 2) {
    *(undefined2 *)puVar2 = 2;
  }
  *(byte *)p_menu_selected_item_index = bVar3;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar3 + 1;
  if (8 < (byte)(bVar3 + 1)) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: flash_field_bitcount_index_list_init @ 0304787e (file base 0x03000000; code starts at 0x03001000)
 * Size: 92 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: flash-storage
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void flash_field_bitcount_index_list_init(void)

{
  byte bVar1;
  undefined4 *puVar2;
  short sVar3;
  
  *(undefined1 *)PTR_DAT_03047958 = 2;
  puVar2 = p_active_screen_state_word;
  *(byte *)p_active_screen_state_word = p_vfo_display_state->field_0xf & 0x3f;
  *(undefined1 *)PTR_active_screen_subtype_03047940 = 0x1e;
  sVar3 = count_set_bits_in_flash_field();
  *(char *)PTR_DAT_03047980 = (char)sVar3;
  *(short *)p_active_screen_index_list = sVar3 + 1;
  bVar1 = *(byte *)puVar2;
  if (bVar1 < 0x21) {
    *(byte *)p_menu_selected_item_index = bVar1;
    *(byte *)p_active_screen_flag_0003e5d5 = bVar1 + 1;
    if (8 < (byte)(bVar1 + 1)) {
      *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
    }
  }
  else {
    *(undefined1 *)puVar2 = 0;
    *(undefined1 *)p_menu_selected_item_index = 0;
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 1;
  }
  return;
}


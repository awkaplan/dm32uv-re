/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_index_value_select_and_draw_centered @ 03038d24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 190 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_index_value_select_and_draw_centered(void)

{
  char cVar1;
  undefined *puVar2;
  
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x1 + DAT_03038e60 + 2);
  if (cVar1 == '\x03') {
    if ((p_radio_mode_state_0003e318->flags_0x6 & 0x10) == 0) {
      puVar2 = *(undefined **)
                (PTR_PTR_03038e6c[((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 2] +
                (uint)*(byte *)((uint)p_menu_screen_state->index_0x2 + DAT_03038e68 + 2) * 4);
    }
    else {
      display_draw_number_centered
                (1,0xffff,0,
                 **(uint **)(PTR_PTR_03038e50 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4))
      ;
      puVar2 = PTR_LAB_03038e58;
    }
  }
  else if (cVar1 == '\x01') {
    puVar2 = (undefined *)
             **(undefined4 **)
               (PTR_PTR_03038e70 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8);
  }
  else {
    puVar2 = PTR_LAB_03039018;
    if (cVar1 == '\x05') {
      if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03038e74 + 2) == '\f') {
        puVar2 = (undefined *)
                 **(undefined4 **)
                   (PTR_PTR_03038e78 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 4);
      }
    }
    else if ((cVar1 == '\0') &&
            (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03038e68 + 2) == '\x03')) {
      puVar2 = &stack0x00000004;
      memcpy_bytes_iram(puVar2,DAT_03038e7c,0x10);
    }
  }
  display_draw_number_centered(1,0xffff,0,(uint)puVar2);
  return;
}


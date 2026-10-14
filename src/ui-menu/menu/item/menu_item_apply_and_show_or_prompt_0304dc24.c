/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_item_apply_and_show_or_prompt @ 0304dc24 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void menu_item_apply_and_show_or_prompt(void)

{
  char cVar1;
  
  if (*(char *)((uint)p_menu_screen_state->index_0x2 + DAT_0304dcb8 + 2) == '\x03') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x3 + DAT_0304dcac + 2);
    if (cVar1 == '\x01') {
      flash_record_erase_and_clear_cache(2);
    }
    else if (cVar1 == '\0') {
      flash_record_erase_and_clear_cache(1);
    }
    else if (cVar1 == '\x02') {
      flash_record_erase_and_clear_cache(3);
    }
    dialog_show_icon_and_number
              (1,**(undefined4 **)
                   (PTR_PTR_0304dcbc + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
    history_queue_pop();
  }
  else {
    write_status_mode_byte_pair(0x23,1);
  }
  return;
}


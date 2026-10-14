/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_state_code_dispatch @ 03036378 (file base 0x03000000; code starts at 0x03001000)
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

void menu_state_code_dispatch(void)

{
  char cVar1;
  
  cVar1 = *(char *)((uint)(byte)PTR_g_menu_screen_state_030364a8[1] + DAT_030364ac + 2);
  if (cVar1 == '\x03') {
    menu_screen_state_mode_dispatch();
  }
  else if (cVar1 == '\x04') {
    quick_text_insert_and_commit();
  }
  else if (cVar1 == '\x05') {
    menu_confirm_apply_manual_freq_entry();
  }
  else if (cVar1 == '\0') {
    status_dialog_request_by_code_dispatch();
  }
  else if (cVar1 == '\x01') {
    scan_list_flash_field_bit_update();
  }
  else {
    write_status_mode_byte_pair(0x38,1);
  }
  return;
}


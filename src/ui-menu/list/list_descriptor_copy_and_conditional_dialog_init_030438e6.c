/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_descriptor_copy_and_conditional_dialog_init @ 030438e6 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-menu
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void list_descriptor_copy_and_conditional_dialog_init(void)

{
  undefined4 *puVar1;
  
  puVar1 = PTR_DAT_03043998;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03043998 + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_0304396c = *(undefined1 *)((int)puVar1 + 5);
  if (*(char *)PTR_DAT_0304397c == '\x01') {
    p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xef | 0x10;
    dialog_request_init(0x80);
  }
  return;
}


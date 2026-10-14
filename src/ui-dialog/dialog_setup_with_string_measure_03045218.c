/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_setup_with_string_measure @ 03045218 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_setup_with_string_measure(void)

{
  undefined4 *puVar1;
  char cVar2;
  
  dialog_request_init(0x10);
  if (*(char *)PTR_DAT_0304526c == '\x01') {
    cVar2 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_030452a4 = cVar2 + '\x01';
  }
  puVar1 = PTR_DAT_030452a8;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030452a8 + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_03045264 = *(undefined1 *)((int)puVar1 + 5);
  p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xdf | 0x20;
  return;
}


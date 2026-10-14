/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_name_entry_dialog_init @ 03042a30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 62 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_name_entry_dialog_init(void)

{
  undefined4 *puVar1;
  char cVar2;
  
  dialog_request_init(0x10);
  if (*(char *)PTR_DAT_03042ae8 == '\x01') {
    cVar2 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_03042af0 = cVar2 + '\x01';
    p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0xf7 | 8;
  }
  puVar1 = PTR_DAT_03042af4;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03042af4 + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_03042ae0 = *(undefined1 *)((int)puVar1 + 5);
  return;
}


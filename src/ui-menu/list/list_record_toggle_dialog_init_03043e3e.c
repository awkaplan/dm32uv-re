/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: list_record_toggle_dialog_init @ 03043e3e (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void list_record_toggle_dialog_init(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  
  puVar1 = PTR_DAT_03043f14;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_03043f14 + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_03043efc = *(undefined1 *)((int)puVar1 + 5);
  if (*(char *)PTR_DAT_03043f18 == '\x01') {
    dialog_request_init(0x80);
    list_record_lookup_and_toggle_by_index(5,p_menu_screen_state->index_0x4 + 1);
    uVar2 = p_text_entry_buffer;
    cVar3 = strlen_ck803s(p_text_entry_buffer);
    *(char *)PTR_DAT_03043f20 = cVar3 + '\x01';
    *(char *)PTR_DAT_03043f24 = cVar3;
    *(undefined2 *)PTR_DAT_03043f28 = 0x20;
    *(undefined2 *)p_text_entry_current_char = 5;
    gb2312_text_wrap_calculate(uVar2);
    p_radio_mode_state_0003e318->flags_0x6 = p_radio_mode_state_0003e318->flags_0x6 & 0xef | 0x10;
  }
  return;
}


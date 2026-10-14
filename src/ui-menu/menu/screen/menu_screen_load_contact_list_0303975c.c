/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_screen_load_contact_list @ 0303975c (file base 0x03000000; code starts at 0x03001000)
 * Size: 64 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_screen_load_contact_list(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  
  puVar1 = PTR_DAT_030397ec;
  *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_DAT_030397ec + 1);
  *p_active_screen_option_ptr_array = *puVar1;
  *(undefined1 *)PTR_active_screen_subtype_030397d4 = *(undefined1 *)((int)puVar1 + 5);
  uVar2 = contact_count_range_calc(2);
  *(undefined2 *)p_active_screen_index_list = uVar2;
  *(undefined2 *)PTR_DAT_030397fc = uVar2;
  if (p_dialog_history_ui_state->field_0x4 == 1) {
    *(undefined2 *)PTR_DAT_03039800 = 0;
    *(undefined2 *)PTR_DAT_03039804 = 1;
  }
  set_flag_byte_03064328_variant_0303501c(2);
  return;
}


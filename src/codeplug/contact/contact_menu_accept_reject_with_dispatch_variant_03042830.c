/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_menu_accept_reject_with_dispatch_variant @ 03042830 (file base 0x03000000; code starts at 0x03001000)
 * Size: 140 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_menu_accept_reject_with_dispatch_variant(void)

{
  undefined1 *puVar1;
  
  if (*(char *)((uint)p_menu_screen_state->index_0x3 + DAT_03042950 + 2) == '\0') {
    if (*(char *)PTR_DAT_03042954 == '\x01') {
      *PTR_DAT_03042944 = 0;
      *PTR_DAT_03042948 = 1;
    }
    screen_option_template_load_id_generic();
  }
  else {
    if (*(char *)PTR_DAT_03042954 == '\x01') {
      menu_option_list_dispatch
                (0x10,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
    }
    puVar1 = PTR_DAT_03042958;
    if (*(short *)p_active_screen_index_list == 0) {
      history_queue_pop();
    }
    else {
      *(undefined1 *)p_active_screen_option_count = PTR_DAT_03042958[4];
      *p_active_screen_option_ptr_array = *(undefined4 *)puVar1;
      *(undefined1 *)PTR_active_screen_subtype_03042934 = puVar1[5];
      p_radio_mode_state_0003e318->flags_0x5 = p_radio_mode_state_0003e318->flags_0x5 & 0x7f | 0x80;
      if (*(char *)PTR_DAT_03042954 == '\x01') {
        if ((*(byte *)PTR_DAT_03042960 & 1) == 0) {
          init_field_pair_0x20_5();
        }
        else {
          *(undefined2 *)p_text_entry_current_char = 8;
        }
      }
    }
  }
  return;
}


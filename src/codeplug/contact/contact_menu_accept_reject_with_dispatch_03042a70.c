/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: contact_menu_accept_reject_with_dispatch @ 03042a70 (file base 0x03000000; code starts at 0x03001000)
 * Size: 86 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void contact_menu_accept_reject_with_dispatch(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (*(char *)PTR_DAT_03042ae8 == '\x01') {
    menu_option_list_dispatch
              (1,p_active_screen_index_list,(void *)((int)p_active_screen_index_list + 2));
  }
  puVar1 = PTR_PTR_03042af8;
  if (*(short *)p_active_screen_index_list == 0) {
    ui_event_notify(0x21);
    history_queue_pop();
  }
  else {
    uVar2 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    *(undefined1 *)p_active_screen_option_count = *(undefined1 *)(PTR_PTR_03042af8 + uVar2 * 2 + 1);
    *p_active_screen_option_ptr_array = puVar1[uVar2 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03042ae0 = *(undefined1 *)((int)puVar1 + uVar2 * 8 + 5)
    ;
  }
  return;
}


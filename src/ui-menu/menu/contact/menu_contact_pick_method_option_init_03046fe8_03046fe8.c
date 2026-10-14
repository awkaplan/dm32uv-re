/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_contact_pick_method_option_init_03046fe8 @ 03046fe8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 146 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_contact_pick_method_option_init_03046fe8(void)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = PTR_PTR_030471a8;
  cVar1 = *(char *)((uint)p_menu_screen_state->index_0x2 + DAT_03047198 + 2);
  if (cVar1 == '\x03') {
    if ((*(char *)((uint)p_menu_screen_state->index_0x6 + DAT_0304719c + 2) == '\x02') &&
       (*(char *)((uint)p_menu_screen_state->field_0x7 + DAT_030471a0 + 2) == '\0')) {
      uVar4 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
      bVar2 = *(byte *)(PTR_PTR_030471a8 + uVar4 * 2 + 1);
      *(byte *)p_active_screen_option_count = bVar2;
      *p_active_screen_option_ptr_array = puVar3[uVar4 * 2];
      *(undefined1 *)PTR_active_screen_subtype_030471b4 =
           *(undefined1 *)((int)puVar3 + uVar4 * 8 + 5);
      if (*(char *)PTR_DAT_030471b8 == '\x01') {
        build_sequential_index_list
                  ((ushort)bVar2,p_active_screen_index_list,(byte *)(p_active_screen_index_list + 1)
                  );
      }
    }
  }
  else if (cVar1 == '\0') {
    cVar1 = *(char *)((uint)p_menu_screen_state->index_0x6 + DAT_0304719c + 2);
    if (cVar1 == '\0') {
      shutdown_confirm_gate_check();
    }
    else if (cVar1 == '\x02') {
      menu_screen_dispatch_by_field_0x8();
    }
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_message_compose_actions_option_init @ 03045e3c (file base 0x03000000; code starts at 0x03001000)
 * Size: 82 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_message_compose_actions_option_init(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = PTR_PTR_03045fa4;
  if (*(char *)((uint)p_menu_screen_state->index_0x4 + DAT_03045f9c + 2) == '\x01') {
    uVar3 = (byte)p_dm32_settings_block04[0x30] >> 6 & 1;
    bVar1 = *(byte *)(PTR_PTR_03045fa4 + uVar3 * 2 + 1);
    *(byte *)p_active_screen_option_count = bVar1;
    *p_active_screen_option_ptr_array = puVar2[uVar3 * 2];
    *(undefined1 *)PTR_active_screen_subtype_03045fb0 = *(undefined1 *)((int)puVar2 + uVar3 * 8 + 5)
    ;
    if (*(char *)PTR_DAT_03045fb4 == '\x01') {
      build_sequential_index_list
                ((ushort)bVar1,(ushort *)p_active_screen_index_list,
                 (byte *)((int)p_active_screen_index_list + 2));
    }
  }
  return;
}


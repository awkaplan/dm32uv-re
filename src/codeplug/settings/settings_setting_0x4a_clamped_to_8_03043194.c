/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_setting_0x4a_clamped_to_8 @ 03043194 (file base 0x03000000; code starts at 0x03001000)
 * Size: 12 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void settings_setting_0x4a_clamped_to_8(void)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  
  uVar2 = settings_read_dispatcher(0x4a);
  *(undefined1 *)p_active_screen_state_word = uVar2;
  *(undefined1 *)PTR_DAT_030432f0 = 2;
  cVar1 = *(char *)p_active_screen_state_word;
  *(char *)p_menu_selected_item_index = cVar1;
  bVar3 = cVar1 + 1;
  *(byte *)p_active_screen_flag_0003e5d5 = bVar3;
  if (8 < bVar3) {
    *(undefined1 *)p_active_screen_flag_0003e5d5 = 8;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: menu_exit_time_option_apply @ 0304fe20 (file base 0x03000000; code starts at 0x03001000)
 * Size: 32 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: ui-menu
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void menu_exit_time_option_apply(void)

{
  char cVar1;
  
  cVar1 = *(char *)p_active_screen_state_word;
  p_dm32_settings_block04[0x59] = cVar1;
  PTR_DAT_0304fe50[0xb] = cVar1 * '\x05';
  flash_field_write_cached(4,0x32);
  dialog_show_icon_and_number_from_ptr();
  return;
}


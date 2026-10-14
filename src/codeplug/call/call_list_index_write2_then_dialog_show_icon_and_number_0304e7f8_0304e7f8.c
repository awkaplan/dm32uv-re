/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: call_list_index_write2_then_dialog_show_icon_and_number_0304e7f8 @ 0304e7f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 10 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void call_list_index_write2_then_dialog_show_icon_and_number_0304e7f8(void)

{
  PTR_DAT_0304e950[10] = *(undefined1 *)p_active_screen_state_word;
  call_list_index_write2();
  dialog_show_icon_and_number
            (1,**(undefined4 **)
                 (PTR_PTR_0304e958 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: settings_block6_offset0x100_write_field0xc @ 0304e5f2 (file base 0x03000000; code starts at 0x03001000)
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

void settings_block6_offset0x100_write_field0xc(void)

{
  PTR_DAT_0304e660[0xc] = *(undefined1 *)p_active_screen_state_word;
  flash_block_write(6,0x100,PTR_DAT_0304e660,0xd);
  dialog_show_icon_and_number
            (1,**(undefined4 **)
                 (PTR_PTR_0304e668 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  return;
}


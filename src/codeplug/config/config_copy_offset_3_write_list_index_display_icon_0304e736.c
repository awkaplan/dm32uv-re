/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: config_copy_offset_3_write_list_index_display_icon @ 0304e736 (file base 0x03000000; code starts at 0x03001000)
 * Size: 10 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void config_copy_offset_3_write_list_index_display_icon(void)

{
  PTR_DAT_0304e7a0[3] = *(undefined1 *)p_active_screen_state_word;
  call_list_index_write();
  dialog_show_icon_and_number
            (1,**(undefined4 **)
                 (PTR_PTR_0304e7a8 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  return;
}


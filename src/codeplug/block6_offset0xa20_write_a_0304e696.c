/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: block6_offset0xa20_write_a @ 0304e696 (file base 0x03000000; code starts at 0x03001000)
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

void block6_offset0xa20_write_a(void)

{
  PTR_DAT_0304e700[8] = *(undefined1 *)p_active_screen_state_word;
  flash_block_write(6,0xa20,PTR_DAT_0304e700,9);
  dialog_show_icon_and_number
            (1,**(undefined4 **)
                 (PTR_PTR_0304e708 + ((byte)p_dm32_settings_block04[0x30] >> 6 & 1) * 8));
  return;
}


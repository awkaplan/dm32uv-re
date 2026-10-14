/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_show_and_clear_bits @ 030684f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_show_and_clear_bits(void)

{
  dialog_flags_from_flash *pdVar1;
  
  if ((p_radio_mode_state_0003e318[2].flags_0x2 & 1) != 0) {
    dialog_show_number_or_alt();
    p_radio_mode_state_0003e318[2].flags_0x2 = p_radio_mode_state_0003e318[2].flags_0x2 & 0xfe;
    pdVar1 = p_dialog_flags_from_flash;
    p_dialog_flags_from_flash->flags_0x1 = p_dialog_flags_from_flash->flags_0x1 & 0xf7;
    pdVar1->flags_0x2d = pdVar1->flags_0x2d & 0xf3;
    *(byte *)PTR_DAT_03068618 = *(byte *)PTR_DAT_03068618 & 0x7f;
  }
  return;
}


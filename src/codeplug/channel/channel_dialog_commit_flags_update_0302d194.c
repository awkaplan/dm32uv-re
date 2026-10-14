/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_dialog_commit_flags_update @ 0302d194 (file base 0x03000000; code starts at 0x03001000)
 * Size: 48 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: codeplug
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void channel_dialog_commit_flags_update(void)

{
  dialog_flags_from_flash *pdVar1;
  
  p_tx_ptt_ui_state->field_0x6 = 10;
  pdVar1 = p_dialog_flags_from_flash;
  p_dialog_flags_from_flash->flags_0x1f = p_dialog_flags_from_flash->flags_0x1f & 0x87 | 0x20;
  pdVar1->field_0x3d = 0;
  pdVar1->field_0x21 = pdVar1->field_0x3b;
  pdVar1->field_0x20 = pdVar1->field_0x20 & 0xef;
  return;
}


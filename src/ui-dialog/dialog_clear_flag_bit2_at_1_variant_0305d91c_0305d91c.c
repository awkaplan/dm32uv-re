/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_clear_flag_bit2_at_1_variant_0305d91c @ 0305d91c (file base 0x03000000; code starts at 0x03001000)
 * Size: 18 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_clear_flag_bit2_at_1_variant_0305d91c(void)

{
  p_dialog_flags_from_flash->flags_0x2d = p_dialog_flags_from_flash->flags_0x2d & 0xf7;
  return;
}


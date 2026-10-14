/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_tick_idle_check @ 0305dfd4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 60 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_tick_idle_check(void)

{
  if ((p_dialog_flags_from_flash->flags_0x1e & 0x70) != 0) {
    p_dialog_flags_from_flash->flags_0x1e = p_dialog_flags_from_flash->flags_0x1e & 0x8f;
    dialog_state_set_2bit_at_1();
  }
  if ((p_dialog_flags_from_flash->flags_0x1d & 1) != 0) {
    protocol_control_char_dispatch_backspace_wrapper();
    p_dialog_flags_from_flash->flags_0x1d = p_dialog_flags_from_flash->flags_0x1d & 0xfe;
  }
  return;
}


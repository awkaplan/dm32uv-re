/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: dialog_state_set_bit_0301ed30 @ 0301ed30 (file base 0x03000000; code starts at 0x03001000)
 * Size: 12 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-dialog
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void dialog_state_set_bit_0301ed30(byte param_1)

{
  p_call_setup_sm_state->flags_0x18 = p_call_setup_sm_state->flags_0x18 & 0xdf | (param_1 & 1) << 5;
  return;
}


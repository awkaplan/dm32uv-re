/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: write_two_bit_flags_0301eef8 @ 0301ed98 (file base 0x03000000; code starts at 0x03001000)
 * Size: 16 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: accessors
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void write_two_bit_flags_0301eef8(byte param_1,byte param_2)

{
  p_call_setup_sm_state->flags_0x19 =
       p_call_setup_sm_state->flags_0x19 & 0xf9 | (param_1 & 1) << 2 | (param_2 & 1) << 1;
  return;
}


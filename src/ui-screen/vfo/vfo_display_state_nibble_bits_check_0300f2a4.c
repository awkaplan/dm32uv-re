/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_display_state_nibble_bits_check @ 0300f2a4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 40 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

undefined4 vfo_display_state_nibble_bits_check(void)

{
  undefined4 uVar1;
  
  if (((p_vfo_display_state->field_0xc & 0xf0) == 0) &&
     ((p_vfo_display_state->flags_0x8 & 0xf0) == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = reg_0xc_bit1_read();
  }
  return uVar1;
}


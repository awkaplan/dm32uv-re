/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: scan_entry_get_mode_bits @ 03014198 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint scan_entry_get_mode_bits(byte param_1)

{
  uint uVar1;
  int iVar2;
  
  mode_transition_cleanup();
  uVar1 = vfo_active_side_mode_nibble();
  iVar2 = get_current_mode_state1();
  if (((iVar2 != 0) && (param_1 < 0xd)) && ((1 << ((int)(char)param_1 & 0x3fU) & 0x189eU) != 0)) {
    uVar1 = p_vfo_freq_display_state->flags_0x10 >> 5 & 3;
  }
  return uVar1;
}


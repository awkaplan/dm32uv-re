/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: vfo_freq_display_field0x5c_in_range @ 0302f41c (file base 0x03000000; code starts at 0x03001000)
 * Size: 70 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: ui-screen
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

bool vfo_freq_display_field0x5c_in_range(void)

{
  bool bVar1;
  byte bVar2;
  
  bVar2 = p_vfo_display_state->flags_0x9 & 0x3f;
  if ((bVar2 + 0x3f & 0x3f) < 0x20) {
    if ((p_vfo_display_state->flags_0x9 & 0x3f) == 0) {
      bVar1 = false;
    }
    else if (*(byte *)p_vfo_freq_display_state < bVar2) {
      bVar1 = false;
    }
    else if (p_vfo_freq_display_state->field_0x5c < 2) {
      bVar1 = false;
    }
    else {
      bVar1 = p_vfo_freq_display_state->field_0x5c < 0x11;
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


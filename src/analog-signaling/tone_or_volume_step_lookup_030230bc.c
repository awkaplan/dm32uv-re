/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tone_or_volume_step_lookup @ 030230bc (file base 0x03000000; code starts at 0x03001000)
 * Size: 68 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: analog-signaling
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tone_or_volume_step_lookup(void)

{
  byte bVar1;
  
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    fd6818b_reg48_cic_mode_write(*(undefined1 *)PTR_DAT_03023104);
  }
  else {
    bVar1 = *(byte *)PTR_DAT_03023108;
    if (bVar1 < 0x20) {
      bVar1 = 0x1f - bVar1;
    }
    else if (bVar1 < 0x40) {
      bVar1 = 0x5f - bVar1;
    }
    else {
      bVar1 = 0;
    }
    PTR_DAT_0302310c[0xdf] = bVar1 | 0x80;
  }
  return;
}


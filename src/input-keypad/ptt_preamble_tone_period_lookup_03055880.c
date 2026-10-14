/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: ptt_preamble_tone_period_lookup @ 03055880 (file base 0x03000000; code starts at 0x03001000)
 * Size: 72 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: input-keypad
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void ptt_preamble_tone_period_lookup(uint param_1)

{
  byte bVar1;
  
  if ((p_vfo_display_state->flags_0x8 & 0xf0) == 0) {
    bVar1 = PTR_LAB_030558e0[param_1 & 0xff];
  }
  else {
    bVar1 = PTR_LAB_030558e4[param_1 & 0xff];
  }
  if (bVar1 < 0x20) {
    bVar1 = 0x1f - bVar1;
  }
  else if (bVar1 < 0x40) {
    bVar1 = 0x5f - bVar1;
  }
  else {
    bVar1 = 0;
  }
  PTR_DAT_030558d8[0xdf] = bVar1 | 0x80;
  return;
}


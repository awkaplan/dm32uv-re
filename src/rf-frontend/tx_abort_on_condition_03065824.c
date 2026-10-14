/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_abort_on_condition @ 03065824 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_abort_on_condition(void)

{
  if (((PTR_DAT_03065960[1] & 0x80) != 0) &&
     (*(undefined1 *)PTR_DAT_03065964 = 0, (PTR_DAT_03065960[2] & 1) == 0)) {
    PTR_DAT_03065960[2] = PTR_DAT_03065960[2] & 0xfe | 1;
    audio_pa_enable_gate(0);
    rda5807m_power_down();
  }
  return;
}


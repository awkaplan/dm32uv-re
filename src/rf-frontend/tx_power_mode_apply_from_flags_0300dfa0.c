/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: tx_power_mode_apply_from_flags @ 0300dfa0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 56 bytes
 * Confidence: STRUCTURAL (inferred from code shape and call context; plausible but unverified)
 */


/* Subsystem: rf-frontend
 * Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: STRUCTURAL - inferred from code shape and call context; plausible but unverified. */

void tx_power_mode_apply_from_flags(int param_1)

{
  if ((*(byte *)(param_1 + 8) & 0xf0) == 0) {
    if ((*(byte *)(param_1 + 9) & 0x80) == 0) {
      tx_bandwidth_deviation_mode_set(0,0);
    }
    else {
      tx_bandwidth_deviation_mode_set(0,1);
    }
  }
  else {
    tx_bandwidth_deviation_mode_set(1,0);
  }
  return;
}


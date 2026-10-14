/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_channel_enable_dispatch @ 0301d740 (file base 0x03000000; code starts at 0x03001000)
 * Size: 14 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void timer_channel_enable_dispatch(uint param_1)

{
  if ((param_1 & 0xff) < 6) {
                    /* WARNING: Could not recover jumptable at 0x0301d74c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(PTR_PTR_0301d750[param_1 & 0xff] & 0xfffffffe))();
    return;
  }
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: timer_ch3_read_status @ 0301d7f8 (file base 0x03000000; code starts at 0x03001000)
 * Size: 8 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

dword timer_ch3_read_status(void)

{
  dword dVar1;
  
  dVar1 = TIMER_Type_14000000.CH[4].CurrentValue;
  return dVar1;
}


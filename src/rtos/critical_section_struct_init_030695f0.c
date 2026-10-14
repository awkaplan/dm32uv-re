/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: critical_section_struct_init @ 030695f0 (file base 0x03000000; code starts at 0x03001000)
 * Size: 16 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: rtos
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void critical_section_struct_init(undefined4 *param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 2) = param_2;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


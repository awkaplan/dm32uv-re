/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: display_status_buffer_reset_or_score_calc @ 030c84f4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 102 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: display-driver
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void display_status_buffer_reset_or_score_calc(int param_1,short param_2)

{
  short sVar1;
  
  u16_buffer_fill_memset(param_1,0,0x22);
  if (param_2 != 0) {
    *(undefined2 *)(param_1 + 0x42) = 1;
    *(undefined2 *)(param_1 + 0x3a) = 1;
    *(undefined2 *)(param_1 + 0x3c) = 1;
    *(undefined2 *)(param_1 + 0x36) = 0x31;
    *(undefined2 *)(param_1 + 0x3e) = 0;
    *(undefined2 *)(param_1 + 0x40) = 0;
    *(undefined2 *)(param_1 + 0x38) = 0x17;
    *(undefined2 *)(param_1 + 0x34) = 0x48;
    return;
  }
  sVar1 = *(short *)(param_1 + 0x3c) * 0xb + *(short *)(param_1 + 0x3a) * 0xc +
          *(short *)(param_1 + 0x40) * 4 + *(short *)(param_1 + 0x3e) * 5;
  *(short *)(param_1 + 0x38) = sVar1;
  *(short *)(param_1 + 0x34) = sVar1 + *(short *)(param_1 + 0x36);
  return;
}


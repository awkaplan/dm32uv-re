/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: channel_apply_frequency_offset @ 03031500 (file base 0x03000000; code starts at 0x03001000)
 * Size: 58 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

int channel_apply_frequency_offset(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  byte bStack_6;
  
  iVar1 = bcd_frequency_decode(&stack0x0000000c,4);
  bStack_6 = (byte)(param_3 >> 0x10);
  if ((param_3 & 0x30000) != 0) {
    if ((bStack_6 & 3) == 1) {
      param_1 = iVar1 + param_1;
    }
    else {
      param_1 = param_1 - iVar1;
    }
  }
  return param_1;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bcd_frequency_bound_clamp @ 0302e12c (file base 0x03000000; code starts at 0x03001000)
 * Size: 100 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void bcd_frequency_bound_clamp(char param_1,uint param_2,byte *param_3)

{
  uint uVar1;
  undefined1 uStack_18;
  undefined1 uStack_17;
  byte bStack_16;
  byte bStack_15;
  
  uStack_18 = 0;
  uStack_17 = 0;
  bStack_16 = *param_3 << 4;
  bStack_15 = *param_3 >> 4 | param_3[1] << 4;
  uVar1 = bcd_frequency_decode(&uStack_18,4);
  if (((param_2 < uVar1) && (param_1 == '\0')) || ((uVar1 < param_2 && (param_1 == '\x01')))) {
    u32_to_bcd4_encode(param_2,&uStack_18);
    *param_3 = bStack_16 >> 4 | bStack_15 << 4;
    param_3[1] = bStack_15 >> 4;
  }
  return;
}


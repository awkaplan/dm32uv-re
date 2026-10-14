/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: DM32.00.01.048.bin (app region, file offset 0x1000+)
 *   SHA-256: 0791558d1471415556bcea941e161cd695937edd41b7e8ed38a18bdca2556147
 * Function: bcd_frequency_in_range_check @ 0302f6c4 (file base 0x03000000; code starts at 0x03001000)
 * Size: 44 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: codeplug
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

byte bcd_frequency_in_range_check(char param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = bcd_frequency_decode(param_2,4);
  if (param_1 == '\0') {
    uVar4 = *PTR_DAT_0302f784;
    uVar3 = PTR_DAT_0302f784[1];
  }
  else {
    uVar4 = PTR_DAT_0302f784[2];
    uVar3 = PTR_DAT_0302f784[3];
  }
  if (uVar2 < uVar4) {
    bVar1 = 1;
  }
  else {
    bVar1 = ~(uVar2 <= uVar3);
  }
  return bVar1;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: msb_bit_position_via_byte_table @ 000103e0 (IRAM address; the boot stub copies these bytes from program flash 0x030c0000)
 * Size: 74 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

uint msb_bit_position_via_byte_table(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 0x10000) {
    if (param_1 < 0x100) {
      uVar1 = *(byte *)(iRam000104d8 + param_1) + 0x18;
    }
    else {
      uVar1 = *(byte *)(iRam000104d8 + (param_1 >> 8)) + 0x10;
    }
  }
  else if (param_1 < 0x1000000) {
    uVar1 = *(byte *)(iRam000104d8 + (param_1 >> 0x10)) + 8;
  }
  else {
    uVar1 = (uint)*(byte *)(iRam000104d8 + (param_1 >> 0x18));
  }
  return uVar1;
}


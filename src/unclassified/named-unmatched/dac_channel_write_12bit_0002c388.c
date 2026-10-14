/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: dac_channel_write_12bit @ 0002c388 (IRAM address; the boot stub copies these bytes from program flash 0x030dbfa8)
 * Size: 42 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void dac_channel_write_12bit(char param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  param_2 = param_2 & 0xfff;
  uVar1 = param_2;
  uVar2 = uRam140f000c;
  if (((param_1 != '\x01') && (uVar1 = uRam140f0008, uVar2 = param_2, param_1 != '\x02')) &&
     (uVar2 = uRam140f000c, param_1 == '\x04')) {
    uRam140f0010 = param_2;
  }
  uRam140f000c = uVar2;
  uRam140f0008 = uVar1;
  return;
}


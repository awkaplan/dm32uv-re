/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00011a34 @ 00011a34 (IRAM address; the boot stub copies these bytes from program flash 0x030c1654)
 * Size: 30 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00011a34(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(iRam00011a54 + ((param_1 & 0xff) >> 5) * 4);
  uVar1 = ~(param_1 & 0xff) & 0x1f;
  *puVar2 = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & *puVar2;
  return;
}


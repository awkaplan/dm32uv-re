/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: OS_PrioInsert @ 00011a14 (IRAM address; the boot stub copies these bytes from program flash 0x030c1634)
 * Size: 30 bytes
 * Confidence: CONFIRMED (cross-validated against an independent source)
 */


/* Subsystem: unclassified
 * Confidence: CONFIRMED - cross-validated against an independent source.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

/* Confidence: CONFIRMED - cross-validated against an independent source. */

void OS_PrioInsert(uint param_1)

{
  uint *puVar1;
  
  puVar1 = (uint *)(iRam00011a54 + ((param_1 & 0xff) >> 5) * 4);
  *puVar1 = 1 << (~(param_1 & 0xff) & 0x1f) | *puVar1;
  return;
}


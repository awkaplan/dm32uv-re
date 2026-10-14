/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00016088 @ 00016088 (IRAM address; the boot stub copies these bytes from program flash 0x030c5ca8)
 * Size: 38 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00016088(void)

{
  PTR_DAT_000160f4[0x1728] = 1;
  uRam110003b0 = uRam110003b0 | 0x10;
  uRam11000080 = uRam11000080 | 0x10;
  return;
}


/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_0002df40 @ 0002df40 (IRAM address; the boot stub copies these bytes from program flash 0x030ddb60)
 * Size: 36 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

byte FUN_0002df40(void)

{
  byte bVar1;
  
  if ((PTR_DAT_0002df64[0x2d] & 0x80) == 0) {
    bVar1 = PTR_DAT_0002df68[8];
  }
  else {
    bVar1 = PTR_DAT_0002df6c[8];
  }
  return bVar1 & 1;
}


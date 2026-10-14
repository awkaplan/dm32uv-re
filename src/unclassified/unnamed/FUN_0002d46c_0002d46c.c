/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_0002d46c @ 0002d46c (IRAM address; the boot stub copies these bytes from program flash 0x030dd08c)
 * Size: 50 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0002d46c(void)

{
  int iVar1;
  int unaff_r5;
  undefined4 uStack00000000;
  undefined4 uStack00000004;
  
  uStack00000004 = *(undefined4 *)(unaff_r5 + 0x2c);
  uStack00000000 = uRam0002d4dc;
  func_0x03019fc4(0xa0);
  func_0x030231e8(0xbe);
  iVar1 = iRam0002d4b8;
  *(undefined4 *)(iRam0002d4b8 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  return;
}


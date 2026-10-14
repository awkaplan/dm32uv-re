/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00010b6c @ 00010b6c (IRAM address; the boot stub copies these bytes from program flash 0x030c078c)
 * Size: 26 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00010b6c(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0xc4) = uRam00010c90;
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 0x1c) = uRam00010c90;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 8) + 0x20);
  }
  return;
}


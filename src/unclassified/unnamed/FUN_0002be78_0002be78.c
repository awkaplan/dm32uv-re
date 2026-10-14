/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_0002be78 @ 0002be78 (IRAM address; the boot stub copies these bytes from program flash 0x030dba98)
 * Size: 62 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

undefined4 FUN_0002be78(uint param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*piRam0002bf8c == 1) {
    uVar1 = 0xffffffff;
  }
  else if ((uint)piRam0002bf8c[4] < param_1) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = 0;
    do {
      *(undefined1 *)(param_3 + uVar2) = *(undefined1 *)(uVar2 + param_1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
    uVar1 = 0;
  }
  return uVar1;
}


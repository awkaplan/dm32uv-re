/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_00015f30 @ 00015f30 (IRAM address; the boot stub copies these bytes from program flash 0x030c5b50)
 * Size: 76 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_00015f30(ushort param_1,char param_2)

{
  param_1 = param_1 & 0xff;
  if (param_2 != '\0') {
    if (6 < param_1) {
      *(undefined2 *)(iRam00015f80 + 0x1738) = 6;
      *(undefined2 *)(iRam00015f7c + 0x1168) = 6;
      return;
    }
    *(ushort *)(iRam00015f80 + 0x1738) = param_1;
    *(ushort *)(iRam00015f7c + 0x1168) = param_1;
    return;
  }
  if (param_1 < 5) {
    *(ushort *)(iRam00015f80 + 0x1736) = param_1;
    *(ushort *)(iRam00015f7c + 0x1166) = param_1;
    return;
  }
  *(undefined2 *)(iRam00015f80 + 0x1736) = 4;
  *(undefined2 *)(iRam00015f7c + 0x1166) = 4;
  return;
}


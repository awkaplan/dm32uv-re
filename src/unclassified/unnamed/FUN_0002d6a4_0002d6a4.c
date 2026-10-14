/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_0002d6a4 @ 0002d6a4 (IRAM address; the boot stub copies these bytes from program flash 0x030dd2c4)
 * Size: 165 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

void FUN_0002d6a4(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)(iRam0002d74c + 1) != '\x01') {
    if (*(char *)(iRam0002d74c + 1) != '\x04') {
      return;
    }
    if (pcRam0002d750[4] == *pcRam0002d750) {
      return;
    }
    iVar3 = func_0x0300c3ac();
    if (iVar3 != 0) {
      pcRam0002d750[0x13] = '\x01';
      return;
    }
    pcRam0002d750[0x13] = '\0';
    return;
  }
  if (pcRam0002d750[9] == '\0') {
    return;
  }
  uVar4 = uRam11000390 >> 0x16 & 1;
  if (*(byte *)(iRam0002d74c + 3) == uVar4) {
    return;
  }
  uVar2 = uRam11000390 >> 0x14 & 3;
  cVar1 = pcRam0002d750[0x14];
  if (cVar1 == '~') {
    if (uVar2 == 1) goto LAB_0002d700;
  }
  else if ((cVar1 == -7) || (cVar1 == -0x19)) {
    if (uVar2 != 3) {
      return;
    }
    goto LAB_0002d700;
  }
  if (cVar1 != -0x61) {
    return;
  }
  if (uVar2 != 2) {
    return;
  }
LAB_0002d700:
  if ((*(ushort *)(pcRam0002d750 + 10) & 0xf) == 10) {
    if (uVar4 != 1) {
      return;
    }
  }
  else {
    if ((*(ushort *)(pcRam0002d750 + 10) & 0xf) != 5) {
      return;
    }
    if (uVar4 != 0) {
      return;
    }
  }
  pcRam0002d750[0x13] = (byte)(uRam11000390 >> 0x17) & 1;
  return;
}


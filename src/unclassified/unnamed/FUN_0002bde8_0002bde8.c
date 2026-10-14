/*
 * Decompiler reconstruction for interoperability research; not Baofeng source code.
 * Source binary: IRAM_dm32.00.01.048.bin (IRAM image as built at boot from DM32.00.01.048.bin flash 0x030bfc20..0x030decb7, base 0x00010000)
 *   SHA-256: 4bccb47dea691a8b06483137a40ad41e2b891618741830b7ca43947a325eb941
 * Function: FUN_0002bde8 @ 0002bde8 (IRAM address; the boot stub copies these bytes from program flash 0x030dba08)
 * Size: 132 bytes
 * Confidence: RAW (unmodified decompiler output; the name, if any, is a guess)
 */


/* Subsystem: unclassified
 * Confidence: RAW - unmodified decompiler output; the name, if any, is a guess.
 *
 * GENERATED FILE - do not edit; regenerate from the source project.
 */
#include "dm32/dm32.h"

int FUN_0002bde8(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*piRam0002be74 == 1) {
    iVar1 = -1;
  }
  else {
    uVar4 = param_2 >> 0xc;
    if ((param_2 & 0xfff) != 0) {
      uVar4 = uVar4 + 1;
    }
    if (uVar4 == 0) {
      iVar1 = 0;
    }
    else {
      uVar3 = param_1 & 0xfff000 | 0x20000000;
      uVar2 = 0;
      while ((iVar1 = func_0x0002bca4(6,1,0,0), iVar1 == 0 &&
             (iVar1 = func_0x0002bca4(uVar3,4,0,0), iVar1 == 0))) {
        func_0x0002bc38(5000);
        iVar1 = func_0x0002bd9c(0xfffff);
        if (iVar1 != 0) {
          return iVar1;
        }
        uVar2 = uVar2 + 1;
        if (uVar4 <= uVar2) {
          return 0;
        }
        uVar3 = uVar3 + 0x1000;
      }
    }
  }
  return iVar1;
}

